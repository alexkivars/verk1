#ifndef Data_H
#define Data_H
#include "Service.h"
#include <iostream>


class Data: public Scientist{
public:
    Data();
    void SaveFile();
    vector<Scientist>getVector();
private:
    vector<Scientist>scientist;
};

#endif // Data_H
