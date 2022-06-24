#include <Data.h>

Data::Data()
{
    NumStage = 0;
}

Data::~Data()
{
}

void Data::SetStage(int numStage)
{
    if (numStage == 0){
        NumStage++;
    } else {
        NumStage = numStage;
    }
}

int Data::GetStage()
{
    return NumStage;
}
