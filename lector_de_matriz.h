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
#define TRANSICIONES 8
#endif //TRANSICIONES


typedef struct lector_de_matriz
{
    int transiciones;
    int plazas;
    int matriz_incidencia[][];
    int matriz_estado[];
} lector_matriz_t;

void lector_de_matriz_init(lector_matriz_t *lector);

void lector_de_matriz_leer(lector_de_matriz_t *lector,
                           char *path_matriz_incidencia,
                           char *path_matriz_estado);
