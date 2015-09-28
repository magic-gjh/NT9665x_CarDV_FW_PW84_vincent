//This source code is generated by UI Designer Studio.

#ifndef UIFLOWWNDMOVIERES_H
#define UIFLOWWNDMOVIERES_H

#include "UIFramework.h"
#include "UIFrameworkExt.h"
#include "UIGraphics.h"
#include "NVTToolCommand.h"
#include "UIDisplayUtil.h"
//------------------------------------------------------------

SHOW_ITEM_RECT(CMD_Rectangle,Skin1Rect,0,0,319,239,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin1)
SHOW_MAP_BODY(Skin1Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin1,0,0,319,239)

SHOW_MAP_BEGIN(Skin3)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin3,0,0,29,29)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon4, 1, 1, 11,15, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal2)
SHOW_MAP_BODY(Skin3)
SHOW_MAP_BODY(Icon4)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal2,12,5,41,34)

SHOW_MAP_BEGIN(UIFlowWndMovie_Static_camera)
SHOW_MAP_BODY(Normal2)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Static_camera)
CREATE_STATIC_DATA(UIFlowWndMovie_Static_camera,ICON_MODE_VIDEO)
CREATE_STATIC_CTRL(UIFlowWndMovie_Static_camera,0,12,5,41,34)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin7Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin7)
SHOW_MAP_BODY(Skin7Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin7,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon8, 0, 0, 27,27, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal6)
SHOW_MAP_BODY(Skin7)
SHOW_MAP_BODY(Icon8)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal6,12,38,39,65)

CREATE_STATE_ITEM_DATA(ICONID_NULL9,STRID_NULL,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(ICON_CYCLIC_REC_3MIN10,STRID_NULL,ICON_CYCLIC_REC_3MIN,NULL) 
CREATE_STATE_ITEM_DATA(ICON_CYCLIC_REC_5MIN11,STRID_NULL,ICON_CYCLIC_REC_5MIN,NULL) 
CREATE_STATE_ITEM_DATA(ICON_CYCLIC_REC_10MIN12,STRID_NULL,ICON_CYCLIC_REC_10MIN,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_CyclicRec)
SHOW_MAP_BODY(Normal6)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_CyclicRec)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_CyclicRec)
STATE_LIST_ITEM(ICONID_NULL9)
STATE_LIST_ITEM(ICON_CYCLIC_REC_3MIN10)
STATE_LIST_ITEM(ICON_CYCLIC_REC_5MIN11)
STATE_LIST_ITEM(ICON_CYCLIC_REC_10MIN12)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_CyclicRec,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_CyclicRec,0,12,38,39,65)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin14Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin14)
SHOW_MAP_BODY(Skin14Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin14,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon15, 0, 0, 27,27, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal13)
SHOW_MAP_BODY(Skin14)
SHOW_MAP_BODY(Icon15)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal13,12,71,39,98)

CREATE_STATE_ITEM_DATA(ICONID_NULL16,STRID_NULL,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(ICON_MOTION_ON17,STRID_NULL,ICON_MOTION_ON,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_MotionDet)
SHOW_MAP_BODY(Normal13)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_MotionDet)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_MotionDet)
STATE_LIST_ITEM(ICONID_NULL16)
STATE_LIST_ITEM(ICON_MOTION_ON17)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_MotionDet,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_MotionDet,0,12,71,39,98)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin19Rect,0,0,33,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin19)
SHOW_MAP_BODY(Skin19Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin19,0,0,33,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon20, 0, -1, 31,26, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal18)
SHOW_MAP_BODY(Skin19)
SHOW_MAP_BODY(Icon20)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal18,276,208,309,235)

