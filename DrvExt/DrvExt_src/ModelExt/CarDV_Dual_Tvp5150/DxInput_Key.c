/**
    Copyright   Novatek Microelectronics Corp. 2009.  All rights reserved.

    @file       DetKey.c
    @ingroup    mIPRJAPKeyIO

    @brief      Scan key, modedial
                Scan key, modedial

    @note       Nothing.

    @date       2009/04/22
*/

/** \addtogroup mIPRJAPKeyIO */
//@{

#include "DxCfg.h"
#include "IOCfg.h"

#include "DxInput.h"
#include "Debug.h"
#include "KeyDef.h"
#include "Rtc.h"
#include "IrRx.h"
#include "IrRxParser.h"

#define GPIO_KEY            DISABLE//ENABLE
#define ADC_KEY             ENABLE
#define IRRX_KEY            DISABLE//ENABLE//DISABLE

#define PW84_KEY_BOARD_D_V01   1   // 5 keys 
#define PW84_KEY_BOARD_V02   2   // 6 keys 
#define PW84_KEY_BOARD_AIDUOSHI_6KEYS   3//爱多士
#define PW84_KEY_BOARD_H510   4   // 5 keys 
#define PW84_KEY_BOARD_MUBEN   5   // 牧本5 keys 
#define PW84_KEY_BOARD_SAIBOSHI   6  // 赛博士 6 keys 
#define PW84_KEY_BOARD_M1   7   // M1  5 keys 
#define PW84_KEY_BOARD_F5   8   // E车E拍F5  7 keys 
#define PW84_KEY_BOARD_NM   9  // NM  6 keys 
#define PW84_KEY_BOARD_ZHENGFUZHE   10  //征服者5 keys
#define PW84_KEY_BOARD_HLYD   11  //5 keys
#define PW84_KEY_BOARD_F84   12  //5 keys 
#define PW84_KEY_BOARD_NANYANG   13  //5 keys   南洋按键
#define PW84_KEY_BOARD_PW8403   14  //5 keys   牧本第二套模具
#define PW84_KEY_BOARD_MUBEN_FLIPUPDOWN   15   // 牧本5 keys 

 
#define KEY_BOARD_TYPE   PW84_KEY_BOARD_MUBEN_FLIPUPDOWN// PW84_KEY_BOARD_AIDUOSHI_6KEYS//

