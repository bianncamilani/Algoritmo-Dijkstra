#include <stdio.h>    // Fornece funções para operações de entrada e saída, como printf (imprimir na tela) e scanf (ler do teclado).
#include <limits.h>   // Define várias constantes relacionadas aos limites dos tipos de dados inteiros, como INT_MAX, que representa o maior valor possível para um inteiro. Nesse caso, representa o infinito.
#include <ctype.h>    // Contém funções para testar e transformar caracteres, como toupper, que converte letras minúsculas em maiúsculas. 

#define V 7  // definindo que o grafo tem 7 vértices (A-G)
#define INF INT_MAX  // ausência de aresta na matriz do grafo

// Função que escolhe o próximo vértice que possui a menor distância ainda não visitado.
int menorDistancia(int distancia[], int visitado[]) {
    int menor = INF; 
    int indice = -1;
    for (int i = 0; i < V; i++) {
        if (!visitado[i] && distancia[i] < menor) {
            menor = distancia[i];
            indice = i;
        }
    }
    return indice;
}

// Algoritmo de Dijkstra
void dijkstra(int grafo[V][V], int origem) { 
    int distancia[V], visitado[V], anterior[V];

    // Inicializa vetores
    for (int i = 0; i < V; i++) {
        distancia[i] = INF;
        visitado[i] = 0;
        anterior[i] = -1;
    }

    distancia[origem] = 0;  // distância até a origem é zero

    // Loop principal do Dijkstra
    for (int i = 0; i < V - 1; i++) {
        int u = menorDistancia(distancia, visitado); // u recebe o indice do vertice mais proximo 
        if (u == -1) break;  // se não houver mais vertices validos -> encerra
        visitado[u] = 1;  // marca como visitado

        // Tenta diminuir a distancia atual
        for (int v = 0; v < V; v++) {
            if (!visitado[v] && grafo[u][v] != INF && distancia[u] + grafo[u][v] < distancia[v]) {
                distancia[v] = distancia[u] + grafo[u][v];  // atualiza a distancia
                anterior[v] = u;  // guarda o predecessor para montar o caminho 
            }
        }
    }

    // Exibe resultado
    printf("\nMenores distâncias a partir de %c:\n", origem + 'A');
    for (int i = 0; i < V; i++) {
        printf("%c -> %c = ", origem + 'A', i + 'A');  // para cada vertice vai imprimir a distancia 

        if (distancia[i] == INF) {
            printf("sem caminho\n");  // se não tiver caminho, imprime "sem caminho"
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
}

int main() {
    int grafo[V][V];  // monta a matriz do grafo 

    // Inicializa grafo com INF
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            grafo[i][j] = INF;
            
    // Representação do grafo:        
    // A → B (5)
    // A → C (3)
    // D → A (2)

    // B → C (2)
    // B → G (1)
    // B → E (3)

    // C → E (7)
    // C → D (7)

    // D → F (6)

    // F → E (1)

    // G → E (1)
       
    //Vertices Mapeados: A=0, B=1, C=2, D=3, E=4, F=5, G=6 

    // Arestas
    grafo[0][1] = 5;     // A->B
    grafo[0][2] = 3;     // A->C
    grafo[3][0] = 2;     // D->A
    
    grafo[1][2] = 2;     // B->C 
    grafo[1][6] = 1;     // B->G 
    grafo[1][4] = 3;     // B->E
    
    grafo[2][4] = 7;     // C->E
    grafo[2][3] = 7;     // C->D 
    
    grafo[3][5] = 6;     // D->F   
    
    grafo[5][4] = 1;     // F->E 
    
    grafo[6][4] = 1;     // G->E 

    // Entrada do usuário
    char letra;
    printf("Digite o ponto de origem (A-G): ");
    scanf(" %c", &letra);
    letra = toupper(letra);

    if (letra < 'A' || letra > 'G') {
        printf("Entrada inválida!\n");
        return 1;
    }

    int origem = letra - 'A';

    dijkstra(grafo, origem);

    return 0;
}