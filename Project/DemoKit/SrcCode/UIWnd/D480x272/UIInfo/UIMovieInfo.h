#ifndef UI_MOVIEINFO_H
#define UI_MOVIEINFO_H

#include "Type.h"
//#include "UIInfo.h"
#include "../../UIWnd/D480x272/UIInfo/UIInfo.h"
#include "PrjCfg.h"

#if 0
typedef enum
{
    MOVIE_COLOR_STANDARD = 0,
    MOVIE_COLOR_VIVID,
    MOVIE_COLOR_SEPIA,
    MOVIE_COLOR_MONO,
    MOVIE_COLOR_SETTING_MAX
}MOVIE_COLOR_SETTING;
#endif

typedef enum
{
    MOVIE_WB_AUTO = 0,
    MOVIE_WB_DAYLIGHT,
    MOVIE_WB_CLOUDY,
    MOVIE_WB_TUNGSTEN,
    MOVIE_WB_FLUORESCENT,
    MOVIE_WB_SETTING_MAX
}MOVIE_WB_SETTING;

typedef enum
{
    MOVIE_EV_P_20 = 0,
    MOVIE_EV_P_17,
    MOVIE_EV_P_13,
    MOVIE_EV_P_10,
    MOVIE_EV_P_7,
    MOVIE_EV_P_3,
    MOVIE_EV_P_0,
    MOVIE_EV_N_3,
    MOVIE_EV_N_7,
    MOVIE_EV_N_10,
    MOVIE_EV_N_13,
    MOVIE_EV_N_17,
    MOVIE_EV_N_20,
    MOVIE_EV_SETTING_MAX
}MOVIE_EV_SETTING;

typedef enum
{
    MOVIE_DZOOM_10X = 0,
    MOVIE_DZOOM_20X,
    MOVIE_DZOOM_30X,
    MOVIE_DZOOM_40X,
    MOVIE_DZOOM_SETTING_MAX
}MOVIE_DZOOM_SETTING;

#if 0
typedef enum
{
    MOVIE_SELFTIMER_OFF = 0x00,
    MOVIE_SELFTIMER_ON_2S,
    MOVIE_SELFTIMER_ON_10S,
    MOVIE_SELFTIMER_ON_10_2S,
    MOVIE_SELFTIMER_SETTING_MAX
}MOVIE_SELFTIMER_SETTIMG;
#endif

typedef enum
{
    MOVIE_AUDIO_VOL_MUTE = 0x0,             ///< Volume mute
    MOVIE_AUDIO_VOL_0,                ///< Volume 0
    MOVIE_AUDIO_VOL_1,                ///< Volume 1
    MOVIE_AUDIO_VOL_2,                ///< Volume 2
    MOVIE_AUDIO_VOL_3,                ///< Volume 3
    MOVIE_AUDIO_VOL_4,                ///< Volume 4
    MOVIE_AUDIO_VOL_5,                ///< Volume 5
    MOVIE_AUDIO_VOL_6,                ///< Volume 6
    MOVIE_AUDIO_VOL_7,                 ///< Volume 7
    MOVIE_AUDIO_VOL_SETTING_MAX
} MOVIE_AUDIO_VOL_SETTING;

typedef enum
{
    MOVIE_DIS_ON = 0x0,
    MOVIE_DIS_OFF,
    MOVIE_DIS_SETTING_MAX
}MOVIE_DIS_SETTING;

typedef enum
{
    MOVIE_MCTF_ON = 0x0,
    MOVIE_MCTF_OFF,
    MOVIE_MCTF_SETTING_MAX
}MOVIE_MCTF_SETTING;

typedef enum
{
    MOVIE_RSC_ON = 0x0,
    MOVIE_RSC_OFF,
    MOVIE_RSC_SETTING_MAX
}MOVIE_RSC_SETTING;

typedef enum
{
    MOVIE_GDC_ON = 0x0,
    MOVIE_GDC_OFF,
    MOVIE_GDC_SETTING_MAX
}MOVIE_GDC_SETTING;

typedef enum
{
    MOVIE_SMEAR_ON = 0x0,
    MOVIE_SMEAR_OFF,
    MOVIE_SMEAR_SETTING_MAX
}MOVIE_SMEAR_SETTING;

#endif //UI_MOVIEINFO_H