CREATE_STATE_ITEM_DATA(ICON_BATTERY_FULL21,STRID_NULL,ICON_BATTERY_FULL,NULL) 
CREATE_STATE_ITEM_DATA(ICON_BATTERY_MED22,STRID_NULL,ICON_BATTERY_MED,NULL) 
CREATE_STATE_ITEM_DATA(ICON_BATTERY_LOW23,STRID_NULL,ICON_BATTERY_LOW,NULL) 
CREATE_STATE_ITEM_DATA(ICON_BATTERY_EMPTY24,STRID_NULL,ICON_BATTERY_EMPTY,NULL) 
CREATE_STATE_ITEM_DATA(ICON_BATTERY_ZERO25,STRID_NULL,ICON_BATTERY_ZERO,NULL) 
CREATE_STATE_ITEM_DATA(ICON_BATTERY_CHARGE26,STRID_NULL,ICON_BATTERY_CHARGE,NULL) 
CREATE_STATE_ITEM_DATA(ICON_TRANSPAENT27,STRID_NULL,ICON_TRANSPAENT,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_battery)
SHOW_MAP_BODY(Normal18)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_battery)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_battery)
STATE_LIST_ITEM(ICON_BATTERY_FULL21)
STATE_LIST_ITEM(ICON_BATTERY_MED22)
STATE_LIST_ITEM(ICON_BATTERY_LOW23)
STATE_LIST_ITEM(ICON_BATTERY_EMPTY24)
STATE_LIST_ITEM(ICON_BATTERY_ZERO25)
STATE_LIST_ITEM(ICON_BATTERY_CHARGE26)
STATE_LIST_ITEM(ICON_TRANSPAENT27)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_battery,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_battery,0,276,208,309,235)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin29Rect,0,0,99,20,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin29)
SHOW_MAP_BODY(Skin29Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin29,0,0,99,20)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text31,0,0,99,20,STRID_NULL,0,1280,0,0,2,1,1,0,0,16,0,0,0,0)
SHOW_MAP_BEGIN(Normal28)
SHOW_MAP_BODY(Skin29)
SHOW_MAP_BODY(Text31)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal28,80,214,179,234)

SHOW_MAP_BEGIN(UIFlowWndMovie_YMD_Static)
SHOW_MAP_BODY(Normal28)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_YMD_Static)
CREATE_STATIC_DATA(UIFlowWndMovie_YMD_Static,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndMovie_YMD_Static,0,80,214,179,234)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin34Rect,0,0,86,20,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin34)
SHOW_MAP_BODY(Skin34Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin34,0,0,86,20)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text36,1,2,84,18,STRID_NULL,0,1280,0,0,2,1,1,0,0,16,0,0,0,0)
SHOW_MAP_BEGIN(Normal33)
SHOW_MAP_BODY(Skin34)
SHOW_MAP_BODY(Text36)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal33,187,214,273,234)

SHOW_MAP_BEGIN(UIFlowWndMovie_HMS_Static)
SHOW_MAP_BODY(Normal33)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_HMS_Static)
CREATE_STATIC_DATA(UIFlowWndMovie_HMS_Static,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndMovie_HMS_Static,0,187,214,273,234)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin39Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin39)
SHOW_MAP_BODY(Skin39Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin39,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon40, 0, 0, 27,27, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal38)
SHOW_MAP_BODY(Skin39)
SHOW_MAP_BODY(Icon40)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal38,280,177,307,204)

CREATE_STATE_ITEM_DATA(ICON_INTERNAL_FLASH41,STRID_NULL,ICON_INTERNAL_FLASH,NULL) 
CREATE_STATE_ITEM_DATA(ICON_SD_CARD42,STRID_NULL,ICON_SD_CARD,NULL) 
CREATE_STATE_ITEM_DATA(ICON_SD_LOCK43,STRID_NULL,ICON_SD_LOCK,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_Storage)
SHOW_MAP_BODY(Normal38)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_Storage)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_Storage)
STATE_LIST_ITEM(ICON_INTERNAL_FLASH41)
STATE_LIST_ITEM(ICON_SD_CARD42)
STATE_LIST_ITEM(ICON_SD_LOCK43)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_Storage,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_Storage,0,280,177,307,204)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin45Rect,0,0,85,29,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin45)
SHOW_MAP_BODY(Skin45Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin45,0,0,85,29)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text47,0,0,85,29,STRID_NULL,0,1280,0,0,2,1,0,0,0,16,0,0,0,0)
SHOW_MAP_BEGIN(Normal44)
SHOW_MAP_BODY(Skin45)
SHOW_MAP_BODY(Text47)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal44,223,5,308,34)

