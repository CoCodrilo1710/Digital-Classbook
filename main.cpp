
#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <string>
#include <windows.h>

using namespace std;

class grupa;
void first_read();
class materie
{
    int nrabsente;
    int nrnote;
    int *note;
    bool restanta;
    string *absente;
    string *datanota;

public:

    materie()
    {
        nrabsente=0;
        restanta=false;
        nrnote=0;
        note=NULL;
        absente=NULL;
        datanota=NULL;
    }

    materie(int nrnote, int nrabsente)
    {
        this->nrabsente=nrabsente;
        this->nrnote=nrnote;
        note= new int[this->nrnote];
        restanta=false;
        absente= new string[this->nrabsente];
        datanota= new string[this->nrnote];
    }

    int* get_note()
    {
        return note;
    }


    void add_nota(int nota, string data)
    {
        nrnote++;

      int* aux=new int[nrnote];
      for(int i=0;i<nrnote-1;i++)
         aux[i]=note[i];
      aux[nrnote-1]=nota;
      delete[] note;
      note=aux;


      string* aux1=new string[nrnote];
      for(int i=0;i<nrnote-1;i++)
         aux1[i]=datanota[i];

      aux1[nrnote-1]=data;
      delete[] datanota;
      datanota=aux1;




    }

    bool get_restanta()
    {
        return restanta;
    }

    string* get_datanote()
    {
        return datanota;
    }

    string* get_absente()
    {
        return absente;
    }

    int getter_nrnote()
    {
        return this->nrnote;
    }

    int getter_nrabsente()
    {
        return this->nrabsente;
    }




    void setter_restanta(bool ok)
    {
        restanta=ok;
    }

    void setter_note(int* aux)
    {
        note=aux;
    }

    void setter_datanota(string* aux)
    {
        datanota=aux;
    }

    void setter_absente(string* aux)
    {
        absente=aux;
    }

    void setter_nrnote(int nrnotelocal)
    {
        this->nrnote=nrnotelocal;
    }

    void setter_nrabsente(int nrabsentelocal)
    {
        this->nrabsente=nrabsentelocal;
    }




    ~materie() { delete[] note; delete[] absente; delete[] datanota; }

    materie& operator=(const materie &m);

   materie(const materie &m);

  friend ostream& operator<< (ostream& out, materie& ob);
  friend istream& operator>> (istream& in, materie& ob);


};

materie& materie::operator=(const materie& m){
        if(this!=&m){
            this->nrabsente=m.nrabsente;
            this->nrnote=m.nrnote;
            this->restanta=m.restanta;
            note= new int[this->nrnote];
            for(int i=0;i<nrnote;i++)
                note[i]=m.note[i];
            absente= new string[this->nrabsente];
            for(int i=0;i<nrabsente;i++)
                absente[i]=m.absente[i];
            datanota= new string[this->nrnote];
            for(int i=0;i<nrnote;i++)
                datanota[i]=m.datanota[i];

        }
        return *this;
}

materie::materie(const materie &m){

        this->nrabsente=m.nrabsente;
        this->nrnote=m.nrnote;
        this->restanta=m.restanta;
        note= new int[this->nrnote];
        for(int i=0;i<nrnote;i++)
            note[i]=m.note[i];
        absente= new string[this->nrabsente];
        for(int i=0;i<nrabsente;i++)
            absente[i]=m.absente[i];
        datanota= new string[this->nrnote];
        for(int i=0;i<nrnote;i++)
            datanota[i]=m.datanota[i];

}


ostream& operator<< (ostream& out, materie& ob)
{

            out<<"La materia --- POO --- poti avea:"<<endl;
            out<<" - maxim "<<ob.nrabsente<<" absente pentru a intra in examen"<<endl;
            out<<" - minim "<<ob.nrnote<<" note(pe proiecte) pentru a intra in colocviu"<<endl;
            out<<endl;

            if (ob.nrnote!=0)
               {

                out<<"Un exemplu de set de note pentru a putea intra in colocviu este: "<<endl;
                for (int j=0;j<ob.nrnote;j++)
                    out<<ob.note[j]<<"/"<<ob.datanota[j]<<" ";

                out<<endl;
                out<<endl;

               }
            if (ob.nrabsente!=0)
            {
                out<<"Un exemplu de set de absente pentru a putea intra in examen este: "<<endl;
                for (int j=0;j<ob.nrabsente;j++)
                    out<<ob.absente[j]<<" ";
            }
            out<<endl;

    return out;
}


istream& operator>> (istream& in, materie& ob)
{
   cout<<endl;
   cout<<"Introduceti urmatoarele caracteristici despre materia -- POO -- : "<<endl;
   cout<<endl;
   cout<<"Cate absente poti avea maxim pentru a putea intra in examen?"<<endl;
   in>>ob.nrabsente;
   cout<<"Cate note trebuie sa ai (minim) pe proiecte pentru a putea intra in colocviu?"<<endl;
   in>>ob.nrnote;


    ob=materie(ob.nrnote,ob.nrabsente);

   if (ob.nrabsente!=0)
   {

       cout<<"Introduceti un set de absente ca exemplu pentru a putea intra in examen"<<endl;

       in.get();
       for (int k=0;k<ob.nrabsente;k++)
                   {
                        char aux[100];
                        in>>aux;

                        ob.absente[k]=aux;
                    }

    cout<<endl;
    cout<<endl;

   }

    if (ob.nrnote!=0)
    {
       cout<<"Introduceti un set de note ca exemplu pentru a putea intra in colocviu"<<endl;
       cin.get();
       for (int k=0;k<ob.nrnote;k++)
       {

                        int nota;
                        string data;
                        char citit[23]="";

                        in.getline(citit, 3, '/');
                        nota=atoi(citit);

                        ob.note[k]=nota;



                        in.getline(citit, 20, '\n');

                        data=string(citit);

                        ob.datanota[k]=data;

       }
   }

    return in;

}




class Student
{
    string nume;
    string an; /// data nasterii
    int credite;  /// nr credite
    double medie;
    materie materii[7];


public:
    Student()                    /// const de initializare fara param
    {
    nume=" ";
    an=" ";
    credite=0;
    medie=-1;

    for (int i=0;i<7;i++)
        materii[i]=materie(0,0);

    }

    ~Student(){}       /// deconstr

    Student(string nume)                 /// cons de initializare cu param
    {
        this->nume=nume;
        an=" ";
        credite=0;
        medie=0;

        for (int i=0;i<7;i++)
                materii[i]=materie(0,0);
    }

    Student(const Student&);          /// constructor de copiere(antet)
    Student& operator = (Student&);   /// constructor de atribuire --- declarare

    friend ostream& operator<< (ostream& out, Student &s);
    friend istream& operator>> (istream& in, Student &s);


    materie* getter_materii()
    {
        return materii;
    }


    string  getnume()
    {
        return this->nume;
    }

    string getan()
    {
        return this->an;
    }

    int getcredite()
    {
        return this->credite;
    }

    double getmedie()
    {
        return this->medie;
    }


    void set_nume(string nume)
    {
        this->nume=nume;
    }

    void set_an(int an)
    {
        this->an=an;
    }

    void set_credite(int credite)
    {
        this->credite=credite;
    }


    void set_medie(double medie)
    {
        this->medie=medie;
    }



    ///  settere importante



    void set_note(int nota_locala, int materie_locala, int i)
    {
        this->materii[materie_locala].get_note()[i] = nota_locala;
    }

    void set_absenta(string absenta_locala, int materie_locala, int i)
    {
        this->materii[materie_locala].get_absente()[i] = absenta_locala;
    }


    void set_datanota(string data_locala, int materie_locala, int i)
    {
        this->materii[materie_locala].get_datanote()[i] = data_locala;
    }


    void set_materie(int materie_locala, materie aux )
    {
        this->getter_materii()[materie_locala]=aux;
    }

   void adaugare_nota (int materielocala);
   int stergere_nota( int materielocala);
   int stergere_absenta( int materielocala);
   void adaugare_absenta( int materielocala);
   double calcul_medie_student ();
   int nr_restante();
   double getter_medie_per_materie(int materielocala);


 friend  ostream& operator<< (ostream& out, grupa& ob);
 friend istream& operator>> (istream &in, grupa &ob);

};



ostream& operator<< (ostream& out, Student& s)
    {
        out<<endl;
        out<<endl;
        out<<"Studentul "<<s.nume<<" are: ";
        out<<'\n';

        out<<"Media: "<<s.medie;
        if (s.nr_restante()!=0)
            out<<" ,dar studentul are "<<s.nr_restante()<<" restante";

        out<<'\n';
        out<<" anul nasterii: "<<s.an;
        out<<'\n';


        out<<endl;
        out<<endl;
        out<<"Situatia lui este urmatoarea:"<<endl;
        out<<endl;
        out<<endl;
        string nume=s.nume;
        materie *materii;
        materii=s.materii;

            for (int j=0;j<7;j++)
            {
                if (j==0)
                    {
                        if ( materii[0].get_restanta()== 1 )
                        {
                            out<<"La materia -- POO -- studentul @"<<nume<<" este RESTANT!"<<endl;

                        }
                        else
                        {
                        out<<endl;
                        out<<"La materia -- POO -- studentul @"<<nume<<" are numarul de note = "<<materii[0].getter_nrnote()<<" si numarul de absente = "<<materii[0].getter_nrabsente();

                          out<<endl;

                        if ( materii[0].getter_nrnote() !=0 )
                        {
                            out<<"Notele lui sunt urmatoarele: ";

                            for (int k=0;k<materii[0].getter_nrnote();k++)
                            {
                                out<<materii[0].get_note()[k]<<"/"<<materii[0].get_datanote()[k]<<"  ";
                            }
                        }
                        }

                        if ( materii[0].getter_nrabsente() !=0 )
                        {
                            out<<endl;

                            out<<"Absentele lui sunt urmatoarele: ";

                            for (int k=0;k<materii[0].getter_nrabsente();k++)
                            {
                                out<<materii[0].get_absente()[k]<<"  ";
                            }
                        }
                        out<<endl;
                        out<<endl;


                    }
                if (j==1)
                    {
                        if ( materii[1].get_restanta()== 1 )
                        {
                            out<<"La materia -- Structuri de Date -- studentul @"<<nume<<" este RESTANT!"<<endl;

                        }
                        else
                        {
                        out<<"La materia -- Structuri de Date -- studentul @"<<nume<<" are numarul de note = "<<materii[1].getter_nrnote()<<" si numarul de absente = "<<materii[1].getter_nrabsente();

                        out<<endl;
                        if ( materii[1].getter_nrnote() !=0 )
                        {
                            out<<"Notele lui sunt urmatoarele: ";

                            for (int k=0;k<materii[1].getter_nrnote();k++)
                            {
                                out<<materii[1].get_note()[k]<<"/"<<materii[1].get_datanote()[k]<<"  ";
                            }
                        }
                        }

                        if ( materii[1].getter_nrabsente() !=0 )
                        {
                            out<<endl;

                            out<<"Absentele lui sunt urmatoarele: ";

                            for (int k=0;k<materii[1].getter_nrabsente();k++)
                            {
                                out<<materii[1].get_absente()[k]<<"  ";
                            }
                        }
                        out<<endl;
                        out<<endl;

                    }
                if (j==2)
                    {
                        if ( materii[2].get_restanta()== 1 )
                        {
                            out<<"La materia -- Tehnici Web -- studentul @"<<nume<<" este RESTANT!"<<endl;

                        }
                        else
                        {
                        out<<"La materia -- Tehnici Web -- studentul @"<<nume<<" are numarul de note = "<<materii[2].getter_nrnote()<<" si numarul de absente = "<<materii[2].getter_nrabsente();
                        out<<endl;

                        if ( materii[2].getter_nrnote() !=0 )
                        {
                            out<<"Notele lui sunt urmatoarele: ";

                            for (int k=0;k<materii[2].getter_nrnote();k++)
                            {
                                out<<materii[2].get_note()[k]<<"/"<<materii[2].get_datanote()[k]<<"  ";
                            }
                        }

                        }


                        if ( materii[2].getter_nrabsente() !=0 )
                        {
                            out<<endl;

                            out<<"Absentele lui sunt urmatoarele: ";

                            for (int k=0;k<materii[2].getter_nrabsente();k++)
                            {
                                out<<materii[2].get_absente()[k]<<"  ";
                            }
                        }
                        out<<endl;
                        out<<endl;

                    }
                if (j==3)
                    {
                        if ( materii[3].get_restanta()== 1 )
                        {
                            out<<"La materia -- LFA -- studentul @"<<nume<<" este RESTANT!"<<endl;

                        }
                        else
                        {
                        out<<"La materia -- LFA -- studentul @"<<nume<<" are numarul de note = "<<materii[3].getter_nrnote()<<" si numarul de absente = "<<materii[3].getter_nrabsente();

                        out<<endl;
                        if ( materii[3].getter_nrnote() !=0 )
                        {
                            out<<"Notele lui sunt urmatoarele: ";

                            for (int k=0;k<materii[3].getter_nrnote();k++)
                            {
                                out<<materii[3].get_note()[k]<<"/"<<materii[3].get_datanote()[k]<<"  ";
                            }
                        }
                        }

                        if ( materii[3].getter_nrabsente() !=0 )
                        {
                            out<<endl;

                            out<<"Absentele lui sunt urmatoarele: ";

                            for (int k=0;k<materii[3].getter_nrabsente();k++)
                            {
                                out<<materii[3].get_absente()[k]<<"  ";
                            }
                        }
                        out<<endl;
                        out<<endl;
                    }
                if (j==4)
                    {
                        if ( materii[4].get_restanta()== 1 )
                        {
                            out<<"La materia -- Baze de date -- studentul @"<<nume<<" este RESTANT!"<<endl;

                        }
                        else
                        {
                        out<<"La materia -- Baze de date -- studentul @"<<nume<<" are numarul de note = "<<materii[4].getter_nrnote()<<" si numarul de absente = "<<materii[4].getter_nrabsente();
                        out<<endl;

                        if ( materii[4].getter_nrnote() !=0 )
                        {
                            out<<"Notele lui sunt urmatoarele: ";

                            for (int k=0;k<materii[4].getter_nrnote();k++)
                            {
                                out<<materii[4].get_note()[k]<<"/"<<materii[4].get_datanote()[k]<<"  ";
                            }
                        }


                        if ( materii[4].getter_nrabsente() !=0 )
                        {
                            out<<endl;
                            out<<"Absentele lui sunt urmatoarele: ";

                            for (int k=0;k<materii[4].getter_nrabsente();k++)
                            {
                                out<<materii[4].get_absente()[k]<<"  ";
                            }
                        }
                        out<<endl;
                        out<<endl;

                    }
                if (j==5)
                    {
                        if ( materii[5].get_restanta() == 1 )
                        {
                            out<<"La materia -- Limba Engleza -- studentul @"<<nume<<" este RESTANT!"<<endl;

                        }
                        else
                        {
                        out<<"La materia -- Limba Engleza -- studentul @"<<nume<<" are numarul de note = "<<materii[5].getter_nrnote()<<" si numarul de absente = "<<materii[5].getter_nrabsente();
                        out<<endl;


                        if ( materii[5].getter_nrnote() !=0 )
                        {
                            out<<"Notele lui sunt urmatoarele: ";

                            for (int k=0;k<materii[5].getter_nrnote();k++)
                            {
                                out<<materii[5].get_note()[k]<<"/"<<materii[5].get_datanote()[k]<<"  ";
                            }
                        }
                        }

                        if ( materii[5].getter_nrabsente() !=0 )
                        {
                            out<<endl;

                            out<<"Absentele lui sunt urmatoarele: ";

                            for (int k=0;k<materii[5].getter_nrabsente();k++)
                            {
                                out<<materii[5].get_absente()[k]<<"  ";
                            }
                        }
                        out<<endl;
                        out<<endl;

                    }
                if (j==6)
                    {
                        if ( materii[6].get_restanta()== 1 )
                        {
                            out<<"La materia -- Sport -- studentul @"<<nume<<" este RESTANT!"<<endl;

                        }
                        else
                        {
                        out<<"La materia -- Sport -- studentul @"<<nume<<" are numarul de note = "<<materii[6].getter_nrnote()<<" si numarul de absente = "<<materii[6].getter_nrabsente();
                        out<<endl;


                        if ( materii[6].getter_nrnote() !=0 )
                        {
                            out<<"Notele lui sunt urmatoarele: ";

                            for (int k=0;k<materii[6].getter_nrnote();k++)
                            {
                                out<<materii[6].get_note()[k]<<"/"<<materii[6].get_datanote()[k]<<"  ";
                            }
                        }
                        }


                        if ( materii[6].getter_nrabsente() !=0 )
                        {
                            out<<endl;

                            out<<"Absentele lui sunt urmatoarele: ";

                            for (int k=0;k<materii[6].getter_nrabsente();k++)
                            {
                                out<<materii[6].get_absente()[k]<<"  ";
                            }
                        }
                        out<<endl;
                        out<<endl;

                    }

            }


            }
        return out;
    }

