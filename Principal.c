#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "Metodos.h"

int main()
{
    int tam,opcion;
    ColaLineal *cl;
    ColaCircular *cc;
    Pila *p;
    Muestra aux;

    printf("Cuantas muestras quiere tener como maximo en las muestras de entrada? ");
    scanf("%d",&tam);

    //Creamos la cola lineal
    cl=(ColaLineal*)malloc(sizeof(ColaLineal));
    cl->arreglo=(Muestra*)malloc(tam*sizeof(Muestra));
    cl->header=-1;
    cl->tail=-1;
    cl->max=tam;

    printf("Cuantas muestras quiere tener como maximo en las muestras analizadas? ");
    scanf("%d",&tam);

    //Creamos la cola circularcl=(ColaLineal*)malloc(sizeof(ColaLineal));
    cc=(ColaCircular*)malloc(sizeof(ColaCircular));
    cc->arreglo=(Muestra*)malloc(tam*sizeof(Muestra));
    cc->header=-1;
    cc->tail=-1;
    cc->max=tam;

    printf("Cuantas muestras quiere tener como maximo en las muestras por entregar? ");
    scanf("%d",&tam);

    //Creamos la pila estatica
    p=(Pila*)malloc(sizeof(Pila));
    p->arreglo=(Muestra*)malloc(tam*sizeof(Muestra));
    p->tope=-1;
    p->max=tam;

    do{
        opcion = Menu("\n1)Generar muestra \n2)Analizar muestra \n3)Liberar muestra \n4)Entregar muestra \n5)Salir \nSeleccione una opcion: ",5);

        switch (opcion) {
            case 1: //Se ingresa una muestra a la cola lineal
                if(ValidaEspacioCL(cl))
                {
                    InsertarCL(cl);
                }
                else
                {
                    printf("\nMuestras de entrada lleno...\n");
                }
                break;
            case 2: //Se ingresa una muestra a la cola circular
                if(ValidaVacioCL(cl))
                {
                        printf("\nNo hay muestras para analizar\n");
                }
                else
                {
                    if(ValidaEspacioCC(cc))
                    {
                        aux=BorrarCL(cl);
                        InsertarCC(cc,aux);
                        printf("\nAnalizada\n");
                    }
                    else
                    {
                        printf("No hay espacio para analizar");
                    }
                }
                break;
            case 3://Se ingresa una mustra a la pila
                if(ValidaVacioCC(cc))
                {
                    printf("\nNo hay muestras para liberar(Verifique si se analizaron)\n");
                }
                else
                {
                    if(ValidaEspacioP(p))
                    {
                        aux = BorrarCC(cc);
                        Push(p,aux);
                        printf("\nLiberada\n");
                    }
                    else
                    {
                        printf("\nNo hay espacio para liberar\n");
                    }
                }
                break;
            case 4://Se saca una muestra de la pila
                if(ValidaVacioP(p))
                {
                        printf("\nNo hay muestras para entregar\n");
                }
                else
                {
                    printf("\nMuestra entregada...\n");
                    aux = Pop(p);
                }
                break;
        }
    }while (opcion != 5);

    return 0;
}
