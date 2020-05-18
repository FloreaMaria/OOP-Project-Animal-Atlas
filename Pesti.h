#pragma once
#include "Exceptie.h"
#include "Vertebrate.h"
#include <typeinfo>

class Pesti : public Vertebrate
{

    std :: string tip_inotatoare;
    int nr_inotatoare, dimensiune;
    bool rapitor;


    public:

        Pesti();
        Pesti(std :: string casa, std :: string tip_inotatoare, int nr_inotatoare, int dim, bool rapitor);
        Pesti(const Pesti&);
        virtual ~Pesti() = default;
        void Display();

        std :: string getInotatoare() const{
            return this -> tip_inotatoare;
        }

        void setInotatoare(std :: string tip_nou){
            this -> tip_inotatoare = tip_nou;
        }

        int getnrInotatoare() const{
            return this -> nr_inotatoare;
        }

        void setnrInotatoare(int nnou){

            this -> nr_inotatoare = nnou;
        }

        void setRapitor(bool a){

            this -> rapitor = a;
        }

        int getRapitor() const{

            return this -> rapitor;
        }

        void setDim(int dimnou){
            this -> dimensiune = dimnou;
        }
        int getDim() const{
            return this -> dimensiune;
        }


        Pesti& operator = (const Pesti&);
        friend std :: istream& operator >> (std :: istream&, Pesti&);
        friend std :: ostream& operator << (std :: ostream&, Pesti&);


};


