#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Cria a struct para armazenar os registros bancarios
typedef struct x{
	int NuConta;
    char NmTitular[100];
	float VrSaldo;
} conta;

//Funcao para mostrar as informacoes da conta
void mostrar(conta c[], int n){
    int x;
    for(x=0; x<n; x++){
        if(c[x].NuConta == n){
            printf("\nNome do titular da conta: %s \nNumero da conta: %d \nSaldo: %f \n", c[x].NmTitular, c[x].NuConta, c[x].VrSaldo);
            break;
        }
    }
}
	
//Funcao para realizar um deposito
void depositar(conta c[], int q, float deposito){
    q = q - 1;
    c[q].VrSaldo += deposito;
    printf("Novo Saldo: %f", c[q].VrSaldo);
}

//Funcao para realizar um saque
void sacar(conta c[], int i, float saque){
    i = i - 1;
    if(saque > c[i].VrSaldo){
        printf("Valor do saque maior que o saldo disponivel!!!!");
    }
    else{
        c[i].VrSaldo -= saque;
        printf("Novo saldo: %f", c[i].VrSaldo);
    }
}

int main() {
    int cd=1, op=0, contas_existentes=0;
    conta contas[10];

    while(op != 5)
	{
		printf("\n\nEntre com a opcao desejada:\n");
		printf("\n1) Criar uma nova conta");
		printf("\n2) Mostrar as informacoes da conta");
		printf("\n3) Realizar um deposito");
		printf("\n4) Realizar um saque");
		printf("\n5) Sair\n\n");
        scanf("%d", &op);
        
        if(op == 1){
            printf("Informe o nome do titular da conta: ");
            //scanf("%s", &contas[contas_existentes].NmTitular);
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            fgets(contas[contas_existentes].NmTitular, sizeof(contas[contas_existentes].NmTitular), stdin);
            // remove o '\n' do final, se existir
            contas[contas_existentes].NmTitular[strcspn(contas[contas_existentes].NmTitular, "\n")] = '\0';
            contas[contas_existentes].NuConta = cd;
            contas[contas_existentes].VrSaldo = 0.0;
			contas_existentes++;
            printf("Conta criada com sucesso!!\nNumero da conta é: %d", cd);
            cd++;
        }
        if(op == 2){
            int n=1;
            if(contas_existentes == 0){
                printf("Ainda nao ha contas cadastradas!!!\n");
            } else{
                printf("Qual o numero da conta que gostaria de ver?\n");
                scanf("%d", &n);
                mostrar(contas, n);
            }
        }
        if(op == 3){
            int c;
            float dp;
            printf("\nDigite o numero da conta que deseja fazer o deposito: ");
            scanf("%d", &c);
            if(c > cd){
                printf("Numero de conta nao cadastrado!!!");
            } else{
                printf("\nDigite o valor do seu deposito: ");
                scanf("%f", &dp);
                depositar(contas, c, dp);
            } 
        }
        if(op == 4){
            int c;
            float sq;
            printf("\nDigite o numero da conta que deseja fazer o saque: ");
            scanf("%d", &c);
            if(c > cd){
                printf("Numero de conta nao cadastrado!!!");
            } else{
                printf("\nDigite o valor do seu saque: ");
                scanf("%f", &sq);
                sacar(contas, c, sq);
            }          
        }
    }
	return 0;
}