///////////////////////////////////////////////////////////////////////////////
#define __MODULE__          DxDrv 
#define __DBGLVL__          1 // 0=OFF, 1=ERROR, 2=TRACE
#define __DBGFLT__          "*" //*=All, [mark]=CustomClass
#include "DebugModule.h"
///////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
// ADC related
////////////////////////////////////////////////////////////////////////////////
// ADC related
//#NT#2009/11/16#Lincy -begin
#if (ADC_KEY == ENABLE)
#if(KEY_BOARD_TYPE==PW84_KEY_BOARD_D_V01)
#define VOLDET_KEY_ADC_RANGE        (25)
#define VOLDET_KEY_ADC_LVL0         (0)
#define VOLDET_KEY_ADC_LVL1         (175-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL2         (348-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL3         (516-VOLDET_KEY_ADC_RANGE)
//#define VOLDET_KEY_ADC_LVL4         (950-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_TH           (516+VOLDET_KEY_ADC_RANGE)
#elif(KEY_BOARD_TYPE==PW84_KEY_BOARD_V02)
#define VOLDET_KEY_ADC_RANGE        (25)
#define VOLDET_KEY_ADC_LVL0         (0)
#define VOLDET_KEY_ADC_LVL1         (170-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL2         (345-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL3         (510-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL4         (950-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_TH           (950+VOLDET_KEY_ADC_RANGE)
#elif(KEY_BOARD_TYPE==PW84_KEY_BOARD_H510)
#define VOLDET_KEY_ADC_RANGE        (25)
#define VOLDET_KEY_ADC_LVL0         (0)
#define VOLDET_KEY_ADC_LVL1         (175-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL2         (348-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL3         (514-VOLDET_KEY_ADC_RANGE)
//#define VOLDET_KEY_ADC_LVL4         (950-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_TH           (516+VOLDET_KEY_ADC_RANGE)
#elif(KEY_BOARD_TYPE==PW84_KEY_BOARD_MUBEN)
#define VOLDET_KEY_ADC_RANGE        (25)
#define VOLDET_KEY_ADC_LVL0         (0)
#define VOLDET_KEY_ADC_LVL1         (172-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL2         (348-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL3         (514-VOLDET_KEY_ADC_RANGE)
//#define VOLDET_KEY_ADC_LVL4         (950-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_TH           (516+VOLDET_KEY_ADC_RANGE)
#elif(KEY_BOARD_TYPE==PW84_KEY_BOARD_MUBEN_FLIPUPDOWN)
#define VOLDET_KEY_ADC_RANGE        (25)
#define VOLDET_KEY_ADC_LVL0         (0)
#define VOLDET_KEY_ADC_LVL1         (172-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL2         (348-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL3         (514-VOLDET_KEY_ADC_RANGE)
//#define VOLDET_KEY_ADC_LVL4         (950-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_TH           (516+VOLDET_KEY_ADC_RANGE)
#elif(KEY_BOARD_TYPE==PW84_KEY_BOARD_AIDUOSHI_6KEYS)
#define VOLDET_KEY_ADC_RANGE        (25)
#define VOLDET_KEY_ADC_LVL0         (0)
#define VOLDET_KEY_ADC_LVL1         (174-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL2         (346-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL3         (516-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL4         (958-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_TH           (950+VOLDET_KEY_ADC_RANGE)
#elif(KEY_BOARD_TYPE==PW84_KEY_BOARD_SAIBOSHI)
#define VOLDET_KEY_ADC_RANGE        (25)
#define VOLDET_KEY_ADC_LVL0         (0)
#define VOLDET_KEY_ADC_LVL1         (465-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL2         (672-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL3         (828-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL4         (936-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_TH           (950+VOLDET_KEY_ADC_RANGE)
#elif(KEY_BOARD_TYPE==PW84_KEY_BOARD_M1)
#define VOLDET_KEY_ADC_RANGE        (25)
#define VOLDET_KEY_ADC_LVL0         (0)
#define VOLDET_KEY_ADC_LVL1         (174-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL2         (369-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL3         (516-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_TH           (516+VOLDET_KEY_ADC_RANGE)
#elif(KEY_BOARD_TYPE==PW84_KEY_BOARD_F5)
#define VOLDET_KEY_ADC_RANGE        (25)
#define VOLDET_KEY_ADC_LVL0         (0)
#define VOLDET_KEY_ADC_LVL1         (176-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL2         (350-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL3         (516-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL4         (642-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL5         (755-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_TH           (755+VOLDET_KEY_ADC_RANGE)
#elif(KEY_BOARD_TYPE==PW84_KEY_BOARD_NM)
#define VOLDET_KEY_ADC_RANGE        (25)
#define VOLDET_KEY_ADC_LVL0         (0)
#define VOLDET_KEY_ADC_LVL1         (176-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL2         (350-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL3         (516-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL4         (958-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_TH           (958+VOLDET_KEY_ADC_RANGE)
#elif(KEY_BOARD_TYPE==PW84_KEY_BOARD_ZHENGFUZHE)
#define VOLDET_KEY_ADC_RANGE        (25)
#define VOLDET_KEY_ADC_LVL0         (0)
#define VOLDET_KEY_ADC_LVL1         (300-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL2         (522-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL3         (690-VOLDET_KEY_ADC_RANGE)
//#define VOLDET_KEY_ADC_LVL4         (950-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_TH           (690+VOLDET_KEY_ADC_RANGE)
#elif(KEY_BOARD_TYPE==PW84_KEY_BOARD_HLYD)
#define VOLDET_KEY_ADC_RANGE        (25)
#define VOLDET_KEY_ADC_LVL0         (0)
#define VOLDET_KEY_ADC_LVL1         (372-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL2         (598-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL3         (784-VOLDET_KEY_ADC_RANGE)
//#define VOLDET_KEY_ADC_LVL4         (950-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_TH           (784+VOLDET_KEY_ADC_RANGE)
#elif(KEY_BOARD_TYPE==PW84_KEY_BOARD_F84)
#define VOLDET_KEY_ADC_RANGE        (25)
#define VOLDET_KEY_ADC_LVL0         (0)
#define VOLDET_KEY_ADC_LVL1         (174-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL2         (348-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL3         (516-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_TH           (516+VOLDET_KEY_ADC_RANGE)
#elif(KEY_BOARD_TYPE==PW84_KEY_BOARD_NANYANG)
#define VOLDET_KEY_ADC_RANGE        (25)
#define VOLDET_KEY_ADC_LVL0         (0)
#define VOLDET_KEY_ADC_LVL1         (348-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL2         (595-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL3         (760-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_TH           (760+VOLDET_KEY_ADC_RANGE)
#elif(KEY_BOARD_TYPE==PW84_KEY_BOARD_PW8403)
#define VOLDET_KEY_ADC_RANGE        (25)
#define VOLDET_KEY_ADC_LVL0         (0)
#define VOLDET_KEY_ADC_LVL1         (370-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL2         (595-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_LVL3         (784-VOLDET_KEY_ADC_RANGE)
#define VOLDET_KEY_ADC_TH           (784+VOLDET_KEY_ADC_RANGE)
#endif

