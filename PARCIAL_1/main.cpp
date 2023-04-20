#include <iostream>
#include "Funciones.h"

using namespace std;

//VARIABLES GLOBALES
int opcion, opcionR;
int n;
int*** semana = nullptr;



//PROTOTIPO FUNCIONES
void MENUPRINCIPAL(int opcion);
void imprimirSemanaHTD(int*** semana);


//PROTOTIPO FUNCIONES DINAMICAS
int*** registroSemanaHTD();
char*** registrarMaterias();



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

                                     bool repetirR;
                                     do{

                                          cout <<endl;
                                          cout << "***** MENU REGISTRO ****"<<endl;
                                          cout << " 1. Registrar horario HTD "<<endl;
                                          cout << " 2. registrar datos de materia    "<<endl;
                                          cout << " 3. Salir    "<<endl;
                                          cin >> opcionR;


                                        switch (opcionR){
                                               case 1:
                                                     registroSemanaHTD();
                                                     repetirR=true;
                                                    break;

                                               case 2:

                                                     registrarMaterias();
                                                     repetirR=true;
                                                    break;

                                               case 3:

                                                       //sale del menu registro
                                                       repetirR=false;
                                          }
                                      } while (repetirR==true);
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



