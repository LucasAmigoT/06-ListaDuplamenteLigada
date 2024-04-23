#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
	NO* ant;
};

NO* primeiro = NULL;
NO* ultimo = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void exibirReverso();
void inserirElemento();
void excluirPrimeiroElemento();
void excluirUltimoElemento();
void inserirElementoOrdenado();
void excluirElemento();
NO* posicaoElemento(int numero);

//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 8) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Inserir elemento \n";
		cout << "3 - Exibir quantidade de elementos \n";
		cout << "4 - Exibir elementos  \n";
		cout << "5 - Exibir elementos na ordem reversa \n";
		cout << "6 - Excluir primeiro elemento \n";
		cout << "7 - Excluir ultimo elemento \n";
		cout << "8 - Inserir elemento Ordenado\n";
		cout << "9 - Excluir elemento \n";
		cout << "10 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2:inserirElemento();
			break;
		case 3: exibirQuantidadeElementos(); 
			break;
		case 4: exibirElementos();
			break;
		case 5: exibirReverso();
			break;
		case 6: excluirPrimeiroElemento();
			break;
		case 7: excluirUltimoElemento();
			break;
		case 8:inserirElementoOrdenado();
			break;
		case 9:excluirElemento();
			break;
		case 10:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista ja possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	ultimo = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;
	novo->ant = NULL;

	if (primeiro == NULL)
	{
		primeiro = novo;
		ultimo = novo;
	}
	else
	{
		novo->ant = ultimo;
		ultimo->prox = novo;
		ultimo = novo;
	}
}


// funções a serem implementadas no exericio
void exibirReverso()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = ultimo;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->ant;
		}
	}
}

void excluirPrimeiroElemento()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else{
		NO* aux = primeiro;
		primeiro = primeiro->prox;
		if (aux->prox == NULL) {
			primeiro = NULL;
		}
		else {
			aux->prox = primeiro;
			primeiro->ant = NULL;
		}
		free(aux);
	}
}

void excluirUltimoElemento()
{
	if (ultimo == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		NO* aux = ultimo;
		if (aux->ant == NULL) {
			primeiro = NULL;
		}
		else {
			ultimo = ultimo->ant;
			ultimo->prox = NULL;
		}
		free(aux);
	}
}

void inserirElementoOrdenado()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	{
		return;
	}

	cout << "Digite o elemento: ";
	cin >> novo->valor;
	novo->prox = NULL;
	novo->ant = NULL;

	if (primeiro == NULL)
	{
		primeiro = novo;
		ultimo = novo;
	}
	NO* aux = posicaoElemento(novo->valor);
	if (aux == novo->valor) {
		cout << "numero ja existe!";
	}
	NO* proxNovo = posicaoElemento->prox;
	NO* antNovo = posicaoElemento->ant;
	if(aux< ){
		novo->ant = ultimo;
		ultimo->prox = novo;
		ultimo = novo;
	}
}

void excluirElemento()
{
	if (primeiro == NULL)
	{
		cout << "Lista vazia \n";
		return;
	}
	else
	{
		int excluir;
		cout << "Digite o valor que deseja excluir: ";
		cin >> excluir;
		NO* buscaExcluir = posicaoElemento(excluir);
		if (buscaExcluir != NULL)
		{
			if (buscaExcluir == primeiro)
			{
				primeiro = buscaExcluir->prox;
			}
			else
			{
				NO* aux = primeiro;
				while (aux != buscaExcluir)
				{
					aux = aux->prox;
				}
				NO* antExcluir = buscaExcluir->ant;
				NO* proxExcluir = buscaExcluir->prox;

				antExcluir->prox = buscaExcluir->prox;
				proxExcluir->ant = buscaExcluir->ant;


			}
			free(buscaExcluir);
		}
		else
		{
			cout << "Este elemento nao esta na lista \n";
		}
	}
}

NO* posicaoElemento(int numero)
{
	NO* aux = primeiro;
	while (aux != NULL) {
		if (aux->valor == numero)
		{
			break;
		}
		aux = aux->prox;
	}
	return aux;
}




