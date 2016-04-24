#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "vmslib.h"



            int cataint()
            {

                int valor;

                scanf("%d",&valor);

                return valor;

            }
            char catachar()
            {

                char valor;

                scanf("%c",&valor);

                return valor;
            }
            float catafloat()
            {

                float valor;

                scanf("%f",&valor);

                return valor;
            }

            //ESCRITA

            void botaint(int valor)
            {
                printf("%d\n",valor);
            }
            void botachar(char valor)
            {
                printf("%c\n",valor);
            }
            void botafloat(float valor)
            {
                printf("%f\n",valor);
            }

            //MISC

            int mdc(int dividendo,int divisor)
            {
                int aux=0,mdc=0;

                for(aux=1;; aux++)
                {
                    if ((aux>dividendo)||(aux>divisor))
                        break;
                    if ((dividendo%aux==0)&&(divisor%aux==0))
                        mdc=mdc*aux;
                }

                return mdc;
            }
            int mmc(int prim,int segu)
            {



            }
            int fatorial(int num)
            {
                int a;
                for(a=num; num>1; num--)
                    a*=num;

                return a;

            }
            int fibonacci(int num)
            {
                int swap,sum=1,sumi=0;

                for(; num>1; num--)
                {
                    swap=sum;
                    sum+=sumi;
                    sumi=swap;
                }

                return sum;

            }
            int gausum(int num)
            {
                int a;
                for(a=num; num>1; num--)
                    a+=num;

                return a;

            }
            int menor(int atual,int desafiante)
            {
                if(desafiante<atual)
                    return desafiante;
                else
                    return atual;
            }
            int maior(int atual,int desafiante)
            {
                if(desafiante>atual)
                    return desafiante;
                else
                    return atual;
            }
            void debug ()
            {
                printf("DEBUG\n");
            }
            void nline()
            {
                printf("\n");
            }

//::::::::::::::::::::::::::VETORES:::::::::::::::::::::::::::::::


//MALLOC

            int *alocavetor_int (int tamanho)
            {
                int *vetor;

                vetor = (int *) malloc (tamanho * sizeof(int));

                return vetor;
            }
            char *alocavetor_char (int tamanho)
            {
                char *vetor;

                vetor = (char *) malloc (tamanho * sizeof(char));

                return vetor;
            }
            float *alocavetor_float (int tamanho)
            {
                float *vetor;

                vetor = (float *) malloc (tamanho * sizeof(float));

                return vetor;
            }

//CALLOC

            int *calocavetor_int (int tamanho)
            {
                int *vetor;

                vetor = (int *) calloc (tamanho , sizeof(int));

                return vetor;
            }
            char *calocavetor_char (int tamanho)
            {
                char *vetor;

                vetor = (char *) calloc (tamanho , sizeof(char));

                return vetor;
            }
            float *calocavetor_float (int tamanho)
            {
                float *vetor;

                vetor = (float *) calloc (tamanho , sizeof(float));

                return vetor;

            }

//REALLOC

            int *realocavetor_int (int *vetor,int tamanho)
            {

                vetor = (int *) realloc (vetor, tamanho* sizeof(int));

                return vetor;
            }
            char *realocavetor_char (char *vetor,int tamanho)
            {

                vetor = (char *) realloc (vetor, tamanho* sizeof(char));

                return vetor;
            }
            float *realocavetor_float (float *vetor,int tamanho)
            {

                vetor = (float *) realloc (vetor, tamanho* sizeof(float));

                return vetor;
            }

//FREE

            void liberavetor_int(int *vetor)
            {
                free(vetor);
            }
            void liberavetor_char(char *vetor)
            {
                free(vetor);
            }
            void liberavetor_float(float *vetor)
            {
                free(vetor);
            }

