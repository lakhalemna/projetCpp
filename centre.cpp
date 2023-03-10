#include "centre.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QObject>

centre::centre()
{
idC=0;
nomC="";
adresse="";
etat="";
}

centre::centre(int idC,QString nomC,QString adresse,QString etat)
{
    this->idC=idC;
    this->nomC=nomC;
    this->adresse=adresse;
    this->etat=etat;
}

bool centre::ajouterC()
{

QString id_string= QString::number(idC);
QSqlQuery query;
      query.prepare("INSERT INTO CENTRE (IDC, ADRESSE,ETAT, NOMC) "
                    "VALUES (:IDC, :ADRESSE, :ETAT, :NOMC)");
      query.bindValue(":IDC", id_string);
      query.bindValue(":ADRESSE",adresse);
      query.bindValue(":ETAT", etat);
      query.bindValue(":NOMC", nomC);
      return query.exec();

}


QSqlQueryModel * centre::afficherC()
{
    QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from CENTRE");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDC"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NOMC"));

    return model;


}

bool centre::supprimerC(int id)
{


    QString id_string= QString::number(id);
    QSqlQuery query;
    query.prepare("delete from CENTRE where IDC = :id");
    query.bindValue(":id", id_string);
    return query.exec();
}

bool centre::modifierC(int id)
{
    QString id_string= QString::number(id);
    QSqlQuery query ;
           query.prepare("update  CENTRE set  IDC=:id, ADRESSE=:ADRESSE, ETAT=:ETAT,NOMC=:NOMC where(IDC=:id)");
           query.bindValue(":id", id_string);
           query.bindValue(":ADRESSE",adresse);
           query.bindValue(":ETAT", etat);
           query.bindValue(":NOMC", nomC);
           return query.exec();
}
