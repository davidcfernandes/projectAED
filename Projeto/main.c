#include <stdio.h>
#include <stdlib.h>
#include "dados.h"
#include "lista_estacionamento.h"

int main ( int argc, char **argv ) {
	int menuOption; //Opcao do menu principal
	carro c1; //Objeto carro
	int xIntroduzidoCorretamente=0;//Linhas introduzidas
	int yIntroduzidoCorretamente=0;//Colunas introduzidas
	int zIntroduzidoCorretamente=0;//Pisos Introduzidos
	
	lista_c *lista=NULL; //Lista vazia inicialmente
    lista_c *fim=NULL; //Fim da lista vazia
    
    puts("\t\t\t___________________________________________________________________\n");
	puts("\t\t\t                    ESTRUTURA DO PARQUE\n");
	puts("\t\t\t___________________________________________________________________\n");
    
	while(xIntroduzidoCorretamente!=1 || xLugar<0){//Introduzir corretamente as linhas
		printf("Introduza o numero de linhas do parque: ");
		if(scanf("%d",&xLugar) == 1){
			xIntroduzidoCorretamente=1;
		}
		fflush(stdin);
	}

	while(yIntroduzidoCorretamente!=1 || yLugar<0){//Introduzir corretamente as colunas
		printf("Introduza o numero de colunas do parque: ");
		if(scanf("%d",&yLugar) == 1){
			yIntroduzidoCorretamente=1;
		}
		fflush(stdin);
	}
	
	while(zIntroduzidoCorretamente!=1 || zLugar<0){//Introduzir corretamente os pisos
		printf("Introduza o numero de pisos do parque: ");
		if(scanf("%d",&zLugar) == 1){
			zIntroduzidoCorretamente=1;
			system("cls");
		}
		fflush(stdin);
	}
	
	while(menuOption=!0)//Terminar programa se o valor for igual a zero
	{	
		puts("\n\t\t\t___________________________________________________________________\n");
		puts("\t\t\t                             MENU\n");
		puts("\t\t\t___________________________________________________________________\n");
		puts("\t\t\t                      Escolha uma opcao\n\n");
		puts("\t\t\t1. Estacionar Carro");
		puts("\t\t\t2. Listar Carros");
		puts("\t\t\t3. Visualizar Parque");
		puts("\t\t\t4. Retirar Viatura");
		puts("\t\t\t___________________________________________________________________\n");
		puts("\t\t\t0. Sair");
		puts("\t\t\t___________________________________________________________________\n");
		
		if(scanf("%d",&menuOption) != 1){//Verificar o tipo da opcao
			menuOption=-1;
		}
		fflush(stdin);	
		system("cls");
		switch(menuOption){//Escolha do utilizador
			case 0://Sair do programa
			{
				printf("Obrigado por usar o programa");
				return 0;
				break;
			}
			case 1://Estacionar carro
			{
				
				puts("\t\t\t___________________________________________________________________\n");
				puts("\t\t\t                     ESTACIONAR CARRO\n");
				puts("\t\t\t___________________________________________________________________\n");
		
				if(numeroCarros(&lista)>=xLugar*yLugar*zLugar)
					printf("Lotacao maxima do parque de estacionamento foi atingida!");
				else{
					estacionar_carro(&c1, &lista);//Metodo estacionar carro
					atribuirLugarParque(carroEstacionado, &lista);//Atribuir lugar do parque ao carro introduzido
					inserirFim(&lista, *carroEstacionado);//Inserir na da lista
				}
				break;
			}
			case 2:
			{
				puts("\t\t\t___________________________________________________________________\n");
				puts("\t\t\t                     LISTAR CARROS\n");
				puts("\t\t\t___________________________________________________________________\n");
				listar(lista);//Listar os veiculos estacionados
				puts("\n\t\t\t___________________________________________________________________\n");
				break;
			}
			case 3:
			{
				puts("\t\t\t___________________________________________________________________\n");
				puts("\t\t\t                       VISUALIZAR PARQUE\n");
				puts("\t\t\t___________________________________________________________________\n");
				visualizarParque(&lista);//Visualizar disposicao do parque
				puts("\n\t\t\t___________________________________________________________________\n");
				break;
			}
			case 4:
			{
				puts("\t\t\t___________________________________________________________________\n");
				puts("\t\t\t                       REMOVER VIATURA\n");
				puts("\n\t\t\t___________________________________________________________________\n");
				removerElemento(&lista);//Remover carro da lista
				break;
			}
			default://Caso a opcao nao seja valida
			{
				printf("Escolha invalida\n");
				system("cls");
				break;
			}
		};
	}
	return 0;//Terminar programa
}