istream& operator>> (istream &in, Student &s)
{

    cout<<"Numele este: ";
    in>>s.nume;
    cout<<endl;

    cout<<"Data nasterii este( format:(zi.luna.an) ) : ";
    in>>s.an;
    cout<<endl;
    cout<<endl;

    cout<<endl;
    cout<<endl;

    cout<<"In continuare, introduceti datele despre Notele, respectiv Absentele studentului."<<endl;
    cout<<endl;

    for (int j=0;j<7;j++)
        {
            if (j==0)
            {
                int localnrnote,localnrabsente;
                cout<<"Materia -- POO --"<<endl;

                cout<<"Numar note: ";
                in>>localnrnote;

                s.materii[j].setter_nrnote(localnrnote);

                cout<<"Numar absente: ";
                in>>localnrabsente;
               /// in.ignore();
                s.materii[j].setter_nrabsente(localnrabsente);

                s.materii[j]=materie(localnrnote,localnrabsente);


                 if (localnrnote!=0)
                {
                    /// citire note     --- cu formatul nota/data
                    cout<<endl;
                    cout<<"Studentul are cel putin o absenta in cadrul sesiunii curente?"<<endl;
                    cout<<"Tastati da/nu si apasati ENTER"<<endl;
                    string raspuns;
                    cin>>raspuns;
                    if (raspuns=="da")
                       {
                        s.set_medie(0);
                        cout<<"Nu mai este nevoie sa introduceti celelalte note!"<<endl;
                        s.getter_materii()[j].setter_restanta(1);
                        s.getter_materii()[j].setter_nrnote(0);
                       }
                    else
                    {
                    cout<<endl;
                    cout<<"Introduceti notele studentului in formatul NOTA/DATA( format data: zi.luna) dupa care apasati tasta ENTER!";
                    cout<<endl;

                    cin.get();
                    for (int k=0;k<localnrnote;k++)
                    {

                        int nota;
                        string data;
                        char citit[23]="";

                        in.getline(citit, 3, '/');
                        nota=atoi(citit);


                        s.set_note(nota,j,k);       /// setter de nota

                        ///cin.get();
                        in.getline(citit, 20, '\n');

                        data=string(citit);

                        s.set_datanota(data,j,k);  /// setter de data de nota

                    }
                    }
                }


                 if (localnrabsente!=0)
                {
                    cout<<endl;
                    cout<<"Introduceti absentele studentului in formatul dd.mm (zi.luna) dupa care apasati tasta ENTER!";
                    cout<<endl;

                    for (int k=0;k<localnrabsente;k++)
                   {

                        char aux[100];
                        in>>aux;

                        s.set_absenta(aux,j,k);
                    }



                }
                cout<<endl;
                cout<<endl;

            }

            if (j==1)
            {
                int localnrnote,localnrabsente;
                cout<<"Materia -- Structuri de Date --"<<endl;

                cout<<"Numar note: ";
                in>>localnrnote;
                s.materii[j].setter_nrnote(localnrnote);

                cout<<"Numar absente: ";
                in>>localnrabsente;

                s.materii[j].setter_nrabsente(localnrabsente);

                s.materii[j]=materie(localnrnote,localnrabsente);


                 if (localnrnote!=0)
                {
                    /// citire note     --- cu formatul nota/data
                    cout<<endl;
                    cout<<"Studentul are cel putin o absenta in cadrul sesiunii curente?"<<endl;
                    cout<<"Tastati da/nu si apasati ENTER"<<endl;
                    string raspuns;
                    cin>>raspuns;
                    if (raspuns=="da")
                       {
                        s.set_medie(0);
                        cout<<"Nu mai este nevoie sa introduceti celelalte note!"<<endl;
                        s.getter_materii()[j].setter_restanta(1);
                        s.getter_materii()[j].setter_nrnote(0);
                       }
                    else
                    {
                    cout<<endl;
                    cout<<"Introduceti notele studentului in formatul NOTA/DATA( format data: zi.luna) dupa care apasati tasta ENTER!";
                    cout<<endl;

                    cin.get();
                    for (int k=0;k<localnrnote;k++)
                    {
                        int nota;
                        string data;
                        char citit[23];

                        cin.getline(citit, 3, '/');


                        cout<<citit<<" "<<endl;

                        nota=atoi(citit);

                        s.set_note(nota,j,k);       /// setter de nota


                        cin.getline(citit, 20, '\n');
                        data=string(citit);

                        s.set_datanota(data,j,k);    /// setter de data de nota
                    }
                    }
                }


                 if (localnrabsente!=0)
                {
                    cout<<endl;
                    cout<<"Introduceti absentele studentului in formatul dd.mm (zi.luna) dupa care apasati tasta ENTER!";
                    cout<<endl;

                    for (int k=0;k<localnrabsente;k++)
                   {
                        char aux[200];
                        cin>>aux;
                       /// data=string(aux);
                        s.set_absenta(aux,j,k);
                    }


                }
                cout<<endl;
                cout<<endl;

            }

            if (j==2)
            {
                int localnrnote,localnrabsente;
                cout<<"Materia -- Tehnici Web --"<<endl;

                cout<<"Numar note: ";
                in>>localnrnote;
                s.materii[j].setter_nrnote(localnrnote);

                cout<<"Numar absente: ";
                in>>localnrabsente;

                s.materii[j].setter_nrabsente(localnrabsente);

                s.materii[j]=materie(localnrnote,localnrabsente);


                 if (localnrnote!=0)
                {
                    /// citire note     --- cu formatul nota/data
                    cout<<endl;
                    cout<<"Studentul are cel putin o absenta in cadrul sesiunii curente?"<<endl;
                    cout<<"Tastati da/nu si apasati ENTER"<<endl;
                    string raspuns;
                    cin>>raspuns;
                    if (raspuns=="da")
                       {
                        s.set_medie(0);
                        cout<<"Nu mai este nevoie sa introduceti celelalte note!"<<endl;
                        s.getter_materii()[j].setter_restanta(1);
                        s.getter_materii()[j].setter_nrnote(0);
                       }
                    else
                    {
                    cout<<endl;
                    cout<<"Introduceti notele studentului in formatul NOTA/DATA( format data: zi.luna) dupa care apasati tasta ENTER!";
                    cout<<endl;

                    cin.get();
                    for (int k=0;k<localnrnote;k++)
                    {
                        int nota;
                        string data;
                        char citit[23];

                        cin.getline(citit, 3, '/');
                        nota=atoi(citit);

                        s.set_note(nota,j,k);       /// setter de nota


                        cin.getline(citit, 20, '\n');
                        data=string(citit);

                        s.set_datanota(data,j,k);    /// setter de data de nota
                    }
                    }
                }


                 if (localnrabsente!=0)
                {
                    cout<<endl;
                    cout<<"Introduceti absentele studentului in formatul dd.mm (zi.luna) dupa care apasati tasta ENTER!";
                    cout<<endl;

                    for (int k=0;k<localnrabsente;k++)
                   {

                        char aux[200];
                        cin>>aux;

                        s.set_absenta(aux,j,k);
                    }


                }
                cout<<endl;
                cout<<endl;

            }

            if (j==3)
            {
                int localnrnote,localnrabsente;
                cout<<"Materia -- LFA --"<<endl;

                cout<<"Numar note: ";
                in>>localnrnote;
                s.materii[j].setter_nrnote(localnrnote);

                cout<<"Numar absente: ";
                in>>localnrabsente;

                s.materii[j].setter_nrabsente(localnrabsente);

                s.materii[j]=materie(localnrnote,localnrabsente);


                 if (localnrnote!=0)
                {
                    /// citire note     --- cu formatul nota/data
                    cout<<endl;
                    cout<<"Studentul are cel putin o absenta in cadrul sesiunii curente?"<<endl;
                    cout<<"Tastati da/nu si apasati ENTER"<<endl;
                    string raspuns;
                    cin>>raspuns;
                    if (raspuns=="da")
                       {
                        s.set_medie(0);
                        cout<<"Nu mai este nevoie sa introduceti celelalte note!"<<endl;
                        s.getter_materii()[j].setter_restanta(1);
                        s.getter_materii()[j].setter_nrnote(0);
                       }
                    else
                    {
                     cout<<endl;
                    cout<<"Introduceti notele studentului in formatul NOTA/DATA( format data: zi.luna) dupa care apasati tasta ENTER!";
                    cout<<endl;

                    cin.get();
                    for (int k=0;k<localnrnote;k++)
                    {
                        int nota;
                        string data;
                        char citit[23];

                        cin.getline(citit, 3, '/');
                        nota=atoi(citit);

                        s.set_note(nota,j,k);       /// setter de nota


                        cin.getline(citit, 20, '\n');
                        data=string(citit);

                        s.set_datanota(data,j,k);    /// setter de data de nota
                    }
                    }
                }


                 if (localnrabsente!=0)
                {
                    cout<<endl;
                    cout<<"Introduceti absentele studentului in formatul dd.mm (zi.luna) dupa care apasati tasta ENTER!";
                    cout<<endl;

                    for (int k=0;k<localnrabsente;k++)
                   {
                        char aux[200];
                        cin>>aux;
                       /// data=string(aux);
                        s.set_absenta(aux,j,k);
                    }


                }
                cout<<endl;
                cout<<endl;

            }

            if (j==4)
            {
                int localnrnote,localnrabsente;
                cout<<"Materia -- Baze de Date --"<<endl;

                cout<<"Numar note: ";
                in>>localnrnote;
                s.materii[j].setter_nrnote(localnrnote);

                cout<<"Numar absente: ";
                in>>localnrabsente;

                s.materii[j].setter_nrabsente(localnrabsente);

                s.materii[j]=materie(localnrnote,localnrabsente);


                 if (localnrnote!=0)
                {
                    /// citire note     --- cu formatul nota/data
                    cout<<endl;
                    cout<<"Studentul are cel putin o absenta in cadrul sesiunii curente?"<<endl;
                    cout<<"Tastati da/nu si apasati ENTER"<<endl;
                    string raspuns;
                    cin>>raspuns;
                    if (raspuns=="da")
                       {
                        s.set_medie(0);
                        cout<<"Nu mai este nevoie sa introduceti celelalte note!"<<endl;
                        s.getter_materii()[j].setter_restanta(1);
                        s.getter_materii()[j].setter_nrnote(0);
                       }
                    else
                    {
                    cout<<endl;
                    cout<<"Introduceti notele studentului in formatul NOTA/DATA( format data: zi.luna) dupa care apasati tasta ENTER!";
                    cout<<endl;

                    cin.get();
                    for (int k=0;k<localnrnote;k++)
                    {
                        int nota;
                        string data;
                        char citit[23];

                        cin.getline(citit, 3, '/');
                        nota=atoi(citit);

                        s.set_note(nota,j,k);       /// setter de nota


                        cin.getline(citit, 20, '\n');
                        data=string(citit);

                        s.set_datanota(data,j,k);    /// setter de data de nota
                    }
                    }
                }


                 if (localnrabsente!=0)
                {
                    cout<<endl;
                    cout<<"Introduceti absentele studentului in formatul dd.mm (zi.luna) dupa care apasati tasta ENTER!";
                    cout<<endl;

                    for (int k=0;k<localnrabsente;k++)
                   {

                        char aux[200];
                        cin>>aux;
                       /// data=string(aux);
                        s.set_absenta(aux,j,k);
                    }


                }
                cout<<endl;
                cout<<endl;

            }

            if (j==5)
            {
                int localnrnote,localnrabsente;
                cout<<"Materia -- Limba Engleza --"<<endl;

                cout<<"Numar note: ";
                in>>localnrnote;
                s.materii[j].setter_nrnote(localnrnote);

                cout<<"Numar absente: ";
                in>>localnrabsente;

                s.materii[j].setter_nrabsente(localnrabsente);

                s.materii[j]=materie(localnrnote,localnrabsente);


                 if (localnrnote!=0)
                {
                    /// citire note     --- cu formatul nota/data
                    cout<<endl;
                    cout<<"Studentul are cel putin o absenta in cadrul sesiunii curente?"<<endl;
                    cout<<"Tastati da/nu si apasati ENTER"<<endl;
                    string raspuns;
                    cin>>raspuns;
                    if (raspuns=="da")
                       {
                        s.set_medie(0);
                        cout<<"Nu mai este nevoie sa introduceti celelalte note!"<<endl;
                        s.getter_materii()[j].setter_restanta(1);
                        s.getter_materii()[j].setter_nrnote(0);
                       }
                    else
                    {
                    cout<<endl;
                    cout<<"Introduceti notele studentului in formatul NOTA/DATA( format data: zi.luna) dupa care apasati tasta ENTER!";
                    cout<<endl;

                    cin.get();
                    for (int k=0;k<localnrnote;k++)
                    {
                        int nota;
                        string data;
                        char citit[23];

                        cin.getline(citit, 3, '/');
                        nota=atoi(citit);

                        s.set_note(nota,j,k);       /// setter de nota


                        cin.getline(citit, 20, '\n');
                        data=string(citit);

                        s.set_datanota(data,j,k);    /// setter de data de nota
                    }
                    }
                }


                 if (localnrabsente!=0)
                {
                    cout<<endl;
                    cout<<"Introduceti absentele studentului in formatul dd.mm (zi.luna) dupa care apasati tasta ENTER!";
                    cout<<endl;

                    for (int k=0;k<localnrabsente;k++)
                   {

                        char aux[200];
                        cin>>aux;
                       /// data=string(aux);
                        s.set_absenta(aux,j,k);
                    }


                }
                cout<<endl;
                cout<<endl;

            }

            if (j==6)
            {
                int localnrnote,localnrabsente;
                cout<<"Materia -- Sport --"<<endl;

                cout<<"Numar note: ";
                in>>localnrnote;
                s.materii[j].setter_nrnote(localnrnote);

                cout<<"Numar absente: ";
                in>>localnrabsente;

                s.materii[j].setter_nrabsente(localnrabsente);

                s.materii[j]=materie(localnrnote,localnrabsente);


                 if (localnrnote!=0)
                {
                    /// citire note     --- cu formatul nota/data
                    cout<<endl;
                    cout<<"Studentul are cel putin o absenta in cadrul sesiunii curente?"<<endl;
                    cout<<"Tastati da/nu si apasati ENTER"<<endl;
                    string raspuns;
                    cin>>raspuns;
                    if (raspuns=="da")
                       {
                        s.set_medie(0);
                        cout<<"Nu mai este nevoie sa introduceti celelalte note!"<<endl;
                        s.getter_materii()[j].setter_restanta(1);
                        s.getter_materii()[j].setter_nrnote(0);
                       }
                    else
                    {
                    cout<<endl;
                    cout<<"Introduceti notele studentului in formatul NOTA/DATA( format data: zi.luna) dupa care apasati tasta ENTER!";
                    cout<<endl;

                    cin.get();
                    for (int k=0;k<localnrnote;k++)
                    {
                        int nota;
                        string data;
                        char citit[23];

                        cin.getline(citit, 3, '/');
                        nota=atoi(citit);

                        s.set_note(nota,j,k);       /// setter de nota


                        cin.getline(citit, 20, '\n');
                        data=string(citit);

                        s.set_datanota(data,j,k);    /// setter de data de nota
                    }
                    }
                }


                 if (localnrabsente!=0)
                {

                    cout<<endl;
                    cout<<"Introduceti absentele studentului in formatul dd.mm (zi.luna) dupa care apasati tasta ENTER!";
                    cout<<endl;

                    for (int k=0;k<localnrabsente;k++)
                   {

                        char aux[200];
                        cin>>aux;
                       /// data=string(aux);
                        s.set_absenta(aux,j,k);
                    }


                }
                cout<<endl;
                cout<<endl;

            }


    }



    return in;
}


Student::Student(const Student& ob)   /// constructor de copiere , nu i se copiaza si numele
{
    this->an=ob.an;
    this->credite=ob.credite;
    this->medie=ob.medie;
    this->nume=ob.nume;
    for (int i=0;i<7;i++)
        this->materii[i]=ob.materii[i];

}

Student& Student::operator=(Student& ob){      /// constructor de atribuire

    if (this!= &ob)
    {
        this->an=ob.an;
        this->credite=ob.credite;
        this->medie=ob.medie;
        this->nume=ob.nume;
        for (int i=0;i<7;i++)
            this->materii[i]=ob.materii[i];
    }

    return *this;
}


class grupa
{

    Student *v;
    int nrstudenti;
    int nr_grupa;
    double medie_totala;

public:

    grupa()                    /// const de initializare fara param
    {
    nr_grupa=0;
    v=NULL;
    nrstudenti=0;
    medie_totala=0.0;
    }

    ~grupa(){ delete[] v;}