#define VOLDET_KEY_LVL_UNKNOWN      0xFFFFFFFF
#define VOLDET_KEY_LVL_MENU         0
#define VOLDET_KEY_LVL_REC          1
#define VOLDET_KEY_LVL_UP           2
#define VOLDET_KEY_LVL_DOWN         3
#define VOLDET_KEY_LVL_MODE           4
#define VOLDET_KEY_LVL_SHUTTER2         5
#define VOLDET_KEY_LVL_CUSTOMER       6
#endif

#define VOLDET_MS_ADC_RANGE         (60)
#define VOLDET_MS_ADC_LVL0          (0)
#define VOLDET_MS_ADC_LVL1          (262-VOLDET_MS_ADC_RANGE)
#define VOLDET_MS_ADC_LVL2          (525-VOLDET_MS_ADC_RANGE)
#define VOLDET_MS_ADC_LVL3          (788-VOLDET_MS_ADC_RANGE)
#define VOLDET_MS_ADC_TH            (788+VOLDET_MS_ADC_RANGE)

#define VOLDET_MS_LVL_UNKNOWN           0xFFFFFFFF
#define VOLDET_MS_LVL_0                 0
#define VOLDET_MS_LVL_1                 1 
#define VOLDET_MS_LVL_2                 2
#define VOLDET_MS_LVL_3                 3
#define VOLDET_MS_LVL_4                 4
#define VOLDET_MS_LVL_5                 5

#if (ADC_KEY == ENABLE)
static UINT32 VolDet_GetKey1ADC(void)
{
#if (VOLDET_ADC_CONT_MODE == DISABLE)
    UINT32 uiADCValue;

    uiADCValue = adc_readData(ADC_CH_VOLDET_KEY1);
    // One-Shot Mode, trigger one-shot
    adc_triggerOneShot(ADC_CH_VOLDET_KEY1);

    return uiADCValue;
#else
    return adc_readData(ADC_CH_VOLDET_KEY1);
#endif
}

static UINT32 VolDet_GetKey2ADC(void)
{
#if (VOLDET_ADC_CONT_MODE == DISABLE)
    UINT32 uiADCValue;

    uiADCValue = adc_readData(ADC_CH_VOLDET_KEY2);
    // One-Shot Mode, trigger one-shot
    adc_triggerOneShot(ADC_CH_VOLDET_KEY2);

    return uiADCValue;
#else
    return adc_readData(ADC_CH_VOLDET_KEY2);
#endif
}


/**
  Get ADC key voltage level

  Get  ADC key  2 voltage level.

  @param void
  @return UINT32 key level, refer to VoltageDet.h -> VOLDET_MS_LVL_XXXX
*/
static UINT32 VolDet_GetKey1Level(void)
{
    static UINT32   uiRetKey1Lvl;
    UINT32          uiKey1ADC, uiCurKey2Lvl;

    uiKey1ADC = VolDet_GetKey1ADC();
    //if (uiKey1ADC <1000)
       // debug_msg("uiKey1ADC %d \r\n", uiKey1ADC);
    if (uiKey1ADC < VOLDET_KEY_ADC_TH)
    {
#if(KEY_BOARD_TYPE==PW84_KEY_BOARD_D_V01) 
        if (uiKey1ADC >= VOLDET_KEY_ADC_LVL3)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_SHUTTER2;
        }    
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL2)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UP;
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL1)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_DOWN;
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL0)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_MODE;
        }
        else
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UNKNOWN;
        }
