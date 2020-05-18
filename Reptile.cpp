#include "Reptile.h"

Reptile :: Reptile() : Vertebrate(), veninos("Nu"){

    ReduceO2();
}

Reptile :: Reptile(std :: string casa, std :: string repr, std :: string venin) : Vertebrate(casa, repr), veninos(venin){

    ReduceO2();
}

Reptile :: Reptile(const Reptile& R) : Vertebrate(R), veninos(R.veninos){
    ///
}

void Reptile :: Display(){

    Vertebrate :: Display();
    std :: cout << "Veninos : " << getVenin() << "\n";
}

Reptile& Reptile :: operator = (const Reptile& R){

    if(this != &R)
    {
        this -> Animale :: operator = (R);
        this -> Vertebrate :: operator = (R);
        this -> veninos = R.veninos;
    }
    return *this;
}

std :: istream& operator >> (std :: istream& f, Reptile & R){

    std :: string home, repr;
    double venin;
    std :: cout << "Specificatii reptila : \n";
    std :: cout << "Mediu : ";
    f >> home;
    std :: cout << "Reproducere : ";
    f >> repr;
    std :: cout <<"Inserati 1 pentru veninos, 0 pentru neveninos : ";
    f >> venin;
    if(venin == 1)
        R.setVenin("Da");
    else
        R.setVenin("Nu");

    R.setHome(home);
    R.setRepr(repr);

    return f;
}
std :: ostream& operator << (std :: ostream& c, Reptile& R)
{
    c << "Specificatii : ";
    R.Display();
    return c;
}
