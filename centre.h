#ifndef CENTRE_H
#define CENTRE_H

#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class centre
{
public:
    centre();
    centre(int,QString,QString,QString);
    bool ajouterC();
    QSqlQueryModel * afficherC();
    bool modifierC(int id);
    bool supprimerC(int id);
    bool genererPDF();
    QSqlQueryModel* trierparid();
    bool rechercheparadresse(QString adresse);
    QSqlQueryModel* trierparAdresse();
    QSqlQueryModel* afficherparadresse(QString adresse);



    int get_idC(){return  idC;}
    QString get_nomC(){return  nomC;}
    QString get_etat(){return  etat;}
    QString get_adresse(){return adresse;}
    void setidC(int val){idC=val;};
    void setnomC(QString val){nomC=val;};
    void setetat(QString val){etat=val;};
    void setadresse(QString val){adresse=val;};


private:
    int idC;
    QString nomC,adresse,etat;

};

#endif // CENTRE_H
