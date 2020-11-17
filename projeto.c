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
        printf("\n-------\n\nCadastro do aluno nº%d finalizado.", *nAlunosAtual - 1);
        printf("\nNúmero de alunos atual é %d", *nAlunosAtual);
        printf("\n--------\n\nPressione enter para continuar. . .");
        getchar();
    }
}

void RemocaoDeAlunos()
{
    // Para remover alunos, selecionar o aluno que deve ser removido (provavelmente por RA)
    // Depois voltar 1 número todos os alunos que estão cadastrados na frente desse.
    // Finalizar reduzindo o valor de nAlunosAtual em 1 unidade.
    // Basicamente, se tem 5 alunos cadastrados, o que vai acontecer é:

    // nAlunosAtual=5
    // Alunos Cadastrados 0 1 2 3 4
    // Quero remover o 2
    // Volta cadastros sucessores ao removido 0 1 3 4
    // Transforma o endereço deles no correto 0 1 2 3 - Talvez precise só mudar o endereço deles, ainda preciso pensar mais nisso.
    // Reduz nAlunos atual
    // nAlunosAtual=4
}

void AlteracaoDeInformacoes()
{
    // Selecionar aluno pelo RA.
    // Executar etapa idêntica ao do cadastro do aluno.
    //Precisa mudar o ponteiro *nAlunosAtual para o endereço (int) onde o aluno está guardado.

    /*
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
    */
}

void BuscarAluno()
{
    // Basicamente o mesmo processo incial de remover e alterar informações de um aluno.
    // Acho que é só usar parte do código do cadastro do aluno também.
    // Vai precisar mudar *nAlunosAtual pelo endereço (int) do aluno buscado.
    // Acho que seria legal deixar mais bonitinho a apresentação das notas nesse caso.

    /*
    system("clear");

    printf("Informações do aluno nº%d:", *nAlunosAtual + 1);
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
  */
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

    // Reseta as disciplinas cursadas por todos os alunos. Basicamente, no início do programa ninguém cursa nada.
    for(int i = 0; i < maxAlunos; i++)
    {
        for(int j = 0; j < maxDisciplinas; j++)
        {
            cadastroAlunos[i].disciplinasCursadas[j] = 0;
        }
    }

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
        printf("[ 2 ] - Remover Aluno\n");                          // Precisa de pouco para funcionar.
        printf("[ 3 ] - Alterar Informações\n");                    // Precisa de pouco para funcionar.
        printf("[ 4 ] - Buscar Aluno\n");                           // Precisa de pouco para funiconar.
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