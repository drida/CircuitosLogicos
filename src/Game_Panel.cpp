#include "Game_Panel.h"

Game_Panel::Game_Panel(wxFrame *parent, Circuit* stage)
       : wxPanel(parent, wxID_ANY, wxDefaultPosition,
             wxDefaultSize, wxBORDER_NONE)
{
	localCircuit = stage;

	vector<_Operator> Operators = localCircuit->GetOperators();
	OperatorImageList.assign (Operators.size(), {wxNullBitmap});

	vector<_Connector> Connectors = localCircuit->GetConnectors();
	ConnectorImageList.assign (Connectors.size(), {wxNullBitmap});

	int circuitX, circuitY, cX, cY, W, H;
	localCircuit->GetCoordinates(circuitX, circuitY, W, H);
	this->SetMinClientSize(wxSize(W,H));

	CalculateConnector(-1,-1,-1,-1,-1);


	Connect(wxEVT_PAINT, wxPaintEventHandler(Game_Panel::OnPaint));
	Connect(wxEVT_LEFT_DOWN,(wxObjectEventFunction)&Game_Panel::OnLeftDown);
}



void Game_Panel::SetImageOperator(int index, int& x, int& y)
{
	static wxString OperatorImage[5] = {
	    "D:\900-ServidorProducao\DriDaTIC\CircuitosLogicos\assets\and.png",
	    "D:\900-ServidorProducao\DriDaTIC\CircuitosLogicos\assets\or.png",
	    "D:\900-ServidorProducao\DriDaTIC\CircuitosLogicos\assets\not.png",
	    "D:\900-ServidorProducao\DriDaTIC\CircuitosLogicos\assets\nand.png",
	    "D:\900-ServidorProducao\DriDaTIC\CircuitosLogicos\assets\and.png"
    };
    wxImage Image;
	wxBitmap Bmp;
	int opX, opY;
	vector<_Operator> Operators = localCircuit->GetOperators();

	int ot = Operators[index].GetOperatorType();
	Operators[index].GetCoordinates(opX, opY);

	if(opX == -1 && opY == -1)
	{
        wxString SelectedImage = OperatorImage[ot];
        if (access(SelectedImage.c_str(), F_OK ) != -1 )
        {
            Image.LoadFile(SelectedImage, wxBITMAP_TYPE_ANY);
            Bmp = wxBitmap(Image);
            OperatorImageList[index] = {Bmp};
            x =  ((ImageDefaultW[ot]/2)-(Bmp.GetWidth()/2)) + x;
            y =  ((ImageDefaultH[ot]/2)-(Bmp.GetHeight()/2)) + y;
            Operators[index].SetCoordinates(x, y, Bmp.GetWidth(), Bmp.GetHeight());
        }
        else
        {
            x = -1;
            y = -1;

        }
	}
	else
	{
		x = opX;
		y = opY;
	}
}

void Game_Panel::SetImageConnector(int index, int sourceSignal, int x, int y)
{
	static wxString ConnectorImage[3] = {
	    "D:\900-ServidorProducao\DriDaTIC\CircuitosLogicos\assets\input.png",
	    "D:\900-ServidorProducao\DriDaTIC\CircuitosLogicos\assets\input.png",
	    "D:\900-ServidorProducao\DriDaTIC\CircuitosLogicos\assets\input.png"
    };
    wxImage Image;
	wxBitmap Bmp;
	int cX, cY, W, H;
	vector<_Connector> Connectors = localCircuit->GetConnectors();

	int ct = Connectors[index].GetConnectorType();
	Connectors[index].GetCoordinatesConnector(cX, cY);

	if(cX == -1 && cY == -1)
	{
        wxString SelectedImage = ConnectorImage[ct];
        if (access(SelectedImage.c_str(), F_OK ) != -1 )
        {
            Image.LoadFile(SelectedImage, wxBITMAP_TYPE_ANY);
            Bmp = wxBitmap(Image);
            wxBitmap T = Bmp.GetSubBitmap(wxRect(0,0,50,50));
            wxBitmap F = Bmp.GetSubBitmap(wxRect(0,50,50,50));
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
                cY= y+(50*sourceSignal)+29;

            }
            Connectors[index].SetCoordinatesConnector(cX, cY, T.GetWidth(), T.GetHeight());
        }
    }
}

void Game_Panel::SetImageInOutConnector(int index, int opX, int opY)
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
				int opy = opY+50+(H*position);
				int opoutx = opX+W-10;
				int opouty = opY+(H/(out.size()+1));
				CalculateConnector(k, opx, opy, opoutx, opouty);
				position++;
			}
		}
	}
}

void Game_Panel::CalculateConnector(int index, int opX, int opY, int outX, int outY)
{
	int sourceOperator , sourceSignal, targetOperator, targetSignal;
	int  cX, cY, W, H;
	vector<_Connector> Connectors = localCircuit->GetConnectors();

	if(index == -1)
	{
		int position = 0;
		for(unsigned cn = 0; cn < Connectors.size(); ++cn)
		{
			if(Connectors[cn].GetConnectorType() == ctINPUT)
			{
				localCircuit->GetCoordinates(cX,cY,W,H);
				cX += 100;
				cY = (50*position) + cY;
				CalculateConnector(cn, cX, cY, -1, -1);
				position++;
				localCircuit->SetConnectorSignal(cn, false);
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
				SetImageConnector(index, sourceSignal, opX, opY);
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
				SetImageConnector(index, targetSignal, opX, opY);
				Connectors[index].GetCoordinatesConnector(cX, cY);
				Connectors[index].SetCoordinatesSource(outX, outY,  -1, -1);
				Connectors[index].SetCoordinatesTarget(cX+15, cY+25,  -1, -1);
				break;
			}
		}
	}
}

void Game_Panel::OnPaint(wxPaintEvent &event)
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

void Game_Panel::OnLeftDown(wxMouseEvent& event)
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
}
