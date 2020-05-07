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

void GuardarTareas(Tarea ** tareas, int NTareas);

void ListarTareas(Tarea ** tareas, Tarea ** tareas_Realizadas, int NTareas);

void ListarTareasRyP(Tarea ** tareas, Tarea ** tareas_Realizadas, int NTareas);

Tarea * BuscarTareaID(Tarea ** tareas, Tarea ** tareas_Realizadas, int NTareas);

Tarea * BuscarTareaPalabra(Tarea ** tareas, Tarea ** tareas_Realizadas, int NTareas);

int main(){

    time_t t;
    srand((unsigned) time(&t));

    Tarea ** tareas;

    int NTareas;

    tareas = Interfaz(&NTareas);
    
    GuardarTareas(tareas, NTareas);    //agregue esta funcion y dejo de funcionar

    Tarea ** tareas_Realizadas = (Tarea **) malloc(sizeof(Tarea *) * NTareas);

    ListarTareas(tareas, tareas_Realizadas, NTareas);

    ListarTareasRyP(tareas, tareas_Realizadas, NTareas);

    Tarea * tareaBuscID = (Tarea *)malloc(sizeof(Tarea));

    tareaBuscID = BuscarTareaID(tareas, tareas_Realizadas, NTareas);

    if (tareaBuscID == NULL)
    {
        printf("La tarea con ese ID no existe: ");
    }else
    {
        printf("\n Tarea con id %d: \n", tareaBuscID->TareaID);
        printf("ID: %d\n", tareaBuscID->TareaID);
        printf("Descripcion: %s \n", tareaBuscID->Descripcion);
        printf("Duracion: %d\n", tareaBuscID->Duracion);
    }

    Tarea * tareaBuscPalabra = (Tarea *)malloc(sizeof(Tarea));

    tareaBuscPalabra = BuscarTareaPalabra(tareas, tareas_Realizadas, NTareas);

    if (tareaBuscPalabra == NULL)
    {
        printf("\n\nLa tarea con esa palabra clave no existe \n");
    }else
    {
        printf("\n\nLa tarea con la palabra '%s' es: \n\n", tareaBuscPalabra->Descripcion);
        printf("ID: %d\n", tareaBuscPalabra->TareaID);
        printf("Descripcion: %s\n", tareaBuscPalabra->Descripcion);
        printf("Duracion: %d\n", tareaBuscPalabra->Duracion);
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


void GuardarTareas(Tarea ** tareas, int NTareas){

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
    }
}


void ListarTareas(Tarea ** tareas, Tarea ** tareas_Realizadas, int NTareas){

    printf("\n\nTodas las Tareas: \n\n");
    for (int i = 1; i <= NTareas; i++)  //Muevo las tareas realizadas
    {
        int c = rand() % 2;         //asignador para decidir si la tarea se ralizo o no

        printf("ID: %d\n", (*tareas)->TareaID);
        printf("Descripción: %s\n", (*tareas)->Descripcion);
        printf("Duracion: %d\n", (*tareas)->Duracion);
        printf("\n");

        if (c == 1){                                                            //Muevo TareasR
            *tareas_Realizadas = (Tarea *) malloc(sizeof(Tarea));
            (*tareas_Realizadas)->TareaID = (*tareas)->TareaID;
            int tamanio = strlen(((*tareas)->Descripcion));
            (*tareas_Realizadas)->Descripcion = (char *) malloc(sizeof(char) * tamanio);
            strcpy((*tareas_Realizadas)->Descripcion, (*tareas)->Descripcion);
            (*tareas_Realizadas)->Duracion = (*tareas)->Duracion;
            tareas_Realizadas++;
            *tareas = NULL;
        }
        tareas++;
    }
}


void ListarTareasRyP(Tarea ** tareas, Tarea ** tareas_Realizadas, int NTareas){
    int TP = 0;

    printf("\n------------------------------ \n");
    printf("\n\nTareas Pendientes: \n");

    for (int i = 1; i <= NTareas; i++)      //Tareas Pendientes
    {
        if (*tareas != NULL)
        {
            printf("ID: %d\n", (*tareas)->TareaID);
            printf("Descripción: %s\n", (*tareas)->Descripcion);
            printf("Duracion: %d\n", (*tareas)->Duracion);
            printf("\n");
            TP++;
        }
        tareas++;
    }

    printf("------------------\n\n");
    printf("Tareas Realizadas: \n\n");

    for (int i = 1; i <= NTareas-TP; i++)       //Tareas Realizadas
    {
        printf("ID: %d\n", (*tareas_Realizadas)->TareaID);
        printf("Descripción: %s\n", (*tareas_Realizadas)->Descripcion);
        printf("Duracion: %d\n", (*tareas_Realizadas)->Duracion);
        printf("\n");
        tareas_Realizadas++;
    }
}


Tarea * BuscarTareaID(Tarea ** tareas, Tarea ** tareas_Realizadas, int NTareas){
    int TP = 0;
    int ID;

    printf("\n\nIngrese el ID de la Tarea a Buscar: \n");
    scanf("%d", &ID);

    for (int i = 1; i <= NTareas; i++)
    {
        if (*tareas != NULL)
        {
            if ((*tareas)->TareaID == ID)
            {
                return *tareas;
            }
            TP++;
        }
        tareas++;
    }

    for (int i = 1; i <= NTareas-TP; i++)
    {
        if ((*tareas_Realizadas)->TareaID == ID)
        {
            return *tareas_Realizadas;
        }
        tareas_Realizadas++;
    }

    return NULL;
}

Tarea * BuscarTareaPalabra(Tarea ** tareas, Tarea ** tareas_Realizadas, int NTareas){
    int TP = 0;
    int tamanio;
    
    char * descripcion = (char *) malloc(sizeof(char) * 100);

    printf("\n\nIngrese el la descripcion de la Tarea a Buscar: \n");
    scanf("%s", descripcion);

    for (int i = 1; i <= NTareas; i++)
    {
        if (*tareas != NULL)
        {
            tamanio = strlen(descripcion);
            if (strncmp((*tareas)->Descripcion, descripcion, tamanio) == 0)
            {
                free(descripcion);
                return *tareas;
            }
            TP++;
        }
        tareas++;
    }
    
    for (int i = 1; i <= NTareas-TP; i++)
    {
        tamanio = strlen(descripcion);
        if (strncmp((*tareas_Realizadas)->Descripcion, descripcion, tamanio) == 0)
        {
            free(descripcion);
            return *tareas_Realizadas;
        }
        tareas_Realizadas++;
    }
    
    return NULL;

}
