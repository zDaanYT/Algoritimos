#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define VERDADEIRO 1
#define FALSO 0

typedef struct {
    int num;
    char operacao[2], data[11];
    float valor;

} REG_CONTA;

FILE *credito, *debito, *dc; // ARQUIVOS

void grava_credito(){
    int n;
    REG_CONTA aux_c;

    credito = fopen("C:\\Users\\Danilo\\Desktop\\Lista n.º 5 - Registros e Arquivos\\001. Agência bancária\\C\\credito.bin", "ab+");

    printf("Informe quantos dados serão gravados: ");
    scanf("%d", &n);

    do{

        printf("Informe o número da conta: ");
        scanf("%d", &aux_c.num);

        printf("Informe a data - (dd/MM/AAAA): ");
        scanf("%c", aux_c.data);

        aux_c.operacao = "C";

        printf("Informe o valor do crédito: ");
        scanf("%f", aux_c.valor);

        fwrite(&aux_c, sizeof(REG_CONTA), 1, credito);
        fseek(credito, sizeof(REG_CONTA), SEEK_CUR);

        n--;
    }
    while(n > 0);

    fclose(credito);
}

void grava_debito(){
    int n
    REG_CONTA aux_d;

    debito = fopen("C:\\Users\\Danilo\\Desktop\\Lista n.º 5 - Registros e Arquivos\\001. Agência bancária\\C\\debito.bin", "ab+");

    printf("Informe quantos dados serão gravados: ");
    scanf("%d", &n);

    do{
        printf("Informe o número da conta: ");
        scanf("%d", &aux_d.num);

        printf("Informe a data - (dd/MM/AAAA): ");
        scanf("%c", aux_d.data);

        aux_d.operacao = "D";

        printf("Informe o valor do crédito: ");
        scanf("%f", aux_d.valor);

        fwrite(&aux_d, sizeof(REG_CONTA), 1, debito);
        fseek(debito, sizeof(REG_CONTA), SEEK_CUR);

        n--;

    } while(n > 0);

    fclose(debito);
}

void cria_dc(){
    REG_CONTA aux_c, aux_d;
    int achou, conta;
    int temCredito, temDebito;

    credito = fopen("C:\\Users\\Danilo\\Desktop\\Lista n.º 5 - Registros e Arquivos\\001. Agência bancária\\C\\credito.bin", "rb");
    debito  = fopen("C:\\Users\\Danilo\\Desktop\\Lista n.º 5 - Registros e Arquivos\\001. Agência bancária\\C\\debito.bin", "rb");
    dc      = fopen("C:\\Users\\Danilo\\Desktop\\Lista n.º 5 - Registros e Arquivos\\001. Agência bancária\\C\\dc.bin", "wb");

    if (!credito || !debito || !dc) {
        printf("Erro ao abrir um dos arquivos!\n");
        exit(1);
    }

    temCredito  = fread(&aux_c, sizeof(REG_CONTA), 1, credito);
    temDebito   = fread(&aux_d, sizeof(REG_CONTA), 1, debito);

    while (temCredito || temDebito) {
        achou = FALSO;

        if (temCredito && temDebito) {
            if (aux_c.num == aux_d.num) {
                fwrite(&aux_c, sizeof(REG_CONTA), 1, dc);
                fwrite(&aux_d, sizeof(REG_CONTA), 1, dc);

                achou = VERDADEIRO;

                temCredito = fread(&aux_c, sizeof(REG_CONTA), 1, credito);
                temDebito  = fread(&aux_d, sizeof(REG_CONTA), 1, debito);
            } else if (aux_c.num > aux_d.num) {
                conta = aux_c.num;

                while (temDebito && aux_d.num == conta) {
                    fwrite(&aux_d, sizeof(REG_CONTA), 1, dc);
                    temDebito = fread(&aux_d, sizeof(REG_CONTA), 1, debito);
                }
            } else {
                conta = aux_c.num;

                while (temCredito && aux_c.num == conta) {
                    temCredito = fread(&aux_c, sizeof(REG_CONTA), 1, credito);
                }

            }
        } else if (!temCredito && temDebito) {
            fwrite(&aux_d, sizeof(REG_CONTA), 1, dc);
            temDebito = fread(&aux_d, sizeof(REG_CONTA), 1, debito);
        } else if (!temDebito && temCredito) {
            temCredito = fread(&aux_c, sizeof(REG_CONTA), 1, credito);
        }

        if (achou == FALSO && temCredito && temDebito){
            printf  ("Conta %d não possui correspondente entre crédito e débito.\n",
                    (aux_c.num > aux_d.num ? aux_d.num : aux_c.num));
        }
    }

    fclose(credito);
    fclose(debito);
    fclose(dc);

    printf("\nArquivo DC criado com sucesso!\n");
}


void mostra_tabela(){


}

int main(){
    setlocale(LC_ALL, "Portuguese");

    return 0;
}
