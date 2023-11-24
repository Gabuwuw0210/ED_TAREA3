#include "hash.hpp"

int h(tipoClave k) {
    return k % tamTabla;
}

int hashInsert(ranura HT[], tipoClave k, tipoInfo I) {
    int pos = h(k);
    
    if (HT[pos].entregado && HT[pos].numero == k) {
        return 0;
    }

    while (HT[pos].entregado) {
        pos = (pos + 1) % tamTabla;
    }

    HT[pos].numero = k;
    HT[pos].descripcion = I.informacion;
    HT[pos].entregado = true;

    return 1;
}

tipoInfo hashDelete(ranura HT[], tipoClave k) {
    int pos = h(k);

    while (HT[pos].entregado) {
        if (HT[pos].numero == k) {
            tipoInfo retorno;
            HT[pos].entregado = false;
            retorno.informacion = HT[pos].descripcion;
            return retorno;
        }
        pos = (pos + 1) % tamTabla;
    }

    tipoInfo infoInvalida;
    return infoInvalida;
}

tipoInfo hashSearch(ranura HT[], tipoClave k) {
    int pos = h(k);

    while (HT[pos].entregado) {
        if (HT[pos].numero == k) {
            tipoInfo retorno;
            retorno.informacion = HT[pos].descripcion;
            return retorno;
        }
        pos = (pos + 1) % tamTabla;
    }

    tipoInfo infoInvalida;
    return infoInvalida;
}
