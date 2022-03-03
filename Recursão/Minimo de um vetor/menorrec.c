#include <stdio.h>
int min(int n, int *v) {
  if (n == 1) return v[0];
  int r = min(n - 1,v);
  if (r <= v[n-1])
    return r;
  return v[n-1];
}
int main() {
  int n;
  scanf("%d", &n);
 
  int v[n];
  for (int i = 0; i < n; i ++)
  scanf("%d", &v[i]);
 
  printf("%d\n", min(n, v));
  return 0;
}