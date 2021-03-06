/*
    Gyro Driver InvenSense IDG2020.

    @file       GyroDrv_IDG2020.c
    @ingroup
    @note       Nothing.

    Copyright   Novatek Microelectronics Corp. 2012.  All rights reserved.
*/

#include <stdio.h>
#include <String.h>
#include "Debug.h"
#include "type.h"
#include "ErrorNo.h"

#include "Cache.h"
#include "dma.h"
#include "GyroDrv.h"
#include "spi.h"
#include "SysKer.h"
#include "Delay.h"

#define THIS_DBGLVL         1 //0=OFF, 1=ERROR, 2=TRACE
///////////////////////////////////////////////////////////////////////////////
#define __MODULE__          GyroDrv
#define __DBGLVL__          THIS_DBGLVL
#define __DBGFLT__          "*" //*=All, [mark]=CustomClass
#include "DebugModule.h"

#define GDCONST_GD_NUM_PER_FRM (8)

typedef enum
{
    GYRO_IDLE   = 0,        ///< idle
    GYRO_READY  = 1,        ///< ready for read/write
    GYRO_RUN    = 2,        ///< running
    ENUM_DUMMY4WORD(GYRO_STATUS)
} GYRO_STATUS;


static GYRO_STATUS g_GyroStatus = GYRO_IDLE;
static GYRO_OP_MODE g_GyroOpMode = GYRO_OP_MODE_SINGLE_ACCESS;
//do callback instead//static UINT32 g_uiGyroFlgId    =   0;
//do callback instead//static UINT32 g_uiGyroPtnId    =   0;
static UINT32 g_uiGyroFrPeriod =   0;
static UINT32 g_uiGyroFrNumber =   0;
static SPI_ID g_TestSpiID = SPI_ID_2;
const static UINT32 g_uiReadFrequency = 10000000; // 10 MHz for read
const static UINT32 g_uiWriteFrequency = 1875000; // 1.875 MHz for write (temp, actually it should be 1MHz)
static INT16  g_xOffset = 0;
static INT16  g_yOffset = 0;
static void (*pGyroCB)(void) = NULL;

#define GDI2_GB_NUM (32)
static UINT32 puiGyroBuf[GDI2_GB_NUM][4]={0};
static UINT32 uiGyroBufInIdx = 0, uiGyroBufOutIdx = 0;

#define REG_GYRO_CONFIG             (0x1B)
#define REG_GYRO_XOUT_H             (0x43)
#define REG_GYRO_XOUT_L             (0x44)
#define REG_GYRO_YOUT_H             (0x45)
#define REG_GYRO_YOUT_L             (0x46)
#define REG_GYRO_ZOUT_H             (0x47)
#define REG_GYRO_ZOUT_L             (0x48)
#define REG_PWR_MGMT_1              (0x6B)
#define REG_PWR_MGMT_2              (0x6C)
#define REG_WHO_AM_I                (0x75)
#define REG_WRITE                   (0x00)
#define REG_READ                    (0x80)

#define IDG2020_ID                  (0x68)

typedef struct
{
    UINT32  uiAddress;                      // Panel Register Address
    UINT32  uiValue;                        // Panel Register config value
}tGYRO_CMD;

tGYRO_CMD cmd_gyro_init[]=
{
    0x1B,    0x08,      // FS_SEL set 1
};

ER gyro_open(GYRO_OPENOBJ *openObj)
{
    // state check: only while idle
    if(g_GyroStatus!=GYRO_IDLE)
    {
        DBG_ERR("GYRO ERR: gyro_open, g_GyroStatus=%d!!\r\n", g_GyroStatus);
        return E_SYS;
    }

    uiGyroBufOutIdx = 0;
    uiGyroBufInIdx = 0;

    // parameter check
    if (openObj && openObj->FP_GYRO_CB)
    {
        pGyroCB = openObj->FP_GYRO_CB;
    }

    // power on gyro
    // always power-on

    // initializa gyro
    {
        UINT32 uiRecv1, uiRecv2;

        spi_setConfig(g_TestSpiID, SPI_CONFIG_ID_ENG_GYRO_UNIT, FALSE);  // normal mode

        spi_setConfig(g_TestSpiID, SPI_CONFIG_ID_FREQ, g_uiReadFrequency);

        spi_setConfig(g_TestSpiID, SPI_CONFIG_ID_BUSMODE, SPI_MODE_0);
        spi_setConfig(g_TestSpiID, SPI_CONFIG_ID_MSB_LSB, SPI_MSB);
        spi_setConfig(g_TestSpiID, SPI_CONFIG_ID_CS_ACT_LEVEL, SPI_CS_ACT_LEVEL_LOW);
        spi_setConfig(g_TestSpiID, SPI_CONFIG_ID_CS_CK_DLY, 1);

        // Read IDG2020 ID
        spi_open(g_TestSpiID);

        spi_setCSActive(g_TestSpiID, TRUE);
        spi_setTransferLen(g_TestSpiID, SPI_TRANSFER_LEN_2BYTES);
        spi_writeReadSingle(g_TestSpiID, (REG_READ|REG_WHO_AM_I)<<8, &uiRecv1);
        spi_writeReadSingle(g_TestSpiID, 0x00, &uiRecv2);
        spi_setCSActive(g_TestSpiID, FALSE);

        spi_close(g_TestSpiID);

        if ((uiRecv1&0xFF) != IDG2020_ID)
        {
            return E_SYS;
        }
    }
    // set initial value
    {
        UINT32 i;
        spi_open(g_TestSpiID);
        spi_setTransferLen(g_TestSpiID, SPI_TRANSFER_LEN_1BYTE);
        for (i=0;i<sizeof(cmd_gyro_init)/sizeof(tGYRO_CMD);i++)
        {
            spi_setCSActive(g_TestSpiID, TRUE);
            spi_writeSingle(g_TestSpiID, REG_WRITE|(cmd_gyro_init[i].uiAddress&0x7f));
            spi_writeSingle(g_TestSpiID, cmd_gyro_init[i].uiValue);
            spi_setCSActive(g_TestSpiID, FALSE);
        }
        spi_close(g_TestSpiID);
    }

    // state change: ready for gyro
    g_GyroStatus = GYRO_READY;
    return E_OK;
}


