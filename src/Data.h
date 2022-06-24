#ifndef DATA_H
#define DATA_H

class Data
{
    public:
        Data();
		~Data();
		void SetStage(int numStage);
        int GetStage();

    private:
        int NumStage;
};

#endif // DATA_H
