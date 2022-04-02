#include <stdio.h>
#include "dados.h"
#include "lista_estacionamento.h"
#include <time.h>

int igual (carro c1, carro c2){//Verificar se 2 carros sao iguais
	if(c1.matricula==c2.matricula)
		return 1;
	else
		return 0;
}
int igualMatricula (char c1[10], char c2[10]){//Verfica se duas matriculas sao iguais
	if(c1==c2)
		return 1;
	else
		return 0;
}

void estacionar_carro(carro *c1){//Adicionar um carro
	time_t t = time(NULL);//Utilizar o tempo local
    struct tm tm = *localtime(&t);
	fflush(stdin);
	carroEstacionado = c1;
	int matriculaCorreta=0;
	while(matriculaCorreta==0){
		printf("Indique a matricula do carro: ");//Introduzir a matricula
		gets(carroEstacionado->matricula);
		
		//Tipo XX-00-00
		if(isalpha(carroEstacionado->matricula[0])!=0){
			if(isalpha(carroEstacionado->matricula[1])!=0){
				if(carroEstacionado->matricula[2]=='-'){
					if(isdigit(carroEstacionado->matricula[3])!=0){
						if(isdigit(carroEstacionado->matricula[4])!=0){
							if(carroEstacionado->matricula[5]=='-'){
								if(isdigit(carroEstacionado->matricula[6])!=0){
									if(isdigit(carroEstacionado->matricula[7])!=0){
										if(carroEstacionado->matricula[8]!=NULL){
										}else{
											matriculaCorreta=1;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		//Tipo 00-XX-00
		if(isdigit(carroEstacionado->matricula[0])!=0){
			if(isdigit(carroEstacionado->matricula[1])!=0){
				if(carroEstacionado->matricula[2]=='-'){
					if(isalpha(carroEstacionado->matricula[3])!=0){
						if(isalpha(carroEstacionado->matricula[4])!=0){
							if(carroEstacionado->matricula[5]=='-'){
								if(isdigit(carroEstacionado->matricula[6])!=0){
									if(isdigit(carroEstacionado->matricula[7])!=0){
										if(carroEstacionado->matricula[8]!=NULL){
											fflush(stdin);
										}else{
											matriculaCorreta=1;
										}
									}
								}
							}
						}
					}
				}
			}
		}
		//Tipo 00-00-XX
		if(isdigit(carroEstacionado->matricula[0])!=0){
			if(isdigit(carroEstacionado->matricula[1])!=0){
				if(carroEstacionado->matricula[2]=='-'){
					if(isdigit(carroEstacionado->matricula[3])!=0){
						if(isdigit(carroEstacionado->matricula[4])!=0){
							if(carroEstacionado->matricula[5]=='-'){
								if(isalpha(carroEstacionado->matricula[6])!=0){
									if(isalpha(carroEstacionado->matricula[7])!=0){
										if(carroEstacionado->matricula[8]!=NULL){
											fflush(stdin);
										}else{
											matriculaCorreta=1;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	printf("Indique a marca do carro: ");//Introduzir a marca
	gets(carroEstacionado->marca);
	printf("Indique o modelo do carro: ");//Introduzir o modelo
	gets(carroEstacionado->modelo);
	printf("Indique a cor do carro: ");//Introduzir a cor
	gets(carroEstacionado->cor);
	carroEstacionado->he=tm.tm_hour;
    carroEstacionado->me=tm.tm_min;
    carroEstacionado->se=tm.tm_sec;
    printf("\nCarro estacionado. A data de entrada foi:  %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);
}

void mostrar_carro(carro c1)//Mostrar dados sobre carro selecionado
{
	printf("Matricula do carro:  %s\n",c1.matricula);
	printf("Marca do carro:  %s\n",c1.marca);
	printf("Modelo do carro: %s\n",c1.modelo);
	printf("Cor do carro: %s\n",c1.cor);
	printf("Lugar estacionado: %d\n",c1.lugar);
	printf("A data de entrada foi: %02d:%02d:%02d\n\n", carroEstacionado->he, carroEstacionado->me, carroEstacionado->se);
}
