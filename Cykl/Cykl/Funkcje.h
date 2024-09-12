/** @file */

// DECLARATIONS (HEADERS) OF FUNCTIONS

#ifndef FUNKCJE_H
#define FUNKCJE_H

#include "Struktury.h"

/** @brief Funkcja odczytuje dane z pliku
* @param plik_z_grafem Plik zawiera wierczholki grafu polaczone strzalkami
* @return Zwraca odczytane z pliku liczby typu string
*/
std::string oczytanie_z_pliku(const std::string& plik_z_grafem);

/** @brief Funkcja przeszkuje parametr typu string w celu odnalezienia ciagu znakow ktore zostane przeksztalcone w typ int i usuwa go
* @param str Lancuch znakow w ktorym szukamy ciagow znakow ktory mozemy przemienic na int
* @return Zwraca wierzcholki grafu zamienione int
*/
int int_ze_stringa(std::string& str);

/** @brief Funkcja wypisuje zawartosc wektora
* @param[out] vector Wektor z zapisanymi cyklami
* @param vector Wektor ktory zostanie wypisany
*/
void wypisz_vector(std::vector<int>& vector);

/** @brief Funkcja sprawdza czy podany wektor zawiera cykl do wypisania
* @param vector Przeszukiwany wektor
* @param wartosc Cykl do wypisania ktorego szukamy w wektorze
* @return Funkcja zwraca true lub false w zaleznosci od tego czy znaleziono cykl do wypisania z wektora
*/
bool czy_wektor_zawiera(const std::vector<int>& vector, int wartosc);

/** @brief Funkcja szuka cykli w grafie
* @param graf Graf ktory przeszukujemy w celu znalezienia w nim cykli
* @param[out] cykl Znaleziony cykl w grafie
* @param wierz_poczatkowy Wierzcholek poczatkowy krawedzi grafu
* @param sasiad Wierzcholek z ktorym wierzcholek poczatkowy posiada polaczenie w grafie
* @param zapis
* @return Funkcja nic nie zwraca
*/
void szukanie_cykli(const Graf& graf, std::vector<int>& cykl, const int wierz_poczatkowy, const int sasiad, std::ofstream& zapis);

/** @brief Funkcja do pierwszego znalezionego wierzcholka grafu przypisuje jego sasiada
* @param[out] cykl Wektor zawierajacy cykle
* @param str Lancuch znakow ktory zostaje wykorzystany w celu wygenerowania grafu
* @param graf Graf ktory generujemy
* @return Funkcja nic nie zwraca
*/
void stworz_graf_ze_stringa(std::string str, Graf& graf);

/** @brief Wypisuje w konsoli tekstowa reprezentacje grafu
* @param[out] graf Graf do wypisania
* @param graf Graf ktory wypisujemy
*/
void drukuj_graf(Graf& graf);

/** @brief Funkcja wywoluje funkcje szukanie_cykli a po znalezieniu cykli zapisuje je do pliku
* @param graf Graf w ktorym szukamy cykli
* @param plik_z_cyklami Plik do ktorego zostana zapisane znalezione cykle
* @return Funkcja nic nie zwraca
*/
void zapisz_cykle(Graf& graf, const std::string& plik_z_cyklami);


#endif