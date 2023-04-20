#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <fstream>

using namespace std;

int*** registroSemanaHTD();
char*** registrarMaterias(int& numPunterosDobles);
void imprimirSemanaHTD(int*** semana) ;
int HTI(int creditos, int HTD);



#endif // FUNCIONES_H