SHOW_MAP_BEGIN(UIFlowWndMovie_Static_time)
SHOW_MAP_BODY(Normal44)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Static_time)
CREATE_STATIC_DATA(UIFlowWndMovie_Static_time,STRID_NULL_)
CREATE_STATIC_CTRL(UIFlowWndMovie_Static_time,0,223,5,308,34)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin50Rect,0,0,85,29,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin50)
SHOW_MAP_BODY(Skin50Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin50,0,0,85,29)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text52,0,0,85,29,STRID_NULL,0,1280,0,0,2,1,1,0,0,16,0,0,0,0)
SHOW_MAP_BEGIN(Normal49)
SHOW_MAP_BODY(Skin50)
SHOW_MAP_BODY(Text52)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal49,223,5,308,34)

SHOW_MAP_BEGIN(UIFlowWndMovie_Static_maxtime)
SHOW_MAP_BODY(Normal49)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Static_maxtime)
CREATE_STATIC_DATA(UIFlowWndMovie_Static_maxtime,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndMovie_Static_maxtime,0,223,5,308,34)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin55Rect,0,0,107,29,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin55)
SHOW_MAP_BODY(Skin55Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin55,0,0,107,29)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text57,1,0,106,29,STRID_NULL,0,1280,0,0,2,1,0,0,0,18,0,0,0,0)
SHOW_MAP_BEGIN(Normal54)
SHOW_MAP_BODY(Skin55)
SHOW_MAP_BODY(Text57)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal54,201,32,308,61)

SHOW_MAP_BEGIN(UIFlowWndMovie_Static_resolution)
SHOW_MAP_BODY(Normal54)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Static_resolution)
CREATE_STATIC_DATA(UIFlowWndMovie_Static_resolution,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndMovie_Static_resolution,0,201,32,308,61)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin60Rect,0,0,43,19,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin60)
SHOW_MAP_BODY(Skin60Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin60,0,0,43,19)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text62,0,0,43,19,STRID_NULL,0,1280,0,0,2,1,1,0,0,16,0,0,0,0)
SHOW_MAP_BEGIN(Normal59)
SHOW_MAP_BODY(Skin60)
SHOW_MAP_BODY(Text62)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal59,12,192,55,211)

SHOW_MAP_BEGIN(UIFlowWndMovie_Zoom_Static)
SHOW_MAP_BODY(Normal59)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Zoom_Static)
CREATE_STATIC_DATA(UIFlowWndMovie_Zoom_Static,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndMovie_Zoom_Static,0,12,192,55,211)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin65Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin65)
SHOW_MAP_BODY(Skin65Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin65,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon66, 0, 0, 27,27, ICONID_NULL,0,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal64)
SHOW_MAP_BODY(Skin65)
SHOW_MAP_BODY(Icon66)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal64,12,137,39,164)

