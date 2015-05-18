#include <stdio.h>
#include <stdlib.h>

#include "romantica.h"

void ordina(ricetta elenco[], int dimensione) {
    ricetta temp;
    int indiceMinore;
    int i, j;
    
    indiceMinore = 0;
    for(i=0; i<(dimensione-1); i++) {
        indiceMinore = i;
        for(j=i+1; j<dimensione; j++) {
            if(strcmp(elenco[j].nome, elenco[indiceMinore].nome) < 0) {
                indiceMinore = j;
            }
        }
        if(indiceMinore != i) {
            temp = elenco[indiceMinore];
            elenco[indiceMinore] = elenco[i];
            elenco[i] = temp;
        }
    }
    return;
}

ricetta *rialloca(ricetta *elencoCorrente, int dimensioneCorrente) {
    ricetta *elencoNuovo = NULL;
    int i;
    
    elencoNuovo = (ricetta *)malloc(2*dimensioneCorrente*sizeof(ricetta));
    if(elencoNuovo != NULL) {
        for(i=0; i<dimensioneCorrente; i++) {
            elencoNuovo[i] = elencoCorrente[i];
        }
        free(elencoCorrente);
    }
    
    return elencoNuovo;
}

int scriviCSV(ricetta elenco[], int dimensione, char nomeNormale[], char nomeSenzaGlutine[]) {
    FILE *normale;
    FILE *senzaGlutine;
    
    int returnCode = 0;
    
    normale = fopen(nomeNormale, "w");
    senzaGlutine = fopen(nomeSenzaGlutine, "w");
    
    if(normale != NULL && senzaGlutine != NULL) {
        scriviIntestazioneCSV(normale);
        scriviIntestazioneCSV(senzaGlutine);

        scriviGlutineCSV(normale, 1, elenco, dimensione);
        scriviGlutineCSV(senzaGlutine, 0, elenco, dimensione);

        fclose(normale);
        fclose(senzaGlutine);
    }
    else {
        returnCode = -1;
        if(normale == NULL)
            fprintf(stderr, "Impossibile aprire il file \"%s\"\n", nomeNormale);
        if(senzaGlutine == NULL)
            fprintf(stderr, "Impossibile aprire il file \"%s\"\n", nomeSenzaGlutine);
    }
    
    return returnCode;
}

void scriviIntestazioneCSV(FILE *f) {
    fprintf(f, "nome;descrizione;pomodoro;mozzarella;con glutine\n");
}

int scriviGlutineCSV(FILE *f, int conGlutine, ricetta elenco[], int dimensione) {
    int i;
    
    for(i=0; i<dimensione; i++) {
        if(elenco[i].conGlutine == conGlutine) {
            scriviRicettaCSV(f, elenco[i]);
        }
    }
    return i;
}
void scriviRicettaCSV(FILE *f, ricetta r) {
    fprintf(f, "%s;%s;%d;%d;%d\n", r.nome, r.descrizione, r.quantitaPomodoro, r.quantitaMozzarella, r.conGlutine);
}
