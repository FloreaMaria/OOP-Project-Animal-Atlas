#include "Animale.h"
#include <string>
#include <iostream>
#pragma once

class Nevertebrate : public virtual Animale
{

    public:

        Nevertebrate();
        Nevertebrate(std :: string casa, std :: string R);
        Nevertebrate(const Nevertebrate&);
        virtual ~Nevertebrate()= default;
        void Display();
        Nevertebrate& operator = (const Nevertebrate&);
        friend std :: istream& operator >> (std :: istream&, Nevertebrate&);
        friend std :: ostream& operator << (std :: ostream&, Nevertebrate&);

};


