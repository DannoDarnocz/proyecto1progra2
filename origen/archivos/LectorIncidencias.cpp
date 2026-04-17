//
// Created by Daniel on 17/04/2026.
//

#include "../../cabeceras/archivos/LectorIncidencias.h"
#include "../../cabeceras/excepciones/ErrorArchivoLectura.h"

ListaIncidencia* LectorIncidencias::leerArchivo(string nombreArchivo) const
{
    ifstream f(nombreArchivo);

    if (!f)
    {
        throw ErrorArchivoLectura(nombreArchivo);
    }

    ListaIncidencia* lista = new ListaIncidencia();
    while (f.good())
    {
        int severidad;
        f >> severidad;
        //nullptr porque aun no se asigna a ninguna, y dia 0 porque es cuando empieza la simulacion
        Incidencia* incidencia = new Incidencia(nullptr,severidad,0);
        lista->insertarFinal(incidencia);
    }

    return lista;
}
