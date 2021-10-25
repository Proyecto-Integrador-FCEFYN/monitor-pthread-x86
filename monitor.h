#include <stdio.h>
#include <pthread.h>
#include "procesador_petri.h"
#include "politica.h"
#include "macros.h"

typedef struct monitor_t monitor_t;

struct monitor_t
{
    pthread_mutex_t entrada;
    pthread_cond_t condition[TRANSICIONES];
    procesador_petri_t *petri;
    void (*disparar)(monitor_t *monitor, int disparo);
};


void monitor_init(monitor_t *monitor, procesador_petri_t *petri);


