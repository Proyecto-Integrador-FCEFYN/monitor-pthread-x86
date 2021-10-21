

#ifdef TRANSICIONES
#define CANT_VAR_COND TRANSICIONES
#else 
#define CANT_VAR_COND 8
#define TRANSICIONES 6
#endif

typedef struct politica_t politica_t;

struct politica_t
{
    int prioridad[TRANSICIONES];
    int element_count;
    void (*add_element)(politica_t *politica, int d);
    int (*get_prioridad)(politica_t *politica, int d);
    void (*modificar_prioridad)(politica_t *politica, int d);
    int (*get_numero_elementos)(politica_t *politica);
};

void politica_init(politica_t *politica);





