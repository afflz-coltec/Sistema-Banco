#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "vmslib.h"
#include "fvmslib.h"


int cataint_arquivo(FILE * arquivo)
{

    int valor;

    fscanf(arquivo,"%d",&valor);

    return valor;

}
char catachar_arquivo(FILE * arquivo)
{

    char valor;

    fscanf(arquivo,"%c",&valor);

    return valor;
}
float catafloat_arquivo(FILE * arquivo)
{

    float valor;

    fscanf(arquivo,"%f\n",&valor);

    return valor;
}


void botaint_arquivo(int valor,FILE *arquivo)
{
    fprintf(arquivo,"%d\n",valor);
}

void botaint_arquivo_espaco(int valor,FILE *arquivo)
{
    fprintf(arquivo,"%d ",valor);
}

void botachar_arquivo(char valor,FILE *arquivo)
{
    fprintf(arquivo,"%c\n",valor);
}
void botafloat_arquivo(float valor,FILE *arquivo)
{
    fprintf(arquivo,"%f\n",valor);
}


FILE * abrearquivo_readonly(char *nomedoarquivo)
{
    FILE *arquivo;

    arquivo = fopen(nomedoarquivo,"r");

    if (!arquivo)
        {
        printf("Não foi\n\n");
        return 0;
        }
    else
    {
        return arquivo;
    }
}

FILE * abrearquivo_readwrite(char *nomedoarquivo)
{
    FILE *arquivo;

    arquivo = fopen(nomedoarquivo,"a+");
    if (!arquivo)
        {
        printf("Não foi\n\n");
        return 0;
        }
    else
    {
        return arquivo;
    }
}

FILE * novoarquivo_readwrite(char *nomedoarquivo)
{
    FILE *arquivo;

    arquivo = fopen(nomedoarquivo,"w+");

    if (!arquivo)
        {
        printf("Não foi\n\n");
        return 0;
        }
    else
    {
        return arquivo;
    }
}


void catastring_arquivo (char *string, FILE *arquivo)
{
    int aux=0;

    while (!feof(arquivo))
        {
        if ((string[aux]=fgetc(arquivo)) != '\n')
            aux++;
        else
            break;
        }

    string[aux]='\0';
}
void botastring_arquivo (char *string,FILE *arquivo)
{
    int aux=0;

    while (string[aux]!='\0')
    {
        fputc(string[aux],arquivo);
        aux++;
    }

    fprintf(arquivo,"\n");
}


int conta_linhas_arquivo (FILE *arquivo)
{
    int linhas=1;
    char c;

    while(!feof(arquivo))
    {
        c=fgetc(arquivo);

        if (c == '\n')
        {
            linhas++;
        }
    }

    return linhas;
}
int conta_chars_arquivo (FILE *arquivo)
{
    int chars=0;
    char c;

    while(!feof(arquivo))
    {
        c=fgetc(arquivo);

        if (c == '\n'||c == ' '||c == '\t')
            continue;
        else
            chars++;
    }

    return chars;
}


FILE * file_set_start (FILE *arquivo)
{
    fseek (arquivo,0,SEEK_SET);

    return arquivo;
}
FILE * file_set_end (FILE *arquivo)
{
    fseek (arquivo,0,SEEK_END);

    return arquivo;
}

