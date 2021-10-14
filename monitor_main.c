#include <stdio.h>
#include "politica.h"
#in


int main()
{
    politica_t politica;

    politica_init(&politica);

    politica_add_element(&politica,0);
    politica_add_element(&politica,1);
    politica_add_element(&politica,2);
    politica_add_element(&politica,3);
    politica_add_element(&politica,4);
    politica_add_element(&politica,5);
    politica_add_element(&politica,6);
    politica_add_element(&politica,7);


    politica_modificar_prioridad(&politica,3);

    printf("%i",politica_get_numero_elementos(&politica));



    return 0;
}