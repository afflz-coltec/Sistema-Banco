#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "vmslib.h"
#include "fvmslib.h"
#include "trablib.h"
#include "gerente.h"
#include "cliente.h"


//_________________________DEFINIÇÃO_CONSTANTES_____________________________//
        #ifndef CONSTANTES_GERAIS
        #define CONSTANTES_GERAIS
        int TAMANHO_LOGIN=8;
        int TAMANHO_SENHA_CLIENTE=8;
        int TAMANHO_SENHA_GERENTE=5;
        #endif // CONSTANTES_GERAIS

//_____________________________________________________________//
//_________________________GERENTE_____________________________//
//_____________________________________________________________//

 //_________________________MANIPULAÇÃO_DE_CONTAS _____________//


        void novo_cliente ()
        {
            conta_cliente nova_conta;
            login_data new_log,tester;
            bank_info bank_data,client_data;
            int procedure=10,tamanho_teste, i;
            FILE *login,*conta,*clientes,*banco,*extrato;

//___________________________________________________________________________________//
//LEITURA DAS INFORMAÇÕES DO CLIENTE_________________________________________________//
//___________________________________________________________________________________//
            printf("Digite o nome do cliente:\n");
            catastring(nova_conta.nome);

            printf("Digite o deposito inicial do cliente:\n");
            scanf("%f",&nova_conta.saldo);

            while (nova_conta.saldo<=0)
            {
                printf("O deposito inicial do cliente precisa ser positivo:\n");
                scanf("%f",&nova_conta.saldo);
            }

            printf("Digite o limite de transferencia do cliente:\n");
            scanf("%f",&nova_conta.limite);

            while (nova_conta.limite<=0)
            {
                printf("O limite de tranferencia do cliente precisa ser positivo:\n");
                scanf("%f",&nova_conta.limite);
            }


            __fpurge(stdin);

            data (&nova_conta.dia, &nova_conta.mes, &nova_conta.ano);
//___________________________________________________________________________________//
            printf("\n________________________________________________\n");

            __fpurge(stdin);

//___________________________________________________________________________________//
//LEITURA_DO_NOME_DE_USUARIO_________________________________________________________//
//___________________________________________________________________________________//
            login=abrearquivo_readwrite("clientlogins");

            system("clear");

            while (1)
            {
                login=file_set_start(login);

                while (1)
                {

                    printf("Digite um numero para a conta com 8 digitos numericos:\n");
                    catastring(new_log.username);

                    for (i=0; i<strlen(new_log.username); i++)
                    {
                        if (isdigit (new_log.username[i]) == 0)
                        {
                            printf ("Você deve digitar 8 numeros\n");
                            break;
                        }
                    }

                    if (i==contastring(new_log.username))
                        break;
                }

                tamanho_teste=contastring(new_log.username);
                procedure=0;

                if (tamanho_teste==TAMANHO_LOGIN)
                {
                    procedure = compara_login_arquivo(new_log,login);

                    if(procedure==1)
                    printf("%% ERRO : O numero de conta digitado já existe, entre com outro por favor %%\n\n");

                    else if (procedure==0)
                    {
                        system("clear");
                        printf("## Numero de conta registrado com sucesso ##\n\n");
                        break;
                    }
                }

                else
                {
                    system("clear");
                    printf("%% ERRO : Numero de conta em tamanho errado  %%\n\n");
                }

            }
//___________________________________________________________________________________//
//LEITURA_DA_SENHA_DO_USUARIO________________________________________________________//
//___________________________________________________________________________________//
            while (1)
            {
                printf("@@ Digite agora sua senha entre 8 e 20 caracteres @@\n\n");
                catastring(new_log.passwd);

                tamanho_teste=contastring(new_log.passwd);

                if (tamanho_teste <= TAMANHO_SENHA_CLIENTE-1 ||tamanho_teste >= 20)
                {
                    printf("%% ERRO : Sua senha precisa ter entre 8 e 20 caracteres %%\n\n");
                    continue;
                }
                else
                {
                    printf("## Senha registrada com sucesso ##\n\n");
                    break;
                }
            }
//___________________________________________________________________________________//
//ESCRITA_DOS DADOS OBTIDOS NO ARQUIVO DE LOGIN______________________________________//
//___________________________________________________________________________________//
            printf("REGISTRANDO USUARIO NOS SERVIDORES DO BANCO ... ");
            if(!(!login))
            {
                botastring_arquivo(new_log.username,login);
                botastring_arquivo(new_log.passwd,login);
                printf("OK\n");
            }
            fclose(login);

//___________________________________________________________________________________//

//___________________________________________________________________________________//
//ABERTURA DO ARQUIVO DE REGISTRO DE OPERAÇÔES_______________________________________//
//___________________________________________________________________________________//
            printf("DEFININDO ESPAÇO PARA O EXTRATO DO CLIENTE ... ");
            new_log = nomeia_arquivo_extrato (new_log);

            extrato=abrearquivo_readwrite(new_log.nome_arquivo_extrato);

            fclose(extrato);
            printf("OK\n");
//___________________________________________________________________________________//

//___________________________________________________________________________________//
//ESCRITA_DOS DADOS OBTIDOS NO ARQUIVO DE CONTA DO USUARIO___________________________//
//___________________________________________________________________________________//
            conta=abrearquivo_readwrite(new_log.username);
            printf("REGISTRANDO AS INFORMAÇÕES DO CLIENTE NOS SERVIDORES ... ");
            if(!(!conta))
            {
                botastring_arquivo(nova_conta.nome,conta);
                botafloat_arquivo(nova_conta.saldo,conta);
                botaint_arquivo(nova_conta.limite,conta);
                botaint_arquivo_espaco(nova_conta.dia,conta);
                botaint_arquivo_espaco(nova_conta.mes,conta);
                botaint_arquivo_espaco(nova_conta.ano,conta);
                printf("OK\n");
            }

            fclose(conta);
//___________________________________________________________________________________//

//___________________________________________________________________________________//
//ADICIONAR O CLIENTE A LISTA DE CLIENTES DO BANCO___________________________________//
//___________________________________________________________________________________//
            clientes=abrearquivo_readwrite ("listofclients");

            botastring_arquivo(nova_conta.nome,clientes);

            fclose(clientes);
//___________________________________________________________________________________//

//___________________________________________________________________________________//
//ADICIONAR O CLIENTE AS INFORMAÇÕES DO BANCO________________________________________//
//___________________________________________________________________________________//
            client_data.num_clientes=1;
            client_data.reservas=nova_conta.saldo;

            altera_reserva_banco(client_data);

//___________________________________________________________________________________//
        }

        void novo_gerente ()
        {
            bank_info bank_data;
            login_data new_log,tester;
            int procedure=10,tamanho_teste, i;
            FILE *login, *arquivo_banco;

//___________________________________________________________________________________//
//LEITURA_DO_NOME_DE_USUARIO_________________________________________________________//
//___________________________________________________________________________________//
            login=abrearquivo_readwrite("managerlogins");

            while (1)
            {
                login=file_set_start(login);

                while (1)
                {
                    printf("Digite um numero para a conta com 8 digitos numericos:\n");
                    catastring(new_log.username);

                    for (i=0; i<strlen(new_log.username); i++)
                    {
                        if (isdigit (new_log.username[i]) == 0)
                        {
                            printf ("Você deve digitar 8 numeros\n");
                            break;
                        }
                    }

                    if (i==contastring(new_log.username))
                        break;
                }

                tamanho_teste=contastring(new_log.username);
                procedure=0;

                if (tamanho_teste==TAMANHO_LOGIN)
                {
                    procedure = compara_login_arquivo(new_log,login);

                    if(procedure==1)
                    printf("%% ERRO : O numero de conta digitado já existe, entre com outro por favor %%\n\n");

                    else if (procedure==0)
                    {
                        system("clear");
                        printf("## Numero de conta registrado com sucesso ##\n\n");
                        break;
                    }
                }

                else
                {
                    system("clear");
                    printf("%% ERRO : Numero de login em tamanho errado  %%\n\n");
                }

            }
//___________________________________________________________________________________//
//LEITURA_DA_SENHA_DO_USUARIO________________________________________________________//
//___________________________________________________________________________________//
            while (1)
            {
                printf("@@ Digite agora sua senha entre 5 e 20 caracteres @@\n\n");
                catastring(new_log.passwd);

                tamanho_teste=contastring(new_log.passwd);

                if (tamanho_teste <= TAMANHO_SENHA_GERENTE -1 ||tamanho_teste >= 20)
                {
                    printf("%% ERRO : Sua senha precisa ter entre 8 e 20 caracteres %%\n\n");
                    continue;
                }
                else
                {
                    printf("## Senha registrada com sucesso ##\n\n");
                    break;
                }
            }

//ADICIONA AO ARQUIVO DO BANCO O NOVO GERENTE

            bank_data.num_gerentes = 1;
            bank_data.num_clientes = 0;
            bank_data.reservas = 0;

            altera_reserva_banco(bank_data);
//___________________________________________________________________________________//
//ESCRITA_DOS DADOS OBTIDOS NO ARQUIVO DE LOGIN______________________________________//
//___________________________________________________________________________________//
            if(!(!login))
            {
                botastring_arquivo(new_log.username,login);
                botastring_arquivo(new_log.passwd,login);
            }
            fclose(login);

        }

        void deletar_cliente ()
        {
            bank_info client_data;
            login_data ex_conta, tester;
            conta_cliente cliente, teste;
            FILE *login, *banco, *client, *lista, *arquivo_info_ex_cliente;
            int i=0,count=0,procedure;


//REMOVE O LOGIN E A SENHA DO ARQUIVO CLIENTLOGINS

            login=abrearquivo_readwrite("clientlogins");
            login=file_set_start(login);

            printf ("Digite o numero da conta a ser apagada\n");
            catastring(ex_conta.username);

            for (count=0; !feof (login); count++)
            {
                catastring_arquivo(tester.username,login);
                catastring_arquivo(tester.passwd,login);

                procedure = comparastrings(tester.username,ex_conta.username);

                if (procedure == 1)
                {
                    tira_linha_arquivo("clientlogins", count+1);
                    tira_linha_arquivo("clientlogins", count+2);
                    break;
                }

                else
                    count++;
            }

            fclose (login);

//ABRE O ARQUIVO DO USUARIO E PEGA AS INFORMAÇÕES NECESSARIAS PARA USO POSTERIOR

            arquivo_info_ex_cliente = abrearquivo_readwrite (ex_conta.username);
            arquivo_info_ex_cliente = file_set_start (arquivo_info_ex_cliente);

            cliente = cata_dados_cliente (arquivo_info_ex_cliente);

//ALTERA O VALOR DO DINHEIRO POSSUIDO NO BANCO E O NUMERO DE CLIENTES DO ARQUIVO BANKINFO

            client_data.reservas = cliente.saldo * (-1);
            client_data.num_clientes =  client_data.num_clientes * (-1);
            client_data.num_gerentes = 0;

            altera_reserva_banco(client_data);

//APAGA A LINHA DO NOME DO CLIENTE DO ARQUIVO LISTOFCLIENTS

            lista = abrearquivo_readwrite ("listofclients");
            lista = file_set_start (lista);

            for (count=0; !feof (lista); count++)
            {
                catastring_arquivo(teste.nome,lista);

                procedure = comparastrings(teste.nome,cliente.nome);

                if (procedure == 1)
                {
                    tira_linha_arquivo("listofclients", count+1);
                    break;
                }

                else
                    count++;
            }

//REMOVE O ARQUIVO COM AS INFORMAÇÔES DO CLIENTE E SUAS OPERAÇÕES

            ex_conta = nomeia_arquivo_extrato(ex_conta);
            remove (ex_conta.username);
            remove (ex_conta.nome_arquivo_extrato);
            fclose (lista);
            fclose(arquivo_info_ex_cliente);

        }

        void deletar_gerente ()
        {
		int count, procedure;
		bank_info dados;
		login_data ex_conta, tester;
		FILE *login, *banco;

	//REMOVE O LOGIN E A SENHA DO ARQUIVO MANAGERLOGINS

	   login=abrearquivo_readwrite("managerlogins");
           login=file_set_start(login);

            printf ("Digite o numero da conta a ser apagada\n");
            catastring(ex_conta.username);

            for (count=0; !feof (login); count++)
            {
                catastring_arquivo(tester.username,login);
                catastring_arquivo(tester.passwd,login);

                procedure = comparastrings(tester.username,ex_conta.username);

                if (procedure == 1)
                {
                    tira_linha_arquivo("managerlogins", count+1);
                    tira_linha_arquivo("managerlogins", count+2);
                    break;
                }

                else
                    count++;
            }

            fclose (login);

			//TROCA O NUMERO DE GERENTES DO ARQUIVO BANKINFO

            dados.num_gerentes = dados.num_gerentes - 1;
            dados.num_clientes = 0;
            dados.reservas = 0;

            //RESCREVE AS INFORMAÇÕES NO ARQUIVO BANKINFO
            altera_reserva_banco(dados);
        }

