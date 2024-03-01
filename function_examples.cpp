#include<iostream>
#include<cmath>
#include<cstdlib>

int menu(){
    int opc;
    std::cout<<"::::MENU::::"<<std::endl;
    std::cout<<"1. Suma\n2. Resta\n3. Producto\n4. División"<<std::endl;
    std::cin>>opc;
    system("cls");
    return opc;
}

double readnum(){

    double num;
    std::cout<<"Ingrese un número:"<<std::endl;
    std::cin>>num;

    return (num);
}

double sum(double num1, double num2){

    return(num1+num2);

}

double resta(double num1, double num2){

    return(num1-num2);

}

double product(double num1, double num2){

    return(num1*num2);

}

double div(double num1, double num2){

    return(num1/num2);

}

int main(){
    double x, y;
    switch (menu())
    {
    case 1:
        x=readnum();
        y=readnum();
        std::cout<<"El resultado es:"<<sum(x,y)<<std::endl;
        break;
    
    case 2:
        x=readnum();
        y=readnum();
        std::cout<<"El resultado es:"<<resta(x,y)<<std::endl;
        break;

    case 3:
        x=readnum();
        y=readnum();
        std::cout<<"El resultado es:"<<product(x,y)<<std::endl;
        break;

    case 4:
        x=readnum();
        y=readnum();
        std::cout<<"El resultado es:"<<div(x,y)<<std::endl;
        break;

    default:
        std::cout<<"Opción inválida"<<std::endl;
        break;
    }

    return 0;
}