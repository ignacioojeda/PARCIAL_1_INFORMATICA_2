#include <iostream>
#include "Funciones.h"

using namespace std;

//VARIABLES GLOBALES
int opcion;
int n;
int*** semana = nullptr;



//PROTOTIPO FUNCIONES
void MENUPRINCIPAL(int opcion);
void imprimirSemanaHTD(int*** semana);


//PROTOTIPO FUNCIONES DINAMICAS
int*** registroSemanaHTD();




int main()
{
 MENUPRINCIPAL(opcion);
}


//FUNCIONES
        void MENUPRINCIPAL(int opcion){
        //crecion menu principal
        bool repetir= true;


           do{

                cout <<endl;
                cout << "***** MENU PRINCIPAL ****"<<endl;
                cout << " 1. Registrar "<<endl;
                cout << " 2. Visualizar      "<<endl;
                cout << " 3. Sugerir "<<endl;
                cout << " 4. Salir    "<<endl;
                cin >> opcion;


              switch (opcion){
                     case 1:

                             semana = registroSemanaHTD();

                             repetir=true;
                             break;

                     case 2:

                             if (semana != nullptr) {
                                                 imprimirSemanaHTD(semana);
                                             } else {
                                                 cout << "El horario no ha sido creado todavía." << endl;
                                             }
                             repetir=true;
                             break;

                     case 3:
                             cout<<" aqui se visualiza el horario sugerido con las HTD y las HTI, ademas lo imprime en un archivo de texto..."<<endl;
                             repetir=true;

                             break;
                     case 4:
                             //sale del programa
                             repetir=false;
                }
            } while (repetir==true);

         }



