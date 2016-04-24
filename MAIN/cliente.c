#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "vmslib.h"
#include "fvmslib.h"
#include "trablib.h"
#include "gerente.h"
#include "cliente.h"

//_____________________________________________________________//
//_________________________CLIENTE_____________________________//
//_____________________________________________________________//

//_________________________PROCEDIMENTOS_DE_LEITURA_CLIENTE_____________________________//



        void visualizar_saldo (login_data login_atual)
        {
            conta_cliente info_atual;
            FILE *conta;
            int w8;

            conta=abrearquivo_readonly(login_atual.username);

            info_atual=cata_dados_cliente(conta);

            printf ("O seu saldo eh R$%.2f\n\n", info_atual.saldo);

            printf("TECLE 1 E DIGITE ENTER PARA VOLTAR\n");
            scanf("%d",&w8);

            fclose (conta);
        }

        void data_de_cadastro (login_data login_atual)
        {
            conta_cliente info_atual;
            FILE *conta;
            int w8;

            conta=abrearquivo_readonly(login_atual.username);

            info_atual=cata_dados_cliente(conta);

            printf ("A data de cadastro é %i/%i/%i\n\n", info_atual.dia, info_atual.mes, info_atual.ano);

            printf("TECLE 1 E DIGITE ENTER PARA VOLTAR\n");
            scanf("%d",&w8);

            fclose (conta);
        }

        void visualizar_limite (login_data login_atual)
        {
            conta_cliente info_atual;
            FILE *conta;
            int w8;

            conta=abrearquivo_readonly(login_atual.username);

            info_atual=cata_dados_cliente(conta);
            printf ("O limite de transferencia eh R$%.2f\n\n", info_atual.limite);

            printf("TECLE 1 E DIGITE ENTER PARA VOLTAR\n");
            scanf("%d",&w8);

            fclose (conta);
        }

        void visualizar_extrato (login_data login_atual)
        {
            int w8;
            operation_code extrato;
            FILE *arquivo_extrato;

            login_atual = nomeia_arquivo_extrato(login_atual);

            arquivo_extrato=abrearquivo_readwrite(login_atual.nome_arquivo_extrato);

            if(!(!arquivo_extrato))
            {
                    while (1)
                    {
                        extrato=cata_extrato_arquivo(extrato,arquivo_extrato);

                        if(extrato.numconta_origem[0] == '\n' ||extrato.numconta_origem[0] == '\0' )
                            break;

                        printf("\nCONTA DE ORIGEM DA OPERAÇÃO : %s",extrato.numconta_origem);

                        switch (extrato.tipo)
                        {
                            case 1:printf("\nDEPOSITO DE : %.2f\nPARA CONTA: %s\n",extrato.valor,extrato.numconta_destino); break;
                            case 2:printf("\nRETIRADA DE : %.2f\nPARA CONTA: %s\n",extrato.valor,extrato.numconta_destino); break;
                            case 3:printf("\nTRANSFERENCIA DE : %.2f\nPARA CONTA: %s\n",extrato.valor,extrato.numconta_destino); break;
                        }
                        switch (extrato.mes)
                        {
                            case 1 : printf("NO DIA %d de JANEIRO DE %d\n",extrato.dia,extrato.ano); break;
                            case 2 : printf("NO DIA %d de FEVEREIRO DE %d\n",extrato.dia,extrato.ano); break;
                            case 3 : printf("NO DIA %d de MARÇO DE %d\n",extrato.dia,extrato.ano); break;
                            case 4 : printf("NO DIA %d de ABRIL DE %d\n",extrato.dia,extrato.ano); break;
                            case 5 : printf("NO DIA %d de MAIO DE %d\n",extrato.dia,extrato.ano); break;
                            case 6 : printf("NO DIA %d de JUNHO DE %d\n",extrato.dia,extrato.ano); break;
                            case 7 : printf("NO DIA %d de JULHO DE %d\n",extrato.dia,extrato.ano); break;
                            case 8 : printf("NO DIA %d de AGOSTO DE %d\n",extrato.dia,extrato.ano); break;
                            case 9 : printf("NO DIA %d de SETEMBRO DE %d\n",extrato.dia,extrato.ano); break;
                            case 10 : printf("NO DIA %d de OUTUBRO DE %d\n",extrato.dia,extrato.ano); break;
                            case 11 : printf("NO DIA %d de NOVEMBRO DE %d\n",extrato.dia,extrato.ano); break;
                            case 12 : printf("NO DIA %d de DEZEMBRO DE %d\n",extrato.dia,extrato.ano); break;
                        }

			if(feof(arquivo_extrato))
				break;
                    }
            }
            printf("TECLE 1 E DIGITE ENTER PARA VOLTAR\n");
            scanf("%d",&w8);
        }


