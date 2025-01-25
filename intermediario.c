#include <stdio.h>

#define NUM_ESTADOS 8
#define NUM_CIDADES 4

// Definição de estrutura para armazenar as informações da cidade
typedef struct {
    int populacao;
    float area;
    float pib;
    int pontos_turisticos;
  

    

} Cidade;

// Função para cadastrar as cidades
void cadastrarCidades(Cidade cidades[NUM_ESTADOS][NUM_CIDADES]) {
    char estado;
    int cidade;

    for (estado = 'A'; estado <= 'H'; estado++) {
        for (cidade = 1; cidade <= 4; cidade++) {
            printf("Cadastro da cidade %c%02d\n", estado, cidade);
            printf("Digite a população: ");
            scanf("%d", &cidades[estado - 'A'][cidade - 1].populacao);

            // Limpar o buffer para evitar problemas com a leitura do próximo valor
            while (getchar() != '\n');  // Limpar qualquer entrada residual do buffer

            printf("Digite a área (em km²): ");
            while (scanf("%f", &cidades[estado - 'A'][cidade - 1].area) != 1) {
                printf("Entrada inválida! Por favor, insira um número válido para a área: ");
                while (getchar() != '\n');  // Limpar o buffer após erro de entrada
            }

            printf("Digite o PIB (em bilhões): ");
            while (scanf("%f", &cidades[estado - 'A'][cidade - 1].pib) != 1) {
                printf("Entrada inválida! Por favor, insira um número válido para o PIB: ");
                while (getchar() != '\n');  // Limpar o buffer após erro de entrada
            }

            printf("Digite o número de pontos turísticos: ");
            while (scanf("%d", &cidades[estado - 'A'][cidade - 1].pontos_turisticos) != 1) {
                printf("Entrada inválida! Por favor, insira um número válido para pontos turísticos: ");
                while (getchar() != '\n');  // Limpar o buffer após erro de entrada
            }

        

            printf("\n");
        }
    }
}
// Função para exibir as informações cadastradas das cidades
void exibirCidades(Cidade cidades[NUM_ESTADOS][NUM_CIDADES]) {
    char estado;
    int cidade; 

    for (estado = 'A'; estado <= 'H'; estado++) {
        for (cidade = 1; cidade <= 4; cidade++) {

            Cidade cidadeAtual = cidades[estado - 'A'][cidade - 1];

            float densidadePopulacional = cidadeAtual.populacao / cidadeAtual.area;
            float pibPerCapita = cidadeAtual.pib / cidadeAtual.populacao;

            
            printf("Cidade %c%02d:\n", estado, cidade);
            printf("População: %d\n", cidades[estado - 'A'][cidade - 1].populacao);
            printf("Área: %.2f km²\n", cidades[estado - 'A'][cidade - 1].area);
            printf("PIB: %.2f bilhões\n", cidades[estado - 'A'][cidade - 1].pib);
            printf("Pontos turísticos: %d\n\n", cidades[estado - 'A'][cidade - 1].pontos_turisticos);
            printf("Densidade Populacional: %.2f habitantes/km²\n", densidadePopulacional);
            printf("PIB per Capita: %.2f bilhões/habitante\n\n", pibPerCapita);
        }

    }
}

int main() {
    Cidade cidades[NUM_ESTADOS][NUM_CIDADES];
    
    // Cadastro das cidades
    cadastrarCidades(cidades);
    
    // Exibição dos dados cadastrados
    exibirCidades(cidades);

    return 0;
}
