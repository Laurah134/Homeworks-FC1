#include <iostream>

#include <iostream>
#include <cmath>
#include <cstdlib>

// Definición de funciones
double f(double x) {
    return exp(2*x) + log(2*x);
}

double df(double x) {
    if (x != 0) {
        return exp(2*x) * 2 + 1/x;
    } else {
        // Manejar la división por cero
        std::cerr << "Error: División por cero." << std::endl;
        exit(EXIT_FAILURE);
    }
}

int main() {
    // Definición de variables
    double x0, x1;
    int iteraciones = 100000;
    system("cls");

    std::cout << "Ingrese el valor aproximado en el cual cree que está la raíz de la función: " << std::endl;
    std::cin >> x0;

    // Verificación de valores de f(x0) y df(x0)
    if (std::isnan(f(x0)) || std::isnan(df(x0))) {
        std::cout << "La función no está definida en el punto ingresado" << std::endl;
    } else {
        // Método Newton-Raphson
        for (int i = 0; i < iteraciones; i++) {
            x1 = x0 - f(x0) / df(x0);
            x0 = x1;
        }

        // Resultado obtenido
        std::cout << "La raíz de la función es: " << x1 << std::endl;
        std::cout << "f(x): " << f(x0) << std::endl;
        std::cout << "df(x): " << df(x0) << std::endl;
    }

    return 0;
}