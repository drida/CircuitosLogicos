/***************************************************************
 * Name:      CircuitosLogicosMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Adriano Araujo (drida@drida.com.br)
 * Created:   2020-12-26
 * Copyright: Adriano Araujo (http://drida.com.br)
 * License:
 **************************************************************/

#include "CircuitosLogicosMain.h"
#include "Circuit.h"
#include "Debug.h"
#include "Tetris.h"
#include "Circuit_Template.h"


//#include "wx/msgdlg.h"

//(*InternalHeaders(CircuitosLogicosFrame)
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat
{
	short_f, long_f
};

wxString wxbuildinfo(wxbuildinfoformat format)
{
	wxString wxbuild(wxVERSION_STRING);

	if (format == long_f )
	{
		#if defined(__WXMSW__)
		wxbuild << _T("-Windows");
		#elif defined(__UNIX__)
		wxbuild << _T("-Linux");
		#endif

		#if wxUSE_UNICODE
		wxbuild << _T("-Unicode build");
		#else
		wxbuild << _T("-ANSI build");
		#endif // wxUSE_UNICODE
	}

	return wxbuild;
}

//(*IdInit(CircuitosLogicosFrame)
const long CircuitosLogicosFrame::idMenuNew = wxNewId();
const long CircuitosLogicosFrame::idMenuQuit = wxNewId();
const long CircuitosLogicosFrame::idMenuTemplate = wxNewId();
const long CircuitosLogicosFrame::ID_MENUITEM1 = wxNewId();
const long CircuitosLogicosFrame::idMenuDebug = wxNewId();
const long CircuitosLogicosFrame::idMenuAbout = wxNewId();
const long CircuitosLogicosFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(CircuitosLogicosFrame,wxFrame)
	//(*EventTable(CircuitosLogicosFrame)
	//*)
END_EVENT_TABLE()

CircuitosLogicosFrame::CircuitosLogicosFrame(wxWindow* parent,wxWindowID id)
{
	//(*Initialize(CircuitosLogicosFrame)
	wxMenu* Menu1;
	wxMenu* Menu2;
	wxMenuBar* MenuBar1;
	wxMenuItem* MenuItem1;
	wxMenuItem* MenuItem2;

	Create(parent, id, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("id"));
	MenuBar1 = new wxMenuBar();
	Menu1 = new wxMenu();
	MenuItem3 = new wxMenuItem(Menu1, idMenuNew, _("New\tCtrl+N"), _("Novo"), wxITEM_NORMAL);
	Menu1->Append(MenuItem3);
	MenuItem1 = new wxMenuItem(Menu1, idMenuQuit, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
	Menu1->Append(MenuItem1);
	MenuBar1->Append(Menu1, _("&File"));
	Menu2 = new wxMenu();
	MenuItem4 = new wxMenuItem(Menu2, idMenuTemplate, _("Template"), _("Exemplo"), wxITEM_NORMAL);
	Menu2->Append(MenuItem4);
	MenuItem5 = new wxMenuItem(Menu2, ID_MENUITEM1, _("Tetris"), wxEmptyString, wxITEM_NORMAL);
	Menu2->Append(MenuItem5);
	Menu3 = new wxMenuItem(Menu2, idMenuDebug, _("Debug"), _("Depurador"), wxITEM_NORMAL);
	Menu2->Append(Menu3);
	MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
	Menu2->Append(MenuItem2);
	MenuBar1->Append(Menu2, _("Help"));
	SetMenuBar(MenuBar1);
	StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
	int __wxStatusBarWidths_1[1] = { -1 };
	int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
	StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
	StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
	SetStatusBar(StatusBar1);

	Connect(idMenuQuit,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CircuitosLogicosFrame::OnQuit);
	Connect(idMenuTemplate,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CircuitosLogicosFrame::OnTemplate);
	Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CircuitosLogicosFrame::OnTetris);
	Connect(idMenuDebug,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CircuitosLogicosFrame::OnDebug);
	Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CircuitosLogicosFrame::OnAbout);
	//*)
}

CircuitosLogicosFrame::~CircuitosLogicosFrame()
{
	//(*Destroy(CircuitosLogicosFrame)
	//*)
}

void CircuitosLogicosFrame::OnQuit(wxCommandEvent& event)
{
	Close();
}

void CircuitosLogicosFrame::OnAbout(wxCommandEvent& event)
{
	wxString msg = wxbuildinfo(long_f);
	wxMessageBox(msg, _("Welcome to..."));
}

void CircuitosLogicosFrame::OnDebug(wxCommandEvent& event)
{
	Debug* Frame = new Debug(0);
	Frame->Show();
}

void CircuitosLogicosFrame::OnTemplate(wxCommandEvent& event)
{
	Circuit* Fase1 = new Circuit();
	Fase1->SetCoordinates(0, 0, 800, 600);
	Fase1->AddOperator(otAND);
	Fase1->AddOperator(otAND);
	Fase1->AddOperator(otOR);
	Fase1->AddOperator(otOR);
	Fase1->AddOperator(otAND);
	Fase1->AddConnector(ctINPUT,0,0,-1,-1);
	Fase1->AddConnector(ctINPUT,0,1,-1,-1);
	Fase1->AddConnector(ctIN_OUT,1,0,0,0);
	Fase1->AddConnector(ctINPUT,1,1,-1,-1);
	Fase1->AddConnector(ctOUTPUT,-1,-1,1,0);
/*
	Fase1->AddConnector(ctINPUT,2,0,-1,-1);
	Fase1->AddConnector(ctINPUT,2,1,-1,-1);
	Fase1->AddConnector(ctINPUT,3,0,-1,-1);
	Fase1->AddConnector(ctINPUT,3,1,-1,-1);
	Fase1->AddConnector(ctIN_OUT,4,0,2,0);
	Fase1->AddConnector(ctIN_OUT,4,1,3,0);
	Fase1->AddConnector(ctOUTPUT,-1,-1,4,0);

	Fase1->AddOperator(otOR);
	Fase1->AddOperator(otOR);
	Fase1->AddOperator(otOR);
	Fase1->AddOperator(otOR);
	Fase1->AddConnector(ctINPUT,5,0,-1,-1);
	Fase1->AddConnector(ctINPUT,5,1,-1,-1);
	Fase1->AddConnector(ctINPUT,6,1,-1,-1);
	Fase1->AddConnector(ctINPUT,7,1,-1,-1);
	Fase1->AddConnector(ctINPUT,8,1,-1,-1);
	Fase1->AddConnector(ctIN_OUT,6,0,5,0);
	Fase1->AddConnector(ctIN_OUT,7,0,6,0);
	Fase1->AddConnector(ctIN_OUT,8,0,7,0);
	Fase1->AddConnector(ctOUTPUT,-1,-1,8,0);
*/
	Circuit_Template* Frame = new Circuit_Template(wxT("FASE 1"), Fase1, wxSize(1000,800));

	//Frame->SetBackground("assets/background.png");
	Frame->SetBackground("assets/14624.jpg");
	Frame->Centre();
	Frame->Show(true);
}

void CircuitosLogicosFrame::OnTetris(wxCommandEvent& event)
{
	srand(time(NULL));
    Tetris *tetris = new Tetris(wxT("Tetris"));
    tetris->Centre();
    tetris->Show(true);
}
