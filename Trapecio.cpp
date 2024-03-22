#include<iostream>
#include<cmath>
#include<fstream>
#include<vector>

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
    double e=abs(integralT-integral_exacta)/integral_exacta;
    datafile1<<N<<" "<<integralT<<" "<<integral_exacta<<" "<<integralR<<" "<<" "<<e<<std::endl;
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



std::ofstream dataFile3("rectangulos_trapecio.dat");
int N_plot=100;
double h_plot=(1.0-0.0)/N_plot;
for(double x=0.0; x<=1.0; x+=h_plot){
    dataFile3<<x<<" "<<f(x)<<std::endl;
    dataFile3<<x<<" "<<0.0<<std::endl;
    dataFile3<<std::endl;
}
dataFile3.close();

std::ofstream scriptFile3("Trapezoide_rectangulos.gp");
scriptFile3<<"set term png\n";
scriptFile3<<"set output 'Trapezoides_rectangulos.png'\n";
scriptFile3<<"set xlabel 'x'\n";
scriptFile3<<"set ylabel 'f(x)'\n";
scriptFile3<<"set logscale x\n";
scriptFile3<<"plot 'rectangulos_trapecio.dat' w l title 'Funcion', '' w boxes title 'Rectangulos'\n";
scriptFile3.close();

std::ofstream scriptFile4("error.gp");
scriptFile4<<"set term png\n";
scriptFile4<<"set output 'error.png'\n";
scriptFile4<<"set xlabel 'N'\n";
scriptFile4<<"set ylabel 'Integral'\n";
scriptFile4<<"set logscale x\n";
scriptFile4<<"plot 'Aproximacion_trapezoidal.dat' u 1:5 w l title 'Error'\n";
scriptFile4.close();


system("gnuplot Aproximacion_trapezoidal_rectangular.gp");
system("gnuplot Aproximacion_trapezoidal.gp");
system("gnuplot Trapezoide_rectangulos.gp");
system("gnuplot error.gp");




return 0;

}
