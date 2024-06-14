# ANÁLISE SOBRE A BIBLIOTECA Intel® oneAPI Math Kernel (oneMKL)
### (Accelerate math processing routines, increase application performance, and reduce development time.)

## 1 Introdução
A computação científica exige desempenho elevado e precisão nas operações matemáticas para diversas aplicações em áreas como física, engenharia, biologia e economia. Bibliotecas matemáticas otimizadas, como a Intel® oneAPI Math Kernel Library (oneMKL), desempenham um papel crucial nesse contexto.

Este trabalho visa fornecer uma análise da Intel® oneAPI Math Kernel Library (oneMKL), destacando suas principais funcionalidades, benefícios, casos de uso e comparações com outras bibliotecas matemáticas. Além disso, serão apresentados exemplos práticos de implementação utilizando a oneMKL. 

## 2 Significado
A Intel® oneAPI Math Kernel Library (oneMKL) é uma coleção abrangente de rotinas matemáticas otimizadas, projetadas para fornecer desempenho elevado em CPUs, GPUs e outras arquiteturas de hardware. Seus principais componentes:
Álgebra Linear: Rotinas para operações de álgebra linear, incluindo multiplicação de matrizes, solução de sistemas lineares e decomposição de matrizes.
Transformadas de Fourier (FFT): Implementações rápidas de FFT para transformações de Fourier.
Geração de Números Aleatórios: Ferramentas para gerar números aleatórios com várias distribuições.
Estatísticas: Funções para cálculos estatísticos essenciais.

## 3 Funcionalidades
### 3.1 Operações de Álgebra Linear
BLAS (Basic Linear Algebra Subprograms): Implementação otimizada das rotinas de BLAS para operações básicas de álgebra linear.
LAPACK (Linear Algebra PACKage): Rotinas otimizadas para resolução de sistemas de equações lineares, decomposição de matrizes e problemas de autovalores.

### 3.2 Transformadas de Fourier (FFT)
FFT de uma e várias dimensões: Transformadas rápidas de Fourier para dados unidimensionais e multidimensionais.
Desempenho Otimizado: Utilização de otimizações específicas para hardware Intel para maximizar o desempenho.

### 3.3 Geração de Números Aleatórios
Distribuições Comuns: Geração de números aleatórios com distribuições uniformes, normais, exponenciais, entre outras.
Streams e Sub Streams: Suporte para streams de números aleatórios independentes, facilitando simulações complexas.

### 3.4 Funções Estatísticas
Estatísticas Descritivas: Cálculo de média, variância, correlação, etc.
Testes Estatísticos: Implementação de testes estatísticos básicos.


## Referências
Intel® oneAPI Math Kernel Library Documentation. (https://www.intel.com/content/www/us/en/developer/tools/oneapi/onemkl.html)
