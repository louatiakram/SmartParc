#include "gestion_animaux.h"
#include<QtDebug>
#include<QObject>
#include <numeric>
Animaux::Animaux()
{
id_animal=0; nom=""; race="";age=0;date_entree="";emplacement="";
}
Animaux::Animaux(int id_animal ,QString nom ,QString race,int age,QString date_entree,QString emplacement)
{

    this->id_animal=id_animal;
    this->nom=nom;
    this->race=race;
    this->age=age;
    this->date_entree=date_entree;
    this->emplacement=emplacement;
}
    int Animaux::getid()
    {
        return id_animal;
    }
    QString Animaux::getnom()
    {
        return nom;
    }
    QString Animaux::getrace()
    {
        return race;
    }
    int Animaux::getage()
    {
        return age;
    }
    QString Animaux::getdate()
    {
        return date_entree;
    }
    QString Animaux::getemplacement()
    {
        return emplacement;
    }


    void Animaux::setid(int id_animal)
    {
        this->id_animal=id_animal;

    }
    void Animaux::setnom(QString nom)
    {
        this->nom=nom;

    }
    void Animaux::setrace(QString race)
    {
        this->race=race;

    }
    void Animaux::setage(int age)
    {
        this->age=age;

    }
    void Animaux::setdate(QString date_entree)
    {
        this->date_entree=date_entree;

    }
    void Animaux::setemplacement(QString emplacement)
    {
        this->emplacement=emplacement;
    }
    bool Animaux::ajouter()
    {


        QSqlQuery query;
        QString id_string=QString::number(id_animal);
        QString age_string=QString::number(age);

             query.prepare("INSERT INTO GESTION_ANIMAUX (id_animal,nom,race,age,date_entree,emplacement) VALUES (:id, :nom, :race, :age, :date_entree, :emplacement)");
             query.bindValue(":id", id_animal);
             query.bindValue(":nom", nom);
             query.bindValue(":race", race);
             query.bindValue(":age", age);
             query.bindValue(":date_entree", date_entree);
             query.bindValue(":emplacement", emplacement);



             return query.exec();


    }
   bool Animaux::supprimer(int id)
   {
       QSqlQuery query;

            query.prepare("Delete from GESTION_ANIMAUX where id_animal=:id");
            query.bindValue(0, id);

   return query.exec();
   }

    QSqlQueryModel* Animaux::afficher()
    {
        QSqlQueryModel* model=new QSqlQueryModel();

              model->setQuery("SELECT* FROM GESTION_ANIMAUX");


              return  model;
    }
    bool Animaux::modifier()
    {




        QSqlQuery query;
            query.prepare("UPDATE GESTION_ANIMAUX SET nom=:nom, race=:race, age=:age, date_entree=:date_entree, emplacement=:emplacement WHERE id_animal=:id ");
            query.bindValue(":nom", nom);
            query.bindValue(":race", race);
            query.bindValue(":age", age);
            query.bindValue(":date_entree", date_entree);
            query.bindValue(":emplacement", emplacement);

            query.bindValue(":id", id_animal);






             return query.exec();




    }
   QSqlQueryModel* Animaux ::afficher_id()
   {
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("select id_animal from GESTION_ANIMAUX");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id_animal"));
    return model;

   }

   QSqlQueryModel * Animaux::tri_id()
   {QSqlQueryModel * model= new QSqlQueryModel();

   model->setQuery("select * from GESTION_ANIMAUX order by id_animal");

       return model;
   }
   QSqlQueryModel * Animaux::tri_age()
   {QSqlQueryModel * model= new QSqlQueryModel();

   model->setQuery("select * from GESTION_ANIMAUX order by age");

       return model;
   }
   QSqlQueryModel * Animaux::tri_nom()
   {QSqlQueryModel * model= new QSqlQueryModel();

  model->setQuery("select * from GESTION_ANIMAUX order by nom");

       return model;
   }
   void Animaux::clearTable(QTableView *table)
   {
       QSqlQueryModel *model=new QSqlQueryModel();
       model->clear();
       table->setModel(model);
   }

   void Animaux::rechercher(QTableView *table, int x)
   {
      QSqlQueryModel *model=new QSqlQueryModel();
      QSqlQuery *query =new QSqlQuery;
      query->prepare("select * from GESTION_ANIMAUX where regexp_like(id_animal,:id_animal);");
      query->bindValue(":id_animal",x);

      if(x==0)
      {
          query->prepare("select * from GESTION_ANIMAUX;");
      }
      query->exec();
      model->setQuery(*query);
      table->setModel(model);
      table->show();
   }

