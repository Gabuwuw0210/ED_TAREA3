#include <iostream>
#include <fstream>
#include <string>

struct Premio {
    int numero;
    std::string descripcion;
};

void cargarPremios(const char* archivo, Premio premios[], int n) {
    std::ifstream archivoPremios(archivo);

    if (!archivoPremios) {
        std::cerr << "Error al abrir el archivo de premios." << std::endl;
        exit(1);
    }

    for (int i = 0; i < n; ++i) {
        archivoPremios >> premios[i].numero >> premios[i].descripcion;
    }

    archivoPremios.close();
}

void realizarSorteo(Premio premios[], int n, int numeros[], int k) {
    for (int i = 0; i < k; ++i) {
        bool premioEncontrado = false;
        for (int j = 0; j < n; ++j) {
            if (numeros[i] == premios[j].numero) {
                std::cout << premios[j].descripcion << std::endl;
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

    std::ifstream archivo(archivoPremios);
    if (!archivo) {
        std::cerr << "Error al abrir el archivo de premios." << std::endl;
        return 1;
    }

    int n;
    archivo >> n;

    Premio premios[n];
    cargarPremios(archivoPremios, premios, n);

    int k;
    std::cin >> k;

    int numeros[k];
    for (int i = 0; i < k; ++i) {
        std::cin >> numeros[i];
    }

    realizarSorteo(premios, n, numeros, k);

    archivo.close();

    return 0;
}
