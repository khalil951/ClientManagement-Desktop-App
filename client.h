#ifndef CLIENT_H
#define CLIENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlError>

class CLIENT
{
private:
    int ID_CLIENT;
    QString FIRST_NAMEC;
    QString LAST_NAMEC;
    QString ADDRESSC;
    QString EMAILC;
    QString PHONE_NUM;

public:
    CLIENT();
    CLIENT(int,QString, QString, QString, QString,QString);
    int getIDCLIENT();
    QString getFIRST_NAME();
    QString getLAST_NAME();
    QString getADDRESS();
    QString getEMAIL();
    QString getPHONE_NUM();

    void setIDCLIENT(int);
    void setFIRST_NAME(QString);
    void setLAST_NAME(QString);
    void setADDRESS(QString);
    void setEMAIL(QString);
    void setPHONE_NUM(QString);

    bool addClient();
    bool deleteClient(int);
    QSqlQueryModel *displayClient();
    bool modifyClient();
    QSqlQueryModel *SortByName();
    QSqlQueryModel *PDF();
    QSqlQueryModel *SearchClient(QString);
    QStringList list_Sum(QString var);
    int calcul_Sum(QString ADDRESSC,QString val);
};
#endif // CLIENT_H