ER gyro_close(void)
{
    // state check: only while idle
    if(g_GyroStatus!=GYRO_READY)
    {
        DBG_ERR("GYRO ERR: gyro_close, g_GyroStatus=%d!!\r\n", g_GyroStatus);
        return E_SYS;
    }

    // stop/pause gyro
    // not-yet

    // power off gyro
    // always power-on

    // state change: ready for gyro
    g_GyroStatus = GYRO_IDLE;

    return E_OK;
}

ER gyro_readReg(UINT32 uiAddr, UINT32 * puiData)
{
    // state check: only while ready
    if(g_GyroStatus!=GYRO_READY)
    {
        DBG_ERR("GYRO ERR: gyro_readReg, g_GyroStatus=%d!!\r\n", g_GyroStatus);
        return E_SYS;
    }

    // state change: ready -> run
    g_GyroStatus = GYRO_RUN;

    // read register
    #if 1
    //normal job
    {
    UINT32 uiRecv1;//, uiRecv2;
    spi_open(g_TestSpiID);

    spi_setCSActive(g_TestSpiID, TRUE);
    spi_setTransferLen(g_TestSpiID, SPI_TRANSFER_LEN_1BYTE);
    spi_writeSingle(g_TestSpiID, (REG_READ)|(uiAddr&0x7f));
    spi_setTransferLen(g_TestSpiID, SPI_TRANSFER_LEN_2BYTES);
    spi_writeReadSingle(g_TestSpiID, 0x00, &uiRecv1);
    spi_setCSActive(g_TestSpiID, FALSE);

    spi_close(g_TestSpiID);

    *puiData = (uiRecv1&0xFFFF);
    }
    #else
    //test only
    {
        INT16 xOut, yOut;
        Idg2020_ReadGyroscope(&xOut, &yOut);
        GD_MSG_MSG("%d\t%d\r\n", xOut, yOut);
    }
    #endif

    // state change: run -> ready
    g_GyroStatus = GYRO_READY;

    return E_OK;
}

ER gyro_writeReg(UINT32 uiAddr, UINT32 uiData)
{
    // state check: only while ready
    if(g_GyroStatus!=GYRO_READY)
    {
        DBG_ERR("GYRO ERR: gyro_readReg, g_GyroStatus=%d!!\r\n", g_GyroStatus);
        return E_SYS;
    }

    // state change: ready -> run
    g_GyroStatus = GYRO_RUN;

    // write register
    {
    UINT32 uiRecv1;//, uiRecv2;

    spi_setConfig(g_TestSpiID, SPI_CONFIG_ID_FREQ, g_uiWriteFrequency);

    spi_open(g_TestSpiID);

    spi_setCSActive(g_TestSpiID, TRUE);
    spi_setTransferLen(g_TestSpiID, SPI_TRANSFER_LEN_1BYTE);
    spi_writeSingle(g_TestSpiID, (REG_WRITE)|(uiAddr&0x7f));
    spi_setTransferLen(g_TestSpiID, SPI_TRANSFER_LEN_2BYTES);
    spi_writeReadSingle(g_TestSpiID, uiData, &uiRecv1);
    spi_setCSActive(g_TestSpiID, FALSE);

    spi_close(g_TestSpiID);

    spi_setConfig(g_TestSpiID, SPI_CONFIG_ID_FREQ, g_uiReadFrequency);

    }

    // state change: run -> ready
    g_GyroStatus = GYRO_READY;

    return E_OK;
}