    grupa(int n,int nrgr)              /// const de initializare cu parametru
    {
        nr_grupa=nrgr;
        this->nrstudenti=n;
        v=new Student[this->nrstudenti];
        medie_totala=0.0;
    }


    int getter_nrstudenti()
    {
        return nrstudenti;
    }

    int getter_medie_totala()
    {
        return medie_totala;
    }

    void setter_medie_totala(double valoare)
    {
        medie_totala=valoare;
    }

    Student* getter_studenti()
    {
        return v;
    }


    grupa& operator=(const grupa &ob);

    grupa(const grupa &ob);

    int cautare_student_verificare ( string);
    Student& cautare_student(string);
    void setare_medie_grupa();
    void setare_mass_medie_studenti();
    int nr_restante_grupa();
    void setare_restanta_mass_studenti();

    friend ostream& operator<< (ostream& out, grupa& ob);
    friend istream& operator>> (istream& in, grupa &ob);

};


grupa& grupa::operator=(const grupa& ob){      /// constructor de atribuire

    if (this!= &ob)
    {

        this->medie_totala=ob.medie_totala;
        this->nrstudenti=ob.nrstudenti;
        this->nr_grupa=ob.nr_grupa;

        v= new Student[this->nrstudenti];

        for(int i=0;i<nrstudenti;i++)
            this->v[i]=ob.v[i];
    }

    return *this;
}


grupa::grupa(const grupa& ob)
{

        this->medie_totala=ob.medie_totala;
        this->nrstudenti=ob.nrstudenti;
        this->nr_grupa=ob.nr_grupa;

        v= new Student[this->nrstudenti];

        for(int i=0;i<nrstudenti;i++)
            v[i]=ob.v[i];

}




ostream& operator<< (ostream& out, grupa& ob)
{
        out<<'\n';
        out<<"Studentii grupei "<<ob.nr_grupa<<" sunt urmatorii, cu urmatoarele medii si note: ";
        out<<'\n';


        out<<"Media generala a grupei este: "<<ob.medie_totala<<endl;

        out<<'\n';
        out<<'\n';
        for (int i=0;i<ob.nrstudenti;i++)
        {

            out<<endl;
            out<<endl;
            out<<endl;

            out<<"Studentul #"<<i+1<<endl;

            out<<endl;
            out<<"Numele studentului este: "<<ob.v[i].nume<<" , iar data de nastere este: "<<ob.v[i].an<<endl;

            out<<"Media lui este: "<<ob.v[i].medie;
            if (ob.v[i].nr_restante()!=0)
                out<<", dar are "<<ob.v[i].nr_restante()<<" restanta/restante";
            out<<endl;

            out<<endl;

            for (int j=0;j<7;j++)
            {
                if (j==0)
                    {
                        out<<endl;
                        if ( ob.v[i].materii[0].get_restanta()== 1 )
                        {
                            out<<"La materia -- POO -- studentul @"<<ob.v[i].nume<<" este RESTANT!"<<endl;

                        }
                        else
                        {


                        out<<"La materia -- POO -- studentul @"<<ob.v[i].nume<<" are numarul de note = "<<ob.v[i].materii[0].getter_nrnote()<<" si numarul de absente = "<<ob.v[i].materii[0].getter_nrabsente();

                          out<<endl;

                        if ( ob.v[i].materii[0].getter_nrnote() !=0 )
                        {
                            out<<"Notele lui sunt urmatoarele: ";

                            for (int k=0;k<ob.v[i].materii[0].getter_nrnote();k++)
                            {
                                out<<ob.v[i].materii[0].get_note()[k]<<"/"<<ob.v[i].materii[0].get_datanote()[k]<<"  ";
                            }
                        }

                        }


                        if ( ob.v[i].materii[0].getter_nrabsente() !=0 )
                        {
                            out<<endl;

                            out<<"Absentele lui sunt urmatoarele: ";

                            for (int k=0;k<ob.v[i].materii[0].getter_nrabsente();k++)
                            {
                                out<<ob.v[i].materii[0].get_absente()[k]<<"  ";
                            }
                        }
                        out<<endl;
                        out<<endl;


                    }
                if (j==1)
                    {
                        if ( ob.v[i].materii[1].get_restanta()== 1 )
                        {
                            out<<"La materia -- Structuri de Date -- studentul @"<<ob.v[i].nume<<" este RESTANT!"<<endl;

                        }
                        else
                        {
                        out<<"La materia -- Structuri de Date -- studentul @"<<ob.v[i].nume<<" are numarul de note = "<<ob.v[i].materii[1].getter_nrnote()<<" si numarul de absente = "<<ob.v[i].materii[1].getter_nrabsente();

                        out<<endl;
                        if ( ob.v[i].materii[1].getter_nrnote() !=0 )
                        {
                            out<<"Notele lui sunt urmatoarele: ";

                            for (int k=0;k<ob.v[i].materii[1].getter_nrnote();k++)
                            {
                                out<<ob.v[i].materii[1].get_note()[k]<<"/"<<ob.v[i].materii[1].get_datanote()[k]<<"  ";
                            }
                        }

                        }
                        if ( ob.v[i].materii[1].getter_nrabsente() !=0 )
                        {
                            out<<endl;

                            out<<"Absentele lui sunt urmatoarele: ";

                            for (int k=0;k<ob.v[i].materii[1].getter_nrabsente();k++)
                            {
                                out<<ob.v[i].materii[1].get_absente()[k]<<"  ";
                            }
                        }
                        out<<endl;
                        out<<endl;

                    }
                if (j==2)
                    {
                        if ( ob.v[i].materii[2].get_restanta()== 1 )
                        {
                            out<<"La materia -- Tehnici Web -- studentul @"<<ob.v[i].nume<<" este RESTANT!"<<endl;

                        }
                        else
                        {
                        out<<"La materia -- Tehnici Web -- studentul @"<<ob.v[i].nume<<" are numarul de note = "<<ob.v[i].materii[2].getter_nrnote()<<" si numarul de absente = "<<ob.v[i].materii[2].getter_nrabsente();
                        out<<endl;

                        if ( ob.v[i].materii[2].getter_nrnote() !=0 )
                        {
                            out<<"Notele lui sunt urmatoarele: ";

                            for (int k=0;k<ob.v[i].materii[2].getter_nrnote();k++)
                            {
                                out<<ob.v[i].materii[2].get_note()[k]<<"/"<<ob.v[i].materii[2].get_datanote()[k]<<"  ";
                            }
                        }
                        }

                        if ( ob.v[i].materii[2].getter_nrabsente() !=0 )
                        {
                            out<<endl;

                            out<<"Absentele lui sunt urmatoarele: ";

                            for (int k=0;k<ob.v[i].materii[2].getter_nrabsente();k++)
                            {
                                out<<ob.v[i].materii[2].get_absente()[k]<<"  ";
                            }
                        }
                        out<<endl;
                        out<<endl;

                    }
                if (j==3)
                    {
                        if ( ob.v[i].materii[3].get_restanta()== 1 )
                        {
                            out<<"La materia -- LFA -- studentul @"<<ob.v[i].nume<<" este RESTANT!"<<endl;

                        }
                        else
                        {
                        out<<"La materia -- LFA -- studentul @"<<ob.v[i].nume<<" are numarul de note = "<<ob.v[i].materii[3].getter_nrnote()<<" si numarul de absente = "<<ob.v[i].materii[3].getter_nrabsente();

                        out<<endl;
                        if ( ob.v[i].materii[3].getter_nrnote() !=0 )
                        {
                            out<<"Notele lui sunt urmatoarele: ";

                            for (int k=0;k<ob.v[i].materii[3].getter_nrnote();k++)
                            {
                                out<<ob.v[i].materii[3].get_note()[k]<<"/"<<ob.v[i].materii[3].get_datanote()[k]<<"  ";
                            }
                        }
                        }

                        if ( ob.v[i].materii[3].getter_nrabsente() !=0 )
                        {
                            out<<endl;

                            out<<"Absentele lui sunt urmatoarele: ";

                            for (int k=0;k<ob.v[i].materii[3].getter_nrabsente();k++)
                            {
                                out<<ob.v[i].materii[3].get_absente()[k]<<"  ";
                            }
                        }
                        out<<endl;
                        out<<endl;
                    }
                if (j==4)
                    {
                        if ( ob.v[i].materii[4].get_restanta()== 1 )
                        {
                            out<<"La materia -- Baze de date -- studentul @"<<ob.v[i].nume<<" este RESTANT!"<<endl;

                        }
                        else
                        {
                        out<<"La materia -- Baze de date -- studentul @"<<ob.v[i].nume<<" are numarul de note = "<<ob.v[i].materii[4].getter_nrnote()<<" si numarul de absente = "<<ob.v[i].materii[4].getter_nrabsente();
                        out<<endl;

                        if ( ob.v[i].materii[4].getter_nrnote() !=0 )
                        {
                            out<<"Notele lui sunt urmatoarele: ";

                            for (int k=0;k<ob.v[i].materii[4].getter_nrnote();k++)
                            {
                                out<<ob.v[i].materii[4].get_note()[k]<<"/"<<ob.v[i].materii[4].get_datanote()[k]<<"  ";
                            }
                        }

                        }
                        if ( ob.v[i].materii[4].getter_nrabsente() !=0 )
                        {
                            out<<endl;
                            out<<"Absentele lui sunt urmatoarele: ";

                            for (int k=0;k<ob.v[i].materii[4].getter_nrabsente();k++)
                            {
                                out<<ob.v[i].materii[4].get_absente()[k]<<"  ";
                            }
                        }
                        out<<endl;
                        out<<endl;

                    }
                if (j==5)
                    {
                        if ( ob.v[i].materii[5].get_restanta()== 1 )
                        {
                            out<<"La materia -- Limba Engleza -- studentul @"<<ob.v[i].nume<<" este RESTANT!"<<endl;

                        }
                        else
                        {
                        out<<"La materia -- Limba Engleza -- studentul @"<<ob.v[i].nume<<" are numarul de note = "<<ob.v[i].materii[5].getter_nrnote()<<" si numarul de absente = "<<ob.v[i].materii[5].getter_nrabsente();
                        out<<endl;


                        if ( ob.v[i].materii[5].getter_nrnote() !=0 )
                        {
                            out<<"Notele lui sunt urmatoarele: ";

                            for (int k=0;k<ob.v[i].materii[5].getter_nrnote();k++)
                            {
                                out<<ob.v[i].materii[5].get_note()[k]<<"/"<<ob.v[i].materii[5].get_datanote()[k]<<"  ";
                            }
                        }
                        }

                        if ( ob.v[i].materii[5].getter_nrabsente() !=0 )
                        {
                            out<<endl;

                            out<<"Absentele lui sunt urmatoarele: ";

                            for (int k=0;k<ob.v[i].materii[5].getter_nrabsente();k++)
                            {
                                out<<ob.v[i].materii[5].get_absente()[k]<<"  ";
                            }
                        }
                        out<<endl;
                        out<<endl;

                    }
                if (j==6)
                    {
                        if ( ob.v[i].materii[6].get_restanta()== 1 )
                        {
                            out<<"La materia -- Sport -- studentul @"<<ob.v[i].nume<<" este RESTANT!"<<endl;

                        }
                        else
                        {
                        out<<"La materia -- Sport -- studentul @"<<ob.v[i].nume<<" are numarul de note = "<<ob.v[i].materii[6].getter_nrnote()<<" si numarul de absente = "<<ob.v[i].materii[6].getter_nrabsente();
                        out<<endl;


                        if ( ob.v[i].materii[6].getter_nrnote() !=0 )
                        {
                            out<<"Notele lui sunt urmatoarele: ";

                            for (int k=0;k<ob.v[i].materii[6].getter_nrnote();k++)
                            {
                                out<<ob.v[i].materii[6].get_note()[k]<<"/"<<ob.v[i].materii[6].get_datanote()[k]<<"  ";
                            }
                        }
                        }

                        if ( ob.v[i].materii[6].getter_nrabsente() !=0 )
                        {
                            out<<endl;

                            out<<"Absentele lui sunt urmatoarele: ";

                            for (int k=0;k<ob.v[i].materii[6].getter_nrabsente();k++)
                            {
                                out<<ob.v[i].materii[6].get_absente()[k]<<"  ";
                            }
                        }
                        out<<endl;
                        out<<endl;

                    }

            }



        }


        return out;
}



istream& operator>> (istream &in, grupa &ob)

