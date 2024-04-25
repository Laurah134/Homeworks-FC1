#include<iostream>
#include<cmath>
#include<fstream>
#include <cstdlib>


//con v0=0 y t0=0 magnitud de la velocidad
long double velocidadf(double vlim, double g, double t)
{
    return vlim*(-exp(g*t/vlim)+exp(-g*t/vlim))/(-exp((g*t/vlim))-exp(-g*t/vlim));
}

long double derivada_velocidad(double g, double b, double m, double v)
{
    return g-(b/m)*(v*v);
}
long double derivada_velocidad_2(double g, double b, double m, double v)
{
    return (-2*b/m)*v;
}

long double derivada_velocidad_3(double g, double b, double m)
{
    return -2*b/m;
}

//Método de Taylor
long double Taylor_orden3(double v0, double h, double b, double m, double g)
{
    return v0+h*derivada_velocidad(g,b,m,v0)+((h*h)/2)*derivada_velocidad_2(g,b,m,v0)+((h*h*h)/6)*derivada_velocidad_3(g,b,m);
}
//Método de Euler
long double Euler(double v0, double h, double b, double m, double g)
{
    return v0+h*derivada_velocidad(g, b, m, v0);
}
//Método de Euler mejorado (Heun)
long double Heun(double v0, double v02,  double h, double b, double m, double g )
{
    return v0+h*0.5*(derivada_velocidad(g,b,m,v0)+derivada_velocidad(g,b,m,v02));
}
//Método de Runge-Kutta
long double Rungekutta(double v0, double h, double b, double m, double g)
{
    double k1=derivada_velocidad(g, b, m, v0);
    double k2=derivada_velocidad(g, b, m, v0+((h*k1)/2));
    double k3=derivada_velocidad(g, b, m, v0+((h*k2)/2));
    double k4=derivada_velocidad(g, b, m, v0+h*k3);
    return v0+(h/6)*(k1+2*k2+2*k3+k4);
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
    long double vit=0;
    long double vi_e=0;
    long double vi_m=0;
    long double vi_r=0;
    double N1=100;
    double h=50/N1;

    system("cls");

    int selection;
    std::cout<<":::::::::::::::Bienvenido a al problema del paracaidista:::::::::::::::"<<std::endl;
    std::cout<<"\tIngrese mediante cual método númerico le gustaria graficar la velocidad del paracaidista"<<std::endl;
    std::cout<<"\t1. Método de Taylor de orden 3 \n\t2. Método de Euler \n\t3. Método de Euler Mejorado (Heun) \n\t4.Método de Runge-Kutta de orden 4\n\t5. Los tres Métodos"<<std::endl;
    std::cin>>selection;

    std::ofstream datafile1("velocidad.dat");

    for (double t=0; t<=50; t+=h)
    {
        //solución analítica
        long double velocidad= velocidadf(vlim1, g1, t);

        //Método de Taylor de orden 3
        long double vi2t=Taylor_orden3(vit, h, b1, m1, g1);
        long double et=((vit-velocidad)/velocidad)*100;
        if(et<0)
        {
            et=-et;
        }
        //Método de euler normal
        long double v2i=Euler(vi_e, h, b1, m1, g1);
         long double e_e=((vi_e-velocidad)/velocidad)*100;

        //Método de euler mejorado
        long double v3i=Heun(vi_m, v2i, h, b1, m1, g1);
        long double e_m=((velocidad-vi_m)/velocidad)*100;

        //Método de Runge-Kutta
        long double v2_r=Rungekutta(vi_r, h, b1, m1, g1);
        long double e_r=((velocidad-vi_r)/velocidad)*100;

        datafile1<<t<<"    "<<velocidad<<"   "<<vit<<"     "<<vi_e<<"    "<<vi_m<<"     "<<vi_r<<"     "<<et<<"    "<<e_e<<"    "<<e_m<<"     "<<e_r<<std::endl;
        vi_e=v2i;
        vi_m=v3i;
        vit=vi2t;
        vi_r=v2_r;
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

switch (selection)
{
case 1:
    scriptFile<<"plot 'velocidad.dat' u 1:2 w l linewidth 2 title 'Función analítica', 'velocidad.dat' u 1:3 w l linecolor 'black' title 'Método de Taylor'\n";
    break;

case 2:
    scriptFile<<"plot 'velocidad.dat' u 1:2 w l linewidth 2 title 'Función analítica', 'velocidad.dat' u 1:4 w l linecolor 'black' title 'Método de Euler'\n";
    break;
case 3:
    scriptFile<<"plot 'velocidad.dat' u 1:2 w l linewidth 2 title 'Función analítica',  'velocidad.dat' u 1:5 w l linecolor 'black' title 'Método de Euler mejorado'\n";
    break;
case 4:
    scriptFile<<"plot 'velocidad.dat' u 1:2 w l linewidth 2 title 'Función analítica', 'velocidad.dat' u 1:6 w l linecolor 'green' title 'Método de Runge-Kutta de orden 4'\n ";
case 5:
     scriptFile<<"plot 'velocidad.dat' u 1:2 w l linewidth 2 title 'Función analítica', 'velocidad.dat' u 1:3 w l linecolor 'black' title 'Método de Taylor', 'velocidad.dat' u 1:4 w points pointsize 0.6 pt 7 title 'Método de Euler', 'velocidad.dat' u 1:5 w points pointsize 0.5 title 'Método de Euler mejorado', 'velocidad.dat' u 1:6 w l linecolor 'green' title 'Método Runge-Kutta de cuerto orden'\n";
     break;
default:
     std::cout<<"Opción inválida"<<std::endl;
    break;
}
   scriptFile.close();

    std::ofstream scriptFile2("Grafica_velocidad_error.gp");
    scriptFile2<<"set term png\n";
    scriptFile2<<"set output 'Grafica_de_velocidad_error.png'\n";
    scriptFile2<<"set xlabel 'Tiempo(s)'\n";
    scriptFile2<<"set ylabel 'E'\n";
    scriptFile2<<"set title 'Error de aproximación para la velocidad(%)'\n";
    scriptFile2<<"set grid\n";
    switch (selection)
    {
    case 1:
        scriptFile2<<"plot 'velocidad.dat' u 1:7 w l linewidth 2 title 'Error velocidad por Taylor'\n";
        break;
    case 2:
        scriptFile2<<"plot 'velocidad.dat' u 1:8 w l linewidth 2 title 'Error velocidad por Euler'\n";
        break;
    case 3:
        scriptFile2<<"plot 'velocidad.dat' u 1:9 w l linewidth 2 title 'Error velocidad por Euler mejorado' \n";
        break;
    case 4:
        scriptFile2<<"plot 'velocidad.dat' u 1:10 w l linewidth 2 title 'Error velocidad por Runge-Kutta' \n";
        break;
    case 5:
        scriptFile2<<"plot 'velocidad.dat' u 1:7 w l linewidth 2 title 'Error velocidad por Taylor', 'velocidad.dat' u 1:8 w l linewidth 2 title 'Error velocidad por Euler', 'velocidad.dat' u 1:9 w l linewidth 2 title 'Error velocidad por Euler mejorado', 'velocidad.dat' u 1:10 w l linewidth 2 title 'Error velocidad por Runge-Kutta' \n";
        break;
    }
    scriptFile2.close();
    system("gnuplot Grafica_velocidad.gp");
    system("gnuplot Grafica_velocidad_error.gp");
    system("explorer.exe Grafica_de_velocidad.png");
    system("explorer.exe Grafica_de_velocidad_error.png");


    return 0;
}