CREATE_STATE_ITEM_DATA(ICON_EV_P2P067,STRID_NULL,ICON_EV_P2P0,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P1P668,STRID_NULL,ICON_EV_P1P6,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P1P369,STRID_NULL,ICON_EV_P1P3,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P1P070,STRID_NULL,ICON_EV_P1P0,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P0P671,STRID_NULL,ICON_EV_P0P6,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P0P372,STRID_NULL,ICON_EV_P0P3,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_P0P073,STRID_NULL,ICON_EV_P0P0,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_M0P374,STRID_NULL,ICON_EV_M0P3,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_M0P675,STRID_NULL,ICON_EV_M0P6,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_M1P076,STRID_NULL,ICON_EV_M1P0,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_M1P377,STRID_NULL,ICON_EV_M1P3,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_M1P678,STRID_NULL,ICON_EV_M1P6,NULL) 
CREATE_STATE_ITEM_DATA(ICON_EV_M2P079,STRID_NULL,ICON_EV_M2P0,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_StatusICN_EV)
SHOW_MAP_BODY(Normal64)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_StatusICN_EV)
STATE_LIST_BEGIN(UIFlowWndMovie_StatusICN_EV)
STATE_LIST_ITEM(ICON_EV_P2P067)
STATE_LIST_ITEM(ICON_EV_P1P668)
STATE_LIST_ITEM(ICON_EV_P1P369)
STATE_LIST_ITEM(ICON_EV_P1P070)
STATE_LIST_ITEM(ICON_EV_P0P671)
STATE_LIST_ITEM(ICON_EV_P0P372)
STATE_LIST_ITEM(ICON_EV_P0P073)
STATE_LIST_ITEM(ICON_EV_M0P374)
STATE_LIST_ITEM(ICON_EV_M0P675)
STATE_LIST_ITEM(ICON_EV_M1P076)
STATE_LIST_ITEM(ICON_EV_M1P377)
STATE_LIST_ITEM(ICON_EV_M1P678)
STATE_LIST_ITEM(ICON_EV_M2P079)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_StatusICN_EV,0)
CREATE_STATE_CTRL(UIFlowWndMovie_StatusICN_EV,0,12,137,39,164)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin81Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin81)
SHOW_MAP_BODY(Skin81Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin81,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon82, 0, 0, 27,27, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal80)
SHOW_MAP_BODY(Skin81)
SHOW_MAP_BODY(Icon82)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal80,80,5,107,32)

CREATE_STATE_ITEM_DATA(ICONID_NULL83,STRID_NULL,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(ICON_HDR84,STRID_NULL,ICON_HDR,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_HDR)
SHOW_MAP_BODY(Normal80)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_HDR)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_HDR)
STATE_LIST_ITEM(ICONID_NULL83)
STATE_LIST_ITEM(ICON_HDR84)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_HDR,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_HDR,0,80,5,107,32)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin86Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin86)
SHOW_MAP_BODY(Skin86Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin86,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon87, 0, 0, 27,27, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal85)
SHOW_MAP_BODY(Skin86)
SHOW_MAP_BODY(Icon87)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal85,112,5,139,32)

SHOW_MAP_BEGIN(UIFlowWndMovie_StaticIcon_PIMC)
SHOW_MAP_BODY(Normal85)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_StaticIcon_PIMC)
CREATE_STATIC_DATA(UIFlowWndMovie_StaticIcon_PIMC,ICON_MODE_CAPTURE)
CREATE_STATIC_CTRL(UIFlowWndMovie_StaticIcon_PIMC,0,112,5,139,32)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin90Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin90)
SHOW_MAP_BODY(Skin90Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin90,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon91, 0, 0, 27,27, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal89)
SHOW_MAP_BODY(Skin90)
SHOW_MAP_BODY(Icon91)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal89,179,5,206,32)

CREATE_STATE_ITEM_DATA(ICON_GPS_NS92,STRID_NULL,ICON_GPS_NS,NULL) 
CREATE_STATE_ITEM_DATA(ICON_GPS_OK93,STRID_NULL,ICON_GPS_OK,NULL) 
CREATE_STATE_ITEM_DATA(ICON_GPS_LEVEL094,STRID_NULL,ICON_GPS_LEVEL0,NULL) 
CREATE_STATE_ITEM_DATA(ICON_GPS_LEVEL195,STRID_NULL,ICON_GPS_LEVEL1,NULL) 
CREATE_STATE_ITEM_DATA(ICON_GPS_LEVEL296,STRID_NULL,ICON_GPS_LEVEL2,NULL) 
CREATE_STATE_ITEM_DATA(ICON_GPS_LEVEL397,STRID_NULL,ICON_GPS_LEVEL3,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_GPS)
SHOW_MAP_BODY(Normal89)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_GPS)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_GPS)
STATE_LIST_ITEM(ICON_GPS_NS92)
STATE_LIST_ITEM(ICON_GPS_OK93)
STATE_LIST_ITEM(ICON_GPS_LEVEL094)
STATE_LIST_ITEM(ICON_GPS_LEVEL195)
STATE_LIST_ITEM(ICON_GPS_LEVEL296)
STATE_LIST_ITEM(ICON_GPS_LEVEL397)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_GPS,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_GPS,0,179,5,206,32)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin99Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin99)
SHOW_MAP_BODY(Skin99Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin99,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon100, 0, 0, 27,27, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal98)
SHOW_MAP_BODY(Skin99)
SHOW_MAP_BODY(Icon100)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal98,280,143,307,170)

