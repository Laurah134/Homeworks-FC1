#include<iostream>
#include<cmath>
#include<cstdlib>

void suma(){

    int vectorsize;
    float components;


    std::cout<<"Seleccione el tamaño de los vectores (escriba el de mas componentes)"<<std::endl;
    std::cin>>vectorsize;

    float vector1[vectorsize];
    float vector2[vectorsize];
    float vector3[vectorsize];

    for (int i=0; i < vectorsize; i++){
        std::cout<<"Introduzca la componente "<<i+1<<" del vector 1"<<std::endl;
        std::cin>>components;

        vector1[i]=components;
    }
        for (int i=0; i < vectorsize; i++){
        std::cout<<"Introduzca la componente "<<i+1<<" del vector 2"<<std::endl;
        std::cin>>components;

        vector2[i]=components;
    }
    for (int i=0; i < vectorsize; i++){
        vector3[i]=vector1[i]+vector2[i];
        std::cout<<vector3[i]<<std::endl;

    }
}

void resta(){


    int vectorsize;
    float components;


    std::cout<<"Seleccione el tamaño de los vectores (escriba el de mas componentes)"<<std::endl;
    std::cin>>vectorsize;

    float vector1[vectorsize];
    float vector2[vectorsize];
    float vector3[vectorsize];

    for (int i=0; i < vectorsize; i++){
        std::cout<<"Introduzca la componente "<<i+1<<" del vector 1"<<std::endl;
        std::cin>>components;

        vector1[i]=components;
    }
        for (int i=0; i < vectorsize; i++){
        std::cout<<"Introduzca la componente "<<i+1<<" del vector 2"<<std::endl;
        std::cin>>components;

        vector2[i]=components;
    }
    for (int i=0; i < vectorsize; i++){
        vector3[i]=vector1[i]-vector2[i];
        std::cout<<vector3[i]<<std::endl;

    }
}


void escalar(){
    int vectorsize;
    float components;


    std::cout<<"Seleccione el tamaño del vector"<<std::endl;
    std::cin>>vectorsize;

    float vector1[vectorsize];
    float vector3[vectorsize];
    float multiply;

    for (int i=0; i < vectorsize; i++){
        std::cout<<"Introduzca la componente "<<i+1<<" del vector 1"<<std::endl;
        std::cin>>components;

        vector1[i]=components;
    }
    std::cout<<"Seleccione elvalor por el cual quiere multiplicar"<<std::endl;
    std::cin>>multiply;

        for (int i=0; i < vectorsize; i++){
        vector3[i]=vector1[i]*multiply;
        std::cout<<vector3[i]<<std::endl;

    }
}

void punto(){

    int vectorsize;
    float components;
    double sumatory;
    std::cout<<"Seleccione el tamaño de los vectores (escriba el de mas componentes)"<<std::endl;
    std::cin>>vectorsize;

    float vector1[vectorsize];
    float vector2[vectorsize];
    float vector3[vectorsize];


    for (int i=0; i < vectorsize; i++){
        std::cout<<"Introduzca la componente "<<i+1<<" del vector 1"<<std::endl;
        std::cin>>components;

        vector1[i]=components;
    }
        for (int i=0; i < vectorsize; i++){
        std::cout<<"Introduzca la componente "<<i+1<<" del vector 2"<<std::endl;
        std::cin>>components;

        vector2[i]=components;
    }
    for (int i=0; i < vectorsize; i++){
        vector3[i]=vector1[i]*vector2[i];
    }


}


int main(){
    int selection;
    std::cout<<":::::::::::::::Bienvenido a la calculadora de vectores:::::::::::::::"<<std::endl;
    std::cout<<"\t1. SUMA \n\t2. RESTA \n\t3. PRODUCTO POR ESCALAR  \n\t4. PRODUCTO PUNTO \n\t5. PRODUCTO VECTORIAL \n\t6. NORMA \n\t7. PRODUCTO EXTERIOR \n\t8. PRODUCTO GEOMETRICO"<<std::endl;
    std::cout<<"Porfavor, selecciona una de las opciones: "<<std::endl;
    std::cin>>selection;


    if (selection==1){
        system("clear");
        std::cout<<":::::::::::::::USTED HA SELECCIONADO SUMA VECTORIAL:::::::::::::::"<<std::endl;
        suma();
    }
    else if (selection==2)
    {
        system("clear");
        std::cout<<":::::::::::::::USTED HA SELECCIONADO RESTA VECTORIAL:::::::::::::::"<<std::endl;
        std::cout<<"PRECAUCION: la resta se hace entre el vector 1 y el vector 2"<<std::endl;
        resta();
    }

    else if (selection==3)
    {
        system("clear");
        std::cout<<":::::::::::::::USTED HA SELECCIONADO PRODUCTO POR ESCALAR:::::::::::::::"<<std::endl;
        std::cout<<"PRECAUCION: la resta se hace entre el vector 1 y el vector 2"<<std::endl;
        escalar();
    }

    else if (selection==4)
    {
        system("clear");
        std::cout<<":::::::::::::::USTED HA SELECCIONADO PRODUCTO PUNTO:::::::::::::::"<<std::endl;
        punto();
    }

    
    return 0;
}