//_________________________LISTAGEM_DE_DADOS___________________//


        void listar_clientes_data ()
        {
            FILE *clientes;
            int num_linhas,i,w8;
            char **nomes;


            clientes = abrearquivo_readonly("listofclients");

            nomes = alocamatrix_char(5,50);
            nomes = catatudo_arquivo(nomes,clientes);

            clientes=file_set_start(clientes);
            num_linhas=conta_linhas_arquivo(clientes)-1;

            for (i=0;i<num_linhas;i++)
                {
                    botastring(nomes[i]);
                }

            printf("TECLE 1 E DIGITE ENTER PARA VOLTAR\n");
            scanf("%d",&w8);

            liberamatrix_char(nomes,num_linhas,50);
            fclose(clientes);
        }

        void listar_clientes_alfabetico ()
        {
            FILE *clientes;
            int num_linhas,i,w8;
            char **nomes;


            clientes = abrearquivo_readonly("listofclients");

            nomes = alocamatrix_char(5,50);
            nomes = catatudo_arquivo(nomes,clientes);

            clientes=file_set_start(clientes);
            num_linhas=conta_linhas_arquivo(clientes)-1;

            nomes = ordena_matring (nomes,num_linhas);

            for (i=0;i<num_linhas;i++)
                {
                    botastring(nomes[i]);
                }

            printf("TECLE 1 E DIGITE ENTER PARA VOLTAR\n");
            scanf("%d",&w8);

            liberamatrix_char(nomes,num_linhas,50);
            fclose(clientes);
        }

        void listar_reservas ()
        {
            FILE *banco;
            bank_info bank_data;
            int w8;

            banco = abrearquivo_readonly ("bankinfo");

            fscanf (banco,"%f %d %d",&bank_data.reservas,&bank_data.num_clientes,&bank_data.num_gerentes);

            printf ("\n\nAtualmente o banco possui :\n%.2f REAIS FISICOS\n",bank_data.reservas);
            printf ("%d Clientes\n\n",bank_data.num_clientes);

            printf("TECLE 1 E DIGITE ENTER PARA VOLTAR\n");
            scanf("%d",&w8);

            fclose (banco);
        }


