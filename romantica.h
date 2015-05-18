#ifndef ROMANTICA_H
#define	ROMANTICA_H

#include <stdlib.h>

#define NOME_MAXLEN 20
#define DESCRIZIONE_MAXLEN 50

struct s_ricetta {
    char nome[NOME_MAXLEN+1];
    char descrizione[DESCRIZIONE_MAXLEN+1];
    int quantitaPomodoro;
    int quantitaMozzarella;
    int conGlutine;
};

typedef struct s_ricetta ricetta;

/**
 * Ordina l'elenco delle ricette in base al nome.
 * @param elenco
 * @param dimensione
 */
void ordina(ricetta elenco[], int dimensione);

ricetta *rialloca(ricetta *elencoCorrente, int dimensioneCorrente);

int scriviCSV(ricetta *elenco, int dimensione, char nomeNormale[], char nomeSenzaGlutine[]);

/**
 * Scrive l'intestazione (prima riga) del file CSV
 * @param f
 */
void scriviIntestazioneCSV(FILE *f);


int scriviGlutineCSV(FILE *f, int conGlutine, ricetta elenco[], int dimensione);

/**
 * Scrive una singola ricetta nel file in formato CSV
 * @param f
 * @param r
 */
void scriviRicettaCSV(FILE *f, ricetta r);

#endif	/* ROMANTICA_H */

