#include "hash.hpp"

int h(tipoClave k) {
    return k % tamTabla;
}

int hashInsert(ranura HT[], tipoClave k, tipoInfo I) {
    int pos = h(k);
    
    // Verificar si la clave ya está en la tabla
    if (HT[pos].ocupado && HT[pos].clave == k) {
        return 0;  // La clave ya está en la tabla
    }

    // Buscar la primera ranura libre
    while (HT[pos].ocupado) {
        pos = (pos + 1) % tamTabla;
    }

    // Insertar la clave y la información
    HT[pos].clave = k;
    HT[pos].informacion = I;
    HT[pos].ocupado = true;

    return 1;  // Inserción exitosa
}

tipoInfo hashDelete(ranura HT[], tipoClave k) {
    int pos = h(k);

    while (HT[pos].ocupado) {
        if (HT[pos].clave == k) {
            // Eliminar la clave y retornar la información asociada
            HT[pos].ocupado = false;
            return HT[pos].informacion;
        }
        pos = (pos + 1) % tamTabla;
    }

    // La clave no se encontró, retorna un valor inválido
    tipoInfo infoInvalida;
    // Puedes personalizar infoInvalida según tus necesidades
    return infoInvalida;
}

tipoInfo hashSearch(ranura HT[], tipoClave k) {
    int pos = h(k);

    while (HT[pos].ocupado) {
        if (HT[pos].clave == k) {
            // Retornar la información asociada a la clave
            return HT[pos].informacion;
        }
        pos = (pos + 1) % tamTabla;
    }

    // La clave no se encontró, retorna un valor inválido
    tipoInfo infoInvalida;
    // Puedes personalizar infoInvalida según tus necesidades
    return infoInvalida;
}
