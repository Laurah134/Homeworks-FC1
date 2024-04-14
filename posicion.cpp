#include<iostream>
#include<cmath>
#include<fstream>
#include <cstdlib>

double velocidadf(double vlim,double v0, double g, double t, double t0)
{
    return -vlim*((v0-vlim)*exp(g*(t-t0)/vlim)+(v0+vlim)*exp(-g*(t-t0)/vlim))/((v0-vlim)*exp((g*(t-t0)/vlim))-(v0+vlim)*exp(-g*(t-t0)/vlim));
}

//con v0=0, t0=0, y0=100
double posicionf(double vlim, double g, double t)
{
    return ((vlim*vlim)/g)*((g*t)/(vlim)-log(exp((2*g*t)/vlim)+1)+log(2))+100;
}

long double trapezoidMethod(double t0, double tf, double N, double vlim, double g, double v0) {
	double stepSize = (tf - t0) / N;
	long double sum = 0.5 * (v0 + velocidadf(vlim, v0, g, tf, t0));

	for (int i = 1; i <= N; i++) {
		double t = t0 + i * stepSize;
		sum += velocidadf(vlim, v0, g, t, t0);
	}
	return stepSize * sum;
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
    double N1=1000;
    double h=50/N1;
    double v01=0;


 std::ofstream datafile3("Posicion.dat");
    for(double t=0; t<=10; t+=h)
    {
        double posicion=posicionf(vlim1,g1,t);
        double posicion_aprox=trapezoidMethod(0, t, N1, vlim1, g1, v01)+100;
        if (posicion<=0)
        {
            break;
        }

        long double e=(posicion-posicion_aprox)/posicion;
        datafile3<<t<<"       "<<posicion<<"     "<<posicion_aprox<<"     "<<e<<std::endl;
    }

 std::ofstream scriptFile1("Grafica_posicion.gp");
    scriptFile1<<"set term png\n";
    scriptFile1<<"set output 'Grafica_de_posicion_aprox.png'\n";
    scriptFile1<<"set title 'Posición(m)'\n";
    scriptFile1<<"set xlabel 'Tiempo(s)'\n";
    scriptFile1<<"set ylabel 'y'\n";
    scriptFile1<<"plot 'Posicion.dat' u 1:2 w l title 'Funcion analitica', 'Posicion.dat' u 1:3  w points pointsize 0.5 title 'Regla rectangular'\n ";
    scriptFile1.close();

    std::ofstream scriptFile2("Grafica_posicion_error.gp");
    scriptFile2<<"set term png\n";
    scriptFile2<<"set output 'Grafica_de_posicion_error.png'\n";
    scriptFile2<<"set title 'Error de aproximación para para posición(%)'\n";
    scriptFile2<<"set xlabel 'Tiempo(s)'\n";
    scriptFile2<<"set ylabel 'E'\n";
    scriptFile2<<"set grid\n";
    scriptFile2<<"plot 'Posicion.dat' u 1:4 w l linewidth 2 title 'error posicion'\n";
    scriptFile2.close();


    system("gnuplot Grafica_posicion.gp");
    system("gnuplot Grafica_posicion_error.gp");

    return 0;

}