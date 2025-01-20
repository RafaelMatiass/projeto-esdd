#include <stdio.h>
#include <stdlib.h>

void lerVetor(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &vetor[i]);
    }
}

void processarFila(int *filaInicial, int n, int *saida, int m, int *filaFinal, int *tamanhoFinal) {
    int *marcados = (int *)calloc(100001, sizeof(int));

    for (int i = 0; i < m; i++) {
        marcados[saida[i]] = 1;
    }

    *tamanhoFinal = 0;
    for (int i = 0; i < n; i++) {
        if (!marcados[filaInicial[i]]) {
            filaFinal[(*tamanhoFinal)++] = filaInicial[i];
        }
    }

    free(marcados);
}

int main() {
    int n, m;

    scanf("%d", &n);

    int *filaInicial = (int *)malloc(n * sizeof(int));

    lerVetor(filaInicial, n);

    scanf("%d", &m);

    int *saida = (int *)malloc(m * sizeof(int));

    lerVetor(saida, m);

    int *filaFinal = (int *)malloc((n - m) * sizeof(int));
    int tamanhoFinal;

    processarFila(filaInicial, n, saida, m, filaFinal, &tamanhoFinal);

    for (int i = 0; i < tamanhoFinal; i++) {
        printf("%d%c", filaFinal[i], (i == tamanhoFinal - 1) ? '\n' : ' ');
    }

    free(filaInicial);
    free(saida);
    free(filaFinal);

    return 0;
}