#include "Funciones.h"
char*** registro(int num_materias)
{


    char*** Materia = new char**[num_materias]; // reserva de memoria para las materias
    for (int i = 0; i < num_materias; i++) {
        Materia[i] = new char*[7]; // datos de cada materia
        for (int j = 0; j < 7; j++) {
            Materia[i][j] = new char[50];
        }
    }

    // ingresar los datos del Materia en la matriz
    for (int i = 0; i < num_materias; i++) {
        cout << "Ingrese el codigo de la materia " << i+1 << ": ";
        cin >> Materia[i][0];
        cout << "Ingrese el nombre de la materia " << i+1 << ": ";
        cin >> Materia[i][1];
        cout << "Ingrese el numero de creditos de la materia " << i+1 << ": ";
        cin >> Materia[i][2];
        cout << "Ingrese la hora de inicio de la materia " << i+1 << ": ";
        cin >> Materia[i][3];
        cout << "Ingrese la hora de fin de la materia " << i+1 << ": ";
        cin >> Materia[i][4];
        cout << "Ingrese los dias de la semana en que se imparte la materia " << i+1 << ": ";
        cin >> Materia[i][5];
        cout << "Ingrese la hora limite de estudio para la materia " << i+1 << ": ";
        cin >> Materia[i][6];
    }

return Materia;


// liberar la memoria reservada para el Materia
for (int i = 0; i < num_materias; i++) {
    for (int j = 0; j < 7; j++) {
        delete[] Materia[i][j];
    }
    delete[] Materia[i];
}
delete[] Materia;


}

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

void organizarSemana() {

    int*** semana = new int**[7]; // Puntero triple llamado "semana" con 7 punteros dobles
    for (int i = 0; i < 7; i++) {
        semana[i] = new int*[24]; // Cada puntero doble llamado "dia" tiene 24 punteros simples
        for (int j = 0; j < 24; j++) {
            semana[i][j] = nullptr; // Inicializar cada puntero simple a nulo
        }
        char materia;
        int hora;
        do {
            cout << "Ingresa el nombre de la materia para el dia " << i << " (o presiona enter para terminar): ";
            cin.ignore();
            materia = cin.get();
            if (materia != '\n') {
                cout << "Ingresa la hora para la materia " << materia << " del dia " << i << ": ";
                cin >> hora;
                semana[i][hora] = new int(materia); // Almacenar la variable char en el puntero simple correspondiente
            }
        } while (materia != '\n');
        for (int j = 0; j < 24; j++) {
            if (semana[i][j] == nullptr) { // Si el puntero simple es nulo, asignar el valor "---"
                semana[i][j] = new int('-');
            }
        }
    }

}
