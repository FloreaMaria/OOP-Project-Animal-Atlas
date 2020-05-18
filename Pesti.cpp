#include "Pesti.h"
#include <string>

Pesti :: Pesti() : Vertebrate(), tip_inotatoare("basic"), nr_inotatoare(0), dimensiune(0), rapitor(0){

    ReduceO2();
}

Pesti :: Pesti(std :: string casa, std :: string tip_inotatoare, int nr_inotatoare, int dim, bool r) :
    Vertebrate(casa, "eggs"), tip_inotatoare(tip_inotatoare), nr_inotatoare(nr_inotatoare),  dimensiune(dim), rapitor(r){

    ReduceO2();
}

Pesti :: Pesti(const Pesti & P) : Vertebrate(P), tip_inotatoare(P.tip_inotatoare), nr_inotatoare(P.nr_inotatoare),
        dimensiune(P.dimensiune), rapitor(P.rapitor){
    ///
}

void Pesti :: Display(){

    Vertebrate :: Display();
    std :: cout << "Tip inotatoare : " << getInotatoare() << "\n";
    std ::  cout << "Numar inotatoare : " << getnrInotatoare() << "\n" << "Dimensiune : " << getDim() << " cm \n";
    if(getRapitor())
        std :: cout << "Rapitor : DA\n";
    else
        std :: cout << "Rapitor : NU\n";
}

Pesti & Pesti :: operator = (const Pesti & P){

    if( this != &P)
    {
        this -> Animale :: operator = (P);
        this -> Vertebrate :: operator = (P);
        this -> nr_inotatoare = P.nr_inotatoare;
        this -> tip_inotatoare = P.tip_inotatoare;
        this -> rapitor = P.rapitor;
        this -> dimensiune = P.dimensiune;
    }
    return *this;
}


std :: istream& operator >> (std :: istream& f, Pesti& P){

    std :: string home, repr, tip_inotatoare;
    int nr_inotatoare, dimensiune;
    bool R;
    std :: cout << "Specificatii peste : \n";
    std :: cout << "Mediu : ";
    f >> home;
    std :: cout << "Reproducere : ";
    f >> repr;
    std :: cout << "Tip inotatoare : ";
    f >> tip_inotatoare;
    std :: cout << "Numar inotatoare : ";
    f >> nr_inotatoare;
    std :: cout << "Dimensiune(cm) : ";
    f >> dimensiune;
    std :: cout << "Rapitor :(0 - NU, 1 - DA) : ";
    f >> R;

    try{
        if(home.size() < 2)
            throw Exceptie();
    }catch(std :: exception &e){
        std :: cout << e.what() << " of Mediu\n";
    }

    try{
        if(repr.size() < 2)
            throw Exceptie();
    }catch(std :: exception &e){
        std :: cout << e.what() << " of Reproducere\n";
    }

    try{
        if(tip_inotatoare.size() < 2)
            throw Exceptie();
    }catch(std :: exception &e){
        std :: cout << e.what() << " of tip_inotatoare\n" ;
    }

    try{
        if(nr_inotatoare < 2)
            throw Exceptie();
    }catch(std :: exception &e){
        std :: cout << e.what() << " of nr_inotatoare\n";
    }

    try{
        if((R != 0) && (R != 1))
            throw Exceptie();
    }catch(std :: exception &e){
        std :: cout << e.what() << " of Rapitor\n";
    }


    P.setRapitor(R);
    P.setHome(home);
    P.setRepr(repr);
    P.setInotatoare(tip_inotatoare);
    P.setnrInotatoare(nr_inotatoare);
    P.setDim(dimensiune);
    return f;
}

std :: ostream& operator << ( std :: ostream& c, Pesti& P)
{
    c << "Specificatii : \n";
    P.Display();
    return c;
}
