#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

main(){

    setlocale(LC_ALL, "Portuguese");
    int v1, v2;

      printf("Informe o 1 valor inteiro: ");
      scanf("%d", &v1);

      printf("Informe o 2 valor inteiro: ");
      scanf("%d", &v2);

        if(v1 > v2){
        printf("%d",v1);
                  }else if(v1 < v2){
                  printf("%d",v2);
                                  }else
                                  printf("Os valores são iguais!");
}
