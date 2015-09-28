//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "NVTToolCommand.h"
#include "UIFlowWndUSBRes.c"
//#include "UIFlow.h"
#include "../../../D480x272/UIFlow.h"

#include "UMSDC.h"
#include "UsbDevDef.h"

//#NT#2014/10/16#KS Hung -begin
static UINT32 g_uiMSDCTimerID = NULL_TIMER;
static UINT32 g_uiMSDCTimerCount = 0;
//#NT#2014/10/16#KS Hung -end

//---------------------UIFlowWndUSBCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIFlowWndUSB)
CTRL_LIST_ITEM(UIFlowWndMSDC_StaticTxt_MassStorage)
CTRL_LIST_END

//----------------------UIFlowWndUSBCtrl Event---------------------------
INT32 UIFlowWndUSB_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndUSB_OnClose(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndUSB_OnTimer(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIFlowWndUSB)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIFlowWndUSB_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIFlowWndUSB_OnClose)
EVENT_ITEM(NVTEVT_TIMER,UIFlowWndUSB_OnTimer)
EVENT_END

INT32 UIFlowWndUSB_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    if (paramNum==1)
    {
        if (paramArray[0]==UIFlowWndUSB_PCC_MODE)
        { // show pcc string
            UxStatic_SetData(&UIFlowWndMSDC_StaticTxt_MassStorageCtrl,
                         STATIC_VALUE,STRID_PCC);
        }
        else
        {
            // show msdc string
            UxStatic_SetData(&UIFlowWndMSDC_StaticTxt_MassStorageCtrl,
                         STATIC_VALUE,STRID_MSDC);
            //#NT#2014/10/16#KS Hung -begin
            if (g_uiMSDCTimerID == NULL_TIMER)
            {
                g_uiMSDCTimerID = GxTimer_StartTimer(1000, NVTEVT_1SEC_TIMER, CONTINUE);
            }
            //#NT#2014/10/16#KS Hung -end
        }
    }
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndUSB_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    if (g_uiMSDCTimerID != NULL_TIMER)
    {
        GxTimer_StopTimer(&g_uiMSDCTimerID);
    }
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndUSB_OnTimer(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32  uiEvent;
    MSDC_TASK_STS MsdcStatus;

    //#NT#2014/10/16#KS Hung -begin
    uiEvent = paramNum ? paramArray[0] : 0;
    switch(uiEvent)
    {
    case NVTEVT_1SEC_TIMER:
        MsdcStatus = Msdc_GetStatus();
        if (MsdcStatus == MSDC_CLOSED_STATE)
        {
            g_uiMSDCTimerCount++;
            if (g_uiMSDCTimerCount >= 5)
            {
                g_uiMSDCTimerCount = 0;
                if (g_uiMSDCTimerID != NULL_TIMER)
                {
                    GxTimer_StopTimer(&g_uiMSDCTimerID);
                }
                Ux_PostEvent(NVTEVT_SYSTEM_MODE, 1, PRIMARY_MODE_MOVIE);
            }
        }
        else
        {
            g_uiMSDCTimerCount = 0;
            if (g_uiMSDCTimerID != NULL_TIMER)
            {
                GxTimer_StopTimer(&g_uiMSDCTimerID);
            }
        }
        break;
    }
    //#NT#2014/10/16#KS Hung -end

    return NVTEVT_CONSUME;
}
//----------------------UIFlowWndMSDC_StaticTxt_MassStorageCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndMSDC_StaticTxt_MassStorage)
EVENT_END

