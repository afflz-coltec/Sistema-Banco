#ifndef vmslib_H_INCLUDED
#define vmslib_H_INCLUDED


            int cataint();

            char catachar();

            float catafloat();


            //ESCRITA

            void botaint(int valor);

            void botachar(char valor);

            void botafloat(float valor);

            //MISC

            int mdc(int dividendo,int divisor);

            int mmc(int prim,int segu);

            int fatorial(int num);

            int fibonacci(int num);

            int gausum(int num);

            int menor(int atual,int desafiante);

            int maior(int atual,int desafiante);

            void debug ();

            void nline();


//::::::::::::::::::::::::::VETORES:::::::::::::::::::::::::::::::


//MALLOC

            int *alocavetor_int (int tamanho);

            char *alocavetor_char (int tamanho);

            float *alocavetor_float (int tamanho);


//CALLOC

            int *calocavetor_int (int tamanho);

            char *calocavetor_char (int tamanho);

            float *calocavetor_float (int tamanho);


//REALLOC

            int *realocavetor_int (int *vetor,int tamanho);

            char *realocavetor_char (char *vetor,int tamanho);

            float *realocavetor_float (float *vetor,int tamanho);


//FREE

            void liberavetor_int(int *vetor);

            void liberavetor_char(char *vetor);

            void liberavetor_float(float *vetor);


//LEITURA

            void catavetor_int(int *vetor,int tamanho);

            void catavetor_char(char *vetor,int tamanho);

            void catavetor_float(float *vetor,int tamanho);


//ESCRITA VERTICAL

            void botavetorvertical_int(int *vetor,int tamanho);

            void botavetorvertical_char(char *vetor,int tamanho);

            void botavetorvertical_float(float *vetor,int tamanho);


//ESCRITA HORIZONTAL

            void botavetorhorizontal_int(int *vetor,int tamanho);

            void botavetorhorizontal_char(char *vetor,int tamanho);

            void botavetorhorizontal_float(float *vetor,int tamanho);


//MISC

            void randvetor(int *vetor,int tamanho,int s);

            int menor_elemento (int *vetor,int tamanho);

            void spacer(char *vetor,int tamanho);

            int soma_vetor(int *vetor,int tamanho);

            int multiplica_vetor(int *vetor,int tamanho);

            float media_vetor(int *vetor,int tamanho);

            void ordena_vetor (int *vetor,int tamanho);

            void iguala_vetor (int *vetor1,int *vetor2,int tamanho);



//::::::::::::::::::::::::::MATRIZES:::::::::::::::::::::::::::::::

//MALLOC

            int **alocamatrix_int (int linhas,int colunas);

            char **alocamatrix_char (int linhas,int colunas);

            float **alocamatrix_float (int linhas,int colunas);


//CALLOC

            int **calocamatrix_int (int linhas,int colunas);

            char **calocamatrix_char (int linhas,int colunas);

            float **calocamatrix_float (int linhas,int colunas);


//REALLOC

            int **realocamatrix_int (int **mtrx,int linhas,int colunas);

            char **realocamatrix_char (char **mtrx,int linhas,int colunas);

            float **realocamatrix_float (float **mtrx,int linhas,int colunas);


//FREE

            void liberamatrix_int(int **mtrx,int linhas,int colunas);

            void liberamatrix_char(char **mtrx,int linhas,int colunas);

            void liberamatrix_float(float **mtrx,int linhas,int colunas);


//LEITURA

            void catamatrix_int(int **mtrx,int linhas,int colunas);

            void catamatrix_char(char **mtrx,int linhas,int colunas);

            void catamatrix_float(float **mtrx,int linhas,int colunas);


//ESCRITA

            void botamatrix_int(int **mtrx,int linhas,int colunas);

            void botamatrix_char(char **mtrx,int linhas,int colunas);

            void botamatrix_float(float **mtrx,int linhas,int colunas);

            void botasomadim(int **mtrx,int *vet,int linhas,int colunas,int indice);

            void botaintlado(int **mtrx,int *vet,int linhas,int colunas,int indice);

            void botacharlado(char **mtrx,char *vet,int linhas,int colunas,int indice);


            void botafloatlado(float **mtrx,float *vet,int linhas,int colunas,int indice);



//MISC

            void transpoe_matrix(int **mtrx,int linhas,int colunas);


            void randmatrix(int **mtrx,int linhas,int colunas,int s);


            int somatrix (int **mtrx,int linhas,int colunas);


            void somalct (int **mtrx,int *resp,int linhas,int colunas,int nlinhas,int ncolunas);


            void somadiag (int **mtrx,int *resp,int linhas,int colunas);

            int ** multiplica_matrix(int **mtrxa,int **mtrxb,int alinhas,int acolunas,int blinhas,int bcolunas);


            void matrixspacer(char **mtrx,int linhas,int colunas);


            void iguala_matrix (int **mtrx2,int **mtrx1,int linhas,int colunas);


            void inverte_matrix (int **mtrx,int linhas,int colunas);


            int compara_matrix (int **mtrx1,int **mtrx2,int linhas,int colunas);


//::::::::::::::::::::::::::::::STRINGS::::::::::::::::::::::::::::::::::::::::


//GERAIS

            void catastring (char *string);

            void botastring (char *string);

            int contastring(char *string);

            void igualastring(char *string_origem,char *string_destino);

            void invertestring (char *string_origem,char *string_destino);

            void tiraosimbolos (char *string);

            int comparastrings(char *string_A,char *string_B);



//::::::::::::::::::::::::::::::RECURSIVIDADE::::::::::::::::::::::::::::::::::::::::


            void recont (int in,int cont,int fin);

            int recontaux (int in,int cont,int fin);

            void refibonacci (int n);

            int refibonacciaux (int n,int sum,int sumi);

            int resomavetor (int *vet,int tamanho);

            int resomavetoraux (int *vet,int tamanho,int soma);

            int remenorvetor (int *vet,int tamanho);

            int remenorvetoraux (int *vet,int tamanho,int me);

            int repot (int n,int valor);

            int repotaux(int n,int acc,int valor);

#endif // gerente_H_INCLUDED