CREATE_STATE_ITEM_DATA(ICON_IRLED_OFF101,STRID_NULL,ICON_IRLED_OFF,NULL) 
CREATE_STATE_ITEM_DATA(ICON_IRLED_ON102,STRID_NULL,ICON_IRLED_ON,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_LED)
SHOW_MAP_BODY(Normal98)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_LED)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_LED)
STATE_LIST_ITEM(ICON_IRLED_OFF101)
STATE_LIST_ITEM(ICON_IRLED_ON102)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_LED,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_LED,0,280,143,307,170)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin104Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin104)
SHOW_MAP_BODY(Skin104Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin104,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon105, 0, 0, 27,27, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal103)
SHOW_MAP_BODY(Skin104)
SHOW_MAP_BODY(Icon105)
SHOW_MAP_END

#if(_MODEL_DSC_ == _MODEL_CARDV_K12_)
SHOW_ITEM_GROUP(CMD_Group,Normal103,178,5,205,32)
#else
SHOW_ITEM_GROUP(CMD_Group,Normal103,280,110,307,137)
#endif

CREATE_STATE_ITEM_DATA(ICONID_NULL106,STRID_NULL,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(ICON_TYPE2_SHARPNESS_LOW107,STRID_NULL,ICON_TYPE2_SHARPNESS_LOW,NULL) 
CREATE_STATE_ITEM_DATA(ICON_TYPE2_SHARPNESS_MID108,STRID_NULL,ICON_TYPE2_SHARPNESS_MID,NULL) 
CREATE_STATE_ITEM_DATA(ICON_TYPE2_SHARPNESS_HIGH109,STRID_NULL,ICON_TYPE2_SHARPNESS_HIGH,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_GSENSOR)
SHOW_MAP_BODY(Normal103)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_GSENSOR)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_GSENSOR)
STATE_LIST_ITEM(ICONID_NULL106)
STATE_LIST_ITEM(ICON_TYPE2_SHARPNESS_LOW107)
STATE_LIST_ITEM(ICON_TYPE2_SHARPNESS_MID108)
STATE_LIST_ITEM(ICON_TYPE2_SHARPNESS_HIGH109)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_GSENSOR,0)
#if(_MODEL_DSC_ == _MODEL_CARDV_K12_)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_GSENSOR,0,178,5,205,32)
#else
CREATE_STATE_CTRL(UIFlowWndMovie_Status_GSENSOR,0,280,110,307,137)
#endif


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin111Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin111)
SHOW_MAP_BODY(Skin111Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin111,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon112, 0, 0, 27,27, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal110)
SHOW_MAP_BODY(Skin111)
SHOW_MAP_BODY(Icon112)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal110,146,5,173,32)

SHOW_MAP_BEGIN(UIFlowWndMovie_Static_Lock)
SHOW_MAP_BODY(Normal110)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Static_Lock)
CREATE_STATIC_DATA(UIFlowWndMovie_Static_Lock,ICON_LOCK)
CREATE_STATIC_CTRL(UIFlowWndMovie_Static_Lock,0,146,5,173,32)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin115Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin115)
SHOW_MAP_BODY(Skin115Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin115,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon116, 0, 0, 27,27, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal114)
SHOW_MAP_BODY(Skin115)
SHOW_MAP_BODY(Icon116)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal114,12,170,39,197)

