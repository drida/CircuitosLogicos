/***************************************************************
 * Name:      CircuitosLogicosApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Adriano Araujo (drida@drida.com.br)
 * Created:   2020-12-26
 * Copyright: Adriano Araujo (http://drida.com.br)
 * License:
 **************************************************************/

#include "CircuitosLogicosApp.h"

#include <iostream>

//(*AppHeaders
#include "CircuitosLogicosMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(CircuitosLogicosApp);

bool CircuitosLogicosApp::OnInit()
{
	//(*AppInitialize
	bool wxsOK = true;
	wxInitAllImageHandlers();
	if ( wxsOK )
	{
		CircuitosLogicosFrame* Frame = new CircuitosLogicosFrame(0);
		Frame->Show();
		SetTopWindow(Frame);
	}
	//*)

	return wxsOK;

}
