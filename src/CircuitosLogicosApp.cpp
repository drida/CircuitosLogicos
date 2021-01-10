/***************************************************************
 * Name:      CircuitosLogicosLinuxApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Adriano Araujo (drida@drida.com.br)
 * Created:   2021-01-10
 * Copyright: Adriano Araujo (http://drida.com.br)
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "CircuitosLogicosApp.h"
#include "CircuitosLogicosMain.h"

IMPLEMENT_APP(CircuitosLogicosApp);

bool CircuitosLogicosApp::OnInit()
{
    CircuitosLogicosMain* frame = new CircuitosLogicosMain(0L, _("wxWidgets Application Template"));

    frame->Show();

    return true;
}
