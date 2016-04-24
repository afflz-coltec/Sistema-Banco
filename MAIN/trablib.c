#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "vmslib.h"
#include "fvmslib.h"
#include "trablib.h"
#include "gerente.h"
#include "cliente.h"


//_________________________UTILIDADES_____________________________//


        void data (int *dia, int *mes, int *ano)
        {
            struct tm *local;
            time_t t;

            t = time(NULL);
            local = localtime(&t);

            *dia = local -> tm_mday;
            *mes = local -> tm_mon+1;
            *ano = local -> tm_year+1900;
        }

        int tira_linha_arquivo (char *arquivo, int line)
        {
            FILE *entrada;
            FILE *saida;
            int linha=1, i;
            char textoarquivo[20], aux[40] = "mv ";

            if ((entrada = fopen(arquivo, "r")) == 0)
            {
                printf("Impossivel abrir arquivo..\n");
                exit(1);
            }

            if ((saida = fopen("copia", "w")) == 0)
            {
                printf("Impossivel abrir arquivo...\n");
                exit(1);
            }

            rewind(entrada); //certifica se o cursor esta no primeiro caractere do arquivo

            for(i = 0; !feof(entrada);i++)
            {
                memset(textoarquivo, '\0', 20);
                fgets(textoarquivo, 21, entrada);

                if(linha == line)
                {
                    fputc('\n', saida);
                    linha++;
                    continue;
                }

                linha++;
                fputs(textoarquivo, saida);
            }

            fclose(entrada);
            fclose(saida);

            strcat (aux, "copia ");
            strcat (aux, arquivo);
            remove (arquivo);
            system(aux);
        }

        conta_cliente cata_dados_cliente (FILE *arquivo)
        {
        conta_cliente um;

        catastring_arquivo(um.nome, arquivo);

        fscanf (arquivo," %f %f %i %i %i", &um.saldo, &um.limite, &um.dia, &um.mes, &um.ano);

        return um;
        }

        int login (FILE *arquivo_de_login,login_data *return_log)
        {
            int procedure,check,count=0;
            login_data log,tester;

            system("clear");

            while (count <= 3)
            {
                __fpurge(stdin);

                arquivo_de_login=file_set_start(arquivo_de_login);

                printf("\t@@ DIGITE SEU NOME DE USUARIO @@\n\t");
                catastring(log.username);
                printf("\t@@ DIGITE SUA SENHA @@\n\t");
                catastring(log.passwd);

                while (!feof(arquivo_de_login))
                {
                    catastring_arquivo(tester.username,arquivo_de_login);
                    catastring_arquivo(tester.passwd,arquivo_de_login);

                    procedure=comparastrings(tester.username,log.username);

                    if (procedure==1)
                    {
                        check=comparastrings(tester.passwd,log.passwd);
                        if(check==1)
                        {
                            system("clear");
                            printf("## ACESSO PERMITIDO ##\n");
                            igualastring(log.username,return_log->username);
                            igualastring(log.passwd,return_log->passwd);
                            return 1;
                        }
                        else
                        {
                            system("clear");
                            printf("%% A SENHA DIGITADA NÃO CORRESPONDE AO USUARIO DIGITADO %%\n");
                            procedure=0;
                            check=0;
                        }
                    }
                    else
                    {
                        system("clear");
                        printf("%% O USUARIO DIGITADO NÃO CONSTA EM NOSSO SISTEMA %%\n\n\n");
                        procedure=0;
                        check=0;
                    }
                }
            count++;
            }
            system("clear");
            printf("NUMERO DE TENTATIVAS EXCEDIDO\n");
            return 0;
        }

        int compara_login_arquivo (login_data new_log,FILE * login)
        {
            login_data tester;
            int procedure;

            while (!feof(login))
            {
                catastring_arquivo(tester.username,login);
                catastring_arquivo(tester.passwd,login);

                procedure=comparastrings(tester.username,new_log.username);

                if (procedure==1)
                {
                    return 1;
                }
            }
            return 0;
        }

        operation_code  cata_extrato_arquivo (operation_code opcode ,FILE *arquivo)
        {
		if(!(feof(arquivo)))
		{
		        fscanf (arquivo,"%d %f \n",&opcode.tipo,&opcode.valor);
		        fscanf (arquivo,"%d %d %d \n",&opcode.dia,&opcode.mes,&opcode.ano);
		        catastring_arquivo (opcode.numconta_origem,arquivo);
		        catastring_arquivo (opcode.numconta_destino,arquivo);
		}


            return opcode;
        }

        void *bota_dados_cliente (conta_cliente um,FILE *arquivo)
        {
        botastring_arquivo(um.nome,arquivo);

        fprintf (arquivo,"%f\n %f\n%i %i %i\n", um.saldo, um.limite, um.dia, um.mes, um.ano);
        }

        void bota_arquivo_extrato(operation_code op_atual,FILE *arquivo_extrato)
        {
            data(&op_atual.dia,&op_atual.mes,&op_atual.ano);

            if(!(!arquivo_extrato))
            {
                fprintf (arquivo_extrato,"%d %f \n",op_atual.tipo,op_atual.valor);
                fprintf (arquivo_extrato,"%d %d %d \n",op_atual.dia,op_atual.mes,op_atual.ano);
                botastring_arquivo (op_atual.numconta_origem,arquivo_extrato);
                botastring_arquivo (op_atual.numconta_destino,arquivo_extrato);
            }
        }

        login_data nomeia_arquivo_extrato (login_data new_log)
        {
            igualastring (new_log.username,new_log.nome_arquivo_extrato);
            new_log.nome_arquivo_extrato[8]='e';
            new_log.nome_arquivo_extrato[9]='\0';

            return new_log;
        }

        void altera_reserva_banco(bank_info client_data)
        {
            FILE *banco;
            bank_info bank_data;

            banco=abrearquivo_readwrite ("bankinfo");

            printf("ATUALIZANDO AS INFORMAÇÕES DO BANCO ... ");

            //OBTENDO AS INFORMAÇÕES ATUAIS DO BANCO
            if(!(!banco))
            {
                banco=file_set_start(banco);

                fscanf(banco,"%f %d %d",&bank_data.reservas,&bank_data.num_clientes,&bank_data.num_gerentes);

                bank_data.reservas+=client_data.reservas;
                bank_data.num_clientes+=client_data.num_clientes;
            }
            fclose(banco);

            banco=novoarquivo_readwrite ("bankinfo");

            //ESCREVENDO NO NOVO ARQUIVO DO BANCO
            if(!(!banco))
            {
                fprintf(banco,"%f %d %d",bank_data.reservas,bank_data.num_clientes,bank_data.num_gerentes);
                printf("OK\n");
            }
            fclose(banco);
        }


