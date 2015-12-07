#ifndef DATABASE_H
#define DATABASE_H
#include <QtSql>
#include <QDebug>
#include "Scientist.h"
#include "computers.h"


class Database
{
public:
    Database();
    bool IsOpen()const;
    void InfoToVector();
    void ComputerToVector();
    void ScientistToVector();
    bool AddScientist(Scientist add);
    bool Addcomputers(Computer add);
    vector<Scientist> getSciVector();
private:
    QSqlDatabase db;
    vector<Scientist>scientist;
    vector<Computer>computers;
};

#endif // DATABASE_H