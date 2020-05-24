/*
	Nome: Sistema de Gerenciamento de Aluno
	Inicio: 18/05/2020 16:37
	T�rmino: ??/??/???? ??:??
Autores:
	Felipe Silva Joaquim | RA: 3333294	 
	Guilherme Mandeli Fernandes Camacho | RA: 3210023
*/

//     ----------------8<-------------[ Corte Aqui ]------------------

// Inclus�o de Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define LIMITE 100 // Definindo um valor m�ximo

//     ----------------8<-------------[ Corte Aqui ]------------------

// Cria��o do Struct do Aluno
struct lista{
    int ra; // Matricula do aluno
    char nome[256]; // Nome do aluno
    char disciplina[256]; // Nome da disciplina do aluno
    float avaliacao_1,avaliacao_2,avaliacao_3; // Avalia��es do aluno
};

//     ----------------8<-------------[ Corte Aqui ]------------------

// Definindo os tipos de Estrutura de Dados onde foi utilizada
typedef struct lista Lista; // Definindo Struct
Lista* cria_lista(); // Criando a Estrutura de Dados
void libera_lista(Lista* li); // Verifica e realiza a libera��o da Estrutura de Dados
int consulta_lista_pos(Lista* li, int pos, struct aluno *al); // Estrutura para consultar a posi��o
int consulta_lista_RA(Lista* li, int RA, struct aluno *al); // Estrutura para consultar a matricula
int insere_lista_final(Lista* li, struct aluno al);
int insere_lista_inicio(Lista* li, struct aluno al);
int insere_lista_ordenada(Lista* li, struct aluno al);
int remove_lista(Lista* li, int RA);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_cheia(Lista* li);
int lista_vazia(Lista* li);
void imprime_lista(Lista* li);

int remove_lista_otimizado(Lista* li, int mat);

//     ----------------8<-------------[ Corte Aqui ]------------------

int main(){ // Fun��o principal

    struct aluno al, a[8]; = {{7,"Gloria",4.3,9.9,8.6},{2,"Circe",2.7,5.4,7.5},{4,"Fate",1.9,6.7,6.8},{8,"Muffet",4.4,5.2,6.4},{1,"Esra",9.7,1.1,5.2},{3,"Folgore",6.7,2.1,9.4},{6,"Wiz",2.2,4.5,6.8},{5,"Midas", 5.5,3.2,8.6}}; // Os Adorados(Malditos) Alunos, RPG Feelings ;(
                                              
    Lista* li = cria_lista(); // Criando a estrutura de dados
    
	int i; // �ndice para uso de estrutura��o dos dados
    
    for(i=0; i < 8; i++){ // La�o de repeti��o para a constru��o da estrutura de dados, insere e mostra a lista realizando todas as verifica��es, assim mostrando a lista
    	insere_lista_ordenada(li,a[i]);
		imprime_lista(li);
    	printf("\n\n\n\n");
	}
	
    for(i=0; i < 8; i++){ // La�o de repeti��o para a verifica��o da estrutura de dados, se caso o elemento n�o for encontrado � emitido uma mensagem de erro
        if (!remove_lista_otimizado(li,i))
            printf("Erro\n");

        imprime_lista(li); 
        printf("\n\n\n\n");
    }

    libera_lista(li); // Ao fim de todo o longo processo de fun��es dentro de fun��es o programa � devidamente encerrado ;-(
    system("pause");
    return 0;
}

//     ----------------8<-------------[ Corte Aqui ]------------------

struct lista{ //Defini��o do tipo estrutura, o limite de alunos e sua quantidade
    int qtd;
    struct aluno dados[LIMITE];
};

//     ----------------8<-------------[ Corte Aqui ]------------------

Lista* cria_lista(){ // Cria��o da lista e utiliza��o do "Malloc" para aloca��o na memoria RAM
    Lista *li;
    li = (Lista*) malloc(sizeof(struct lista));
    if(li != NULL)
        li->qtd = 0;
    return li;
}

//     ----------------8<-------------[ Corte Aqui ]------------------

void libera_lista(Lista* li){ // Utiliza��o da fun��o "free", que nunca ouvi falar, mas ela desaloca a por��o de mem�ria alocada por malloc
    free(li);
}

//     ----------------8<-------------[ Corte Aqui ]------------------

int consulta_lista_pos(Lista* li, int pos, struct aluno *al){ // Realiza a consulta da fila pela posi��o
    if(li == NULL || pos <= 0 ||  pos > li->qtd)
        return 0;
    *al = li->dados[pos-1];
    return 1;
}

