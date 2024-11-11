#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int vetor[5], matriz[2][2];

int somaVetor (){
	int soma=0;
	for (int i=0; i < 5; i++){
		soma+=vetor[i];
	}
	return soma;
}
void preencherMatriz (int valor){
	printf ("Preencher matriz[2][2]\n");
	for (int i=0; i < 2; i++){
	for (int j=0; j < 2; j++){
			matriz[i][j]=valor;
		}
	}
}
void imprimirMatriz(){
	printf ("Matriz 2x2\n");
	for (int i=0; i < 2; i++){
	for (int j=0; j < 2; j++){
		printf ("%d\t", matriz[i][j]);
	}
	printf ("\n");
	}
}
int main (){
	int soma;
	setlocale(LC_ALL, "Portuguese");
	printf ("Digite 5 números inteiros:\n");
	for (int i=0; i < 5; i++){
		scanf ("%d", &vetor[i]);
	}
	printf ("Soma dos elementos do vetor: %d\n", somaVetor());
	preencherMatriz(somaVetor());
	imprimirMatriz();
}
