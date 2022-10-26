#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define DOSIS 5

struct Vacuna {
    char nombre[20];
    char lote[10];
};

struct Ciudadano{
    char nombreYApellido[30];
    int nroCiudadano;
    struct Vacuna vacunas[DOSIS];
};


///Funciones de Vacuna
void cargarVacuna(struct Vacuna v);
void mostrarVacuna(struct Vacuna v);

///Funciones del Ciudadano
void cargarCiudadano(struct Ciudadano c);
void mostrarCiudadano(struct Ciudadano c);
int buscarVacuna(struct Ciudadano c, char nombreVacuna[20]);


int main()
{
    srand(time(0));
    struct Ciudadano c;
    cargarCiudadano(c);
    mostrarCiudadano(c);

    return 0;
}


///Funciones de Vacuna
void cargarVacuna(struct Vacuna v){
    printf("\nIngrese la vacuna...\n");
    fflush(stdin);
    gets(v.nombre);

    char lotesDiccionario[] = "abcdefghijklmnopqrstuvwxyz0123456789";
    int elementosDiccionario = strlen(lotesDiccionario);
    for (int i=0;i<10; i++){
        int randNum = rand() % (elementosDiccionario);
        v.lote[i] = lotesDiccionario[randNum];
    }

};
void mostrarVacuna(struct Vacuna v){
    printf("\nNombre de la vacuna: %s\n", v.nombre);
    printf("\nLote de la vacuna: #%s\n", v.lote);

}

///Funciones del Ciudadano
void cargarCiudadano(struct Ciudadano c){
    printf("\nIngrese el nombre y apellido del ciudadano...\n");
    fflush(stdin);
    gets(c.nombreYApellido);
    c.nroCiudadano = (100000 + rand() % 900000);

    for (int i=0;i<DOSIS; i++){
        cargarVacuna(c.vacunas[i]);
    }

};
void mostrarCiudadano(struct Ciudadano c){
    printf("\nCiudadano: %s\n", c.nombreYApellido);
    printf("\nNumero de ciudadano: %d\n", c.nroCiudadano);
    printf("\n-----VACUNAS-----\n");
     for (int i=0;i<DOSIS; i++){
        mostrarVacuna(c.vacunas[i]);
    }


};
int buscarVacuna(struct Ciudadano c, char nombreVacuna[20]);
