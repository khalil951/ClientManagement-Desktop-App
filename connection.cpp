#include "connection.h"
Connection::Connection()
{
}

bool Connection::createconnection()
{
    db = QSqlDatabase::addDatabase("QODBC");
    bool test = false;
    db.setDatabaseName("source_project2A");
    db.setUserName("khalil");
    db.setPassword("esprit2023");

    if (db.open())
        test = true;
    return test;
}
void Connection::closeconnection() { db.close(); }
