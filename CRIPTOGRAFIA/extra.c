#include <stdio.h>
#include <stdlib.h>
#include "fvmslib.h"
#include "vmslib.h"

//#define DEBUG

            int TAMANHO_SENHA_CLIENTE=8;
            int TAMANHO_SENHA_GERENTE=5;
            int KEY2 = 50699;
            long int KEY3 = 495549505755;
            int KEY4 = 156;
            int KEY5 = 3;

            typedef struct log_cliente
            {
                char username    [32];
                char passwd      [20];
            } log_cliente;

            typedef struct log_cliente_encripted
            {
                int  *username;
                int  *passwd;
            } log_cliente_encripted;


//BUSCADOR DO CHAR DE CONTROLE

            int achaofim(int *cnt)
            {
                int count=0;

                while (cnt[count]!=KEY2*-1)
                    count++;

                return count+1;
            }

//_____________ENCRIPTADORES E DECRIPTADORES_______________//

//ENCRIPTADOR

            int * enigma(char *data_in)
            {
                srand(time(NULL));

                #ifdef DEBUG
                printf("\nENIGMA HAS BEEN TURNED ON\n\n");
                #endif // DEBUG

                int n=contastring(data_in);
                int *data_out;
                int aux=0;
                int RANDOM_KEY=rand()%1000;

                #ifdef DEBUG
                printf("A CHAVE DE ENCRIPTAÇÃO ALEATORIA DESTA SESSÃO É : %d\n",RANDOM_KEY);
                #endif // DEBUG

                data_out=alocavetor_int(n+2);

                while (aux < n)
                {
                    #ifdef DEBUG
                    printf("O CHAR %c ENCRIPTADO SE TORNA >  ",data_in[aux]);
                    #endif // DEBUG

                    data_out[aux]=data_in[aux];

                    data_out[aux]*=KEY5;

                    data_out[aux]*=KEY4;

                    data_out[aux]*=RANDOM_KEY;

                    data_out[aux]+=(aux+9)*KEY4;

                    #ifdef DEBUG
                    printf("%i\n",data_out[aux]);
                    #endif // DEBUG

                    aux++;
                }
                data_out[aux]=RANDOM_KEY*KEY4;

                aux++;

                data_out[aux]=KEY2*-1;

            #ifdef DEBUG
            botavetorhorizontal_int(data_out,n+2);
            #endif // DEBUG

                return data_out;
            }

//DESENCRIPTADOR

            char * christopher(int *data_in)
            {
                #ifdef DEBUG
                printf("\nCHRISTOPHER HAS BEEN TURNED ON\n\n");
                #endif // DEBUG

                int n=achaofim(data_in);
                char *data_out;
                int aux=0;
                int RANDOM_KEY=data_in[n-2]/KEY4;

                #ifdef DEBUG
                printf("A CHAVE DE ENCRIPTAÇÃO ALEATORIA DESTA SESSÃO É : %d\n",RANDOM_KEY);
                #endif // DEBUG

                data_out=alocavetor_char(n-2);

                while (aux < n-2)
                {

                    #ifdef DEBUG
                    printf("A ENTRADA %d DESENCRIPTADA VOLTA A SER : >  ",data_in[aux]);
                    #endif // DEBUG

                    data_in[aux]-=(aux+9)*KEY4;

                    data_in[aux]/=RANDOM_KEY;

                    data_in[aux]/=KEY4;

                    data_in[aux]/=KEY5;

                    data_out[aux]=data_in[aux];

                    #ifdef DEBUG
                    printf("%c\n",data_out[aux]);
                    #endif // DEBUG

                    aux++;
                }

                #ifdef DEBUG
                botavetorhorizontal_char(data_out,n-3);
                #endif // DEBUG

                return data_out;
            }


//MANUTENÇÂO DOS DADOS ENCRIPTADOS____________________//

