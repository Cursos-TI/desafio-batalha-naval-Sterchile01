#include <stdio.h>'
#include <stdlib.h>

#define TAM 10
#define TAM_HAB 5  // Tamanho das matrizes de habilidades (5x5)
#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Função para inicializar o tabuleiro com água
void inicializar_tabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para posicionar navios fixos (2 horizontais, 2 diagonais)
void posicionar_navios(int tabuleiro[TAM][TAM]) {
    // Horizontal
    for (int i = 0; i < 3; i++)
        tabuleiro[1][2 + i] = NAVIO;

    // Vertical
    for (int i = 0; i < 3; i++)
        tabuleiro[5 + i][4] = NAVIO;

    // Diagonal principal ↘
    for (int i = 0; i < 3; i++)
        tabuleiro[7 + i][i] = NAVIO;

    // Diagonal secundária ↙
    for (int i = 0; i < 3; i++)
        tabuleiro[i][9 - i] = NAVIO;
}

// Função para exibir o tabuleiro com legenda
void exibir_tabuleiro(int tabuleiro[TAM][TAM]) {
    printf("\n===== TABULEIRO BATALHA NAVAL =====\n\n");
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            int val = tabuleiro[i][j];
            if (val == AGUA) printf(". ");
            else if (val == NAVIO) printf("N ");
            else if (val == HABILIDADE) printf("* ");
        }
        printf("\n");
    }
}

// Gera matriz de habilidade com formato de cone
void gerar_habilidade_cone(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            habilidade[i][j] = (j >= TAM_HAB / 2 - i && j <= TAM_HAB / 2 + i) ? 1 : 0;
        }
    }
}

// Gera matriz de habilidade com formato de cruz
void gerar_habilidade_cruz(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            habilidade[i][j] = (i == TAM_HAB / 2 || j == TAM_HAB / 2) ? 1 : 0;
        }
    }
}

// Gera matriz de habilidade com formato de octaedro (losango)
void gerar_habilidade_octaedro(int habilidade[TAM_HAB][TAM_HAB]) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            int dist = abs(i - TAM_HAB / 2) + abs(j - TAM_HAB / 2);
            habilidade[i][j] = (dist <= TAM_HAB / 2) ? 1 : 0;
        }
    }
}

// Aplica matriz de habilidade ao tabuleiro com origem central
void aplicar_habilidade(int tabuleiro[TAM][TAM], int habilidade[TAM_HAB][TAM_HAB], int origem_x, int origem_y) {
    for (int i = 0; i < TAM_HAB; i++) {
        for (int j = 0; j < TAM_HAB; j++) {
            if (habilidade[i][j] == 1) {
                int tx = origem_x + i - TAM_HAB / 2;
                int ty = origem_y + j - TAM_HAB / 2;
                if (tx >= 0 && tx < TAM && ty >= 0 && ty < TAM && tabuleiro[tx][ty] == AGUA) {
                    tabuleiro[tx][ty] = HABILIDADE;
                }
            }
        }
    }
}

int main() {
    int tabuleiro[TAM][TAM];
    int habilidade_cone[TAM_HAB][TAM_HAB];
    int habilidade_cruz[TAM_HAB][TAM_HAB];
    int habilidade_octaedro[TAM_HAB][TAM_HAB];

    inicializar_tabuleiro(tabuleiro);
    posicionar_navios(tabuleiro);

    // Gerar habilidades
    gerar_habilidade_cone(habilidade_cone);
    gerar_habilidade_cruz(habilidade_cruz);
    gerar_habilidade_octaedro(habilidade_octaedro);

    // Aplicar habilidades no tabuleiro
    aplicar_habilidade(tabuleiro, habilidade_cone, 2, 5);      // Cone em (2,5)
    aplicar_habilidade(tabuleiro, habilidade_cruz, 6, 6);      // Cruz em (6,6)
    aplicar_habilidade(tabuleiro, habilidade_octaedro, 4, 2);  // Octaedro em (4,2)

    exibir_tabuleiro(tabuleiro);

    return 0;
}
