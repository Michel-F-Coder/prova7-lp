#include <stdio.h>
#include <stdbool.h>

float nota1, nota2, nota3, nota4;
char aluno[50];
float media;
float soma;
FILE *boletins;
int menu;

void main()
{

    printf("================ BOLETIM ====================\n\n");

    printf("1 - CADASTRAR ALUNO\n");
    printf("2 - CONSULTAR ALUNO\n");
    scanf("%d", &menu);

    switch (menu)
    {
    case 1:

        printf("================ CADASTRAR ALUNO ====================\n\n");

        printf("Digite o nome do aluno: \n");
        scanf("%s", aluno);

        printf("Digite a primeira nota: \n");
        scanf("%f", &nota1);

        printf("Digite a segunda nota: \n");
        scanf("%f", &nota2);

        printf("Digite a terceira nota: \n");
        scanf("%f", &nota3);

        printf("Digite a quarta nota: \n");
        scanf("%f", &nota4);

        soma = nota1 + nota2 + nota3 + nota4;

        media = (soma + media) / 4;

        printf("=============== RESULTADO ================\n\n");

        printf("Soma = %.2f\n", soma);
        printf("Media = %.2f\n\n", media);

        if (media >= 7)
        {
            printf("APROVADO\n");
        }
        if (media < 5)
        {
            printf("REPROVADO\n");
        }
        else
        {
            printf("RECUPERAÇÃO\n");
        }

        boletins = fopen("boletins.txt", "a");

        if (boletins == NULL)
        {
            printf("ERRO");
        }

        fprintf(boletins, "ALUNO: %s / Nota 1: %.2f / Nota 2: %.2f / Nota 3: %.2f / Nota 4: %.2f / Media final: %.2f", aluno, nota1, nota2, nota3, nota4, media) == 6;

        fclose(boletins);

        break;

    case 2:

        printf("================ CONSULTAR ALUNO ====================\n\n");

        printf("digite o nome do aluno: ");
        scanf("%s", aluno);

        boletins = fopen("boletins.txt", "r");

        if (boletins == NULL)
        {
            printf("ERRO");
        }

        while (fscanf(boletins, "ALUNO: %s / Nota 1: %f / Nota 2: %f / Nota 3: %f / Nota 4: %f / Media final: %f", aluno, &nota1, &nota2, &nota3, &nota4, &media) == 6)
            ;
        {
            printf("ALUNO: %s / Nota 1: %.2f / Nota 2: %.2f / Nota 3: %.2f / Nota 4: %.2f / Media final: %.2f", aluno, nota1, nota2, nota3, nota4, media);
        }
        fclose(boletins);
        break;
    }
}