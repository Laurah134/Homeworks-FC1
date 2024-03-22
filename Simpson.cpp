#include<iostream>
#include<cmath>
#include<fstream>

//Función para integrar
double f(double x){
    return 100*pow(x,2)*cos(20*x);
}

//Calcuilo de la integral aproximada bajo cuadratura rectangular
double sum1(double a, double b, int N){
    double h=(b-a)/N;
    double I1;
    for(int i=0;i<N;i++){
        double xi=a+i*h;
        I1+=f(xi+h/2);
    }
    return I1*4;
}
double sum2(double a, double b, int N){
    double h=(b-a)/N;
    double I2;
    for(int i=2;i<N;i++){
        double xi=a+i*h;
        I2+=f(xi);
    }
    return I2*2;
}

double Simpson(double a,double b,int N)
{
    double h=(b-a)/N;
    return (h/6)*(f(a)+sum1(a,b,N)+sum2(a,b,N)+f(b));
}

int main(){


std::ofstream datafile1("Aproximacion_simpson.dat");

for(int N=1; N<=10000; ++N){
    double integralS =Simpson(0.0,1.0,N);
    double integral_exacta=4.7459;
    double e=abs(integralS-integral_exacta)/integral_exacta;
    datafile1<<N<<" "<<integralS<<" "<<integral_exacta<<" "<<e<<std::endl;
    }
datafile1.close();

std::ofstream scriptFile2("Aproximacion_simpson.gp");
scriptFile2<<"set term png\n";
scriptFile2<<"set output 'Aproximacion_simpson.png'\n";
scriptFile2<<"set xlabel 'N'\n";
scriptFile2<<"set ylabel 'Integral'\n";
scriptFile2<<"set logscale x\n";
scriptFile2<<"plot 'Aproximacion_simpson.dat' u 1:2 w l title 'Integral aproximada', '' u 1:3 w l title 'Valor exacto'\n";
scriptFile2.close();

std::ofstream dataFile3("rectangulos_Simpson.dat");
int N_plot=10000;
double h_plot=(1.0-0.0)/N_plot;
for(double x=0.0; x<=1.0; x+=h_plot){
    dataFile3<<x<<" "<<f(x)<<std::endl;
    dataFile3<<x<<" "<<0.0<<std::endl;
    dataFile3<<std::endl;
}
dataFile3.close();

std::ofstream scriptFile3("simpson_rectangulos.gp");
scriptFile3<<"set term png\n";
scriptFile3<<"set output 'simpson_rectangulos.png'\n";
scriptFile3<<"set xlabel 'x'\n";
scriptFile3<<"set ylabel 'f(x)'\n";
scriptFile3<<"set logscale x\n";
scriptFile3<<"plot 'rectangulos_Simpson.dat' w l title 'Funcion', '' w boxes title 'Rectangulos'\n";
scriptFile3.close();

std::ofstream scriptFile4("errorS.gp");
scriptFile4<<"set term png\n";
scriptFile4<<"set output 'errorS.png'\n";
scriptFile4<<"set xlabel 'N'\n";
scriptFile4<<"set ylabel 'Integral'\n";
scriptFile4<<"set logscale x\n";
scriptFile4<<"plot 'Aproximacion_trapezoidal.dat' u 1:4 w l title 'Error'\n";
scriptFile4.close();


system("gnuplot Aproximacion_simpson.gp");
system("gnuplot simpson_rectangulos.gp");
system("gnuplot errorS.gp");
return 0;
}