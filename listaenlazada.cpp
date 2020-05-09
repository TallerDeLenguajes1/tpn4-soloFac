#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct{
    int TareaID;
    char *Descripcion;
    int Duracion;
}Tarea;

typedef struct{
    Tarea T;
    Nodo *Next;
}Nodo;

Nodo * CrearListaVacia();
Nodo * CrearNodo();
void InsertarNodoALista(Nodo ** nodo, Nodo ** Start);

int main(){

    time_t t;
    srand((unsigned) time(&t));

    Nodo * Start = (Nodo *) malloc(sizeof(Nodo));
    Start = CrearListaVacia();



    return 0;
}

Nodo * CrearListaVacia(){
    return NULL;
}

Nodo * CrearNodo(){
    Nodo * NN = (Nodo *) malloc(sizeof(Nodo));
    NN->Next = NULL;
    return NN;
}

void InsertarNodoALista(Nodo ** NN, Nodo ** Start){
    (*NN)->Next = *Start;
    *Start = *NN;
}

