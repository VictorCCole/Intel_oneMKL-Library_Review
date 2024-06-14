/*
O que faz:
Este programa resolve um sistema de equações lineares 𝐴𝑥=𝑏, onde 𝐴 é uma matriz e 𝑏
é um vetor, usando a decomposição LU obtida com LAPACKE_dgetrf e 
a função LAPACKE_dgetrs da oneMKL. A decomposição LU é calculada primeiro, 
e em seguida o sistema é resolvido usando a matriz fatorada e os pivôs obtidos.

Por que é relevante:
Resolver sistemas de equações lineares é uma 
tarefa comum em diversas áreas da ciência computacional e 
engenharia. A oneMKL oferece rotinas altamente otimizadas para essas 
operações, garantindo eficiência computacional mesmo para matrizes grandes e densas.


source /opt/intel/oneapi/setvars.sh

gcc -I$MKLROOT/include linear_system_solve.c -Wl,--start-group $MKLROOT/lib/intel64/libmkl_intel_lp64.a $MKLROOT/lib/intel64/libmkl_core.a $MKLROOT/lib/intel64/libmkl_sequential.a -Wl,--end-group -lpthread -lm -ldl -o linear_system_solve
*/

#include <stdio.h>
#include <stdlib.h>
#include "mkl.h"

int main() {
    int n = 3, nrhs = 1, lda = 3, ldb = 1, info;
    int ipiv[3];

    double A[9] = {
        4.0, 2.0, 3.0,
        3.0, 1.0, 2.0,
        2.0, 1.0, 3.0
    };

    double b[3] = {1.0, 2.0, 3.0};

    // Executa a decomposição LU
    info = LAPACKE_dgetrf(LAPACK_ROW_MAJOR, n, n, A, lda, ipiv);

    if (info == 0) {
        // Resolve o sistema linear usando a decomposição LU
        info = LAPACKE_dgetrs(LAPACK_ROW_MAJOR, 'N', n, nrhs, A, lda, ipiv, b, ldb);

        if (info == 0) {
            printf("Solution vector x:\n");
            for (int i = 0; i < n; i++) {
                printf("%f\n", b[i]);
            }
        } else {
            printf("System solving failed with info = %d\n", info);
        }
    } else {
        printf("LU decomposition failed with info = %d\n", info);
    }

    return 0;
}
