#include <stdio.h>

// Definindo o tamanho do tabuleiro e dos navios
#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3

// --- Função para inicializar o tabuleiro com água (0) ---
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0; // 0 representa água
        }
    }
}

// --- Função para exibir o tabuleiro ---
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("Tabuleiro de Batalha Naval:\n\n");
    // Imprime os números das colunas
    printf("  ");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // Imprime o tabuleiro com os números das linhas
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i); // Imprime o número da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

// --- Função para posicionar um navio no tabuleiro ---
// Retorna 1 se o posicionamento for bem-sucedido, 0 se houver erro
int posicionarNavio(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int coluna, int orientacao) {
    // Valida se o navio está dentro dos limites do tabuleiro
    if (orientacao == 0) { // Navio horizontal
        if (coluna + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            printf("Erro: Navio horizontal fora dos limites do tabuleiro.\n");
            return 0;
        }
        // Valida se o navio se sobrepõe a outro
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha][coluna + i] != 0) {
                printf("Erro: Navio horizontal se sobrepõe a outro.\n");
                return 0;
            }
        }
        // Posiciona o navio
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha][coluna + i] = 3; // 3 representa o navio
        }
    } else { // Navio vertical
        if (linha + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
            printf("Erro: Navio vertical fora dos limites do tabuleiro.\n");
            return 0;
        }
        // Valida se o navio se sobrepõe a outro
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha + i][coluna] != 0) {
                printf("Erro: Navio vertical se sobrepõe a outro.\n");
                return 0;
            }
        }
        // Posiciona o navio
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linha + i][coluna] = 3; // 3 representa o navio
        }
    }
    return 1;
}

// --- Função principal (main) ---
int main() {
    // Declaração e inicialização do tabuleiro
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    inicializarTabuleiro(tabuleiro);

    // Declaração das coordenadas dos navios
    int linha_navio1 = 2;
    int coluna_navio1 = 5;
    int orientacao_navio1 = 0; // 0 para horizontal

    int linha_navio2 = 7;
    int coluna_navio2 = 3;
    int orientacao_navio2 = 1; // 1 para vertical

    // Posicionando o primeiro navio
    if (!posicionarNavio(tabuleiro, linha_navio1, coluna_navio1, orientacao_navio1)) {
        return 1; // Encerra o programa se o posicionamento falhar
    }

    // Posicionando o segundo navio
    if (!posicionarNavio(tabuleiro, linha_navio2, coluna_navio2, orientacao_navio2)) {
        return 1; // Encerra o programa se o posicionamento falhar
    }

    // Exibe o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);

    return 0;
}