
#include "procesador_petri.h"
#include "monitor.h"

/// Esta funcion por ahora la usemos para probar los distintos metodos que
/// vayamos implementando.
/// \return

int main()
{
    // PRUEBAS DE POLITICA

//    politica_t politica;
//    politica_init(&politica);

//    politica.add_element(&politica,0);
//    politica.add_element(&politica,1);
//    politica.add_element(&politica,2);
//    politica.add_element(&politica,3);
//    politica.add_element(&politica,4);
//    politica.add_element(&politica,5);
//    politica.add_element(&politica,6);
//    politica.add_element(&politica,7);
//
//    politica.modificar_prioridad(&politica,3);
//
//    printf("%i",politica.get_numero_elementos(&politica));

    // PRUEBAS DE LECTOR DE MATRIZ

//    lector_de_matriz_t lector;

//    lector_de_matriz_init(&lector,
//                          "../redes-de-petri/productor-consumidor/incidencia-prod-cons.csv",
//                          "../redes-de-petri/productor-consumidor/marcado-prod-cons.csv");

//    lector.leer(&lector);
    procesador_petri_t petri;
    procesador_de_petri_init(&petri);

    monitor_t monitor;
    monitor_init(&monitor, &petri);

    monitor.disparar(&monitor, 0);
//    int i;
//    pthread_attr_t atrib;
//    pthread_t c[2];
//    pthread_attr_init(&atrib) ;
//    pthread_attr_setscope(&atrib, PTHREAD_SCOPE_SYSTEM);
//    i=pthread_attr_setschedpolicy(&atrib, SCHED_RR);
//    printf("%d\n", i);
//
//    for (i=0;i<2;i++)
//    {
//        pthread_create(&c[i], &atrib,  monitor.disparar, (void*) i);
//    }
//
//    for (i=0;i<2;i++)
//    {
//        pthread_join(c[i], NULL);
//    }



    return 0;
}