#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
 int TareaID; //Numerado en ciclo iterativo
 char *Descripcion; //
 int Duracion; // entre 10 – 100
} Tarea;

Tarea ** Interfaz(int *NTareas);



int main(){

    time_t t;
    srand((unsigned) time(&t));

    Tarea ** tareas;



    int NTareas;

    tareas = Interfaz(&NTareas);

        int cont1 = 0; 
    for (int i = 1; i <= NTareas; i++)  //Guardo todas las tareas en var tarea
    {
        *tareas = (Tarea *) malloc(sizeof(Tarea));
        (*tareas)->TareaID = i;
        printf("Escriba su tarea: ");
        char * aux_descrip = (char *) malloc(sizeof(char) * 100);
        scanf("%s", aux_descrip);
        (*tareas)->Descripcion = (char *) malloc(sizeof(char) * strlen(aux_descrip));
        strcpy((*tareas)->Descripcion, aux_descrip);
        free(aux_descrip);
        (*tareas)->Duracion = 10 + rand() % 91;
        tareas++;
        cont1++;
    }

    tareas -= cont1;

    Tarea ** tareas_Realizadas = (Tarea **) malloc(sizeof(Tarea *) * NTareas);

            int cont2 = 0;
    for (int i = 1; i <= NTareas; i++)  //Muevo las tareas realizadas de tarea a tareas_Realizadas
    {
        int c = rand() % 2; //asignador para decidir si la tarea se ralizo o no

        if (c == 1){
            *tareas_Realizadas = (Tarea *) malloc(sizeof(Tarea));
            (*tareas_Realizadas)->TareaID = (*tareas)->TareaID;
            int tamanio = strlen(((*tareas)->Descripcion));
            (*tareas_Realizadas)->Descripcion = (char *) malloc(sizeof(char) * tamanio);
            strcpy((*tareas_Realizadas)->Descripcion, (*tareas)->Descripcion);
            (*tareas_Realizadas)->Duracion = (*tareas)->Duracion;
            tareas_Realizadas++;
            *tareas = NULL;
            cont2++;
        }
        tareas++;
    }

    tareas -= cont1;
    tareas_Realizadas -= cont2;

    printf("\n\nTareas Pendientes: \n");
    for (int i = 1; i <= cont1; i++)
    {
        if (*tareas != NULL)
        {
            printf("ID: %d\n", (*tareas)->TareaID);
            printf("Descripción: %s\n", (*tareas)->Descripcion);
            printf("Duracion: %d\n", (*tareas)->Duracion);
            printf("\n");
        }
        tareas++;
    }

    printf("------------------\n\n");
    printf("Tareas Realizadas: \n");

    for (int i = 1; i <= cont2; i++)
    {
        printf("ID: %d\n", (*tareas_Realizadas)->TareaID);
        printf("Descripción: %s\n", (*tareas_Realizadas)->Descripcion);
        printf("Duracion: %d\n", (*tareas_Realizadas)->Duracion);
        printf("\n");
        tareas_Realizadas++;
    }


    scanf(" %c");

    return 0;
}



Tarea ** Interfaz(int *NTareas){    //Realizo ademas las reserva

    printf("Ingrese la cantidad de tareas a cargar: \n");
    scanf("%d", NTareas);

    Tarea ** tarea = (Tarea **) malloc(sizeof(Tarea *) * (*NTareas));

    return tarea;
};