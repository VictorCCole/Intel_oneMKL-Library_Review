/*
O que faz:
Este programa realiza a decomposição LU (Lower-Upper) de uma matriz quadrada 
𝐴. A decomposição LU é uma forma de fatorar uma matriz em duas matrizes triangulares (uma inferior e uma superior), 
𝐴=𝐿𝑈, onde 𝐿 é uma matriz triangular inferior e 𝑈 é uma matriz triangular superior. 
Esta decomposição é muito útil em diversas aplicações numéricas, incluindo a resolução de sistemas lineares.

Por que é relevante:
A decomposição LU é uma operação fundamental em álgebra linear e é 
frequentemente usada em métodos numéricos para resolver sistemas de equações 
lineares e calcular inversas de matrizes. A oneMKL fornece a função LAPACKE_dgetrf para 
realizar essa decomposição de forma eficiente, aproveitando otimizações de desempenho específicas para arquiteturas Intel.

source /opt/intel/oneapi/setvars.sh

gcc -I$MKLROOT/include lu_decomposition.c -Wl,--start-group $MKLROOT/lib/intel64/libmkl_intel_lp64.a $MKLROOT/lib/intel64/libmkl_core.a $MKLROOT/lib/intel64/libmkl_sequential.a -Wl,--end-group -lpthread -lm -ldl -o lu_decomposition
*/

#include <stdio.h>
#include <stdlib.h>
#include "mkl.h"

int main() {
    int n = 3;
    int lda = n;
    int ipiv[3];
    int info;

    double A[9] = {
        4.0, 2.0, 3.0,
        3.0, 1.0, 2.0,
        2.0, 1.0, 3.0
    };

    // Executa a decomposição LU
    info = LAPACKE_dgetrf(LAPACK_ROW_MAJOR, n, n, A, lda, ipiv);

    if (info == 0) {
        printf("LU decomposition successful.\n");
        printf("LU matrix:\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                printf("%f ", A[i*n + j]);
            }
            printf("\n");
        }
    } else {
        printf("LU decomposition failed with info = %d\n", info);
    }

    return 0;
}