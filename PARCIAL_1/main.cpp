#include <iostream>

using namespace std;

//VARIABLES GLOBALES
int opcion;
int n;



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
<<<<<<< HEAD
                             cout<<" se hace el registro de variables dadas por el Usuario..."<<endl;
                             cout<<"Cuantas materias tienes este semestre?  :"<<endl;
                             int n;
                             cin>>n;
=======
                             char Materia[50];
                             int codigo, creditos, HTD;

                                         // Solicitar información al usuario
                                         cout << "Ingrese el codigo de la materia: ";
                                        cin>>codigo;
                                        cin.ignore();
                                         cout << "Ingrese el nombre de la materia: ";
                                        cin.getline(Materia, 50);
                                         cout << "Ingrese creditos de la materia: ";
                                         cin>>creditos;
                                         cout << "Ingrese las horas dictadas por el docente: ";
                                         cin>>HTD;


                                        registro(codigo,Materia,creditos,HTD);
                                        repetir=true;

                             repetir=true;
>>>>>>> 4173c695758b18d2c15803b71df29c44915135f4

                             //LA IDEA ES AQUI PONER A FUNCIONAR LA FUNCION DINAMICA crearMatriz

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

//FUNCIONES DINAMICAS
        char** crearMatriz(int n) {
          // Definir la matriz dinámicamente
          char** matriz = new char*[n];
          for (int i = 0; i < n; i++) {
            matriz[i] = new char[5];
          }

          // Llenar la matriz con datos de entrada proporcionados por el usuario
          for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
              cout << "Ingresa el elemento [" << i << "][" << j << "]: ";
              cin >> matriz[i][j];
            }
          }

          // Retornar la matriz
          return matriz;
        }


