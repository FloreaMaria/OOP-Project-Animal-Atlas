#include "Pasari.h"
#include "Exceptie.h"

Pasari :: Pasari() : Vertebrate(),  dimensiune_aripi(0), viteza_zbor(0){
    ReduceO2();
}

Pasari :: Pasari(std :: string casa, std :: string repr, int dimensiune_aripi, double viteza_zbor) :  Vertebrate(casa, repr), dimensiune_aripi(dimensiune_aripi), viteza_zbor(viteza_zbor){
    ReduceO2();
}

Pasari :: Pasari(const Pasari& P) :  Vertebrate(P), dimensiune_aripi(P.dimensiune_aripi), viteza_zbor(P.viteza_zbor){
    ///
}

void Pasari :: Display(){

    Vertebrate ::  Display();
    std :: cout << "Dimensiune aripi(cm) : " << getDimensiune() << "\n" << "Viteza zbor(m/s) : " << getViteza() << "\n";
}


Pasari& Pasari :: operator = (const Pasari& P){

    if(this != &P)
    {
        this -> Animale :: operator = (P);
        this -> Vertebrate :: operator = (P);
        this -> dimensiune_aripi = P.dimensiune_aripi;
        this -> viteza_zbor = P.viteza_zbor;
    }
    return *this;
}

std :: istream& operator >> (std :: istream& f, Pasari& P){

    std :: string H, R;
    int dim;
    double speed;


    std :: cout << "Mediu : ";
    f >> H;
    std :: cout << "Reproducere : ";
    f >> R;
    std :: cout << "Dimensiune aripi : ";
    f >> dim;
    std :: cout << "Viteza in zbor : ";
    f >> speed;

    try{
        if(H.size() < 2)
            throw Exceptie();
    }catch(std :: exception & e)
    {
        std :: cout << e.what();
    }


    try{
        if(R.size() < 2)
            throw Exceptie();
    }catch(std :: exception & e)
    {
        std :: cout << e.what();
    }

    try{
        if(dim < 0)
            throw Exceptie();
    }catch(std :: exception & e)
    {
        std :: cout << e.what();
    }

    try{
        if(speed < 0)
            throw Exceptie();
    }catch(std :: exception & e)
    {
        std :: cout << e.what();
    }

    P.setHome(H);
    P.setRepr(R);
    P.setDimensiune(dim);
    P.setViteza(speed);
    return f;
}
std :: ostream& operator << (std :: ostream& c, Pasari & P){

     c << "Specificatii : \n";
     P.Display();
     return c;
}
