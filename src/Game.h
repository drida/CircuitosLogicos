#ifndef GAME_H
#define GAME_H

#include "Circuit.h"
#include <wx/wx.h>

class Game : public wxFrame
{
    public:
        Game(const wxString& title, Circuit* stage);
        void SetBackground(wxString file = "");
        void OnEraseBackground(wxEraseEvent& event);
    private:
        Circuit* localCircuit;

        wxBitmap Background;
		bool ImageBackground;
		void TileBitmap(const wxRect& rect, wxDC& dc, wxBitmap& bitmap);
		void ResizeBitmap(const wxRect& rect, wxDC& dc, wxBitmap& bitmap);
        DECLARE_EVENT_TABLE()
};

#endif // GAME_H
