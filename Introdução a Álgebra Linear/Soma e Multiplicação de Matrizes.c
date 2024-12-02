#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#include <string.h>

struct Dim {
    int i;
    int j;
};

struct Dim obter_dimensoes() {
    struct Dim dim;

    printf("Insira o número de linhas 'i' e o número de colunas 'j':\n");
    printf("\nNúmero de linhas i=");
    scanf("%d", &dim.i);

    printf("\nNúmero de colunas j=");
    scanf("%d", &dim.j);

    return dim;
}

void imprimir_matriz(int** mat, int i, int j) {
    printf("\n");

    for (int m = 0; m < i; m++)
    {
        printf("|  ");

        for (int n = 0; n < j; n++)
        {
            printf("%02d", mat[m][n]);
            if (n < j - 1) printf("    ");
        }

        printf("  |\n");

        if (m < i - 1)
        {
            printf("|  ");
            for (int n = 0; n < 3 * j - 2; n++)
            {
                printf("  ");
            }
            printf("  |\n");
        }
    }

    printf("\n");
}

int** criar_matriz(char* nome, int i, int j) {
    nome = nome == NULL ? "matriz" : nome;
    
    printf("\nAgora, preencha a %s.\n", nome);

    int **mat = (int**)malloc(i * sizeof(int*));

    for (int m = 0; m < i; m++) {
        mat[m] = (int*)malloc(j * sizeof(int));

        for (int n = 0; n < j; n++) {
            printf("Digite o valor do elemento ij=%d%d: \n", m, n);
            scanf("%d", &mat[m][n]);
        }
    }

    printf("Imprimindo a %s:\n", nome);
    imprimir_matriz(mat, i, j);

    return mat;
}

void liberar_matriz(int** mat, int i) {
    for (int m = 0; m < i; m++) {
        free(mat[m]);
    }
    free(mat);
}

void somar_ou_subtrair_matrizez(int** mat1, int** mat2, int i, int j, char* op) {
    int **mat3 = (int**)malloc(i * sizeof(int*));
    int multi = op == "soma" ? 1 : -1;
    char *sinal = op == "soma" ? "+" : "-";

    printf("\nEntão você quer realizar uma %s.\n", op);

    for(int x=0; x<i; x++){
        mat3[x] = (int*)malloc(j * sizeof(int));

        for(int y=0; y<j; y++){
            mat3[x][y] = mat1[x][y] + (multi * mat2[x][y]);
        }
    }

    printf("\n---------------------------------------------\n");
    printf("\nEsta é a %s dessas duas matrizes:\n\n\n", op);

    imprimir_matriz(mat1, i, j);

    printf("%s\n", sinal);

    imprimir_matriz(mat2, i, j);

    printf("=\n");

    imprimir_matriz(mat3, i, j);

    liberar_matriz(mat3, i);
}

void somar_matrizez(int** mat1, int** mat2, int i, int j) {
    somar_ou_subtrair_matrizez(mat1, mat2, i, j, "soma");
}

void subtrair_matrizez(int** mat1, int** mat2, int i, int j) {
    somar_ou_subtrair_matrizez(mat1, mat2, i, j, "subtração");
}

int produto_escalar(int* vet1, int* vet2, int n) {
    int resultado = 0;
    for (int i = 0; i < n; i++) {
        resultado += vet1[i] * vet2[i];
    }
    return resultado;
}

int** transpor_matriz(int** mat, int i, int j) {
    int **mat_t = (int**)malloc(j * sizeof(int*));
    for (int n = 0; n < j; n++)
    {
        mat_t[n] = (int*)malloc(i * sizeof(int));
    }

    for (int m = 0; m < i; m++)
    {
        for (int n = 0; n < j; n++)
        {
            mat_t[n][m] = mat[m][n];
        }
    }

    return mat_t;
}

void multiplicar_matrizez(int** mat1, int** mat2, int i, int j, int n) {
    int **mat2_t = transpor_matriz(mat2, n, j);
    int **mat3 = (int**)malloc(i * sizeof(int*));

    printf("\nEntão você quer realizar uma multiplicação.\n");

    for(int x=0; x<i; x++){
        mat3[x] = (int*)malloc(j * sizeof(int));

        for(int y=0; y<j; y++){
            mat3[x][y] = produto_escalar(mat1[x], mat2_t[y], n);
        }
    }

    printf("\n---------------------------------------------\n");
    printf("\nEsta é a multiplicação dessas duas matrizes:\n\n\n");

    imprimir_matriz(mat1, i, j);

    printf(".\n");

    imprimir_matriz(mat2, i, j);

    printf("=\n");

    imprimir_matriz(mat3, i, j);

    liberar_matriz(mat3, i);
}

int main (){
    setlocale(LC_ALL, "Portuguese");

    printf("---------- MATRIZES ----------\n\n");

    int op;

    printf("\nVamos criar a Matriz A.\n");

    struct Dim dim1 = obter_dimensoes();
    int** mat1 = criar_matriz("Matriz A", dim1.i, dim1.j);
    
    printf("\n----------------------------------------------------\n");

    printf("\nAgora, vamos criar a Matriz B.\n");

    struct Dim dim2 = obter_dimensoes();
    int** mat2 = criar_matriz("Matriz B", dim2.i, dim2.j);

    do {
        printf("\n------------------------------------------------------------------\n");
        printf("\nOperações:\n");
        printf("1. Somar\n");
        printf("2. Subtrair\n");
        printf("3. Multiplicar\n");
        printf("4. Sair\n");

        printf("Escolha uma operação: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                if (dim1.i != dim2.i || dim1.j != dim2.j) {
                    printf("\nO número de linhas e colunas das matrizes não são iguais. Logo, é imposs­ível efetuar a soma.\n");
                } else {
                    somar_matrizez(mat1, mat2, dim1.i, dim1.j);
                }
                break;
            case 2:
                if (dim1.i != dim2.i || dim1.j != dim2.j) {
                    printf("\nO número de linhas e colunas das matrizes não são iguais. Logo, é imposs­ível efetuar a subtração.\n");
                } else {
                    subtrair_matrizez(mat1, mat2, dim1.i, dim1.j);
                }
                break;
            case 3:
                if (dim1.j != dim2.i) {
                    printf("\nO número de colunas da matriz A não é igual ao número de linhas da matriz B. Logo, é imposs­ível efetuar a multiplicação.\n");
                } else {
                    multiplicar_matrizez(mat1, mat2, dim1.i, dim2.j, dim1.j);
                }
                break;
            case 4:
                printf("\nAté a próxima!\n\n");
                break;
        }
    } while(op != 4);

    liberar_matriz(mat1, dim1.i);
    liberar_matriz(mat2, dim2.i);
    return 0;
}