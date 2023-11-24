#include <iostream>
#include <fstream>

const int MAX_REGISTROS = 100;

struct EstadoFinal {
    char tablero[3][3];
};

bool sonIguales(const EstadoFinal &estado1, const EstadoFinal &estado2) {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (estado1.tablero[i][j] != estado2.tablero[i][j])
                return false;
    return true;
}

void mostrarFrecuencias(const int frecuencias[], int totalRegistros) {
    for (int i = 0; i < totalRegistros; ++i) {
        std::cout << frecuencias[i] << std::endl;
    }
}

int main() {
    EstadoFinal registros[MAX_REGISTROS];
    int frecuencias[MAX_REGISTROS] = {0};
    int totalRegistros = 0;
    int opcion;
    std::ifstream archivo("entrada.txt");

    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir el archivo de entrada." << std::endl;
        return 1;
    }

    while (archivo >> opcion && opcion != 3) {
        switch (opcion) {
            case 1: {
                if (totalRegistros < MAX_REGISTROS) {
                    for (int i = 0; i < 3; ++i)
                        for (int j = 0; j < 3; ++j)
                            archivo >> registros[totalRegistros].tablero[i][j];
                    totalRegistros++;
                } else {
                    std::cerr << "Número máximo de registros alcanzado." << std::endl;
                }
                break;
            }
            case 2: {
                EstadoFinal consulta;
                for (int i = 0; i < 3; ++i)
                    for (int j = 0; j < 3; ++j)
                        archivo >> std::ws >> consulta.tablero[i][j];
                int frecuencia = 0;
                for (int i = 0; i < totalRegistros; ++i) {
                    if (sonIguales(registros[i], consulta)) {
                        frecuencia++;
                    }
                }
                frecuencias[totalRegistros - 1] = frecuencia;
                break;
            }
            default:
                std::cerr << "Opción no válida." << std::endl;
                break;
        }
    }

    archivo.close();
    mostrarFrecuencias(frecuencias, totalRegistros);
    return 0;
}
