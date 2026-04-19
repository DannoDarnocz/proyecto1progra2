//
// Created by axel on 9/4/2026.
//

#ifndef PROYECTO_1_LISTA_H
#define PROYECTO_1_LISTA_H
#include <iostream>
#include <sstream>
#include "NodoEquipo.h"
using namespace std;

class ListaEquipo {
private:
    NodoEquipo* primero;
    NodoEquipo* actual;
    int tam;

    NodoEquipo* dividir(NodoEquipo*);
    NodoEquipo* merge(NodoEquipo*, NodoEquipo*);
    NodoEquipo* mergeSort(NodoEquipo*);
public:
    ListaEquipo();
    ~ListaEquipo();
    // Gets
    NodoEquipo* getPrimero() const;
    int getTam() const;
    int obtenerPos(string); //Devuelve posicion de un Nodo

    // Inserciones
    void insertarInicio(Equipo*); //Usado por InsertPos
    void insertarFinal(Equipo*);  //Usado por InsertPos
    bool insertarPos(int pos, Equipo*);  // 0..tam

    // Eliminaciones
    bool eliminarInicio();  //Usado por EliminarPos
    bool eliminarFinal();   //Usado por EliminarPos
    bool eliminarPos(int pos);       // 0..tam

    // Busquedas
    NodoEquipo* buscarPorId(string); //Busqueda Binaria por prioridad
    NodoEquipo* buscarPorPos(int); // Busca por posicion

    //Ordenamiento
    void ordenarPrioridad();

    //degradacion
    void degradarTodos(int dia);

    //toString
    string toString();
};


#endif //PROYECTO_1_LISTA_H