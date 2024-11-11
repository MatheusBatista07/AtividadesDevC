#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

//Programacao de Matheus Batista e Sophia Dacy

int main(){
	int matriz[10][3], id, qtd, op, cont, qtdvend;
	float vetor[10], venda, valor;
	
	setlocale(LC_ALL, "portuguese");
	
	//Cadastro dos Produtos
	for(int i=0; i<10; i++)
	{
		printf("Produto %d\n", i+1);
		printf("Digite o ID do produto: ");
		scanf("%d", &matriz[i][0]);
		printf("Digite a quantidade do produto em estoque: ");
		scanf("%d", &matriz[i][1]);
		printf("Digite o preço do produto: ");
		scanf("%f", &vetor[i]);
	}
	
	//Menu de Opcoes
	do{
		printf("\nMenu de opções:\n");
		printf("1. Exibir Produtos\n2. Vender Produto\n0. Sair do programa\n");
		scanf("%d", &op);
		
		switch(op)
		{
			//Exibicao de produtos
			case 1: 
			printf("ID | Quantidade | Preço\n");
			for(int i=0; i<10; i++)
			{
				printf("ID: %d | Quantidade: %d | Preço: %.2f\n", matriz[i][0], matriz[i][1], vetor[i]);
			
			if(matriz[i][1]<3)
			{
				printf("Estoque baixo\n");
			}
			}
			break;
			
			//Venda de Produtos
			case 2: 
			printf("Informe o ID do produto: ");
			scanf("%d", &id);
			printf("Informe a quantidade de produto que deseja: ");
			scanf("%d", &qtd);
			for(int i=0; i<10; i++)
			{
				if(id==matriz[i][0])
				{
					if(matriz[i][1]==0)
					{
						printf("Estoque esgotado, venda não permitida");
					}
					else if(qtd<=matriz[i][1])
					{
						matriz[i][1]= matriz[i][1]-qtd; 
						venda= qtd*vetor[i];
						printf("Venda realizada!\nValor total: %.2f\nQuantidade restante do produto %d: %d\n", venda, matriz[i][0], matriz[i][1]);
					}
					else
					{
						printf("Estoque insuficiente!");
					}
				}
			}
			break;
			
			}
		}while(op!=0);
	}

