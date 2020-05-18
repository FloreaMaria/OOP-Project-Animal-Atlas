#include "Vertebrate.h"
#include <iostream>
#include <string>
#pragma once

class Reptile : public Vertebrate
{
    std :: string veninos;

    public:

        Reptile();
        Reptile(std :: string casa, std :: string repr, std :: string venin);
        Reptile(const Reptile&);
        virtual ~Reptile() = default;
        void Display();

        std :: string getVenin() const
        {
            return this -> veninos;
        }
        void setVenin(std :: string nouv)
        {
            this -> veninos = nouv;
        }

        Reptile& operator = (const Reptile&);
        friend std :: istream& operator >> (std :: istream&, Reptile&);
        friend std :: ostream& operator << (std :: ostream&, Reptile&);

};

