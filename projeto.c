//O programa serve para cadastrar alunos, disciplinas e suas notas nas disciplinas.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define maxAlunos 2
#define maxDisciplinas 7

typedef struct disciplina
{
    char nomeDisciplina[15];
    float nota1, nota2;
} cDisciplina;

typedef struct infoAluno
{
    char nome[60];
    int RA; //definir máximo de 99999999.
    cDisciplina disciplina[maxDisciplinas];
} cAluno;

void End()
{
    system("clear");
    printf("O programa será encerrado agora. . .");
    getchar();getchar();
    end(0);
}

void CadastrarDisciplinas(cDisciplina cadastroDisciplinas[maxDisciplinas])
{
    int nDisciplinas;

    do
    {
        system("clear");
        printf("Quantas disciplinas existem? [ Máximo: %d ]\nDigite: ", maxDisciplinas);
        scanf("%d", &nDisciplinas);
        getchar();
        
        if(nDisciplinas < 0 || nDisciplinas > 7)
            printf("\nPor favor, insira um valor válido. . .");
    } while (nDisciplinas < 0 || nDisciplinas > 7);
    
    system("clear");
    for(int i = 0; i < nDisciplinas; i++)
    {
        printf("\nDigite o nome da %dª disciplina: ", i + 1);
        gets(cadastroDisciplinas[i].nomeDisciplina);
    }
}

int main()
{
    int loop = 1;
    cAluno cadastroAlunos[maxAlunos];
    cDisciplina cadastroDisciplinas[maxDisciplinas];

    CadastrarDisciplinas(cadastroDisciplinas);
    // Menu do Programa.
    do
    {
        int escolha;
        system("clear");
        printf("---- Bem-vindo ao Menu ----\n\n");
        printf("O que você deseja fazer?\n");
        printf("[ 0 ] - Fechar Programa\n");
        printf("[ 1 ] - Inserir Aluno\n");
        printf("[ 2 ] - Remover Aluno\n");
        printf("[ 3 ] - Alterar Informações\n");
        printf("[ 4 ] - Buscar Aluno\n");
        printf("[ 5 ] - Mostrar Informações dos Alunos\n");
        printf("[ 6 ] - Mostrar Alunos de uma disciplina\n");
        printf("Resposta: ");
        scanf("%d", &escolha);

        switch (escolha)
        {
        case 0:
            End();
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        }
    } while (loop != 1);
    
    getchar();getchar();
    return 0;
}