#elif(KEY_BOARD_TYPE==PW84_KEY_BOARD_V02)     
        if (uiKey1ADC >= VOLDET_KEY_ADC_LVL4)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_MENU;
        }    
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL3)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_MODE;
        }    
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL2)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UP;
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL1)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_DOWN;
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL0)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_SHUTTER2;
        }
        else
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UNKNOWN;
        }
#elif(KEY_BOARD_TYPE==PW84_KEY_BOARD_H510) 
        if (uiKey1ADC >= VOLDET_KEY_ADC_LVL3)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_MODE;
        }    
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL2)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_DOWN;
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL1)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UP;
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL0)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_SHUTTER2;
        }
        else
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UNKNOWN;
        }		
#elif(KEY_BOARD_TYPE==PW84_KEY_BOARD_MUBEN) 
        if (uiKey1ADC >= VOLDET_KEY_ADC_LVL3)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_SHUTTER2;
        }    
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL2)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UP;
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL1)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_DOWN;
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL0)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_MENU;
        }
        else
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UNKNOWN;
        }		
#elif(KEY_BOARD_TYPE==PW84_KEY_BOARD_MUBEN_FLIPUPDOWN) 
        if (uiKey1ADC >= VOLDET_KEY_ADC_LVL3)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_SHUTTER2;
        }    
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL2)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_DOWN;
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL1)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UP;
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL0)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_MENU;
        }
        else
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UNKNOWN;
        }		
#elif(KEY_BOARD_TYPE==PW84_KEY_BOARD_AIDUOSHI_6KEYS)     
        if (uiKey1ADC >= VOLDET_KEY_ADC_LVL4)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_SHUTTER2;
        }    
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL3)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_DOWN;
        }    
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL2)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UP;
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL1)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_MODE;
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL0)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_MENU;
        }
        else
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UNKNOWN;
        }	
#elif(KEY_BOARD_TYPE==PW84_KEY_BOARD_SAIBOSHI)
        if (uiKey1ADC >= VOLDET_KEY_ADC_LVL4)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_MENU;
        }    
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL3)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_MODE;
        }    
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL2)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UP;
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL1)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_SHUTTER2;
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL0)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_DOWN;
        }
        else
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UNKNOWN;
        }			
#elif(KEY_BOARD_TYPE==PW84_KEY_BOARD_M1)
        if (uiKey1ADC >= VOLDET_KEY_ADC_LVL3)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_SHUTTER2;
        }    
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL2)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UP;
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL1)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_DOWN;
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL0)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_MODE;
        }
        else
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UNKNOWN;
        }			
#elif(KEY_BOARD_TYPE==PW84_KEY_BOARD_F5)
        if (uiKey1ADC >= VOLDET_KEY_ADC_LVL5)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_CUSTOMER;
		debug_msg("KEY CUSTOMER1..\r\n");
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL4)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_MODE;
		debug_msg("KEY MODE..\r\n");			
        }    
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL3)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_DOWN;
		debug_msg("KEY DOWN..\r\n");			
        }    
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL2)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_SHUTTER2;
		debug_msg("KEY SHUTTER2..\r\n");			
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL1)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UP;
		debug_msg("KEY UP..\r\n");			
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL0)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_MENU;
		debug_msg("KEY MENU..\r\n");			
        }
        else
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UNKNOWN;
        }	
#elif(KEY_BOARD_TYPE==PW84_KEY_BOARD_NM)
        if (uiKey1ADC >= VOLDET_KEY_ADC_LVL4)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_SHUTTER2;
		//debug_msg("KEY MODE..\r\n");			
        }    
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL3)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UP;
		//debug_msg("KEY DOWN..\r\n");			
        }    
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL2)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_DOWN;
		//debug_msg("KEY SHUTTER2..\r\n");			
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL1)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_MENU;
		//debug_msg("KEY UP..\r\n");			
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL0)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_MODE;
		//debug_msg("KEY MENU..\r\n");			
        }
        else
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UNKNOWN;
        }		
