#include <stdio.h>
int soma(int n, int *v) {
  if (n == 1) {
      return v[0];
  }
  else {
      int r = soma(n-1, v);
      return r + v[n-1];
  }
}

int main() {
  int n;
  scanf("%d", &n);
  
  int v[n];
  for (int i = 0; i < n; i ++)
  scanf("%d", &v[i]);
  
  printf("%d\n", soma(n, v));
  return 0;
}