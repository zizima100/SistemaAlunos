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
    int disciplinasCursadas[maxDisciplinas];
    cDisciplina infoDisciplinaAluno[maxDisciplinas];
} cAluno;

void End()
{
    system("clear");
    printf("O programa será encerrado agora. . .");
    getchar();getchar();
    end(0);
}

void ResetDisciplinasCursadas(cAluno cadastroAlunos[maxAlunos], int posicaoReset)
{
    if(posicaoReset == -1)
    {
        for(int i = 0; i < maxAlunos; i++)
        {
            for(int j = 0; j < maxDisciplinas; j++)
            {
                cadastroAlunos[i].disciplinasCursadas[j] = 0;
            }
        }
    }
    else
    {
        for(int j = 0; j < maxDisciplinas; j++)
        {
            cadastroAlunos[posicaoReset].disciplinasCursadas[j] = 0;
        }
    }
}

int BuscaRA(cAluno cadastroAlunos[maxAlunos], int RAPesquisado)
{
    int RAEncontrado = -1;

    for(int i = 0; i < maxAlunos; i++)
    {
        if(cadastroAlunos[i].RA == RAPesquisado)
        {
            RAEncontrado = i;
            break;
        }
    }

    if(RAEncontrado >= 0)
    {
        return(RAEncontrado);
    }
    else
    {
        printf("\n--------\nRA Não Encontrado!");
        getchar();
        return(-1);
    }
}

void InserirAlunos(cAluno cadastroAlunos[maxAlunos], int *nAlunosAtual, cDisciplina cadastroDisciplinas[maxDisciplinas], int nDisciplinas)
{
    int nAlunosCadastrar;

    do
    {
        system("clear");
        printf("O número de alunos já cadastrados é: %d - [ Máximo de %d ]", *nAlunosAtual, maxAlunos);
        printf("\n--------\n\nQuantos alunos deseja cadastrar?\nNúmero: ");
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

        ResetDisciplinasCursadas(cadastroAlunos, *nAlunosAtual);

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

            printf("Cadastrando o aluno nº%d:", *nAlunosAtual + 1);
            printf("\n\nNome: %s.", cadastroAlunos[*nAlunosAtual].nome);
            printf("\nRA: %d.", cadastroAlunos[*nAlunosAtual].RA);

            for(int j = 0; j < maxDisciplinas; j++)
            {
                if(cadastroAlunos[*nAlunosAtual].disciplinasCursadas[j] != 0)
                {
                    printf("\nCursando: %s", cadastroDisciplinas[j].nomeDisciplina);
                    printf(" - Nota 1: %.2f", cadastroAlunos[*nAlunosAtual].infoDisciplinaAluno[j].nota1);
                    printf(" - Nota 2: %.2f.", cadastroAlunos[*nAlunosAtual].infoDisciplinaAluno[j].nota2);
                }
            }

            printf("\n--------\n\nOpções de cadastro de disciplina disponíveis:");
            printf("\n\n[ 0 ] - Finalizar Cadastro\n");

            for(int j = 0; j < nDisciplinas; j++)
            {
                printf("[ %d ] - %s\n", j + 1, cadastroDisciplinas[j].nomeDisciplina);
            }

            printf("\nCUIDADO - Se você selecionar uma disciplina já cadastrada, ela será sobre-escrita.\n");
            printf("\nSelecione uma opção: ");
            scanf("%d", &select);
            getchar();

            if(select < 0 || select > nDisciplinas)
            {
                printf("\n--------\n\nPor favor, insira um valor válido. . .");
                getchar();
                continue;
            }

            if(select == 0)
            {
                break;
            }

            // Adiciona a disciplina selecionada no vetor de disciplinas cursadas pelo aluno atual.
            cadastroAlunos[*nAlunosAtual].disciplinasCursadas[select - 1] = 1;

            system("clear");
            printf("Qual a primeira nota de %s na disciplina %s?", cadastroAlunos[*nAlunosAtual].nome, cadastroDisciplinas[select - 1].nomeDisciplina);
            printf("\nNota 1: ");
            scanf("%f", &cadastroAlunos[*nAlunosAtual].infoDisciplinaAluno[select - 1].nota1);
            getchar();
            printf("\n--------\nQual a segunda nota de %s na disciplina %s?", cadastroAlunos[*nAlunosAtual].nome, cadastroDisciplinas[select - 1].nomeDisciplina);
            printf("\nNota 2: ");
            scanf("%f", &cadastroAlunos[*nAlunosAtual].infoDisciplinaAluno[select - 1].nota2);
            getchar();

        } while (select != 0);

        *nAlunosAtual += 1;

        printf("\n-------\nCadastro do aluno na posição %d finalizado.", *nAlunosAtual - 1);
        printf("\nNúmero de alunos atual é %d", *nAlunosAtual);
        printf("\n--------\n\nPressione enter para continuar. . .");
        getchar();
    }
}

