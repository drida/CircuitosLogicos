#include "Game.h"
#include "Data.h"

BEGIN_EVENT_TABLE(Game, wxFrame)
    EVT_ERASE_BACKGROUND(Game::OnEraseBackground)
END_EVENT_TABLE()

Game::Game(const wxString& title, Circuit *circuit, Data *dataStage, const wxSize& size)
       : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, size, wxDEFAULT_DIALOG_STYLE)
{
    wxInitAllImageHandlers();
    AdjustBackground = true;
    Background = wxBitmap("ID_BACKGROUND", wxBITMAP_TYPE_PNG_RESOURCE);

    localCircuit = circuit;
    localDataStage = dataStage;

    vector<_Operator> Operators = localCircuit->GetOperators();
	OperatorImageList.assign (Operators.size(), {wxNullBitmap});

	vector<_Connector> Connectors = localCircuit->GetConnectors();
	ConnectorImageList.assign (Connectors.size(), {wxNullBitmap});

	int circuitX, circuitY, cX, cY, W, H;
	localCircuit->GetCoordinates(circuitX, circuitY, W, H);
	this->SetMinClientSize(wxSize(W,H));

	CalculateConnector(-1,-1,-1,-1,-1);

	Connect(wxEVT_ERASE_BACKGROUND,(wxObjectEventFunction)&Game::OnEraseBackground);
	Connect(wxEVT_PAINT, wxPaintEventHandler(Game::OnPaint));
	Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&Game::OnLeftDown);
	Connect(wxEVT_CLOSE_WINDOW, (wxObjectEventFunction)&Game::OnClose);
}

void Game::SetImageOperator(int index, int& x, int& y)
{
	static wxString OperatorImage[5] = {"ID_AND", "ID_OR","ID_NOT","ID_NAND","ID_NOR"};
	wxBitmap img;
	int opX, opY;
	vector<_Operator> Operators = localCircuit->GetOperators();
	Operators[index].GetCoordinates(opX, opY);
	if(opX == -1 && opY == -1)
	{
		int ot = Operators[index].GetOperatorType();
		img = wxBitmap(OperatorImage[ot], wxBITMAP_TYPE_PNG_RESOURCE);
		OperatorImageList[index] = {img};
		x =  ((ImageDefaultW[ot]/2)-(img.GetWidth()/2)) + x;
		y =  ((ImageDefaultH[ot]/2)-(img.GetHeight()/2)) + y;
		Operators[index].SetCoordinates(x, y, img.GetWidth(), img.GetHeight());
	}
	else
	{
		x = opX;
		y = opY;
	}
}

void Game::SetImageConnector(int index, int sourceSignal, int x, int y, int outY)
{
	static wxString ConnectorImage[3] = {"ID_INPUT", "ID_INPUT", "ID_INPUT"};
	wxBitmap img;
	int cX, cY, W, H;
	vector<_Connector> Connectors = localCircuit->GetConnectors();
	int ct = Connectors[index].GetConnectorType();
	Connectors[index].GetCoordinatesConnector(cX, cY);
	if(cX == -1 && cY == -1)
	{
		img = wxBitmap(ConnectorImage[ct], wxBITMAP_TYPE_PNG_RESOURCE);
		wxBitmap T = img.GetSubBitmap(wxRect(0,0,50,50));
		wxBitmap F = img.GetSubBitmap(wxRect(0,50,50,50));
		ConnectorImageList[index] = {T,F};
		localCircuit->GetCoordinates(cX,cY,W,H);
		if (ct == 0)
		{
			cX += 20;
			cY = y+(50*sourceSignal)+4;
		}
		else
		{
			cX += W - 70;
			cY = outY - 25;
		}
		Connectors[index].SetCoordinatesConnector(cX, cY, T.GetWidth(), T.GetHeight());
	}
}

void Game::SetImageInOutConnector(int index, int opX, int opY)
{
	int x, y, W, H;
	vector<_Connector> Connectors = localCircuit->GetConnectors();
	vector<_Operator> Operators = localCircuit->GetOperators();
	BooleanList out = Operators[index].GetOuts();
	int position = 0;
	for (unsigned j = 0; j < out.size(); ++j)
	{
		for (unsigned k = 0; k < Connectors.size(); ++k)
		{
			if(Connectors[k].GetIdLinkOperator() == index && Connectors[k].GetIdLinkSignal() == j)
			{
				Operators[index].GetCoordinates(x,y,W,H);
				int opx = opX+150;
				int opy = opY+(50*position)+(H/4);
				int opoutx = opX+W-10;
				int opouty = opY+(H/(out.size()+1));
				CalculateConnector(k, opx, opy, opoutx, opouty);
				position++;
			}
		}
	}
}