ER gyro_setFreeRunParam(GYRO_FREE_RUN_PARAM *frParam)
{
    // state check: only while idle
    //not-yet

    g_uiGyroFrPeriod = frParam->uiPeriodUs;
    g_uiGyroFrNumber = frParam->uiDataNum;

    return E_OK;
}

static void gyro_HandleGyroEvent(SPI_GYRO_INT gyroInt)
{
    ER Status;
    UINT32 i, j, k;
    GYRO_BUF_QUEUE gyroData;

    switch (gyroInt)
    {
    case SPI_GYRO_INT_SYNC_END:
        //GD_ERR_MSG("uiGyroBufInIdx %d\r\n", uiGyroBufInIdx);
        j = uiGyroBufInIdx;
        for (i=0; i<g_uiGyroFrNumber; i++)
        {
            Status = spi_getGyroData(g_TestSpiID, &gyroData);
            if(Status!=E_OK)
            {
                gyroData.uiFrameID      = 9;
                gyroData.uiDataID       = 9;
                gyroData.vRecvWord[0]   = 9;
                gyroData.vRecvWord[1]   = 9;
            }
//        debug_err(("%d\t%d\t%08x\t%08x\r\n", gyroData.uiFrameID, gyroData.uiDataID, gyroData.vRecvWord[0], gyroData.vRecvWord[1]));
            k = j%GDI2_GB_NUM;
            puiGyroBuf[k][0] = gyroData.uiFrameID;
            puiGyroBuf[k][1] = gyroData.uiDataID;
            #if 0
            {
                UINT32 uiVal;
                uiVal = (gyroData.vRecvWord[0]&0xFF00) | ((gyroData.vRecvWord[0]>>16)&0xFF);
            }
            #else
            //  x =  byte 1 | byte2 (byte 0 is address, we ignore it)
            puiGyroBuf[k][2] = (gyroData.vRecvWord[0]&0xFF00) | ((gyroData.vRecvWord[0]>>16)&0xFF);
            //  y =  byte 3 | byte4
            puiGyroBuf[k][3] = ((gyroData.vRecvWord[0]>>16)&0xFF00) | (gyroData.vRecvWord[1]&0xFF);
            #endif
            j++;
        }
        uiGyroBufInIdx = j;
#if 0
{
static UINT32 uiTest=0;
if(uiTest++%4==0)
GD_MSG_MSG("%d\t%d\r\n",
    ((INT16)(puiGyroBuf[(uiGyroBufInIdx-1)%GDI2_GB_NUM][2]))  ,
    ((INT16)(puiGyroBuf[(uiGyroBufInIdx-1)%GDI2_GB_NUM][3]))  );
}
#endif
        break;
    case SPI_GYRO_INT_OVERRUN:
        DBG_ERR("SPI_GYRO_INT_OVERRUN!!\r\n");
        //set_flg(FLG_ID_IDG2020, IDG2020_FLG_HW_OVERRUN);
        break;
    case SPI_GYRO_INT_SEQ_ERR:
        DBG_ERR("SPI_GYRO_INT_SEQ_ERR!!\r\n");
        //set_flg(FLG_ID_IDG2020, IDG2020_FLG_SEQ_ERR);
        break;

    case SPI_GYRO_INT_QUEUE_THRESHOLD:
        DBG_ERR("SPI_GYRO_INT_QUEUE_THRESHOLD!!\r\n");
        //set_flg(FLG_ID_IDG2020, IDG2020_FLG_QUEUE_THRESHOLD);
        break;
    case SPI_GYRO_INT_QUEUE_OVERRUN:
        DBG_ERR("SPI_GYRO_INT_QUEUE_OVERRUN!!\r\n");
        //set_flg(FLG_ID_IDG2020, IDG2020_FLG_QUEUE_OVERRUN);
        break;
    default:
        DBG_ERR("%d\r\n",gyroInt);
        break;
    }

    if(pGyroCB!=NULL)
    {
        pGyroCB();
    }
}

static ER gyro_setFreeRun(void)
{
    UINT32 i;
    SPI_GYRO_INFO gyroInfo= {0};

    //
    // 1. Prepare data buffer to store polled gyroscope data
    //
    //useless in new driver//uiDumpCount = 0;
    //useless in new driver//pNextBuf = (UINT32*)uiDumpBufAddr;

    //
    // 2. Start SPI gyro polling
    //
    gyroInfo.gyroMode = SPI_GYRO_MODE_SIE_SYNC;

    gyroInfo.uiTransferCount = g_uiGyroFrNumber/2;  // 4 Transfer => Total 8 CS in one frame
    gyroInfo.uiOpInterval       = g_uiGyroFrPeriod/g_uiGyroFrNumber;
    gyroInfo.uiTransferInterval = g_uiGyroFrPeriod/g_uiGyroFrNumber;
    gyroInfo.uiOp0Length = 5;
    gyroInfo.vOp0OutData[0] = REG_READ|REG_GYRO_XOUT_H;
    for (i=1; i<gyroInfo.uiOp0Length; i++)
    {
        gyroInfo.vOp0OutData[i] = 0;
    }

    gyroInfo.uiOp1Length = 5;
    gyroInfo.vOp1OutData[0] = REG_READ|REG_GYRO_XOUT_H;
    for (i=1; i<gyroInfo.uiOp1Length; i++)
    {
        gyroInfo.vOp1OutData[i] = 0;
    }

    gyroInfo.pEventHandler = gyro_HandleGyroEvent;

    spi_open(g_TestSpiID);

    spi_setTransferLen(g_TestSpiID, SPI_TRANSFER_LEN_1BYTE);

    spi_startGyro(g_TestSpiID, &gyroInfo);

    return E_OK;
}

