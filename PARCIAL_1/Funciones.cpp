#include "Funciones.h"
void registro(int codigo, char Materia[], int creditos, int HTD)
{

//    int horaInicio, horaFin,diasSemana,horalimite;

//    cout << "Ingrese la hora de inicio de la materia (en formato de 24 horas): ";
//    cin >> horaInicio;


//    cout << "Ingrese la hora de finalización de la materia (en formato de 24 horas): ";
//    cin >> horaFin;

//    cout << "Ingrese dias : ";
//    cin >> dias;


//    cout << "Ingrese la hora limite de estudio: ";
//    cin >> horalimite;



        // Guardar la información en un archivo de texto
      ofstream archivo("cursos.txt",ios::app); // Abrir el archivo en modo de escritura al final
        if (archivo.is_open()) {
          archivo << codigo<<","<<Materia<<","<<creditos<<","<<HTD;
            //archivo << "Horario: " << horaInicio << " - " << horaFin << endl;

           archivo.close(); // Cerrar el archivo
       }
        else {
          cout << "No se pudo abrir el archivo" << endl;
       }
}

int HTI(int creditos, int HTD)
{ int H_semana= creditos* 48 - HTD;
  int HTI=H_semana/16;
  return HTI;
}
