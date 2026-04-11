#include <iostream>
#include "ListaEquipo.h"
#include "ErrorDecimal.h"
#include "ErrorNegativo.h"
#include "Laptop.h"
#include "ComputadoraEscritorio.h"
using namespace std;

ListaEquipo* cargarDatosQuemados(ListaEquipo* lista); // 100 equipos generados automaticamente

int main()
{
    ListaEquipo* equipos = new ListaEquipo();
    equipos = cargarDatosQuemados(equipos);

    // Menú principal
    bool repetir = true;
    string dato;

    while (repetir)
    {
        system("cls");
        cout << "— SISTEMA INTELIGENTE DE MANTENIMIENTO —"<<endl<<endl
        << "Equipos cargados en el sistema:" << equipos->getTam() <<endl		// por defecto son 100
        << "   1. Ingresar nuevos dispositivos"<<endl
        << "   2. Ejecutar simulacion"<<endl<<endl
         << "Escriba el numero de la opcion: ";

        getline(cin,dato);
        if (dato=="2")
        {
            repetir = false;
        }
        else if (dato=="1")
        {
            // agregar nuevo equipo a mano
            while (dato!="0")
            {
                system("cls");
                cout << "— AGREGAR NUEVO EQUIPO —"<<endl<<endl
                << "Tipos de equipo: " << endl
                << "   1. Laptop"<<endl
                << "   2. Computadora de escritorio"<<endl
                << "   3. Microscopio"<<endl
                << "   4. Osciloscopio"<<endl
                << "   0. Salir"<<endl<<endl
                 << "Escriba el numero de la opcion: ";

                getline(cin,dato);
                Equipo* nuevoEquipo = nullptr;
                try
                {
                    switch (dato)
                    {
                    case "1":
                        nuevoEquipo = new Laptop;
                        break;
                    case "2":
                        nuevoEquipo = new ComputadoraEscritorio;
                        break;
                    case "3":
                        nuevoEquipo = new Microscopio;
                        break;
                    case "4":
                        nuevoEquipo = new Osciloscopio;
                        break;
                    }
                }
            }
        }
    }



    for (int dia=1;dia<=30;dia++)
    {

    }
}

ListaEquipo cargarDatos(ListaEquipo* l)
{
    for (int i=0;i<100;i++)
    {
        l->insertarFinal();
    }
}