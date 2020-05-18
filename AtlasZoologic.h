
#include "Animale.h"
#include <iostream>
#include <string>
#include <vector>
#include <typeinfo>
#include "Vertebrate.h"
#include "Nevertebrate.h"
#include "Pesti.h"
#include "Pasari.h"
#include "Reptile.h"
#include "Mamifere.h"
#include "Exceptie.h"
#include <typeinfo>
#pragma once

using namespace std;

template<class T> class AtlasZoologic;
template<class T> ostream& operator <<(ostream&,AtlasZoologic<T>&);
template<class T> istream& operator >>(istream&,AtlasZoologic<T>&);


template <typename T>
class AtlasZoologic
{
    int nr_animale;
    vector <T*> Animal;

public:

    AtlasZoologic() : nr_animale(0)
    {
        ///
    }

    AtlasZoologic(int nr, vector <T*> R) : nr_animale(nr), Animal(R)
    {
        ///
    }

    AtlasZoologic(const AtlasZoologic& R) : nr_animale(R.nr_animale), Animal(R.Animal)
    {
        ///
    }

    virtual ~AtlasZoologic()
    {
        for(auto el : Animal)
            delete el;
        Animal.clear();
    };

    int get_nr() const
    {
        return nr_animale;
    }

    void set_nr(int n)
    {
        this -> nr_animale = n;
    }

    void setVector( vector <T*> L)
    {
        this -> Animal = L;
    }

    vector <T*> getVector() const
    {
        return this -> Animal;
    }

    AtlasZoologic<T>& operator += (T *A)
    {
            nr_animale ++;
            Animal.push_back(A);
        return *this;
    }

    AtlasZoologic <T>& operator = (const AtlasZoologic& Z)
    {
        if(this != &Z)
        {
            this -> nr_animale = Z.nr_animale;
            this -> Animal = Z.Animal;
        }
        return *this;
    }
    void Display()
    {
        cout << "\nNumarul de animale : " << get_nr() << "\n";
        vector < T*> V = getVector();

        for(auto it : V)
        {
            if(typeid(*it) == typeid(Nevertebrate))
                cout << "Fisa obervatie -> Nevertebrata : \n";
            if(typeid(*it) == typeid(Vertebrate))
                cout << "Fisa observatie -> Vertebrata : \n";
            if(typeid(*it) == typeid(Pesti))
                cout << "Fisa observatie -> Peste : \n";
            if(typeid(*it) == typeid(Pasari))
                cout << "Fisa observatie -> Pasare : \n";
            if(typeid(*it) == typeid(Reptile))
                cout << "Fisa observatie -> Reptila : \n";
            if(typeid(*it) == typeid(Mamifere))
                cout << "Fisa observatie -> Mamifer : \n";
            it -> Display();
        }

    }


    friend istream& operator >> <>(istream&f, AtlasZoologic <T> &);
    friend  ostream& operator<< <>(ostream& c, AtlasZoologic <T> & );

};
template <class T>

istream& operator >> (istream & f, AtlasZoologic <T> &A)
{
    int nr_animale, p, r, nounr;
    cout << "Numar animale : ";
    f >> nr_animale;
    nounr = nr_animale;
    try
    {
        if(nr_animale <= 0)
            throw Exceptie();
    }
    catch (exception &e)
    {
        cout << e.what();

    }

    vector <T*> V;

    while(nr_animale > 0)
    {
        cout << "Alege un tip de animal(0 - Nevertebrat, 1 - Vertebrat) : ";

        f >> p;
        if(p == 0)
        {
            Nevertebrate * N = new Nevertebrate;
            f >> *N;
            V.push_back(N);
            nr_animale --;
        }
        if(p == 1)
        {

            cout <<  "Alege o vertebrata (1 - Pasare, 2 - Peste, 3 - Reptila, 4 - Mamifer) : \n";
            f >> r;
            switch (r)
            {
            case 1:
            {

                Pasari * P = new Pasari;
                f >> *P;
                V.push_back(P);
                nr_animale --;
                break;
            }
            case 2 :
            {
                Pesti * p = new Pesti();
                f >> (*p);
                V.push_back(p);
                nr_animale--;
                break;
            }
            case 3 :
            {
                Reptile *r = new Reptile();
                f >> (*r);
                V.push_back(r);
                nr_animale -- ;
                break;
            }
            case 4 :
            {
                Mamifere *m  = new Mamifere();
                f >> (*m);
                V.push_back(m);
                nr_animale--;
                break;
            }

            default:
            {
                try
                {
                    throw Exceptie();
                }
                catch(exception & e)
                {
                    cout << e.what();
                }
                break;
            }
            }
        }
    }

    A.set_nr(nounr - nr_animale);
    A.setVector(V);
    return f;
}


