#include <stdio.h>
#include "SysCfg.h"
//#include "UIFlow.h"
#include "../../../DRIVER/UIFlow.h"
static TM_MENU* g_pTabMenu;

static void TM_CalcPageCount(TM_MENU* pMenu)
{
    UINT32      i, j;
    TM_PAGE*    pPage;
    TM_ITEM*    pItem;

    for (i = 0; i < pMenu->Count; i++)
    {
        pPage = &pMenu->pPages[i];
        j = 0;
        while (j < 100) // avoid infinite loop
        {
            pItem = &pPage->pItems[j];
            if (pItem->pOptions == NULL)
                break;
            j++;
        }

        pPage->Count = j;
    }
}

void TM_SetMenu(TM_MENU* pMenu)
{
    g_pTabMenu = pMenu;
    TM_CalcPageCount(pMenu);
}

TM_MENU* TM_GetMenu(void)
{
    return g_pTabMenu;
}

void TM_SelectTab(TM_MENU* pMenu, INT32 iNewSel)
{
    // new page
    pMenu->SelPage = iNewSel;

    // page index needs to be within the effective range, otherwise go back to 1st or last page
    if (pMenu->SelPage >= pMenu->Count)
        pMenu->SelPage = 0;
    else if (pMenu->SelPage < 0)
        pMenu->SelPage = pMenu->Count - 1;
}

void TM_ShiftTab(TM_MENU* pMenu, INT32 iOffset)
{
    TM_SelectTab(pMenu, pMenu->SelPage + iOffset);
}
