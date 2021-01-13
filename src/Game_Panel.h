#ifndef GAME_PANEL_H
#define GAME_PANEL_H

#include <Circuit.h>
#include "wx/file.h"
#include "wx/frame.h"
#include <wx/wx.h>

typedef vector<vector<wxBitmap>> ImageList;

class Game_Panel : public wxPanel
{
	public:
		Game_Panel(wxFrame *parent,  Circuit* stage);


		void OnPaint(wxPaintEvent& event);
		void OnLeftDown(wxMouseEvent& event);
		bool getSinal(int index);

	private:
		Circuit* localCircuit;

		ImageList OperatorImageList;
		ImageList ConnectorImageList;
		int ImageDefaultW[5]={100,100,100,100,100};
		int ImageDefaultH[5]={100,100,50,100,100};

		void CalculateConnector(int index, int opX, int opY, int outX, int outY);
		void SetImageOperator(int index, int& opX,int& opY);
		void SetImageConnector(int index, int sourceSignal, int opX, int opY);
		void SetImageInOutConnector(int index, int sourceSignal, int opY);
};

#endif // GAME_PANEL_H
