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
    long double vi_e=0;
    long double vi_m=0;
    long double v2i=0;
    double N1=100;
    double h=50/N1;

    std::ofstream datafile1("velocidad.dat");

    for (double t=0; t<=50; t+=h)
    {
        long double velocidad= velocidadf(vlim1, g1, t);
        //Método de euler normal
        v2i=vi_e+h*derivada_velocidad(g1, b1, m1, vi_e);
         long double e_e=((vi_e-velocidad)/velocidad)*100;
        //Metodo de euler mejorado
        double v3i=vi_m+h*0.5*(derivada_velocidad(g1,b1,m1,vi_m)+derivada_velocidad(g1,b1,m1,v2i));
        long double e_m=((velocidad-vi_m)/velocidad)*100;
        datafile1<<t<<"    "<<velocidad<<"   "<<vi_e<<"    "<<vi_m<<"       "<<e_e<<"    "<<e_m<<std::endl;
        vi_e=v2i;
        vi_m=v3i;
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

    scriptFile<<"plot 'velocidad.dat' u 1:2 w l title 'Función analítica', 'velocidad.dat' u 1:3 w points pointsize 0.5 title 'Método de Euler', 'velocidad.dat' u 1:4 w points pointsize 0.3 title 'Método de euler mejorado'\n";
    scriptFile.close();

    std::ofstream scriptFile2("Grafica_velocidad_error.gp");
    scriptFile2<<"set term png\n";
    scriptFile2<<"set output 'Grafica_de_velocidad_error.png'\n";
    scriptFile2<<"set xlabel 'Tiempo(s)'\n";
    scriptFile2<<"set ylabel 'E'\n";
    scriptFile2<<"set title 'Error de aproximación para la velocidad(%)'\n";
    scriptFile2<<"set grid\n";
    scriptFile2<<"plot 'velocidad.dat' u 1:5 w l linewidth 2 title 'error velocidad por euler', 'velocidad.dat' u 1:6 w l linewidth 2 title 'error velocidad por euler mejorado'\n";
    scriptFile2.close();



    system("gnuplot Grafica_velocidad.gp");
    system("gnuplot Grafica_velocidad_error.gp");

    return 0;
}