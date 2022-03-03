#include <math.h>
#ifndef GEOMETRIA
#define GEOMETRIA

struct s_ponto {
  double x, y;
};

typedef struct s_ponto ponto;
typedef struct s_ponto vetor;

struct s_segmento {
  ponto p, q;
};

typedef struct s_segmento segmento;

struct s_triangulo {
  ponto p, q, r;
};

typedef struct s_triangulo triangulo;

struct s_retangulo {
  ponto ie; // inferior esquerdo
  ponto sd; // superior direito
};

typedef struct s_retangulo retangulo;

// 01. Calcula o produto interno <u,v>
double produto_interno(vetor u, vetor v){
  return u.x * v.x + u.y * v.y;
}

// 02. Calcula o vetor u - v
vetor subtrai(vetor u, vetor v){
  double novox = u.x - v.x;
  double novoy = u.y - v.y;
  vetor w = {novox, novoy};
  return w;
}

/* 03. Calcula o vetor resultante da rota¸c~ao do vetor v
de um ^angulo de 90 graus no sentido anti-hor´ario. */
vetor roda90(vetor v){
    vetor novov = {v.y * -1, v.x};
    return novov;
}

// 04. Calcula a dist^ancia entre os pontos p e q.
double distancia(ponto p, ponto q){
  double dx = p.x - q.x;
  double dy = p.y - q.y;

  return sqrt(dx * dx + dy *dy);
}

/* 05. Retorna 1 se o coseno do ^angulo entre os vetores u e v ´e
positivo e retorna -1 se for negativo e 0 se for nulo.
Se u ou v for o vetor nulo, devolve 0. */
int sinal_do_coseno(vetor u, vetor v){
  double prod = produto_interno(u,v);
  double norma_u = sqrt(u.x * u.x + u.y * u.y);
  double norma_v = sqrt(v.x * v.x + v.y * v.y);
  double cos = prod / (norma_u * norma_v) ;

  if (cos > 0)
    return 1;
  if (cos < 0)
    return -1;
  else
    return 0;
}

/* 06. Retorna 1 se p, q e r est~ao em sentido hor´ario e -1 se for
anti-hor´ario. Se os pontos forem colineares devolva 0.
Se dois desses pontos s~ao iguais, devolve 0. */
int sentido(ponto p, ponto q, ponto r){
    double valor = produto_interno(subtrai(q,p), roda90(subtrai(r,q)));
    
    if (valor > 0)
        return 1;
    if (valor < 0)
        return -1;
    if (distancia(p,q) == 0 || 
        distancia(p,r) == 0 || 
        distancia(q,r) == 0)
        return 0;
    else
        return 0;
}


/* 07. Retorna 1 se os interiores dos segmentos se intersectam em
um ´unico ponto e retorna 0 caso contr´ario. */
int cruza(segmento s, segmento t){
    if (sentido(s.p, s.q, t.p) == sentido(s.p, s.q, t.q) || sentido(t.p, t.q, s.p) == sentido(t.p, t.q, s.q))
        return 0;
    if (sentido(s.p, s.q, t.p) == 0 || sentido(s.p, s.q, t.q) == 0 || sentido(t.p, t.q, s.p) == 0 || sentido(t.p, t.q, s.q) ==0)
        return 0;
    return 1;
}

/* 08. Retorna 1 se o ponto p est´a no interior do tri^angulo t
e retorna 0 caso contr´ario. */
int dentro(ponto p, triangulo t);
  
/* 09. Devolve 1 se um ret^angulo ´e vazio e 0 caso contr´ario. */
/* Um ret^angulo ´e vazio se a extremidade inferior esquerda
(ponto ie da struct) se encontra estritamente a direita
ou estritamente acima da extremidade superior direita
(ponto sd da struct). */
int retangulo_vazio(retangulo r){
    if (r.ie.x > r.sd.x || r.ie.y > r.sd.y)
        return 1;
    else
        return 0;
}

/* 10. Devolve o ret^angulo resultante da intersec¸c~ao de
dois ret^angulos fechados passados como argumento.
Se a intersec¸c~ao ´e vazia, qualquer representa¸c~ao
de ret^angulo vazio serve como resposta da fun¸cao! */
retangulo intersecta_ret(retangulo a, retangulo b);

/* 13. Devolve 1 se o tri^angulo ´e degenerado, isto ´e
se seus tr^es v´ertices s~ao colineares e 0 caso contr´ario.*/
int degenerado(triangulo t){
    if (distancia(t.p, t.q) != 0 || 
        distancia(t.p, t.r) != 0 || 
        distancia(t.q, t.r) != 0) {
            if (sentido(t.p, t.q, t.r) == 0)
                return 1;
        }
    return 0;
        
}

#endif