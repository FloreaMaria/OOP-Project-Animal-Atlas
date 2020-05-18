#include "Vertebrate.h"
#include <iostream>
#include <string>
#include <exception>
#pragma once

class Pasari : public Vertebrate
{
    int dimensiune_aripi;
    double viteza_zbor;

    public:

        Pasari();
        Pasari(std :: string casa, std :: string repr, int dimensiune_aripi, double viteza_zbor);
        Pasari(const Pasari&);
        virtual ~Pasari() = default;
        void Display();

        int getDimensiune() const{
            return this -> dimensiune_aripi;
        }

        void setDimensiune(int noudim){
            this -> dimensiune_aripi = noudim;
        }

        double getViteza() const{
            return this -> viteza_zbor;
        }

        void setViteza(double nouv){
            this -> viteza_zbor = nouv;
        }

        Pasari& operator = (const Pasari&);
        friend std :: istream& operator >> (std :: istream&, Pasari&);
        friend std :: ostream& operator << (std :: ostream&, Pasari&);

};

