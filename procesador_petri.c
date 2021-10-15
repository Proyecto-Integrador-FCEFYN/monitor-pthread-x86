#include "procesador_petri.h"

static int matriz_estado_aux[PLAZAS];

static int petri_solicitud_disparo(procesador_petri_t *petri, int t_disparar)
{
    for (int i = 0; i < PLAZAS; ++i)
    {
        matriz_estado_aux[i] = petri->matriz_estado[i] + petri->matriz_incidencia[i][t_disparar];
        if (matriz_estado_aux[i] == -1)
            return 0;
    }
    return 1;
}

static int petri_disparar(procesador_petri_t *petri, int disparo)
{
    if(petri_solicitud_disparo(petri, disparo))
    {
        for (int i = 0; i < PLAZAS; ++i)
        {
            petri->matriz_estado[i] = matriz_estado_aux[i];
        }
        return 1;
    }
    else return 0;
}

void procesador_de_petri_init(procesador_petri_t *petri)
{
    petri->transiciones = TRANSICIONES;
    petri->plazas = PLAZAS;
    petri->solicitud_disparo = petri_solicitud_disparo;
    petri->disparar = petri_disparar;
}