#ifndef CIUDADANO_H_INCLUDED
#define CIUDADANO_H_INCLUDED

struct ciudadano;

typedef struct ciudadano * ciudadanoP;

ciudadanoP crearCiudadano();

void mostrarCiudadano(ciudadanoP c);

void buscarVacuna(ciudadanoP c, char nombreVacuna[30]);

void ordenarVacunasPorLote(ciudadanoP c);


#endif // CIUDADANO_H_INCLUDED
