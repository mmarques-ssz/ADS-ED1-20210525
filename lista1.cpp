#include <iostream>
using namespace std;

struct Lista
{
	int dado;
	struct Lista *prox;
};

Lista* init()
{
	return NULL;
}

int isEmpty(Lista* lista)
{
	return (lista==NULL);
}

Lista* insert(Lista* lista, int i)
{
	Lista* novo = new Lista();
	novo->dado = i;
	novo->prox = lista;
	return novo;
}

void print(Lista* lista)
{
	Lista* aux;
	aux = lista;
	while(aux != NULL)
	{
		cout << "Dado: " << aux->dado << endl;
		aux = aux->prox;
	}
	cout << "----------------" << endl;
}

Lista* find(Lista* lista, int i)
{
	Lista* aux;
	aux = lista;
	while (aux != NULL && aux->dado != i)
	{
		aux = aux->prox;
	}
	return aux;
}

Lista* remove(Lista* lista, int i)
{
	Lista *aux;
	Lista *ant = NULL;
	
	aux = lista;
	while (aux != NULL && aux->dado != i)
	{
		ant = aux;
		aux = aux->prox;
	}
	
	if (aux == NULL)
	{
		return lista;
	}
	
	if (ant == NULL) // era o primeiro
	{
		aux = aux->prox;
	}
	else // estava no meio
	{
		ant->prox = aux->prox;
	}
	free(aux);
	return lista;
}

void freeLista(Lista* lista)
{
    Lista *aux;
    aux = lista;
    while (aux != NULL)
	{
		Lista *ant = aux->prox;
		free(aux);
		aux = ant;
	}
}

int main(int argc, char** argv)
{
	Lista *minhaLista;
	minhaLista = init();
	
	// (<bool>?true:false)
	
	cout << "Lista vazia: " << (isEmpty(minhaLista)?"SIM":"NAO") << endl;
	
	minhaLista = insert(minhaLista, 5);
	minhaLista = insert(minhaLista, 10);
	minhaLista = insert(minhaLista, 7);
	
	cout << "Lista vazia: " << (isEmpty(minhaLista)?"SIM":"NAO") << endl;
	
	print(minhaLista);
	
	Lista *procurado = find(minhaLista, 7);
	if (procurado != NULL)
	{
   	    cout << "Dado encontrado: " << procurado->dado << endl;	
	}
	else
	{
		cout << "Dado nao encontrado!" << endl;
	}
	
	cout << "Dado encontrado: " << find(minhaLista, 5)->dado << endl;
	
	minhaLista = remove(minhaLista, 10);
	
	print(minhaLista);
	
    minhaLista = remove(minhaLista, 5);
	
	print(minhaLista);
	
	return 0;
}