//LEITURA

            void catavetor_int(int *vetor,int tamanho)
            {
                int i;

                for (i=0; i<tamanho; i++)
                    scanf("%d",&vetor[i]);
            }
            void catavetor_char(char *vetor,int tamanho)
            {
                int i;

                for (i=0; i<tamanho; i++)
                    scanf("%c",&vetor[i]);
            }
            void catavetor_float(float *vetor,int tamanho)
            {
                int i;

                for (i=0; i<tamanho; i++)
                    scanf("%f",&vetor[i]);
            }

//ESCRITA VERTICAL

            void botavetorvertical_int(int *vetor,int tamanho)
            {
                int i;

                for (i=0; i<tamanho; i++)
                {
                    if      (vetor[i]<10)
                        printf("0%d\n",vetor[i]);
                    else if ((vetor[i]>=10)&&(vetor[i]<=99))
                        printf("%d\n",vetor[i]);
                    else
                        printf("%d\n",vetor[i]);
                }

            }
            void botavetorvertical_char(char *vetor,int tamanho)
            {
                int i;

                for (i=0; i<tamanho; i++)
                    printf("%c\n",vetor[i]);
            }
            void botavetorvertical_float(float *vetor,int tamanho)
            {
                int i;

                for (i=0; i<tamanho; i++)
                    printf("%f\n",vetor[i]);
            }

//ESCRITA HORIZONTAL

            void botavetorhorizontal_int(int *vetor,int tamanho)
            {
                int i;

                for (i=0; i<tamanho; i++)
                {
                    if      (vetor[i]<10)
                        printf("00%d ",vetor[i]);
                    else if ((vetor[i]>=10)&&(vetor[i]<=99))
                        printf("0%d ",vetor[i]);
                    else
                        printf("%d ",vetor[i]);
                }

            }
            void botavetorhorizontal_char(char *vetor,int tamanho)
            {
                int i;

                printf("\n");

                for (i=0; i<tamanho; i++)
                    printf(" %c ",vetor[i]);

                printf("\n");
            }
            void botavetorhorizontal_float(float *vetor,int tamanho)
            {
                int i;

                for (i=0; i<tamanho; i++)
                    printf("%f ",vetor[i]);
            }

//MISC

            void randvetor(int *vetor,int tamanho,int s)
            {
                srand(time(NULL));

                int i;

                for (i=0; i<tamanho; i++)
                    vetor[i]=(rand()%s)+1;
            }
            int menor_elemento (int *vetor,int tamanho)
            {

                int i,im=0;

                for (i=0; i<tamanho; i++)
                    if (vetor[i] <= vetor[im])
                        im=i;

                return im;
            }
            void spacer(char *vetor,int tamanho)
            {
                int i;

                for (i=0; i<tamanho; i++)
                    vetor[i]=' ';
            }
            int soma_vetor(int *vetor,int tamanho)
            {
                int i,soma=0;

                for (i=0; i<tamanho; i++)
                    soma+=vetor[i];

                return soma;
            }
            int multiplica_vetor(int *vetor,int tamanho)
            {
                int i,mult=1;

                for (i=0; i<tamanho; i++)
                    mult*=vetor[i];

                return mult;
            }
            float media_vetor(int *vetor,int tamanho)
            {
                float a;

                a=soma_vetor(vetor,tamanho);
                a/=tamanho;

                return a;
            }
            void ordena_vetor (int *vetor,int tamanho)
            {
                int i=0,s=(tamanho-1),swap;

                for (; i<9; i++)
                    for (; s>i; s--)
                        if  (vetor[s]<vetor[s-1])
                        {
                            swap=vetor[s];
                            vetor[s]=vetor[s-1];
                            vetor[s-1]=swap;
                        }
            }
            void iguala_vetor (int *vetor1,int *vetor2,int tamanho)
            {
                int i;

                for (i=0; i<tamanho; i++)
                    vetor2[i]=vetor1[i];
            }


//::::::::::::::::::::::::::MATRIZES:::::::::::::::::::::::::::::::