CREATE_STATE_ITEM_DATA(ICON_VOICE_OFF117,STRID_NULL,ICON_VOICE_OFF,NULL) 
CREATE_STATE_ITEM_DATA(ICON_VOICE_ON118,STRID_NULL,ICON_VOICE_ON,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_Audio)
SHOW_MAP_BODY(Normal114)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_Audio)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_Audio)
STATE_LIST_ITEM(ICON_VOICE_OFF117)
STATE_LIST_ITEM(ICON_VOICE_ON118)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_Audio,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_Audio,0,12,170,39,197)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin120Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin120)
SHOW_MAP_BODY(Skin120Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin120,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon121, 0, 0, 27,27, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal119)
SHOW_MAP_BODY(Skin120)
SHOW_MAP_BODY(Icon121)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal119,46,5,73,32)

CREATE_STATE_ITEM_DATA(ICON_TRANSPAENT122,STRID_NULL,ICON_TRANSPAENT,NULL) 
CREATE_STATE_ITEM_DATA(ICON_REC_ELIPPSE123,STRID_NULL,ICON_REC_ELIPPSE,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_REC)
SHOW_MAP_BODY(Normal119)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_REC)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_REC)
STATE_LIST_ITEM(ICON_TRANSPAENT122)
STATE_LIST_ITEM(ICON_REC_ELIPPSE123)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_REC,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_REC,0,46,5,73,32)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin125Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin125)
SHOW_MAP_BODY(Skin125Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin125,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon126, 0, 0, 27,27, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal124)
SHOW_MAP_BODY(Skin125)
SHOW_MAP_BODY(Icon126)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal124,12,104,39,131)

CREATE_STATE_ITEM_DATA(ICON_TRANSPAENT127,STRID_NULL,ICON_TRANSPAENT,NULL) 
CREATE_STATE_ITEM_DATA(ICON_TIMELAPSE_REC_STATUS128,STRID_NULL,ICON_TIMELAPSE_REC_STATUS,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_TimeLapes)
SHOW_MAP_BODY(Normal124)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_TimeLapes)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_TimeLapes)
STATE_LIST_ITEM(ICON_TRANSPAENT127)
STATE_LIST_ITEM(ICON_TIMELAPSE_REC_STATUS128)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_TimeLapes,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_TimeLapes,0,12,104,39,131)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin130Rect,0,0,27,27,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin130)
SHOW_MAP_BODY(Skin130Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin130,0,0,27,27)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon131, 0, 0, 27,27, ICONID_NULL,83886080,0,0,0,0,0,17,0)
SHOW_MAP_BEGIN(Normal129)
SHOW_MAP_BODY(Skin130)
SHOW_MAP_BODY(Icon131)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal129,280,72,307,99)

CREATE_STATE_ITEM_DATA(ICONID_NULL132,STRID_NULL,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(ICON_PARKING_MONITOR133,STRID_NULL,ICON_PARKING_MONITOR,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_ParkingMonitor)
SHOW_MAP_BODY(Normal129)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_ParkingMonitor)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_ParkingMonitor)
STATE_LIST_ITEM(ICONID_NULL132)
STATE_LIST_ITEM(ICON_PARKING_MONITOR133)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_ParkingMonitor,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_ParkingMonitor,0,280,72,307,99)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin135Rect,0,0,169,19,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin135)
SHOW_MAP_BODY(Skin135Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin135,0,0,169,19)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text137,0,0,199,19,STRID_NULL,0,1280,0,0,2,1,1,0,0,16,0,0,0,0)
SHOW_MAP_BEGIN(Normal134)
SHOW_MAP_BODY(Skin135)
SHOW_MAP_BODY(Text137)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal134,86,188,255,207)

