#include <stdio.h>
#include <math.h>

int main() {
    int N;
    scanf("%d", &N);
    
    int horas = N / 3600;
    N = N % 3600;

    int minutos = N / 60;
    N = N % 60;
    
    printf("%d:%d:%d", horas, minutos, N);
    
    return 0;
}