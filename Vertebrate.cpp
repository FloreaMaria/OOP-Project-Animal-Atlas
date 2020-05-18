#include "Vertebrate.h"

Vertebrate :: Vertebrate() : Animale(){
    //ctor
}

Vertebrate :: Vertebrate(std :: string casa, std :: string Repr) : Animale(casa, Repr){
    ///
}

Vertebrate :: Vertebrate(const Vertebrate & V) : Animale(V){
    ///
}


void Vertebrate :: Display(){

    std :: cout << "Mediu : " <<  getHome() << "\n" << "Reproducere : " << getRepr() <<"\n";
}


Vertebrate& Vertebrate :: operator = (const Vertebrate& V){

    if(this != &V)
        this -> Animale :: operator = (V);
    return *this;

}

std :: istream& operator >> (std :: istream&f, Vertebrate& V){

    std :: string casa, repr;
    std :: cout << "Specificatii vertebrata : \n";
    std :: cout << "Mediu : ";
    f >> casa;
    std :: cout << "Reproducere : ";
    f >> repr ;
    V.setHome(casa);
    V.setRepr(repr);
    //V.setVertebra(v);
    return f;
}

std :: ostream& operator << (std :: ostream& c, Vertebrate & V){

        c << "Specificatii : \n";
        V.Display();
        return c;

}
