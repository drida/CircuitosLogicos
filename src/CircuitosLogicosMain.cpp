/***************************************************************
 * Name:      CircuitosLogicosLinuxMain.cpp
 * Purpose:   Code for Application Frame
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

#include "CircuitosLogicosMain.h"
#include "Circuit.h"
#include "Circuit_Template.h"
#include "Game.h"
#include "Tetris.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
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

BEGIN_EVENT_TABLE(CircuitosLogicosMain, wxFrame)
    EVT_CLOSE(CircuitosLogicosMain::OnClose)
	EVT_MENU(idMenuTemplate, CircuitosLogicosMain::OnTemplate)
	EVT_MENU(idMenuTetris, CircuitosLogicosMain::OnTetris)
	EVT_MENU(idMenuGame, CircuitosLogicosMain::OnGame)
    EVT_MENU(idMenuQuit, CircuitosLogicosMain::OnQuit)
    EVT_MENU(idMenuAbout, CircuitosLogicosMain::OnAbout)
END_EVENT_TABLE()

CircuitosLogicosMain::CircuitosLogicosMain(wxFrame *frame, const wxString& title)
    : wxFrame(frame, -1, title)
{
#if wxUSE_MENUS
    // create a menu bar
    wxMenuBar* mbar = new wxMenuBar();
    wxMenu* fileMenu = new wxMenu(_T(""));
    fileMenu->Append(idMenuTemplate, _("&Template"), _("Modeler application"));
    fileMenu->Append(idMenuTetris, _("Tetris"), _("Mini game"));
    fileMenu->Append(idMenuGame, _("&Game"), _("Full game"));
    fileMenu->Append(idMenuQuit, _("&Quit\tAlt-F4"), _("Quit the application"));
    mbar->Append(fileMenu, _("&File"));

    wxMenu* helpMenu = new wxMenu(_T(""));
    helpMenu->Append(idMenuAbout, _("&About\tF1"), _("Show info about this application"));
    mbar->Append(helpMenu, _("&Help"));

    SetMenuBar(mbar);
#endif // wxUSE_MENUS

#if wxUSE_STATUSBAR
    // create a status bar with some information about the used wxWidgets version
    CreateStatusBar(2);
    SetStatusText(_("Hello Code::Blocks user!"),0);
    SetStatusText(wxbuildinfo(short_f), 1);
#endif // wxUSE_STATUSBAR

}


CircuitosLogicosMain::~CircuitosLogicosMain()
{
}

void CircuitosLogicosMain::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void CircuitosLogicosMain::OnTemplate(wxCommandEvent &event)
{
	Circuit* Fase1 = new Circuit();
	Fase1->SetCoordinates(0, 0, 800, 600);
	Fase1->AddOperator(otOR);
	Fase1->AddOperator(otAND);
	Fase1->AddOperator(otNOT);
	Fase1->AddOperator(otNAND);
	Fase1->AddOperator(otNOT);
	Fase1->AddConnector(ctINPUT,0,0,-1,-1);
	Fase1->AddConnector(ctINPUT,0,1,-1,-1);
	Fase1->AddConnector(ctINPUT,2,0,-1,-1);
	Fase1->AddConnector(ctINPUT,3,0,-1,-1);
	Fase1->AddConnector(ctINPUT,3,1,-1,-1);
	Fase1->AddConnector(ctIN_OUT,1,0,0,0);
	Fase1->AddConnector(ctIN_OUT,1,1,2,0);
	Fase1->AddConnector(ctIN_OUT,4,0,3,0);
	Fase1->AddConnector(ctOUTPUT,-1,-1,1,0);
	Fase1->AddConnector(ctOUTPUT,-1,-1,4,0);

	Circuit_Template* Frame = new Circuit_Template(wxT("FASE 1"), Fase1, wxSize(1000,800));
	//Frame->SetBackground("assets/background.png");
	Frame->SetBackground("../assets/14624.jpg");
	Frame->Centre();
	Frame->Show(true);
}

void CircuitosLogicosMain::OnTetris(wxCommandEvent &event)
{
	Tetris* MiniGame = new Tetris("MINI GAME - TETRIS");
	MiniGame->Show();
}

void CircuitosLogicosMain::OnGame(wxCommandEvent &event)
{
    Circuit* Fase1 = new Circuit();
	Fase1->SetCoordinates(0, 0, 800, 600);
	Fase1->AddOperator(otOR);
	Fase1->AddOperator(otAND);
	Fase1->AddOperator(otNOT);
	Fase1->AddOperator(otNAND);
	Fase1->AddOperator(otNOT);
	Fase1->AddConnector(ctINPUT,0,0,-1,-1);
	Fase1->AddConnector(ctINPUT,0,1,-1,-1);
	Fase1->AddConnector(ctINPUT,2,0,-1,-1);
	Fase1->AddConnector(ctINPUT,3,0,-1,-1);
	Fase1->AddConnector(ctINPUT,3,1,-1,-1);
	Fase1->AddConnector(ctIN_OUT,1,0,0,0);
	Fase1->AddConnector(ctIN_OUT,1,1,2,0);
	Fase1->AddConnector(ctIN_OUT,4,0,3,0);
	Fase1->AddConnector(ctOUTPUT,-1,-1,1,0);
	Fase1->AddConnector(ctOUTPUT,-1,-1,4,0);

	Game* Frame = new Game(wxT("FASE 1"), Fase1);
	Frame->SetBackground("assets/background.png");
	Frame->Centre();
	Frame->Show(true);
}

void CircuitosLogicosMain::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void CircuitosLogicosMain::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Welcome to..."));
}
