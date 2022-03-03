#include <stdio.h>
#include <string.h>
void reverter(int n, char *p) {
    if (n <= 1) return;
    reverter(n-2, &p[1]);
    char tmp = p[0];
    p[0] = p[n-1];
    p[n-1] = tmp;
}
int main() {
  int n;
 
  // Vetor com espaço para 1002 carcteres (1001 da palavra mais '\0')
  char palavra[1002];
 
  // Lê uma palavra, não mais que 1001 caractéres
  scanf("%1001s", palavra);
 
  n = strlen(palavra);
  reverter(n, palavra);
 
  printf("%s\n", palavra);
 
  return 0;
}