#include "politica.h"

void politica_init(politica_t *politica)
{
    for (int i=0;i<CANT_VAR_COND;i++)
        politica->prioridad[i] = 0;
    politica->element_count = 0;
}

void politica_add_element(politica_t *politica, int d)
{
    politica->prioridad[politica->element_count] = d;
    politica->element_count++;
}

void politica_modificar_prioridad(politica_t *politica, int d)
{
    int temp = politica->prioridad[d];
    for(int i=d; i < politica->element_count; i++)
    {
        politica->prioridad[i] = politica->prioridad[i+1];
    }
    politica->prioridad[politica->element_count - 1] = temp;
}

int politica_get_prioridad(politica_t *politica, int d)
{
    return politica->prioridad[d];
}

int politica_get_numero_elementos(politica_t *politica)
{
    return politica->element_count;
}