//
// Created by axel on 9/4/2026.
//

#include "../../cabeceras/listas/ListaEquipo.h"
#include "../../cabeceras/excepciones/ErrorValor.h"

NodoEquipo* ListaEquipo::buscarPorPos(int pos) {
	if (pos < 0 || pos >= tam) { return nullptr; }
	actual = primero;
	for (int i = 0; i < pos; i++) { actual = actual->sig; }
	return actual;
}


int ListaEquipo::obtenerPos(string id) {
    if (!primero) return -1;
    actual = primero;
    int pos = -1;
    while (actual) {
        ++pos;
        if (actual->getEquipo() && actual->getEquipo()->getId() == id) {
            return pos;
        }
        actual = actual->sig;
    }
    return -1;
}

ListaEquipo::ListaEquipo() : primero(nullptr), actual(nullptr), tam(0) {}

ListaEquipo::~ListaEquipo() {
	while (primero) {
		NodoEquipo* temp = primero;
		primero = primero->sig;
		delete temp->getEquipo();
		actual = primero;
	}
}

NodoEquipo* ListaEquipo::getPrimero() const { return primero; }
int ListaEquipo::getTam() const { return tam; }

// Inserciones
void ListaEquipo::insertarInicio(Equipo* c) {
    NodoEquipo* nuevo = new NodoEquipo();
    nuevo->sig = primero;
    primero = nuevo;
    nuevo->setEquipo(c);
    ++tam;
}

void ListaEquipo::insertarFinal(Equipo* c) {
    NodoEquipo* nuevo = new NodoEquipo();
    if (!primero) {
        primero = nuevo;
    }
    else {
        actual = primero;
        while (actual->sig) actual = actual->sig;
        actual->sig = nuevo;

    }
    nuevo->setEquipo(c);
    ++tam;
}

bool ListaEquipo::insertarPos(int pos, Equipo* c) {
    if (pos < 0 || pos > tam) return false;

    if (pos == 0) {
        insertarInicio(c);
        return true;
    }
    if (pos == (tam)) {
        insertarFinal(c);
        return true;
    }
    NodoEquipo* previo = buscarPorPos(pos - 1);
    if (!previo) return false;

    NodoEquipo* nuevo = new NodoEquipo();
    nuevo->sig = previo->sig;
    previo->sig = nuevo;
    nuevo->setEquipo(c);
    ++tam;
    return true;
}

// Eliminaciones
bool ListaEquipo::eliminarInicio() {
    if (!primero) return false;
    NodoEquipo* temp = primero;
    primero = primero->sig;
    delete temp->getEquipo();
    delete temp;
    --tam;
    return true;
}

bool ListaEquipo::eliminarFinal() {
    if (!primero) return false;
    if (tam == 1) {
        return eliminarInicio();
    }

    NodoEquipo* previo = buscarPorPos(tam - 2);
    NodoEquipo* ultimo = previo->sig;
    previo->sig = nullptr;
    delete ultimo->getEquipo();
    delete ultimo;
    --tam;
    return true;
}

bool ListaEquipo::eliminarPos(int pos) {
    if (!primero) return false;
    if (pos < 0 || pos >= tam) return false;

    if (pos == 0) { return eliminarInicio(); }
    if (pos == (tam-1)) { return eliminarFinal(); }

    actual = primero;
    for (int i = 0; i < pos-1; i++) { actual = actual->sig; }
    NodoEquipo* temp = actual->sig;
    actual->sig = temp->sig;
    delete temp->getEquipo();
    delete temp;
    --tam;
    return true; // Encontrado
}
// Busquedas
NodoEquipo* ListaEquipo::buscarPorId(string id) {
    if (!primero) { return nullptr; }

    //Busca la prioridad double especifica
    actual = primero;
    while (actual) {
        if (actual->getEquipo() && actual->getEquipo()->getId() == id) {
            return actual;
        }
        actual = actual->sig;
    }
    return nullptr;
}


//Ordenamientos
NodoEquipo *ListaEquipo::dividir(NodoEquipo* cabeza) {
    NodoEquipo* rapido = cabeza;
    NodoEquipo* lento = cabeza;

    while (rapido != nullptr && rapido->sig != nullptr) {
        rapido = rapido->sig->sig;
        if (rapido != nullptr) {
            lento = lento->sig;
        }
    }

    NodoEquipo* temporal = lento->getSig();
    lento->sig = nullptr;
    return temporal;
}

NodoEquipo *ListaEquipo::merge(NodoEquipo *primero, NodoEquipo *segundo) {
    if (primero == nullptr) { return segundo;}
    if (segundo == nullptr) { return primero;}

    Equipo* a = primero->getEquipo();
    Equipo* b = segundo->getEquipo();
    if (!a || !b) { return nullptr; }
    if (a->getCriticidad() > b->getCriticidad()) {
        primero->sig = merge(primero->getSig(),segundo);
        return primero;
    } else if (a->getCriticidad() < b->getCriticidad()) {
        segundo->sig = merge(primero,segundo->getSig());
        return segundo;
    } else {
        if (a->getDiaMant() <= b->getDiaMant()) {
            primero->sig = merge(primero->getSig(),segundo);
            return primero;
        }
        else {
            segundo->sig = merge(primero,segundo->getSig());
            return segundo;
        }
    }
}

NodoEquipo *ListaEquipo::mergeSort(NodoEquipo *cabeza) {
    if (!cabeza || !cabeza->sig) { return cabeza;}
    NodoEquipo* mitad = dividir(cabeza);
    cabeza = mergeSort(cabeza);
    mitad = mergeSort(mitad);
    return merge(cabeza,mitad);
}

void ListaEquipo::ordenarPrioridad() {
    actual = primero;
    if (tam==0 || tam==1) return;
    primero = mergeSort(primero);
}

// degradacion
void ListaEquipo::degradarTodos(int dia)
{
    actual = primero;
    // recorrer todos los nodos degradnado
    while (actual)
    {
        actual->getEquipo()->aplicarDegradacion(dia);
        actual = actual->getSig();
    }
}

// toString
string ListaEquipo::toString() {
    if (tam==0) return "No hay equipos registrados";
    stringstream s;
    actual = primero;
    while (actual) {
        s << actual->getEquipo()->toString() << endl;
        actual = actual->sig;
    }
    return s.str();
}
