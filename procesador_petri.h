#ifndef PROCESADOR_DE_PETRI
#define PROCESADOR_DE_PETRI
#ifndef PLAZAS
#define PLAZAS 8
#endif
#ifndef TRANSICIONES
#define TRANSICIONES 8
#endif

#include "lector_de_matriz.h"

typedef struct procesador_petri_t procesador_petri_t;

struct procesador_petri_t
{
    int transiciones;
    int plazas;
    long int matriz_estado[PLAZAS];
    long int matriz_incidencia[PLAZAS][TRANSICIONES];
    int (*solicitud_disparo)(procesador_petri_t *petri, int t_disparar);
    int (*disparar)(procesador_petri_t *petri, int disparo);
};

void procesador_de_petri_init(procesador_petri_t *petri);








#endif //PROCESADOR_DE_PETRI