void RemocaoDeAlunos(cAluno cadastroAlunos[maxAlunos], int *nAlunosAtual, int nDisciplinas)
{
    int RAPesquisado, posicaoPesquisa, confirmacao = 0;

    system("clear");
    printf("Digite o RA do aluno que deseja remover: ");
    scanf("%d", &RAPesquisado);
    getchar();

    posicaoPesquisa = BuscaRA(cadastroAlunos, RAPesquisado);

    if(posicaoPesquisa < 0)
        return 0;

    do
    {
        system("clear");
        printf("O aluno encontrado foi: %s.", cadastroAlunos[posicaoPesquisa].nome);
        printf("\nRA: %d.", cadastroAlunos[posicaoPesquisa].RA);
        printf("\n\nTem certeza que deseja remove-lo do sistema?\n[ 0 ] - Não\n[ 1 ] - Sim");
        printf("\n\nResposta: ");
        scanf("%d", &confirmacao);
        getchar();

        if(confirmacao == 0)
            return 0;
            
    } while (confirmacao != 0 && confirmacao != 1);
    
    
    system("clear");

    for(int i = posicaoPesquisa; i < *nAlunosAtual; i++)
    {
        strcpy(cadastroAlunos[i].nome, cadastroAlunos[i + 1].nome);
        cadastroAlunos[i].RA = cadastroAlunos[i + 1].RA;

        for(int j = 0; j < nDisciplinas; j++)
        {
            cadastroAlunos[i].disciplinasCursadas[j] = cadastroAlunos[i + 1].disciplinasCursadas[j];
            cadastroAlunos[i].infoDisciplinaAluno[j].nota1 = cadastroAlunos[i + 1].infoDisciplinaAluno[j].nota1;
            cadastroAlunos[i].infoDisciplinaAluno[j].nota2 = cadastroAlunos[i + 1].infoDisciplinaAluno[j].nota2;
        }
    }
    *nAlunosAtual -= 1;
}

