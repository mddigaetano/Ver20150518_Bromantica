#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "romantica.h"

void allocaRiempi(elemento **nuovo){
    
    *nuovo=(elemento *)malloc(sizeof(elemento));
    
    (*nuovo)->next=NULL;
    
    printf("\nInserisci il nome della ricetta: ");
    scanf("\n%[^\n]", ((*nuovo)->v).nome);
    printf("Inserisci una descrizione della ricetta: ");
    scanf("\n%[^\n]", ((*nuovo)->v).descrizione);
    printf("Inserisci la quantita' di pomodoro in grammi: ");
    scanf("%d", &(((*nuovo)->v).pomodoro));
    printf("Inserisci la quantita' di formaggio in grammi: ");
    scanf("%d", &(((*nuovo)->v).formaggio));
    printf("Inserisci \"s\" se contiene glutine; altrimenti \"n\": ");
    scanf("%s", ((*nuovo)->v).glutine);
    
    return;
}

void aggiungiOvunque(elemento **primo, elemento *precedente, elemento* nuovo){
    
    if(*primo){
        if(precedente){
            nuovo->next=precedente->next;
            precedente->next=nuovo;
        }
        else{
            nuovo->next=*primo;
            *primo=nuovo;
        }
    }
    else
        *primo=nuovo;
    
    return;
}

void scriviLinea(FILE* file, ricetta daScrivere){
    fprintf(file, "%s;%s;%d;%d,%s\n", daScrivere.nome, daScrivere.descrizione, daScrivere.pomodoro, daScrivere.formaggio, daScrivere.glutine);
    
    return;
}

void svuotaLista(elemento *primo){
    elemento *temp=NULL;
    
    while(primo != NULL){
        temp=primo->next;
        free(primo);
        primo=temp;
    }
    
    return;
}