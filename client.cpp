#include "client.h"
#include<string>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QtDebug>
#include <QCalendarWidget>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <iostream>
#include <QMessageBox>

CLIENT::CLIENT(){
  ID_CLIENT=0;
  FIRST_NAMEC="";
  LAST_NAMEC="";
  ADDRESSC="";
  EMAILC="";
  PHONE_NUM="";
}
CLIENT::CLIENT(int ID_CLIENT,QString FIRST_NAMEC, QString LAST_NAMEC, QString ADDRESSC, QString EMAILC,QString PHONE_NUM){
    this->ID_CLIENT=ID_CLIENT;
     this->FIRST_NAMEC=FIRST_NAMEC;
     this->LAST_NAMEC=LAST_NAMEC;
     this->ADDRESSC=ADDRESSC;
     this->EMAILC=EMAILC;
     this->PHONE_NUM=PHONE_NUM;
}
int CLIENT::getIDCLIENT(){return ID_CLIENT;}
QString CLIENT::getFIRST_NAME(){return FIRST_NAMEC;}
QString CLIENT::getLAST_NAME(){return LAST_NAMEC;}
QString CLIENT::getADDRESS(){return ADDRESSC;}
QString CLIENT::getEMAIL(){return ADDRESSC;}
QString CLIENT::getPHONE_NUM(){return PHONE_NUM;}

void CLIENT::setIDCLIENT(int ID_CLIENT){
    this->ID_CLIENT=ID_CLIENT;

}
void CLIENT::setFIRST_NAME(QString FIRST_NAMEC){
    this->FIRST_NAMEC=FIRST_NAMEC;

}
void CLIENT::setLAST_NAME(QString LAST_NAMEC){
    this->LAST_NAMEC=LAST_NAMEC;

}
void CLIENT::setADDRESS(QString ADDRESSC){
    this->ADDRESSC=ADDRESSC;
}
void CLIENT::setEMAIL(QString EMAILC){
    this->EMAILC=EMAILC;
}
void CLIENT::setPHONE_NUM(QString PHONE_NUM){
     this->PHONE_NUM=PHONE_NUM;
}
bool CLIENT::addClient()
{
   QString res=QString::number(ID_CLIENT);
    QSqlQuery query;

  query.prepare("insert into CLIENT ( ID_CLIENT,FIRST_NAMEC,LAST_NAMEC,ADDRESSC,EMAILC,PHONE_NUM) "
                "VALUES (:ID_CLIENT,:FIRST_NAMEC,:LAST_NAMEC,:ADDRESSC,:EMAILC,:PHONE_NUM)");
           query.bindValue(0, ID_CLIENT);
           query.bindValue(1, FIRST_NAMEC);
           query.bindValue(2, LAST_NAMEC);
           query.bindValue(3, ADDRESSC);
           query.bindValue(4, EMAILC);
           query.bindValue(5, PHONE_NUM);
          return query.exec();
}
bool CLIENT::deleteClient(int ID_CLIENT)
{
   QSqlQuery query;
   query.prepare("Delete from CLIENT where  ID_CLIENT=:ID_CLIENT");
   query.bindValue(":ID_CLIENT", ID_CLIENT);
    return query.exec();
}

QSqlQueryModel * CLIENT::displayClient()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from CLIENT");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_CLIENT"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("FIRST_NAMEC"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("LAST_NAMEC"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADDRESSC"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("EMAILC"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("PHONE_NUM"));

    return model;
}
bool CLIENT::modifyClient()
{
    QSqlQuery query;
    QString res=QString::number( ID_CLIENT);

  query.prepare("update CLIENT set  ID_CLIENT=:ID_CLIENT ,FIRST_NAMEC=:FIRST_NAMEC ,LAST_NAMEC=:LAST_NAMEC,ADDRESSC=:ADDRESSC,EMAILC=:EMAILC,PHONE_NUM=:PHONE_NUM where  ID_CLIENT=:ID_CLIENT");
  query.bindValue(":ID_CLIENT",res);
  query.bindValue(":FIRST_NAMEC", FIRST_NAMEC);
  query.bindValue(":LAST_NAMEC", LAST_NAMEC);
  query.bindValue(":ADDRESSC", ADDRESSC);
  query.bindValue(":EMAILC", EMAILC);
  query.bindValue(":PHONE_NUM", PHONE_NUM);
  return query.exec();
}

QSqlQueryModel* CLIENT::SortByName()
{
    QSqlQueryModel *model= new QSqlQueryModel();
            model->setQuery("select  ID_CLIENT,FIRST_NAMEC,LAST_NAMEC,ADDRESSC,EMAILC,PHONE_NUM  from CLIENT ORDER BY FIRST_NAMEC asc");

            model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_CLIENT"));
            model->setHeaderData(1,Qt::Horizontal,QObject::tr("FIRST_NAMEC"));
            model->setHeaderData(2,Qt::Horizontal,QObject::tr("LAST_NAMEC"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADDRESSC"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("EMAILC"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("PHONE_NUM"));

            return model;
}

QSqlQueryModel * CLIENT::SearchClient(QString FIRST_NAMEC)
{
    QSqlQueryModel *model= new QSqlQueryModel();
        model->setQuery("SELECT * FROM CLIENT WHERE  FIRST_NAMEC LIKE'%"+ FIRST_NAMEC+"%'");

        model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_CLIENT"));
        model->setHeaderData(1,Qt::Horizontal,QObject::tr("FIRST_NAMEC"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("LAST_NAMEC"));
        model->setHeaderData(3,Qt::Horizontal,QObject::tr("ADDRESSC"));
        model->setHeaderData(4,Qt::Horizontal,QObject::tr("EMAILC"));
        model->setHeaderData(5,Qt::Horizontal,QObject::tr("PHONE_NUM"));
        return model;
}

QStringList CLIENT::list_Sum(QString var)
{
    QSqlQuery query;
    query.prepare("select DISTINCT("+var+") from CLIENT");
    query.exec();
    QStringList list;
    while(query.next())
    {
        list.append(query.value(0).toString());
    }

    return list;
}
int CLIENT::calcul_Sum(QString ADDRESSC,QString val)
{
    QSqlQuery query;
     query.prepare("select  * from CLIENT  WHERE "+val+"=:ADDRESSC");
     query.bindValue(":ADDRESSC", ADDRESSC );
     query.exec();
     int total=0;
     while(query.next())
     {
       total++;
     }
     return total;
}
