#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "Animale.h"
#include "Vertebrate.h"
#include "Nevertebrate.h"
#include "Pesti.h"
#include "Pasari.h"
#include "Reptile.h"
#include "Mamifere.h"
#include "AtlasZoologic.h"
#include <list>




void CitireAnimale()
{

    std :: list <Animale*> Lista;
    int n, nev;
    std :: cout << "Introduceti numarul de animale : ";

    if(std :: cin >> n)
    {
        while(n > 0)
        {
            std :: cout << "Alege un tip de animal (1 - nevertebrata, 2 - vertebrata) :\n";
            int p;
            std :: cin >> p;
            if(p == 1)
            {
                Nevertebrate * N = new Nevertebrate();
                std ::  cin >> (*N);
                Lista.push_back(N);
                n --;
            }
            else if(p == 2)
            {
                std :: cout << "Alege o vertebrata (1 - Pasare, 2 - Peste, 3 - Reptila, 4 - Mamifer) : \n";
                std :: cin >> nev;

                switch(nev)
                {
                case 1 :
                {
                    Pasari * p = new Pasari();
                    std :: cin >> (*p);
                    Lista.push_back(p);
                    n --;
                    break;
                }
                case 2 :
                {
                    Pesti * p = new Pesti();
                    std :: cin >> (*p);

                    Lista.push_back(p);
                    n--;
                    break;
                }
                case 3 :
                {
                    Reptile *r = new Reptile();
                    std :: cin >> (*r);
                    Lista.push_back(r);
                    n -- ;
                    break;
                }
                case 4 :
                {
                    Mamifere *m  = new Mamifere();
                    std :: cin >> (*m);
                    Lista.push_back(m);
                    n --;
                    break;
                }
                }
            }
        }
    }
    else
    {
        std ::  cout << "Wrong number!\n";
    }
    int i = 1;
    for(auto it : Lista)
    {
        std :: cout << "Animalul nr " << i << ": \n";
        i++;
        it -> Display();
    }

}

void Meniu()
{
    cout << "MENIU :\n";
    cout << "1 - Citire si afisare n animale\n";
    cout << "2 - Citire atlas zoologic\n";
    cout << "3 - Adaugare fisa observatie in atlas\n";
    cout << "4 - Afisare atlas\n";
    cout << "5 - Citire atlas pesti\n";
    cout << "6 - Afisare numar pesti rapitori mai mari de 1 metru\n";
    cout << "7 - Revenire meniu principal\n";
    cout << "8 - Exit\n";
}



int main()
{
    int p;
    int ok = 0, animal, ok2 = 0;
    AtlasZoologic <Animale> A;
    AtlasZoologic<Pesti> P;
    do
    {
        Meniu();
        cin >> p;
        if(p == 1)
            CitireAnimale();
        else if(p == 2)
        {
            ok = 1;
            cin >> A;
        }
        else if(p == 3)
        {
            if(ok == 1)
            {
                std :: cout << "Introduceti ce fel de animal doriti sa adaugati in atlas\n";
                std :: cout << "1 - Nevertebrata, 2 - Vertebrata\n";
                cin >> animal;
                if(animal == 1)
                {
                    Nevertebrate *N = new Nevertebrate;
                    cin >> *N;
                    A += N;
                    std :: cout << "Adaugare efectuata cu succes!\n";
                }
                else if(animal == 2)
                {
                    int c;
                    std :: cout << "Introduceti ce vertebrata doriti sa adaugati in atlas\n";
                    std :: cout << "1 - Pasare, 2 - Peste, 3 - Reptila, 4 - Mamifer \n";
                    cin >> c;
                    if(c == 1)
                    {
                        Pasari * p = new Pasari;
                        cin >> *p;
                        A += p;
                        std :: cout << "Adaugare efectuata cu succes!\n";
                    }
                    else if(c == 2)
                    {
                        Pesti * l =  new Pesti;
                        cin >> *l;
                        A += l;
                        std :: cout << "Adaugare efectuata cu succes!\n";
                    }
                    else if(c == 3)
                    {
                        Reptile *r =  new Reptile;
                        cin >> *r;
                        A += r;
                        std :: cout << "Adaugare efectuata cu succes!\n";
                    }
                    else if(c == 4)
                    {
                        Mamifere  *m = new Mamifere;
                        cin >> *m;
                        A += m;
                        std :: cout << "Adaugare efectuata cu succes!\n";
                    }
                    else
                    {
                        std :: cout << "Introduceti optiune valida!\n";
                        continue;
                    }
                }

            }
            else
            {
                std :: cout << "Nu ati citit un atlas inca!\n";
                continue;
            }
        }
        else if(p == 4)
        {
            if(ok == 1)
            {
                cout << A;
            }
            else
            {
                cout << "Nu ati citit un atlas inca!\n";
                continue;
            }
        }
        else if(p == 5)
        {
            ok2 = 1;
            cin >> P;
        }
        else if(p == 6)
        {
            if(ok2 == 0)
                std :: cout << "Nu ati citit un atlas pentru pesti inca!\n";
            else
            {
                if(P.getPestiBuni() == 1)
                    cout << "Exista 1 peste rapitor mai mare de 1 metru\n";
                if(P.getPestiBuni() == 0)
                    cout << "Nu exista pesti rapitori mai mari de 1 metru in acest atlas\n";
                else
                    cout << "Exista " << P.getPestiBuni() << " pesti rapitori mai mari de 1 metru in acest atlas\n";
            }

        }
        else if(p == 8)
        {
            break;
        }
        else
        {
            std :: cout << "Introduceti o optiune valida!\n";
            continue;
        }
    }
    while(true);

    return 0;
}
