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
    float nota1;
    float nota2;
} cDisciplina;

typedef struct infoAluno
{
    char nome[60];
    int RA;
    cDisciplina disciplinaAluno[maxDisciplinas];
} cAluno;

void End()
{
    system("clear");
    printf("O programa será encerrado agora. . .");
    getchar();getchar();
    end(0);
}

void InserirAlunos(cAluno cadastroAlunos[maxAlunos], int *nAlunosAtual, cDisciplina cadastroDisciplinas[maxDisciplinas], int nDisciplinas)
{
    int nAlunosCadastrar;

    do
    {
        system("clear");
        printf("Quantos alunos deseja cadastrar?\nNúmero: ");
        scanf("%d", &nAlunosCadastrar);
        getchar();

        if(*nAlunosAtual + nAlunosCadastrar > maxAlunos)
        {
            printf("\n\n--------\nNúmero inválido. O valor colocado ultrapassaria o máximo de alunos registrado. . .");
            getchar();
        }
    } while (*nAlunosAtual + nAlunosCadastrar > maxAlunos);


    for(int i = 0; i < nAlunosCadastrar; i++)
    {
        int select;

        system("clear");
        printf("Cadastrando o aluno nº%d:\n", *nAlunosAtual + 1);
        printf("Digite o nome completo: ");
        gets(cadastroAlunos[*nAlunosAtual].nome);
        printf("Digite seu RA [9 Dígito]: ");
        scanf("%d", &cadastroAlunos[*nAlunosAtual].RA);
        getchar();

        do
        {

            system("clear");
            printf("As disciplinas disponíveis são:\n");

            for(int j = 0; j < nDisciplinas; j++)
            {
                printf("[ %d ] - %s\n", j, cadastroDisciplinas[j].nomeDisciplina);
            }

            printf("\nSelecione a disciplina: ");
            scanf("%d", &select);
            // getchar();

            if(select < 0 || select >= nDisciplinas)
            {
                printf("\n--------\n\nPor favor, insira um valor válido. . .");
                getchar();
            }
        } while (select < 0 || select >= nDisciplinas);

        // Agora, a partir do select, deve ser inserido que o aluno faz a disciplina correspondente ao endereço cadastroDisciplinas[select].nomeDisciplina no endereço cadastroAlunos[*nAlunoAtual].disciplinaAluno[select]. Acho que da para fazer olhando apenas para posição, sem precisar copiar o nome. De qualquer forma, vai se preciso da uma boa experimentada em como funciona um struct dentro de outro struct.
    }
}

void RemocaoDeAlunos()
{

}

void AlteracaoDeInformacoes()
{

}

void BuscarAluno()
{

}

void ListarNotas()
{

}

void ListaDisciplina()
{

}

void CadastrarDisciplinas(cDisciplina cadastroDisciplinas[maxDisciplinas],int *nDisciplinas)
{
    do
    {
        system("clear");
        printf("Quantas disciplinas existem? [ Máximo: %d ]\nDigite: ", maxDisciplinas);
        scanf("%d", &*nDisciplinas);
        getchar();
        
        if(*nDisciplinas < 0 || *nDisciplinas > 7)
        {
            printf("\n--------\n\nPor favor, insira um valor válido. . .");
            getchar();
        }
    } while (*nDisciplinas < 0 || *nDisciplinas > 7);
    
    system("clear");
    for(int i = 0; i < *nDisciplinas; i++)
    {
        printf("\nDigite o nome da %dª disciplina: ", i + 1);
        gets(cadastroDisciplinas[i].nomeDisciplina);
    }
}

int main()
{
    int loop = 1, nDisciplinas, nAlunosAtual = 0;
    cAluno cadastroAlunos[maxAlunos];
    cDisciplina cadastroDisciplinas[maxDisciplinas];

    CadastrarDisciplinas(cadastroDisciplinas, &nDisciplinas);

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
        printf("[ 5 ] - Listar Notas\n");
        printf("[ 6 ] - Mostrar Alunos de uma disciplina\n");
        printf("Resposta: ");
        scanf("%d", &escolha);
        getchar();

        switch (escolha)
        {
        case 0:
            End();
            break;
        case 1:
            if(nAlunosAtual >= maxAlunos)
            {
                printf("\n\n--------\nO número máximo de alunos já foi atingido!");
                getchar();
            }
            else
                InserirAlunos(cadastroAlunos, &nAlunosAtual, cadastroDisciplinas, nDisciplinas);
            break;
        case 2:
            RemocaoDeAlunos();
            break;
        case 3:
            AlteracaoDeInformacoes();
            break;
        case 4:
            BuscarAluno();
            break;
        case 5:
            ListarNotas();
            break;
        case 6:
            ListaDisciplina();
            break;
        }
    } while (loop == 1);
    
    getchar();getchar();
    return 0;
}