#ifndef HASH_HPP
#define HASH_HPP

#include <string>

typedef int tipoClave;

const int tamTabla = 100;

struct tipoInfo {
    std::string informacion;
};

struct ranura {
    tipoClave clave;
    tipoInfo informacion;
    bool ocupado;  // Indica si la ranura está ocupada
};

int h(tipoClave k);

int hashInsert(ranura HT[], tipoClave k, tipoInfo I);

tipoInfo hashDelete(ranura HT[], tipoClave k);

tipoInfo hashSearch(ranura HT[], tipoClave k);

#endif  // HASH_HPP