void AlteracaoDeInformacoes(cAluno cadastroAlunos[maxAlunos], cDisciplina cadastroDisciplinas[maxDisciplinas], int nDisciplinas)
{
    int RAPesquisado, posicaoPesquisa, confirmacao = 0, select = 0;
    char novoNome[60];

    system("clear");
    printf("Digite o RA do aluno que deseja remover: ");
    scanf("%d", &RAPesquisado);
    getchar();

    posicaoPesquisa = BuscaRA(cadastroAlunos, RAPesquisado);

    if(posicaoPesquisa < 0)
        return 0;

    do
    {
        system("clear");
        printf("O aluno encontrado foi: %s.", cadastroAlunos[posicaoPesquisa].nome);
        printf("\nRA: %d.", cadastroAlunos[posicaoPesquisa].RA);
        printf("\n\nTem certeza que deseja alterar suas informações?\n[ 0 ] - Não\n[ 1 ] - Sim");
        printf("\n\nResposta: ");
        scanf("%d", &confirmacao);
        getchar();

        if(confirmacao == 0)
            return 0;
            
    } while (confirmacao != 0 && confirmacao != 1);

    do
    {
        system("clear");
        printf("Informações do aluno nº%d:", posicaoPesquisa + 1);
        printf("\n\nNome: %s.", cadastroAlunos[posicaoPesquisa].nome);
        printf("\nRA: %d.", cadastroAlunos[posicaoPesquisa].RA);

        for(int j = 0; j < maxDisciplinas; j++)
        {
            if(cadastroAlunos[posicaoPesquisa].disciplinasCursadas[j] != 0)
            {
                printf("\n--------\nCursando: %s", cadastroDisciplinas[j].nomeDisciplina);
                printf(" - Nota 1: %.2f", cadastroAlunos[posicaoPesquisa].infoDisciplinaAluno[j].nota1);
                printf(" - Nota 2: %.2f", cadastroAlunos[posicaoPesquisa].infoDisciplinaAluno[j].nota2);
            }
        }

        printf("\n--------\nO que você deseja alterar?\n[ 0 ] - Cancelar\n[ 1 ] - Nome\n");
        printf("[ 2 ] - Remover uma disciplina\n");

        for(int j = 0; j < nDisciplinas; j++)
        {
            printf("[ %d ] - Adicionar/Alterar %s\n", j + 3, cadastroDisciplinas[j].nomeDisciplina);
        }

        printf("\nResposta: ");
        scanf("%d", &confirmacao);
        getchar();

        if(confirmacao < 0 || confirmacao > nDisciplinas + 3)
        {
            printf("\n\nPor favor selecione uma opção válida. . .");
            getchar();
            continue;
        }
        else if(confirmacao == 0)
            return 0;
        else if(confirmacao == 1)
        {
            system("clear");
            printf("Por favor digite o novo nome de %s.", cadastroAlunos[posicaoPesquisa].nome);
            printf("\n\nNovo nome: ");
            gets(novoNome);
            strcpy(cadastroAlunos[posicaoPesquisa].nome, novoNome);
        }
        else if(confirmacao == 2)
        {
            do
            {
                system("clear");
                printf("Qual disciplina você deseja alterar?\n[ 0 ] - Sair\n");

                for(int j = 0; j < nDisciplinas; j++)
                {
                    printf("[ %d ] - Remover %s\n", j + 1, cadastroDisciplinas[j].nomeDisciplina);
                }

                printf("\nResposta: ");
                scanf("%d", &select);
                getchar();

                if(select < 0 || select > nDisciplinas + 1)
                {
                    printf("\n\nPor favor selecione uma opção válida. . .");
                    getchar();
                    continue;
                }
                else if(select == 0)
                    break;
                else
                {
                    cadastroAlunos[posicaoPesquisa].disciplinasCursadas[select - 1] = 0;

                    printf("\n--------\nA matrícula na disciplina %s foi removida.", cadastroDisciplinas[select - 1].nomeDisciplina);
                    getchar();
                }
            } while (select != 0);
        }
        else
        {
            // Adicionar ou alterar disciplinas específicas.
            cadastroAlunos[posicaoPesquisa].disciplinasCursadas[confirmacao - 3] = 1;

            system("clear");
            printf("Qual a primeira nota de %s na disciplina %s?", cadastroAlunos[posicaoPesquisa].nome, cadastroDisciplinas[confirmacao - 3].nomeDisciplina);
            printf("\nNota 1: ");
            scanf("%f", &cadastroAlunos[posicaoPesquisa].infoDisciplinaAluno[confirmacao - 3].nota1);
            getchar();
            printf("\n--------\nQual a segunda nota de %s na disciplina %s?", cadastroAlunos[posicaoPesquisa].nome, cadastroDisciplinas[confirmacao - 3].nomeDisciplina);
            printf("\nNota 2: ");
            scanf("%f", &cadastroAlunos[posicaoPesquisa].infoDisciplinaAluno[confirmacao - 3].nota2);
            getchar();
        }
    } while (confirmacao != 0);
}

