#include <stdio.h>
#include <stdlib.h>

struct Nodo
{
    int dato;
    struct Nodo *siguiente;
};

struct ListaSimp
{
    struct Nodo *com;    
    int cant;           
    struct Nodo *actual;
};

void inicializarLista(struct ListaSimp *lista)
{
    lista->com = NULL;
    lista->cant = 0;
    lista->actual = NULL;
}

void agregarAlPrincipio(struct ListaSimp *lista, int valor)
{
    struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    

    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = lista->com;
    lista->com = nuevoNodo;
    lista->cant++;
    lista->actual = nuevoNodo; 
}

void insertarDespuesDelActual(struct ListaSimp *lista, int valor)
{

    struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevoNodo == NULL)
    {
        perror("Error al asignar memoria para el nodo");
        exit(1);
    }

    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = lista->actual->siguiente;
    lista->actual->siguiente = nuevoNodo;
    lista->cant++;
    lista->actual = nuevoNodo; 
}

void insertarAntesDelActual(struct ListaSimp *lista, int valor)
{
    if (lista->actual == NULL)
    {
        printf("Error: El nodo actual no está definido.\n");
        return;
    }

    struct Nodo *nuevoNodo = (struct Nodo *)malloc(sizeof(struct Nodo));
    if (nuevoNodo == NULL)
    {
        perror("Error al asignar memoria para el nodo");
        exit(1);
    }

    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = lista->actual;

    if (lista->com == lista->actual)
    {
        lista->com = nuevoNodo;
    }
    else
    {
        struct Nodo *anterior = lista->com;
        while (anterior->siguiente != lista->actual)
        {
            anterior = anterior->siguiente;
        }
        anterior->siguiente = nuevoNodo;
    }

    lista->cant++;
    lista->actual = nuevoNodo; 
}

void mostrarLista(struct ListaSimp *lista)
{
    struct Nodo *actual = lista->com;
    printf("Lista enlazada simple:\n");
    while (actual != NULL)
    {
        printf("%d -> ", actual->dato);
        actual = actual->siguiente;
    }
    printf("NULL\n");
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

    agregarAlPrincipio(&lista, 5);
    agregarAlPrincipio(&lista, 10);

    lista.actual = lista.com;

    insertarDespuesDelActual(&lista, 7);

    insertarAntesDelActual(&lista, 15);

    mostrarLista(&lista);

    liberarLista(&lista);

    return 0;
}