//MALLOC

            int **alocamatrix_int (int linhas,int colunas)
            {
                int **mtrx,i;

                mtrx = (int **) malloc (linhas * sizeof(int *));

                for(i=0; i<linhas; i++)
                    mtrx[i] = (int *) malloc (colunas * sizeof(int));

                return mtrx;
            }
            char **alocamatrix_char (int linhas,int colunas)
            {
                char **mtrx;
                int i;

                mtrx = (char **) malloc (linhas * sizeof(char *));

                for(i=0; i<linhas; i++)
                    mtrx[i] = (char *) malloc (colunas * sizeof(char));

                return mtrx;
            }
            float **alocamatrix_float (int linhas,int colunas)
            {
                float **mtrx;
                int i;

                mtrx = (float **) malloc (linhas * sizeof(float *));

                for(i=0; i<linhas; i++)
                    mtrx[i] = (float *) malloc (colunas * sizeof(float));

                return mtrx;
            }

            //CALLOC

            int **calocamatrix_int (int linhas,int colunas)
            {
                int **mtrx,i;

                mtrx = (int **) calloc (linhas,sizeof(int *));

                for(i=0; i<linhas; i++)
                    mtrx[i] = (int *) calloc (colunas,sizeof(int));

                return mtrx;
            }
            char **calocamatrix_char (int linhas,int colunas)
            {
                char **mtrx;
                int i;

                mtrx = (char **) calloc (linhas,sizeof(char *));

                for(i=0; i<linhas; i++)
                    mtrx[i] = (char *) calloc (colunas,sizeof(char));

                return mtrx;
            }
            float **calocamatrix_float (int linhas,int colunas)
            {
                float **mtrx;
                int i;

                mtrx = (float **) calloc (linhas,sizeof(float *));

                for(i=0; i<linhas; i++)
                    mtrx[i] = (float *) calloc (colunas,sizeof(float));

                return mtrx;
            }

//REALLOC

            int **realocamatrix_int (int **mtrx,int linhas,int colunas)
            {
                int i;

                mtrx = (int **) realloc (mtrx,linhas*sizeof(int*));

                for(i=0; i<linhas; i++)
                    mtrx[i] = (int *) realloc (mtrx[i],colunas*sizeof(int));

                return mtrx;
            }
            char **realocamatrix_char (char **mtrx,int linhas,int colunas)
            {

                int i;

                mtrx = (char **) realloc (mtrx,linhas*sizeof(char*));

                for(i=0; i<linhas; i++)
                    mtrx[i] = (char *) realloc (mtrx[i],colunas*sizeof(char));

                return mtrx;
            }
            float **realocamatrix_float (float **mtrx,int linhas,int colunas)
            {

                int i;

                mtrx = (float **) realloc (mtrx,linhas*sizeof(float*));

                for(i=0; i<linhas; i++)
                    mtrx[i] = (float *) realloc (mtrx[i],colunas*sizeof(float));

                return mtrx;
            }

//FREE

            void liberamatrix_int(int **mtrx,int linhas,int colunas)
            {
                int i;

                for (i=0; i<linhas; i++)
                    free(mtrx[i]);

                free(mtrx);
            }
            void liberamatrix_char(char **mtrx,int linhas,int colunas)
            {
                int i;

                for (i=0; i<linhas; i++)
                    free(mtrx[i]);

                free(mtrx);
            }
            void liberamatrix_float(float **mtrx,int linhas,int colunas)
            {
                int i;

                for (i=0; i<linhas; i++)
                    free(mtrx[i]);

                free(mtrx);
            }

//LEITURA

            void catamatrix_int(int **mtrx,int linhas,int colunas)
            {
                int a,b;

                for (a=0; a<linhas; a++)
                    for(b=0; b<colunas; b++)
                        scanf("%d",&mtrx[a][b]);
            }
            void catamatrix_char(char **mtrx,int linhas,int colunas)
            {
                int a,b;

                for (a=0; a<linhas; a++)
                    for(b=0; b<colunas; b++)
                        scanf("%c",&mtrx[a][b]);
            }
            void catamatrix_float(float **mtrx,int linhas,int colunas)
            {
                int a,b;

                for (a=0; a<linhas; a++)
                    for(b=0; b<colunas; b++)
                        scanf("%f",&mtrx[a][b]);
            }

