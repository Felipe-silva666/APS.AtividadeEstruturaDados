#include <stdio.h>
#include <stdlib.h>
#include <locale>

#define maximo 100

struct aluno{
    int matricula;
    char nome[30];
    float n1,n2,n3;
};

typedef struct fila Fila;


struct fila{
    int inicio, final, qtd;
    struct aluno dado[maximo];
};

// Fun��es
Fila* cria_Fila();
void libera_Fila(Fila* fi);
int consulta_Fila(Fila* fi, struct aluno *al);
int insere_Fila(Fila* fi, struct aluno al);
int remove_Fila(Fila* fi);
int tamanho_Fila(Fila* fi);
int Fila_vazia(Fila* fi);
int Fila_cheia(Fila* fi);
void imprime_Fila(Fila* fi);

//       .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--.
//     :::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\
//     '      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `

int main(void){ // Fun��o principal
	setlocale(LC_ALL, "Portuguese"); // Fun��o vinda de uma biblioteca para a utiliza��o de acentua��es da l�ngua portuguesa
	 
	struct aluno al, a[8]; // ADICIONADO
	Fila* fi = cria_Fila();
	int opcao, i;
	
	switch(opcao){
		
		case 0:
			system("pause");
    		return 0;
		break;
		
		case 1:
			for(i=0; i < 4; i++){
        		insere_Fila(fi,a[i]);
        		consulta_Fila(fi,&al);
    		}
    		imprime_Fila(fi);
    		printf("Tamanho: %d\n\n\n\n",tamanho_Fila(fi));
		break;
		
		case 2:
			for(i=0; i < 4; i++){
        		remove_Fila(fi);
        		consulta_Fila(fi,&al);
    		}
    		printf("Tamanho: %d\n\n\n\n",tamanho_Fila(fi));
    		imprime_Fila(fi);
		break;
		
		case 3:
			for(i=0; i < 4; i++){
    			insere_Fila(fi,a[i]);
			}
    		imprime_Fila(fi);
		break;
		
		case 4:
    		libera_Fila(fi);
    		system("pause");
    		return 0;
		break;
	}
	
}

//       .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--.
//     :::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\
//     '      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `

int menu(void){ // Fun��o para o uso do menu
	int opt; // Vari�vel para a sele��o das op��es de menu

	// Op��es do menu para o usu�rio
	printf("Escolha a opcao\n"); // Mensagem ao usu�rio
	printf("1. Adicionar Elemento na Fila\n"); // Mensagem ao usu�rio
	printf("2. Exibir fila\n"); // Mensagem ao usu�rio
	printf("3. Retirar Elemento da Fila\n"); // Mensagem ao usu�rio
	printf("4. Zerar fila\n"); // Mensagem ao usu�rio
	printf("5. Sair\n"); // Mensagem ao usu�rio
	
	printf("Opcao: "); // Mensagem ao usu�rio
	scanf("%d", &opt); // Leitura do valor atribu�do pelo usu�rio, assim selecionando a op��o do menu

	return opt; // retornando o valor de "opt" para a aplica��o do menu
}

//       .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--.
//     :::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\
//     '      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `

void opcao(info *fila, int opcao){ // Fun��o para a aplica��o do menu
	
	info *aux; // Vari�vel auxiliar para visualizar toda a fila
	
	switch(op){ // Aplica��o do Switch aplicando o valor atribu�do pelo usu�rio
		case 1:
			insere(fila); // Fun��o para adicionar alguem na fila
			break;

		case 2:
			exibe(fila); // Fun��o para exibir toda a fila
			break;

		case 3:
			aux = retira(fila); // Conferindo a ponta da fila
			if(aux != NULL){ // Visualizando toda a fila
				printf("Retirado: %3d\n\n", aux -> codigo); // Indiv�duo retirado da fila
				libera(aux); // Retirando o indiv�duo da fila
			}
			break;
		
		case 4:
			libera(fila); // Fun��o para checagem e libera��o da fila 
			inicia(fila); // Fun��o para iniciar uma fila
			break;

		case 5:
			libera(fila); // Fun��o para checagem e libera��o da fila 
			break;

		default: printf("Comando invalido\n\n"); // Caso o Engra�adin- usu�rio tente digitar algo fora do padr�o
 }
}