//ESCRITA

            void bota_cdata_arquivo (log_cliente_encripted data_flow,FILE *arquivo)
            {
                int aux=0;

                while (1)
                {
                    fprintf(arquivo,"%d ",data_flow.username[aux]);

                    if(data_flow.username[aux]==KEY2*-1)
                    {
                        fprintf(arquivo,"\n");
                        break;
                    }

                    aux++;
                }


                aux=0;

                while (1)
                {
                    fprintf(arquivo,"%d ",data_flow.passwd[aux]);

                    if(data_flow.passwd[aux]==KEY2*-1)
                    {
                        fprintf(arquivo,"\n");
                        break;
                    }
                    aux++;
                }
            }

//LEITURA

            int cata_cdata_arquivo (log_cliente_encripted data_flow,FILE *arquivo)
            {
                int aux=0;

                while (1)
                {
                    if (feof(arquivo))
                        return 0;

                    fscanf(arquivo,"%d",&data_flow.username[aux]);

                    if(data_flow.username[aux]==KEY2*-1)
                        break;

                    aux++;
                }

                aux=0;

                while (1)
                {
                    if (feof(arquivo))
                        return 0;

                    fscanf(arquivo,"%d",&data_flow.passwd[aux]);

                    if(data_flow.passwd[aux]==KEY2*-1)
                        break;

                    aux++;
                }
            }


//____________TESTE DO FUNCIONAMENTO DA FUNÇÃO__________________-//

            novo_cliente ()
            {

                log_cliente new_log;
                log_cliente_encripted new_log_e,tester;/**/

                char *compare_string;
                int procedure=0;

                FILE *login;

                //ALOCA MEMORIA PARA A STRUCT DE TESTES
                tester.username=calocavetor_int(34);/**/
                tester.passwd=calocavetor_int(22);/**/

                login=abrearquivo_readwrite("clientlogins");



                while (1)
                {
                    login=file_set_start(login);


                    if (procedure == 1)
                    {
                        printf("NUMERO DE CONTA JÁ EXISTE, DIGITE OUTRO:\n");
                        catastring(new_log.username);
                    }
                    else
                    {
                            printf("DIGITE UM NUMERO PARA CONTA:\n");
                            catastring(new_log.username);
                    }

                    //ZERA VARIAVEL DE CONTROLE DO FUNCIONAMENTO
                    procedure=0;

                    while (!feof(login))
                    {
                        //COLETA DO ARQUIVO UMA STRUCT COM LOGIN E SENHAS ENCRIPTADOS
                        cata_cdata_arquivo(tester,login);

                        //DESENCRIPTA O NOME DE USUARIO PARA O TESTE FUTURO

                        compare_string = christopher(tester.username);

                        //TESTA SE AS INFORMAÇÕES OBTIDAS JÁ EXISTEM
                        if (comparastrings(compare_string,new_log.username)==1)
                        {
                            procedure=1;
                            break;
                        }
                    }


                    //NO CASO DO LOGIN DESEJADO ESTAR DISPONIVEL
                    if (procedure==0)
                    {
                        printf("NOME DE USUARIO DISPONIVEL\n");
                        //RECEBE A SENHA DO USUARIO
                        printf("DIGITE AGORA SUA SENHA\n");
                        catastring(new_log.passwd);

                        //ENCRIPTA O USUARIO DO CLIENTE
                        new_log_e.username=enigma(new_log.username);

                        //ENCRIPTA A SENHA DO CLIENTE
                        new_log_e.passwd=enigma(new_log.passwd);

                        break;
                    }
                }

                //ESCREVE AS INFORMAÇÕES ENCRIPTADAS NO ARQUIVO
                bota_cdata_arquivo(new_log_e,login);

                fclose(login);

                //LIBERA OS VETORES UTILIZADOS NO PROCESSO DE ENCRIPTAÇÃO
                liberavetor_int(new_log_e.username);/**/
                liberavetor_int(new_log_e.passwd);/**/
                liberavetor_char(compare_string);/**/
            }


            int main()
            {
                novo_cliente();
                return 0;
            }



