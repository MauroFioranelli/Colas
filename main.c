#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

typedef struct nodo {
    int dato;
    char nombre[MAX];
    struct nodo *sig;
} tnodo;

typedef struct cola {
    tnodo *pri;
    tnodo *ult;
} tcola;

void inicializar_cola(tcola *cab);
tnodo *genera_nodo(int num, char nom[]);
void poner_en_cola(tcola *cab, int num, char nom[]);
void sacar_de_cola(tcola *cab, int *num, char nom[]);
int cola_vacia(tcola cab);
void mostrar_cola(tcola *cab);

int main() {

    tcola cab;
    inicializar_cola(&cab);
    poner_en_cola(&cab,8,"Juan");
    poner_en_cola(&cab,9,"Pepe");
    poner_en_cola(&cab,6,"fernando");
    poner_en_cola(&cab,2,"felipe");
    mostrar_cola(&cab);

    return 0;
}

void inicializar_cola(tcola *cab) {
    cab->pri = NULL;
    cab->ult = NULL;
}

tnodo *genera_nodo(int num, char nom[]) {
    tnodo *aux = malloc(sizeof(tnodo));
    aux->dato = num;
    strcpy(aux->nombre,nom);
    aux->sig = NULL;
    return aux;
}

void poner_en_cola(tcola *cab, int num, char nom[]) {
    tnodo *nuevo = genera_nodo(num, nom);

    if(cab->pri == NULL) {
        cab->pri = nuevo;
        cab->ult = nuevo;
    } else {
        cab->ult->sig = nuevo;
        cab->ult = nuevo;
    }
}

void sacar_de_cola(tcola *cab, int *num, char nom[]) {
    tnodo *aux = cab->pri;
    cab->pri = aux->sig;
    if(cab->pri == NULL)
        cab->ult = NULL;
    *num = aux->dato;
    strcpy(nom,aux->nombre);
    free(aux);
}

int cola_vacia(tcola cab) {
    return cab.pri == NULL;
}

void mostrar_cola(tcola *cab) {
    tcola *auxiliar = malloc(sizeof(tcola));
    inicializar_cola(auxiliar);
    int num;
    char nom[MAX];
    while(!cola_vacia(*cab)) {
        sacar_de_cola(cab,&num,nom);
        printf("%d %s, ",num,nom);
        poner_en_cola(auxiliar,num,nom);
    }
    while(!cola_vacia(*auxiliar)) {
        sacar_de_cola(auxiliar,&num,nom);
        poner_en_cola(cab,num,nom);
    }
}