{
    cout<<"Introduceti urmatoarele date despre studenti:"<<endl;
    cout<<endl;

    cin.get();
    for (int i=0;i<ob.nrstudenti;i++)
    {

    cout<<"Numele este: ";
    char aux[200];
    cin.getline(aux, 200, '\n');
    ob.v[i].nume=aux;

    cout<<endl;

    cout<<"Data nasterii este ( format:(zi.luna.an) ) : ";
    in>>ob.v[i].an;
    cout<<endl;



    cout<<"In continuare, introduceti datele despre Notele, respectiv Absentele elevului."<<endl;
    cout<<endl;

    for (int j=0;j<7;j++)
        {
            if (j==0)
            {
                int localnrnote,localnrabsente;
                cout<<"Materia -- POO --"<<endl;

                cout<<"Numar note: ";
                in>>localnrnote;

                ob.v[i].materii[j].setter_nrnote(localnrnote);

                cout<<"Numar absente: ";
                in>>localnrabsente;

                ob.v[i].materii[j].setter_nrabsente(localnrabsente);

                ob.v[i].materii[j]=materie(localnrnote,localnrabsente);


                 if (localnrnote!=0)
                {
                    /// citire note     --- cu formatul nota/data
                    cout<<endl;

                    cout<<"Studentul are cel putin o absenta in cadrul sesiunii curente?"<<endl;
                    cout<<"Tastati da/nu si apasati ENTER"<<endl;
                    string raspuns;
                    cin>>raspuns;
                    if (raspuns=="da")
                       {
                        ob.v[i].set_medie(0);
                        cout<<"Nu mai este nevoie sa introduceti celelalte note!"<<endl;
                        ob.v[i].getter_materii()[j].setter_restanta(1);
                        ob.v[i].getter_materii()[j].setter_nrnote(0);
                       }
                    else
                    {

                    cout<<"Introduceti notele studentului in formatul NOTA/DATA( format data: zi.luna) dupa care apasati tasta ENTER!";
                    cout<<endl;
                    cout<<endl;
                    cin.get();
                    for (int k=0;k<localnrnote;k++)
                    {

                        int nota;
                        string data;
                        char citit[23];

                        cin.getline(citit, 3, '/');
                        nota=atoi(citit);

                        ob.v[i].set_note(nota,j,k);       /// setter de nota

                       // cin.get();
                        cin.getline(citit, 20, '\n');

                        data=string(citit);

                        ob.v[i].set_datanota(data,j,k);    /// setter de data de nota
                    }

                }
                    }

                 if (localnrabsente!=0)
                {
                    cout<<endl;
                    cout<<"Introduceti absentele studentului in formatul dd.mm (zi.luna) dupa care apasati tasta ENTER!";
                    cout<<endl;

                    for (int k=0;k<localnrabsente;k++)
                   {

                        char aux[200];
                        cin>>aux;
                        string data=string(aux);
                        ///cin.get();
                        ob.v[i].set_absenta(data,j,k);
                    }


                }
                cout<<endl;
                cout<<endl;

            }

            if (j==1)
            {
                int localnrnote,localnrabsente;
                cout<<"Materia -- Structuri de Date --"<<endl;

                cout<<"Numar note: ";
                in>>localnrnote;
                ob.v[i].materii[j].setter_nrnote(localnrnote);

                cout<<"Numar absente: ";
                in>>localnrabsente;

                ob.v[i].materii[j].setter_nrabsente(localnrabsente);

                ob.v[i].materii[j]=materie(localnrnote,localnrabsente);


                 if (localnrnote!=0)
                {
                    /// citire note     --- cu formatul nota/data

                    cout<<endl;
                    cout<<"Studentul are cel putin o absenta in cadrul sesiunii curente?"<<endl;
                    cout<<"Tastati da/nu si apasati ENTER"<<endl;
                    string raspuns;
                    cin>>raspuns;
                    if (raspuns=="da")
                       {
                        ob.v[i].set_medie(0);
                        cout<<"Nu mai este nevoie sa introduceti celelalte note!"<<endl;
                        ob.v[i].getter_materii()[j].setter_restanta(1);
                        ob.v[i].getter_materii()[j].setter_nrnote(0);
                       }
                    else
                    {

                    cout<<endl;
                    cout<<"Introduceti notele studentului in formatul NOTA/DATA( format data: zi.luna) dupa care apasati tasta ENTER!";
                    cout<<endl;

                    cin.get();
                    for (int k=0;k<localnrnote;k++)
                    {
                        int nota;
                        string data;
                        char citit[23];

                        cin.getline(citit, 3, '/');
                        nota=atoi(citit);

                        ob.v[i].set_note(nota,j,k);       /// setter de nota


                        cin.getline(citit, 20, '\n');
                        data=string(citit);

                        ob.v[i].set_datanota(data,j,k);    /// setter de data de nota
                    }

                    }
                }


                 if (localnrabsente!=0)
                {
                    cout<<endl;
                    cout<<"Introduceti absentele studentului in formatul dd.mm (zi.luna) dupa care apasati tasta ENTER!";
                    cout<<endl;

                    for (int k=0;k<localnrabsente;k++)
                   {
                        char aux[200];
                        cin>>aux;
                       /// data=string(aux);
                        ob.v[i].set_absenta(aux,j,k);
                    }


                }
                cout<<endl;
                cout<<endl;

            }

            if (j==2)
            {
                int localnrnote,localnrabsente;
                cout<<"Materia -- Tehnici Web --"<<endl;

                cout<<"Numar note: ";
                in>>localnrnote;
                ob.v[i].materii[j].setter_nrnote(localnrnote);

                cout<<"Numar absente: ";
                in>>localnrabsente;

                ob.v[i].materii[j].setter_nrabsente(localnrabsente);

                ob.v[i].materii[j]=materie(localnrnote,localnrabsente);


                 if (localnrnote!=0)
                {
                    /// citire note     --- cu formatul nota/data
                    cout<<endl;
                    cout<<"Studentul are cel putin o absenta in cadrul sesiunii curente?"<<endl;
                    cout<<"Tastati da/nu si apasati ENTER"<<endl;
                    string raspuns;
                    cin>>raspuns;
                    if (raspuns=="da")
                       {
                        ob.v[i].set_medie(0);
                        cout<<"Nu mai este nevoie sa introduceti celelalte note!"<<endl;
                        ob.v[i].getter_materii()[j].setter_restanta(1);
                        ob.v[i].getter_materii()[j].setter_nrnote(0);
                       }
                    else
                    {

                    cout<<endl;
                    cout<<"Introduceti notele studentului in formatul NOTA/DATA( format data: zi.luna) dupa care apasati tasta ENTER!";
                    cout<<endl;

                    cin.get();
                    for (int k=0;k<localnrnote;k++)
                    {
                        int nota;
                        string data;
                        char citit[23];

                        cin.getline(citit, 3, '/');
                        nota=atoi(citit);

                        ob.v[i].set_note(nota,j,k);       /// setter de nota


                        cin.getline(citit, 20, '\n');
                        data=string(citit);

                        ob.v[i].set_datanota(data,j,k);    /// setter de data de nota
                    }

                    }
                }


                 if (localnrabsente!=0)
                {
                    cout<<endl;
                    cout<<"Introduceti absentele studentului in formatul dd.mm (zi.luna) dupa care apasati tasta ENTER!";
                    cout<<endl;

                    for (int k=0;k<localnrabsente;k++)
                   {
                        char aux[200];
                        cin>>aux;
                       /// data=string(aux);
                        ob.v[i].set_absenta(aux,j,k);
                    }


                }
                cout<<endl;
                cout<<endl;

            }

            if (j==3)
            {
                int localnrnote,localnrabsente;
                cout<<"Materia -- LFA --"<<endl;

                cout<<"Numar note: ";
                in>>localnrnote;
                ob.v[i].materii[j].setter_nrnote(localnrnote);

                cout<<"Numar absente: ";
                in>>localnrabsente;

                ob.v[i].materii[j].setter_nrabsente(localnrabsente);

                ob.v[i].materii[j]=materie(localnrnote,localnrabsente);


                 if (localnrnote!=0)
                {
                    /// citire note     --- cu formatul nota/data
                    cout<<endl;
                    cout<<"Studentul are cel putin o absenta in cadrul sesiunii curente?"<<endl;
                    cout<<"Tastati da/nu si apasati ENTER"<<endl;
                    string raspuns;
                    cin>>raspuns;
                    if (raspuns=="da")
                       {
                        ob.v[i].set_medie(0);
                        cout<<"Nu mai este nevoie sa introduceti celelalte note!"<<endl;
                        ob.v[i].getter_materii()[j].setter_restanta(1);
                        ob.v[i].getter_materii()[j].setter_nrnote(0);
                       }
                    else
                    {

                     cout<<endl;
                    cout<<"Introduceti notele studentului in formatul NOTA/DATA( format data: zi.luna) dupa care apasati tasta ENTER!";
                    cout<<endl;

                    cin.get();
                    for (int k=0;k<localnrnote;k++)
                    {
                        int nota;
                        string data;
                        char citit[23];

                        cin.getline(citit, 3, '/');
                        nota=atoi(citit);

                        ob.v[i].set_note(nota,j,k);       /// setter de nota


                        cin.getline(citit, 20, '\n');
                        data=string(citit);

                        ob.v[i].set_datanota(data,j,k);    /// setter de data de nota
                    }

                }
                }


                 if (localnrabsente!=0)
                {
                    cout<<endl;
                    cout<<"Introduceti absentele studentului in formatul dd.mm (zi.luna) dupa care apasati tasta ENTER!";
                    cout<<endl;

                    for (int k=0;k<localnrabsente;k++)
                   {
                        char aux[200];
                        cin>>aux;
                       /// data=string(aux);
                        ob.v[i].set_absenta(aux,j,k);
                    }


                }
                cout<<endl;
                cout<<endl;

            }

            if (j==4)
            {
                int localnrnote,localnrabsente;
                cout<<"Materia -- Baze de Date --"<<endl;

                cout<<"Numar note: ";
                in>>localnrnote;
                ob.v[i].materii[j].setter_nrnote(localnrnote);

                cout<<"Numar absente: ";
                in>>localnrabsente;

                ob.v[i].materii[j].setter_nrabsente(localnrabsente);

                ob.v[i].materii[j]=materie(localnrnote,localnrabsente);


                 if (localnrnote!=0)
                {
                    /// citire note     --- cu formatul nota/data
                    cout<<endl;
                    cout<<"Studentul are cel putin o absenta in cadrul sesiunii curente?"<<endl;
                    cout<<"Tastati da/nu si apasati ENTER"<<endl;
                    string raspuns;
                    cin>>raspuns;
                    if (raspuns=="da")
                       {
                        ob.v[i].set_medie(0);
                        cout<<"Nu mai este nevoie sa introduceti celelalte note!"<<endl;
                        ob.v[i].getter_materii()[j].setter_restanta(1);
                        ob.v[i].getter_materii()[j].setter_nrnote(0);
                       }
                    else
                    {
                    cout<<endl;
                    cout<<"Introduceti notele studentului in formatul NOTA/DATA( format data: zi.luna) dupa care apasati tasta ENTER!";
                    cout<<endl;

                    cin.get();
                    for (int k=0;k<localnrnote;k++)
                    {
                        int nota;
                        string data;
                        char citit[23];

                        cin.getline(citit, 3, '/');
                        nota=atoi(citit);

                        ob.v[i].set_note(nota,j,k);       /// setter de nota


                        cin.getline(citit, 20, '\n');
                        data=string(citit);

                        ob.v[i].set_datanota(data,j,k);    /// setter de data de nota
                    }
                    }
                }


                 if (localnrabsente!=0)
                {
                    cout<<endl;
                    cout<<"Introduceti absentele studentului in formatul dd.mm (zi.luna) dupa care apasati tasta ENTER!";
                    cout<<endl;

                    for (int k=0;k<localnrabsente;k++)
                   {
                        char aux[200];
                        cin>>aux;
                       /// data=string(aux);
                        ob.v[i].set_absenta(aux,j,k);
                    }


                }
                cout<<endl;
                cout<<endl;

            }

            if (j==5)
            {
                int localnrnote,localnrabsente;
                cout<<"Materia -- Limba Engleza --"<<endl;

                cout<<"Numar note: ";
                in>>localnrnote;
                ob.v[i].materii[j].setter_nrnote(localnrnote);

                cout<<"Numar absente: ";
                in>>localnrabsente;

                ob.v[i].materii[j].setter_nrabsente(localnrabsente);

                ob.v[i].materii[j]=materie(localnrnote,localnrabsente);


                 if (localnrnote!=0)
                {
                    /// citire note     --- cu formatul nota/data

                    cout<<endl;
                    cout<<"Studentul are cel putin o absenta in cadrul sesiunii curente?"<<endl;
                    cout<<"Tastati da/nu si apasati ENTER"<<endl;
                    string raspuns;
                    cin>>raspuns;
                    if (raspuns=="da")
                       {
                        ob.v[i].set_medie(0);
                        cout<<"Nu mai este nevoie sa introduceti celelalte note!"<<endl;
                        ob.v[i].getter_materii()[j].setter_restanta(1);
                        ob.v[i].getter_materii()[j].setter_nrnote(0);
                       }
                    else
                    {

                    cout<<endl;
                    cout<<"Introduceti notele studentului in formatul NOTA/DATA( format data: zi.luna) dupa care apasati tasta ENTER!";
                    cout<<endl;

                    cin.get();
                    for (int k=0;k<localnrnote;k++)
                    {
                        int nota;
                        string data;
                        char citit[23];

                        cin.getline(citit, 3, '/');
                        nota=atoi(citit);

                        ob.v[i].set_note(nota,j,k);       /// setter de nota


                        cin.getline(citit, 20, '\n');
                        data=string(citit);

                        ob.v[i].set_datanota(data,j,k);    /// setter de data de nota
                    }
                    }
                }


                 if (localnrabsente!=0)
                {
                    cout<<endl;
                    cout<<"Introduceti absentele studentului in formatul dd.mm (zi.luna) dupa care apasati tasta ENTER!";
                    cout<<endl;

                    for (int k=0;k<localnrabsente;k++)
                   {
                        char aux[200];
                        cin>>aux;
                       /// data=string(aux);
                        ob.v[i].set_absenta(aux,j,k);
                    }


                }
                cout<<endl;
                cout<<endl;

            }

            if (j==6)
            {
                int localnrnote,localnrabsente;
                cout<<"Materia -- Sport --"<<endl;

                cout<<"Numar note: ";
                in>>localnrnote;
                ob.v[i].materii[j].setter_nrnote(localnrnote);

                cout<<"Numar absente: ";
                in>>localnrabsente;

                ob.v[i].materii[j].setter_nrabsente(localnrabsente);

                ob.v[i].materii[j]=materie(localnrnote,localnrabsente);


                 if (localnrnote!=0)
                {
                    /// citire note     --- cu formatul nota/data

                    cout<<endl;
                    cout<<"Studentul are cel putin o absenta in cadrul sesiunii curente?"<<endl;
                    cout<<"Tastati da/nu si apasati ENTER"<<endl;
                    string raspuns;
                    cin>>raspuns;
                    if (raspuns=="da")
                       {
                        ob.v[i].set_medie(0);
                        cout<<"Nu mai este nevoie sa introduceti celelalte note!"<<endl;
                        ob.v[i].getter_materii()[j].setter_restanta(1);
                        ob.v[i].getter_materii()[j].setter_nrnote(0);
                       }
                    else
                    {

                    cout<<endl;
                    cout<<"Introduceti notele studentului in formatul NOTA/DATA( format data: zi.luna) dupa care apasati tasta ENTER!";
                    cout<<endl;

                    cin.get();
                    for (int k=0;k<localnrnote;k++)
                    {
                        int nota;
                        string data;
                        char citit[23];

                        cin.getline(citit, 3, '/');
                        nota=atoi(citit);

                        ob.v[i].set_note(nota,j,k);       /// setter de nota


                        cin.getline(citit, 20, '\n');
                        data=string(citit);

                        ob.v[i].set_datanota(data,j,k);    /// setter de data de nota
                    }
                    }
                }


                 if (localnrabsente!=0)
                {

                    cout<<endl;
                    cout<<"Introduceti absentele studentului in formatul dd.mm (zi.luna) dupa care apasati tasta ENTER!";
                    cout<<endl;

                    for (int k=0;k<localnrabsente;k++)
                   {
                        char aux[200];
                        cin>>aux;
                       /// data=string(aux);
                        ob.v[i].set_absenta(aux,j,k);
                    }


                }
                cout<<endl;
                cout<<endl;

            }


    }
    cout<<endl;
    cout<<endl;

    cout<<"Apasati ENTER pentru a trece la urmatorul pas"<<endl;
    cout<<" --------------- ATENTIE!! --------------- "<<endl;
    cout<<"    Ecranul se va goli!    ";

    cin.get();
    cin.ignore();
    system("cls");

    }

    return in;
}








Student& grupa::cautare_student(string nume)
{
    for (int i=0;i<getter_nrstudenti();i++)
    {
        if (getter_studenti()[i].getnume()==nume)
            return getter_studenti()[i];
    }
}

int grupa::cautare_student_verificare (string nume)
{
    for (int i=0;i<getter_nrstudenti();i++)
    {
        if (getter_studenti()[i].getnume()==nume)
            return 1;
    }
    return 0;
}


int Student::nr_restante()
{
    int nr=0;
    for (int i=0;i<7;i++)
    {
        if (getter_materii()[i].get_restanta()==true)
            nr++;
    }
    return nr;
}

void Student::adaugare_nota (int materielocala)
{
    cout<<"Introduceti nota care vreti sa fie adaugata in formatul nota/data( format data: zi.luna )"<<endl;

    int nota;
    string data;
    char citit[23];
    cin.get();
    cin.getline(citit, 3, '/');
    nota=atoi(citit);


    cin.getline(citit, 20, '\n');
    data=string(citit);

    cout<<endl;
    cout<<endl;




    getter_materii()[materielocala].add_nota(nota,data);

}



int Student::stergere_nota( int materielocala)
{

    cout<<"Introduceti nota care trebuie stearsa, fara data la care a fost data!"<<endl;
    int nota;
    cin>>nota;

    cout<<endl;
    cout<<"Introduceti data la care a fost adaugata, dupa care apasati tasta ENTER"<<endl;
    string datanotalocala;

    cin>>datanotalocala;

    cout<<endl;
    int poznotastearsa=0;

    if (getter_materii()[materielocala].getter_nrnote()==0)
        return 0;

    for (int i=0;i<getter_materii()[materielocala].getter_nrnote();i++)
            if (getter_materii()[materielocala].get_note()[i]==nota && getter_materii()[materielocala].get_datanote()[i]==datanotalocala )
                poznotastearsa=i;
            else return 0;


    int k=0;

    materie aux= materie(getter_materii()[materielocala].getter_nrnote()-1,getter_materii()[materielocala].getter_nrabsente());

    for (int i=0;i<getter_materii()[materielocala].getter_nrnote();i++)
        if (i!=poznotastearsa)
            {
              aux.get_note()[k++]=getter_materii()[materielocala].get_note()[i];
              aux.get_datanote()[k++]=getter_materii()[materielocala].get_datanote()[i];
            }

    getter_materii()[materielocala].setter_nrnote(getter_materii()[materielocala].getter_nrnote()-1);


    getter_materii()[materielocala].setter_note(aux.get_note());
    getter_materii()[materielocala].setter_datanota(aux.get_datanote());

    return 1;


}




int Student::stergere_absenta( int materielocala)
{

    cout<<"Introduceti absenta care trebuie stearsa( format: zi.luna )"<<endl;
    string dataabsentalocala;
    cin>>dataabsentalocala;

    cout<<endl;
    int pozabsentaastearsa=0;

    for (int i=0;i<getter_materii()[materielocala].getter_nrabsente();i++)
            if (getter_materii()[materielocala].get_absente()[i]==dataabsentalocala  )
                pozabsentaastearsa=i;
            else return 0;



    int k=0;

    materie aux= materie(getter_materii()[materielocala].getter_nrnote(),getter_materii()[materielocala].getter_nrabsente()-1);

    for (int i=0;i<getter_materii()[materielocala].getter_nrabsente();i++)
        if (i!=pozabsentaastearsa)
              aux.get_absente()[k++]=getter_materii()[materielocala].get_absente()[i];


    getter_materii()[materielocala].setter_nrabsente(getter_materii()[materielocala].getter_nrabsente()-1);






    delete[] getter_materii()[materielocala].get_absente();

    getter_materii()[materielocala]=aux;

    return 1;

}



void Student::adaugare_absenta( int materielocala)
{

    cout<<"Introduceti absenta care vreti sa fie adaugata in formatul zi.luna "<<endl;


    char auxi[200];
    cin>>auxi;

    getter_materii()[materielocala].setter_nrabsente(getter_materii()[materielocala].getter_nrabsente()+1);



    materie aux= getter_materii()[materielocala] ;


    for (int i=0;i<getter_materii()[materielocala].getter_nrabsente()-1;i++)
        aux.get_absente()[i]=getter_materii()[materielocala].get_absente()[i];

    aux.get_absente()[getter_materii()[materielocala].getter_nrabsente()-1]=auxi;


   // getter_materii()[materielocala].setter_absente(aux.get_absente());

    this->set_materie(materielocala,aux);

}


