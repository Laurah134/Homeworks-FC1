#include<iostream>
#include<cmath>
#include<fstream>
#include <cstdlib>

//con v0=0 y t0=0 magnitud de la velocidad
double velocidadf(double vlim, double g, double t)
{
    return vlim*(-exp(g*t/vlim)+exp(-g*t/vlim))/(-exp((g*t/vlim))-exp(-g*t/vlim));
}

double derivada_velocidad(double g, double b, double m, double v)
{
    return g-(b/m)*(v*v);
}


int main()
{
    double m1=70;
    double g1=9.8;
    double rho=1.29;
    double A=0.6;
    double delta=0.8;
    double b1=(rho*A*delta)/2;
    double vlim1=sqrt((m1*g1)/b1);
    long double vi=0;
    long double v2i=0;
    double N1=100;
    double h=50/N1;

    std::ofstream datafile1("velocidad.dat");

    for (double t=0; t<=50; t+=h)
    {
        long double velocidad= velocidadf(vlim1, g1, t);
        v2i=vi+h*derivada_velocidad(g1, b1, m1, vi);
        long double e=((vi-velocidad)/velocidad)*100;
        datafile1<<t<<"    "<<velocidad<<"   "<<vi<<"    "<<e<<std::endl;
        vi=v2i;
    }
    datafile1.close();

    std::ofstream scriptFile("Grafica_velocidad.gp");
    scriptFile<<"set term png\n";
    scriptFile<<"set output 'Grafica_de_velocidad.png'\n";
    scriptFile<<"set xlabel 'Tiempo(s)'\n";
    scriptFile<<"set ylabel 'V' \n";
    scriptFile<<"set title 'Velocidad (m/s)'\n";
    scriptFile<<"set grid\n";
    scriptFile<<"set key below\n";
    scriptFile<<"plot 'velocidad.dat' u 1:2 w l title 'Función analítica', 'velocidad.dat' u 1:3 w points pointsize 0.5 title 'Método de Euler'\n ";
    scriptFile.close();

    std::ofstream scriptFile2("Grafica_velocidad_error.gp");
    scriptFile2<<"set term png\n";
    scriptFile2<<"set output 'Grafica_de_velocidad_error.png'\n";
    scriptFile2<<"set xlabel 'Tiempo(s)'\n";
    scriptFile2<<"set ylabel 'E'\n";
    scriptFile2<<"set title 'Error de aproximación para la velocidad(%)'\n";
    scriptFile2<<"set grid\n";
    scriptFile2<<"plot 'velocidad.dat' u 1:4 w l linewidth 2 title 'error velocidad'\n";
    scriptFile2.close();



    system("gnuplot Grafica_velocidad.gp");
    system("gnuplot Grafica_velocidad_error.gp");

    return 0;
}