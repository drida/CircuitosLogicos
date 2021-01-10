#ifndef CIRCUITO_H
#define CIRCUITO_H

#include <iostream>
#include <vector>
#include <time.h>
#include <wx/wx.h>
using namespace std;

typedef vector<vector<bool>> BooleanMatrix;
typedef vector<bool> BooleanList;

enum _OperatorType
{
	otNULL = -1,
	otAND = 0,
	otOR = 1,
	otNOT = 2,
	otNAND = 3,
	otNOR = 4
};

enum _ConnectorType
{
	ctNULL = -1,
	ctINPUT = 0,
	ctIN_OUT = 1,
	ctOUTPUT = 2
};

class _TrueTable
{
	public:
		_TrueTable(_OperatorType operatorType);
		BooleanMatrix GetIn();
		BooleanMatrix GetOut();
		BooleanList GetIn(int index);
		BooleanList GetOut(int index);

	private:
		BooleanMatrix In;
		BooleanMatrix Out;
};

class _Draw
{
	public:
		_Draw();
		void SetDraw(int x, int y, int w, int h);
		void GetDraw(int& x, int& y, int& w, int& h);

	private:
		int X;
		int Y;
		int W;
		int H;
};

class _Operator
{
	public:
		_Operator(_OperatorType operatorType);

		_OperatorType GetOperatorType();
		void SetIn(int index, bool value);
		bool GetIn(int index);
		bool GetOut(int index);
		BooleanList GetIns();
		BooleanList GetOuts();
		void SetCoordinates(int x, int y, int w, int h);
		void GetCoordinates(int& x, int& y, int& w, int& h);
		void GetCoordinates(int& x, int& y);

	protected:
		void CalculateOut();

	private:
		_OperatorType OperatorType;
		_TrueTable* TrueTable;
		_Draw* Coordinates;
		BooleanList In;
		BooleanList Out;
};

class _Connector
{
	public:
		_Connector(_ConnectorType connectorType);

		_ConnectorType GetConnectorType();
		void SetIds(int sourceOperator, int sourceSignal , int linkOperator , int linkSignal);
		void GetIds(int& sourceOperator, int& sourceSignal );
		void GetIds(int& sourceOperator, int& sourceSignal , int& linkOperator , int& linkSignal);
		int GetIdSourceOperator( );
		int GetIdSourceSignal();
		int GetIdLinkOperator();
		int GetIdLinkSignal();
		void SetCoordinatesConnector(int x, int y, int w, int h);
		void GetCoordinatesConnector(int& x, int& y, int& w, int& h);
		void GetCoordinatesConnector(int& x, int& y);
		void SetCoordinatesSource(int x, int y, int w, int h);
		void GetCoordinatesSource(int& x, int& y, int& w, int& h);
		void GetCoordinatesSource(int& x, int& y);
		void SetCoordinatesTarget(int x, int y, int w, int h);
		void GetCoordinatesTarget(int& x, int& y, int& w, int& h);
		void GetCoordinatesTarget(int& x, int& y);

	private:
		_ConnectorType ConnectorType;
		_Draw* CoordinatesConnector;
		_Draw* CoordinatesSource;
		_Draw* CoordinatesTarget;
		int IdSourceOperator = -1;
		int IdSourceSignal = -1;
		int IdLinkOperator = -1;
		int IdLinkSignal = -1;
};

class Circuit
{
	public:
		Circuit();
		virtual ~Circuit();

		void SetCoordinates(int x, int y, int w, int h);
		void GetCoordinates(int& x, int& y, int& w, int& h);

		int AddOperator(_OperatorType tipoOperador);
		vector<_Operator> GetOperators();
		_Operator GetOperator(int index);

		int AddConnector(_ConnectorType tipoConector);
		int AddConnector(_ConnectorType tipoConector, int sourceOperator, int sourceSignal, int targetOperator, int targetSignal);
		void SetConnector(int index, int sourceOperator, int sourceSignal, int targetOperator, int targetSignal);
		void SetConnectorSignal(int index, bool value);
		bool GetConnectorSignal(int index);
		vector<int> GetConnectorLink(int linkOperator, int linkSignal);
		vector<_Connector> GetConnectors();

	private:
		_Draw* Coordinates;
		vector<_Operator> Operators;
		vector<_Connector> Connectors;
};

class _Debug
{
	public:
		_Debug();
		virtual ~_Debug();

		string GetOperator(vector<_Operator> operators);
		string GetOperator(_Operator operators);
		string GetConnectors(vector<_Connector> connectors);
		string GetIn(BooleanList In);
		string GetOut(BooleanList Out);

	protected:

	private:
		string GetNow(string txt);
};

#endif // CIRCUITO_H
