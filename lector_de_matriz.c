//
// Created by agustin on 14/10/21.
//



#include <string.h>
#include <stdlib.h>
#include "lector_de_matriz.h"

static void leer_linea(char arreglo[BUFFER_LINEA], long int marcado[PLAZAS])
{
    int i = 0;

    char *p = strtok(arreglo, ",");

    while (p != NULL)
    {
        marcado[i] = strtol(p, NULL, 0);
        p = strtok(NULL, ",");
        printf("\nEntero es p=%li", marcado[i]);
        ++i;
    }
}

void lector_de_matriz_leer(lector_de_matriz_t *lector,
                           long int matriz_estado[PLAZAS],
                           long int matriz_incidencia[PLAZAS][TRANSICIONES])

{
    char arreglo[BUFFER_LINEA]; //entrada
    FILE *fptr;
    fptr = fopen(lector->path_matriz_estado,"r");
    fgets(arreglo, sizeof arreglo, fptr);
    fclose(fptr);

//    long int vector[PLAZAS]; //salida

    printf("\nVector de estado leido");
    leer_linea(arreglo, matriz_estado);

    printf("\nMatriz leida, de a filas");
    char matriz_char[PLAZAS][BUFFER_LINEA]; // entrada
//    long int matriz_entero[PLAZAS][TRANSICIONES]; // salida

    fptr = fopen(lector->path_matriz_incidencia,"r");

    for (int i = 0; i < PLAZAS; ++i) {
        fgets(matriz_char[i], sizeof matriz_char[0], fptr);
        leer_linea(matriz_char[i],  matriz_incidencia[i]);
    }
}


void lector_de_matriz_init(lector_de_matriz_t *lector,
                           char *path_matriz_incidencia,
                           char *path_matriz_estado)
{
    lector->plazas = PLAZAS;
    lector->transiciones = TRANSICIONES;
    lector->path_matriz_estado = path_matriz_estado;
    lector->path_matriz_incidencia = path_matriz_incidencia;

    lector->leer = lector_de_matriz_leer;

}