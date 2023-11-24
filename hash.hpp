#ifndef HASH_HPP
#define HASH_HPP

#include <string>

const int tamTabla = 100;

typedef int tipoClave;

struct tipoInfo {
    std::string informacion;
};

struct ranura {
    int numero;
    std::string descripcion;
    bool entregado;
};

int h(tipoClave k);

int hashInsert(ranura HT[], tipoClave k, tipoInfo I);

tipoInfo hashDelete(ranura HT[], tipoClave k);

tipoInfo hashSearch(ranura HT[], tipoClave k);

#endif
