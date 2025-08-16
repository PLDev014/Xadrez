#include <stdio.h>

// Definição de constantes para o número de casas a serem movidas
#define NUM_SQUARES_RECURSION 4
#define NUM_SQUARES_HORSE 2
#define NUM_SQUARES_BISHOP 3

// --- Funções Recursivas para Movimentos ---

/**
 * @brief Simula o movimento da Torre de forma recursiva.
 * * A função se move para a direita (horizontal) e depois para cima (vertical).
 * * @param squares_Remaining O número de casas que a torre ainda deve se mover.
 */
void moveTower(int squares_Remaining) {
    if (squares_Remaining <= 0) {
        return; // Condição de parada da recursão
    }

    printf("Direita\n");
    moveTower(squares_Remaining - 1); // Chamada recursiva para a próxima casa
    
    // Você pode adicionar mais direções aqui, como "Cima" ou "Baixo"
    // para simular um movimento mais completo.
}

/**
 * @brief Simula o movimento do Bispo de forma recursiva.
 * * O bispo se move na diagonal, neste caso para Cima/Direita.
 * * @param squares_Remaining O número de casas que o bispo ainda deve se mover.
 */
void moveBishopRecursive(int squares_Remaining) {
    if (squares_Remaining <= 0) {
        return; // Condição de parada da recursão
    }
    
    // Para simular a diagonal, imprimimos duas direções por chamada.
    printf("Cima\n");
    printf("Direita\n");
    moveBishopRecursive(squares_Remaining - 1);
}


/**
 * @brief Simula o movimento da Rainha de forma recursiva.
 * * A rainha se move para a frente (vertical) e depois para a direita (horizontal).
 * * @param squares_Remaining O número de casas que a rainha ainda deve se mover.
 */
void moveQuenn(int squares_Remaining) {
    if (squares_Remaining <= 0) {
        return; // Condição de parada da recursão
    }

    printf("Cima\n");
    printf("Direita\n");
    moveQuenn(squares_Remaining - 1); // Chamada recursiva para a próxima casa
}

// --- Funções com Loops Complexos ---

/**
 * @brief Simula o movimento do Cavalo (2 casas para cima, 1 para a direita).
 * * Utiliza loops aninhados com múltiplas variáveis e 'continue'.
 */
void moveHorse() {
    printf("Movendo o Cavalo em L (2 para cima, 1 para a direita):\n");
    
    // O loop externo simula o movimento vertical
    for (int i = 0; i < NUM_SQUARES_HORSE; i++) {
        printf("Cima\n");
    }
    
    // O loop interno simula o movimento horizontal
    for (int j = 0; j < 1; j++) {
        printf("Direita\n");
    }

    // Exemplo de um loop aninhado mais complexo com 'continue'
    printf("\nExemplo de Loop complexo para o Cavalo:\n");
    for (int vertical = 0; vertical < 3; vertical++) {
        if (vertical == 2) {
            // Após 2 movimentos verticais, inicia o movimento horizontal
            for (int horizontal = 0; horizontal < 2; horizontal++) {
                if (horizontal == 0) {
                    printf("Direita\n");
                    continue; // Pula para a próxima iteração do loop interno
                }
                // Exemplo de 'break'
                if (horizontal == 1) {
                    break; // Sai do loop interno
                    printf("Direita\n");// Esta linha nunca será executada, porque o loop interno é interrompido
                }
            }
        }
        if (vertical < 2) {
            printf("Cima\n");
        }
    }
}

/**
 * @brief Simula o movimento do Bispo usando loops aninhados.
 * * O loop externo controla o movimento vertical (Cima), e o interno o horizontal (Direita).
 */
void moveBishopLoops() {
    printf("Movendo o Bispo usando loops aninhados (diagonal):\n");
    
    // Loop externo: movimento vertical
    for (int i = 0; i < NUM_SQUARES_BISHOP; i++) {
        printf("Cima\n");
        
        // Loop interno: movimento horizontal
        for (int j = 0; j < 1; j++) {
            printf("Direita\n");
        }
    }
}


int main() {
    printf("--- Movimento da Torre ---\n");
    moveTower(NUM_SQUARES_RECURSION);
    printf("\n"); // Linha em branco para separar

    printf("--- Movimento do Bispo (recursivo) ---\n");
    moveBishopRecursive(NUM_SQUARES_RECURSION);
    printf("\n");

    printf("--- Movimento da Rainha ---\n");
    moveQuenn(NUM_SQUARES_RECURSION);
    printf("\n");

    printf("--- Movimento do Cavalo ---\n");
    moveHorse();
    printf("\n");
    
    printf("--- Movimento do Bispo (loops aninhados) ---\n");
    moveBishopLoops();
    printf("\n");
    system("pause"); // Pausa para visualizar a saída antes de fechar o console
    return 0; // Retorna 0 para indicar que o programa terminou corretamente.
}