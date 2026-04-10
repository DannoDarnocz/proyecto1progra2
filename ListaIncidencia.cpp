//
// Created by axela on 9/4/2026.
//

#include "ListaIncidencia.h"

ListaIncidencia::ListaIncidencia() : primero(nullptr), actual(nullptr), tam(0) {}

NodoIncidencia* ListaIncidencia::getPrimero() const { return primero; }
int ListaIncidencia::getTam() const { return tam; }

// Inserciones
void ListaIncidencia::insertarInicio(Equipo* e, int severidad, int dia) {
    NodoIncidencia* nuevo = new NodoIncidencia();
    nuevo->sig = primero;
    primero = nuevo;
    Incidencia* i = new Incidencia(e, severidad, dia);
    nuevo->setIncidencia(i);
    ++tam;
}

bool ListaIncidencia::eliminarTodos() {
    while (primero) {
        NodoIncidencia* temp = primero;
        primero = primero->sig;
        delete temp->getIncidencia();
        delete temp;
        actual = primero;
    }
    return true;
}
