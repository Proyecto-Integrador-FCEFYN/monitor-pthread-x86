#ifdef PETRINET_SIZE
#define CANT_VAR_COND PETRINET_SIZE
#else 
#define CANT_VAR_COND 8
#endif

typedef struct politica
{
    int prioridad[CANT_VAR_COND];
    int element_count;
} politica_t;


void politica_init(politica_t *politica);

void politica_add_element(politica_t *politica, int d);

int politica_get_prioridad(politica_t *politica, int d);

void politica_modificar_prioridad(politica_t *politica, int d);

int politica_get_numero_elementos(politica_t *politica);

