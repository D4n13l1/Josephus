#include<stdio.h>
#include<stdlib.h>
#include"funcoes.c"

int menu(){
	system("cls");
	//system("clear");
	printf("Há um pequeno grupo de soldados\nQue por um grande exército está cercado\nNo problema de Josephus decidiremos\nQual soldado foge à cavalo\n\n");

	printf("\n[1] - Inserir soldados\n");
	printf("[2] - Mostrar soldados\n");
	printf("[3] - Sortear o soldado que iniciara a contagem\n");
	printf("[4] - Apresentar o soldado selecionado\n");
	printf("Sua escolha: ");
	int opc;
	fflush(stdin);
	scanf("%i", &opc);
	return opc;
}
void main(){
	int opc, sold, n;
	No *l1 = NULL;
	char nome[50];
	opc=menu();
	while(opc>0&&opc<5)
	{
		int i = 0;
		switch (opc)
		{
			case 1:
			printf("Digite quantos soldados cadastrar: ");
			scanf("%i",&sold);
				while(i<sold){
					printf("\nInsira o nome do soldado %i: ", i+1);
					scanf("\n%[^\n]", &nome);
					printf("%s inserido\n", nome);
					i++;
					inserir_fim(&l1, nome);
				};
				getchar();
				getchar();
				break;
			case 2:
				mostrar(&l1);
				getchar();
				getchar();
				break;
			case 3:
				n=randomico(10000);
				change_first(&l1, n);
				getchar();
				getchar();
				break;
			case 4:
				if(n>10000)printf("Voce deve sortear um soldado primeiro\n");
				else{
					printf("Numero sorteado: %i\n", n);
					removeAt(&l1,n);
					(l1!=NULL)?printf("%s se safa com o cavalo\n", l1->nome):printf("Nao existem soldados\n");	
					l1=NULL;
					qtd--;
				}
				getchar();
				getchar();
				break;
			default:
				break;
		}
		opc=menu();
	}
}
