/*
O que faz:
Este programa calcula a Transformada Rápida de Fourier (FFT) unidimensional 
de um vetor real usando a função DftiComputeForward da oneMKL. A FFT é uma técnica 
eficiente para transformar um sinal do domínio do tempo para o domínio da frequência.

Por que é relevante:
A FFT é amplamente utilizada em processamento de sinais, comunicações, 
processamento de imagens, entre outros. A oneMKL fornece uma implementação 
otimizada da FFT que aproveita as características específicas dos processadores Intel, 
garantindo desempenho e eficiência em aplicações que exigem operações de transformação de 
sinal rápidas e precisas.

source /opt/intel/oneapi/setvars.sh

gcc -I$MKLROOT/include fft_example.c -Wl,--start-group $MKLROOT/lib/intel64/libmkl_intel_lp64.a $MKLROOT/lib/intel64/libmkl_core.a $MKLROOT/lib/intel64/libmkl_sequential.a -Wl,--end-group -lpthread -lm -ldl -o fft_example
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mkl.h"

int main() {
    int n = 8;
    double x[8] = {0.0, 1.0, 0.0, -1.0, 0.0, 1.0, 0.0, -1.0};
    MKL_Complex16 y[8];

    DFTI_DESCRIPTOR_HANDLE handle;
    MKL_LONG status;

    // Cria o descritor para a FFT
    status = DftiCreateDescriptor(&handle, DFTI_DOUBLE, DFTI_REAL, 1, n);
    if (status != 0) {
        printf("Error in DftiCreateDescriptor: %ld\n", status);
        return 1;
    }

    // Configura a FFT para armazenar a saída em um formato complexo conjugado
    status = DftiSetValue(handle, DFTI_PLACEMENT, DFTI_NOT_INPLACE);
    if (status != 0) {
        printf("Error in DftiSetValue: %ld\n", status);
        return 1;
    }

    // Commita o descritor
    status = DftiCommitDescriptor(handle);
    if (status != 0) {
        printf("Error in DftiCommitDescriptor: %ld\n", status);
        return 1;
    }

    // Executa a FFT
    status = DftiComputeForward(handle, x, y);
    if (status != 0) {
        printf("Error in DftiComputeForward: %ld\n", status);
        return 1;
    }

    // Imprime a saída da FFT
    printf("FFT result:\n");
    for (int i = 0; i < n; i++) {
        printf("(%f, %f)\n", y[i].real, y[i].imag);
    }

    // Libera o descritor
    status = DftiFreeDescriptor(&handle);
    if (status != 0) {
        printf("Error in DftiFreeDescriptor: %ld\n", status);
        return 1;
    }

    return 0;
}