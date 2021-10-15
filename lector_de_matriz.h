//
// Created by agustin on 14/10/21.
//

#ifndef PTHREAD_MONITOR_IA32_LECTOR_DE_MATRIZ_H
#define PTHREAD_MONITOR_IA32_LECTOR_DE_MATRIZ_H
#endif //PTHREAD_MONITOR_IA32_LECTOR_DE_MATRIZ_H

#ifndef PLAZAS
#define PLAZAS 8
#endif //PLAZAS
#ifndef TRANSICIONES
#define TRANSICIONES 6
#endif //TRANSICIONES

#include <stdio.h>

typedef struct lector_de_matriz_t lector_de_matriz_t;

struct lector_de_matriz_t
{
    int transiciones;
    int plazas;
    int matriz_incidencia[PLAZAS][TRANSICIONES];
    int matriz_estado[PLAZAS];
    void (*leer)(lector_de_matriz_t *lector,
                 char *path_matriz_incidencia,
                 char *path_matriz_estado);
};

void lector_de_matriz_init(lector_de_matriz_t *lector);


