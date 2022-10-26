#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "vacuna.h"
#define VACUNAS 5

struct vacuna{
    char nombre[20];
    int lote;
};

vacunaP crearVacuna(){
    vacunaP vacuna = malloc(sizeof(struct vacuna));

    printf("\nIngrese el nombre de la vacuna\n");
    fflush(stdin);
    gets(vacuna->nombre);

    printf("\nIngrese el lote\n");
    scanf("%d", &vacuna->lote);

    return vacuna;
}

void mostrarVacuna(vacunaP v){
    printf("\n---------------\n");
    printf("\nVacuna: %s", v->nombre);
    printf("\nLote: #%d\n", v->lote);
};

char * getVacuna (vacunaP v){ ///Getter para poder hacer la busqueda.
    return v->nombre;
};

int getLote(vacunaP v){
    return v->lote;
}
