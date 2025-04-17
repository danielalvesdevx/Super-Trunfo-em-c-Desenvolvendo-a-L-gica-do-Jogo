#include <stdio.h>
#include <string.h>

// Estrutura que representa uma carta do Super Trunfo
struct Carta {
    char estado[3];
    char codigo[10];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float densidade_populacional;
    float pib_per_capita;
};

// Função que calcula densidade populacional e PIB per capita
void calcularIndicadores(struct Carta *carta) {
    carta->densidade_populacional = carta->populacao / carta->area;
    carta->pib_per_capita = carta->pib / carta->populacao;
}

// Função principal
int main() {
    // Cadastro das cartas (valores fictícios)
    struct Carta carta1 = {"SP", "C001", "São Paulo", 12300000, 1521.11, 230000000000.0, 30};
    struct Carta carta2 = {"RJ", "C002", "Rio de Janeiro", 6000000, 1182.3, 120000000000.0, 25};

    // Calculando indicadores
    calcularIndicadores(&carta1);
    calcularIndicadores(&carta2);

    // Comparação baseada em POPULAÇÃO (pode ser alterado para outro atributo)
    printf("Comparação de cartas (Atributo: População):\n\n");
    printf("Carta 1 - %s (%s): %d\n", carta1.cidade, carta1.estado, carta1.populacao);
    printf("Carta 2 - %s (%s): %d\n\n", carta2.cidade, carta2.estado, carta2.populacao);

    if (carta1.populacao > carta2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", carta1.cidade);
    } else if (carta2.populacao > carta1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", carta2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }

    // Exibição opcional dos outros indicadores
    printf("\nIndicadores adicionais:\n");
    printf("%s - Densidade Populacional: %.2f hab/km², PIB per capita: R$ %.2f\n",
           carta1.cidade, carta1.densidade_populacional, carta1.pib_per_capita);
    printf("%s - Densidade Populacional: %.2f hab/km², PIB per capita: R$ %.2f\n",
           carta2.cidade, carta2.densidade_populacional, carta2.pib_per_capita);

    return 0;
}