void gyro_RSCInfoInit(GYRO_RSCINFOINIT *pRSCInfoInfo)
{
    // please refer to IPL_Ctrl_RSC_Int.h file for the GDFmt/FDDir definition
    pRSCInfoInfo->GDFmt = 2;//_ISIGD2020
    pRSCInfoInfo->GDDir = 0;//_RSC_GYRO_DIR_UP_RIGHT
    pRSCInfoInfo->GDunit = (65536/131);
}


ER gyro_setMode(GYRO_OP_MODE opMode)
{
    DBG_IND("gyro_setMode %d!!\r\n", opMode);

    // state check: only while idle
    if((g_GyroStatus!=GYRO_READY) && (g_GyroOpMode!=GYRO_OP_MODE_FREE_RUN))
    {
        DBG_ERR("gyro_setMode, g_GyroOpMode = %d, g_GyroStatus=%d!!\r\n", g_GyroOpMode, g_GyroStatus);
        return E_SYS;
    }

    if(opMode==GYRO_OP_MODE_SINGLE_ACCESS)
    {
        if(g_GyroOpMode==GYRO_OP_MODE_SINGLE_ACCESS)
        {
            DBG_ERR("gyro_setMode, already single access mode!!\r\n");
            return E_SYS;
        }
        else if(g_GyroOpMode==GYRO_OP_MODE_FREE_RUN)
        {
            // disable free run
            spi_stopGyro(g_TestSpiID);

            g_GyroOpMode = GYRO_OP_MODE_SINGLE_ACCESS;
            g_GyroStatus = GYRO_READY;
        }
        else
        {
            DBG_ERR("gyro_setMode, g_GyroOpMode=%d!!\r\n", opMode);
            return E_SYS;
        }
    }
    else if(opMode==GYRO_OP_MODE_FREE_RUN)
    {
        if(g_GyroOpMode==GYRO_OP_MODE_FREE_RUN)
        {
            DBG_ERR("gyro_setMode, already free run mode!!\r\n");
            return E_SYS;
        }
        else if(g_GyroOpMode==GYRO_OP_MODE_SINGLE_ACCESS)
        {
            if(g_uiGyroFrPeriod==0)
            {
                DBG_ERR("gyro_setMode, run mode param is not set!!\r\n");
                return E_SYS;
            }
            // enable free run
            gyro_setFreeRun();

            g_GyroOpMode = GYRO_OP_MODE_FREE_RUN;
            g_GyroStatus = GYRO_RUN;
        }
        else
        {
            DBG_ERR("gyro_setMode, g_GyroOpMode=%d!!\r\n", opMode);
            return E_SYS;
        }
    }
    else
    {
        DBG_ERR("gyro_setMode, opMode=%d!!\r\n", opMode);
        return E_SYS;
    }

    return E_OK;
}

static void gyro_AdjustDataOffset(UINT32* gx, UINT32* gy)
{
    INT16  tempX,tempY;


    DBG_IND("gx=%ld, gy=%ld, g_xOffset = %ld, g_yOffset = %ld\r\n",*gx,*gy,g_xOffset,g_yOffset);
    tempX = *gx;
    if ((INT32)tempX + (INT32)g_xOffset > 32767)
        tempX = 32767;
    else if ((INT32)tempX + (INT32)g_xOffset < -32768)
        tempX = -32768;
    else
        tempX +=g_xOffset;

    tempY = *gy;
    if ((INT32)tempY + (INT32)g_yOffset > 32767)
        tempY = 32767;
    else if ((INT32)tempY + (INT32)g_yOffset < -32768)
        tempY = -32768;
    else
        tempY +=g_yOffset;

    *gx = (INT16)tempX;
    *gy = (INT16)tempY;

    DBG_IND("gx=%ld, gy=%ld \r\n",*gx,*gy);


}


