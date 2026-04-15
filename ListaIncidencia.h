//
// Created by axel on 9/4/2026.
//

#ifndef PROYECTO_1_LISTAINCIDENCIA_H
#define PROYECTO_1_LISTAINCIDENCIA_H
#include "NodoIncidencia.h"
#include "Equipo.h"

class Equipo;
class Incidencia;
class NodoIncidencia;

class ListaIncidencia {
private:
    NodoIncidencia* primero;
    NodoIncidencia* actual;
    int tam;
public:
    ListaIncidencia();
    // Gets
    NodoIncidencia* getPrimero() const;
    int getTam() const;

    // Inserciones
    void insertarInicio(Equipo* e, int severidad, int dia); //Crea la Incidencia

    // Eliminaciones
    bool eliminarInicio();  //Usado por EliminarPos
    bool eliminarFinal();   //Usado por EliminarPos
    bool eliminarPos(int pos);       // 0..tam
    bool eliminarTodos(); //Metodo que limpia la colección

    //Buscar
    NodoIncidencia* buscarPorPos(int pos);
};


#endif //PROYECTO_1_LISTAINCIDENCIA_H