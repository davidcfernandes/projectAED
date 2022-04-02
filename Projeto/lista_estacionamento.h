typedef struct lista_carros{//Estrutura da lista dos carros
	carro c_lista;
	struct lista_carros* next;
} lista_c;

int xLugar;
int yLugar;
int zLugar;
int lugarAtual;
carro *carroEstacionado;



lista_c * criar_nodo(carro c);//Metodo criar nodo para o carro introduzido

void inserirInicio(lista_c **lista, carro c);//Metodo para inserir o carro no inicio da lista

void inserirFim(lista_c **lista, carro c);//Metodo para inserir o carro no fim da lista

int removerElemento(lista_c **lista);//Metodo para remover carro da lista

void listar(lista_c *lista);//Metodo para listar todos os carros na lista

void visualizarParque(lista_c **lista);//Metodo para visualizar a disposicao do parque

void atribuirLugarParque(carro *c, lista_c **lista);//Metodo para atribuir um lugar vazio do parque a um carro

void verificarLugarNaoOcupado(lista_c **lista);//Metodo para verificar se um lugar no parque nao se encontra ocupado

int numeroCarros(lista_c **lista);//Metodo para indicar o numero de carros que se encontram estacionados

void selectionSort(int arr[], int n);//Metodo para organizar array introduzido

void printArray(int arr[], int size);//Metodo para dar print ao array introduzido
