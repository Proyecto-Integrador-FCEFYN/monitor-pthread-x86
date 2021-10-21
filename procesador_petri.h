#ifndef PROCESADOR_DE_PETRI
#define PROCESADOR_DE_PETRI

#include "lector_de_matriz.h"

typedef struct procesador_petri_t procesador_petri_t;

struct procesador_petri_t
{
    long int matriz_estado[PLAZAS];
    long int matriz_incidencia[PLAZAS][TRANSICIONES];
    int (*solicitud_disparo)(procesador_petri_t *petri, int t_disparar);
    int (*disparar)(procesador_petri_t *petri, int disparo);
};

void procesador_de_petri_init(procesador_petri_t *petri);

#endif //PROCESADOR_DE_PETRI