//       .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--.
//     :::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\
//     '      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `

void inicia(info *fila){ // Fun��o para iniciar uma fila
	
	fila -> proximo = NULL; // Apontando o in�cio da fula
	tamanho = 0; // Tamanho da fila inicial
}

//       .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--.
//     :::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\
//     '      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `

int vazia(info *fila){ // Fun��o para conferindo se a fila est� vazia
	
	if(fila -> proximo == NULL){  // Utilizando a condi��o para a verifica��o da fila
		return 1; // Retorno de valores se ainda existir alguem na fila
	}else{	
		return 0; // Retorno de valores se a fila estiver vazia
	}
}

//       .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--.
//     :::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\
//     '      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `

info *aloca(){ // Fun��o para alocar e substituir alguem na fila
	
	info *novo =(info *) malloc(sizeof(info)); // Nova var�avel que faz essa opera��o de rebecer um valor para a aloca��o na mem�ria
	if(!novo){ // Se caso a mem�ria esteja cheia
		printf("Sem memoria disponivel!\n"); // Mensagem ao usu�rio
		exit(1); // Interrompendo a execu��o do programa
	}else{
		printf("Novo elemento: "); // Mensagem ao usu�rio para a pessoa nova na fila
		scanf("%d", &novo -> codigo); // Leitura da mensagem do usu�rio
		return novo;
	}
}

//       .--.      .-'.      .--.      .--.      .--.      .--.      .`-.      .--.
//     :::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\::::::::.\
//     '      `--'      `.-'      `--'      `--'      `--'      `-.'      `--'      `

// Defini��o e constru��o da fila
struct TipoFila{
    int inicio, final, quantidade;
    struct aluno dado[100];
}; 
typedef struct TipoFila Fila;

int consulta_Fila(Fila* fi, struct aluno *al){
    if(fi == NULL || Fila_vazia(fi))
        return 0;
    *al = fi -> dado[fi -> inicio];
    return 1;
}

Fila* cria_Fila(){
    
	Fila *fi;
    fi = (Fila*)malloc(sizeof(struct TipoFila));
	if(fi != NULL){
        fi -> inicio = 0;
        fi -> final = 0;
        fi -> quantidade = 0;
    }
    return fi;
}

int Fila_cheia(Fila* fi){
    if(fi == NULL)
        return -1;
    if (fi -> quantidade == maximo)
        return 1;
    else
        return 0;
}

int Fila_vazia(Fila* fi){
    if(fi == NULL)
        return -1;
    if (fi -> quantidade == 0)
        return 1;
    else
        return 0;
}

void imprime_Fila(Fila* fi){
    if(fi == NULL)
        return;
    int n, i = fi -> inicio;
    for(n = 0; n < fi -> quantidade; n++){
        printf("Matricula: %d\n", fi -> dado[i].matricula);
        printf("Nome: %s\n", fi -> dado[i].nome);
        printf("Avalia��es: %.2f %.2f %.2f\n", fi -> dado[i].avaliacao1, fi -> dado[i].avaliacao2, fi -> dado[i].avaliacao3);
        i = (i + 1) %maximo;
    }
}

int insere_Fila(Fila* fi, struct aluno){
    if(fi == NULL)
        return 0;
    if(Fila_cheia(fi))
        return 0;
    fi -> dado[fi -> final] = aluno;
    fi -> final = (fi-> final + 1) %maximo;
    fi -> quantidade++;
    return 1;
}

// Fun��o para liberar a fila, utilizando "free"
void libera_Fila(Fila* fi){
    free(fi);
}

int remove_Fila(Fila* fi){
    if(fi == NULL || Fila_vazia(fi))
        return 0;
    fi -> inicio = (fi -> inicio + 1) %maximo;
    fi -> quantidade--;
    return 1;
}

int tamanho_Fila(Fila* fi){
    if(fi == NULL)
        return - 1;
    return fi -> quantidade;
}

