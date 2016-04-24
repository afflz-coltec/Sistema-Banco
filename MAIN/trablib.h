#ifndef trablib_H_INCLUDED
#define trablib_H_INCLUDED


//_________________________DEFINIÇÃO_STRUCTS_____________________________//

        typedef struct conta_cliente
        {
            char nome[50];
            float saldo, limite;
            int dia, mes, ano;
        } conta_cliente;

        typedef struct operation_code
        {
            char numconta_origem[10];
            char numconta_destino[10];
            int tipo;//DEPOSITOS = 1 RETIRADAS = 2 TRANFERENCIAS = 3
            int dia, mes, ano;
            float valor;

        } operation_code;

        typedef struct login_data
        {
            char username    [32];
            char passwd      [20];
            char nome_arquivo_extrato [10];
        } login_data;

        typedef struct bank_info
        {
            float reservas;
            int num_clientes;
            int num_gerentes;
        } bank_info;

//_________________________UTILIDADES_____________________________//


        void data (int *dia, int *mes, int *ano);

        int tira_linha_arquivo (char *arquivo, int line);

        conta_cliente cata_dados_cliente (FILE *arquivo);

        int login (FILE *arquivo_de_login,login_data *return_log);

        int compara_login_arquivo (login_data new_log,FILE * login);

        operation_code  cata_extrato_arquivo (operation_code opcode ,FILE *arquivo);

        void *bota_dados_cliente (conta_cliente um,FILE *arquivo);

        void bota_arquivo_extrato(operation_code op_atual,FILE *arquivo_extrato);

        void altera_reserva_banco(bank_info client_data);

        login_data nomeia_arquivo_extrato (login_data new_log);

//_________________________MATRING_FUNCTIONS_____________________________//


        char ** catatudo_arquivo (char **matring,FILE *arquivo);

        int compara_palavras(char *a,char *b,int count);

        char ** ordena_matring (char **matring,int tamanho);

//_________________________OPERATIONS_FUNCTIONS_____________________________//
//_____________________________________________________________//
//_________________________GERAL_______________________________//
//_____________________________________________________________//


        void menu_cliente (login_data login_atual);//A SER FEITO

        void login_cliente ();

        void menu_gerente (login_data login_atual);//A SER FEITO

        void login_gerente();

        void menu_geral ();

#endif // trablib_H_INCLUDED



