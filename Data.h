#ifndef DATA_H
#define DATA_H

#include "sqlite3.h"

class Data
{
	public:
		Data();
		~Data();

private:
	sqlite3* Stages;
};

#endif // DATA_H
