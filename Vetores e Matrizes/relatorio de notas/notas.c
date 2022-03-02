#include <stdio.h>

int main() {

  int n;
  double a, b, c, d, f, aporc, bporc, cporc, dporc, fporc;
  char conceito;
  float menor, menor2, soma, media;  

  scanf("%d", &n);

  float notas[n][10];

  for (int i=0; i < n; i++){
    for (int j=0; j < 10; j++){
      scanf("%f", &notas[i][j]);        
    }
  }

  for (int i=0; i < n; i++){
    menor = 10;
    menor2 = 10;
    media = 0;
    soma = 0;
    for (int j=1; j < 10; j++){
      soma = soma + notas[i][j];
      if (notas[i][j] < menor){
        menor2 = menor;
        menor = notas[i][j];
      }
      else if (menor2 > notas[i][j]) {
        menor2 = notas[i][j];
      }
    }
    
    soma = soma - (menor + menor2);
    media = soma / 6;

    if (media >= 8.5) {
      conceito = 'A';
      a++;
    }
    if (7 <= media && media < 8.5) {
      conceito = 'B';
      b++;
    }
    if (5.5 <= media && media < 7.0){
      conceito = 'C';
      c++;
    }      
    if (4.5 <= media && media < 5.5) {
      conceito = 'D';
      d++;
    }
    if (media < 4.5) {
      conceito = 'F';
      f++;
    }
    

    printf("%0.f %.3f %c\n", notas[i][0], media, conceito);
  }  
  aporc = (a/n) * 100;
  bporc = (b/n) * 100;
  cporc = (c/n) * 100;
  dporc = (d/n) * 100;
  fporc = (f/n) * 100;


  printf("\n"); 
  
  printf("A %.0lf %.1lf\n", a, aporc);
  printf("B %.0lf %.1lf\n", b, bporc);
  printf("C %.0lf %.1lf\n", c, cporc);
  printf("D %.0lf %.1lf\n", d, dporc);
  printf("F %.0lf %.1lf\n", f, fporc);



}