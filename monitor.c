#include "monitor.h"
#include "macros.h"


static int log(int disparo)
{
    FILE *f = fopen("../file.txt", "a" );
    if (f == NULL)
    {
        printf("Error opening file!\n");
        return -1;
    }
    fprintf(f,"%i\n", disparo);
    printf("%i\n",disparo);
    fclose(f);
    return 1;
}

int monitor_get_bloqueados(monitor_t *monitor, int d)
{
    return monitor->var_condicion[d].bloqueados;
}

void monitor_disparar2(monitor_t *monitor, int disparo)
{
    pthread_mutex_lock(&monitor->entrada);

    int k = monitor->petri->solicitud_disparo(monitor->petri, disparo);
//  if (k == 0) // 0 si no se pudo disparar
    while (k == 0)
    {
#if DEBUG
        printf("No Sensibilizada: %i -- espera\n", disparo);
#endif
        pthread_cond_wait(&monitor->condition[disparo], &monitor->entrada);
        k = monitor->petri->solicitud_disparo(monitor->petri, disparo);
    }
    monitor->petri->disparar(monitor->petri, disparo);
#if LOG
    log(disparo);
#endif
#if DEBUG
    printf("Si sensibilizada: %i -- disparo\n",disparo);
        monitor->petri->toString(monitor->petri);
#endif
    for (int i = 0; i < TRANSICIONES; ++i)
    {
//            pthread_cond_broadcast(&monitor->condition[i]);
        pthread_cond_signal(&monitor->condition[i]);
    }
    pthread_mutex_unlock(&monitor->entrada);
}

void monitor_init(monitor_t *monitor, procesador_petri_t *petri)
{
    pthread_mutex_init(&monitor->entrada, NULL);
    politica_init(&monitor->politica);
    for (int i = 0; i < TRANSICIONES; ++i)
    {
        pthread_cond_init(&monitor->condition[i], NULL);
        vcondicion_init(&monitor->var_condicion[i], &monitor->entrada);
        monitor->politica.add_element(&monitor->politica,i);
    }
    monitor->petri = petri;
    monitor->disparar = monitor_disparar2;
    monitor->get_bloqueados = monitor_get_bloqueados;
}

void vcondicion_delay(variable_condicion_t *condicion)
{
    condicion->bloqueados++;
    pthread_cond_wait(&condicion->var_condicion, condicion->mutex);
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
