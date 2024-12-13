#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>
#include <wchar.h>

typedef struct Termo {
    int coeficiente;
    int expoente;
} Termo;

typedef struct Polinomio {
    int n;
    Termo *t;
} Polinomio;

Polinomio criar_polinomio() {
    Polinomio p;

    printf("Nº de termos diferentes de zero: ");
    scanf("%d", &p.n);

    p.t = (Termo*)malloc(p.n * sizeof(Termo));

    printf("\nInsira os termos do polinômio:\n\n");

    for (int i = 0; i < p.n; i++) {
        printf("Coeficiente do %dº termo: ", i + 1);
        scanf("%d", &p.t[i].coeficiente);
        printf("Expoente do %dº termo: ", i + 1);
        scanf("%d", &p.t[i].expoente);
        printf("\n");
    }

    return p;
}

void imprimir_polinomio(Polinomio p) {
    printf("O polinômio gerado é:\n\n");

    for (int i = 0; i < p.n; i++) {
        int c = p.t[i].coeficiente, e = p.t[i].expoente;

        if (c == 0) continue;
        if (i > 0 || c < 0) printf("%c", c < 0 ? '-' : '+');
        if (i > 0) printf(" ");
        if (abs(c) != 1) printf("%d", abs(c));

        if (e == 0) continue;
        else if (e == 1) printf("x");
        else printf("x^%d", e);

        if (i != p.n - 1) printf(" ");
    }

    printf("\n\n");
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    Polinomio p = criar_polinomio();
    
    imprimir_polinomio(p);

    return 0;
}
