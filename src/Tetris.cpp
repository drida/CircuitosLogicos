#include "Tetris.h"
#include "Tetris_Board.h"

Tetris::Tetris(const wxString& title)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(360, 720))
{
  wxStatusBar *sb = CreateStatusBar();
  sb->SetStatusText(wxT("0"));
  Board *board = new Board(this);
  board->SetFocus();
  board->Start();
}