SHOW_MAP_BEGIN(UIFlowWndMovie_CarNo_Static)
SHOW_MAP_BODY(Normal134)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_CarNo_Static)
CREATE_STATIC_DATA(UIFlowWndMovie_CarNo_Static,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndMovie_CarNo_Static,0,86,188,255,207)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin140Rect,0,0,20,24,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin140)
SHOW_MAP_BODY(Skin140Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin140,0,0,20,24)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text142,0,0,20,24,STRID_NULL,0,0,0,0,2,1,1,0,0,17,0,0,0,0)
SHOW_MAP_BEGIN(Normal139)
SHOW_MAP_BODY(Skin140)
SHOW_MAP_BODY(Text142)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal139,65,187,85,211)

CREATE_STATE_ITEM_DATA(STRID_NULL_143,STRID_NULL_,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_4E91144,STRID_4E91,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_4EAC145,STRID_4EAC,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_5B81146,STRID_5B81,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_5DDD147,STRID_5DDD,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_6CAA148,STRID_6CAA,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_6D25149,STRID_6D25,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_6D59150,STRID_6D59,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_6E1D151,STRID_6E1D,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_6E58152,STRID_6E58,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_7CA4153,STRID_7CA4,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_8C6B154,STRID_8C6B,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_8D35155,STRID_8D35,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_8D63156,STRID_8D63,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_8FBD157,STRID_8FBD,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_9C81158,STRID_9C81,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_9ED1159,STRID_9ED1,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_65B0160,STRID_65B0,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_82CF161,STRID_82CF,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_85CF162,STRID_85CF,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_95FD163,STRID_95FD,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_664B164,STRID_664B,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_743C165,STRID_743C,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_5180166,STRID_5180,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_5409167,STRID_5409,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_6842168,STRID_6842,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_7518169,STRID_7518,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_7696170,STRID_7696,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_8499171,STRID_8499,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_9102172,STRID_9102,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_9655173,STRID_9655,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(STRID_9752174,STRID_9752,ICONID_NULL,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_ZHCarNo)
SHOW_MAP_BODY(Normal139)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_ZHCarNo)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_ZHCarNo)
STATE_LIST_ITEM(STRID_NULL_143)
STATE_LIST_ITEM(STRID_4E91144)
STATE_LIST_ITEM(STRID_4EAC145)
STATE_LIST_ITEM(STRID_5B81146)
STATE_LIST_ITEM(STRID_5DDD147)
STATE_LIST_ITEM(STRID_6CAA148)
STATE_LIST_ITEM(STRID_6D25149)
STATE_LIST_ITEM(STRID_6D59150)
STATE_LIST_ITEM(STRID_6E1D151)
STATE_LIST_ITEM(STRID_6E58152)
STATE_LIST_ITEM(STRID_7CA4153)
STATE_LIST_ITEM(STRID_8C6B154)
STATE_LIST_ITEM(STRID_8D35155)
STATE_LIST_ITEM(STRID_8D63156)
STATE_LIST_ITEM(STRID_8FBD157)
STATE_LIST_ITEM(STRID_9C81158)
STATE_LIST_ITEM(STRID_9ED1159)
STATE_LIST_ITEM(STRID_65B0160)
STATE_LIST_ITEM(STRID_82CF161)
STATE_LIST_ITEM(STRID_85CF162)
STATE_LIST_ITEM(STRID_95FD163)
STATE_LIST_ITEM(STRID_664B164)
STATE_LIST_ITEM(STRID_743C165)
STATE_LIST_ITEM(STRID_5180166)
STATE_LIST_ITEM(STRID_5409167)
STATE_LIST_ITEM(STRID_6842168)
STATE_LIST_ITEM(STRID_7518169)
STATE_LIST_ITEM(STRID_7696170)
STATE_LIST_ITEM(STRID_8499171)
STATE_LIST_ITEM(STRID_9102172)
STATE_LIST_ITEM(STRID_9655173)
STATE_LIST_ITEM(STRID_9752174)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_ZHCarNo,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_ZHCarNo,0,65,187,85,211)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin176Rect,0,0,319,112,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin176)
SHOW_MAP_BODY(Skin176Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin176,0,0,319,112)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon177, 0, 0, 27,27, ICONID_NULL,83886080,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Normal175)
SHOW_MAP_BODY(Skin176)
SHOW_MAP_BODY(Icon177)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal175,0,90,319,202)