//ESCRITA

            void botamatrix_int(int **mtrx,int linhas,int colunas)
            {
                int a,b;

                for (a=0; a<linhas; a++)
                {
                    for (b=0; b<colunas; b++)
                    {
                        if (mtrx[a][b]<10)
                            printf("00%d ",mtrx[a][b]);

                        else if ((mtrx[a][b]>=10)&&(mtrx[a][b]<=99))
                            printf("0%d ",mtrx[a][b]);

                        else
                            printf("%d ",mtrx[a][b]);

                    }
                    printf("\n");
                }
            }
            void botamatrix_char(char **mtrx,int linhas,int colunas)
            {
                int a,b;

                for (a=0; a<linhas; a++)
                {
                    for (b=0; b<colunas; b++)
                        printf("%c ",mtrx[a][b]);
                    printf("\n");
                }

            }
            void botamatrix_float(float **mtrx,int linhas,int colunas)
            {
                int a,b;

                for (a=0; a<linhas; a++)
                {
                    for (b=0; b<colunas; b++)
                        printf("%0.f ",mtrx[a][b]);
                    printf("\n");
                }

            }
            void botasomadim(int **mtrx,int *vet,int linhas,int colunas,int indice)
            {
                int a,b;

                if(indice==linhas)
                {
                    for (a=0; a<linhas; a++)
                    {
                        for (b=0; b<colunas; b++)
                        {
                            if (vet[a]<10)
                                printf("0%d ",mtrx[a][b]);
                            else if ((mtrx[a][b]>=10)&&(mtrx[a][b]<=99))
                                printf("%d ",mtrx[a][b]);
                            else
                                printf("%d ",mtrx[a][b]);
                        }
                        printf(" = %d\n",vet[a]);
                    }
                }
                else if(indice==colunas)
                {
                    botamatrix_int(mtrx,linhas,colunas);
                    printf("\n");
                    botavetorhorizontal_int(vet,indice);
                }
            }
            void botaintlado(int **mtrx,int *vet,int linhas,int colunas,int indice)
            {
                int a,b;

                for (a=0; a<linhas; a++)
                {
                    for (b=0; b<colunas; b++)
                    {
                        if (mtrx[a][b]<10)
                            printf("00%d ",mtrx[a][b]);
                        else if ((mtrx[a][b]>=10)&&(mtrx[a][b]<=99))
                            printf("0%d ",mtrx[a][b]);
                        else
                            printf("%d ",mtrx[a][b]);
                    }
                    printf(" %d\n",vet[a]);
                }

            }

            void botacharlado(char **mtrx,char *vet,int linhas,int colunas,int indice)
            {
                int a,b;

                for (a=0; a<linhas; a++)
                {
                    for (b=0; b<colunas; b++)
                    {
                        if (mtrx[a][b]<10)
                            printf("00%c ",mtrx[a][b]);
                        else if ((mtrx[a][b]>=10)&&(mtrx[a][b]<=99))
                            printf("0%c ",mtrx[a][b]);
                        else
                            printf("%c ",mtrx[a][b]);
                    }
                    printf(" %c\n",vet[a]);
                }

            }

            void botafloatlado(float **mtrx,float *vet,int linhas,int colunas,int indice)
            {
                int a,b;

                for (a=0; a<linhas; a++)
                {
                    for (b=0; b<colunas; b++)
                    {
                        if (mtrx[a][b]<10)
                            printf("00%f ",mtrx[a][b]);
                        else if ((mtrx[a][b]>=10)&&(mtrx[a][b]<=99))
                            printf("0%f ",mtrx[a][b]);
                        else
                            printf("%f ",mtrx[a][b]);
                    }
                    printf(" %f\n",vet[a]);
                }

            }


