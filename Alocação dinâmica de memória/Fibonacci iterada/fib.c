#include <stdio.h>
#include <stdlib.h>

void completaVetor(int *v, int n, int inic){
  for (int i = inic; i <= n; i++){
    int ult = *(v+i-1);
    int pult = *(v+i-2);
    *(v+i) = *(v+ ult % i) + *(v + pult % i);
  }
}

int main(void) {  
  int n;
  int inic = 2;
  int *v = (int *) malloc(inic * sizeof(int));
  *(v+0) = 1;
  *(v+1) = 1;

  while (scanf("%d", &n) == 1){
    if (n <= inic)
      printf("%d\n", *(v+n));
    else {
      int *novov = (int *) realloc(v, (n+1)*sizeof(int));
      v = novov;
      completaVetor(v, n, inic);
      printf("%d\n", *(v+n));
      inic = n;
    }     
  }
  return 0;
}