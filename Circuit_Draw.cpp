#include "Circuit.h"

_Draw::_Draw()
{
	X = -1;
	Y = -1;
	W = -1;
	H = -1;
}

void _Draw::SetDraw(int x, int y, int w, int h)
{
	X = x;
	Y = y;
	W = w;
	H = h;
}

void _Draw::GetDraw(int& x, int& y, int& w, int& h)
{
	x = X;
	y = Y;
	w = W;
	h = H;
}

