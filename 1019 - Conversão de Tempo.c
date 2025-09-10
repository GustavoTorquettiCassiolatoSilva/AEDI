#include <stdio.h>

int main() {
    int segundos, minutos = 0, horas = 0;
    scanf("%i", &segundos);

    while (segundos >= 3600) {
        ++horas;
        segundos -= 3600;
    }

    while (segundos >= 60) {
        ++minutos;
        segundos -= 60;
    }

    printf("%i:%i:%i\n", horas, minutos, segundos);

    return 0;
}
