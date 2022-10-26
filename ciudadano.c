#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "vacuna.h"
#include "ciudadano.h"
#define VACUNAS 5

struct ciudadano{
    char nombre[30];
    int codeCiudadano;
    vacunaP vacunas[VACUNAS];
};


ciudadanoP crearCiudadano(){
    ciudadanoP c = malloc(sizeof(struct ciudadano));

    printf("\nIngrese el nombre del ciudadano\n");
    fflush(stdin);
    gets(c->nombre);
    c->codeCiudadano = ( 100000 + rand()%900000); ///Numero de 6 cifras aleatorio

    for(int i=0; i<VACUNAS; i++){

        c->vacunas[i] = crearVacuna();
    }

    return c;
};

void mostrarCiudadano(ciudadanoP c){
    printf("\n---------------\n");
    printf("\nNombre del ciudadano: %s\n", c->nombre);
    printf("\nCodigo de ciudadano: %d", c->codeCiudadano);


    for(int i=0; i<VACUNAS; i++){

        mostrarVacuna(c->vacunas[i]); ///Llamo a la funcion mostrar vacuna para mostrar todas
    }

};

void buscarVacuna(ciudadanoP c, char nombreVacuna[30]){
    int flag = -1; ///Flag por si no se encuentra esa vacuna.
    vacunaP aux; ///Aux para guardar la vacuna por si la encuentro.
    for (int i=0; i<VACUNAS; i++){

        if (strcmp(getVacuna(c->vacunas[i]), nombreVacuna)== 0){ ///Comparo los nombres en todas las vacunas, si es = 0, los string son iguales.
            flag = 1; ///Al ser iguales, cambio la flag a 1.

            if (flag == 1){
                aux = (c->vacunas[i]); ///Guardo toda la vacuna para luego mostrarla que la encontre.
                i=VACUNAS; /// Le doy a I el valor de VACUNAS(6) para salir del FOR.
            }
        }
    }
    if (flag==1){ ///Si la Flag es 1, osea que se encontro, muestro la vacuna donde estaba.
        printf("\nLa vacuna %s esta aca:\n", nombreVacuna);
        mostrarVacuna(aux);
    } else{
    printf("\nEl ciudadano no se dio esa vacuna\n"); ///Si la Flag != 1, digo que no se encontro.
    }
};

void ordenarVacunasPorLote(ciudadanoP c){
    vacunaP aux;

    for(int i = 0; i < VACUNAS; i++)
    {
        for(int j=0; j < (VACUNAS - 1); j++ )
        {
            if(getLote(c->vacunas[j]) > getLote(c->vacunas[j+1]))
            {
                aux = c->vacunas[j];
                c->vacunas[j] = c->vacunas[j+1];
                c->vacunas[j+1] = aux;
            }
        }
    }
};
