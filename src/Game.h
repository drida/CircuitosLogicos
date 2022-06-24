#ifndef GAME_H
#define GAME_H

#include "Circuit.h"
#include "CircuitosLogicosMain.h"
#include <wx/wx.h>

typedef vector<vector<wxBitmap>> ImageList;

class Game : public wxFrame
{
    public:
        Game(const wxString& title, Circuit* stage, Data* dataStage, const wxSize& size=wxDefaultSize);

    private:
        Circuit* localCircuit;
        Data* localDataStage;

        void OnClose(wxCloseEvent& event);
        void OnEraseBackground(wxEraseEvent& event);
		void OnPaint(wxPaintEvent& event);
		void OnLeftDown(wxMouseEvent& event);

        ImageList OperatorImageList;
		ImageList ConnectorImageList;
		int ImageDefaultW[5]={100,100,100,100,100};
		int ImageDefaultH[5]={100,100,50,100,100};

		void CalculateConnector(int index, int opX, int opY, int outX, int outY);
		void SetImageOperator(int index, int& opX,int& opY);
		void SetImageConnector(int index, int sourceSignal, int x, int y, int outY);
		void SetImageInOutConnector(int index, int sourceSignal, int opY);

		wxBitmap Background;
		bool AdjustBackground;
		void TileBitmap(const wxRect& rect, wxDC& dc, wxBitmap& bitmap);
		void ResizeBitmap(const wxRect& rect, wxDC& dc, wxBitmap& bitmap);

        DECLARE_EVENT_TABLE()
};

#endif // GAME_H