#elif(KEY_BOARD_TYPE==PW84_KEY_BOARD_ZHENGFUZHE) 
        if (uiKey1ADC >= VOLDET_KEY_ADC_LVL3)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_SHUTTER2;
        }    
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL2)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UP;
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL1)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_DOWN;
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL0)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_MENU;
        }
        else
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UNKNOWN;
        }		
#elif(KEY_BOARD_TYPE==PW84_KEY_BOARD_HLYD) 
        if (uiKey1ADC >= VOLDET_KEY_ADC_LVL3)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_DOWN;
        }    
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL2)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UP;
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL1)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_MENU;
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL0)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_SHUTTER2;
        }
        else
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UNKNOWN;
        }		
#elif(KEY_BOARD_TYPE==PW84_KEY_BOARD_F84)      
        if (uiKey1ADC >= VOLDET_KEY_ADC_LVL3)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_SHUTTER2;
        }    
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL2)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_DOWN;
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL1)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UP;
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL0)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_MODE;
        }
        else
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UNKNOWN;
        }		
#elif(KEY_BOARD_TYPE==PW84_KEY_BOARD_NANYANG)      
        if (uiKey1ADC >= VOLDET_KEY_ADC_LVL3)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_SHUTTER2;
        }    
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL2)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_DOWN;
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL1)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UP;
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL0)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_MODE;
        }
        else
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UNKNOWN;
        }		
#elif(KEY_BOARD_TYPE==PW84_KEY_BOARD_PW8403)      
        if (uiKey1ADC >= VOLDET_KEY_ADC_LVL3)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_SHUTTER2;
        }    
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL2)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_DOWN;
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL1)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UP;
        }
        else if (uiKey1ADC >= VOLDET_KEY_ADC_LVL0)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_MODE;
        }
        else
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UNKNOWN;
        }		
#endif			
    }
    else
    {
        uiCurKey2Lvl = VOLDET_KEY_LVL_UNKNOWN;
    }

    uiRetKey1Lvl = uiCurKey2Lvl;

    return uiRetKey1Lvl;
}

static UINT32 VolDet_GetKey2Level(void)
{
    static UINT32   uiRetKey1Lvl;
    UINT32          uiKey2ADC, uiCurKey2Lvl;

    uiKey2ADC = VolDet_GetKey2ADC();
    if (uiKey2ADC <1000)
        DBG_IND("uiKey2ADC %d \r\n", uiKey2ADC);
    if (uiKey2ADC < VOLDET_KEY_ADC_TH)
    {
        if (uiKey2ADC >= VOLDET_KEY_ADC_LVL2)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_REC;
        }
        else if (uiKey2ADC >= VOLDET_KEY_ADC_LVL1)
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_MENU;
        }
        else
        {
            uiCurKey2Lvl = VOLDET_KEY_LVL_UNKNOWN;
        }
    }
    else
    {
        uiCurKey2Lvl = VOLDET_KEY_LVL_UNKNOWN;
    }

    uiRetKey1Lvl = uiCurKey2Lvl;

    return uiRetKey1Lvl;
}

#endif

/**
  Get IrRx key

  Get IrRx key.

  @param void
  @return UINT32 key level, refer to VoltageDet.h -> VOLDET_MS_LVL_XXXX
*/
#if (IRRX_KEY == ENABLE)
static BOOL IrRxDet_Key(UINT32 *uiKey)
{
  IRRX_DATA_QUEUE IrRxGetDataQ = {0, 0, 0};
  static UINT32 uiIrRxData = 0;
  static UINT32 uiPreIrRxData = 0;

    if(irrx_dequeueData((PIRRX_DATA_QUEUE)&IrRxGetDataQ))
    {
        uiIrRxData = IrRxGetDataQ.uiRxData;
        debug_ind(("IrRx(%010lu): CODE: 0x%08X\r\n", IrRxGetDataQ.uiRxTime, uiIrRxData));

        *uiKey = IrRx_ParseKey(g_pIrCodeTb, uiIrRxData);
        uiPreIrRxData = *uiKey;
         return TRUE;

    } else if (uiPreIrRxData!=0)
    {
        // return IR key one more time because keyscan time interval is smaller than IR key scan time interval
        // and this will get zero value when keyscan task get data the sencondary time
        *uiKey = uiPreIrRxData;
        // clear uiPreIrRxData
        uiPreIrRxData = 0;
        return TRUE;
    }
    *uiKey = 0;
    return FALSE;
}
#endif

