#ifndef CIRCUIT_TEMPLATE_H
#define CIRCUIT_TEMPLATE_H

#include <Circuit.h>
#include <wx/wx.h>

typedef vector<vector<wxBitmap>> ImageList;

class Circuit_Template : public wxFrame
{
	public:
		Circuit_Template(const wxString& title, Circuit* circuit, const wxSize& size=wxDefaultSize);
		void SetBackground(wxString file = "");
		void OnEraseBackground(wxEraseEvent& event);
		void OnPaint(wxPaintEvent& event);
		void OnLeftDown(wxMouseEvent& event);
		bool getSinal(int index);

	private:
		Circuit* localCircuit;

		ImageList OperatorImageList;
		ImageList ConnectorImageList;

		void CalculateConnector(int index, int opX, int opY, int outX, int outY);
		void SetImageOperator(int index, int& opX,int& opY);
		void SetImageConnector(int index, int sourceSignal, int opX, int opY);
		void SetImageInOutConnector(int index, int sourceSignal, int opY);

		wxBitmap Background;
		bool ImageBackground;
		void TileBitmap(const wxRect& rect, wxDC& dc, wxBitmap& bitmap);
		void ResizeBitmap(const wxRect& rect, wxDC& dc, wxBitmap& bitmap);
};


#endif // CIRCUIT_TEMPLATE_H
