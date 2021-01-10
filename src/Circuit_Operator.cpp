#include "Circuit.h"

_Operator::_Operator(_OperatorType operatorType)
{
	OperatorType = operatorType;
	TrueTable = new _TrueTable(operatorType);
	Coordinates = new _Draw();

	BooleanList TemplateIn = TrueTable->GetIn(0);
	for (int i = 0; i < int(TemplateIn.size()); i++)
	{
		In.push_back(TemplateIn[i]);
	}

	BooleanList TemplateOut = TrueTable->GetOut(0);
	for (int i = 0; i < int(TemplateOut.size()); i++)
	{
		Out.push_back(TemplateOut[i]);
	}
}

_OperatorType _Operator::GetOperatorType()
{
	return OperatorType;
}

void _Operator::SetIn(int  index, bool value)
{
		In[index] = value;
		CalculateOut();
}

bool _Operator::GetIn(int  index)
{
	return In[index];
}

bool _Operator::GetOut(int  index)
{
	return Out[index];
}

BooleanList _Operator::GetIns()
{
	return In;
}

BooleanList _Operator::GetOuts()
{
	return Out;
}

void _Operator::CalculateOut()
{
	bool found;
	BooleanMatrix TemplateIn = TrueTable->GetIn();
	BooleanMatrix TemplateOut = TrueTable->GetOut();
	for (unsigned i = 0; i < TemplateIn.size(); i++)
	{
		found = true;
		for (unsigned j = 0; j < TemplateIn[i].size(); j++)
		{
			if(In[j] != TemplateIn[i][j])
			{
				found = false;
			}
		}
		if (found)
		{
			for (unsigned j = 0; j < TemplateOut[i].size(); j++)
			{
				Out[j] = TemplateOut[i][j];
			}
			break;
		}
	}
}

void _Operator::SetCoordinates(int x, int y, int w, int h)
{
	Coordinates->SetDraw(x, y, w, h);
}

void _Operator::GetCoordinates(int& x, int& y, int& w, int& h)
{
	Coordinates->GetDraw(x, y, w, h);
}

void _Operator::GetCoordinates(int& x, int& y)
{
	int w,h;
	Coordinates->GetDraw(x, y, w, h);
}
