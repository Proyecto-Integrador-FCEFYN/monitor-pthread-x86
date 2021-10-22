#include <stdio.h>
#include <pthread.h>
#include "procesador_petri.h"
#include "politica.h"
#define TRANSICIONES 6

typedef struct monitor_t monitor_t;
typedef struct variable_condicion_t variable_condicion_t;

struct variable_condicion_t {
    pthread_cond_t var_condicion;
    pthread_mutex_t *mutex;
    int bloqueados;
    void (*delay)(variable_condicion_t *condicion);
    void (*resume)(variable_condicion_t *condicion);
    int (*is_empty)(variable_condicion_t *condicion);
};

struct monitor_t
{
    pthread_mutex_t entrada;
    variable_condicion_t var_condicion[TRANSICIONES];
    pthread_cond_t condition[TRANSICIONES];
    procesador_petri_t *petri;
    politica_t politica;
    void (*disparar)(monitor_t *monitor, int disparo);
    int (*get_bloqueados)(monitor_t *monitor, int d);
};


void monitor_init(monitor_t *monitor, procesador_petri_t *petri);

void vcondicion_init(variable_condicion_t *condicion, pthread_mutex_t *mutex);

