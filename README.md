Algoritmo de Dijkstra em C — Otimização de Rotas em Rede Logística

Este projeto implementa o Algoritmo de Dijkstra em linguagem C para calcular o menor caminho entre uma cidade de origem e todas as demais em uma rede logística modelada como grafo direcionado e ponderado. O trabalho foi desenvolvido como parte da disciplina LCII (Laboratório de Computação II), aplicando conceitos de grafos, caminhos mínimos, matriz de adjacência, alocação dinâmica e leitura de arquivos externos.

Sobre o Algoritmo

O Algoritmo de Dijkstra é utilizado para determinar o menor custo/tempo de deslocamento entre um ponto inicial e todos os outros vértices de um grafo, desde que todos os pesos sejam não negativos.

No contexto deste projeto:
- O grafo possui 7 cidades (A a G).
- As rotas são direcionadas.
- Cada rota tem um peso de custo/tempo.
- A matriz é preenchida com INF (INT_MAX) para indicar ausência de rota.
- O menor caminho é reconstruído usando o vetor anterior[].

Funcionalidades do Programa

- Leitura da rede logística a partir de um arquivo entrada.txt
- Recebe a cidade de origem escolhida pelo usuário
- Calcula a menor distância até todas as demais cidades
- Reconstrói e exibe o caminho mínimo
- Indica quando não existe rota possível
- Suporta redes modificáveis sem necessidade de recompilação (basta editar o arquivo de entrada)

Implementação — Principais Componentes
Função menorDistancia()

- Identifica o próximo vértice não visitado com a menor distância acumulada.

Função dijkstra()

- Inicializa vetores distancia[], visitado[] e anterior[]
- Percorre o grafo realizando relaxamento das arestas
- Atualiza menores distâncias
- Reconstrói o caminho final de cada cidade
- Exibe as distâncias e trajetos encontrados

Entrada via Arquivo .txt

- Permite definir ordem, arestas, pesos e vértices
A execução é feita via linha de comando:

.\AlgoritmoDijkstra.exe entrada.txt

Grafo definido por Matriz de Adjacência

- Matriz 7×7
- Valores representam peso da rota ou INF quando não há ligação direta

Exemplos de Saída (Origem: A)

O algoritmo retorna:

- Distância mínima
- Caminho reconstruído cidade por cidade

Autores
- Bianca Milani
- Ana Beatriz Costa
- Sara Andrade
- Ágata Silvério
