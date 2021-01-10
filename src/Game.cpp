#include "Game.h"
#include "Game_Panel.h"

Game::Game(const wxString& title, Circuit* stage)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(1024, 768))
{
  wxStatusBar *sb = CreateStatusBar();
  sb->SetStatusText(wxT("0"));
  Game_Panel *Game = new Game_Panel(this, stage);
  Game->SetFocus();
  //Game->Start();
}