//_________________________MOVIMENTAÇÃO_FINANCEIRA_CLIENTE_____________________________//


        void depositar_na_conta (login_data login_atual)
        {
            conta_cliente info_atual;
            bank_info client_data;
            operation_code op_atual;
            float deposito;
            FILE *conta,*arquivo_extrato;

            conta=abrearquivo_readwrite(login_atual.username);

//_______________MOVIMENTAÇÃO CONTA CLIENTE________________//

            //OBTENDO AS INFORMAÇÕES ATUAIS E DEPOISITO DO CLIENTE
            if(!(!conta))
            {
                conta=file_set_start(conta);

                info_atual=cata_dados_cliente(conta);

                printf ("Qual o valor a ser depositado?\n");
                scanf ("%f", &deposito);

               while (deposito <= 0)
                {
                    printf ("O deposito deve ter valor positivo\nDigite novamente: ");
                    scanf ("%f", &deposito);
                }

                info_atual.saldo += deposito;

                printf ("Seu novo saldo eh R$%.2f\n", info_atual.saldo);
            }

            fclose (conta);

            conta=novoarquivo_readwrite(login_atual.username);

            //SOBREESCREVENDO AS MESMAS INFORMAÇÕES EM UM NOVO ARQUIVO
            if(!(!conta))
                {
                    bota_dados_cliente(info_atual,conta);
                }
            fclose (conta);

//______________MOVIMENTANDO AS RESERVAS DO BANCO______________//

//FORMATA OS DADOS PARA SEREM PROCESSADOS PELA FUNÇÃO ABAIXO

            client_data.num_clientes=0;
            client_data.num_gerentes=0;
            client_data.reservas=deposito;

            altera_reserva_banco(client_data);

//_________________________ARQUIVO_EXTRAT_____________________________//


            //GUARDANDO E FOMATANDO AS INFORAMÇÕES OBTIDAS NUMA STRUCT FEITA PRA CODIGO DE OPERAÇÕES
            igualastring(login_atual.username,op_atual.numconta_destino);
            igualastring(login_atual.username,op_atual.numconta_origem);
            op_atual.tipo = 1;
            op_atual.valor = deposito;

            arquivo_extrato=abrearquivo_readwrite(login_atual.nome_arquivo_extrato);

            //IMPRIME AS INFORMAÇÕES OBTIDAS NO ARQUIVO
            bota_arquivo_extrato(op_atual,arquivo_extrato);

            fclose(arquivo_extrato);

        }

        void  retirar_da_conta (login_data login_atual)
        {
       conta_cliente info_atual;
            bank_info client_data;
            operation_code op_atual;
            float retirada;
            FILE *conta,*arquivo_extrato;

            conta=abrearquivo_readwrite(login_atual.username);

//_______________MOVIMENTAÇÃO CONTA CLIENTE________________//

            //OBTENDO AS INFORMAÇÕES ATUAIS E RETIRADA DO CLIENTE
            if(!(!conta))
            {
                conta=file_set_start(conta);

                info_atual=cata_dados_cliente(conta);

                printf ("Qual o valor a ser retirado?\n");
                scanf ("%f", &retirada);

               while (retirada <= 0)
                {
                    printf ("A retirada deve ter valor positivo \nDigite novamente: ");
                    scanf ("%f", &retirada);
                    printf ("\n");
                }

                while (retirada > info_atual.saldo)
                {
                    printf ("A retirada deve ser menor que o seu saldo\nDigite novamente: ");
                    scanf ("%f", &retirada);
                    printf ("\n");
                }

                info_atual.saldo -= retirada;

                printf ("Seu novo saldo eh R$%.2f\n", info_atual.saldo);
            }

            fclose (conta);

            conta=novoarquivo_readwrite(login_atual.username);

            //SOBREESCREVENDO AS MESMAS INFORMAÇÕES EM UM NOVO ARQUIVO
            if(!(!conta))
                {
                    bota_dados_cliente(info_atual,conta);
                }
            fclose (conta);

//______________MOVIMENTANDO AS RESERVAS DO BANCO______________//

            //FORMATA OS DADOS PARA SEREM PROCESSADOS PELA FUNÇÃO ABAIXO

            client_data.num_clientes=0;
            client_data.num_gerentes=0;
            client_data.reservas=(-1) * retirada;

            altera_reserva_banco(client_data);

//_________________________ARQUIVO_EXTRAT_____________________________//


            //GUARDANDO E FOMATANDO AS INFORAMÇÕES OBTIDAS NUMA STRUCT FEITA PRA CODIGO DE OPERAÇÕES
            igualastring(login_atual.username,op_atual.numconta_destino);
            igualastring(login_atual.username,op_atual.numconta_origem);
            op_atual.tipo = 2;
            op_atual.valor = retirada;

            arquivo_extrato=abrearquivo_readwrite(login_atual.nome_arquivo_extrato);

            //IMPRIME AS INFORMAÇÕES OBTIDAS NO ARQUIVO
            bota_arquivo_extrato(op_atual,arquivo_extrato);

            fclose(arquivo_extrato);
        }

        void  transferir_da_conta (login_data login_atual)
        {
			conta_cliente info_atual, cliente2;
            bank_info client_data;
            operation_code op_atual, op_atual2;
            login_data tester, client;
            float transferencia;
            FILE *arquivo_conta, *arquivo_transfer, *arquivo_extrato, *arquivo_extrato2, *arquivo_logins;
			char username[32];
			int count, procedure;

			arquivo_logins = abrearquivo_readonly ("clientlogins");
			arquivo_logins = file_set_start (arquivo_logins);

			printf ("Para qual conta você deseja transferir dinheiro?\n");
            catastring (client.username);
            __fpurge(stdin);

            login_atual = nomeia_arquivo_extrato (login_atual);
            client = nomeia_arquivo_extrato (client);

            procedure = compara_login_arquivo (client, arquivo_logins);

            //VERIFICA SE A CONTA PASSADA EXISTE (FAZER ALGO PARA SAIR CASO O CARINHA TENTE MAIS DE TRES VEZES)
            while (procedure != 1)
            {
                printf ("O numero da conta não existe. Favor tentar novamente\n");
                catastring (client.username);
                __fpurge(stdin);

                procedure = compara_login_arquivo (client, arquivo_logins);
            }

			arquivo_conta=abrearquivo_readwrite(login_atual.username);


            //_______________MOVIMENTAÇÃO CONTA CLIENTE________________//

            //OBTENDO AS INFORMAÇÕES ATUAIS E VALOR DA TRANSFERENCIA DO CLIENTE
            if(!(!arquivo_conta))
            {
                arquivo_conta=file_set_start(arquivo_conta);

                info_atual=cata_dados_cliente(arquivo_conta);

                printf ("Qual o valor a ser transferido?\n");
                scanf ("%f", &transferencia);
                __fpurge(stdin);

                while (transferencia < 0)
                {
                    printf ("O valor deve ser positivo\nDigite novamente: ");
                    scanf ("%f", &transferencia);
                    __fpurge(stdin);
                }

                while (transferencia > info_atual.limite)
                {
					printf ("O valor de transferencia deve ser menor que o seu limite\nFavor digitar novamente\n");
					scanf ("%f", &transferencia);
					__fpurge(stdin);
				}


				if ((info_atual.saldo - transferencia) < 0)
				{
					printf ("Não foi possível realizar a transferencia, seu saldo nao pode ser menor que zero\n");
				}

				else
				{
					info_atual.saldo = info_atual.saldo - transferencia;
					printf ("Seu novo saldo eh R$%.2f\n", info_atual.saldo);

                fclose (arquivo_conta);
				}

                arquivo_conta=novoarquivo_readwrite(login_atual.username);

					//SOBREESCREVENDO AS MESMAS INFORMAÇÕES EM UM NOVO ARQUIVO
					if(!(!arquivo_conta))
						bota_dados_cliente(info_atual,arquivo_conta);

					fclose (arquivo_conta);

                //_________________________ARQUIVO_EXTRAT_____________________________//


            //GUARDANDO E FOMATANDO AS INFORAMÇÕES OBTIDAS NUMA STRUCT FEITA PRA CODIGO DE OPERAÇÕES
            igualastring(client.username,op_atual.numconta_destino);
            igualastring(login_atual.username,op_atual.numconta_origem);
            op_atual.tipo = 3;
            op_atual.valor = transferencia;

            arquivo_extrato=abrearquivo_readwrite(login_atual.nome_arquivo_extrato);

            //IMPRIME AS INFORMAÇÕES OBTIDAS NO ARQUIVO
            bota_arquivo_extrato(op_atual,arquivo_extrato);

            fclose(arquivo_extrato);

					//BUSCANDO INFORMAÇOES DO CLIENTE 2

					arquivo_transfer = abrearquivo_readonly (client.username);
					arquivo_transfer = file_set_start (arquivo_transfer);

					cliente2 = cata_dados_cliente (arquivo_transfer);

					cliente2.saldo = cliente2.saldo + transferencia;transferir_da_conta;

					fclose (arquivo_transfer);

					//SOBRESCREVENDO AS MESMAS INFORMAÇOES EM UM NOVO ARQUIVO

                    arquivo_transfer=novoarquivo_readwrite (client.username);

					if (!(!arquivo_transfer))
						bota_dados_cliente (cliente2, arquivo_transfer);

					fclose(arquivo_transfer);

					//GUARDANDO E FOMATANDO AS INFORAMÇÕES OBTIDAS NUMA STRUCT FEITA PRA CODIGO DE OPERAÇÕES
            igualastring(client.username,op_atual.numconta_destino);
            igualastring(login_atual.username,op_atual.numconta_origem);
            op_atual.tipo = 3;
            op_atual.valor = transferencia;

            arquivo_extrato2=abrearquivo_readwrite(client.nome_arquivo_extrato);

            //IMPRIME AS INFORMAÇÕES OBTIDAS NO ARQUIVO
            bota_arquivo_extrato(op_atual,arquivo_extrato2);

            fclose(arquivo_extrato2);
            }

        }

