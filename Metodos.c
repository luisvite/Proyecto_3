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

int ValidaEspacioCL(ColaLineal *cl)
{
    return(cl->tail<cl->max-1);
}

int ValidaVacioCL(ColaLineal *cl)
{
    return(cl->header==-1);
}

//Metodos para la cola circular
void InsertarCC(ColaCircular *cc,Muestra m)
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
    cc->arreglo[cc->header]=m;
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

int ValidaEspacioCC(ColaCircular *cc)
{
    return !((cc->header&&cc->tail==cc->max)||(cc->tail+1==cc->header));
}

int ValidaVacioCC(ColaCircular *cc)
{
    return (cc->tail==0 || cc->header==-1);
}


//Metodos para la pila estatica
void Push(Pila *p, Muestra m)
{
    p->tope++;
    p->arreglo[p->tope]=m;
}

Muestra Pop(Pila *p)
{
    Muestra aux;
    aux=p->arreglo[p->tope];
    p->tope--;
    return aux;
}

int ValidaEspacioP(Pila *p)
{
    return p->tope<p->max-1;
}

int ValidaVacioP(Pila *p)
{
    return p->tope==-1;
}



