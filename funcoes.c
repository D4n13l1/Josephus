#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include"jose.h"
int qtd = 0;
typedef struct no{
	char nome[20];
	struct no *prox;
}No;

void inserir_fim(No **l, char nome[]){
	No *novo;
	novo = (No *)malloc(sizeof(No));
	novo->prox = NULL;
	strcpy(novo->nome, nome);

	if (*l == NULL){
		*l = novo;
		novo->prox = novo;
	}else{
		No *p;
		for (p=*l; p->prox!=*l; p=p->prox);
		p->prox = novo;
		novo->prox = *l;		
	}
	qtd++;
}

void mostrar(No **l){
	No *p;
	
	if (*l == NULL){
		printf("Lista vazia.\n");
		return;
	}

	for (p=*l; p->prox!=*l ; p=p->prox)
		printf("%s -> ", (p->nome));
	printf("%s\n", (p->nome));
	printf("Quantidade de soldados: %i\n", qtd);
}

int removeAt(No **l, int n){
		if(*l == NULL)return 0;
	while(qtd>1){
		No*p = *l, *q;
		if(p->prox==p){
			p=*l;
			*l=NULL;
			free(p);
			return 1;
		}
		int cont = 0;
		for(p=*l;;p=p->prox, cont++){
			if(cont == n)break;
			q=p;
		}
		if(*l==p){
			*l=p->prox;
		}
		q->prox=p->prox;
		printf("%s removido\n", p->nome);
		free(p);
		qtd--;
	}
	return 1;
}
void change_first(No**l, int n){
	if(*l == NULL){
		printf("Nao ha soldados na lista\n");
		return;
		}
	if((*l)->prox == *l){
		printf("%s inicia a contagem\n", (*l)->nome);
		return;
		}
	No*p;
	int cont = 0;
	for(p=*l;p->prox!=*l;p=p->prox, cont++){
		if(cont == n)break;
	}
	*l=p;
	printf("%s inicia a contagem\n", (*l)->nome);
	return;
}
int randomico(int vlr_max){
	//um numero pseudo-aleatório que vai de 0 a valor estipulado
	return rand() % vlr_max;
}