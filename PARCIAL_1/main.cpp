#include <iostream>

using namespace std;

//VARIABLES GLOBALES
int opcion;
int n=1;



//PROTOTIPO FUNCIONES
void MENUPRINCIPAL(int opcion);
void menuAdministrador(int opcion);

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
                             cout<<" se hace el registro de variables dadas por el Usuario..."<<endl;
                             repetir=true;

                            break;

                     case 2:
                             cout<<" aqui se visualiza el horario HTD..."<<endl;
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
