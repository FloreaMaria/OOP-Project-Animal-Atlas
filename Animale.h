
#include <iostream>
#include <string>
#include <iomanip>
#pragma once


class Animale
{
    std :: string home;
    std :: string WayOfReproduction;
    static double oxigen;

    public:
        Animale();
        Animale(std :: string home, std :: string reproduction);
        Animale(const Animale&);
        virtual ~Animale() = default;
        virtual void Display() = 0;

    static double getOxigen(){
        return oxigen;
    }

    void ReduceO2(){
        oxigen  = oxigen - 0.00000000000001;
    }

    static void OxigenRamas(){
        std :: cout << "Procentaj oxigen : ";
        std ::cout << std :: fixed << std :: setprecision(16) << Animale ::getOxigen() << " %\n";
    }

    std :: string getHome() const{
        return this -> home;
    }

    std :: string getRepr() const{
        return this -> WayOfReproduction;
    }

    void setHome(std :: string newhome){
        this -> home = newhome;
    }

    void setRepr(std :: string newWay){
        this -> WayOfReproduction = newWay;
    }

    Animale& operator = (const Animale&);
    friend std :: istream& operator >> (std :: istream&, Animale&);
    friend std :: ostream& operator << (std :: ostream&, const Animale&);

};