ER gyro_getFreeRunData(UINT32 *puiNum, UINT32 *puiDatX, UINT32 *puiDatY)
{
    UINT32 i, j;//, k;
    // state check: only while run
    if(g_GyroStatus!=GYRO_RUN)
    {
        DBG_ERR("gyro_getGyroData, g_GyroStatus=%d!!\r\n", g_GyroStatus);
        return E_SYS;
    }

    // op mode check: only while free run mode
    if(g_GyroOpMode!=GYRO_OP_MODE_FREE_RUN)
    {
        DBG_ERR("gyro_getGyroData, not in free run mode!!\r\n", g_GyroOpMode);
        return E_SYS;
    }

    #if 1
    // normal job
    //GD_ERR_MSG("uiGyroBufOutIdx %d\r\n", uiGyroBufOutIdx);
    if((uiGyroBufOutIdx+g_uiGyroFrNumber)==uiGyroBufInIdx)
    {
        j = uiGyroBufOutIdx;
        for (i=0; i<g_uiGyroFrNumber; i++)
        {
            UINT32 k;
            k = j%GDI2_GB_NUM;
            *(puiDatX+i) = puiGyroBuf[k][2];
            *(puiDatY+i) = puiGyroBuf[k][3];
            gyro_AdjustDataOffset(puiDatX+i,puiDatY+i);
            j++;
        }
        uiGyroBufOutIdx = j;
        *puiNum = g_uiGyroFrNumber;
    }
    else if((uiGyroBufOutIdx+g_uiGyroFrNumber)>uiGyroBufInIdx)
    {
        DBG_ERR("asking for future data!!\r\n");
        memset((void *)puiDatX, 0, g_uiGyroFrNumber*sizeof(UINT32));
        memset((void *)puiDatY, 0, g_uiGyroFrNumber*sizeof(UINT32));
        *puiNum = 0;
    }
    else if((uiGyroBufOutIdx+g_uiGyroFrNumber)<uiGyroBufInIdx)
    {
        DBG_ERR("asking for past data!!\r\n");
        uiGyroBufOutIdx =  uiGyroBufInIdx;
        memset((void *)puiDatX, 0, g_uiGyroFrNumber*sizeof(UINT32));
        memset((void *)puiDatY, 0, g_uiGyroFrNumber*sizeof(UINT32));
        *puiNum = g_uiGyroFrNumber;
    }
    #elif 1
    // test only
    {
        #define TP_PERIOD_CONST (800)
        #define TP_PERIOD_CYCLE (60)//frame number of a period-cycle
        #define TP_PERIOD_NUM   (2)//period number in a frame
        #define TP_X_SHIFT      (100)//x-direction shift amount (+-X)
        #define TP_Y_SHIFT      (0)//y-direction shift amount (+-Y)
        static UINT32 g_uiTestCount=0;
        UINT32 uiVal;
        INT16 iDatX, iDatY;
        g_uiTestCount++;

        uiVal = (g_uiTestCount%TP_PERIOD_CYCLE)*TP_PERIOD_CONST/TP_PERIOD_CYCLE;
        j = uiGyroBufOutIdx;
        for(i=0; i<GDCONST_GD_NUM_PER_FRM; i++)
        {

            if((i/2)%2)
            {
                iDatX = (INT16)uiVal;
                iDatY = (INT16)uiVal;
            }
            else
            {
                iDatX = -((INT16)uiVal);
                iDatY = -((INT16)uiVal);
            }
            *(puiDatX+i) = iDatX;
            *(puiDatY+i) = iDatY;
            j++;
        }
        uiGyroBufOutIdx = j;
        *puiNum = GDCONST_GD_NUM_PER_FRM;
    }
    #elif 0
    // test only
    {
        #define TP_PERIOD_CONST (800)
        #define TP_PERIOD_CYCLE (60)//frame number of a period-cycle
        #define TP_PERIOD_NUM   (2)//period number in a frame
        #define TP_X_SHIFT      (100)//x-direction shift amount (+-X)
        #define TP_Y_SHIFT      (0)//y-direction shift amount (+-Y)
        static UINT32 g_uiTestCount=0;
        UINT32 uiStartPos, uiCurrPos;
        UINT32 uiModA, uiModB, uiVal;
        g_uiTestCount++;
        uiStartPos = (g_uiTestCount*TP_PERIOD_CONST/TP_PERIOD_CYCLE);

        j = uiGyroBufOutIdx;
        for(i=0; i<GDCONST_GD_NUM_PER_FRM; i++)
        {
            uiCurrPos = uiStartPos+(i*TP_PERIOD_CONST*TP_PERIOD_NUM/GDCONST_GD_NUM_PER_FRM);
            uiModA = uiCurrPos%TP_PERIOD_CONST;
            uiModB = (uiModA>(TP_PERIOD_CONST*1/2))?(uiModA-(TP_PERIOD_CONST*1/2)):(0);
            uiVal = uiModA - (uiModB*2);
            *(puiDatX+i) = 0x8000 + (TP_X_SHIFT*2*uiVal/(TP_PERIOD_CONST/2)) - TP_X_SHIFT;
            *(puiDatY+i) = 0x8000 + (TP_Y_SHIFT*2*uiVal/(TP_PERIOD_CONST/2)) - TP_Y_SHIFT;
            j++;
        }
        uiGyroBufOutIdx = j;
        *puiNum = GDCONST_GD_NUM_PER_FRM;
    }
    #else
    // feed 8 (x,y) data to pointer
    //not-yet
    #endif

//GD_MSG_MSG("\t%d\t%d\r\n", (INT16)(*(puiDatX+0)), (INT16)(*(puiDatY+0)));

    // state change: run -> run
    g_GyroStatus = GYRO_RUN;

    return E_OK;
}