template <class T>
ostream& operator << ( ostream & c, AtlasZoologic <T> &A)
{
    c << "\nNumarul de animale : " << A.get_nr() << "\n";
    vector < T*> V = A.getVector();

    for(auto it : V)
    {
        if(typeid(*it) == typeid(Nevertebrate))
            cout << "Fisa obervatie -> Nevertebrata : \n";
        if(typeid(*it) == typeid(Vertebrate))
            cout << "Fisa observatie -> Vertebrata : \n";
        if(typeid(*it) == typeid(Pesti))
            cout << "Fisa observatie -> Peste : \n";
        if(typeid(*it) == typeid(Pasari))
            cout << "Fisa observatie -> Pasare : \n";
        if(typeid(*it) == typeid(Reptile))
            cout << "Fisa observatie -> Reptila : \n";
        if(typeid(*it) == typeid(Mamifere))
            cout << "Fisa observatie -> Mamifer : \n";
        it -> Display();
    }
    return c;
}





template <>
class AtlasZoologic<Pesti>
{
    int nrPestiRapitori, nrPestiBuni;
    vector <Pesti*> V;
public :

    AtlasZoologic() : nrPestiRapitori(0), nrPestiBuni(0)
    {
        ///
    };

    AtlasZoologic(int nrP, int nrR) : nrPestiRapitori(nrR), nrPestiBuni(nrP)
    {
        ///
    }

    AtlasZoologic (const AtlasZoologic & A)
    {
        if(this != &A)
        {
            this -> nrPestiBuni = A.nrPestiBuni;
            this -> nrPestiRapitori = A.nrPestiRapitori;
            for(unsigned int i = 0; i < A.V.size(); i++)
                V.push_back(A.V[i]);
        }
    }

    int getPestiR()const
    {
        return this -> nrPestiRapitori;
    }

    int getPestiBuni()const
    {

        return this -> nrPestiBuni;
    }

    void setPestiR(int nou)
    {
        this -> nrPestiRapitori = nou;
    }
    void setPestiBuni(int nou)
    {
        this -> nrPestiBuni = nou;
    }

    vector <Pesti*> getV()
    {
        return this -> V;
    }

    void setV(vector <Pesti*> Nou)
    {
        this -> V = Nou;
    }


    AtlasZoologic <Pesti> & operator += (Pesti * P)
    {
        cout << "Adaugare peste nou \n";
        V.push_back(P);
        if(P -> getRapitor())
        {
            if(P -> getDim() >= 100)
                nrPestiBuni ++;
        }
        return *this;
    };

    AtlasZoologic<Pesti> & operator = (AtlasZoologic <Pesti> & P)
    {
        nrPestiRapitori = P.nrPestiRapitori;
        nrPestiBuni = P.nrPestiBuni;
        for(unsigned int i = 0; i < P.V.size(); i++)
            V.push_back(P.V[i]);
        return *this;

    };
    void AfisareRapitoriMari()
    {
        cout << "Numarul pestilor rapitori cu lungimea mai mare de 100 : ";
        cout << nrPestiBuni << "\n";
    }

    friend istream& operator >> (istream& f, AtlasZoologic <Pesti> & P)
    {
        int nr;
        cout << "Introduceti nr de pesti : \n";
        f >> nr;
        cout << "Introduceti fisele de observatie pentru " << nr << " pesti\n";
        for(int i = 0; i < nr; i++)
        {
            Pesti * T = new Pesti;
            cin >> *T;
            P.V.push_back(T);
            if(T -> getRapitor())
            {
                P.nrPestiRapitori ++;
                if(T -> getDim() >= 100)
                    P.nrPestiBuni ++;
            }

        }
        return f;
    }

    friend  ostream& operator << (ostream& c, AtlasZoologic <Pesti>& P)
    {
        c << "Atlas Pesti : ";
        if(P.V.size() == 0)
            c << "gol\n";
        else
        {
            c << "\n";
            for(unsigned int i = 0; i < P.V.size(); i ++)
            {
                c <<"Pagina nr " <<  i + 1 << ": \n";
                P.V[i] -> Display();
            }
        }
        return c;

    }

    ~AtlasZoologic()
    {
        for(auto i : V)
            delete i;
        V.clear();
    }


};