double Student::calcul_medie_student ()
{
    int suma=0;
    double medie_totala=0.0, medie_materie=0.0;


    for (int i=0;i<7;i++)
        {
            suma=0;
            medie_materie=0.0;
            for (int j=0;j<getter_materii()[i].getter_nrnote();j++)
            {
                suma+=getter_materii()[i].get_note()[j];
            }

            if ( suma==0  )
                medie_materie=0.0;
            else
                medie_materie=suma/getter_materii()[i].getter_nrnote()  * 1.0;

            medie_totala+=medie_materie;
        }

    medie_totala= (float)medie_totala/7 *1.0;

   ///ob.set_medie(medie_totala);

    return medie_totala;

}

void grupa::setare_medie_grupa ()
{
    double suma=0.0;
    double medie_grupa=0.0;

    for (int i=0;i<getter_nrstudenti();i++)
            suma+=getter_studenti()[i].getmedie();


    medie_grupa=  (double) suma/getter_nrstudenti() * 1.0;

    setter_medie_totala(medie_grupa);
}

void grupa::setare_mass_medie_studenti ()
{
    for (int i=0;i<getter_nrstudenti();i++)
        getter_studenti()[i].set_medie(getter_studenti()[i].calcul_medie_student());
}


int grupa::nr_restante_grupa()
{
    int nr=0;

    for (int i=0;i<getter_nrstudenti();i++)
    {
        int ok=0;
        for (int j=0;j<7;j++)
            if (getter_studenti()[i].getter_materii()[j].get_restanta()==true)
                ok=1;
        if (ok==1)
            nr++;
    }

    return nr;

}



double Student::getter_medie_per_materie(int materielocala)
{
    int suma=0;
    double medie_totala=0.0, medie_materie=0.0;



            for (int j=0;j<getter_materii()[materielocala].getter_nrnote();j++)
            {
                suma+=getter_materii()[materielocala].get_note()[j];
            }

            if ( suma==0  )
                medie_materie=0.0;
            else
                medie_materie=suma/getter_materii()[materielocala].getter_nrnote()  * 1.0;

    return medie_materie;
}





void grupa::setare_restanta_mass_studenti()
{
    for (int i=0;i<getter_nrstudenti();i++)
        for (int j=0;j<7;j++)
            if (getter_studenti()[i].getter_medie_per_materie(j)<5.0)
                getter_studenti()[i].getter_materii()[j].setter_restanta(true);
            else
                getter_studenti()[i].getter_materii()[j].setter_restanta(false);
}





grupa grupaprincipala(0,0);


