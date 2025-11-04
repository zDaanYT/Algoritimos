#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

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

int main(){
    setlocale(LC_ALL, "Portuguese");

    dc      = fopen("C:\\Users\\Danilo\\Desktop\\Lista n.º 5 - Registros e Arquivos\\001. Agência bancária\\C\\dc.bin", "ab+");

    return 0;
}


