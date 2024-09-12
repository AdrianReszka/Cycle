#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

#include "Funkcje.h"
#include "Struktury.h"


std::string oczytanie_z_pliku(const std::string& plik_z_grafem) {

    std::ifstream file(plik_z_grafem);

    char znak;
    std::string graf = "";


    while (!file.eof())
    {
        while (!file.eof()) {
            znak = file.get();

            if (std::isdigit(znak)) {
                graf += znak;
            }
            else if (znak == ',' || znak == '-' || znak == '>')
            {
                graf += ' ';
            }

        }

    }

    file.close();

    return graf;
}

int int_ze_stringa(std::string& str)   
{

    int wynik = 0;

    bool znajdz_pierwszy_int = false;

    int i = 0;
    for (; i < str.size(); i++) {

        if (str[i] <= '9' && str[i] >= '0')
            //zabezpieczenie przed liczbami wielocyfrowymi
        {
            wynik *= 10;
            wynik += str[i] - '0';
            znajdz_pierwszy_int = true;
        }
        else
        {
            if (znajdz_pierwszy_int)
            {
                break;
            }
        }


    }

    //skraca stringa o element ktory odczytalismy aby sprawdzic czy jeszcze mamy jakies dane do przetworzenia
    if (i < str.size()) {
        str = str.substr(i + 1, str.size());
    }
    else
    {
        str = str.substr(i, str.size());
    }


    return wynik;
}

void wypisz_vector(std::vector<int>& vector) {
    for (int i : vector)
    {
        std::cout << i << " ";
    }
}

bool czy_wektor_zawiera(const std::vector<int>& vector, int wartosc)
{

    for (int i : vector)
    {
        if (i == wartosc) {
            return true;
        }
    }

    return false;
}

void szukanie_cykli(const Graf& graf, std::vector<int>& cykl, const int wierz_poczatkowy, const int sasiad, std::ofstream& zapis) {


    if (graf.find(sasiad) == graf.end() || graf.at(sasiad).krawedzie.size() == 0) {
        //jezeli w krawedzi nie znajdziemy szukanej liczby albo natrafimy na krawedz w ktorej nie ma zadnego elementu to wtedy nie ma cyklu 
        zapis << "Nie znaleziono cyklu: " << wierz_poczatkowy << std::endl << std::endl;
        return;
    }

    for (krawedz krawedz : graf.at(sasiad).krawedzie) {
        //w wierzcholkach koncowych krawedzi grafu szukamy danego elementu w wektorze z sasiadami

        if (krawedz.wierz_koncowy == wierz_poczatkowy)
            //jezeli znajdziemy taki sam element jak ten od ktorego zaczelismy to wtedy mamy cykl
        {
            zapis << "Znaleziono cykl dla liczby: " << wierz_poczatkowy << "|| ";
            for (int i : cykl)
                //wpisujemy elementy cyklu do strumienia zapis
            {
                zapis << i << " ";
            }
            zapis << std::endl << std::endl;
            continue;
        }

        if (!czy_wektor_zawiera(cykl, krawedz.wierz_koncowy))
        {
            cykl.push_back(krawedz.wierz_koncowy);
            szukanie_cykli(graf, cykl, wierz_poczatkowy, krawedz.wierz_koncowy, zapis);
            cykl.pop_back();
            //zeby nie robic duplikatow cyklu
        }

    }

}


void stworz_graf_ze_stringa(std::string str, Graf& graf)
{

    while (str.size() > 1)
    {

        int wierz_poczatkowy = int_ze_stringa(str);
        krawedz krawedz;
        krawedz.wierz_koncowy = int_ze_stringa(str);

        graf[wierz_poczatkowy].krawedzie.push_back(krawedz);




    }


}




void drukuj_graf(Graf& graf) {

    for (std::pair<int, wierzcholek> numer_wierzcholka : graf) {

        std::cout << numer_wierzcholka.first << ':';

        for (krawedz krawedz : numer_wierzcholka.second.krawedzie) {
            std::cout << krawedz.wierz_koncowy << ',';
        }

        std::cout << '\n';

    }

}


void zapisz_cykle(Graf& graf, const std::string& plik_z_cyklami) {

    std::ofstream zapis(plik_z_cyklami, std::ios::out);

    for (std::pair<int, wierzcholek> wierzcholek : graf)
    {

        std::vector<int> cykle;
        cykle.push_back(wierzcholek.first);

        szukanie_cykli(graf, cykle, wierzcholek.first, wierzcholek.first, zapis);
    }

    zapis.close();
}