//_______________ALTERAÇÃO DE LIMITES DE TRANFERENCIA________________//


        void alterar_limite_tranferencia ()
        {
			conta_cliente info_atual;
            bank_info client_data;
            operation_code op_atual;
            float limite;
            FILE *conta,*arquivo_extrato;
            char username[9];

            printf ("Qual o numero da conta do cliente?\n");
            fgets (username, 9, stdin);

            conta=abrearquivo_readwrite(username);

//_______________MOVIMENTAÇÃO CONTA CLIENTE________________//

            //OBTENDO AS INFORMAÇÕES ATUAIS E DEPOISITO DO CLIENTE
            if(!(!conta))
            {
                conta=file_set_start(conta);

                info_atual=cata_dados_cliente(conta);

                printf ("Para qual valor voce quer alterar o limite de transferencia?\n");
                scanf ("%f", &limite);

               while (limite <= 0)
                {
                    printf ("O limite deve ter valor positivo\nDigite novamente: ");
                    scanf ("%f", &limite);
                }

                info_atual.limite = limite;

                printf ("O novo limite eh R$%.2f\n", info_atual.limite);
            }

            fclose (conta);

            conta=novoarquivo_readwrite(username);

            //SOBREESCREVENDO AS MESMAS INFORMAÇÕES EM UM NOVO ARQUIVO
            if(!(!conta))
                {
                    bota_dados_cliente(info_atual,conta);
                }
            fclose (conta);

        }


//_________________________GERENTE_FELIZ_____________________________//


        void dar_um_calote_no_banco_e_viajar_pra_europa_com_o_dinheiro_e_uma_nova_identidade ()
        {
        }

        void sair_da_vida_de_gerente_de_banco_pra_ir_vender_minha_arte_na_praia ()
        {
        }

