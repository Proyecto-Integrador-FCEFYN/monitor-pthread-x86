#include <stdio.h>
#include <pthread.h>
#define TRANSICIONES 8


typedef struct monitor
{
    pthread_mutex_t entrada;
    pthread_cond_t var_condicion[TRANSICIONES];
    int *red_petri;
} monitor_t;


void monitor_init(monitor_t *monitor);

void monitor_disparar(monitor_t *monitor, int disparo);

int monitor_get_bloqueados(monitor_t *monitor, int d);