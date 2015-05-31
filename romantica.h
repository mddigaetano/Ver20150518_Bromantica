#define MAX_STRLEN 30
#define FNAME_G "glutine.csv"
#define FNAME_NG "noGlutine.csv"

typedef struct s_ricetta{
    char nome[MAX_STRLEN+1];
    char descrizione[MAX_STRLEN+1];
    unsigned int pomodoro;
    unsigned int formaggio;
    char glutine[2];        //  s || n
}ricetta;

typedef struct s_elemento{
    ricetta v;
    struct s_elemento *next;
}elemento;

void allocaRiempi(elemento **nuovo);
void aggiungiOvunque(elemento **primo, elemento *precedente, elemento* nuovo);
void scriviLinea(FILE* file, ricetta daScrivere);
void svuotaLista(elemento *primo);