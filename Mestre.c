#include <stdio.h>

#define NUM_ESTADOS 8
#define NUM_CIDADES 4


typedef struct {
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
    float super_poder; 
} Cidade;


void cadastrarCidades(Cidade cidades[NUM_ESTADOS][NUM_CIDADES]) {
    char estado;
    int cidade;

    for (estado = 'A'; estado <= 'H'; estado++) {
        for (cidade = 1; cidade <= 4; cidade++) {
            printf("Cadastro da cidade %c%02d\n", estado, cidade);
            printf("Digite a população: ");
            scanf("%d", &cidades[estado - 'A'][cidade - 1].populacao);

            while (getchar() != '\n');  

            printf("Digite a área (em km²): ");
            while (scanf("%f", &cidades[estado - 'A'][cidade - 1].area) != 1) {
                printf("Entrada inválida! Por favor, insira um número válido para a área: ");
                while (getchar() != '\n');
            }

            printf("Digite o PIB (em bilhões): ");
            while (scanf("%f", &cidades[estado - 'A'][cidade - 1].pib) != 1) {
                printf("Entrada inválida! Por favor, insira um número válido para o PIB: ");
                while (getchar() != '\n');
            }

            printf("Digite o número de pontos turísticos: ");
            while (scanf("%d", &cidades[estado - 'A'][cidade - 1].pontos_turisticos) != 1) {
                printf("Entrada inválida! Por favor, insira um número válido para pontos turísticos: ");
                while (getchar() != '\n');
            }

            
            cidades[estado - 'A'][cidade - 1].super_poder =
                cidades[estado - 'A'][cidade - 1].populacao +
                cidades[estado - 'A'][cidade - 1].area +
                cidades[estado - 'A'][cidade - 1].pib +
                cidades[estado - 'A'][cidade - 1].pontos_turisticos;

            printf("\n");
        }
    }
}


void exibirCidades(Cidade cidades[NUM_ESTADOS][NUM_CIDADES]) {
    char estado;
    int cidade; 

    for (estado = 'A'; estado <= 'H'; estado++) {
        for (cidade = 1; cidade <= 4; cidade++) {
            Cidade cidadeAtual = cidades[estado - 'A'][cidade - 1];

            float densidadePopulacional = cidadeAtual.populacao / cidadeAtual.area;
            float pibPerCapita = cidadeAtual.pib / cidadeAtual.populacao;

            printf("Cidade %c%02d:\n", estado, cidade);
            printf("População: %d\n", cidadeAtual.populacao);
            printf("Área: %.2f km²\n", cidadeAtual.area);
            printf("PIB: %.2f bilhões\n", cidadeAtual.pib);
            printf("Pontos turísticos: %d\n", cidadeAtual.pontos_turisticos);
            printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
            printf("PIB per Capita: %.2f bilhões/habitante\n", pibPerCapita);
            printf("Super Poder: %.2f\n\n", cidadeAtual.super_poder);
        }
    }
}


void compararCartas(Cidade carta1, Cidade carta2) {
    printf("Comparação entre as cartas:\n");

    
    float densidade1 = carta1.populacao / carta1.area;
    float densidade2 = carta2.populacao / carta2.area;

    printf("- Densidade Populacional: ");
    if (densidade1 < densidade2) {
        printf("Carta 1 vence (%.2f < %.2f)\n", densidade1, densidade2);
    } else if (densidade1 > densidade2) {
        printf("Carta 2 vence (%.2f > %.2f)\n", densidade1, densidade2);
    } else {
        printf("Empate (%.2f == %.2f)\n", densidade1, densidade2);
    }

    
    printf("- População: %s\n", carta1.populacao > carta2.populacao ? "Carta 1 vence" : "Carta 2 vence");
    printf("- Área: %s\n", carta1.area > carta2.area ? "Carta 1 vence" : "Carta 2 vence");
    printf("- PIB: %s\n", carta1.pib > carta2.pib ? "Carta 1 vence" : "Carta 2 vence");
    printf("- Pontos Turísticos: %s\n", carta1.pontos_turisticos > carta2.pontos_turisticos ? "Carta 1 vence" : "Carta 2 vence");
    printf("- Super Poder: %s\n\n", carta1.super_poder > carta2.super_poder ? "Carta 1 vence" : "Carta 2 vence");
}

int main() {
    Cidade cidades[NUM_ESTADOS][NUM_CIDADES];
    int estado1, cidade1, estado2, cidade2;

    
    cadastrarCidades(cidades);

    
    exibirCidades(cidades);

    
    printf("Selecione as cartas para comparação (Estado e Cidade):\n");
    printf("Carta 1 (Estado [1-8] e Cidade [1-4]): ");
    scanf("%d %d", &estado1, &cidade1);
    printf("Carta 2 (Estado [1-8] e Cidade [1-4]): ");
    scanf("%d %d", &estado2, &cidade2);

    estado1 -= 1;
    cidade1 -= 1;
    estado2 -= 1;
    cidade2 -= 1;

    compararCartas(cidades[estado1][cidade1], cidades[estado2][cidade2]);
    
    return 0;
}
/* Apesar de ter uma certa experiência com outra linguagem de programação, no caso o Python, tive certa dificuldade para montar um projeto 
bem estruturado e que funcionasse corretamente. Por vezes, precisei de ajuda externa para concluir por falta de tempo, tendo que conciliar
trabalho e estudos. Muito do que eu usei não aprendi nas aulas, pois já sabia ou busquei aprender enquanto trabalhava no projeto.
Trabalho concluído.
PS: Trabalhei apenas pelo VS. */

 




