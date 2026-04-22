#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <iomanip>
#include <limits>
#include <windows.h>
#include "cabeceras/equipos/AllInOne.h"
#include "cabeceras/listas/ListaEquipo.h"
#include "cabeceras/excepciones/ErrorDecimal.h"
#include "cabeceras/excepciones/ErrorNegativo.h"
#include "cabeceras/excepciones/ErrorRango.h"
#include "cabeceras/equipos/Laptop.h"
#include "cabeceras/equipos/ComputadoraEscritorio.h"
#include "cabeceras/excepciones/ErrorArchivo.h"
#include "cabeceras/equipos/Osciloscopio.h"
#include "cabeceras/equipos/Microscopio.h"
#include "cabeceras/archivos/LectorEquipos.h"
#include "cabeceras/archivos/LectorIncidencias.h"
#include "cabeceras/excepciones/ErrorArchivoLectura.h"
using namespace std;

void sorteoIncidencias(ListaEquipo*,int,
    ListaIncidencia*);
void esperarEnter(bool = true);
void limpiarPantalla();
int pedirDato(int,int,bool=true);
void limpiarBufer();

struct Menu
{
    int principal(int equipos, int incidencias)
    {
        cout << "- SISTEMA INTELIGENTE DE MANTENIMIENTO -"<<endl<<endl
        << "Equipos cargados en el sistema: " << equipos <<endl
        << "Incidencias cargadas en el sistema: " << incidencias <<endl	<<endl
        << "   1. Cargar datos desde archivos"<<endl
        << "   2. Agregar equipos manualmente"<<endl
        << "   3. Agregar incidencias manualmente"<<endl
        << "   4. Ver lista de equipos"<<endl
        << "   5. Ver lista de incidencias"<<endl
        << "   6. Ejecutar simulacion"<<endl<<endl;
        return pedirDato(1,6);
    }
};

