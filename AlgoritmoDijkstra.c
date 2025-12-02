#include <stdio.h>    // Fornece funções para operações de entrada e saída, como printf (imprimir na tela) e scanf (ler do teclado).
#include <limits.h>   // Define várias constantes relacionadas aos limites dos tipos de dados inteiros, como INT_MAX, que representa o maior valor possível para um inteiro. Nesse caso, representa o infinito.
#include <ctype.h>    // Contém funções para testar e transformar caracteres, como toupper, que converte letras minúsculas em maiúsculas. 
#include <stdlib.h>   // Fornece funções para alocação de memória, controle de processos e conversão de tipos, como malloc, free, atoi e exit.

#define INF INT_MAX  // ausência de aresta na matriz do grafo

// Função que escolhe o próximo vértice que possui a menor distância ainda não visitado.
int menorDistancia(int distancia[], int visitado[], int ordem) { // 
    int menor = INF; 
    int indice = -1;
    for (int i = 0; i < ordem; i++) {
        if (!visitado[i] && distancia[i] < menor) {
            menor = distancia[i];
            indice = i;
        }
    }
    return indice;
}

// Algoritmo de Dijkstra
void dijkstra(int** grafo, int origem, int ordem) { 

    // Vetor que guardará a menor distância encontrada até cada vértice
    int* distancia = malloc(sizeof(int)*ordem); 

    // Vetor que marca quais vértices já foram visitados (1 = visitado, 0 = não visitado)
    int* visitado = malloc(sizeof(int)*ordem);

    // Vetor usado para reconstruir o caminho (guarda o vértice anterior no menor caminho)
    int* anterior = malloc(sizeof(int)*ordem);

    // Inicializa vetores
    for (int i = 0; i < ordem; i++) {
        distancia[i] = INF;
        visitado[i] = 0;
        anterior[i] = -1;
    }

    distancia[origem] = 0;  // Atualiza a distância mínima até v

    // Loop principal do Dijkstra
    for (int i = 0; i < ordem - 1; i++) {
        int u = menorDistancia(distancia, visitado, ordem); // u recebe o indice do vertice mais proximo 
        if (u == -1) break;  // se não houver mais vertices validos -> encerra
        visitado[u] = 1;  // marca como visitado

        // Tenta diminuir a distancia atual
        for (int v = 0; v < ordem; v++) {

            // Verifica 3 condições: 1. v ainda não foi visitado. 2. Existe aresta entre u e v (grafo[u][v] != INF). 3. A distância passando por u é menor que a distância atual
            if (!visitado[v] && grafo[u][v] != INF && distancia[u] + grafo[u][v] < distancia[v]) {
                distancia[v] = distancia[u] + grafo[u][v];  // atualiza a distancia
                anterior[v] = u;  // guarda o predecessor para montar o caminho 
            }
        }
    }

    // Exibe resultado
    printf("\nMenores distancias a partir de %c:\n", origem + 'A');
    for (int i = 0; i < ordem; i++) {
        printf("%c -> %c = ", origem + 'A', i + 'A');  // para cada vertice vai imprimir a distancia 

        if (distancia[i] == INF) {
            printf("Sem caminho\n");  // se não tiver caminho, imprime "sem caminho"
        } else {
            printf("%d | Caminho: ", distancia[i]); // se tiver o caminho, reconstroi o trajeto

            // Reconstrói o caminho
            int caminho[20], t = 0, atual = i;
            while (atual != -1) {
                caminho[t++] = atual;
                atual = anterior[atual];
            }
            for (int k = t - 1; k >= 0; k--)
                printf("%c ", caminho[k] + 'A');
            printf("\n");
        }
    }

     // Libera memória
    free(visitado);
    free(distancia);
    free(anterior);
}

// Cria uma matriz utilizando alocação dinâmica com malloc
int** matriz(int linhas, int colunas) {
    int ** m = malloc(sizeof(int*)*linhas);
    for (int i=0; i<linhas; i++) 
        m[i] = malloc(sizeof(int)*colunas);
    return m;
}

// Função que aloca dinamicamente uma matriz de inteiros
int main(int argc, char* argv[]) {

    FILE * GRAFO;
     // Se recebeu arquivo, abre; senão, lê do teclado
    if (argc > 1) 
        GRAFO = fopen(argv[1], "r");
    else 
        GRAFO = stdin;
        
    int ordem;
    int arestas;

    printf("Digte a quantidade de vertices e de arestas: ");
    fscanf(GRAFO, "%d %d", &ordem, &arestas);    
    printf("%d %d\n", ordem, arestas);

    int** grafo = matriz(ordem, ordem);  // monta a matriz do grafo 

    // Inicializa grafo com INF
    for (int i = 0; i < ordem; i++)
        for (int j = 0; j < ordem; j++)
            grafo[i][j] = INF;

    // Leitura das arestas e pesos
    char i, j;
    int peso;
    for (int e=0; e<arestas;e++) {
        printf("Digite o vertice de origem, o vertice de destino e o peso da aresta: ");
        fscanf(GRAFO, " %c %c %d", &i, &j, &peso);
        i = toupper(i);
        j = toupper(j);

        printf("%c->%c = %d\n", i, j, peso);
        grafo[i - 'A'][j - 'A'] = peso;
    }        

    // Entrada do usuário
    char letra;
    printf("Digite o ponto de origem (A-%c): ", 'A' + ordem - 1);
    scanf(" %c", &letra);
    letra = toupper(letra);

    if (letra < 'A' || letra >= 'A' + ordem) {
        printf("Entrada inválida!\n");
        return 1;
    }

    int origem = letra - 'A';

    // Executa Dijkstra
    dijkstra(grafo, origem, ordem);

    return 0;
}