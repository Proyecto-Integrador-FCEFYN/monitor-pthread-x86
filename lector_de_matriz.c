//
// Created by agustin on 14/10/21.
//
#define BUFFER_LINEA 3*PLAZAS+1


#include <string.h>
#include <stdlib.h>
#include "lector_de_matriz.h"

static void leer_linea(char arreglo[BUFFER_LINEA], long int marcado[PLAZAS])
{
    int i = 0;
    //char arreglo[BUFFER_LINEA];
    //    FILE *fptr;
    //    fptr = fopen("/home/agustin/esp/pthread-monitor-ia32/redes-de-petri/productor-consumidor/marcado-prod-cons.csv","r");
    //    fgets(arreglo, sizeof arreglo, fptr);

    char *p = strtok(arreglo, ",");

    while (p != NULL)
    {
        marcado[i] = strtol(p, NULL, 0);
        p = strtok(NULL, ",");
        printf("\nEntero es p=%li", marcado[i]);
        ++i;
    }

}

static void leer_matriz(char matriz_caracteres[PLAZAS][TRANSICIONES], long int matriz_enteros[PLAZAS][TRANSICIONES])
{


}

void lector_de_matriz_leer(lector_de_matriz_t *lector,
                           char *path_matriz_incidencia,
                           char *path_matriz_estado)
{
    char arreglo[BUFFER_LINEA]; //entrada
    FILE *fptr;
    fptr = fopen("/home/agustin/esp/pthread-monitor-ia32/redes-de-petri/productor-consumidor/marcado-prod-cons.csv","r");
    fgets(arreglo, sizeof arreglo, fptr);
    fclose(fptr);

    long int vector[PLAZAS]; //salida
    leer_linea(arreglo, vector);
    printf("\nhola");
    long int matriz[PLAZAS][TRANSICIONES];
    leer_matriz(matriz);
    printf("\nhola");


    fptr = fopen("/home/agustin/esp/pthread-monitor-ia32/redes-de-petri/productor-consumidor/incidencia-prod-cons.csv","r");




}


void lector_de_matriz_init(lector_de_matriz_t *lector)
{
    lector->plazas = PLAZAS;
    lector->transiciones = TRANSICIONES;
    lector->leer = lector_de_matriz_leer;
}