int main()
{
    ListaEquipo* equipos = new ListaEquipo();
    ListaIncidencia* incidencias = new ListaIncidencia();

    // Menu principal
    bool repetir = true;
    int dato;
    bool cargado = false;

    while (repetir)
    {
        limpiarPantalla();
        Menu menu;
        dato = menu.principal(equipos->getTam(),incidencias->getTam());
        limpiarPantalla();
        switch (dato)
        {
        case 1:
            if (!cargado) {
                LectorEquipos lectorEquipos;
                LectorIncidencias lectorIncidencias;

                try{
                    equipos = lectorEquipos.leerArchivo("../equipos.txt", equipos);
                    incidencias = lectorIncidencias.leerArchivo("../incidencias.txt",incidencias);
                    cout << "Se han cargado los datos con exito." << endl;
                    cargado = true;
                }
                catch (ErrorArchivoLectura& e)
                {
                    cout << e.what() << endl;
                }
            } else { cout << "Los datos ya han sido cargados" << endl; }
            break;
        case 2:
            // agregar nuevo equipo a mano
            while (true)
            {
                cout << "- AGREGAR NUEVO EQUIPO -"<<endl<<endl
                << "Tipos de equipo: " << endl
                << "   1. Laptop"<<endl
                << "   2. Computadora de escritorio"<<endl
                << "   3. Computadora All-In-One"<<endl
                << "   4. Microscopio"<<endl
                << "   5. Osciloscopio"<<endl
                << "   0. Salir"<<endl<<endl;
                dato = pedirDato(0,5);

                if (dato==0) break;

                try {
                    switch (dato)
                    {
                    case 1:
                        equipos->insertarFinal(new Laptop);
                        break;
                    case 2:
                        equipos->insertarFinal(new ComputadoraEscritorio);
                        break;
                    case 3:
                        equipos->insertarFinal(new AllInOne);
                        break;
                    case 4:
                        equipos->insertarFinal(new Microscopio);
                        break;
                    case 5:
                        equipos->insertarFinal(new Osciloscopio);
                        break;
                    }
                    cout<< "Equipo agregado exitosamente."<<endl;
                }
                catch (ErrorValor& e) {
                    cout << e.what()  << endl;
                }
            }
            break;
        case 3: // agregar incidencia
            while (true){
                try
                {
                    string severidad;
                    int s;

                    cout << "Se va a crear una incidencia con ID " << incidencias->getTam()<< endl
                    << "Ingrese la severidad de la incidencia (0- salir, 1- baja, 2- media, 3- alta): ";
                    dato = pedirDato(0,3,false);
                    if (dato==0) break;

                    s=dato-1; // uno menor a lo que se le muestra el usuario
                    Incidencia* nuevaIncidencia = new Incidencia(nullptr,s,0);
                    incidencias->insertarFinal(nuevaIncidencia);
                    cout << "Se ha creado la incidencia con exito. " << endl << endl;
                } catch (ErrorValor& e)
                {
                    cout << e.what() << endl;
                }
            }
            break;
        case 4: // lista equipos
            cout << equipos->toString(0)<<endl;
            break;
        case 5: // lista incidentes
            cout << incidencias->toString()<<endl;
            break;
        case 6: // ejecutar simulacion
            if (equipos->getTam()<3) {
                cout << "Se requiere un minimo de 3 computadoras."<<endl;
            }
            else
            {
                repetir=false;
                continue;
            }
            break;
        }
        esperarEnter();
    }


    // Sorteo inicial de 300 incidencias
    int dia=0;
    sorteoIncidencias(equipos,300,incidencias);
    equipos->ordenarPrioridad(dia);
    cout << equipos->toString(dia);
    cout << "Equipos han sido ordenados y las incidencias han sido sorteadas.\nPresione ENTER para proceder con la simulacion.";
    esperarEnter(false);

    // simulacion
    for (dia=1;dia<=30;dia++)
    {
        //equipos.aplicarDegradacionTodos();
        stringstream resultado;
        cout << " --- DIA " << dia << " ---" <<endl<<endl
        << "Equipos con mayor prioridad"<<endl;


        for (int i=0;i<equipos->getTam()&&i<3;i++)
        {
            Equipo* actual = nullptr;
            NodoEquipo* nodoActual = equipos->buscarPorPos(i+1);
            if (nodoActual) {
                actual = nodoActual->getEquipo();
                cout << actual->toString(dia) << endl;
            }
        }
         cout  <<endl<< endl<<"Presione ENTER para proceder con el mantenimiento.";

        esperarEnter(false);


        // reporte
        resultado << "---- REPORTE DEL DIA " << dia << " ----"<< endl<< endl
            << "Equipos atendidos: 3" << endl
            << "Equipos pendientes de atencion: " << endl
            << "Riesgo global del laboratorio (promedio de prioridades): " << endl;
        cout << resultado.str();
        try
        {
            ofstream f("registros.txt",ios::app);

            if (!f)
            {
                throw ErrorArchivo();
            }

            f << resultado.str();

        }
        catch (ErrorArchivo& e)
        {
            cout << e.what() << endl;
        }

        // finalizar dia
        equipos->ordenarPrioridad(dia);
        cout  << endl<< "Presione ENTER para continuar con el siguiente dia... ";
        esperarEnter(false);
    }
}
/*
void cargarDatosQuemados(ListaEquipo* l)
{
    Equipo* equipoNuevo = nullptr;
    for (int i=0;i<100;i++)
    {
        int tipoRand = rand() % 5;
        int critRand = rand() % 100;

        switch (tipoRand)
        {
        case 0:
            equipoNuevo = new Laptop(critRand,0);
            break;
        case 1:
            equipoNuevo = new ComputadoraEscritorio(critRand,0);
            break;
        case 2:
            equipoNuevo = new AllInOne(critRand,0);
            break;
        case 3:
            equipoNuevo = new Microscopio(critRand,0);
            break;
        case 4:
            equipoNuevo = new Osciloscopio(critRand,0);
            break;
        }
        l->insertarFinal(equipoNuevo);
    }
}
*/
//Función para registrar las incidencias cargadas por primera vez en los equipos de forma automática
void sorteoIncidencias(ListaEquipo* l, int cantidad, ListaIncidencia* inci) {
    try {
        if (cantidad<=0) { throw ErrorNegativo(); }
        NodoEquipo* ne = l->getPrimero();
        NodoIncidencia* ni = inci->getPrimero();
        for (int i=0;i<cantidad;i++) {
            if (!ne) { break;}
            if (!ni) { break;}
            Equipo* E = ne->getEquipo();
            if (!E) { ne = ne->sig; continue;}
            if (E->getCriticidad() <= 100 && E->getCriticidad() > 80) {
                for (int j=0;j<7;j++) {
                    if (!ni) { break;}
                    E->obtenerListaIncidencia()->insertarFinal(ni->getIncidencia());
                    ni = ni->getSig();
                }
            } else if (E->getCriticidad() <= 80 && E->getCriticidad() > 55) {
                for (int j=0;j<5;j++) {
                    if (!ni) { break;}
                    E->obtenerListaIncidencia()->insertarFinal(ni->getIncidencia());
                    ni = ni->getSig();
                }
            } else if (E->getCriticidad() <= 55 && E->getCriticidad() > 30) {
                for (int j=0;j<3;j++) {
                    if (!ni) { break;}
                    E->obtenerListaIncidencia()->insertarFinal(ni->getIncidencia());
                    ni = ni->getSig();
                }
            } else if (E->getCriticidad() <= 30 && E->getCriticidad() > 0) {
                for (int j=0;j<1;j++) {
                    if (!ni) { break;}
                    E->obtenerListaIncidencia()->insertarFinal(ni->getIncidencia());
                    ni = ni->getSig();
                }
            }
            ne = ne->sig;
        }
        cout << "Se han sorteado "  << cantidad << " incidencias correctamente." << endl;
    }
    catch (ErrorNegativo& e) {
        cout << e.what() << endl;
    }
    catch (exception& e) {
        cout << "Ocurrio un error inesperado al sortear las incidencias." << endl;
    }
}
/*
void sorteoIncidencias(ListaEquipo* l, int cantidad, int dia) //Cambiar Nombre funcion
{
    try
    {
        if (cantidad<=0)
        {
            throw ErrorNegativo();
        }

        Incidencia* nueva = nullptr;
        for (int i=0;i<300;i++)
        {
            int pos = rand() % l->getTam();
            Equipo* e = l->buscarPorPos(pos)->getEquipo();
            int severidad = rand() % 3; // 0, 1 o 2
            e->aplicarDegradacion(dia);
        }
    }
    catch (ErrorNegativo& e)
    {
        cout << e.what() << endl;
    }
    catch (exception& e) {
        cout << "Ocurrio un error inesperado al sortear las incidencias." << endl;
    }
}*/

void esperarEnter(bool msg) {
    if (msg) {
        cout << "Presione ENTER para continuar... ";
    }
    cin.clear();
    cin.ignore(100000, '\n');
}

void limpiarPantalla()
{
    system("cls");
    Sleep(100); // tiempo de espera por si acaso
}

int pedirDato(int min, int max, bool mostrarTexto) {
    int opcion;
    if (mostrarTexto) {
        cout << "Ingrese la opcion deseada: ";
    }

    // Repetir hasta que ingrese una opcion valida
    while (true) {
        cin >> opcion;
        // verificar que sea valido
        if (cin.fail()) {
            limpiarBufer();
            cout << "Entrada invalida. Por favor ingrese un numero: ";
            continue;
        }
        if (opcion < min || opcion > max) {
            cout << "Opcion fuera de rango. Ingrese un numero entre " << min << " y " << max << ": ";
            continue;
        }
        limpiarBufer();
        return opcion;
    }
}

void limpiarBufer() {
    cin.clear();
    // "numeric_limits" se usa para indicar la mayor cantidad posible de caracteres a ignorar en el bufer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}