////////////////////////////////////////////////////////////////////////////////
// GPIO related

//static BOOL g_bIsShutter2Pressed = FALSE;



/**
  Delay between toggle GPIO pin of input/output

  Delay between toggle GPIO pin of input/output

  @param void
  @return void
*/
static void DrvKey_DetKeyDelay(void)
{
    gpio_readData(0);
    gpio_readData(0);
    gpio_readData(0);
    gpio_readData(0);
}


void DrvKey_Init(void)
{
}
/**
  Detect normal key is pressed or not.

  Detect normal key is pressed or not.
  Return key pressed status (refer to KeyDef.h)

  @param void
  @return UINT32
*/
UINT32 DrvKey_DetNormalKey(void)
{
    UINT32 uiKeyCode = 0;
#if (IRRX_KEY==ENABLE)
    static UINT32 uiIrRxKey = 0;
#endif

#if (ADC_KEY == ENABLE)
    if (VolDet_GetKey1Level() == VOLDET_KEY_LVL_UP)
    {
        uiKeyCode |= FLGKEY_UP;
    }
    if (VolDet_GetKey1Level() == VOLDET_KEY_LVL_DOWN)
    {
        uiKeyCode |= FLGKEY_DOWN;
    }
    if (VolDet_GetKey1Level() == VOLDET_KEY_LVL_MENU)
    {
        uiKeyCode |= FLGKEY_MENU;
    }	
    if (VolDet_GetKey1Level() == VOLDET_KEY_LVL_MODE)
    {
        uiKeyCode |= FLGKEY_MODE;
    }	
    if (VolDet_GetKey1Level() == VOLDET_KEY_LVL_SHUTTER2)
    {
        uiKeyCode |= FLGKEY_SHUTTER2;
    }
    if (VolDet_GetKey1Level() == VOLDET_KEY_LVL_CUSTOMER)
    {
        uiKeyCode |= FLGKEY_CUSTOM1;
    }	
#endif
#if (GPIO_KEY == ENABLE)
    if(!gpio_getPin(GPIO_KEY_MODE))
    {
        uiKeyCode |= FLGKEY_MODE;
    }
#endif
/*
    //detect if power-on by press playback key
    if (!rtc_getPWR2Status())
    {
        uiKeyCode |= FLGKEY_PLAYBACK;
    }
*/
#if (IRRX_KEY==ENABLE)
        if (IrRxDet_Key(&uiIrRxKey)==TRUE)
        {
            uiKeyCode |= uiIrRxKey;
        }
#endif
    DBG_IND("KEY=%08x\r\n", uiKeyCode);

    DrvKey_DetKeyDelay();
    return uiKeyCode;
}

/**
  Detect power key is pressed or not.

  Detect power key is pressed or not.
  Return key pressed status (refer to KeyDef.h)

  @param void
  @return UINT32
*/
UINT32 DrvKey_DetPowerKey(void)
{
    UINT32 uiKeyCode = 0;

    if(rtc_getPWRStatus())
    {
        uiKeyCode = FLGKEY_KEY_POWER;
        // Reset shutdown timer
        rtc_resetShutdownTimer();
    }

    return uiKeyCode;
}

UINT32 DrvKey_DetStatusKey(DX_STATUS_KEY_GROUP KeyGroup)
{
    UINT32 uiReturn = STATUS_KEY_LVL_UNKNOWN;
    switch (KeyGroup)
    {
        case DX_STATUS_KEY_GROUP1:
            break;

        case DX_STATUS_KEY_GROUP2:
            break;

        case DX_STATUS_KEY_GROUP3:
            break;

        case DX_STATUS_KEY_GROUP4:
            break;

        case DX_STATUS_KEY_GROUP5:
            break;

        default:
            DBG_ERR("[StatusKey]no this attribute");
            break;
    }
    return uiReturn;
}