void Game::CalculateConnector(int index, int opX, int opY, int outX, int outY)
{
	int sourceOperator , sourceSignal, targetOperator, targetSignal;
	int  cX, cY, W, H, YY;
	vector<_Connector> Connectors = localCircuit->GetConnectors();

	if(index == -1)
	{
		int position = 0;
		for(unsigned cn = 0; cn < Connectors.size(); ++cn)
		{
			if(Connectors[cn].GetConnectorType() == ctINPUT)
			{
			    localCircuit->GetCoordinates(cX,cY,W,H);
				cY = (50*position) + cY;
				position++;
			}
		}
		YY = (H/2)-(cY/2)-25;
		position = 0;
		for(unsigned cn = 0; cn < Connectors.size(); ++cn)
		{
			if(Connectors[cn].GetConnectorType() == ctINPUT)
			{
				localCircuit->GetCoordinates(cX,cY,W,H);
				cX += 100;
				cY = (50*position) + cY + YY;
				CalculateConnector(cn, cX, cY, -1, -1);
				position++;
				bool sinal = localCircuit->GetConnectorSignal(cn);
				localCircuit->SetConnectorSignal(cn, sinal);
			}
		}
	}
	else
	{
		Connectors[index].GetIds(sourceOperator, sourceSignal, targetOperator, targetSignal);
		switch (Connectors[index].GetConnectorType())
		{
			case ctNULL :
			{
				break;
			}
			case ctINPUT :
			{
				SetImageOperator(sourceOperator, opX, opY);
				SetImageConnector(index, sourceSignal, opX, opY, outY);
				Connectors[index].GetCoordinatesConnector(cX, cY);
				Connectors[index].SetCoordinatesSource(cX+45, cY+25,  -1, -1);
				Connectors[index].SetCoordinatesTarget(opX+15, cY+25,  -1, -1);
				SetImageInOutConnector(sourceOperator, opX, opY);
				break;
			}
			case ctIN_OUT :
			{
				SetImageOperator(sourceOperator, opX, opY);
				Connectors[index].SetCoordinatesSource(outX, outY,  -1, -1);
				Connectors[index].SetCoordinatesTarget(opX+15, opY+(50*sourceSignal)+29,  -1, -1);
				SetImageInOutConnector(sourceOperator, opX, opY);
				break;
			}
			case ctOUTPUT :
			{
				SetImageOperator(targetOperator, opX, opY);
				SetImageConnector(index, targetSignal, opX, opY, outY);
				Connectors[index].GetCoordinatesConnector(cX, cY);
				Connectors[index].SetCoordinatesSource(outX, outY,  -1, -1);
				Connectors[index].SetCoordinatesTarget(cX+15, cY+25,  -1, -1);
				break;
			}
		}
	}
}

void Game::OnPaint(wxPaintEvent &event)
{
	wxPaintDC dc(this);
	wxColor color[2] = {wxColour(150, 150, 150), wxColour(0, 120, 0)};
	int circuitX, circuitY, opX, opY, cX, cY, csX, csY, ctX, ctY, W, H;
	vector<_Connector> Connectors = localCircuit->GetConnectors();
	vector<_Operator> Operators = localCircuit->GetOperators();

	localCircuit->GetCoordinates(circuitX, circuitY, W, H);

	wxPen pen(color[0], 3, wxSOLID);
	pen.SetCap(wxCAP_PROJECTING);
	dc.SetPen(pen);
	dc.SetBrush(wxBrush(wxColor(0,31,0,50), wxSOLID));
	dc.DrawRectangle(circuitX, circuitY, W, H);

	for(unsigned  cn = 0; cn < Connectors.size(); ++cn)
	{
		Connectors[cn].GetCoordinatesConnector(cX, cY);
		Connectors[cn].GetCoordinatesSource(csX, csY);
		Connectors[cn].GetCoordinatesTarget(ctX, ctY);
		int sinal =  localCircuit->GetConnectorSignal(cn);
		wxPen pen(color[sinal], 3, wxSOLID);
		pen.SetCap(wxCAP_PROJECTING);
		dc.SetPen(pen);
		dc.DrawLine(csX+circuitX, csY+circuitY, ctX+circuitX, ctY+circuitY);
		if(cX != -1 && cY != -1)
		{
			dc.DrawBitmap(ConnectorImageList[cn][sinal], cX+circuitX, cY+circuitY, false);
		}
	}

	for(unsigned  op = 0; op < Operators.size(); ++op)
	{
		Operators[op].GetCoordinates(opX, opY);
		if(opX != -1 && opY != -1)
		{
			dc.DrawBitmap(OperatorImageList[op][0], opX+circuitX, opY+circuitY, false);
		}
	}
}

void Game::OnLeftDown(wxMouseEvent& event)
{
	int mouseCoordX = event.GetPosition().x;
	int mouseCoordY = event.GetPosition().y;
	int circuitX, circuitY, cX, cY, W, H;
	localCircuit->GetCoordinates(circuitX, circuitY, W, H);
	vector<_Connector> Connectors = localCircuit->GetConnectors();
	for (unsigned i = 0; i < Connectors.size(); ++i)
	{
		Connectors[i].GetCoordinatesConnector(cX, cY, W, H);
		if(cX != -1 && cY != -1 && Connectors[i].GetConnectorType() == ctINPUT)
		{
			if(mouseCoordX >= cX+circuitX && mouseCoordX <= cX+W+circuitX && mouseCoordY >= cY+circuitY && mouseCoordY <= cY+H+circuitY)
			{
				bool sinal = localCircuit->GetConnectorSignal(i);
				localCircuit->SetConnectorSignal(i, !sinal);
			}
		}
	}
	Refresh();
	bool outTrue = true;
	for (unsigned i = 0; i < Connectors.size(); ++i)
	{
		if(Connectors[i].GetConnectorType() == ctOUTPUT)
		{
            bool sinal = localCircuit->GetConnectorSignal(i);
            if (!sinal) {
                outTrue = false;
            }
		}
	}
	if (outTrue) {
        wxMessageBox ("Nível " + to_string(localDataStage->GetStage()) + " Completo","Parabéns",wxOK);
        Destroy();
	}
}

void Game::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void Game::OnEraseBackground(wxEraseEvent& event)
{
    if (AdjustBackground) {
        AdjustBackground = false;
        int circuitX, circuitY, cX, cY, W, H;
        localCircuit->GetCoordinates(circuitX, circuitY, W, H);
        wxSize sz = GetClientSize();
        circuitX = (sz.GetWidth()/2) - (W/2);
        circuitY = (sz.GetHeight()/2) - (H/2);
        localCircuit->SetCoordinates(circuitX, circuitY, W, H);

        wxScrolledCanvas m_pview;
        if (Background.Ok()) {
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
