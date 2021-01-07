#include "Circuit.h"

Circuit::Circuit()
{
	Coordinates = new _Draw();
}

Circuit::~Circuit()
{
	//dtor
}

void Circuit::SetCoordinates(int x, int y, int w, int h)
{
	Coordinates->SetDraw(x, y, w, h);
}

void Circuit::GetCoordinates(int& x, int& y, int& w, int& h)
{
	Coordinates->GetDraw(x, y, w, h);
}

int Circuit::AddOperator(_OperatorType tipoOperador)
{
	Operators.push_back(_Operator(tipoOperador));
	return int(Operators.size()-1);
}

int Circuit::AddConnector(_ConnectorType tipoConector)
{
	Connectors.push_back(_Connector(tipoConector));
	return int(Connectors.size()-1);
}

int Circuit::AddConnector(_ConnectorType tipoConector,  int sourceOperator, int sourceSignal, int targetOperator, int targetSignal)
{
	Connectors.push_back(_Connector(tipoConector));
	Connectors[Connectors.size()-1].SetIds(sourceOperator,  sourceSignal, targetOperator, targetSignal);
	return int(Connectors.size()-1);
}

vector<_Operator> Circuit::GetOperators()
{
	return Operators;
}

_Operator Circuit::GetOperator(int index)
{
	_Operator* o = new _Operator(otNULL);
	for (unsigned i = 0; i < Operators.size(); i++)
	{
		if(int(i) != index) continue;
		*o = Operators[i];
		break;
	}
	return *o;
}

vector<int> Circuit::GetConnectorLink(int linkOperator, int linkSignal)
{
	vector<int> ret;
	for (unsigned i = 0; i < Connectors.size(); i++)
	{
		if(Connectors[i].GetIdLinkOperator() == linkOperator &&
			Connectors[i].GetIdLinkSignal() == linkSignal)
			ret.push_back(int(i));
	}
	return ret;
}

void Circuit::SetConnector(int index, int sourceOperator, int sourceSignal, int targetOperator, int targetSignal)
{
	Connectors[index].SetIds(sourceOperator,  sourceSignal, targetOperator, targetSignal);
}

vector<_Connector> Circuit::GetConnectors()
{
	return Connectors;
}

void Circuit::SetConnectorSignal(int index, bool value)
{
	int sourceOperator , sourceSignal, targetOperator, targetSignal;

	switch (Connectors[index].GetConnectorType())
	{
		case ctINPUT :
		case ctIN_OUT :
		{
			Connectors[index].GetIds(sourceOperator, sourceSignal, targetOperator, targetSignal);
			Operators[sourceOperator].SetIn(sourceSignal, value);
			BooleanList out = Operators[sourceOperator].GetOuts();
			for (unsigned j = 0; j < out.size(); j++)
			{
					vector<int> link = GetConnectorLink(sourceOperator, int(j));
					for (unsigned k = 0; k < link.size(); k++)
					{
						SetConnectorSignal(link[k], out[j]);
					}
			}
			break;
		}
	}
}

bool Circuit::GetConnectorSignal(int index)
{
	int sourceOperator , sourceSignal, targetOperator, targetSignal;

	Connectors[index].GetIds(sourceOperator, sourceSignal, targetOperator, targetSignal);
	if(sourceOperator != -1 && sourceSignal != -1)
	{
		return Operators[sourceOperator].GetIn(sourceSignal);
	}
	else
	{
		return Operators[targetOperator].GetOut(targetSignal);
	}
}
