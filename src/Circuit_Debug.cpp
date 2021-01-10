#include "Circuit.h"

_Debug::_Debug( )
{
	//ctor
}

_Debug::~_Debug()
{
	//dtor
}

string _Debug::GetOperator(vector<_Operator> operators)
{
	string ret;
	for (int i = 0; i < int(operators.size()); i++)
	{
		ret +=  "|" + std::to_string(i) + ":" +  std::to_string(operators[i].GetOperatorType());
	}
	return GetNow(ret);
}

string _Debug::GetOperator(_Operator operators)
{
	string ret = std::to_string(operators.GetOperatorType());
	return GetNow(ret);
}

string _Debug::GetIn(BooleanList in)
{
	string ret = "Entrada(s): ";
	for (int i = 0; i < int(in.size()); i++)
	{
		string sinal =  (in[i])? "TRUE":"FALSE";
		ret +=  "|" + std::to_string(i) + ":" + sinal;
	}
	return GetNow(ret);
}

string _Debug::GetOut(BooleanList out)
{
	string ret = "Saida(s): ";
	for (int i = 0; i < int(out.size()); i++)
	{
		string sinal =  (out[i])? "TRUE":"FALSE";
		ret +=  "|" + std::to_string(i) + ":" + sinal;
	}
	return GetNow(ret);
}

string _Debug::GetConnectors(vector<_Connector> connectors)
{
	string ret;
	for (int i = 0; i < int(connectors.size()); i++)
	{
		ret +=  "|" + std::to_string(i) + ":" +  std::to_string(connectors[i].GetConnectorType());
		int sOperator, sSignal, dOperator, dSignal;
		connectors[i].GetIds(sOperator, sSignal, dOperator, dSignal);
		ret +=  "|" + std::to_string(sOperator) + ":" + std::to_string(sSignal) + ":" + std::to_string(dOperator) + ":" + std::to_string(dSignal);
	}
	return GetNow(ret);
}

string _Debug::GetNow(string txt)
{
	time_t rawtime;
	struct tm * timeinfo;
	char buffer [80];
	time (&rawtime);
	timeinfo = localtime (&rawtime);
	strftime (buffer,80,"%d/%m/%Y %H:%M:%S",timeinfo);
	puts (buffer);
	std::string date(buffer);
	return "[" +  date  + "]  " + txt + "\n";
}