void meniu()
{

grupaprincipala.setare_mass_medie_studenti();
grupaprincipala.setare_medie_grupa();
 grupaprincipala.setare_restanta_mass_studenti();

cout<<"1) Afisati intreaga grupa"<<endl;
cout<<"2) Afisati detaliile despre un anumit student"<<endl;
cout<<endl;
cout<<"3) Adaugati o nota unui anumit student"<<endl;
cout<<"4) Stergeti o nota unui anumit student"<<endl;
cout<<endl;
cout<<"5) Adaugati o absenta unui anumit student"<<endl;
cout<<"6) Stergeti o absenta unui anumit stundent"<<endl;
cout<<endl;
cout<<"7) Afisati detalii despre restantele unui anumit student"<<endl;
cout<<"8) Afisati numarul de restantieri ai grupei"<<endl;
cout<<endl;
cout<<endl;
cout<<"9) Cititi alta grupa"<<endl;
cout<<"10) Iesiti din program"<<endl;

cout<<endl;
cout<<endl;
cout<<endl;
cout<<"Introduceti numarul optinuii pe care doriti sa o executati, DOAR NUMARUL, dupa care apasati tasta ENTER!"<<endl;
int raspuns;
cin>>raspuns;
//cin.get();
//cin.ignore();
system("cls");




switch(raspuns)
{
    case 1:
    {

        cout<<grupaprincipala;
        cout<<endl;
        cout<<endl;
        cout<<endl;
        cout<<"          ------  S-a afisat toata grupa! ------"<<endl;
        cout<<endl;
        cout<<"------ Apasati tasta ENTER pentru a afisa meniul -------"<<endl;
        cin.get();
        cin.ignore();
        system("cls");
        meniu();
    }

    case 2:
    {

                                cout<<"Introduceti numele studentului pe care doriti sa il cautati, EXACT cum a fost introdus la inceput"<<endl;
                                cin.get();
                                char aux[200];
                                cin.getline(aux, 200, '\n');
                                string nume=aux;
                                cout<<endl;
                                if (grupaprincipala.cautare_student_verificare(nume)==1)
                               {

                                    cout<<endl;
                                    cout<<"Ce doriti mai exact de la aceasta interogare? Scrieti DOAR numarul optiunii!"<<endl;
                                    cout<<endl;
                                    cout<<"------Submeniu------"<<endl;
                                    cout<<"1) Anul nasterii"<<endl;
                                    cout<<"2) Media acestuia"<<endl;
                                    cout<<"3) Informatii despre situatia acestuia"<<endl;
                                    cout<<endl;
                                    cout<<"4) Meniu"<<endl;
                                    cout<<endl;

                                    int raspuns1;
                                    cin>>raspuns1;
                                    system("cls");

                                    switch(raspuns1)
                                    {

                                                        case 1  :
                                                        {
                                                            cout<<"Data nasterii a studentului "<<nume<<" este "<<grupaprincipala.cautare_student(nume).getan();
                                                            cout<<endl;
                                                            cout<<endl;
                                                            cout<<endl;
                                                            cout<<"------ Apasati tasta ENTER pentru a afisa meniul -------"<<endl;
                                                             cin.get();
                                                            cin.ignore();
                                                            system("cls");
                                                            meniu();
                                                        }

                                                        case 2  :
                                                        {
                                                            cout<<"Media studentului "<<nume<<" este "<<grupaprincipala.cautare_student(nume).getmedie();
                                                            cout<<endl;
                                                            cout<<endl;
                                                            cout<<endl;
                                                            cout<<"------ Apasati tasta ENTER pentru a afisa meniul -------"<<endl;
                                                             cin.get();
                                                            cin.ignore();
                                                            system("cls");
                                                            meniu();
                                                        }


                                                        case 3:
                                                    {
                                                            cout<<"Alegeti din urmatorul submeniu la ce materie doriti sa va fie afisata situatia studentului "<<nume;
                                                            cout<<endl;
                                                            cout<<endl;
                                                            cout<<endl;

                                                            cout<<"1) POO"<<endl;
                                                            cout<<"2) Structuri de Date"<<endl;
                                                            cout<<"3) Tehnici Web"<<endl;
                                                            cout<<"4) LFA"<<endl;
                                                            cout<<"5) Baze de date"<<endl;
                                                            cout<<"6) Engleza"<<endl;
                                                            cout<<"7) Sport"<<endl;
                                                            cout<<endl;
                                                            cout<<"8) Meniu central"<<endl;

                                                            cout<<"9) Afisati situatia la toate materiile"<<endl;

                                                            cout<<endl;
                                                            cout<<"Scrieri DOAR numarul optiunii si tastati ENTER!"<<endl;
                                                            int raspuns2;
                                                            cin>>raspuns2;
                                                            system("cls");

                                                            switch(raspuns2)
                                                            {

                                                                case 1:

                                                                    {
                                                                                cout<<"Situatia studentului "<<nume<<" la materia POO este urmatoarea:"<<endl;

                                                                                cout<<endl;
                                                                                    if ( grupaprincipala.cautare_student(nume).getter_materii()[0].get_restanta()== 1 )
                                                                                    {
                                                                                        cout<<"La materia -- POO -- studentul "<<nume<<" este RESTANT!"<<endl;
                                                                                        cout<<endl;

                                                                                    }
                                                                                    else
                                                                                    {
                                                                                        cout<<"La materia -- POO -- studentul "<<nume<<" este RESTANT!"<<endl;
                                                                                        cout<<endl;

                                                                                    cout<<"La materia -- POO -- studentul "<<nume<<" are numarul de note = "<<grupaprincipala.cautare_student(nume).getter_materii()[0].getter_nrnote()<<" si numarul de absente = "<<grupaprincipala.cautare_student(nume).getter_materii()[0].getter_nrabsente();

                                                                                      cout<<endl;

                                                                                    if ( grupaprincipala.cautare_student(nume).getter_materii()[0].getter_nrnote() !=0 )
                                                                                    {
                                                                                        cout<<"Notele lui sunt urmatoarele: ";

                                                                                        for (int k=0;k<grupaprincipala.cautare_student(nume).getter_materii()[0].getter_nrnote();k++)
                                                                                        {
                                                                                            cout<<grupaprincipala.cautare_student(nume).getter_materii()[0].get_note()[k]<<"/"<<grupaprincipala.cautare_student(nume).getter_materii()[0].get_datanote()[k]<<"  ";
                                                                                        }
                                                                                    }

                                                                                    }


                                                                                    if ( grupaprincipala.cautare_student(nume).getter_materii()[0].getter_nrabsente() !=0 )
                                                                                    {
                                                                                        cout<<endl;

                                                                                        cout<<"Absentele lui sunt urmatoarele: ";

                                                                                        for (int k=0;k<grupaprincipala.cautare_student(nume).getter_materii()[0].getter_nrabsente();k++)
                                                                                        {
                                                                                            cout<<grupaprincipala.cautare_student(nume).getter_materii()[0].get_absente()[k]<<"  ";
                                                                                        }
                                                                                    }
                                                                                    cout<<endl;
                                                                                    cout<<endl;
                                                                                    cout<<"------ Apasati tasta ENTER pentru a afisa meniul -------"<<endl;
                                                                                    cin.get();
                                                                                    cin.ignore();
                                                                                    system("cls");
                                                                                    meniu();

                                                            }

                                                            case 2:
                                                                        {


                                                                                    cout<<"Situatia studentului "<<nume<<" la materia Structuri de Date este urmatoarea:"<<endl;

                                                                                    cout<<endl;
                                                                                        if ( grupaprincipala.cautare_student(nume).getter_materii()[1].get_restanta()== 1 )
                                                                                        {
                                                                                            cout<<"La materia -- Structuri de Date -- studentul "<<nume<<" este RESTANT!"<<endl;
                                                                                            cout<<endl;

                                                                                        }
                                                                                        else
                                                                                        {

                                                                                        cout<<"La materia -- Structuri de Date -- studentul "<<nume<<" are numarul de note = "<<grupaprincipala.cautare_student(nume).getter_materii()[1].getter_nrnote()<<" si numarul de absente = "<<grupaprincipala.cautare_student(nume).getter_materii()[1].getter_nrabsente();

                                                                                          cout<<endl;

                                                                                        if ( grupaprincipala.cautare_student(nume).getter_materii()[1].getter_nrnote() !=0 )
                                                                                        {
                                                                                            cout<<"Notele lui sunt urmatoarele: ";

                                                                                            for (int k=0;k<grupaprincipala.cautare_student(nume).getter_materii()[1].getter_nrnote();k++)
                                                                                            {
                                                                                                cout<<grupaprincipala.cautare_student(nume).getter_materii()[1].get_note()[k]<<"/"<<grupaprincipala.cautare_student(nume).getter_materii()[1].get_datanote()[k]<<"  ";
                                                                                            }
                                                                                        }

                                                                                        }


                                                                                        if ( grupaprincipala.cautare_student(nume).getter_materii()[1].getter_nrabsente() !=0 )
                                                                                        {
                                                                                            cout<<endl;

                                                                                            cout<<"Absentele lui sunt urmatoarele: ";

                                                                                            for (int k=0;k<grupaprincipala.cautare_student(nume).getter_materii()[1].getter_nrabsente();k++)
                                                                                            {
                                                                                                cout<<grupaprincipala.cautare_student(nume).getter_materii()[1].get_absente()[k]<<"  ";
                                                                                            }
                                                                                        }
                                                                                        cout<<endl;
                                                                                        cout<<endl;
                                                                                        cout<<"------ Apasati tasta ENTER pentru a afisa meniul -------"<<endl;
                                                                                        cin.get();
                                                                                        cin.ignore();
                                                                                        system("cls");
                                                                                        meniu();
                                                            }



                                                            case 4:
                                                                            {


                                                                                    cout<<"Situatia studentului "<<nume<<" la materia LFA este urmatoarea:"<<endl;

                                                                                    cout<<endl;
                                                                                        if ( grupaprincipala.cautare_student(nume).getter_materii()[3].get_restanta()== 1 )
                                                                                        {
                                                                                            cout<<"La materia -- LFA -- studentul "<<nume<<" este RESTANT!"<<endl;
                                                                                            cout<<endl;

                                                                                        }
                                                                                        else
                                                                                        {

                                                                                        cout<<"La materia -- LFA -- studentul "<<nume<<" are numarul de note = "<<grupaprincipala.cautare_student(nume).getter_materii()[3].getter_nrnote()<<" si numarul de absente = "<<grupaprincipala.cautare_student(nume).getter_materii()[3].getter_nrabsente();

                                                                                          cout<<endl;

                                                                                        if ( grupaprincipala.cautare_student(nume).getter_materii()[3].getter_nrnote() !=0 )
                                                                                        {
                                                                                            cout<<"Notele lui sunt urmatoarele: ";

                                                                                            for (int k=0;k<grupaprincipala.cautare_student(nume).getter_materii()[3].getter_nrnote();k++)
                                                                                            {
                                                                                                cout<<grupaprincipala.cautare_student(nume).getter_materii()[3].get_note()[k]<<"/"<<grupaprincipala.cautare_student(nume).getter_materii()[3].get_datanote()[k]<<"  ";
                                                                                            }
                                                                                        }

                                                                                        }


                                                                                        if ( grupaprincipala.cautare_student(nume).getter_materii()[3].getter_nrabsente() !=0 )
                                                                                        {
                                                                                            cout<<endl;

                                                                                            cout<<"Absentele lui sunt urmatoarele: ";

                                                                                            for (int k=0;k<grupaprincipala.cautare_student(nume).getter_materii()[3].getter_nrabsente();k++)
                                                                                            {
                                                                                                cout<<grupaprincipala.cautare_student(nume).getter_materii()[3].get_absente()[k]<<"  ";
                                                                                            }
                                                                                        }
                                                                                        cout<<endl;
                                                                                        cout<<endl;
                                                                                        cout<<"------ Apasati tasta ENTER pentru a afisa meniul -------"<<endl;
                                                                                        cin.get();
                                                                                        cin.ignore();
                                                                                        system("cls");
                                                                                        meniu();

                                                            }

                                                            case 3:

                                                                        {

                                                                                        cout<<"Situatia studentului "<<nume<<" la materia Tehnici Web este urmatoarea:"<<endl;

                                                                                        cout<<endl;
                                                                                            if ( grupaprincipala.cautare_student(nume).getter_materii()[2].get_restanta()== 1 )
                                                                                            {
                                                                                                cout<<"La materia -- Tehnici Web -- studentul "<<nume<<" este RESTANT!"<<endl;
                                                                                                cout<<endl;

                                                                                            }
                                                                                            else
                                                                                            {

                                                                                            cout<<"La materia -- Tehnici Web -- studentul "<<nume<<" are numarul de note = "<<grupaprincipala.cautare_student(nume).getter_materii()[2].getter_nrnote()<<" si numarul de absente = "<<grupaprincipala.cautare_student(nume).getter_materii()[2].getter_nrabsente();

                                                                                              cout<<endl;

                                                                                            if ( grupaprincipala.cautare_student(nume).getter_materii()[2].getter_nrnote() !=0 )
                                                                                            {
                                                                                                cout<<"Notele lui sunt urmatoarele: ";

                                                                                                for (int k=0;k<grupaprincipala.cautare_student(nume).getter_materii()[2].getter_nrnote();k++)
                                                                                                {
                                                                                                    cout<<grupaprincipala.cautare_student(nume).getter_materii()[2].get_note()[k]<<"/"<<grupaprincipala.cautare_student(nume).getter_materii()[2].get_datanote()[k]<<"  ";
                                                                                                }
                                                                                            }

                                                                                            }


                                                                                            if ( grupaprincipala.cautare_student(nume).getter_materii()[2].getter_nrabsente() !=0 )
                                                                                            {
                                                                                                cout<<endl;

                                                                                                cout<<"Absentele lui sunt urmatoarele: ";

                                                                                                for (int k=0;k<grupaprincipala.cautare_student(nume).getter_materii()[2].getter_nrabsente();k++)
                                                                                                {
                                                                                                    cout<<grupaprincipala.cautare_student(nume).getter_materii()[2].get_absente()[k]<<"  ";
                                                                                                }
                                                                                            }
                                                                                            cout<<endl;
                                                                                            cout<<endl;
                                                                                            cout<<"------ Apasati tasta ENTER pentru a afisa meniul -------"<<endl;
                                                                                            cin.get();
                                                                                            cin.ignore();
                                                                                            system("cls");
                                                                                            meniu();
                                                            }

                                                            case 6:

                                                                        {


                                                                                        cout<<"Situatia studentului "<<nume<<" la materia Engleza este urmatoarea:"<<endl;

                                                                                        cout<<endl;
                                                                                            if ( grupaprincipala.cautare_student(nume).getter_materii()[5].get_restanta()== 1 )
                                                                                            {
                                                                                                cout<<"La materia -- Engleza -- studentul "<<nume<<" este RESTANT!"<<endl;
                                                                                                cout<<endl;

                                                                                            }
                                                                                            else
                                                                                            {

                                                                                            cout<<"La materia -- Engleza -- studentul "<<nume<<" are numarul de note = "<<grupaprincipala.cautare_student(nume).getter_materii()[5].getter_nrnote()<<" si numarul de absente = "<<grupaprincipala.cautare_student(nume).getter_materii()[5].getter_nrabsente();

                                                                                              cout<<endl;

                                                                                            if ( grupaprincipala.cautare_student(nume).getter_materii()[5].getter_nrnote() !=0 )
                                                                                            {
                                                                                                cout<<"Notele lui sunt urmatoarele: ";

                                                                                                for (int k=0;k<grupaprincipala.cautare_student(nume).getter_materii()[5].getter_nrnote();k++)
                                                                                                {
                                                                                                    cout<<grupaprincipala.cautare_student(nume).getter_materii()[5].get_note()[k]<<"/"<<grupaprincipala.cautare_student(nume).getter_materii()[5].get_datanote()[k]<<"  ";
                                                                                                }
                                                                                            }

                                                                                            }


                                                                                            if ( grupaprincipala.cautare_student(nume).getter_materii()[5].getter_nrabsente() !=0 )
                                                                                            {
                                                                                                cout<<endl;

                                                                                                cout<<"Absentele lui sunt urmatoarele: ";

                                                                                                for (int k=0;k<grupaprincipala.cautare_student(nume).getter_materii()[5].getter_nrabsente();k++)
                                                                                                {
                                                                                                    cout<<grupaprincipala.cautare_student(nume).getter_materii()[5].get_absente()[k]<<"  ";
                                                                                                }
                                                                                            }
                                                                                            cout<<endl;
                                                                                            cout<<endl;
                                                                                            cout<<"------ Apasati tasta ENTER pentru a afisa meniul -------"<<endl;
                                                                                            cin.get();
                                                                                            cin.ignore();
                                                                                            system("cls");
                                                                                            meniu();

                                                            }




                                                            case 5:
                                                                                {


                                                                                    cout<<"Situatia studentului "<<nume<<" la materia Baze de date este urmatoarea:"<<endl;

                                                                                    cout<<endl;
                                                                                        if ( grupaprincipala.cautare_student(nume).getter_materii()[4].get_restanta()== 1 )
                                                                                        {
                                                                                            cout<<"La materia -- Baze de date -- studentul "<<nume<<" este RESTANT!"<<endl;
                                                                                            cout<<endl;

                                                                                        }
                                                                                        else
                                                                                        {

                                                                                        cout<<"La materia -- Baze de date -- studentul "<<nume<<" are numarul de note = "<<grupaprincipala.cautare_student(nume).getter_materii()[4].getter_nrnote()<<" si numarul de absente = "<<grupaprincipala.cautare_student(nume).getter_materii()[4].getter_nrabsente();

                                                                                          cout<<endl;

                                                                                        if ( grupaprincipala.cautare_student(nume).getter_materii()[4].getter_nrnote() !=0 )
                                                                                        {
                                                                                            cout<<"Notele lui sunt urmatoarele: ";

                                                                                            for (int k=0;k<grupaprincipala.cautare_student(nume).getter_materii()[4].getter_nrnote();k++)
                                                                                            {
                                                                                                cout<<grupaprincipala.cautare_student(nume).getter_materii()[4].get_note()[k]<<"/"<<grupaprincipala.cautare_student(nume).getter_materii()[4].get_datanote()[k]<<"  ";
                                                                                            }
                                                                                        }

                                                                                        }


                                                                                        if ( grupaprincipala.cautare_student(nume).getter_materii()[4].getter_nrabsente() !=0 )
                                                                                        {
                                                                                            cout<<endl;

                                                                                            cout<<"Absentele lui sunt urmatoarele: ";

                                                                                            for (int k=0;k<grupaprincipala.cautare_student(nume).getter_materii()[4].getter_nrabsente();k++)
                                                                                            {
                                                                                                cout<<grupaprincipala.cautare_student(nume).getter_materii()[4].get_absente()[k]<<"  ";
                                                                                            }
                                                                                        }
                                                                                        cout<<endl;
                                                                                        cout<<endl;
                                                                                        cout<<"------ Apasati tasta ENTER pentru a afisa meniul -------"<<endl;
                                                                                        cin.get();
                                                                                        cin.ignore();
                                                                                        system("cls");
                                                                                        meniu();

                                                            }


                                                            case 7:
                                                                        {

                                                                                    cout<<"Situatia studentului "<<nume<<" la materia Sport este urmatoarea:"<<endl;

                                                                                    cout<<endl;
                                                                                        if ( grupaprincipala.cautare_student(nume).getter_materii()[6].get_restanta()== 1 )
                                                                                        {
                                                                                            cout<<"La materia -- Sport -- studentul "<<nume<<" este RESTANT!"<<endl;
                                                                                            cout<<endl;

                                                                                        }
                                                                                        else
                                                                                        {

                                                                                        cout<<"La materia -- Sport -- studentul "<<nume<<" are numarul de note = "<<grupaprincipala.cautare_student(nume).getter_materii()[6].getter_nrnote()<<" si numarul de absente = "<<grupaprincipala.cautare_student(nume).getter_materii()[6].getter_nrabsente();

                                                                                          cout<<endl;

                                                                                        if ( grupaprincipala.cautare_student(nume).getter_materii()[6].getter_nrnote() !=0 )
                                                                                        {
                                                                                            cout<<"Notele lui sunt urmatoarele: ";

                                                                                            for (int k=0;k<grupaprincipala.cautare_student(nume).getter_materii()[6].getter_nrnote();k++)
                                                                                            {
                                                                                                cout<<grupaprincipala.cautare_student(nume).getter_materii()[6].get_note()[k]<<"/"<<grupaprincipala.cautare_student(nume).getter_materii()[6].get_datanote()[k]<<"  ";
                                                                                            }
                                                                                        }

                                                                                        }


                                                                                        if ( grupaprincipala.cautare_student(nume).getter_materii()[6].getter_nrabsente() !=0 )
                                                                                        {
                                                                                            cout<<endl;

                                                                                            cout<<"Absentele lui sunt urmatoarele: ";

                                                                                            for (int k=0;k<grupaprincipala.cautare_student(nume).getter_materii()[6].getter_nrabsente();k++)
                                                                                            {
                                                                                                cout<<grupaprincipala.cautare_student(nume).getter_materii()[6].get_absente()[k]<<"  ";
                                                                                            }
                                                                                        }
                                                                                        cout<<endl;
                                                                                        cout<<endl;
                                                                                        cout<<"------ Apasati tasta ENTER pentru a afisa meniul -------"<<endl;
                                                                                        cin.get();
                                                                                        cin.ignore();
                                                                                        system("cls");
                                                                                        meniu();

                                                            }



                                                            case 8:
                                                                            {
                                                                                system("cls");
                                                                                meniu();
                                                                            }




                                                            case 9:
                                                                    {

                                                                                                cout<<"Situatia studentului "<<nume<<" la toate materiile este urmatoarea:"<<endl;

                                                                                                cout<<endl;

                                                                                            if ( grupaprincipala.cautare_student(nume).getter_materii()[0].get_restanta()== 1 )
                                                                                            {
                                                                                                cout<<"La materia -- POO -- studentul "<<nume<<" este RESTANT!"<<endl;
                                                                                                cout<<endl;

                                                                                            }
                                                                                            else
                                                                                            {

                                                                                            cout<<"La materia -- POO -- studentul "<<nume<<" are numarul de note = "<<grupaprincipala.cautare_student(nume).getter_materii()[0].getter_nrnote()<<" si numarul de absente = "<<grupaprincipala.cautare_student(nume).getter_materii()[0].getter_nrabsente();

                                                                                              cout<<endl;

                                                                                            if ( grupaprincipala.cautare_student(nume).getter_materii()[0].getter_nrnote() !=0 )
                                                                                            {
                                                                                                cout<<"Notele lui sunt urmatoarele: ";

                                                                                                for (int k=0;k<grupaprincipala.cautare_student(nume).getter_materii()[0].getter_nrnote();k++)
                                                                                                {
                                                                                                    if ((grupaprincipala.cautare_student(nume).getter_materii()[0].get_datanote()[k])!="")
                                                                                                        cout<<grupaprincipala.cautare_student(nume).getter_materii()[0].get_note()[k]<<"/"<<grupaprincipala.cautare_student(nume).getter_materii()[0].get_datanote()[k]<<"  ";
                                                                                                }
                                                                                            }

                                                                                            }


                                                                                            if ( grupaprincipala.cautare_student(nume).getter_materii()[0].getter_nrabsente() !=0 )
                                                                                            {
                                                                                                cout<<endl;

                                                                                                cout<<"Absentele lui sunt urmatoarele: ";

                                                                                                for (int k=0;k<grupaprincipala.cautare_student(nume).getter_materii()[0].getter_nrabsente();k++)
                                                                                                {
                                                                                                    cout<<grupaprincipala.cautare_student(nume).getter_materii()[0].get_absente()[k]<<"  ";
                                                                                                }
                                                                                            }
                                                                                            cout<<endl;
                                                                                            cout<<endl;
                                                                                cout<<endl;

                                                                                cout<<endl;
                                                                                            if ( grupaprincipala.cautare_student(nume).getter_materii()[1].get_restanta()== 1 )
                                                                                            {
                                                                                                cout<<"La materia -- Structuri de Date -- studentul "<<nume<<" este RESTANT!"<<endl;
                                                                                                cout<<endl;

                                                                                            }
                                                                                            else
                                                                                            {

                                                                                            cout<<"La materia -- Structuri de Date -- studentul "<<nume<<" are numarul de note = "<<grupaprincipala.cautare_student(nume).getter_materii()[1].getter_nrnote()<<" si numarul de absente = "<<grupaprincipala.cautare_student(nume).getter_materii()[1].getter_nrabsente();

                                                                                              cout<<endl;

                                                                                            if ( grupaprincipala.cautare_student(nume).getter_materii()[1].getter_nrnote() !=0 )
                                                                                            {
                                                                                                cout<<"Notele lui sunt urmatoarele: ";

                                                                                                for (int k=0;k<grupaprincipala.cautare_student(nume).getter_materii()[1].getter_nrnote();k++)
                                                                                                {
                                                                                                    cout<<grupaprincipala.cautare_student(nume).getter_materii()[1].get_note()[k]<<"/"<<grupaprincipala.cautare_student(nume).getter_materii()[1].get_datanote()[k]<<"  ";
                                                                                                }
                                                                                            }

                                                                                            }


                                                                                            if ( grupaprincipala.cautare_student(nume).getter_materii()[1].getter_nrabsente() !=0 )
                                                                                            {
                                                                                                cout<<endl;

                                                                                                cout<<"Absentele lui sunt urmatoarele: ";

                                                                                                for (int k=0;k<grupaprincipala.cautare_student(nume).getter_materii()[1].getter_nrabsente();k++)
                                                                                                {
                                                                                                    cout<<grupaprincipala.cautare_student(nume).getter_materii()[1].get_absente()[k]<<"  ";
                                                                                                }
                                                                                            }
                                                                                            cout<<endl;
                                                                                            cout<<endl;
                                                                                cout<<endl;
                                                                                            if ( grupaprincipala.cautare_student(nume).getter_materii()[2].get_restanta()== 1 )
                                                                                            {
                                                                                                cout<<"La materia -- Tehnici Web -- studentul "<<nume<<" este RESTANT!"<<endl;
                                                                                                cout<<endl;

                                                                                            }
                                                                                            else
                                                                                            {

                                                                                            cout<<"La materia -- Tehnici Web -- studentul "<<nume<<" are numarul de note = "<<grupaprincipala.cautare_student(nume).getter_materii()[2].getter_nrnote()<<" si numarul de absente = "<<grupaprincipala.cautare_student(nume).getter_materii()[2].getter_nrabsente();

                                                                                              cout<<endl;

                                                                                            if ( grupaprincipala.cautare_student(nume).getter_materii()[2].getter_nrnote() !=0 )
                                                                                            {
                                                                                                cout<<"Notele lui sunt urmatoarele: ";

                                                                                                for (int k=0;k<grupaprincipala.cautare_student(nume).getter_materii()[2].getter_nrnote();k++)
                                                                                                {
                                                                                                    cout<<grupaprincipala.cautare_student(nume).getter_materii()[2].get_note()[k]<<"/"<<grupaprincipala.cautare_student(nume).getter_materii()[2].get_datanote()[k]<<"  ";
                                                                                                }
                                                                                            }

                                                                                            }


                                                                                            if ( grupaprincipala.cautare_student(nume).getter_materii()[2].getter_nrabsente() !=0 )
                                                                                            {
                                                                                                cout<<endl;

                                                                                                cout<<"Absentele lui sunt urmatoarele: ";

                                                                                                for (int k=0;k<grupaprincipala.cautare_student(nume).getter_materii()[2].getter_nrabsente();k++)
                                                                                                {
                                                                                                    cout<<grupaprincipala.cautare_student(nume).getter_materii()[2].get_absente()[k]<<"  ";
                                                                                                }
                                                                                            }
                                                                                            cout<<endl;
                                                                                            cout<<endl;

                                                                                cout<<endl;
                                                                                            if ( grupaprincipala.cautare_student(nume).getter_materii()[3].get_restanta()== 1 )
                                                                                            {
                                                                                                cout<<"La materia -- LFA -- studentul "<<nume<<" este RESTANT!"<<endl;
                                                                                                cout<<endl;

                                                                                            }
                                                                                            else
                                                                                            {

                                                                                            cout<<"La materia -- LFA -- studentul "<<nume<<" are numarul de note = "<<grupaprincipala.cautare_student(nume).getter_materii()[3].getter_nrnote()<<" si numarul de absente = "<<grupaprincipala.cautare_student(nume).getter_materii()[3].getter_nrabsente();

                                                                                              cout<<endl;

                                                                                            if ( grupaprincipala.cautare_student(nume).getter_materii()[3].getter_nrnote() !=0 )
                                                                                            {
                                                                                                cout<<"Notele lui sunt urmatoarele: ";

                                                                                                for (int k=0;k<grupaprincipala.cautare_student(nume).getter_materii()[3].getter_nrnote();k++)
                                                                                                {
                                                                                                    cout<<grupaprincipala.cautare_student(nume).getter_materii()[3].get_note()[k]<<"/"<<grupaprincipala.cautare_student(nume).getter_materii()[3].get_datanote()[k]<<"  ";
                                                                                                }
                                                                                            }

                                                                                            }


                                                                                            if ( grupaprincipala.cautare_student(nume).getter_materii()[3].getter_nrabsente() !=0 )
                                                                                            {
                                                                                                cout<<endl;

                                                                                                cout<<"Absentele lui sunt urmatoarele: ";

                                                                                                for (int k=0;k<grupaprincipala.cautare_student(nume).getter_materii()[3].getter_nrabsente();k++)
                                                                                                {
                                                                                                    cout<<grupaprincipala.cautare_student(nume).getter_materii()[3].get_absente()[k]<<"  ";
                                                                                                }
                                                                                            }
                                                                                            cout<<endl;
                                                                                            cout<<endl;

                                                                                cout<<endl;
                                                                                            if ( grupaprincipala.cautare_student(nume).getter_materii()[4].get_restanta()== 1 )
                                                                                            {
                                                                                                cout<<"La materia -- Baze de date -- studentul "<<nume<<" este RESTANT!"<<endl;
                                                                                                cout<<endl;

                                                                                            }
                                                                                            else
                                                                                            {

                                                                                            cout<<"La materia -- Baze de date -- studentul "<<nume<<" are numarul de note = "<<grupaprincipala.cautare_student(nume).getter_materii()[4].getter_nrnote()<<" si numarul de absente = "<<grupaprincipala.cautare_student(nume).getter_materii()[4].getter_nrabsente();

                                                                                              cout<<endl;

                                                                                            if ( grupaprincipala.cautare_student(nume).getter_materii()[4].getter_nrnote() !=0 )
                                                                                            {
                                                                                                cout<<"Notele lui sunt urmatoarele: ";

                                                                                                for (int k=0;k<grupaprincipala.cautare_student(nume).getter_materii()[4].getter_nrnote();k++)
                                                                                                {
                                                                                                    cout<<grupaprincipala.cautare_student(nume).getter_materii()[4].get_note()[k]<<"/"<<grupaprincipala.cautare_student(nume).getter_materii()[4].get_datanote()[k]<<"  ";
                                                                                                }
                                                                                            }

                                                                                            }


                                                                                            if ( grupaprincipala.cautare_student(nume).getter_materii()[4].getter_nrabsente() !=0 )
                                                                                            {
                                                                                                cout<<endl;

                                                                                                cout<<"Absentele lui sunt urmatoarele: ";

                                                                                                for (int k=0;k<grupaprincipala.cautare_student(nume).getter_materii()[4].getter_nrabsente();k++)
                                                                                                {
                                                                                                    cout<<grupaprincipala.cautare_student(nume).getter_materii()[4].get_absente()[k]<<"  ";
                                                                                                }
                                                                                            }
                                                                                            cout<<endl;
                                                                                            cout<<endl;

                                                                                            cout<<endl;
                                                                                            if ( grupaprincipala.cautare_student(nume).getter_materii()[5].get_restanta()== 1 )
                                                                                            {
                                                                                                cout<<"La materia -- Engleza -- studentul "<<nume<<" este RESTANT!"<<endl;
                                                                                                cout<<endl;

                                                                                            }
                                                                                            else
                                                                                                        {

                                                                                            cout<<"La materia -- Engleza -- studentul "<<nume<<" are numarul de note = "<<grupaprincipala.cautare_student(nume).getter_materii()[5].getter_nrnote()<<" si numarul de absente = "<<grupaprincipala.cautare_student(nume).getter_materii()[5].getter_nrabsente();

                                                                                              cout<<endl;

                                                                                            if ( grupaprincipala.cautare_student(nume).getter_materii()[5].getter_nrnote() !=0 )
                                                                                            {
                                                                                                cout<<"Notele lui sunt urmatoarele: ";

                                                                                                for (int k=0;k<grupaprincipala.cautare_student(nume).getter_materii()[5].getter_nrnote();k++)
                                                                                                {
                                                                                                    cout<<grupaprincipala.cautare_student(nume).getter_materii()[5].get_note()[k]<<"/"<<grupaprincipala.cautare_student(nume).getter_materii()[5].get_datanote()[k]<<"  ";
                                                                                                }
                                                                                            }

                                                                                                        }


                                                                                            if ( grupaprincipala.cautare_student(nume).getter_materii()[5].getter_nrabsente() !=0 )
                                                                                            {
                                                                                                cout<<endl;

                                                                                                cout<<"Absentele lui sunt urmatoarele: ";

                                                                                                for (int k=0;k<grupaprincipala.cautare_student(nume).getter_materii()[5].getter_nrabsente();k++)
                                                                                                {
                                                                                                    cout<<grupaprincipala.cautare_student(nume).getter_materii()[5].get_absente()[k]<<"  ";
                                                                                                }
                                                                                            }
                                                                                            cout<<endl;
                                                                                            cout<<endl;


                                                                                                cout<<endl;
                                                                                                if ( grupaprincipala.cautare_student(nume).getter_materii()[6].get_restanta()== 1 )
                                                                                                {
                                                                                                    cout<<"La materia -- Sport -- studentul "<<nume<<" este RESTANT!"<<endl;
                                                                                                    cout<<endl;

                                                                                                }
                                                                                                else
                                                                                                {

                                                                                                cout<<"La materia -- Sport -- studentul "<<nume<<" are numarul de note = "<<grupaprincipala.cautare_student(nume).getter_materii()[6].getter_nrnote()<<" si numarul de absente = "<<grupaprincipala.cautare_student(nume).getter_materii()[6].getter_nrabsente();

                                                                                                  cout<<endl;

                                                                                                if ( grupaprincipala.cautare_student(nume).getter_materii()[6].getter_nrnote() !=0 )
                                                                                                {
                                                                                                    cout<<"Notele lui sunt urmatoarele: ";

                                                                                                    for (int k=0;k<grupaprincipala.cautare_student(nume).getter_materii()[6].getter_nrnote();k++)
                                                                                                    {
                                                                                                        cout<<grupaprincipala.cautare_student(nume).getter_materii()[6].get_note()[k]<<"/"<<grupaprincipala.cautare_student(nume).getter_materii()[6].get_datanote()[k]<<"  ";
                                                                                                    }
                                                                                                }

                                                                                                }


                                                                                                if ( grupaprincipala.cautare_student(nume).getter_materii()[6].getter_nrabsente() !=0 )
                                                                                                {
                                                                                                    cout<<endl;

                                                                                                    cout<<"Absentele lui sunt urmatoarele: ";

                                                                                                    for (int k=0;k<grupaprincipala.cautare_student(nume).getter_materii()[6].getter_nrabsente();k++)
                                                                                                    {
                                                                                                        cout<<grupaprincipala.cautare_student(nume).getter_materii()[6].get_absente()[k]<<"  ";
                                                                                                    }
                                                                                                }
                                                                                                cout<<endl;
                                                                                                cout<<endl;



                                                                                                cout<<"       ---- Afisarea s-a sfarsit ------   " <<endl;
                                                                                                cout<<"        ------ Apasati tasta ENTER pentru a afisa meniul -------       "<<endl;
                                                                                                cin.get();
                                                                                                cin.ignore();
                                                                                                system("cls");
                                                                                                meniu();

                                                            }


                                                            default:
                                                                {

                                                                cout<<"Nu ati ales nicio optiune valida!"<<endl;
                                                                cout<<"Va rugam reincercati!"<<endl;
                                                                cout<<endl;
                                                                cout<<endl;
                                                                cout<<"------ Apasati tasta ENTER pentru a afisa meniul -------"<<endl;
                                                                cin.get();
                                                                cin.ignore();
                                                                system("cls");
                                                                meniu();

                                                                }


                                                                            }


                                                            }



                                                            case 4:
                                                                {

                                                                system("cls");
                                                                meniu();

                                                                }

                                                            default:
                                                              {
                                                                    cout<<"NU ati ales o optiune valabila!"<<endl;
                                                                    cout<<" Va rugam reincercati!"<<endl;
                                                                    cout<<endl;
                                                                    cout<<endl;

                                                                    cout<<endl;
                                                                    cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                                                    cin.get();
                                                                    cin.ignore();
                                                                    system("cls");
                                                                    meniu();
                                                            }


                                    }

                               }
                            else

                               {

                                cout<<"Nu s-a gasit acest nume!"<<endl;
                                cout<<"Verificati numele introdus si incercati din nou!"<<endl;
                               // cin.get();
                                cin.ignore();
                                system("cls");
                                meniu();
                               }

            }




    case 3:
    {
                    cout<<"Introduceti numele studentului caruia doriti sa ii adaugati o NOTA, EXACT cum a fost introdus la inceput"<<endl;
                    cin.get();
                    char aux[200];
                    cin.getline(aux, 200, '\n');
                    string nume=aux;
                    cout<<endl;
                    if (grupaprincipala.cautare_student_verificare(nume)==1)
                   {

                                    cout<<endl;
                                    cout<<"La ce materie doriti sa adaugati o NOTA? Scrieti DOAR numarul optiunii!"<<endl;
                                    cout<<endl;
                                    cout<<"------Submeniu------"<<endl;
                                    cout<<"1) POO"<<endl;
                                    cout<<"2) Structuri de Date"<<endl;
                                    cout<<"3) Tehnici Web"<<endl;
                                    cout<<"4) LFA"<<endl;
                                    cout<<"5) Baze de Date"<<endl;
                                    cout<<"6) Engleza"<<endl;
                                    cout<<"7) Sport"<<endl;
                                    cout<<endl;
                                    cout<<"8) Meniu"<<endl;
                                    cout<<endl;

                                    int raspuns1;
                                    cin>>raspuns1;
                                    system("cls");

                                    switch(raspuns1)
                                    {

                                        case 1:
                                        {
                                            grupaprincipala.cautare_student(nume).adaugare_nota(0);

                                            cout<<"--------  Nota s-a adaugat cu SUCCES! -------"<<endl;
                                            cout<<endl;
                                            cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                         //   cin.get();
                                            cin.ignore();
                                            system("cls");
                                            meniu();

                                        }

                                        case 2:
                                            {
                                                grupaprincipala.cautare_student(nume).adaugare_nota(1);

                                            cout<<"--------  Nota s-a adaugat cu SUCCES! -------"<<endl;
                                            cout<<endl;
                                            cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                          //  cin.get();
                                            cin.ignore();
                                            system("cls");
                                            meniu();
                                            }

                                        case 3:
                                            {
                                                grupaprincipala.cautare_student(nume).adaugare_nota(2);

                                            cout<<"--------  Nota s-a adaugat cu SUCCES! -------"<<endl;
                                            cout<<endl;
                                            cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                         //   cin.get();
                                            cin.ignore();
                                            system("cls");
                                            meniu();
                                            }

                                        case 4:
                                            {
                                                grupaprincipala.cautare_student(nume).adaugare_nota(3);

                                            cout<<"--------  Nota s-a adaugat cu SUCCES! -------"<<endl;
                                            cout<<endl;
                                            cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                           // cin.get();
                                            cin.ignore();
                                            system("cls");
                                            meniu();
                                            }

                                        case 5:
                                            {
                                                grupaprincipala.cautare_student(nume).adaugare_nota(4);

                                            cout<<"--------  Nota s-a adaugat cu SUCCES! -------"<<endl;
                                            cout<<endl;
                                            cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                         //   cin.get();
                                            cin.ignore();
                                            system("cls");
                                            meniu();
                                            }

                                        case 6:
                                            {
                                                grupaprincipala.cautare_student(nume).adaugare_nota(5);

                                            cout<<"--------  Nota s-a adaugat cu SUCCES! -------"<<endl;
                                            cout<<endl;
                                            cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                          //  cin.get();
                                            cin.ignore();
                                            system("cls");
                                            meniu();
                                            }

                                        case 7:
                                            {
                                                grupaprincipala.cautare_student(nume).adaugare_nota(6);

                                            cout<<"--------  Nota s-a adaugat cu SUCCES! -------"<<endl;
                                            cout<<endl;
                                            cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                           // cin.get();
                                            cin.ignore();
                                            system("cls");
                                            meniu();
                                            }

                                        case 8:
                                        {

                                            system("cls");
                                            meniu();

                                        }

                                        default:
                                            {

                                cout<<"NU ati ales o optiune valabila!"<<endl;
                                cout<<" Va rugam reincercati!"<<endl;

                                                                    cout<<endl;
                                                                    cout<<endl;

                                                                    cout<<endl;
                                                                    cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                                                    cin.get();
                                                                    cin.ignore();
                                                                    system("cls");
                                                                    meniu();
                                            }


                                    }


                   } /// sfarsit if mare

            else{

                                cout<<"Nu s-a gasit acest nume!"<<endl;
                                cout<<"Verificati numele introdus si incercati din nou!"<<endl;
                               // cin.get();
                                cin.ignore();
                                system("cls");
                                meniu();

            }

    }

                case 4:
                {




                    cout<<"Introduceti numele studentului caruia doriti sa ii stergeti o nota, EXACT cum a fost introdus la inceput"<<endl;
                    cin.get();
                    char aux[200];
                    cin.getline(aux, 200, '\n');
                    string nume=aux;
                    cout<<endl;
                    if (grupaprincipala.cautare_student_verificare(nume)==1)
                   {

                                    cout<<endl;
                                    cout<<"La ce materie doriti sa stergeti o nota? Scrieti DOAR numarul optiunii!"<<endl;
                                    cout<<endl;
                                    cout<<"------Submeniu------"<<endl;
                                    cout<<"1) POO"<<endl;
                                    cout<<"2) Structuri de Date"<<endl;
                                    cout<<"3) Tehnici Web"<<endl;
                                    cout<<"4) LFA"<<endl;
                                    cout<<"5) Baze de Date"<<endl;
                                    cout<<"6) Engleza"<<endl;
                                    cout<<"7) Sport"<<endl;
                                    cout<<endl;
                                    cout<<"8) Meniu"<<endl;
                                    cout<<endl;

                                    int raspuns1;
                                    cin>>raspuns1;
                                    system("cls");

                                    switch(raspuns1)
                                    {

                                        case 1:
                                        {
                                            if (grupaprincipala.cautare_student(nume).stergere_nota(0)==1 )
                                                   {
                                                    cout<<"--------  Nota s-a sters cu SUCCES! -------"<<endl;
                                                    cout<<endl;
                                                   }
                                            else
                                            {
                                                cout<<"-------- Nota NU S-A GASIT! Verificati nota si data acesteia si reincercati! -------"<<endl;
                                                cout<<endl;
                                            }


                                            cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                            cin.get();
                                            cin.ignore();
                                            system("cls");
                                            meniu();

                                        }

                                        case 2:
                                            {
                                                if (grupaprincipala.cautare_student(nume).stergere_nota(1)==1 )
                                                   {
                                                    cout<<"-------- Nota s-a sters cu SUCCES! -------"<<endl;
                                                    cout<<endl;
                                                   }
                                            else
                                            {
                                                cout<<"-------- Nota NU S-A GASIT! Verificati nota si data acesteia si reincercati! -------"<<endl;
                                                cout<<endl;
                                            }


                                            cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                            cin.get();
                                            cin.ignore();
                                            system("cls");
                                            meniu();
                                            }

                                        case 3:
                                            {
                                                if (grupaprincipala.cautare_student(nume).stergere_nota(2)==1 )
                                                   {
                                                    cout<<"-------- Nota s-a sters cu SUCCES! -------"<<endl;
                                                    cout<<endl;
                                                   }
                                            else
                                            {
                                                cout<<"-------- Nota NU S-A GASIT! Verificati nota si data acesteia si reincercati! -------"<<endl;
                                                cout<<endl;
                                            }


                                            cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                            cin.get();
                                            cin.ignore();
                                            system("cls");
                                            meniu();
                                            }

                                        case 4:
                                            {
                                                if (grupaprincipala.cautare_student(nume).stergere_nota(3)==1 )
                                                   {
                                                    cout<<"-------- Nota s-a sters cu SUCCES! -------"<<endl;
                                                    cout<<endl;
                                                   }
                                            else
                                            {
                                                cout<<"-------- Nota NU S-A GASIT! Verificati nota si data acesteia si reincercati! -------"<<endl;
                                                cout<<endl;
                                            }


                                            cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                            cin.get();
                                            cin.ignore();
                                            system("cls");
                                            meniu();
                                            }

                                        case 5:
                                            {
                                                if (grupaprincipala.cautare_student(nume).stergere_nota(4)==1 )
                                                   {
                                                    cout<<"-------- Nota s-a sters cu SUCCES! -------"<<endl;
                                                    cout<<endl;
                                                   }
                                            else
                                            {
                                                cout<<"-------- Nota NU S-A GASIT! Verificati nota si data acesteia si reincercati! -------"<<endl;
                                                cout<<endl;
                                            }


                                            cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                            cin.get();
                                            cin.ignore();
                                            system("cls");
                                            meniu();
                                            }

                                        case 6:
                                            {
                                                if (grupaprincipala.cautare_student(nume).stergere_nota(5)==1 )
                                                   {
                                                    cout<<"-------- Nota s-a sters cu SUCCES! -------"<<endl;
                                                    cout<<endl;
                                                   }
                                            else
                                            {
                                                cout<<"-------- Nota NU S-A GASIT! Verificati nota si data acesteia si reincercati! -------"<<endl;
                                                cout<<endl;
                                            }


                                            cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                            cin.get();
                                            cin.ignore();
                                            system("cls");
                                            meniu();
                                            }

                                        case 7:
                                            {
                                                if (grupaprincipala.cautare_student(nume).stergere_nota(6)==1 )
                                                   {
                                                    cout<<"-------- Nota s-a sters cu SUCCES! -------"<<endl;
                                                    cout<<endl;
                                                   }
                                            else
                                            {
                                                cout<<"-------- Nota NU S-A GASIT! Verificati nota si data acesteia si reincercati! -------"<<endl;
                                                cout<<endl;
                                            }


                                            cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                            cin.get();
                                            cin.ignore();
                                            system("cls");
                                            meniu();
                                            }

                                        case 8:
                                        {

                                            system("cls");
                                            meniu();

                                        }



                                                default:
                                            {

                                                                    cout<<"NU ati ales o optiune valabila!"<<endl;
                                                                    cout<<" Va rugam reincercati!"<<endl;

                                                                    cout<<endl;
                                                                    cout<<endl;

                                                                    cout<<endl;
                                                                    cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                                                    cin.get();
                                                                    cin.ignore();
                                                                    system("cls");
                                                                    meniu();
                                            }



                                            }


}
else{

                                cout<<"Nu s-a gasit acest nume!"<<endl;
                                cout<<"Verificati numele introdus si incercati din nou!"<<endl;
                               // cin.get();
                                cin.ignore();
                                system("cls");
                                meniu();

            }

}  /// sfarsit switch case 4






                case 5:
                    {


                        cout<<"Introduceti numele studentului caruia doriti sa ii adaugati o ABSENTA, EXACT cum a fost introdus la inceput"<<endl;
                    cin.get();
                    char aux[200];
                    cin.getline(aux, 200, '\n');
                    string nume=aux;
                    cout<<endl;
                    if (grupaprincipala.cautare_student_verificare(nume)==1)
                   {

                                    cout<<endl;
                                    cout<<"La ce materie doriti sa adaugati o ABSENTA? Scrieti DOAR numarul optiunii!"<<endl;
                                    cout<<endl;
                                    cout<<"------Submeniu------"<<endl;
                                    cout<<"1) POO"<<endl;
                                    cout<<"2) Structuri de Date"<<endl;
                                    cout<<"3) Tehnici Web"<<endl;
                                    cout<<"4) LFA"<<endl;
                                    cout<<"5) Baze de Date"<<endl;
                                    cout<<"6) Engleza"<<endl;
                                    cout<<"7) Sport"<<endl;
                                    cout<<endl;
                                    cout<<"8) Meniu"<<endl;
                                    cout<<endl;

                                    int raspuns1;
                                    cin>>raspuns1;
                                    system("cls");

                                    switch(raspuns1)
                                    {

                                        case 1:
                                        {
                                            grupaprincipala.cautare_student(nume).adaugare_absenta(0);

                                            cout<<"--------  Absenta s-a adaugat cu SUCCES! -------"<<endl;
                                            cout<<endl;
                                            cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                            cin.get();
                                            cin.ignore();
                                            system("cls");
                                            meniu();

                                        }

                                        case 2:
                                            {
                                                grupaprincipala.cautare_student(nume).adaugare_absenta(1);

                                            cout<<"--------  Absenta s-a adaugat cu SUCCES! -------"<<endl;
                                            cout<<endl;
                                            cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                            cin.get();
                                            cin.ignore();
                                            system("cls");
                                            meniu();
                                            }

                                        case 3:
                                            {
                                                grupaprincipala.cautare_student(nume).adaugare_absenta(2);

                                            cout<<"--------  Absenta s-a adaugat cu SUCCES! -------"<<endl;
                                            cout<<endl;
                                            cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                            cin.get();
                                            cin.ignore();
                                            system("cls");
                                            meniu();
                                            }

                                        case 4:
                                            {
                                                grupaprincipala.cautare_student(nume).adaugare_absenta(3);

                                            cout<<"--------  Absenta s-a adaugat cu SUCCES! -------"<<endl;
                                            cout<<endl;
                                            cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                            cin.get();
                                            cin.ignore();
                                            system("cls");
                                            meniu();
                                            }

                                        case 5:
                                            {
                                                grupaprincipala.cautare_student(nume).adaugare_absenta(4);

                                            cout<<"--------  Absenta s-a adaugat cu SUCCES! -------"<<endl;
                                            cout<<endl;
                                            cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                            cin.get();
                                            cin.ignore();
                                            system("cls");
                                            meniu();
                                            }

                                        case 6:
                                            {
                                                grupaprincipala.cautare_student(nume).adaugare_absenta(5);

                                            cout<<"--------  Absenta s-a adaugat cu SUCCES! -------"<<endl;
                                            cout<<endl;
                                            cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                            cin.get();
                                            cin.ignore();
                                            system("cls");
                                            meniu();
                                            }

                                        case 7:
                                            {
                                                grupaprincipala.cautare_student(nume).adaugare_absenta(6);

                                            cout<<"--------  Absenta s-a adaugat cu SUCCES! -------"<<endl;
                                            cout<<endl;
                                            cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                            cin.get();
                                            cin.ignore();
                                            system("cls");
                                            meniu();
                                            }

                                        case 8:
                                        {

                                            system("cls");
                                            meniu();

                                        }

                                        default:
                                            {

                                cout<<"NU ati ales o optiune valabila!"<<endl;
                                cout<<" Va rugam reincercati!"<<endl;

                                                                    cout<<endl;
                                                                    cout<<endl;

                                                                    cout<<endl;
                                                                    cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                                                    cin.get();
                                                                    cin.ignore();
                                                                    system("cls");
                                                                    meniu();
                                            }


                                    }


                   } /// sfarsit if mare

            else{

                                cout<<"Nu s-a gasit acest nume!"<<endl;
                                cout<<"Verificati numele introdus si incercati din nou!"<<endl;
                                cin.get();
                                cin.ignore();
                                system("cls");
                                meniu();

            }




                    }   /// sfarsit case 5




                case 6:
                 {

                    cout<<"Introduceti numele studentului caruia doriti sa ii stergeti o ABSENTA, EXACT cum a fost introdus la inceput"<<endl;
                    cin.get();
                    char aux[200];
                    cin.getline(aux, 200, '\n');
                    string nume=aux;
                    cout<<endl;
                    if (grupaprincipala.cautare_student_verificare(nume)==1)
                   {

                                    cout<<endl;
                                    cout<<"La ce materie doriti sa stergeti o ABSENTA? Scrieti DOAR numarul optiunii!"<<endl;
                                    cout<<endl;
                                    cout<<"------Submeniu------"<<endl;
                                    cout<<"1) POO"<<endl;
                                    cout<<"2) Structuri de Date"<<endl;
                                    cout<<"3) Tehnici Web"<<endl;
                                    cout<<"4) LFA"<<endl;
                                    cout<<"5) Baze de Date"<<endl;
                                    cout<<"6) Engleza"<<endl;
                                    cout<<"7) Sport"<<endl;
                                    cout<<endl;
                                    cout<<"8) Meniu"<<endl;
                                    cout<<endl;

                                    int raspuns1;
                                    cin>>raspuns1;
                                    system("cls");

                                    switch(raspuns1)
                                    {

                                        case 1:
                                        {
                                            if (grupaprincipala.cautare_student(nume).stergere_absenta(0)==1 )
                                                   {
                                                    cout<<"-------- Absenta s-a sters cu SUCCES! -------"<<endl;
                                                    cout<<endl;
                                                   }
                                            else
                                            {
                                                cout<<"-------- Absenta NU S-A GASIT! Verificati data acesteia si reincercati! -------"<<endl;
                                                cout<<endl;
                                            }


                                            cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                            cin.get();
                                            cin.ignore();
                                            system("cls");
                                            meniu();

                                        }

                                        case 2:
                                            {
                                                if (grupaprincipala.cautare_student(nume).stergere_absenta(1)==1 )
                                                   {
                                                    cout<<"-------- Absenta s-a sters cu SUCCES! -------"<<endl;
                                                    cout<<endl;
                                                   }
                                            else
                                            {
                                                cout<<"-------- Absenta NU S-A GASIT! Verificati data acesteia si reincercati! -------"<<endl;
                                                cout<<endl;
                                            }


                                            cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                            cin.get();
                                            cin.ignore();
                                            system("cls");
                                            meniu();
                                            }

                                        case 3:
                                            {
                                                if (grupaprincipala.cautare_student(nume).stergere_absenta(2)==1 )
                                                   {
                                                    cout<<"-------- Absenta s-a sters cu SUCCES! -------"<<endl;
                                                    cout<<endl;
                                                   }
                                            else
                                            {
                                                cout<<"-------- Absenta NU S-A GASIT! Verificati data acesteia si reincercati! -------"<<endl;
                                                cout<<endl;
                                            }


                                            cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                            cin.get();
                                            cin.ignore();
                                            system("cls");
                                            meniu();
                                            }

                                        case 4:
                                            {
                                                if (grupaprincipala.cautare_student(nume).stergere_absenta(3)==1 )
                                                   {
                                                    cout<<"-------- Absenta s-a sters cu SUCCES! -------"<<endl;
                                                    cout<<endl;
                                                   }
                                            else
                                            {
                                                cout<<"-------- Absenta NU S-A GASIT! Verificati data acesteia si reincercati! -------"<<endl;
                                                cout<<endl;
                                            }


                                            cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                            cin.get();
                                            cin.ignore();
                                            system("cls");
                                            meniu();
                                            }

                                        case 5:
                                            {
                                                if (grupaprincipala.cautare_student(nume).stergere_absenta(4)==1 )
                                                   {
                                                    cout<<"-------- Absenta s-a sters cu SUCCES! -------"<<endl;
                                                    cout<<endl;
                                                   }
                                            else
                                            {
                                                cout<<"-------- Absenta NU S-A GASIT! Verificati data acesteia si reincercati! -------"<<endl;
                                                cout<<endl;
                                            }


                                            cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                            cin.get();
                                            cin.ignore();
                                            system("cls");
                                            meniu();
                                            }

                                        case 6:
                                            {
                                                if (grupaprincipala.cautare_student(nume).stergere_absenta(5)==1 )
                                                   {
                                                    cout<<"-------- Absenta s-a sters cu SUCCES! -------"<<endl;
                                                    cout<<endl;
                                                   }
                                            else
                                            {
                                                cout<<"-------- Absenta NU S-A GASIT! Verificati data acesteia si reincercati! -------"<<endl;
                                                cout<<endl;
                                            }


                                            cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                            cin.get();
                                            cin.ignore();
                                            system("cls");
                                            meniu();
                                            }

                                        case 7:
                                            {
                                                if (grupaprincipala.cautare_student(nume).stergere_absenta(6)==1 )
                                                   {
                                                    cout<<"-------- Absenta s-a sters cu SUCCES! -------"<<endl;
                                                    cout<<endl;
                                                   }
                                            else
                                            {
                                                cout<<"-------- Absenta NU S-A GASIT! Verificati data acesteia si reincercati! -------"<<endl;
                                                cout<<endl;
                                            }


                                            cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                            cin.get();
                                            cin.ignore();
                                            system("cls");
                                            meniu();
                                            }

                                        case 8:
                                        {

                                            system("cls");
                                            meniu();

                                        }



                                                default:
                                            {

                                                                    cout<<"NU ati ales o optiune valabila!"<<endl;
                                                                    cout<<" Va rugam reincercati!"<<endl;

                                                                    cout<<endl;
                                                                    cout<<endl;

                                                                    cout<<endl;
                                                                    cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                                                    cin.get();
                                                                    cin.ignore();
                                                                    system("cls");
                                                                    meniu();
                                            }



                                            }


}
        else{

                                cout<<"Nu s-a gasit acest nume!"<<endl;
                                cout<<"Verificati numele introdus si incercati din nou!"<<endl;
                               // cin.get();
                                cin.ignore();
                                system("cls");
                                meniu();

            }


                  }  /// sfarsit case 6




                case 7:
              {

                    cout<<"Introduceti numele studentului caruia doriti sa ii stergeti o ABSENTA, EXACT cum a fost introdus la inceput"<<endl;
                    cin.get();
                    char aux[200];
                    cin.getline(aux, 200, '\n');
                    string nume=aux;
                    cout<<endl;
                    system("cls");
                    if (grupaprincipala.cautare_student_verificare(nume)==1)
                   {


                       if (grupaprincipala.cautare_student(nume).nr_restante()!=0)
                       {
                           cout<<"Studentul "<<nume<<" are "<<grupaprincipala.cautare_student(nume).nr_restante()<<" RESTANTE la urmatoarele materii:";
                           cout<<endl;
                           cout<<endl;
                           for (int j=0;j<7;j++)
                           {
                               if (j==0 and grupaprincipala.cautare_student(nume).getter_materii()[j].get_restanta()==true)
                               {
                                    cout<<"- POO"<<endl;
                               }

                                if (j==1 and grupaprincipala.cautare_student(nume).getter_materii()[j].get_restanta()==true)
                               {
                                    cout<<"- Structuri de Date"<<endl;
                               }

                               if (j==2 and grupaprincipala.cautare_student(nume).getter_materii()[j].get_restanta()==true)
                               {
                                    cout<<"- Tehnici Web"<<endl;
                               }

                               if (j==3 and grupaprincipala.cautare_student(nume).getter_materii()[j].get_restanta()==true)
                               {
                                    cout<<"- LFA"<<endl;
                               }

                               if (j==4 and grupaprincipala.cautare_student(nume).getter_materii()[j].get_restanta()==true)
                               {
                                    cout<<"- Baze de Date"<<endl;
                               }

                                if (j==5 and grupaprincipala.cautare_student(nume).getter_materii()[j].get_restanta()==true)
                               {
                                    cout<<"- Engleza"<<endl;
                               }

                               if (j==6 and grupaprincipala.cautare_student(nume).getter_materii()[j].get_restanta()==true)
                               {
                                    cout<<"- Sport"<<endl;
                               }

                           }

                       cout<<endl;
                       cout<<endl;
                       cout<<endl;
                        cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                        //cin.get();
                        cin.ignore();
                        system("cls");
                       meniu();


                       }  ///sfarsit if cu verif nr.restante
                       else
                       {
                           cout<<endl;
                           cout<<"Studentul "<<nume<<" nu are NICIO restanta!"<<endl;


                        cout<<endl;
                       cout<<endl;
                       cout<<endl;
                        cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                        //cin.get();
                        cin.ignore();
                        system("cls");
                         meniu();
                       }

                   }
                   else{

                                cout<<"Nu s-a gasit acest nume!"<<endl;
                                cout<<"Verificati numele introdus si incercati din nou!"<<endl;
                               // cin.get();
                                cin.ignore();
                                system("cls");
                                meniu();

                        }



             }  /// sfarsit case 7


                case 8:
                    {
                        cout<<endl;

                        cout<<"   --- Numarul de restante per toata grupa este "<<grupaprincipala.nr_restante_grupa()<<endl;
                        cout<<endl;

                        cout<<endl;
                        cout<<endl;
                        cout<<endl;
                        cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                        cin.get();
                        cin.ignore();
                        system("cls");
                        meniu();
                    }


                case 9:
                    {
                        system("cls");
                        first_read();
                    }


                case 10:
                    {
                        system("cls");
                        exit(0);
                    }

                default:
                    {
                                                                    cout<<"NU ati ales o optiune valabila!"<<endl;
                                                                    cout<<" Va rugam reincercati!"<<endl;

                                                                    cout<<endl;
                                                                    cout<<endl;

                                                                    cout<<endl;
                                                                    cout<<"------ Apasati tasta ENTER pentru a continua -------"<<endl;
                                                                    cin.get();
                                                                    cin.ignore();
                                                                    system("cls");
                                                                    meniu();
                    }
}


}




