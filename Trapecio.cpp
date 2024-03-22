#include<iostream>
#include<cmath>
#include<fstream>

//Funcion para integrar

double f(double x)
{
    return 100*pow(x,2)*cos(20*x);
}

//Calcuilo de la integral aproximada bajo regla trapezoidal
double Trapezoidal(double a, double b, int N){
    double h=(b-a)/N;
    double suma=0.0;
    for(int i=2;i<N;i++){ 
        double xi=a+i*h;
        suma+=f(xi);
    }
    return (suma+(1/2)*(f(a)+f(b)))*h;
}

double Rectangular(double a, double b, int N){
    double h=(b-a)/N;
    double suma=0.0;
    for(int i=0;i<N;i++){
        double xi=a+i*h;
        suma+=f(xi);
    }
    return h*suma;
}
int main(){


std::ofstream datafile1("Aproximacion_trapezoidal.dat");

for(int N=1; N<=10000; ++N){
    double integralT =Trapezoidal(0.0,1.0,N);
    double integral_exacta=4.7459;
    double integralR=Rectangular(0.0,1.0,N);
    datafile1<<N<<" "<<integralT<<" "<<integral_exacta<<" "<<integralR<<std::endl;
    }
datafile1.close();

std::ofstream scriptFile1("Aproximacion_trapezoidal_rectangular.gp");
scriptFile1<<"set term png\n";
scriptFile1<<"set output 'Aproximacion_trapezoidal_rectangular.png'\n";
scriptFile1<<"set xlabel 'N'\n";
scriptFile1<<"set ylabel 'Integral'\n";
scriptFile1<<"set logscale x\n";
scriptFile1<<"plot 'Aproximacion_trapezoidal.dat' u 1:2 w l title 'Integral aproximada Trapezoide', '' u 1:3 w l title 'Valor exacto', '' u 1:4 w l title 'Integral aproximada por rectangulo'\n";
scriptFile1.close();

std::ofstream scriptFile2("Aproximacion_trapezoidal.gp");
scriptFile2<<"set term png\n";
scriptFile2<<"set output 'Aproximacion_trapezoidalr.png'\n";
scriptFile2<<"set xlabel 'N'\n";
scriptFile2<<"set ylabel 'Integral'\n";
scriptFile2<<"set logscale x\n";
scriptFile2<<"plot 'Aproximacion_trapezoidal.dat' u 1:2 w l title 'Integral aproximada Trapezoide', '' u 1:3 w l title 'Valor exacto'\n";
scriptFile2.close();

system("gnuplot Aproximacion_trapezoidal_rectangular.gp");
system("gnuplot Aproximacion_trapezoidal.gp");



return 0;

}
