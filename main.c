#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "romantica.h"

int main(int argc, char** argv) {
    char ctrl[] = "s";
    elemento *primo=NULL, *nuovo=NULL, *scorri=NULL, *precedente=NULL;
    FILE *glutine, *noGlutine;
    
    allocaRiempi(& primo);
    printf("Vuoi aggiungere altre ricette? (s/n): ");
    scanf("%s", ctrl);
    
    while(strcmp(ctrl,"n")){
        allocaRiempi(& nuovo);
        
        precedente=NULL;
        scorri=primo;
        while((scorri != NULL) && (strcmp((scorri->v).nome, (nuovo->v).nome)) < 0){
            precedente=scorri;
            scorri = scorri->next;
        }
        aggiungiOvunque(& primo, precedente, nuovo);
        
        printf("Vuoi aggiungere altre ricette? (s/n): ");
        scanf("%s", ctrl);
    }
    
    glutine=fopen(FNAME_G,"w");
    noGlutine=fopen(FNAME_NG,"w");
    
    fprintf(glutine,"nome;descrizione;pomodoro;formaggio;glutine\n");
    fprintf(noGlutine,"nome;descrizione;pomodoro;formaggio;glutine\n");
    
    scorri=primo;
    while(scorri!=NULL){
        if(strcmp((scorri->v).glutine,"s") == 0)
            scriviLinea(glutine,scorri->v);
        else if(strcmp((scorri->v).glutine,"n") == 0)
            scriviLinea(noGlutine,scorri->v);
        
        scorri=scorri->next;
    }
    
    fclose(glutine);
    fclose(noGlutine);
    
    svuotaLista(primo);

    return (EXIT_SUCCESS);
}

