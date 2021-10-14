#include "monitor.h"

void monitor()
{
    pthread_mutex_init(&entrada, NULL);
    //red de petri
    //politica()
    //variables de condicion
}

void monitor_disparar(int disparo)
{
    pthread_mutex_lock(&entrada);

    //mucho codigo

    pthread_mutex_unlock(&entrada);
}




