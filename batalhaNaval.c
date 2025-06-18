#include <stdio.h>

#define TAMANHO 10  // Tamanho do tabuleiro 10x10
#define TAM_NAVIO1 4 // Tamanho do navio vertical
#define TAM_NAVIO2 3 // Tamanho do navio horizontal

int main() {
    // Tabuleiro representado por uma matriz 10x10
    int tabuleiro[TAMANHO][TAMANHO] = {0};

    // Coordenadas iniciais dos navios
    int inicioX_navioVertical = 2;
    int inicioY_navioVertical = 3;

    int inicioX_navioHorizontal = 6;
    int inicioY_navioHorizontal = 1;

    printf("Posicionando navio vertical (tamanho %d):\n", TAM_NAVIO1);

    for (int i = 0; i < TAM_NAVIO1; i++) {
        int x = inicioX_navioVertical + i;
        int y = inicioY_navioVertical;

        if (x < TAMANHO) {
            tabuleiro[x][y] = 1; // Marca posição do navio
            printf("Parte %d: (%d, %d)\n", i + 1, x, y);
        } else {
            printf("Erro: navio vertical ultrapassa os limites do tabuleiro.\n");
            break;
        }
    }

    printf("\nPosicionando navio horizontal (tamanho %d):\n", TAM_NAVIO2);

    for (int i = 0; i < TAM_NAVIO2; i++) {
        int x = inicioX_navioHorizontal;
        int y = inicioY_navioHorizontal + i;

        if (y < TAMANHO) {
            tabuleiro[x][y] = 2; // Marca posição do navio
            printf("Parte %d: (%d, %d)\n", i + 1, x, y);
        } else {
            printf("Erro: navio horizontal ultrapassa os limites do tabuleiro.\n");
            break;
        }
    }

    return 0;
}
