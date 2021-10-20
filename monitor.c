#include "monitor.h"


int monitor_get_bloqueados(monitor_t *monitor, int d)
{
    return monitor->var_condicion[d].bloqueados;
}

void monitor_disparar(monitor_t *monitor, int disparo)
{
    //try
    pthread_mutex_lock(&monitor->entrada);
    while ( !monitor->petri->solicitud_disparo(monitor->petri, disparo) )
    {

    }

    //mucho codigo

    pthread_mutex_unlock(&monitor->entrada);
}

void monitor_init(monitor_t *monitor, procesador_petri_t *petri)
{
    pthread_mutex_init(&monitor->entrada, NULL);
    politica_init(&monitor->politica);
    for (int i = 0; i < TRANSICIONES; ++i)
    {
        vcondicion_init(&monitor->var_condicion[i], &monitor->entrada);
        monitor->politica.add_element(&monitor->politica,i);
    }
    monitor->petri = petri;
    monitor->disparar = monitor_disparar;
    monitor->get_bloqueados = monitor_get_bloqueados;
}

void vcondicion_delay(variable_condicion_t *condicion)
{
    condicion->bloqueados++;
    pthread_mutex_unlock(condicion->mutex);

    pthread_cond_wait(&condicion->var_condicion, condicion->mutex);
    // ver manejo de errores.
}
void vcondicion_resume(variable_condicion_t *condicion)
{
    if (condicion->bloqueados>0)
    {
        condicion->bloqueados--;
        pthread_cond_signal(&condicion->var_condicion);
    }
}
int vcondicion_is_empty(variable_condicion_t *condicion)
{
    return condicion->bloqueados==0;
}

void vcondicion_init(variable_condicion_t *condicion, pthread_mutex_t *mutex)
{
    condicion->bloqueados = 0;
    condicion->mutex = mutex;
    condicion->delay = vcondicion_delay;
    condicion->resume = vcondicion_resume;
    condicion->is_empty = vcondicion_is_empty;
}