void BuscarAluno(cAluno cadastroAlunos[maxAlunos], cDisciplina cadastroDisciplinas[maxDisciplinas], int nDisciplinas)
{
    int RAPesquisado, posicaoPesquisa;

    system("clear");

    printf("Digite o RA do aluno que deseja buscar: ");
    scanf("%d", &RAPesquisado);
    getchar();

    posicaoPesquisa = BuscaRA(cadastroAlunos, RAPesquisado);

    if(posicaoPesquisa < 0)
    return 0;

    system("clear");
    printf("Informações do aluno nº%d:", posicaoPesquisa + 1);
    printf("\n\nNome: %s.", cadastroAlunos[posicaoPesquisa].nome);
    printf("\nRA: %d.\n", cadastroAlunos[posicaoPesquisa].RA);

    for(int j = 0; j < maxDisciplinas; j++)
    {
        if(cadastroAlunos[posicaoPesquisa].disciplinasCursadas[j] != 0)
        {
            printf("\n--------\nCursando: %s.", cadastroDisciplinas[j].nomeDisciplina);
            printf("\nNota 1: %.2f.", cadastroAlunos[posicaoPesquisa].infoDisciplinaAluno[j].nota1);
            printf("\nNota 2: %.2f.\n", cadastroAlunos[posicaoPesquisa].infoDisciplinaAluno[j].nota2);
        }
    }

    printf("\n\nPressione enter para voltar para o menu. . .");
    getchar();
}

void ListarNotas()
{
    // Não parei para pensar nesse ainda.
}

void ListaDisciplina()
{
    // Vai precisar checar o vetor de disciplinas cursadas de aluno por aluno.
    // Não parei para pensar muito nesse também.
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

    ResetDisciplinasCursadas(cadastroAlunos, -1);

    CadastrarDisciplinas(cadastroDisciplinas, &nDisciplinas);

    // Menu do Programa.
    do
    {
        int escolha;

        system("clear");
        printf("---- Bem-vindo ao Menu ----\n\n");
        printf("O que você deseja fazer?\n\n");
        printf("[ 0 ] - Fechar Programa\n");                        // Funcionando Completamente.
        printf("[ 1 ] - Inserir Aluno\n");                          // Funcionando Completamente.
        printf("[ 2 ] - Remover Aluno\n");                          // Funcionando Completamente.
        printf("[ 3 ] - Alterar Informações\n");                    // Funcionando Completamente.
        printf("[ 4 ] - Buscar Aluno\n");                           // Funcionando Completamente.
        printf("[ 5 ] - Listar Notas\n");                           // Precisa desenvolver do zero praticamente.
        printf("[ 6 ] - Mostrar Alunos de uma disciplina\n\n");     // Precisa desenvolver do zero praticamente.
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
                printf("\n\nSe quiser cadastrar um novo aluno, deverá remover algum antes. . .");
                getchar();
            }
            else
                InserirAlunos(cadastroAlunos, &nAlunosAtual, cadastroDisciplinas, nDisciplinas);
            break;
        case 2:
            if(nAlunosAtual == 0)
            {
                printf("\n\n--------\nNão existem alunos cadastrados!");
                printf("\n\nCadastre um aluno antes de usar essa opção. . .");
                getchar();
            }
            else
            {
                RemocaoDeAlunos(cadastroAlunos, &nAlunosAtual, nDisciplinas);
            }
            break;
        case 3:
            if(nAlunosAtual == 0)
            {
                printf("\n\n--------\nNão existem alunos cadastrados!");
                printf("\n\nCadastre um aluno antes de usar essa opção. . .");
                getchar();
            }
            else
            {
                AlteracaoDeInformacoes(cadastroAlunos, cadastroDisciplinas, nDisciplinas);
            }
            break;
        case 4:
            if(nAlunosAtual == 0)
            {
                printf("\n\n--------\nNão existem alunos cadastrados!");
                printf("\n\nCadastre um aluno antes de usar essa opção. . .");
                getchar();
            }
            else
            {
                BuscarAluno(cadastroAlunos, cadastroDisciplinas, nDisciplinas);
            }
            break;
        case 5:
            ListarNotas();
            break;
        case 6:
            ListaDisciplina();
            break;
        }
    } while (loop == 1);
    getchar();
    return 0;
}