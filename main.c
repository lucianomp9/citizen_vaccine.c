#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "vacuna.h"
#include "ciudadano.h"
#define VACUNAS 5
int main()
{
    srand(time(0));
    ciudadanoP c = crearCiudadano(); ///Creo el ciudadano.
    mostrarCiudadano(c); ///Muestro el ciuudadano.
    buscarVacuna(c, "sinopharm"); ///Busco las vacuna por parametro.
    ordenarVacunasPorLote(c);
    mostrarCiudadano(c);
    return 0;
}
