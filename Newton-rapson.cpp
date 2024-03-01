#include <iostream>
#include<cmath>
#include<cstdlib>
#include <math.h>

//Definición de funciones
double f(double x)
{
    return pow(exp(1.0), 2*x)+log(2*x);
}
double df(double x)
{
    return pow(exp(1.0) , 2*x)*2+1/x;
}

int main()
{
    //Definición de variables
    double x0, x1;
    int iteraciones=100000;
    system("cls");
    std::cout<<"Ingrese el valor aproximado en el cual cree que esta la raiz de la función: "<<std::endl;
    std::cin>>x0;

    //Verificación de valores de f(x0) y df(x0)
    if (isnan(f(x0)) || isnan(df(x0)))
    {
        std::cout<<"La funcion no esta definidad en el punto ingresado"<<std::endl;
    }

    //Metodo Newton-Raphson
    else{
        for(int i=0; i < iteraciones; i++)
        {
        x1=x0-f(x0)/df(x0);
        x0=x1;
        }
        //Resultado obtenido
        std::cout<<"La raiz de la función es: "<< x1 <<std::endl;
    }
    return 0;
}