void first_read()
{

    cout<<"--------- Introduceti datele despre grupa!----------"<<endl;
    cout<<endl;
    cout<<endl;

    int nr=0;
    int nrgrupa;
    cout<<"Numarul studentilor este: ";
    cin>>nr;
    cout<<endl;
    cout<<"Numarul grupei este: ";
    cin>>nrgrupa;
    cout<<endl;
    grupa ob(nr,nrgrupa);

    cin>>ob;



    ob.setare_mass_medie_studenti();
    ob.setare_medie_grupa();


    grupaprincipala=ob;

    cout<<endl;
    cout<<endl;
    cout<<"Ati citit toata grupa!"<<endl;
    cout<<"Ecranul se va goli dupa apasarea tastei ENTER"<<endl;

    cin.ignore();
    system("cls");

    meniu();

}



int main()
{
    int ok=1;


    cout<<"                   ------------ DISCLAIMER --------------"<<endl;
    cout<<endl;
    cout<<"Se recomanda largirea terminalului pentru a intra un rand complet pe latimea acestuia!"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<" Aceasta aplicatie simuleaza un catalog online construit pe planul unui grupe studentesti cu un numar dat de studenti!"<<endl;
    cout<<endl;
    cout<<"-------Aplicatia are aplicabilitate in cadrul secretariatului in activitati precum alocarea locurilor la caminele UNIBUC ------"<<endl;
    cout<<endl;
    cout<<" Materiile acestui catalog sunt materiile corespunzatoare anului I, semestrul II de la profilul Informatica din FMI Bucuresti." <<endl;
    cout<<endl;
    cout<<endl;
    cout<<"    Precizari despre folosirea aplicatiei:"<<endl;
    cout<<"- Daca un student este RESTANT, NU i se vor mai afisa notele"<<endl;
    cout<<"- Notele, respectiv absentele trebuiesc adaugate una cate una, pe fiecare trebuind introdus separat pe sesiune"<<endl;
    cout<<"- Acelasi aspect se foloseste si la stergerea lor"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"-------Rugam citirea cu atentie a instructiunilor date pe ecran!----------"<<endl;

    cout<<endl;
    cout<<endl;
    cout<<"Daca ati citit acest mesaj, puteti trece mai departe!"<<endl;
    cout<<"Pentru acest lucru, apasati tasta ENTER!"<<endl;
   // cin.get();
    cin.ignore();
    system("cls");





  HANDLE console_color;
console_color = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(console_color, 10);

    first_read();


    return 0;
}
