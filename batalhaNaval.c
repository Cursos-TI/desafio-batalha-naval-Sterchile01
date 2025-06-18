#include <stdio.h>

#define TAM 10          // Tamanho do tabuleiro 10x10
#define TAM_NAVIO 3     // Todos os navios têm tamanho 3
#define OCUPADO 3       // Valor que representa navio
#define AGUA 0          // Valor que representa água

// Função para verificar se é possível posicionar o navio
int pode_posicionar(int tabuleiro[TAM][TAM], int x, int y, int dx, int dy) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int nx = x + i * dx;
        int ny = y + i * dy;

        if (nx < 0 || nx >= TAM || ny < 0 || ny >= TAM)
            return 0; // Fora dos limites
        if (tabuleiro[nx][ny] != AGUA)
            return 0; // Já ocupado
    }
    return 1;
}

// Função para posicionar o navio no tabuleiro
void posicionar_navio(int tabuleiro[TAM][TAM], int x, int y, int dx, int dy) {
    for (int i = 0; i < TAM_NAVIO; i++) {
        int nx = x + i * dx;
        int ny = y + i * dy;
        tabuleiro[nx][ny] = OCUPADO;
    }
}

// Função para imprimir o tabuleiro
void exibir_tabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n===== TABULEIRO BATALHA NAVAL =====\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM] = {0}; // Inicializa tudo com água (0)

    // NAVIO 1: Vertical (↕)
    int x1 = 1, y1 = 2;
    if (pode_posicionar(tabuleiro, x1, y1, 1, 0)) {
        posicionar_navio(tabuleiro, x1, y1, 1, 0);
    }

    // NAVIO 2: Horizontal (↔)
    int x2 = 6, y2 = 4;
    if (pode_posicionar(tabuleiro, x2, y2, 0, 1)) {
        posicionar_navio(tabuleiro, x2, y2, 0, 1);
    }

    // NAVIO 3: Diagonal principal (↘)
    int x3 = 0, y3 = 0;
    if (pode_posicionar(tabuleiro, x3, y3, 1, 1)) {
        posicionar_navio(tabuleiro, x3, y3, 1, 1);
    }

    // NAVIO 4: Diagonal secundária (↙)
    int x4 = 0, y4 = 9;
    if (pode_posicionar(tabuleiro, x4, y4, 1, -1)) {
        posicionar_navio(tabuleiro, x4, y4, 1, -1);
    }

    // Exibir o tabuleiro completo
    exibir_tabuleiro(tabuleiro);

    return 0;
}
