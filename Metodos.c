#include "Metodos.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//Menu
int Menu (char texto[], int n)
{
   int opcion;
   do
   {
       printf("%s ",texto);
       scanf("%d", &opcion);
       if (opcion < 1 || opcion > n)
        printf("Error: opcion no valida...\n");
   }while (opcion < 1 || opcion > n);
   return opcion;
}

//Metodos para la cola lineal
void Insertar(ColaLineal *cl)
{
    if(cl->header==-1)
    {
        cl->header++;
    }
    cl->tail++;
    //Se capturan los datos de la muestra
    printf("\nNombre de la muestra: ");
    fflush(stdin);
    gets(&cl->arreglo[cl->tail].nombre);
    printf("\nClave de la muestra: ");
    scanf("%d",&cl->arreglo[cl->tail].clave );
    printf("\nDepartamento de la muestra: ");
    fflush(stdin);
    gets(&cl->arreglo[cl->tail].depto);
}

Muestra Borrar(ColaLineal *cl)
{
    Muestra aux;
    aux=cl->arreglo[cl->header];
    if(cl->header==cl->tail)
    {
        cl->header=-1;
        cl->tail=-1;
    }
    else
    {
        cl->header++;
    }
    return aux;
}

//Metodos para la cola circular
void InsertarCC(ColaCircular *cc)
{
    if(cc->header==-1)
    {
        cc->header++;
    }
    else if(cc->tail==cc->max-1)
    {
        cc->tail=-1;
    }
    cc->tail++;
    //Se capturan los datos de la muestra
    printf("\nNombre de la muestra: ");
    fflush(stdin);
    gets(&cc->arreglo[cc->tail].nombre);
    printf("\nClave de la muestra: ");
    scanf("%d",&cc->arreglo[cc->tail].clave );
    printf("\nDepartamento de la muestra: ");
    fflush(stdin);
    gets(&cc->arreglo[cc->tail].depto);
}

Muestra BorrarCC(ColaCircular *cc)
{
    Muestra aux;
    aux=cc->arreglo[cc->header];
    if(cc->header==cc->tail)
    {
        cc->header=-1;
        cc->tail=-1;
    }
    else
    {
        cc->header++;
    }
    return aux;
}

//Metodos para la pila estatica
