#include <stdio.h>

int main() {
    int numero, horas;
    double valor;
    
    scanf("%d %d %lf", &numero, &horas, &valor);
    
    double salario = valor * horas;
    
    printf("NUMBER = %d\n", numero);
    printf("SALARY =  U$ %.2lf\n", salario);
    
    return 0; 
}