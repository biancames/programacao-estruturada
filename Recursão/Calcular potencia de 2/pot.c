#include <stdio.h>
long long pot2(int k) {
    if (k == 0) return 1;
    long long r = pot2(k-1);
    return r * 2;
  
}
int main() {
  int k;
  scanf("%d", &k);
 
  printf("%lld\n", pot2(k));
  return 0;
}