#include <stdio.h>

int main() {

    int dias, meses, anos;
    meses = 0;
    anos = 0;
    scanf("%i", &dias);
    while(dias >= 365){
        anos = anos + 1;
        dias = dias - 365;
    }
    while(dias >= 30){
        meses = meses + 1;
        dias = dias - 30;
    }

    printf("%i ano(s)\n", anos);
    printf("%i mes(es)\n", meses);
    printf("%i dia(s)\n", dias);
    return 0;
}
