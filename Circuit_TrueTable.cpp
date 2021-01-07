#include "Circuit.h"

_TrueTable::_TrueTable(_OperatorType operatorType)
{
	switch( operatorType )
	{
		case otNULL:
			{
				In.resize(1, BooleanList(1));
				Out.resize(1, BooleanList(1));
				In = {{}};
				Out = {{}};
				break;
			}
		case otAND:
			{
				In.resize(4, BooleanList(2, 0));
				Out.resize(4, BooleanList(1, 0));
				In = {{0,0}, {0,1}, {1,0}, {1,1}};
				Out = {{0},{0},{0},{1}};
				break;
			}
		case otOR:
			{
				In.resize(4, BooleanList(2, 0));
				Out.resize(4, BooleanList(1, 0));
				In = {{0,0}, {0,1}, {1,0}, {1,1}};
				Out = {{0},{1},{1},{1}};
				break;
			}
		case otNOT:
			{
				In.resize(2, BooleanList(1, 0));
				Out.resize(2, BooleanList(1, 0));
				In = {{0}, {1}};
				Out = {{1},{0}};
				break;
			}
		case otNAND:
			{
				In.resize(4, BooleanList(2, 0));
				Out.resize(4, BooleanList(1, 0));
				In = {{0,0}, {0,1}, {1,0}, {1,1}};
				Out = {{1},{1},{1},{0}};
				break;
			}
		case otNOR:
			{
				In.resize(4, BooleanList(2, 0));
				Out.resize(4, BooleanList(1, 0));
				In = {{0,0}, {0,1}, {1,0}, {1,1}};
				Out = {{1},{0},{0},{0}};
				break;
			}
		default:
			throw;
	}
}

BooleanMatrix _TrueTable::GetIn()
{
	return In;
}

BooleanMatrix _TrueTable::GetOut()
{
	return Out;
}

BooleanList _TrueTable::GetIn(int index)
{
	return In[index];
}

BooleanList _TrueTable::GetOut(int index)
{
	return Out[index];
}



