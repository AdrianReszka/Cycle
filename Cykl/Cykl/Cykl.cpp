#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <unordered_map>

#include "Funkcje.h"
#include "Struktury.h"

#include <iostream>
#include <cstring>


int main(int argc, char* argv[])
{
    if (argc != 5) {
        std::cout << "Niepoprawne parametry wywolania!" << std::endl;
        std::cout << "Poprawne wywolania: " << std::endl;
        std::cout << "1) -g nazwa pliku z grafem  -e nazwa pliku do ktorego maja zostac zapisane cykle" << std::endl;
        std::cout << "2) -e nazwa pliku do ktorego maja zostac zapisane cykle  -g nazwa pliku z grafem" << std::endl;
        return 0;
    }

    std::string plik_z_grafem;
    std::string plik_z_cyklami;

    if (strcmp(argv[1], "-g") == 0 && strcmp(argv[3], "-e") == 0)
    {
    plik_z_grafem = argv[2];
    plik_z_cyklami = argv[4];
    }  

    if (strcmp(argv[1], "-e") == 0 && strcmp(argv[3], "-g") == 0)
    {
    plik_z_cyklami = argv[2];
    plik_z_grafem = argv[4];
    }


    std::ifstream file(plik_z_grafem);
    if (!file)
    {
        std::cerr << "Plik <" << plik_z_grafem << "> nie zostal znaleziony!" << std::endl;
        return 0;
    }

    std::string wynik = oczytanie_z_pliku(plik_z_grafem);  
    std::cout << "przed: " << wynik << std::endl;

    Graf graf;


    stworz_graf_ze_stringa(wynik, graf);
    std::cout << "po: " <<  wynik << std::endl;  
    drukuj_graf(graf);
    zapisz_cykle(graf, plik_z_cyklami); 

    return 0;
}  