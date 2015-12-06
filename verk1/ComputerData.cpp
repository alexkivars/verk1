#include "ComputerData.h"

ComputerDatabase::ComputerDatabase()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbName = "Computers.sqlite";
    db.setDatabaseName(dbName);
    db.open();


}


bool ComputerDatabase::IsOpen()const
{

    return db.isOpen();

}


void ComputerDatabase::ComputerToVector()
{

    QSqlQuery query(db);

    query.exec("SELECT * FROM Computers");

    while(query.next()){
        string name = query.value("Name").toString().toStdString();
        int BuildYear = query.value("BuildYear").toUInt();
        string Type = query.value("Type").toString().toStdString();
        string made = query.value("Made").toString().toStdString();
        Computers P(name,BuildYear,Type,made);
        computers.push_back(P);
    }
}


bool ComputerDatabase::Addcomputers(Computers add)
{

    bool Added = false;

    QSqlQuery Insert;

    Insert.prepare("INSERT INTO Scientist (id, Name, Build Year, Type, Made) VALUES (:id,:Name, :Build Year,"
                   ":Type,:Made)");


    Insert.bindValue(":Name",add.getName().c_str());
    Insert.bindValue(":Build Year",add.getBuildYear());
    Insert.bindValue(":Type",add.getType().c_str());
    Insert.bindValue(":Made",add.getType().c_str());

    if (Insert.exec())
    {
        Added = true;
    }

    return Added;

}


vector<Computer> ComputerDatabase::getCompVector()
{
    return scientist;
}
