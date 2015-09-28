//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIMenuWndUSBRes.c"
#include "UIMenuWndUSB.h"
#include "AppControl.h"
#include "SysCommon.h"
#include "UICommon.h"
//#include "UIFlow.h"
#include "../../../D480x272/UIFlow.h"

//---------------------UIMenuWndUSBCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndUSB)
CTRL_LIST_ITEM(UIMenuWndUSB_Background)
CTRL_LIST_ITEM(UIMenuWndUSB_TitleBar)
CTRL_LIST_ITEM(UIMenuWndUSB_TipsBar)
CTRL_LIST_ITEM(UIMenuWndUSB_Item)
CTRL_LIST_END

//----------------------UIMenuWndUSBCtrl Event---------------------------
INT32 UIMenuWndUSB_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndUSB_OnClose(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndUSB_OnChildClose(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndUSB_OnTimer(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndUSB)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIMenuWndUSB_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIMenuWndUSB_OnClose)
EVENT_ITEM(NVTEVT_CHILD_CLOSE,UIMenuWndUSB_OnChildClose)
EVENT_ITEM(NVTEVT_TIMER,UIMenuWndUSB_OnTimer)
EVENT_END

//#NT#2014/9/3#Philex Lin - begin
// add time out mechanism to back to movei mode if nothing does in usb mode
#define TimeOut_Sec     10
static UINT32  g_uiTimeOutCount = 0;
static UINT32  g_uiTimeOutTimerID = NULL_TIMER;
//#NT#2014/9/3#Philex Lin - end
INT32 UIMenuWndUSB_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Input_SetKeyMask(KEY_RELEASE, FLGKEY_KEY_MASK_NULL);
    //#NT#2014/9/3#Philex Lin - begin
    // add time out mechanism to back to movei mode if nothing does in usb mode
    // start timeout timer in usb mode
    if (g_uiTimeOutTimerID==NULL_TIMER)
    {
        g_uiTimeOutTimerID = GxTimer_StartTimer(TIMER_ONE_SEC, NVTEVT_1SEC_TIMER, CONTINUE);
    }
    //#NT#2014/9/3#Philex Lin - end
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndUSB_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    //#NT#2014/9/3#Philex Lin - begin
    // Stop timeout timer in usb mode
    if (g_uiTimeOutTimerID!=NULL_TIMER)
    {
        GxTimer_StopTimer(&g_uiTimeOutTimerID);
    }
    //#NT#2014/9/3#Philex Lin - end
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndUSB_OnChildClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_CHILD_CLOSE,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
//#NT#2014/9/3#Philex Lin - begin
// add time out mechanism to back to movei mode if nothing does in usb mode
INT32 UIMenuWndUSB_OnTimer(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32  uiEvent;

    uiEvent = paramNum ? paramArray[0] : 0;

    switch(uiEvent)
    {
    case NVTEVT_1SEC_TIMER:
        g_uiTimeOutCount++;
        // go to movie mode directly if nothing does in USB menu
        if (g_uiTimeOutCount>=TimeOut_Sec)
        {
            g_uiTimeOutCount = 0;
            SysSetFlag(FL_MOVIE_USBRETURN,         TRUE);
            Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, PRIMARY_MODE_MOVIE);
        }
        break;
    }

    return NVTEVT_CONSUME;
}
//#NT#2014/9/3#Philex Lin - end
//---------------------UIMenuWndUSB_BackgroundCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndUSB_Background)
CTRL_LIST_END

//----------------------UIMenuWndUSB_BackgroundCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndUSB_Background)
EVENT_END

//---------------------UIMenuWndUSB_TitleBarCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndUSB_TitleBar)
CTRL_LIST_ITEM(UIMenuWndUSB_TitleName)
CTRL_LIST_END

//----------------------UIMenuWndUSB_TitleBarCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndUSB_TitleBar)
EVENT_END

//----------------------UIMenuWndUSB_TitleNameCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndUSB_TitleName)
EVENT_END

//---------------------UIMenuWndUSB_TipsBarCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndUSB_TipsBar)
CTRL_LIST_ITEM(UIMenuWndUSB_UDOKTips)
CTRL_LIST_END

//----------------------UIMenuWndUSB_TipsBarCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndUSB_TipsBar)
EVENT_END

//---------------------UIMenuWndUSB_UDOKTipsCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIMenuWndUSB_UDOKTips)
CTRL_LIST_END

//----------------------UIMenuWndUSB_UDOKTipsCtrl Event---------------------------
EVENT_BEGIN(UIMenuWndUSB_UDOKTips)
EVENT_END

//----------------------UIMenuWndUSB_ItemCtrl Event---------------------------
INT32 UIMenuWndUSB_Item_OnKeyUp(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndUSB_Item_OnKeyDown(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndUSB_Item_OnKeyEnter(VControl *, UINT32, UINT32 *);
INT32 UIMenuWndUSB_Item_OnKeyShutter2(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIMenuWndUSB_Item)
EVENT_ITEM(NVTEVT_KEY_UP,UIMenuWndUSB_Item_OnKeyUp)
EVENT_ITEM(NVTEVT_KEY_DOWN,UIMenuWndUSB_Item_OnKeyDown)
EVENT_ITEM(NVTEVT_KEY_ENTER,UIMenuWndUSB_Item_OnKeyEnter)
#if((_MODEL_DSC_ == _MODEL_CARDV_B50_)||(_MODEL_DSC_== _MODEL_DUAL_NAZHIDA_))
EVENT_ITEM(NVTEVT_KEY_CUSTOM1,UIMenuWndUSB_Item_OnKeyShutter2)
#else
EVENT_ITEM(NVTEVT_KEY_SHUTTER2,UIMenuWndUSB_Item_OnKeyShutter2)
#endif
EVENT_END

INT32 UIMenuWndUSB_Item_OnKeyUp(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    g_uiTimeOutCount=0;
    Ux_SendEvent(pCtrl,NVTEVT_PREVIOUS_ITEM,0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndUSB_Item_OnKeyDown(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    g_uiTimeOutCount=0;
    Ux_SendEvent(pCtrl,NVTEVT_NEXT_ITEM,0);
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndUSB_Item_OnKeyEnter(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    UINT32  item;

    g_uiTimeOutCount=0;
    item = UxMenu_GetData(pCtrl,MNU_CURITM);
    if(item == UIMenuWndUSB_Item_STRID_MSDC)
    {
        Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, PRIMARY_MODE_USBMSDC);
    }
    else if(item == UIMenuWndUSB_Item_STRID_PCC)
    {
        Ux_SendEvent(0, NVTEVT_SYSTEM_MODE, 1, PRIMARY_MODE_USBPCC);
    }
    return NVTEVT_CONSUME;
}
INT32 UIMenuWndUSB_Item_OnKeyShutter2(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    // the same behavior as ENTER key!
    return UIMenuWndUSB_Item_OnKeyEnter(pCtrl, paramNum, paramArray);
}
