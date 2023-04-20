#include "Funciones.h"



int HTI(int creditos, int HTD)
{ int H_semana= creditos* 48 - HTD;
  int HTI=H_semana/16;
  return HTI;
}



void visualizaHTD(char ***Materia,int num_materias)
{
    // Guardar la información en un archivo de texto
  ofstream archivo("Materias.txt",ios::app); // Abrir el archivo en modo de escritura al final
    if (archivo.is_open()) {
        for (int i = 0; i < num_materias; i++) {
      archivo << "Materia " << i+1 << ": " << endl << "Codigo: " << Materia[i][0] << endl << "Nombre: " << Materia[i][1] << endl<< "Creditos: " << Materia[i][2] << endl << "Hora de inicio: " << Materia[i][3] << endl;
      archivo << "Hora de fin: " << Materia[i][4] << endl<< "Dias de la semana: " << Materia[i][5] << endl<< "Hora limite de estudio: " << Materia[i][6] << endl<< endl;

}
       archivo.close();
   }
    else {
      cout << "No se pudo abrir el archivo" << endl;}
}





int*** registroSemanaHTD() {
    int*** semana = new int**[7]; // Puntero triple llamado "semana" con 7 punteros dobles
    cout<<"ingrese la hora maxima de estudio por dia en formato 24 horas exacta "<<endl;
    int limiteDia;
    cin >> limiteDia;

    for (int i = 0; i < 7; i++) {
        semana[i] = new int*[24]; // Cada puntero doble llamado "dia" tiene 24 punteros simples


        for (int j = 0; j < 24; j++) {
            if (j >= limiteDia) {
                semana[i][j] = new int[3]; // asignar espacio para  "NNN" de no mas estudio
                semana[i][j][0] = 'N';
                semana[i][j][1] = 'N';
                semana[i][j][2] = '\0'; // termina con un nulo
            } else {
                semana[i][j] = nullptr; // Inicializar cada puntero simple a nulo
            }
        }
        char materia[40];
        int horaI;
        int horaF;
        bool continuar;
        bool receso=true;
        do {
            cin.getline(materia, 40);
            cout << "Ingresa el nombre exacto de la materia para el dia " << i << " (o presiona enter para terminar): ";
            cin.getline(materia, 40);
            if (materia[0] != '\0') {
                cout << "Ingresa la hora de inicio para la materia " << materia << " del dia " << i << ": ";
                cin >> horaI;
                cout << "Ingresa la hora de finalizacion para la materia " << materia << " del dia " << i << ": ";
                cin >> horaF;

                // contar manualmente el número de caracteres en la cadena de caracteres
                int tam = 0;
                while (materia[tam] != '\0') {
                    tam++;
                }
                tam++; // para incluir el caracter nulo '\0'

                for(int d=horaI ;d < horaF; d++){//ciclo que calcula la duracion de cada materia en el dia
                semana[i][d] = new int[tam];
                for (int k = 0; k < tam; k++) {
                    semana[i][d][k] = materia[k]; // copiar cada caracter de la cadena de caracteres en el puntero simple correspondiente
                  }
                }

                cin.ignore();
                cout << "Desea ingresar otra materia para este dia? (S/N): ";
                char respuesta;
                cin >> respuesta;
                if (respuesta == 'N' || respuesta == 'n') {
                    continuar = false;
                }
                else if (respuesta == 'S' || respuesta == 's') {
                    continuar = true;
                }

            } else {
                continuar = false;
            }
        } while (continuar);
        for (int j = 0; j < 24; j++) {
            if (semana[i][j] == nullptr) { // Si el puntero simple es nulo, asignar el valor "---"
                semana[i][j] = new int(45);
            }
        }

        for(int a=11; a<=15;a++){
            if(receso==true){
                if(*semana[i][a]=='-'){
                    semana[i][a] = new int[7]; // asignar espacio para receso
                    semana[i][a][0] = 'R';
                    semana[i][a][1] = 'E';
                    semana[i][a][2] = 'C';
                    semana[i][a][3] = 'E';
                    semana[i][a][4] = 'S';
                    semana[i][a][5] = 'O';
                    semana[i][a][6] = '\0'; // termina con un nulo
                    receso=false;
                    }
              }
        }





    }
    return semana; // Devolver el puntero triple "semana"
}

void imprimirSemanaHTD(int*** semana) {
    for (int i = 0; i < 7; i++) {
        cout << "Dia " << i << endl;
        for (int j = 6; j < 24; j++) {
            cout << j << ": ";
            for (int k = 0; semana[i][j][k] != '\0'; k++) {
                cout << (char)semana[i][j][k];
            }
            cout << endl;
        }
        cout << endl;
    }
}


char*** registrarMaterias(int& numPunterosDobles) {
    // Definimos una variable auxiliar para contar la cantidad de punteros dobles que se han creado
    int i = 0;

    // Creamos un arreglo dinámico para almacenar los punteros dobles
    char*** datosMaterias = new char**[100];

    // Creamos un archivo de texto para almacenar los datos
    ofstream archivo("datosMaterias.txt");

    // Creamos un ciclo para que el usuario pueda registrar las materias que desee
    while (true) {
        // Pedimos al usuario que introduzca el nombre de la materia
        cout << "Introduzca el nombre de la materia (o escriba 'FIN' para salir): ";
        char nombreMateria[50];
        cin >> nombreMateria;

        // Si el usuario escribe 'FIN', salimos del ciclo
        if (nombreMateria[0] == 'F' && nombreMateria[1] == 'I' && nombreMateria[2] == 'N' && nombreMateria[3] == '\0') {
            break;
        }

        // Contamos la cantidad de caracteres del nombre de la materia
        int len = 0;
        while (nombreMateria[len] != '\0') {
            len++;
        }

        // Creamos el puntero doble para almacenar el nombre de la materia y sus créditos
        char** punteroDoble = new char*[2];
        punteroDoble[0] = new char[len + 1];
        for (int j = 0; j <= len; j++) {
            punteroDoble[0][j] = nombreMateria[j];
        }

        // Pedimos al usuario que introduzca los créditos de la materia
        cout << "Introduzca la cantidad de creditos de la materia: ";
        int creditos;
        cin >> creditos;

        // Creamos el puntero simple para almacenar la cantidad de créditos
        int* punteroSimple = new int;
        *punteroSimple = creditos;

        // Asignamos los punteros doble y simple creados a la variable datosMaterias
        datosMaterias[i] = punteroDoble;
        datosMaterias[i][1] = (char*) punteroSimple;

        // Escribimos los datos de la materia en el archivo de texto
        archivo << "Materia " << i+1 << ":" << endl;
        archivo << "Nombre: " << datosMaterias[i][0] << endl;
        archivo << "Creditos: " << *(int*)datosMaterias[i][1] << endl;
        archivo << endl;

        // Incrementamos la variable auxiliar que lleva el conteo de punteros dobles
        i++;
    }

    // Actualizamos el valor de numPunterosDobles
    numPunterosDobles = i;

    // Cerramos el archivo de texto
    archivo.close();

    // Retornamos el arreglo dinámico
    return datosMaterias;
}
