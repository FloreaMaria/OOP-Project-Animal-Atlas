#include "Mamifere.h"

Mamifere :: Mamifere() : Vertebrate(), alimentatie("Unknown"){
    ReduceO2();
}

Mamifere :: Mamifere(std :: string casa, std :: string repr, std :: string alimentatie) :  Vertebrate(casa, repr), alimentatie(alimentatie){
    ReduceO2();
}

Mamifere :: Mamifere(const Mamifere& M) : Vertebrate(M), alimentatie(M.alimentatie){
    ///
}

void Mamifere :: Display(){

    Vertebrate :: Display();
    std :: cout << "Alimentatie : " << getAlimentatie() << "\n";
}

Mamifere& Mamifere :: operator = (const Mamifere& M){

    if( this != &M)
    {
        this -> Animale :: operator = (M);
        this -> Vertebrate :: operator = (M);
        this -> alimentatie = M.alimentatie;
    }
    return *this;
}

std :: istream& operator >> (std :: istream& f, Mamifere& M){

    std :: string H, R, alimentatie;
    std :: cout << "Specificatii mamifer : \n";
    std :: cout << "Mediu : ";
    f >> H;
    std :: cout << "Reproducere : ";
    f >> R;
    std :: cout << "Tip de alimentatie(omnivor, carnivor, ierbivor) : ";
    f >> alimentatie;
    M.setHome(H);
    M.setRepr(R);
    M.setAlimentatie(alimentatie);
    return f;
}
std :: ostream& operator << (std :: ostream& c, Mamifere & M){

     c << "Specificatii :  \n" ;
     M.Display();
     return c;
}
