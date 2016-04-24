#ifndef cliente_H_INCLUDED
#define cliente_H_INCLUDED


//_____________________________________________________________//
//_________________________CLIENTE_____________________________//
//_____________________________________________________________//

//_________________________PROCEDIMENTOS_DE_LEITURA_CLIENTE_____________________________//


        void visualizar_saldo (login_data login_atual);

        void data_de_cadastro (login_data login_atual);

        void visualizar_limite (login_data login_atual);

        void visualizar_extrato (login_data login_atual);

//_________________________MOVIMENTAÇÃO_FINANCEIRA_CLIENTE_____________________________//


        void depositar_na_conta (login_data login_atual);

        void  retirar_da_conta (login_data login_atual);

        void  transferir_da_conta (login_data login_atual);

#endif
