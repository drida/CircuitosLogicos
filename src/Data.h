#ifndef DATA_H
#define DATA_H

#include "sqlite3.h"

class _Data
{

};

class _DataStage : public _Data
{

};

class _DataUser : public _Data
{

};

class Data
{
	public:
		Data();
		~Data();

	private:
		_DataStage Stage;
		_DataUser User;
};

#endif // DATA_H
