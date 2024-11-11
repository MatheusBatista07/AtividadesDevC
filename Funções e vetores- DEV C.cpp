#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX_ALUNOS 10
#define MAX_NOME 50

char nomes[MAX_ALUNOS][MAX_NOME];
float notas[MAX_ALUNOS][3];  // Cada aluno terá 3 notas
float medias[MAX_ALUNOS];
int numAlunos = 0;

void adicionarAluno();
void calcularMedia(int indice);
void exibirAlunos();
void alunoMaiorMedia();
void menu();


int main() {
	setlocale(LC_ALL, "portuguese");
	menu();
    return 0;
    
}

void menu() {
    int opcao;

    do {
        printf("1. Adicionar aluno e notas\n");
        printf("2. Calcular e exibir a média de cada aluno\n");
        printf("3. Exibir todos os alunos\n");
        printf("4. Exibir o aluno com maior média\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                adicionarAluno();
                break;
            case 2:
                exibirAlunos();
                break;
            case 3:
                exibirAlunos();
                break;
            case 4:
                alunoMaiorMedia();
                break;
            case 0:
                printf("Programa encerrado!\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while(opcao != 0);
}

void adicionarAluno() {
    if (numAlunos >= MAX_ALUNOS) {
        printf("Limite de alunos atingido!\n");
        return;
    }

    printf("Digite o nome do aluno: ");
    fgets(nomes[numAlunos], MAX_NOME, stdin);
    nomes[numAlunos][strcspn(nomes[numAlunos], "\n")] = 0;  // Remove newline

    printf("Digite as 3 notas do aluno:\n");
    for (int i = 0; i < 3; i++) {
        printf("Nota %d: ", i + 1);
        scanf("%f", &notas[numAlunos][i]);
    }
    getchar();  // Limpar o buffer do stdin

    calcularMedia(numAlunos);
    numAlunos++;
    printf("Aluno adicionado com sucesso!\n");
}

void calcularMedia(int indice) {
    medias[indice] = (notas[indice][0] + notas[indice][1] + notas[indice][2]) / 3;
}

void exibirAlunos() {
    if (numAlunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    printf("\n--- Alunos Cadastrados ---\n");
    for (int i = 0; i < numAlunos; i++) {
        printf("Nome: %s, Notas: %.2f, %.2f, %.2f, Média: %.2f\n",
               nomes[i],
               notas[i][0],
               notas[i][1],
               notas[i][2],
               medias[i]);
    }
}

void alunoMaiorMedia() {
    if (numAlunos == 0) {
        printf("Nenhum aluno cadastrado.\n");
        return;
    }

    int indiceMaior = 0;
    for (int i = 1; i < numAlunos; i++) {
        if (medias[i] > medias[indiceMaior]) {
            indiceMaior = i;
        }
    }

    printf("\nAluno com maior média:\n");
    printf("Nome: %s, Notas: %.2f, %.2f, %.2f, Média: %.2f\n",
           nomes[indiceMaior],
           notas[indiceMaior][0],
           notas[indiceMaior][1],
           notas[indiceMaior][2],
           medias[indiceMaior]);
}

