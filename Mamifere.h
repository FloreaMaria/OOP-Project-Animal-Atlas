#include "Vertebrate.h"
#include "Animale.h"
#include "iostream"
#include "string"
#pragma once

class Mamifere : public Vertebrate
{
    std :: string alimentatie;

    public:
        Mamifere();
        Mamifere(std :: string home, std :: string repr, std :: string alimentatie);
        Mamifere(const Mamifere&);
        virtual ~Mamifere() = default;
        void Display();

        std :: string getAlimentatie() const{

            return this -> alimentatie;
        }

        void setAlimentatie(std :: string alimentatie_noua){

            this -> alimentatie = alimentatie_noua;
        }

        Mamifere& operator = (const Mamifere&);
        friend std :: istream& operator >> (std :: istream&, Mamifere&);
        friend std :: ostream& operator << (std :: ostream&, Mamifere&);

};

