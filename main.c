#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo
{
    int dato;
    struct Nodo *siguiente;
} Nodo;

typedef struct ListaSimp
{
    struct Nodo *com;
    int cant;
    struct Nodo *actual;
} ListaSimp;

void inicializarLista(struct ListaSimp *lista)
{
    lista->com = NULL;
    lista->cant = 0;
    lista->actual = NULL;
}


void insertarDespuesDelActual( ListaSimp *lista, int valor)
{

    struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    nuevoNodo->siguiente = NULL;
    nuevoNodo->dato = valor;

    if (lista->com == NULL)
    {
        lista->com = nuevoNodo;
    }
    else
    {
        nuevoNodo->siguiente = lista->actual->siguiente;
        lista->actual->siguiente = nuevoNodo;
    }
    lista->actual = nuevoNodo;
    lista->cant++;
}

// void insertarAntesDelActual(struct ListaSimp *lista, int valor)
// {

//     struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));

//     nuevoNodo->dato = valor;
//     nuevoNodo->siguiente = lista->actual;

//     if (lista->com == lista->actual)
//     {
//         lista->com = nuevoNodo;
//     }
//     else
//     {
//         struct Nodo *anterior = lista->com;
//         while (anterior->siguiente != lista->actual)
//         {
//             anterior = anterior->siguiente;
//         }
//         anterior->siguiente = nuevoNodo;
//     }

//     lista->cant++;
//     lista->actual = nuevoNodo;
// }
void esListaVacia(struct ListaSimp *lista){
    if(lista->cant == 0){
        printf("La lista se encuentra vacía");
    }
}
void mostrarLista(struct ListaSimp *lista)
{
    struct Nodo *p = lista->com;
    printf("Lista enlazada simple:\n");
    while (p != NULL)
    {
        printf("%d -> ", p->dato);
        p = p->siguiente;
    }
}

void liberarLista(struct ListaSimp *lista)
{
    struct Nodo *actual = lista->com;
    while (actual != NULL)
    {
        struct Nodo *siguiente = actual->siguiente;
        free(actual);
        actual = siguiente;
    }
    lista->com = NULL;
    lista->cant = 0;
    lista->actual = NULL;
}

int main()
{
    struct ListaSimp lista;
    inicializarLista(&lista);
    
   
    insertarDespuesDelActual(&lista,5);
    mostrarLista(&lista);

    return 0;
}
