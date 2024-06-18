#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mkl_lapacke.h"

#define N 1000  // Tamanho da matriz

// Função para gerar uma matriz simétrica aleatória
void gerarMatrizSimetrica(double **A, int n) {
    srand(time(NULL));  // Inicializa a semente randômica com o tempo atual
    *A = (double *)malloc(n * n * sizeof(double));
    if (*A == NULL) {
        printf("Erro ao alocar memória para a matriz.\n");
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            double valor = (double)(rand() % 100);  // Gera um valor aleatório entre 0 e 99
            (*A)[i*n + j] = valor;
            (*A)[j*n + i] = valor;  // A matriz é simétrica, então A[i][j] = A[j][i]
        }
    }
}

int main() {
    // Matriz A
    double *A = NULL;

    // Gerando matriz simétrica aleatória
    gerarMatrizSimetrica(&A, N);

    // Declaração de variáveis
    lapack_int n = N;
    lapack_int lda = N;
    lapack_int info;

    // Vetor para armazenar os autovalores
    double *w = (double *)malloc(n * sizeof(double));
    if (w == NULL) {
        printf("Erro ao alocar memória para o vetor de autovalores.\n");
        free(A);
        exit(1);
    }

    // Resolvendo os autovalores e autovetores de A
    info = LAPACKE_dsyev(LAPACK_ROW_MAJOR, 'V', 'U', n, A, lda, w);

    // Verificando se houve erro na computação dos autovalores
    if (info != 0) {
        printf("Falha ao computar os autovalores.\n");
        free(A);
        free(w);
        exit(1);
    }

    // Imprimindo os autovalores
    printf("Autovalores:\n");
    for (int i = 0; i < N; i++) {
        printf("%f\n", w[i]);
    }

    // Liberando memória alocada
    free(A);
    free(w);

    return 0;
}
