#include<iostream>
#include<cmath>
#include<cstdlib>
int menu()
{
    int selection;
    std::cout<<":::::::::::::::Bienvenido a la calculadora de vectores:::::::::::::::"<<std::endl;
    std::cout<<"\t1. PRODUCTO POR ESCALAR \n\t2. SUMA \n\t3. RESTA   \n\t4. PRODUCTO PUNTO \n\t5. PRODUCTO VECTORIAL \n\t6. NORMA \n\t7. PRODUCTO EXTERIOR \n\t8. PRODUCTO GEOMETRICO"<<std::endl;
    std::cin>>selection;
    return selection; 
}
double readvector1()
{
    double vec1;
    std::cout<<"Ingrese el primer vector:"<<std::endl;
    std::cin>>vec1;
     return (vec1);
}
double readvector2()
{
        double vec2;
        std::cout<<"Ingrese el segundo vector:"<<std::endl;
        std::cin>>vec2;
        return (vec2);
}
double product(double v1, double v2)
{
    return(v1*v2);
}
double suma(double v1, double v2)
{
    return(v1+v2);
}
double resta(double v1, double v2)
{
    return(v1-v2);
}
double productmix(double v1, double v2, double v3, double v4)
{
    return(v1*v2-v3*v4);
}
double norma(double v1, double v2, double v3)
{
    return(sqrt(pow(v1 , 2)+ pow(v2 , 2)+ pow(v3, 2)));
}

int main()
{
    double x1, x2, y1, y2, z1, z2, a;
    x1=readvector1();
    y1=readvector1();
    z1=readvector1();
    x2=readvector2();
    y2=readvector2();
    z2=readvector2();
    switch (menu())
    {
        case 1:
            std::cout<<"Ingresar el valor del escalar por el que desea multiplicar el vector ingresado: "<<std::endl;
            std::cin>>a;
            std::cout<<"El resultado es: "<<product(x1,a)<<","<<product(y1,a)<<","<<product(z1,a)<<std::endl;
            std::cout<<"El resultado es: "<<product(x2,a)<<","<<product(y2,a)<<","<<product(z2,a)<<std::endl;
        break;
        case 2:
            std::cout<<"El resultado es: " <<suma(x1,x2)<<","<<suma(y1,y2)<<","<<suma(z1,z2)<<std::endl;
        break;
        case 3:
            std::cout<<"El resultado es: " <<resta(x1,x2)<<","<<resta(y1,y2)<<","<<resta(z1,z2)<<std::endl;
        break;
        case 4:
            std::cout<<"El resultado es: " <<product(x1,x2)+product(y1,y2)+product(z1,z2)<<std::endl;
        break;
        case 5:
            std::cout<<"El resultado es: "<< productmix(y1,z2,z1,y2)<<","<<productmix(z1,x2,x1,z2)<<","<<productmix(x1,y2,y1,x2)<<std::endl;
        break;
        case 6:
            std::cout<<"El resultado es: "<<norma(x1,y1,z1)<<" y "<<norma(x2,y2,z2)<<std::endl;
        break;
        case 7:
        std::cout<<"El resultado es: "<<productmix(x1,y2,y1,x2)<<" (i∧j), "<<productmix(y1,z2,z1,y2)<<" (j∧k), "<<productmix(z1,x2,x1,z2)<< "(k∧i)"<<std::endl;
        break;
        default:
            std::cout<<"Opción inválida"<<std::endl;
        break;
    }

    return 0;
}


