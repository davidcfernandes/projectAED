#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include "dados.h"
#include "lista_estacionamento.h"


lista_c * criar_nodo(carro c)//Adicionar nodo para carro na lista
{
	lista_c *aux=(lista_c *)malloc((xLugar*yLugar*zLugar)*sizeof(lista_c));//Alocar memoria para os lugares do parque
	aux->c_lista=c;
	aux->next=NULL;
	return aux;
}

void visualizarParque(lista_c **lista){//Visualizar o parque de estacionamento
	lista_c *aux;//Inicializacao das variaveis
	aux = *lista;
	int length = numeroCarros(lista);
	int carroEstacionamentoArray[length];
	int n;
	int a=0;
	int b=0;
	int c=0;
	int lugar=0;
	printf("O numero de carros estacionados e: %d\n",length);
	for(n=0; n<length; n++){//Criar array com todos os lugares para organizar
		if(aux!=NULL){
			carroEstacionamentoArray[n]=aux->c_lista.lugar;
			aux = aux->next;
		}	
	}
	selectionSort(carroEstacionamentoArray, length);//Metodo para organizar array
	n=0;
	for(c; c<zLugar;c++){//Criar a visualizacao do parque
		printf("Piso %d\n",c+1);
		b=0;
		for(b; b<yLugar;b++){
			a=0;
			for(a; a<xLugar;a++){
				printf("%d",++lugar);
				int soma = a+1+b+c;
				if(length!=0){
					for(n=0;n<length;n++){
						if(soma==carroEstacionamentoArray[n]){//Lugar ocupado por um carro
							printf("[0] ");
							break;
						}else{//Lugar livre
							if(n+1==length)
								printf("[L] ");
						}
					};
				}else{
					printf("[L] ");
				}
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("Info: L- Livre, O- Ocupado");
}

void inserirInicio(lista_c **lista, carro c)//Inserir carro no inicio da lista
{
	lista_c *elemento=criar_nodo(c);
	if (*lista == NULL){//Se o inicio da lista estiver vazio adicona-o
		*lista = elemento;
	}
	else{//Se nao for o primeiro passa o primeiro elemento da lista para o proximo
		elemento->next =*lista;
		*lista = elemento;
	}
	system("cls");
}

void inserirFim(lista_c **lista, carro c){//Inserir carro no fim da lista
	lista_c *elemento=criar_nodo(c);
	lista_c *aux;
	aux = *lista;
	if(*lista == NULL){
		*lista = elemento;//Se o inicio da lista estiver vazio adicona-o
	}
	else{
		/* Percorre a lista até encontrar o último elemento */
		while (aux->next != NULL){
			aux = aux->next;
		}
		aux->next = elemento;
	}
}

void listar(lista_c *lista)//Listar todos os carros na lista
{
	lista_c *aux=lista;
	while(aux!=NULL) {//Enquanto houver elementos na lista visualiza o carro
		mostrar_carro(aux->c_lista);
		aux = aux->next;
	}

}

void atribuirLugarParque(carro *c1, lista_c **lista){//Recebe o carro e a lista e atribui um lugar do parque
	lista_c *aux;
	aux = *lista;
	int checkLista;
	int stopFor = 0;
	int a=0;
	int b=0;
	int c=0;
	lugarAtual=1;
	int stop=0;
	while(stop==0){
		for(c; c<zLugar;c++){
			b=0;
			for(b; b<yLugar;b++){
				a=0;
				for(a; a<xLugar;a++){
					verificarLugarNaoOcupado(lista);//Metodo para verificar qual lugar na lista esta vazio
					carroEstacionado->lugar = lugarAtual;
				}
				printf("\n");
			}
			printf("\n");
		}
		stop=1;
		printf("O carro foi estacionado no lugar: %d",carroEstacionado->lugar);
	}
}

void verificarLugarNaoOcupado(lista_c **lista)//Verificar lugares desocupados
{
	lista_c *aux;
	aux = *lista;
	int a = numeroCarros(lista);
	int array[a];
	int n;
	if(a==0){
		lugarAtual=1;
		return;
	}else{
		for(n=0; n<a; n++){
			if(aux!=NULL){
				array[n]=aux->c_lista.lugar;
				aux = aux->next;
			}	
		}
	}
	selectionSort(array, a);//Organizar array criado
	for(n=0; n<=a;n++){
			if(array[n]!=n+1){
				lugarAtual=++n;
				return;
			}
	}
}
void swap(int* xp, int* yp)//Trocar o elemento minimo com o primeiro
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        // Encontrar o elemento minimo do array
        min_idx = i;
        for (j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        swap(&arr[min_idx], &arr[i]);//Trocar o elemento minimo com o primeiro
    }
}
void printArray(int arr[], int size)//Visualizar o array organizado criado
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int removerElemento(lista_c **lista){//Remover carro da lista
	lista_c *aux, *ant;
	int encontrou=0;
	aux = *lista;
	ant = *lista;
	int horaPagamento;
	int minutoPagamento;
	char carroProcurado[10];
	time_t t = time(NULL);
    struct tm tm = *localtime(&t);
	fflush(stdin);
	printf("Indique a matricula do carro que pretende retirar: ");//Indicar a matricula do carro para o remover
	gets(carroProcurado);
	fflush(stdin);
	//Percorre a lista até encontrar o elemento (nó) procurado
	while (encontrou == 0 && aux != NULL){
		if (strcmp(aux->c_lista.matricula,carroProcurado)==0){ //Funcao igual a implementar
			encontrou = 1;
		}else{
			ant = aux;
			aux=aux->next;
		}
	}
	if (encontrou){
		//Verifica se o elemento (no) encontrado e o primeiro da lista
		if (ant == aux && aux == *lista){
			
			aux->c_lista.hs=tm.tm_hour;
	        aux->c_lista.ms=tm.tm_min;
	        aux->c_lista.ss=tm.tm_sec;
	        horaPagamento= ((aux->c_lista.hs)-(aux->c_lista.he))*60;
	        minutoPagamento= (aux->c_lista.ms)-(aux->c_lista.me);
	        if((horaPagamento+minutoPagamento)<=10)
				printf("Montante a pagar: 0.40 euros");
			else{
				printf("Montante a pagar: %0.2f euros",(horaPagamento+minutoPagamento)*0.04);
			}
			*lista = aux->next;
		}
		//Caso o elemento(nó) encontrado nao seja o primeiro da lista
		else{
			aux->c_lista.hs=tm.tm_hour;
	        aux->c_lista.ms=tm.tm_min;
	        aux->c_lista.ss=tm.tm_sec;
	        horaPagamento= ((aux->c_lista.hs)-(aux->c_lista.he))*60;
	        minutoPagamento= (aux->c_lista.ms)-(aux->c_lista.me);
	        if((horaPagamento+minutoPagamento)<=10)//Enviar a fatura do parque
				printf("Montante a pagar: 0.40 euros");
			else{
				printf("Montante a pagar: %0.2f euros",(horaPagamento+minutoPagamento)*0.04);
			}
			ant->next=aux->next;
		}
		//Liberta a memoria alocada
		free(aux);
		aux = NULL;
		return 1;
	}else{//Caso a matricula nao exista
		printf("Nao existem carros estacionados com esta matricula");
	}
	//Retorna zero indicando que o elemento(no) nao foi encontrado
	return 0;
	
}

int numeroCarros(lista_c **lista)//Numero de carros que foram estacionados
{
	lista_c *aux;
	aux = *lista;
    int out = 0;
    while (aux != NULL)
    {
        out++;
        aux = aux->next;
    }
    return out;
}
