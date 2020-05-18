#include "Animale.h"
double Animale :: oxigen = 21;

Animale :: Animale() : home("Earth"), WayOfReproduction("None"){
    ///
}

Animale :: Animale(std ::  string newhome, std :: string newRepr) : home(newhome), WayOfReproduction(newRepr){
    ///
}

Animale ::  Animale(const Animale& A) : home(A.home), WayOfReproduction(A.WayOfReproduction){
    ///
}

Animale& Animale :: operator = (const Animale &A){

    if(this != &A)
        {
            this -> home = A.home;
            this -> WayOfReproduction = A.WayOfReproduction;
        }
    return *this;
}


std :: istream& operator >> (std :: istream& f, Animale& A){

    std :: string H, R;
    f >> H >> R;
    A.setHome(H);
    A.setRepr(R);
    return f;
}


std :: ostream& operator << (std :: ostream& c, const Animale& B){

    c << B.home <<  " " << B.WayOfReproduction << "\n";
    return c;

}

