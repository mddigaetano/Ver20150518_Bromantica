#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "romantica.h"

int main(int argc, char** argv) {
    char scelta[] = "s";
    ricetta letto; // recordo impiegato per la lettura dei dati
    ricetta *elencoRicette;
    int dimensioneCorrente = 2; // Dimensione dello spazio allocato
    int nElementi = 0; // Numero elementi effettivamente memorizzati
    int i=0;
    
    elencoRicette = (ricetta *)malloc(dimensioneCorrente *sizeof(ricetta));
    if(elencoRicette == NULL) {
        fprintf(stderr, "Impossibile allocare memoria per elenco (%d byte)\n", dimensioneCorrente *sizeof(ricetta));
        exit(1);
    }
    
    while(!strcmp(scelta, "s")) {
        printf("\nInserisci il nome (max %d caratteri): ", NOME_MAXLEN);
        scanf("\n%[^\n]", letto.nome);
        printf("Inserisci la descrizione (max %d caratteri): ", DESCRIZIONE_MAXLEN);
        scanf("\n%[^\n]", letto.descrizione);
        printf("Inserisci la quantita' di pomodoro in grammi: ");
        scanf("%d", &(letto.quantitaPomodoro));
        printf("Inserisci la quantita' di mozzarella in grammi: ");
        scanf("%d", &(letto.quantitaMozzarella));
        printf("Contiene glutine? (1 si'; 0 no) ");
        scanf("%d", &(letto.conGlutine));

        if(i == dimensioneCorrente) {
            elencoRicette = rialloca(elencoRicette, dimensioneCorrente);
            dimensioneCorrente *= 2;
            if(elencoRicette == NULL) {
                fprintf(stderr, "Impossibile allocare memoria per elenco (%d byte)\n", dimensioneCorrente *sizeof(ricetta));
                exit(2);
            }
        }
        
        elencoRicette[i] = letto;
        i++;
        
        printf("\nVuoi aggiungere un'altra ricetta? (s/n) ");
        scanf("%s", scelta);
        
    }
    
    nElementi = i;
    
    /*
     * E' possibile ordinare tutti gli elementi insieme, sebbene l'elenco contenga
     * ricette con o senza glutine. Infatti, se l'insieme è ordinato, anche un suo
     * qualsiasi sottoinsieme è ordinato.
     */
    ordina(elencoRicette, nElementi);
    
    scriviCSV(elencoRicette, nElementi, "normale.csv", "senzaglutine.csv");
    
    return (EXIT_SUCCESS);
}