//_________________________MATRING_FUNCTIONS_____________________________//


        char ** catatudo_arquivo (char **matring,FILE *arquivo)
        {
            int aux=-1,aux2=0;

            while(!feof(arquivo))
            {
                aux++;
                matring[aux2][aux]=fgetc(arquivo);

                if (matring[aux2][aux]== '\n')
                {
                    matring[aux2][aux]='\0';
                    aux2++;
                    aux=-1;
                    matring=realocamatrix_char(matring,aux2+1,50);
                }
            }

            return matring;
        }

        int compara_palavras(char *a,char *b,int count)
        {
            if (a[count] > b[count])
                return 0;

            if (a[count] < b[count])
                return 1;

            if (a[count]==b[count])
                return compara_palavras(a,b,count+1);

        }

        char ** ordena_matring (char **matring,int tamanho)
        {
            int a=0,b=(tamanho-1),i;
            char swap[50];

            for (; a<tamanho; a++)
                for (b=(tamanho-1);b>0; b--)
                    if ((i=compara_palavras(matring[b],matring[b-1],0))==1)
                    {
                        igualastring(matring[b],swap);
                        igualastring(matring[b-1],matring[b]);
                        igualastring(swap,matring[b-1]);
                    }
            return matring;
        }


//_________________________OPERATIONS_FUNCTIONS_____________________________//
//_____________________________________________________________//
//_________________________GERAL_______________________________//
//_____________________________________________________________//


        void menu_cliente (login_data login_atual)//A SER FEITO
        {
            int opt=10;
            conta_cliente atual;
            FILE *arquivo_dados_cliente;

            arquivo_dados_cliente = abrearquivo_readonly(login_atual.username);
            atual = cata_dados_cliente(arquivo_dados_cliente);
            fclose (arquivo_dados_cliente);

            while(opt != 0)
            {
                system("clear");

                printf("\n\n\t## ___________________________________________________ ##\n");
                printf(    "\t BEM VIND@, ");                        botastring(atual.nome);
                printf(    "\t## ___________________________________________________ ##\n\n");

                        printf("\t\t ________________________________________ \n");
                        printf("\t\t|                                        |\n");
                        printf("\t\t|                 OPÇÕES:                |\n");
                        printf("\t\t|___________________  ___________________|\n");
                        printf("\t\t|                   ||                   |\n");
                        printf("\t\t| 1 - SALDO         || 2 - LIMITE        |\n");
                        printf("\t\t|___________________||___________________|\n");
                        printf("\t\t|                   ||                   |\n");
                        printf("\t\t| 3 - DATA CADASTRO || 4 - EXTRATO       |\n");
                        printf("\t\t|___________________||___________________|\n");
                        printf("\t\t|                   ||                   |\n");
                        printf("\t\t| 5 - SAQUE         || 6 - DEPOSITO      |\n");
                        printf("\t\t|___________________||___________________|\n");
                        printf("\t\t|                   ||                   |\n");
                        printf("\t\t| 7 - TRANSFERENCIA || 0 - SAIR          |\n");
                        printf("\t\t|___________________||___________________|\n");
                        printf("\t\t|________________________________________|\n");

                scanf("%d",&opt);

                __fpurge(stdin);


                switch (opt)
                {
                    case 1 : visualizar_saldo (login_atual);    break;
                    case 2 : visualizar_limite (login_atual);   break;
                    case 3 : data_de_cadastro (login_atual);    break;
                    case 4 : visualizar_extrato (login_atual);  break;
                    case 5 : retirar_da_conta (login_atual);    break;
                    case 6 : depositar_na_conta (login_atual);  break;
                    case 7 : transferir_da_conta (login_atual); break;
                }
            }
        }

        void login_cliente ()
        {
            int check;
            FILE *login_file;
            login_data return_log;

            login_file=abrearquivo_readwrite("clientlogins");

            check=login(login_file,&return_log);

           return_log=nomeia_arquivo_extrato(return_log);

            if (check == 1)
                menu_cliente(return_log);
        }

        void menu_gerente (login_data login_atual)//A SER FEITO
        {
            int opt=10;
            conta_cliente atual;


            while(opt != 0)
            {
                system("clear");

                      printf("\n\t\t__________________________________________\n");
                        printf("\t\t        BEM VIND@ GERENTE NUM %s,         \n",login_atual.username);
                        printf("\t\t ________________________________________ \n");
                        printf("\t\t|                                        |\n");
                        printf("\t\t|                 OPÇÕES:                |\n");
                        printf("\t\t|________________________________________|\n");
                        printf("\t\t|                                        |\n");
                        printf("\t\t| 1/2 - ADICIONAR/REMOVER CLIENTE        |\n");
                        printf("\t\t|________________________________________|\n");
                        printf("\t\t|                                        |\n");
                        printf("\t\t| 3/4 - ADICIONAR/REMOVER GERENTES       |\n");
                        printf("\t\t|________________________________________|\n");
                        printf("\t\t|                                        |\n");
                        printf("\t\t| 5   - LISTAR CLIENTES                  |\n");
                        printf("\t\t|________________________________________|\n");
                        printf("\t\t|                                        |\n");
                        printf("\t\t| 6   - LISTAR RESERVAS FISICAS DO BANCO |\n");
                        printf("\t\t|________________________________________|\n");
                        printf("\t\t|                                        |\n");
                        printf("\t\t| 7   - ALTERAR LIMITE DE TRANFERENCIA   |\n");
                        printf("\t\t|________________________________________|\n");
                        printf("\t\t|______________________________ 0 - SAIR |\n");

                scanf("%d",&opt);

                __fpurge(stdin);

                switch (opt)
                {
                    case 1 : novo_cliente ();                 break;
                    case 2 : deletar_cliente ();              break;
                    case 3 : novo_gerente ();                 break;
                    case 4 : deletar_gerente ();              break;

                    case 5 : printf("ORDEM ALFABETICA(1)\nORDEM DE CADASTRO(2)");
                             scanf("%d",&opt);
                                switch(opt)
                                {
                                    case 1 : listar_clientes_alfabetico ();   break;
                                    case 2 :  listar_clientes_data ();         break;
                                }
                                break;

                    case 6 : listar_reservas ();              break;
                    case 7 : alterar_limite_tranferencia ();  break;

                    case 42 : dar_um_calote_no_banco_e_viajar_pra_europa_com_o_dinheiro_e_uma_nova_identidade (); break;
                    case 420 : sair_da_vida_de_gerente_de_banco_pra_ir_vender_minha_arte_na_praia (); break;
                }
            }
        }

        void login_gerente()
        {
            int check;
            login_data return_log;
            FILE *login_file;

            login_file=abrearquivo_readwrite("managerlogins");
            check=login(login_file,&return_log);

            if (check == 1)
                menu_gerente(return_log);


        }


        void menu_geral ()
        {
            int opt=10;

            while(opt != 0)
            {
                system("clear");

                printf("\n\n\t## ___________________________________________________ ##\n");
                printf(    "\t##                                                     ##\n");
                printf(    "\t## BEM VINDO AO TERMINAL DIGITAL DE OPERAÇÕES DO BANCO ##\n");
                printf(    "\t## ___________________________________________________ ##\n\n");

                        printf("\t\t ________________________________________ \n");
                        printf("\t\t|                                        |\n");
                        printf("\t\t|   ESCOLHA SUA OCUPAÇÃO EM NOSSO BANCO: |\n");
                        printf("\t\t|___________________  ___________________|\n");
                        printf("\t\t|                   ||                   |\n");
                        printf("\t\t|    1 - CLIENTE    ||    2 - GERENTE    |\n");
                        printf("\t\t|___________________||___________________|\n");
                        printf("\t\t|______________________________ 0 - SAIR |\n");



                scanf("%d",&opt);


                    switch (opt)
                    {
                        case 1:
                        login_cliente ();
                        break;

                        case 2:
                        login_gerente ();
                        break;
                    }
            }
        }