SHOW_MAP_BEGIN(UIFlowWndMovie_Static_Guide)
SHOW_MAP_BODY(Normal175)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Static_Guide)
CREATE_STATIC_DATA(UIFlowWndMovie_Static_Guide,ICON_DAOCHE)
CREATE_STATIC_CTRL(UIFlowWndMovie_Static_Guide,0,0,90,319,202)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin180Rect,0,0,86,20,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin180)
SHOW_MAP_BODY(Skin180Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin180,0,0,86,20)

SHOW_ITEM_TEXT(CMD_Text|CMD_ITEM,Text182,1,2,84,18,STRID_NULL,0,1280,0,0,2,1,1,0,0,16,0,0,0,0)
SHOW_MAP_BEGIN(Normal179)
SHOW_MAP_BODY(Skin180)
SHOW_MAP_BODY(Text182)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal179,12,166,98,186)

SHOW_MAP_BEGIN(UIFlowWndMovie_StaticTXT_Speed)
SHOW_MAP_BODY(Normal179)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_StaticTXT_Speed)
CREATE_STATIC_DATA(UIFlowWndMovie_StaticTXT_Speed,STRID_MODE)
CREATE_STATIC_CTRL(UIFlowWndMovie_StaticTXT_Speed,0,12,166,98,186)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_ITEM_RECT(CMD_Rectangle,Skin185Rect,0,0,58,20,0,0,0,0,0,0,0)
SHOW_MAP_BEGIN(Skin185)
SHOW_MAP_BODY(Skin185Rect)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Skin185,0,0,58,20)

SHOW_ITEM_IMAGE(CMD_Image|CMD_ITEM,Icon186, 0, 0, 58,20, ICONID_NULL,0,0,0,0,0,0,16,0)
SHOW_MAP_BEGIN(Normal184)
SHOW_MAP_BODY(Skin185)
SHOW_MAP_BODY(Icon186)
SHOW_MAP_END

SHOW_ITEM_GROUP(CMD_Group,Normal184,12,215,70,235)

CREATE_STATE_ITEM_DATA(ICONID_NULL187,STRID_NULL,ICONID_NULL,NULL) 
CREATE_STATE_ITEM_DATA(ICON_GEELY188,STRID_NULL,ICON_GEELY,NULL) 
CREATE_STATE_ITEM_DATA(ICON_YOUDAOSHI189,STRID_NULL,ICON_YOUDAOSHI,NULL) 
SHOW_MAP_BEGIN(UIFlowWndMovie_Status_CustomerLogo)
SHOW_MAP_BODY(Normal184)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie_Status_CustomerLogo)
STATE_LIST_BEGIN(UIFlowWndMovie_Status_CustomerLogo)
STATE_LIST_ITEM(ICONID_NULL187)
STATE_LIST_ITEM(ICON_GEELY188)
STATE_LIST_ITEM(ICON_YOUDAOSHI189)
STATE_LIST_END

CREATE_STATE_DATA(UIFlowWndMovie_Status_CustomerLogo,0)
CREATE_STATE_CTRL(UIFlowWndMovie_Status_CustomerLogo,0,12,215,70,235)

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

SHOW_MAP_BEGIN(UIFlowWndMovie)
SHOW_MAP_BODY(Skin1)
SHOW_MAP_END

DECLARE_EVENT(UIFlowWndMovie)
DECLARE_CTRL_LIST(UIFlowWndMovie)
CREATE_CTRL(UIFlowWndMovie,UIFlowWndMovie,CTRL_WND,NULL,0 ,0,0,319,239)
#endif
