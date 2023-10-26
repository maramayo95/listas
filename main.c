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
int esListaVacia(struct ListaSimp *lista)
{
    return lista->cant == 0;
}

void insertarDespuesDelActual(ListaSimp *lista, int valor)
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

void insertarAntesDelActual(struct ListaSimp *lista, int valor)
{
    if (!esListaVacia(lista))
    {
        int valorAux = lista->actual->dato;
        lista->actual->dato = valor;
        insertarDespuesDelActual(lista, valorAux);
    } else {
        insertarDespuesDelActual(lista,valor);
    }
}


// void eliminarElemento(struct ListaSimp *lista)
// {
//     if (!esListaVacia(lista))
//     {
//         lista->actual
//     }
// }
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

    insertarDespuesDelActual(&lista, 5);
    insertarDespuesDelActual(&lista, 10);
    insertarAntesDelActual(&lista, 4);
    mostrarLista(&lista);

    return 0;
}
