#ifndef VACUNA_H_INCLUDED
#define VACUNA_H_INCLUDED

struct vacuna;

typedef struct vacuna * vacunaP;

vacunaP crearVacuna();

void mostrarVacuna(vacunaP v);

char * getVacuna (vacunaP v);

int getLote(vacunaP v);


#endif // VACUNA_H_INCLUDED
