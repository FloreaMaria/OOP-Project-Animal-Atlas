
#include "Animale.h"
#include <iostream>
#include <string>
#pragma once

class Vertebrate : public Animale
{
    /// bool vertebra
    public:

        Vertebrate();
        Vertebrate(std :: string casa, std :: string Repr);
        Vertebrate(const Vertebrate &);
        virtual ~Vertebrate() = default;
        void Display();


        Vertebrate& operator = (const Vertebrate&);
        friend std :: istream& operator >> (std :: istream&, Vertebrate &);
        friend std :: ostream& operator << (std :: ostream&, Vertebrate &);


};


