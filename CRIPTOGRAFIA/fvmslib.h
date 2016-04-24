#ifndef fvmslib_H_INCLUDED
#define fvmslib_H_INCLUDED


int cataint_arquivo(FILE * arquivo);

char catachar_arquivo(FILE * arquivo);

float catafloat_arquivo(FILE * arquivo);


void botaint_arquivo(int valor,FILE *arquivo);

void botaint_arquivo_espaco(int valor,FILE *arquivo);

void botachar_arquivo(char valor,FILE *arquivo);

void botafloat_arquivo(float valor,FILE *arquivo);


FILE * abrearquivo_readonly(char *nomedoarquivo);

FILE * abrearquivo_readwrite(char *nomedoarquivo);

FILE * novoarquivo_readwrite(char *nomedoarquivo);

void catastring_arquivo (char *string, FILE *arquivo);

void botastring_arquivo (char *string,FILE *arquivo);


int conta_linhas_arquivo (FILE *arquivo);

int conta_chars_arquivo (FILE *arquivo);



FILE * file_set_start (FILE *arquivo);

FILE * file_set_end (FILE *arquivo);

#endif // fvmslib_H_INCLUDED

