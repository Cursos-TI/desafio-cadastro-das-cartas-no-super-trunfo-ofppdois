#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30];
    int populacao;  // Em milhões
    float area;     // Em mil km²
    int idh;        // Índice de Desenvolvimento Humano (de 0 a 1000)
} Carta;

// Função para exibir uma carta
void exibirCarta(Carta carta) {
    printf("\n--- Detalhes do País ---\n");
    printf("País: %s\n", carta.nome);
    printf("População: %d milhões\n", carta.populacao);
    printf("Área: %.2f mil km²\n", carta.area);
    printf("IDH: %d\n", carta.idh);
}

// Função para comparar atributos
void compararAtributo(Carta c1, Carta c2, int atributo) {
    switch (atributo) {
        case 1:
            printf("\nComparando População...\n");
            if (c1.populacao > c2.populacao) {
                printf("%s vence!\n", c1.nome);
            } else if (c1.populacao < c2.populacao) {
                printf("%s vence!\n", c2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
        case 2:
            printf("\nComparando Área...\n");
            if (c1.area > c2.area) {
                printf("%s vence!\n", c1.nome);
            } else if (c1.area < c2.area) {
                printf("%s vence!\n", c2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
        case 3:
            printf("\nComparando IDH...\n");
            if (c1.idh > c2.idh) {
                printf("%s vence!\n", c1.nome);
            } else if (c1.idh < c2.idh) {
                printf("%s vence!\n", c2.nome);
            } else {
                printf("Empate!\n");
            }
            break;
        default:
            printf("Atributo inválido!\n");
    }
}

// Função para o jogador criar uma carta
Carta criarCarta(int jogador) {
    Carta carta;
    printf("\nJogador %d, crie seu país:\n", jogador);
    printf("Digite o nome do país: ");
    scanf(" %[^\n]", carta.nome);
    printf("Digite a população (em milhões): ");
    scanf("%d", &carta.populacao);
    printf("Digite a área (em mil km²): ");
    scanf("%f", &carta.area);
    printf("Digite o IDH (0 a 1000): ");
    scanf("%d", &carta.idh);
    return carta;
}

int main() {
    printf("Bem-vindo ao Super Trunfo de Países!\n");

    // Jogadores criam suas cartas
    Carta cartaJogador1 = criarCarta(1);
    Carta cartaJogador2 = criarCarta(2);

    // Exibindo as cartas dos jogadores
    printf("\nCarta do Jogador 1:");
    exibirCarta(cartaJogador1);

    printf("\nCarta do Jogador 2:");
    exibirCarta(cartaJogador2);

    // Jogador 1 escolhe um atributo para comparar
    int atributo;
    printf("\nJogador 1, escolha um atributo para comparar:\n");
    printf("1 - População\n");
    printf("2 - Área\n");
    printf("3 - IDH\n");
    printf("Digite sua escolha: ");
    scanf("%d", &atributo);

    // Comparação
    compararAtributo(cartaJogador1, cartaJogador2, atributo);

    return 0;
}