//MISC

            void transpoe_matrix(int **mtrx,int linhas,int colunas)
            {
                int **swap,a,b;

                swap=alocamatrix_int(linhas,colunas);

                for (a=0; a<linhas; a++)
                    for(b=0; b<colunas; b++)
                        swap[a][b]=mtrx[b][a];

                for (a=0; a<linhas; a++)
                    for(b=0; b<colunas; b++)
                        mtrx[a][b]=swap[a][b];

            }

            void randmatrix(int **mtrx,int linhas,int colunas,int s)
            {
                srand(time(NULL));
                int a,b;

                for (a=0; a<linhas; a++)
                    for(b=0; b<colunas; b++)
                        mtrx[a][b]=(rand()%s)+1;
            }

            int somatrix (int **mtrx,int linhas,int colunas)
            {
                int a,b,soma=0;

                for (a=0; a<linhas; a++)
                    for(b=0; b<colunas; b++)
                        soma=soma+mtrx[a][b];

                return soma;
            }

            void somalct (int **mtrx,int *resp,int linhas,int colunas,int nlinhas,int ncolunas)
            {
                int a,b;

                for (a=0; a<nlinhas; a++)
                {
                    resp[0]+=mtrx[a][colunas];
                    resp[2]+=mtrx[a][colunas];
                }
                for(b=0; b<ncolunas; b++)
                {
                    resp[1]+=mtrx[b][linhas];
                    resp[2]+=mtrx[b][linhas];
                }

            }

            void somadiag (int **mtrx,int *resp,int linhas,int colunas)
            {
                int a,b;

                for (a=0; a<linhas; a++)
                    for(b=0; b<colunas; b++)
                    {
                        if (a==b)
                            resp[0]+=mtrx[a][b];
                        else if ((a+b)==colunas-1)
                            resp[1]+=mtrx[a][b];
                    }
            }
            int ** multiplica_matrix(int **mtrxa,int **mtrxb,int alinhas,int acolunas,int blinhas,int bcolunas)
            {
                int a,b,c,**resposta;

                resposta=alocamatrix_int(alinhas,bcolunas);

                if (acolunas==blinhas)
                {
                    for (a=0; a<alinhas; a++)
                        for(b=0; b<bcolunas; b++)
                            for(c=0; c < acolunas; c++)
                                resposta [a][b] += mtrxa[a][c] * mtrxb [c][b];
                }

                return resposta;
            }



            void matrixspacer(char **mtrx,int linhas,int colunas)
            {
                int a,b;

                for (a=0; a<linhas; a++)
                    for(b=0; b<colunas; b++)
                        mtrx[a][b]=' ';
            }

            void iguala_matrix (int **mtrx2,int **mtrx1,int linhas,int colunas)
            {
                int a,b,soma=0;

                for (a=0; a<linhas; a++)
                    for(b=0; b<colunas; b++)
                        mtrx1[a][b]=mtrx2[a][b];
            }

            void inverte_matrix (int **mtrx,int linhas,int colunas)
            {
                int a,b,soma=0;

                for (a=0; a<linhas; a++)
                    for(b=0; b<colunas; b++)
                        if(!(a==b))
                        mtrx[a][b]*=-1;
            }

            int compara_matrix (int **mtrx1,int **mtrx2,int linhas,int colunas)
            {
                int a,b;

                for (a=0; a<linhas; a++)
                    for(b=0; b<colunas; b++)
                    {
                        if (mtrx1[a][b]==mtrx2[a][b])
                            continue;
                        else
                            return 0;
                    }
                return 1;
            }

//::::::::::::::::::::::::::::::STRINGS::::::::::::::::::::::::::::::::::::::::


