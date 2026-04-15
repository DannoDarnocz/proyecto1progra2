//
// Created by axel on 9/4/2026.
//

#ifndef PROYECTO_1_LISTA_H
#define PROYECTO_1_LISTA_H
#include <iostream>
#include "NodoEquipo.h"
using namespace std;

class ListaEquipo {
private:
    NodoEquipo* primero;
    NodoEquipo* actual;
    int tam;
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

    // Búsquedas
    NodoEquipo* buscarPorId(string); //Busqueda Binaria por prioridad
    NodoEquipo* buscarPorPos(int); // Busca por posición

    //Ordenamiento
    bool ordenarPrioridad();

    //degradacion
    void degradarTodos(int dia);
};


#endif //PROYECTO_1_LISTA_H