//     ----------------8<-------------[ Corte Aqui ]------------------

int consulta_lista_RA(Lista* li, int RA, struct aluno *al){ // Realiza a consulta da lista pelo RA, � define quando o elemento n�o � encontrado
    if(li == NULL)
        return 0;
    int i = 0;
    while(i<li->qtd && li->dados[i].RA != RA)
        i++;
    if(i == li->qtd)
        return 0;
    *al = li->dados[i];
    return 1;
}

//     ----------------8<-------------[ Corte Aqui ]------------------

int insere_lista_final(Lista* li, struct aluno al){ // Verifica o final da lista e se ela est� cheia ou n�o
    if(li == NULL)
        return 0;
    if(li->qtd == LIMITE)
        return 0;
    li->dados[li->qtd] = al;
    li->qtd++;
    return 1;
}

//     ----------------8<-------------[ Corte Aqui ]------------------

int insere_lista_inicio(Lista* li, struct aluno al){ // Insere a lista e realiza a verifica��o se est� cheia
    if(li == NULL)
        return 0;
    if(li->qtd == LIMITE)
        return 0;
    int i;
    for(i=li->qtd-1; i>=0; i--)
        li->dados[i+1] = li->dados[i];
    li->dados[0] = al;
    li->qtd++;
    return 1;
}

//     ----------------8<-------------[ Corte Aqui ]------------------

int insere_lista_ordenada(Lista* li, struct aluno al){ // Ordena a lista e realiza a verifica��o se est� cheia
    if(li == NULL)
        return 0;
    if(li->qtd == LIMITE)
        return 0;
    int k,i = 0;
    while(i<li->qtd && li->dados[i].RA < al.RA)
        i++;

    for(k=li->qtd-1; k >= i; k--)
        li->dados[k+1] = li->dados[k];

    li->dados[i] = al;
    li->qtd++;
    return 1;
}

//     ----------------8<-------------[ Corte Aqui ]------------------

int remove_lista(Lista* li, int RA){ // Remove algo da lista e confere se o elemento existe
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    int k,i = 0;
    while(i<li->qtd && li->dados[i].RA != RA)
        i++;
    if(i == li->qtd)
        return 0;
        
    for(k=i; k< li->qtd-1; k++)
        li->dados[k] = li->dados[k+1];
    li->qtd--;
    return 1;
}

//     ----------------8<-------------[ Corte Aqui ]------------------

int remove_lista_otimizado(Lista* li, int RA){ // revome a lista verificada
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    int i = 0;
    while(i<li->qtd && li->dados[i].RA != RA)
        i++;
    if(i == li->qtd)
        return 0;

    li->qtd--;
    li->dados[i] = li->dados[li->qtd];
    return 1;
}

//     ----------------8<-------------[ Corte Aqui ]------------------

int remove_lista_inicio(Lista* li){ // Fun��oa para trabalhar com a remo��o de conte�dos da lista
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    int k = 0;
    for(k=0; k< li->qtd-1; k++)
        li->dados[k] = li->dados[k+1];
    li->qtd--;
    return 1;
}

//     ----------------8<-------------[ Corte Aqui ]------------------

int remove_lista_final(Lista* li){ // Fun��oa para trabalhar com a remo��o de conte�dos da lista
    if(li == NULL)
        return 0;
    if(li->qtd == 0)
        return 0;
    li->qtd--;
    return 1;
}

int tamanho_lista(Lista* li){ // Verificar o tamanho da lista
    if(li == NULL)
        return -1;
    else
        return li->qtd;
}

//     ----------------8<-------------[ Corte Aqui ]------------------

int lista_cheia(Lista* li){ // Definindo a lista cheia
    if(li == NULL)
        return -1;
    return (li->qtd == LIMITE);
}

//     ----------------8<-------------[ Corte Aqui ]------------------

int lista_vazia(Lista* li){ // a lista vazia
    if(li == NULL)
        return -1;
    return (li->qtd == 0);
}

//     ----------------8<-------------[ Corte Aqui ]------------------

void imprime_lista(Lista* li){ // Imprime as informa��es da lista
    if(li == NULL)
        return;
    int i;
    for(i=0; i< li->qtd; i++){
        printf("RA: %i\n",li->dados[i].RA);
        printf("Nome: %s\n",li->dados[i].nome);
        printf("Notas: | %.2f | %.2f | %.2f | \n",li->dados[i].avaliacao_1, li->dados[i].avaliacao_2, li->dados[i].avaliacao_3);
        printf("-------------------------------\n");
    }
}