void gyro_setCalZeroOffset(INT16 xOffset, INT16 yOffset)
{
    g_xOffset = xOffset;
    g_yOffset = yOffset;
    DBG_IND("xOffset = %d, yOffset = %d\r\n",xOffset,yOffset);
}



#if 0//mark all follwing


//////////////////from emu_spiIDG2020_int.h
/*
    IDG2020 task flag
*/
typedef enum
{
    IDG2020_FLG_START = 0x0001,             // start polling
    IDG2020_FLG_STOP = 0x0002,              // stop polling

    IDG2020_FLG_FRAME_END = 0x0010,         // frame end of gyro polling
    IDG2020_FLG_HW_OVERRUN = 0x0020,        // h/w buffer overrun
    IDG2020_FLG_SEQ_ERR = 0x0040,           // VD sequence error
    IDG2020_FLG_QUEUE_THRESHOLD = 0x0080,   // f/w queue threshold warning
    IDG2020_FLG_QUEUE_OVERRUN = 0x0100,     // f/w queue overrun

    IDG2020_FLG_IDLE = 0x400000,

    ENUM_DUMMY4WORD(IDG2020_FLG)
} IDG2020_FLG;

extern UINT32 _SECTION(".kercfg_data") FLG_ID_IDG2020;
extern UINT32 _SECTION(".kercfg_data") uiEmuIDG2020TaskID;
//////////////////~from emu_spiIDG2020_int.h


//////////////////from emu_spi.h
#define emuSPI_msg(msg)         debug_msg msg
//////////////////~from emu_spi.h


//////////////////from emu_spi.c
SPI_ID gTestSpiID = SPI_ID_2;
//////////////////~from emu_spi.c

//////////////////from emu_spiIDG2020ID.c
//
//  IDG2020 register offset
//
#define REG_GYRO_XOUT_H             (0x43)
#define REG_GYRO_XOUT_L             (0x44)
#define REG_GYRO_YOUT_H             (0x45)
#define REG_GYRO_YOUT_L             (0x46)
#define REG_GYRO_ZOUT_H             (0x47)
#define REG_GYRO_ZOUT_L             (0x48)
#define REG_PWR_MGMT_1              (0x6B)
#define REG_PWR_MGMT_2              (0x6C)
#define REG_WHO_AM_I                (0x75)
#define REG_WRITE                   (0x00)
#define REG_READ                    (0x80)
// REG_PWR_MGMT_1:
#define PWR_MGMT_CLKSEL             (1<<0)
#define PWR_MGMT_SLEEP              (1<<6)
#define PWR_MGMT_NORMAL             (0)
// REG_WHO_AM_I:
#define IDG2020_ID                  (0x68)
//
//  Internal configurations
//
const static UINT32 uiReadFrequency = 10000000; // 10 MHz for read
const static UINT32 uiWriteFrequency = 1875000; // 1.875 MHz for write (temp, actually it should be 1MHz)
const static UINT32 uiFrameGyroCount = 8;       // read gyro scope 8 times in one frame
const static UINT32 uiFramePerSec = 30;         // P30
const static UINT32 uiEOFTime = 1000;           // Reserve 1000us at frame end
//
//  Internal variables
//
static UINT32 uiDumpBufAddr = 0;
static UINT32 uiDumpCount = 0;
static UINT32* pNextBuf = NULL;
//////////////////~from emu_spiIDG2020ID.c

//////////////////from emu_spiIDG2020ID.c
UINT32 FLG_ID_IDG2020 = 0;
UINT32 uiEmuIDG2020TaskID = 0;

void Idg2020_InstallID(void)
{
    OS_CONFIG_FLAG(FLG_ID_IDG2020);
    OS_CONFIG_TASK(uiEmuIDG2020TaskID,  2, 1024,    Idg2020_Tsk);
}
//////////////////~from emu_spiIDG2020ID.c


//////////////////from emu_spiIDG2020.c
static void Idg2020_HandleGyroEvent(SPI_GYRO_INT gyroInt)
{
    switch (gyroInt)
    {
    case SPI_GYRO_INT_SYNC_END:
        set_flg(FLG_ID_IDG2020, IDG2020_FLG_FRAME_END);
        break;
    case SPI_GYRO_INT_OVERRUN:
        set_flg(FLG_ID_IDG2020, IDG2020_FLG_HW_OVERRUN);
        break;
    case SPI_GYRO_INT_SEQ_ERR:
        set_flg(FLG_ID_IDG2020, IDG2020_FLG_SEQ_ERR);
        break;

    case SPI_GYRO_INT_QUEUE_THRESHOLD:
        set_flg(FLG_ID_IDG2020, IDG2020_FLG_QUEUE_THRESHOLD);
        break;
    case SPI_GYRO_INT_QUEUE_OVERRUN:
        set_flg(FLG_ID_IDG2020, IDG2020_FLG_QUEUE_OVERRUN);
        break;
    default:
        debug_err(("%s\r\n", __func__));
        break;
    }
}
//////////////////~from emu_spiIDG2020.c


