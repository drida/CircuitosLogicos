#include "Game.h"
#include "Game_Panel.h"

BEGIN_EVENT_TABLE(Game, wxFrame)
    EVT_ERASE_BACKGROUND(Game::OnEraseBackground)
END_EVENT_TABLE()

Game::Game(const wxString& title, Circuit* stage)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(800, 600))
{
    localCircuit = stage;

    //wxStatusBar *sb = CreateStatusBar();
   // sb->SetStatusText(wxT("0"));
   // Game_Panel *Game = new Game_Panel(this, localCircuit);
   // Game->SetFocus();
    //Game->Start();
}

void Game::SetBackground(wxString file)
{
    wxImage BG;
    ImageBackground = false;
    //if (access(file.c_str(), F_OK ) != -1 )
    //{
       // BG.LoadFile(file, wxBITMAP_TYPE_ANY);
       // Background = wxBitmap(wxBITMAP_PNG(BG));
        //Background = wxBITMAP_PNG("ID_BACKGROUND1");
        wxInitAllImageHandlers();
        Background = wxBitmap("ID_BACKGROUND2", wxBITMAP_TYPE_PNG_RESOURCE);
        ImageBackground = true;
    //}
}

void Game::OnEraseBackground(wxEraseEvent& event)
{
	int circuitX, circuitY, cX, cY, W, H;
	localCircuit->GetCoordinates(circuitX, circuitY, W, H);
	wxSize sz = GetClientSize();
	circuitX = (sz.GetWidth()/2) - (W/2);
	circuitY = (sz.GetHeight()/2) - (H/2);
	localCircuit->SetCoordinates(circuitX, circuitY, W, H);

	if (!ImageBackground)
	{
		wxDC* pDC = event.GetDC();
		wxColor color(100, 80, 0);
		wxBrush brush(color, wxSOLID);
		pDC->SetBackground(brush);
		pDC->Clear();
	}
	else
	{
		wxScrolledCanvas m_pview;
		if (Background.Ok() ) {
			wxSize sz = GetClientSize();
			int xOrg, yOrg;
			m_pview.GetViewStart(&xOrg, &yOrg);
			wxInt32 pixelsPerStepX, pixelsPerStepY;
			m_pview.GetScrollPixelsPerUnit(&pixelsPerStepX, &pixelsPerStepY);
			xOrg *= pixelsPerStepX;
			yOrg *= pixelsPerStepY;

			int w = Background.GetWidth();
			int h = Background.GetHeight();
			int xShift = xOrg % w;
			int yShift = yOrg % h;
			wxRect rect(-xShift, -yShift, sz.x+xShift, sz.y+yShift);

			if (event.GetDC() ) {
				TileBitmap(rect, *(event.GetDC()), Background);
                ResizeBitmap(rect, *(event.GetDC()), Background);
			} else {
				wxClientDC dc(this);
				TileBitmap(rect, dc, Background);
				ResizeBitmap(rect, dc, Background);
			}
		}
		else
			event.Skip();
	}
}

void Game::TileBitmap(const wxRect& rect, wxDC& dc, wxBitmap& bitmap)
{
    int w = bitmap.GetWidth();
    int h = bitmap.GetHeight();

    int i, j;
    for (i = rect.x; i < rect.x + rect.width; i += w) {
        for (j = rect.y; j < rect.y + rect.height; j+= h)
            dc.DrawBitmap(bitmap, i, j);
    }
}

void Game::ResizeBitmap(const wxRect& rect, wxDC& dc, wxBitmap& bitmap)
{
	float fWScale = 1.0f;
	float fHScale = 1.0f;
	int iImageH = -1;
	int iImageW = -1;
	int iThisH = -1;
	int iThisW = -1;

	iImageH = bitmap.GetHeight();
	iImageW = bitmap.GetWidth();

	GetSize(&iThisW, &iThisH);
	fHScale = (float) iThisH / (float) iImageH;
	fWScale = (float) iThisW / (float) iImageW;

	dc.SetUserScale(fWScale, fHScale);
	dc.DrawBitmap(bitmap,0,0,true);
}
