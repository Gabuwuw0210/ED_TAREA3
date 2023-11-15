#include <iostream>
#include <fstream>
#include <string>

const int MAX_PREMIOS = 100;

struct Premio {
    int numero;
    std::string descripcion;
    bool entregado;
};

void cargarPremios(const char* archivo, Premio premios[], int& totalPremios) {
    std::ifstream archivoPremios(archivo);

    if (archivoPremios.is_open()) {
        archivoPremios >> totalPremios;

        for (int i = 0; i < totalPremios; ++i) {
            archivoPremios >> premios[i].numero >> premios[i].descripcion;
            premios[i].entregado = false;
        }

        archivoPremios.close();
    } else {
        std::cerr << "No se pudo abrir el archivo de premios." << std::endl;
    }
}

void realizarSorteo(Premio premios[], int totalPremios, int numerosComprados[], int k) {
    for (int i = 0; i < k; ++i) {
        bool premioEncontrado = false;

        for (int j = 0; j < totalPremios; ++j) {
            if (!premios[j].entregado && premios[j].numero == numerosComprados[i]) {
                std::cout << premios[j].descripcion << std::endl;
                premios[j].entregado = true;
                premioEncontrado = true;
                break;
            }
        }

        if (!premioEncontrado) {
            std::cout << "No tiene premio" << std::endl;
        }
    }
}

int main() {
    const char* archivoPremios = "premios.txt";
    const int MAX_PERSONAS = 100;

    Premio premios[MAX_PREMIOS];
    int totalPremios = 0;

    cargarPremios(archivoPremios, premios, totalPremios);

    int k;
    std::cin >> k;

    int numerosComprados[MAX_PERSONAS];
    for (int i = 0; i < k; ++i) {
        std::cin >> numerosComprados[i];
    }

    realizarSorteo(premios, totalPremios, numerosComprados, k);

    return 0;
}
