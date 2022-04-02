typedef struct automovel{//Criar a estrutura do carro
	char matricula[10];//Variavel para a matricula do carro
	char marca[20];//Variavel para a marca do carro
	char modelo[20];//Variavel para o modelo do carro
	char cor[20];//Variavel para o modelo do carro
	int lugar, he, me, se, hs, ms, ss;//Variavel do lugar que ocupa no parque, hora, minuto e segundo de entrada e saida
} carro;

void estacionar_carro(carro *c);//Metodo estacionar carro

void mostrar_carro(carro c);//Mostrar carro selecionado

int igualMatricula (char c1[10], char c2[10]);//Metodo verificar se matriculas sao iguais

int igual (carro c1, carro c2);//Metodo verificar se carros sao iguais
