#include <pthread.h>
#include "procesador_petri.h"
#include "monitor.h"


/// Esta funcion por ahora la usemos para probar los distintos metodos que
/// vayamos implementando.
/// \return

_Noreturn void *tarea(void *arg);

    monitor_t monitor;
int main()
{
    procesador_petri_t petri;
    procesador_de_petri_init(&petri);
    monitor_init(&monitor, &petri);

    long int i;
    pthread_attr_t atrib;
    pthread_t c[TRANSICIONES];
    pthread_attr_init(&atrib) ;
    pthread_attr_setscope(&atrib, PTHREAD_SCOPE_SYSTEM);
    pthread_attr_setschedpolicy(&atrib, SCHED_RR);
    int j;
    j = sched_get_priority_max(SCHED_RR);
    printf("PRIORIDAD MAX %i\n", j);
    j = sched_get_priority_min(SCHED_RR);
    printf("PRIORIDAD MIN %i\n", j);


    for (i=0;i<TRANSICIONES;i++)
    {
        pthread_create(&c[i], &atrib, tarea, (void *) i);
    }
    for (i=0;i<TRANSICIONES;i++)
    {
        pthread_join(c[i], NULL);
    }
    return 4;
}

_Noreturn void *tarea(void *arg)
{
    int miid = (int) arg;
    while (1)
    {
    monitor.disparar(&monitor,miid);
    }
}