#include <Data.h>

Data::Data()
{
	sqlite3* DB;
    int exit = 0;
    exit = sqlite3_open("file:data/stages.db", &DB);

    if (exit) {
       //TextCtrl1->AppendText("Error open DB " );
    }
    else
     // TextCtrl1->AppendText("Opened Database Successfully!");

    sqlite3_close(DB);
}

Data::~Data()
{

}


