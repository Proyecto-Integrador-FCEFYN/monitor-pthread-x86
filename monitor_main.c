
#include <stdio.h>
#include "politica.h"

/// Esta funcion por ahora la usemos para probar los distintos metodos que
/// vayamos implementando.
/// \return

int main()
{
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
    return 0;
}