//////////////////from emu_spiIDG2020.c
static ER Idg2020_Open(void)
{
    UINT32 uiRecv1, uiRecv2;

    if ((FLG_ID_IDG2020 == 0) || (uiEmuIDG2020TaskID == 0))
    {
        debug_err(("%s: InstallID should be invoked first\r\n", __func__));
        return E_SYS;
    }

    spi_setConfig(gTestSpiID, SPI_CONFIG_ID_ENG_GYRO_UNIT, FALSE);  // normal mode

    spi_setConfig(gTestSpiID, SPI_CONFIG_ID_FREQ, uiReadFrequency);

    spi_setConfig(gTestSpiID, SPI_CONFIG_ID_BUSMODE, SPI_MODE_0);
    spi_setConfig(gTestSpiID, SPI_CONFIG_ID_MSB_LSB, SPI_MSB);
    spi_setConfig(gTestSpiID, SPI_CONFIG_ID_CS_ACT_LEVEL, SPI_CS_ACT_LEVEL_LOW);
    spi_setConfig(gTestSpiID, SPI_CONFIG_ID_CS_CK_DLY, 1);

    // Read IDG2020 ID
    spi_open(gTestSpiID);

    spi_setCSActive(gTestSpiID, TRUE);
    spi_setTransferLen(gTestSpiID, SPI_TRANSFER_LEN_2BYTES);
    spi_writeReadSingle(gTestSpiID, (REG_READ|REG_WHO_AM_I)<<8, &uiRecv1);
    spi_writeReadSingle(gTestSpiID, 0x00, &uiRecv2);
    spi_setCSActive(gTestSpiID, FALSE);

    spi_close(gTestSpiID);

    debug_msg("%s: read 0x%lx 0x%lx\r\n", __func__, uiRecv1, uiRecv2);

    if ((uiRecv1&0xFF) != IDG2020_ID)
    {
        return E_SYS;
    }

    sta_tsk(uiEmuIDG2020TaskID);

    return E_OK;
}
//////////////////~from emu_spiIDG2020.c


//////////////////from emu_spiIDG2020.c
static void Idg2020_Close(void)
{
    ter_tsk(uiEmuIDG2020TaskID);
}
//////////////////~from emu_spiIDG2020.c

//////////////////from emu_spiIDG2020.c
static ER Idg2020_WaiFlg(PFLGPTN puiFlag, FLGPTN WaitFlags)
{
    if (FLG_ID_IDG2020 == 0)
    {
        debug_err(("^R%s: FLG_ID not installed\r\n"));
        return E_CTX;
    }

    return wai_flg(puiFlag, FLG_ID_IDG2020, WaitFlags, TWF_ORW | TWF_CLR);
}
//////////////////~from emu_spiIDG2020.c



//////////////////from emu_spiIDG2020.c
void Idg2020_Tsk(void)
{
    FLGPTN      uiFlag;

    debug_err(("%s: task started\r\n", __func__));

    while (1)
    {
        const FLGPTN waitEvent = IDG2020_FLG_FRAME_END|IDG2020_FLG_QUEUE_THRESHOLD|IDG2020_FLG_SEQ_ERR|
                                    IDG2020_FLG_HW_OVERRUN|IDG2020_FLG_QUEUE_OVERRUN|IDG2020_FLG_STOP;

        if (Idg2020_WaiFlg(&uiFlag, waitEvent) == E_OK)
        {
            if (uiFlag & IDG2020_FLG_FRAME_END)
            {
                UINT32 i;
                GYRO_BUF_QUEUE gyroData;

                for (i=0; i<uiFrameGyroCount; i++, pNextBuf+=4)
                {
                    spi_getGyroData(gTestSpiID, &gyroData);

                    pNextBuf[0] = gyroData.uiFrameID;
                    pNextBuf[1] = gyroData.uiDataID;
                    pNextBuf[2] = (gyroData.vRecvWord[0]&0xFF00) | ((gyroData.vRecvWord[0]>>16)&0xFF);
                    pNextBuf[3] = ((gyroData.vRecvWord[0]>>16)&0xFF00) | (gyroData.vRecvWord[1]&0xFF);
                    uiDumpCount++;

                    if (i == 1)
                    {
                        INT16 x, y;

                        x = (INT16)pNextBuf[2];
                        y = (INT16)pNextBuf[3];
                        emuSPI_msg(("\r X: %8d Y: %8d              ", x, y));
                    }
                }
                if (uiDumpCount >= 0x1000)
                {
                    debug_err(("^R%s: debug RX full, stop...\r\n", __func__));
                    set_flg(FLG_ID_IDG2020, IDG2020_FLG_STOP);
                }

            }

            if (uiFlag & IDG2020_FLG_QUEUE_THRESHOLD)
            {
                debug_err(("^R%s: IDG2020_FLG_QUEUE_THRESHOLD\r\n", __func__));
            }

            if (uiFlag & IDG2020_FLG_SEQ_ERR)
            {
                debug_err(("^R%s: IDG2020_FLG_SEQ_ERR: SIE VD is shorter than SPI sequence\r\n", __func__));
                set_flg(FLG_ID_IDG2020, IDG2020_FLG_STOP);
            }

            if (uiFlag & (IDG2020_FLG_HW_OVERRUN|IDG2020_FLG_QUEUE_OVERRUN))
            {
                debug_err(("^R%s: buffer overrun, stop it\r\n", __func__));
                if (uiDumpCount >= 0x1000)
                {
                    set_flg(FLG_ID_IDG2020, IDG2020_FLG_STOP);
                }
            }

            if (uiFlag & IDG2020_FLG_STOP)
            {
                Idg2020_StopPolling();
            }
        }
        else
        {
            debug_err(("^R%s: wait flag err\r\n", __func__));
            SwTimer_DelayMs(500);
        }
    }
}//////////////////~from emu_spiIDG2020.c



