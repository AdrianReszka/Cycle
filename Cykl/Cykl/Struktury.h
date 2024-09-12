/** @file */

#ifndef STRUKTURY_H
#define STRUKTURY_H

#include <unordered_map>
#include <vector>
#include <string>


/**
 * @brief Typ przechowujacy informacje o krawedzi grafu
*/
struct krawedz
{
    /**Przechowuje wierzcholek koncowy krawedzi*/
    int wierz_koncowy;
};


/**
 * @brief Typ przechowujacy wczytane krawedzie grafu
*/
struct wierzcholek
{
    /**Przechowuje krawedz z wierzcholkiem koncowym*/
    std::vector<krawedz> krawedzie;
};



/**
 * @brief Typedef mapy nieuporzadkowanej aby uniknac zmiennej globalnej
*/
typedef
std::unordered_map<int, wierzcholek> Graf;

   
#endif
