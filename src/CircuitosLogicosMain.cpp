/***************************************************************
 * Name:      CircuitosLogicosMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Adriano Vilanova Araujo (adriano@vilanovaaraujo.eng.br)
 * Created:   2021-01-10
 * Copyright: Adriano Vilanova Araujo (http://vilanovaaraujo.eng.br)
 * License:   MIT
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#include "CircuitosLogicosMain.h"
#include "Circuit.h"
#include "Data.h"
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
    fileMenu->Append(idMenuGame, _("&Game"), _("Full game"));
    fileMenu->Append(idMenuTetris, _("Tetris"), _("Mini game"));
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

    dataStage = new Data();

}

void CircuitosLogicosMain::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void CircuitosLogicosMain::OnTetris(wxCommandEvent &event)
{
	Tetris* MiniGame = new Tetris("MINI GAME - TETRIS");
	MiniGame->Show();
}

void CircuitosLogicosMain::OnGame(wxCommandEvent &event)
{
    dataStage->SetStage(0);
    Circuit* circuit = new Circuit();
    circuit->SetCoordinates(0, 0, 800, 400);
    MountStage(dataStage->GetStage(), circuit);

    Game* Frame = new Game(wxT("Nivel "+to_string(dataStage->GetStage())), circuit, dataStage, wxSize(1000,600));
    Frame->Centre();
    Frame->Show();
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

Circuit* CircuitosLogicosMain::MountStage(int numStage, Circuit* circuit)
{
    switch(numStage) {
      case 1000:
        circuit->AddOperator(otNAND); // 0
        circuit->AddOperator(otOR); // 1
        circuit->AddOperator(otNAND); // 2
        circuit->AddOperator(otNOT); // 3
        circuit->AddOperator(otNOR); // 4
        circuit->AddOperator(otNOT); // 5
        circuit->AddOperator(otAND); // 6
        circuit->AddOperator(otAND); // 7
        circuit->AddConnector(ctINPUT,0,0,-1,-1);
        circuit->AddConnector(ctINPUT,0,1,-1,-1);
        circuit->AddConnector(ctINPUT,1,0,-1,-1);
        circuit->AddConnector(ctINPUT,1,1,-1,-1);
        circuit->AddConnector(ctINPUT,4,0,-1,-1);
        circuit->AddConnector(ctINPUT,4,1,-1,-1);
        circuit->AddConnector(ctINPUT,5,0,-1,-1);
        circuit->AddConnector(ctIN_OUT,2,0,0,0);
        circuit->AddConnector(ctIN_OUT,2,1,1,0);
        circuit->AddConnector(ctIN_OUT,3,0,2,0);
        circuit->AddConnector(ctIN_OUT,6,0,4,0);
        circuit->AddConnector(ctIN_OUT,6,1,5,0);
        circuit->AddConnector(ctIN_OUT,7,0,3,0);
        circuit->AddConnector(ctIN_OUT,7,1,6,0);
        circuit->AddConnector(ctOUTPUT,-1,-1,7,0);
        circuit->SetConnectorSignal(4, true);
        circuit->SetConnectorSignal(5, true);
        break;
      case 1:
        circuit->AddOperator(otOR); // 0
        circuit->AddConnector(ctINPUT,0,0,-1,-1);
        circuit->AddConnector(ctINPUT,0,1,-1,-1);
        circuit->AddConnector(ctOUTPUT,-1,-1,0,0);
        break;
      case 2:
        circuit->AddOperator(otAND); // 0
        circuit->AddConnector(ctINPUT,0,0,-1,-1);
        circuit->AddConnector(ctINPUT,0,1,-1,-1);
        circuit->AddConnector(ctOUTPUT,-1,-1,0,0);
        break;
      case 3:
        circuit->AddOperator(otNOT); // 0
        circuit->AddConnector(ctINPUT,0,0,-1,-1);
        circuit->AddConnector(ctOUTPUT,-1,-1,0,0);
        circuit->SetConnectorSignal(0, true);
        break;
      case 4:
        circuit->AddOperator(otNAND); // 0
        circuit->AddConnector(ctINPUT,0,0,-1,-1);
        circuit->AddConnector(ctINPUT,0,1,-1,-1);
        circuit->AddConnector(ctOUTPUT,-1,-1,0,0);
        circuit->SetConnectorSignal(0, true);
        circuit->SetConnectorSignal(1, true);
        break;
      case 5:
        circuit->AddOperator(otNOR); // 0
        circuit->AddConnector(ctINPUT,0,0,-1,-1);
        circuit->AddConnector(ctINPUT,0,1,-1,-1);
        circuit->AddConnector(ctOUTPUT,-1,-1,0,0);
        circuit->SetConnectorSignal(0, true);
        circuit->SetConnectorSignal(1, true);
        break;
      case 6:
        circuit->AddOperator(otOR); // 0
        circuit->AddOperator(otOR); // 1
        circuit->AddOperator(otAND); // 2
        circuit->AddConnector(ctINPUT,0,0,-1,-1);
        circuit->AddConnector(ctINPUT,0,1,-1,-1);
        circuit->AddConnector(ctINPUT,1,0,-1,-1);
        circuit->AddConnector(ctINPUT,1,1,-1,-1);
        circuit->AddConnector(ctIN_OUT,2,0,0,0);
        circuit->AddConnector(ctIN_OUT,2,1,1,0);
        circuit->AddConnector(ctOUTPUT,-1,-1,2,0);
        break;
      case 7:
        circuit->AddOperator(otAND); // 0
        circuit->AddOperator(otAND); // 1
        circuit->AddOperator(otOR); // 2
        circuit->AddConnector(ctINPUT,0,0,-1,-1);
        circuit->AddConnector(ctINPUT,0,1,-1,-1);
        circuit->AddConnector(ctINPUT,1,0,-1,-1);
        circuit->AddConnector(ctINPUT,1,1,-1,-1);
        circuit->AddConnector(ctIN_OUT,2,0,0,0);
        circuit->AddConnector(ctIN_OUT,2,1,1,0);
        circuit->AddConnector(ctOUTPUT,-1,-1,2,0);
        break;
      case 8:
        circuit->AddOperator(otAND); // 0
        circuit->AddOperator(otOR); // 1
        circuit->AddOperator(otAND); // 2
        circuit->AddOperator(otNOT); // 3
        circuit->AddConnector(ctINPUT,0,0,-1,-1);
        circuit->AddConnector(ctINPUT,0,1,-1,-1);
        circuit->AddConnector(ctINPUT,1,0,-1,-1);
        circuit->AddConnector(ctINPUT,1,1,-1,-1);
        circuit->AddConnector(ctIN_OUT,2,0,0,0);
        circuit->AddConnector(ctIN_OUT,2,1,1,0);
        circuit->AddConnector(ctIN_OUT,3,0,2,0);
        circuit->AddConnector(ctOUTPUT,-1,-1,3,0);
        circuit->SetConnectorSignal(0, true);
        circuit->SetConnectorSignal(1, true);
        circuit->SetConnectorSignal(2, true);
        circuit->SetConnectorSignal(3, true);
        break;
      case 9:
        circuit->AddOperator(otNAND); // 0
        circuit->AddOperator(otOR); // 1
        circuit->AddOperator(otOR); // 2
        circuit->AddOperator(otNOT); // 3
        circuit->AddConnector(ctINPUT,0,0,-1,-1);
        circuit->AddConnector(ctINPUT,0,1,-1,-1);
        circuit->AddConnector(ctINPUT,1,0,-1,-1);
        circuit->AddConnector(ctINPUT,1,1,-1,-1);
        circuit->AddConnector(ctIN_OUT,2,0,0,0);
        circuit->AddConnector(ctIN_OUT,2,1,1,0);
        circuit->AddConnector(ctIN_OUT,3,0,2,0);
        circuit->AddConnector(ctOUTPUT,-1,-1,3,0);
        circuit->SetConnectorSignal(0, true);
        circuit->SetConnectorSignal(1, true);
        circuit->SetConnectorSignal(2, true);
        circuit->SetConnectorSignal(3, true);
        break;
      case 10:
        circuit->AddOperator(otNAND); // 0
        circuit->AddOperator(otOR); // 1
        circuit->AddOperator(otNAND); // 2
        circuit->AddOperator(otNOT); // 3
        circuit->AddOperator(otNOR); // 4
        circuit->AddConnector(ctINPUT,0,0,-1,-1);
        circuit->AddConnector(ctINPUT,0,1,-1,-1);
        circuit->AddConnector(ctINPUT,1,0,-1,-1);
        circuit->AddConnector(ctINPUT,1,1,-1,-1);
        circuit->AddConnector(ctINPUT,4,0,-1,-1);
        circuit->AddConnector(ctINPUT,4,1,-1,-1);
        circuit->AddConnector(ctIN_OUT,2,0,0,0);
        circuit->AddConnector(ctIN_OUT,2,1,1,0);
        circuit->AddConnector(ctIN_OUT,3,0,2,0);
        circuit->AddConnector(ctOUTPUT,-1,-1,3,0);
        circuit->AddConnector(ctOUTPUT,-1,-1,4,0);
        circuit->SetConnectorSignal(4, true);
        circuit->SetConnectorSignal(5, true);
        break;
      case 11:
        circuit->AddOperator(otNAND); // 0
        circuit->AddOperator(otOR); // 1
        circuit->AddOperator(otNAND); // 2
        circuit->AddOperator(otNOT); // 3
        circuit->AddOperator(otNOR); // 4
        circuit->AddOperator(otNOT); // 5
        circuit->AddOperator(otAND); // 6
        circuit->AddOperator(otAND); // 7
        circuit->AddConnector(ctINPUT,0,0,-1,-1);
        circuit->AddConnector(ctINPUT,0,1,-1,-1);
        circuit->AddConnector(ctINPUT,1,0,-1,-1);
        circuit->AddConnector(ctINPUT,1,1,-1,-1);
        circuit->AddConnector(ctINPUT,4,0,-1,-1);
        circuit->AddConnector(ctINPUT,4,1,-1,-1);
        circuit->AddConnector(ctINPUT,5,0,-1,-1);
        circuit->AddConnector(ctIN_OUT,2,0,0,0);
        circuit->AddConnector(ctIN_OUT,2,1,1,0);
        circuit->AddConnector(ctIN_OUT,3,0,2,0);
        circuit->AddConnector(ctIN_OUT,6,0,4,0);
        circuit->AddConnector(ctIN_OUT,6,1,5,0);
        circuit->AddConnector(ctIN_OUT,7,0,3,0);
        circuit->AddConnector(ctIN_OUT,7,1,6,0);
        circuit->AddConnector(ctOUTPUT,-1,-1,7,0);
        circuit->SetConnectorSignal(4, true);
        circuit->SetConnectorSignal(5, true);
        break;
      default:
        circuit->AddOperator(otOR); // 0
        circuit->AddOperator(otAND); // 1
        circuit->AddOperator(otNOT); // 2
        circuit->AddOperator(otNAND); // 3
        circuit->AddOperator(otNOR); // 4
        circuit->AddConnector(ctINPUT,0,0,-1,-1);
        circuit->AddConnector(ctINPUT,0,1,-1,-1);
        circuit->AddConnector(ctINPUT,2,0,-1,-1);
        circuit->AddConnector(ctINPUT,3,0,-1,-1);
        circuit->AddConnector(ctINPUT,3,1,-1,-1);
        circuit->AddConnector(ctIN_OUT,1,0,0,0);
        circuit->AddConnector(ctIN_OUT,1,1,2,0);
        circuit->AddConnector(ctIN_OUT,4,0,3,0);
        circuit->AddConnector(ctOUTPUT,-1,-1,1,0);
        circuit->AddConnector(ctOUTPUT,-1,-1,4,0);
    }

    return circuit;
}
