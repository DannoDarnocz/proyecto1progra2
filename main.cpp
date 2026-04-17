#include <iostream>
#include <fstream>
#include <sstream>
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

void cargarDatosQuemados(ListaEquipo* lista); // 100 equipos generados automaticamente
void sortearIncidencias(ListaEquipo*,int,int);

int main()
{
    LectorEquipos lectorEquipos;
    LectorIncidencias lectorIncidencias;

    ListaEquipo* equipos = new ListaEquipo();
    ListaIncidencia* incidencias = new ListaIncidencia();

    try{
        incidencias = lectorIncidencias.leerArchivo("incidencias.txt");
        cout << incidencias->toString();
    }
    catch (ErrorArchivoLectura& e)
    {
        cout << e.what() << endl
        << "Se continuara el sistema sin cargar datos.";
    }


    // Menu principal
    bool repetir = true;
    string dato;

    while (repetir)
    {
        system("cls");
        cout << "- SISTEMA INTELIGENTE DE MANTENIMIENTO -"<<endl<<endl
        << "Equipos cargados en el sistema:" << equipos->getTam() <<endl		// por defecto son 100
        << "Incidencias cargadas en el sistema:" << incidencias->getTam() <<endl		// por defecto son 300
        << "   1. Ingresar nuevos dispositivos"<<endl
        << "   2. Ver lista de dispositivos"<<endl
        << "   3. Ejecutar simulacion"<<endl<<endl
         << "Escriba el numero de la opcion: ";

        getline(cin,dato);
        if (dato=="3")
        {
            repetir = false;
        }
        else if (dato=="2")
        {
            
        }
        else if (dato=="1")
        {
            system("cls");
            cin.clear();
            // agregar nuevo equipo a mano
            while (dato!="0")
            {
                cout << "— AGREGAR NUEVO EQUIPO —"<<endl<<endl
                << "Tipos de equipo: " << endl
                << "   1. Laptop"<<endl
                << "   2. Computadora de escritorio"<<endl
                << "   3. Computadora All-In-One"<<endl
                << "   4. Microscopio"<<endl
                << "   5. Osciloscopio"<<endl
                << "   0. Salir"<<endl<<endl
                 << "Escriba el numero de la opcion: ";

                getline(cin,dato);
                try
                {
                    switch (stoi(dato))
                    {
                    case 1:
                        equipos->insertarInicio(new Laptop);
                        break;
                    case 2:
                        equipos->insertarInicio(new ComputadoraEscritorio);
                        break;
                    case 3:
                        equipos->insertarInicio(new AllInOne);
                        break;
                    case 4:
                        equipos->insertarInicio(new Microscopio);
                        break;
                    case 5:
                        equipos->insertarInicio(new Osciloscopio);
                        break;
                    }
                    system("cls");
                    cout<< "Equipo agregado exitosamente.";
                }
                catch (ErrorValor& e)
                {
                    cout << e.what();
                }
            }
        }
    }

    // ordenar antes de
    equipos->ordenarPrioridad();

    // Sorteo inicial de 300 incidencias
    int dia=0;
    //sortearIncidencias(equipos,300,dia);


    for (dia=1;dia<=30;dia++)
    {
        //equipos.aplicarDegradacionTodos();
        stringstream resultado;


        // reporte
        resultado << "---- DIA " << dia << " ----"<< endl<< endl
            << "Equipos atendidos: 3" << endl
            << "Equipos pendientes de atencion: " << endl
            << "Riesgo global del laboratorio (promedio de prioridades): " << endl;
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

    }
    return 0;
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

void sorteoIncidencias(ListaEquipo* l, int cantidad, int dia)
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

