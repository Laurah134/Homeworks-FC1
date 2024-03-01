#include<iostream>
#include<cstdlib>
int main()
{
    //Declaración Variables
    int opcion, num1, num2;
    int repetir=1;
    float resultado;

    //inicio del ciclo
    while(repetir==1)
    {
        //Ingreso de variables
        system("cls");
        std::cout<<"Ingrese el primer número"<<std::endl;
        std::cin>>num1;
        std::cout<<"Ingrese el segundo número"<<std::endl;
        std::cin>>num2;
        system("cls");

        //Opción de menú
        std::cout<<":::::::::::MENU::::::::::::"<<std::endl;
        std::cout<<"   "<<std::endl;
        std::cout<<"\t 1.Sumas\n\t 2.Resta\n\t 3.Producto\n\t 4.División\n\t 5.Modulo"<<std::endl;
        std::cout<<"  "<<std::endl;

        //Operación elegida
        std::cout<<"Indique la operación que desea realizar con los dos número ingresados"<<std::endl;
        std::cin>>opcion;

        //Revisar que la operación elegida este dentro de la opciones
        if(opcion<1 || opcion>5)
        {
            std::cout<<"Por favor ingrese un número que este dentro de las opciones del menu"<<std::endl;
        }

        if(opcion>=1 && opcion<=5 )
        {
            //Resultado de la opción elegida
            if (opcion==1)
            {
                resultado=num1+num2;
                std::cout<<"La suma de "<<num1<<" y "<<num2<<" es "<<resultado<<std::endl;

            }
            
            if(opcion==2)
            {
                resultado=num1-num2;
                std::cout<<"La resta de "<<num1<<" y "<<num2<<" es "<<resultado<<std::endl;
            }

            if(opcion==3)
            {
                resultado=num1*num2;
                std::cout<<"El producto de "<<num1<<" y "<<num2<<" es "<<resultado<<std::endl;
            }

            if(opcion==4)
            {
                if(num2==0)
                {
                    std::cout<<"Recuerde que no se puede dividir entre cero"<<std::endl;
                }
                if(num2!=0)
                {
                    resultado= static_cast<float>(num1)/num2;
                    std::cout<<"La división de "<<num1<<" y "<<num2<<" es "<<resultado<<std::endl;   
                }
            }

            if(opcion==5)
            {
                if(num2==0)
                {
                    std::cout<<"Recuerde que no se puede dividir entre cero"<<std::endl;
                }
                if(num2!=0)
                {
                resultado=num1%num2;
                std::cout<<"El modulo de "<<num1<<" y "<<num2<<" es "<<resultado<<std::endl;
                }

            }

            //revisar si num1 es par
            if(num1%2==0)
            {
                std::cout<<"El primer número ingresado "<<num1<<" es par "<<std::endl;
            }
            if(num1%2!=0)
            {
                std::cout<<"El primer número ingresado "<<num1<<" es impar "<<std::endl;
            }

        }

        //Verificar si se desea continuar haciendo operaciones
        std::cout<<"---------------------------------------------------------------------------------------------- "<<std::endl;
        std::cout<<"Ingrese si desea hacer mas operaciones: "<<std::endl;
        std::cout<<"1.Hacer más operaciones\n2. Salir"<<std::endl;
        std::cin>>repetir;
        if(repetir!=1)
        {
            return 0;
        }
    }
    return 0;
}


