#include "centre.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QObject>
#include <QPrinter>
#include <QPainter>
#include <QPdfWriter>
#include<QDateTime>

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
bool centre::genererPDF()
{
    QPdfWriter pdf("C:/Users/ammou/Desktop/interfacef/centre.pdf");
    QPainter painter(&pdf);
    const QString &date=QDateTime::currentDateTime().toString("dd/MM/yyyy");
    qDebug()<<date;



    int i = 3000;
   // painter.drawImage(500,1000,QImage("C:/Users/ammou/Desktop/interfacef/logo.png"));
    QImage logoImage("C:/Users/ammou/Desktop/interfacef/logo.png");
    painter.drawImage(QRectF(500, 100, 1500, 1500), logoImage);
                            // painter.setPen(Qt::black);
                             painter.setFont(QFont("Arial", 32));


                             QPen pen(Qt::red);
                             painter.setPen(pen);
                             painter.drawText(2700,1000,"Liste des centres");



                             painter.setPen(Qt::black);
                             painter.setFont(QFont("Arial", 15));
                             QBrush brush(Qt::blue);
                             painter.setBrush(brush);
                            //painter.drawRect(1000,100,7700,1600);*/
//painter.drawRect(1000,300,7700,1000);
                             painter.drawRect(1000,2000,7700,500);
                             painter.setFont(QFont("Arial", 10));

                             painter.drawText(1500,2300,"id centre");
                             painter.drawText(3400,2300,"nom centre");
                             painter.drawText(5300,2300,"etat du centre");
                             painter.drawText(7200,2300,"adresse");
                             painter.drawText(7300,1600,date);


                                QSqlQuery query;

                                                         query.prepare("select * from CENTRE");
                                                         query.exec();
                                                         while (query.next())
                                                         {
                                                             painter.drawText(1500,i,query.value(0).toString());
                                                             painter.drawText(3400,i,query.value(1).toString());
                                                             painter.drawText(5300,i,query.value(2).toString());
                                                             painter.drawText(7200,i,query.value(3).toString());




                                                            i = i + 500;
                                                           /* painter.drawRect(1500,2600,7700,i);
                                                            QBrush brush(Qt::white);
                                                            painter.setBrush(brush);*/


                                                         }
 return query.exec();



}
QSqlQueryModel* centre::trierparid()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM CENTRE ORDER BY IDC ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDC"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NOMC"));



    return model;
}
QSqlQueryModel* centre::trierparAdresse()
{
    QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT * FROM CENTRE ORDER BY ADRESSE ASC");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("IDC"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("ADRESSE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("ETAT"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("NOMC"));



    return model;
}
bool centre::rechercheparadresse(QString adresse)
    {
        QSqlQuery query;



        query.prepare("SELECT * FROM ADRESSE WHERE ADRESSE=:adresse");
        query.bindValue(":adresse",adresse);
       return query.exec();
}
QSqlQueryModel* centre::afficherparadresse(QString adresse)
    {
    QSqlQueryModel * model= new QSqlQueryModel();

     //QString ad=  adre;

    QSqlQuery *q = new QSqlQuery;
     q->prepare("SELECT * from ADRESSE where ADRESSE LIKE '%"+adresse+"%'");
      q->addBindValue(adresse);
       q->exec();
         model->setQuery(*q);


        return model;
    }
