#ifndef GAME_H
#define GAME_H

#include "Circuit.h"
#include <wx/wx.h>

class Game : public wxFrame
{
public:
    Game(const wxString& title, Circuit* stage);

};

#endif // GAME_H
