#include "Nevertebrate.h"

Nevertebrate :: Nevertebrate() : Animale()
{
    ReduceO2();
    //ctor
}

Nevertebrate :: Nevertebrate(std :: string casa, std :: string R) : Animale(casa, R)
{
   ReduceO2();
}

Nevertebrate :: Nevertebrate (const Nevertebrate& N) : Animale(N)
{

}

void Nevertebrate :: Display()
{
    std ::  cout << "Mediu : " << getHome() << "\n" << "Reproducere : " << getRepr() << "\n";
}


Nevertebrate & Nevertebrate :: operator = (const Nevertebrate& N)
{
    if(this != &N)
    {
        this -> Animale :: operator = (N);
    }
    return *this;
}


std :: istream& operator >> (std :: istream& f, Nevertebrate& N)
{
    std :: string H, R;
    std :: cout << "Specificatii nevertebrata : \n";
    std :: cout << "Mediu : ";
    f >> H;
    std :: cout << "Reproducere : ";
    f >> R;
    N.setHome(H);
    N.setRepr(R);
    return f;
}

std :: ostream& operator << (std :: ostream& d, Nevertebrate& N)
{
    d << "Specificatii : \n";
    N.Display();
    return d;
}
