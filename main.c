#define REENTRANT
#include <stdio.h>
#include <pthread.h>

#define NumRec 10
#define NumProc 5

pthread_mutex_t mutex ;
pthread_cond_t espera;
int recdis = NumRec;

void pidoRec (int n , int id) 
{
    pthread_mutex_lock(&mutex) ;
    while (recdis < n)
    {
        printf("Trabajador %d pide %d −− espera\n" , id, n);
        pthread_cond_wait(&espera, &mutex );
    }
    recdis = recdis - n;
    printf("Trabajador %d pide %d −− coge \n" , id, n) ;
    pthread_mutex_unlock(&mutex);
}

void devuelvoRec (int n, int id) 
{
    pthread_mutex_lock(&mutex);
    recdis = recdis + n;
    printf("Trabajador %d devuelve %d\n", id, n);
    pthread_cond_broadcast (&espera);
    pthread_mutex_unlock(&mutex);
}

void* cliente(void *arg) {
    int miid = (int) arg;
    int d, i;   
    for (i=0;i<10;i++)
    {
        d = rand() % 10;
        pidoRec (d, miid);
        devuelvoRec (d, miid);
    }      
    pthread_exit(NULL);
}

int main (int argc, char *argv[]) 
{
    int i;
    pthread_attr_t atrib;
    pthread_t c[NumProc];
    pthread_attr_init(&atrib) ;
    pthread_attr_setscope(&atrib, PTHREAD_SCOPE_SYSTEM);
    i=pthread_attr_setschedpolicy(&atrib, SCHED_RR);
    printf("%d\n", i);
    pthread_mutex_init(&mutex, NULL );
    pthread_cond_init(&espera, NULL );
    for (i=0;i<5;i++)
    {
        pthread_create(&c[i], &atrib, cliente, (void*) i);
    }

    for (i=0;i<5;i++) 
    {
        pthread_join(c[i], NULL);
    }
}