//////////////////from emu_spiIDG2020.c
static ER Idg2020_StartPolling(UINT32 uiPeriodUs, UINT32 uiDataNum)
{
    UINT32 i;
    SPI_GYRO_INFO gyroInfo= {0};

    //
    // 1. Prepare data buffer to store polled gyroscope data
    //
    uiDumpCount = 0;
    pNextBuf = (UINT32*)uiDumpBufAddr;

    //
    // 2. Start SPI gyro polling
    //
    gyroInfo.gyroMode = SPI_GYRO_MODE_SIE_SYNC;

    gyroInfo.uiTransferCount = uiFrameGyroCount/2;  // 4 Transfer => Total 8 CS in one frame
    gyroInfo.uiOpInterval       = ((1000000/uiFramePerSec)-uiEOFTime)/uiFrameGyroCount;
    gyroInfo.uiTransferInterval = ((1000000/uiFramePerSec)-uiEOFTime)/uiFrameGyroCount;
    gyroInfo.uiOp0Length = 5;
    gyroInfo.vOp0OutData[0] = REG_READ|REG_GYRO_XOUT_H;
    for (i=1; i<gyroInfo.uiOp0Length; i++)
    {
        gyroInfo.vOp0OutData[i] = 0;
    }

    gyroInfo.uiOp1Length = 5;
    gyroInfo.vOp1OutData[0] = REG_READ|REG_GYRO_XOUT_H;
    for (i=1; i<gyroInfo.uiOp1Length; i++)
    {
        gyroInfo.vOp1OutData[i] = 0;
    }

    gyroInfo.pEventHandler = Idg2020_HandleGyroEvent;

    spi_open(gTestSpiID);

    spi_setTransferLen(gTestSpiID, SPI_TRANSFER_LEN_1BYTE);

    spi_startGyro(gTestSpiID, &gyroInfo);

    return E_OK;
}
//////////////////~from emu_spiIDG2020.c

//////////////////from emu_spiIDG2020.c
static ER Idg2020_StopPolling(void)
{
    spi_stopGyro(gTestSpiID);

    return E_OK;
}
//////////////////~from emu_spiIDG2020.c

//////////////////from emu_spiIDG2020.c
static ER Idg2020_ReadGyroscope(INT16* xOut, INT16* yOut)
{
    UINT32 uiRecv1, uiRecv2;

    if (xOut == NULL)
    {
        return E_MACV;
    }
    if (yOut == NULL)
    {
        return E_MACV;
    }

    spi_open(gTestSpiID);

    spi_setCSActive(gTestSpiID, TRUE);
    spi_setTransferLen(gTestSpiID, SPI_TRANSFER_LEN_1BYTE);
    spi_writeSingle(gTestSpiID, (REG_READ)|(REG_GYRO_XOUT_H));
    spi_setTransferLen(gTestSpiID, SPI_TRANSFER_LEN_2BYTES);
    spi_writeReadSingle(gTestSpiID, 0x00, &uiRecv1);
    spi_writeReadSingle(gTestSpiID, 0x00, &uiRecv2);
    spi_setCSActive(gTestSpiID, FALSE);
        debug_err(("%08x\t%08x\r\n", uiRecv1, uiRecv2));

    spi_close(gTestSpiID);

    *xOut = (INT16)(uiRecv1&0xFFFF);
    *yOut = (INT16)(uiRecv2&0xFFFF);

    return E_OK;
}
//////////////////~from emu_spiIDG2020.c
#endif// 0//mark all follwing

