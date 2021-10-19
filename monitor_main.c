
#include <stdio.h>
#include "politica.h"
//#include "procesador_petri.h"
#include "lector_de_matriz.h"

/// Esta funcion por ahora la usemos para probar los distintos metodos que
/// vayamos implementando.
/// \return

int main()
{
    // PRUEBAS DE POLITICA

    politica_t politica;
    politica_init(&politica);

    politica.add_element(&politica,0);
    politica.add_element(&politica,1);
    politica.add_element(&politica,2);
    politica.add_element(&politica,3);
    politica.add_element(&politica,4);
    politica.add_element(&politica,5);
    politica.add_element(&politica,6);
    politica.add_element(&politica,7);

    politica.modificar_prioridad(&politica,3);

    printf("%i",politica.get_numero_elementos(&politica));

    // PRUEBAS DE LECTOR DE MATRIZ

    lector_de_matriz_t lector;

    lector_de_matriz_init(&lector,
                          "/home/agustin/esp/pthread-monitor-ia32/redes-de-petri/productor-consumidor/incidencia-prod-cons.csv",
                          "/home/agustin/esp/pthread-monitor-ia32/redes-de-petri/productor-consumidor/marcado-prod-cons.csv");

    lector.leer(&lector);



    return 0;
}