//GERAIS

            void catastring (char *string)
            {
                int aux=0;

                while ((string[aux]=getchar()) != '\n')
                    aux++;

                string[aux]='\0';
            }
            void botastring (char *string)
            {
                int aux=0;

                while ((putchar(string[aux]))!='\0')
                    aux++;

                printf("\n");
            }
            int contastring(char *string)
            {
                int count=0;

                while (string[count]!='\0')
                    count++;
                return count;
            }
            void igualastring(char *string_origem,char *string_destino)
            {
                int aux=0;
                while (aux<contastring(string_origem))
                {
                    string_destino[aux]=string_origem[aux];
                    aux++;
                }
                string_destino[aux]='\0';
            }
            void invertestring (char *string_origem,char *string_destino)
            {
                int count=0,aux1=0,aux2=contastring(string_origem)-1;

                while (count<contastring(string_origem))
                {
                    string_destino[aux2]=string_origem[aux1];
                    aux2--;
                    aux1++;
                    count++;
                }
                string_destino[count]='\0';
            }
            void tiraosimbolos (char *string)
            {
                int count,i=0,i2=0;
                char *aux;

                count=contastring(string);

                for (i=0; i<=count; i++)
                {
                    if (isalpha(string[i]))
                        aux[i-i2]=string[i];
                    else
                        i2++;
                }
                aux=alocavetor_char(i-i2+1);
                aux[i-i2]='\0';

                igualastring(aux,string);
            }
            int comparastrings(char *string_A,char *string_B)
            {
                int aux=0;
                int count1 = contastring(string_A);
                int count2 = contastring(string_B);

                if (count1!=count2)
                    return 0;

                for (aux=0; aux<=count1; aux++)
                {
                    if (string_A[aux]!=string_B[aux])
                        return 0;
                }

                return 1;
            }


//::::::::::::::::::::::::::::::RECURSIVIDADE::::::::::::::::::::::::::::::::::::::::


            void recont (int in,int cont,int fin)
            {
                if (in>fin)
                    printf("\t\tVALORES INVALIDOS\n\n");
                else
                {
                    recontaux(in,cont,fin);
                }
            }
            int recontaux (int in,int cont,int fin)
            {
                if (in>fin)
                    return 0;
                else
                {
                    printf("%d",in);
                    recontaux((in+cont),cont,fin);
                }
            }
            void refibonacci (int n)
            {
                if (n<=0)
                    printf("\t\tVALORES INVALIDOS\n\n");
                else
                {
                    refibonacciaux(n,1,0);
                }
            }
            int refibonacciaux (int n,int sum,int sumi)
            {
                int swap;
                if (n<=0)
                    return 0;

                else
                {
                    printf("%d",sum);
                    swap=sum;
                    sum+=sumi;
                    sumi=swap;
                    return refibonacciaux((n-1),sum,sumi);
                }
            }
            int resomavetor (int *vet,int tamanho)
            {
                int soma=0;
                if (tamanho<=0)
                    return 0;
                else
                    return resomavetoraux (vet,tamanho,soma);
            }
            int resomavetoraux (int *vet,int tamanho,int soma)
            {
                if (tamanho<=0)
                    return soma;
                else
                {
                    tamanho--;
                    soma+=vet[tamanho];
                    resomavetoraux (vet,tamanho,soma);
                }
            }
            int remenorvetor (int *vet,int tamanho)
            {
                int me=100;
                if (tamanho<=0)
                    return 0;
                else
                    return remenorvetoraux (vet,tamanho,me);
            }
            int remenorvetoraux (int *vet,int tamanho,int me)
            {
                if (tamanho<=0)
                    return me;
                else
                {
                    tamanho--;
                    if(me<vet[tamanho])
                    me=vet[tamanho];
                    remenorvetoraux (vet,tamanho,me);
                }
            }
            int repot (int n,int valor)
            {
                if (n<=0||valor<=0)
                    return 0;

                else
                    return repotaux(n,1,valor);
            }
            int repotaux(int n,int acc,int valor)
            {
                if (n<=0)
                    return acc;

                else
                    return repotaux((n-1),acc*=valor,valor);
            }











