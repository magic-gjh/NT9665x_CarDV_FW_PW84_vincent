//This source code is generated by UI Designer Studio.

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIFlowWndWrnMsgRes.c"
#include "UIFlowWndWrnMsg.h"
#include "PrjCfg.h"

//---------------------UIFlowWndWrnMsgCtrl Debug Definition -----------------------------
#define _UIFLOWWNDWRNMSG_ERROR_MSG        1
#define _UIFLOWWNDWRNMSG_TRACE_MSG        0

#if (_UIFLOWWNDWRNMSG_ERROR_MSG&(PRJ_DBG_LVL>=PRJ_DBG_LVL_ERR))
#define UIFlowWndWrnMsgErrMsg(...)            debug_msg ("^R UIFlowWndWrnMsg: "__VA_ARGS__)
#else
#define UIFlowWndWrnMsgErrMsg(...)
#endif

#if (_UIFLOWWNDWRNMSG_TRACE_MSG&(PRJ_DBG_LVL>=PRJ_DBG_LVL_TRC))
#define UIFlowWndWrnMsgTraceMsg(...)          debug_msg ("^B UIFlowWndWrnMsg: "__VA_ARGS__)
#else
#define UIFlowWndWrnMsgTraceMsg(...)
#endif

//---------------------UIFlowWndWrnMsgCtrl Global Variables -----------------------------

//---------------------UIFlowWndWrnMsgCtrl Prototype Declaration  -----------------------

//---------------------UIFlowWndWrnMsgCtrl Public API  ----------------------------------

//---------------------UIFlowWndWrnMsgCtrl Private API  ---------------------------------
//---------------------UIFlowWndWrnMsgCtrl Control List---------------------------
CTRL_LIST_BEGIN(UIFlowWndWrnMsg)
CTRL_LIST_ITEM(UIFlowWndWrnMsg_StatusTXT_Msg)
CTRL_LIST_END

//----------------------UIFlowWndWrnMsgCtrl Event---------------------------
INT32 UIFlowWndWrnMsg_OnOpen(VControl *, UINT32, UINT32 *);
INT32 UIFlowWndWrnMsg_OnClose(VControl *, UINT32, UINT32 *);
EVENT_BEGIN(UIFlowWndWrnMsg)
EVENT_ITEM(NVTEVT_OPEN_WINDOW,UIFlowWndWrnMsg_OnOpen)
EVENT_ITEM(NVTEVT_CLOSE_WINDOW,UIFlowWndWrnMsg_OnClose)
EVENT_END

INT32 UIFlowWndWrnMsg_OnOpen(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_OPEN_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
INT32 UIFlowWndWrnMsg_OnClose(VControl *pCtrl, UINT32 paramNum, UINT32 *paramArray)
{
    Ux_DefaultEvent(pCtrl,NVTEVT_CLOSE_WINDOW,paramNum,paramArray);
    return NVTEVT_CONSUME;
}
//----------------------UIFlowWndWrnMsg_StatusTXT_MsgCtrl Event---------------------------
EVENT_BEGIN(UIFlowWndWrnMsg_StatusTXT_Msg)
EVENT_END

