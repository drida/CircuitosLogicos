#include "Circuit.h"

_Connector::_Connector(_ConnectorType connectorType)
{
	ConnectorType = connectorType;
	CoordinatesConnector = new _Draw();
	CoordinatesSource = new _Draw();
	CoordinatesTarget = new _Draw();
}

_ConnectorType _Connector::GetConnectorType()
{
	return ConnectorType;
}

void _Connector::SetIds(int sourceOperator, int sourceSignal , int linkOperator , int linkSignal)
{
	IdSourceOperator = sourceOperator;
	IdSourceSignal = sourceSignal;
	IdLinkOperator = linkOperator;
	IdLinkSignal = linkSignal;
}

void _Connector::GetIds(int& sourceOperator, int& sourceSignal)
{
	sourceOperator = IdSourceOperator;
	sourceSignal = IdSourceSignal;
}

void _Connector::GetIds(int& sourceOperator, int& sourceSignal , int& linkOperator , int& linkSignal)
{
	sourceOperator = IdSourceOperator;
	sourceSignal = IdSourceSignal;
	linkOperator = IdLinkOperator;
	linkSignal = IdLinkSignal;
}

int _Connector::GetIdSourceOperator( )
{
	return IdSourceOperator;
}

int _Connector::GetIdSourceSignal()
{
	return IdSourceSignal;
}

int _Connector::GetIdLinkOperator()
{
	return IdLinkOperator;
}

int _Connector::GetIdLinkSignal()
{
	return IdLinkSignal;
}

void _Connector::SetCoordinatesConnector(int x, int y, int w, int h)
{
	CoordinatesConnector->SetDraw(x, y, w, h);
}

void _Connector::GetCoordinatesConnector(int& x, int& y, int& w, int& h)
{
	CoordinatesConnector->GetDraw(x, y, w, h);
}

void _Connector::GetCoordinatesConnector(int& x, int& y)
{
	int w,h;
	CoordinatesConnector->GetDraw(x, y, w, h);
}

void _Connector::SetCoordinatesSource(int x, int y, int w, int h)
{
	CoordinatesSource->SetDraw(x, y, w, h);
}

void _Connector::GetCoordinatesSource(int& x, int& y, int& w, int& h)
{
	CoordinatesSource->GetDraw(x, y, w, h);
}

void _Connector::GetCoordinatesSource(int& x, int& y)
{
	int w,h;
	CoordinatesSource->GetDraw(x, y, w, h);
}

void _Connector::SetCoordinatesTarget(int x, int y, int w, int h)
{
	CoordinatesTarget->SetDraw(x, y, w, h);
}

void _Connector::GetCoordinatesTarget(int& x, int& y, int& w, int& h)
{
	CoordinatesTarget->GetDraw(x, y, w, h);
}

void _Connector::GetCoordinatesTarget(int& x, int& y)
{
	int w,h;
	CoordinatesTarget->GetDraw(x, y, w, h);
}
