🔍 Algoritmo de Dijkstra em C — Otimização de Rotas em Rede Logística

Este projeto implementa o Algoritmo de Dijkstra em linguagem C para calcular o menor caminho entre uma cidade de origem e todas as demais em uma rede logística modelada como grafo direcionado e ponderado. O trabalho foi desenvolvido como parte da disciplina LCII (Laboratório de Computação II), aplicando conceitos de grafos, caminhos mínimos, matriz de adjacência, alocação dinâmica e leitura de arquivos externos.

🧠 Sobre o Algoritmo

O Algoritmo de Dijkstra é utilizado para determinar o menor custo/tempo de deslocamento entre um ponto inicial e todos os outros vértices de um grafo, desde que todos os pesos sejam não negativos.

No contexto deste projeto:
- O grafo possui 7 cidades (A a G).
- As rotas são direcionadas.
- Cada rota tem um peso de custo/tempo.
- A matriz é preenchida com INF (INT_MAX) para indicar ausência de rota.
- O menor caminho é reconstruído usando o vetor anterior[].

📌 Funcionalidades do Programa

- Leitura da rede logística a partir de um arquivo entrada.txt
- Recebe a cidade de origem escolhida pelo usuário
- Calcula a menor distância até todas as demais cidades
- Reconstrói e exibe o caminho mínimo
- Indica quando não existe rota possível
- Suporta redes modificáveis sem necessidade de recompilação (basta editar o arquivo de entrada)

🗺 Estrutura do Grafo (Arestas)

A rede logística utilizada contém as seguintes rotas:

De	Para	Peso
A	  B	    5
A	  C	    3
B	  C	    2
B	  G	    1
B	  E	    3
C	  E	    7
C	  D	    7
D	  A	    2
D	  F	    6
F	  E	    1
G	  E	    1

📍 Mapeamento dos vértices
A = 0
B = 1
C = 2
D = 3
E = 4
F = 5
G = 6

💻 Implementação — Principais Componentes
📌 Função menorDistancia()

- Identifica o próximo vértice não visitado com a menor distância acumulada.

📌 Função dijkstra()

- Inicializa vetores distancia[], visitado[] e anterior[]
- Percorre o grafo realizando relaxamento das arestas
- Atualiza menores distâncias
- Reconstrói o caminho final de cada cidade
- Exibe as distâncias e trajetos encontrados

📌 Entrada via Arquivo .txt

- Permite definir ordem, arestas, pesos e vértices
A execução é feita via linha de comando:

.\AlgoritmoDijkstra.exe entrada.txt

📌 Grafo definido por Matriz de Adjacência

- Matriz 7×7
- Valores representam peso da rota ou INF quando não há ligação direta

Exemplos de Saída (Origem: A)

O algoritmo retorna:

- Distância mínima
- Caminho reconstruído cidade por cidade

Exemplo de alguns resultados:

Cidade	Menor Distância	Caminho
A	      0	              A
B	      5	              A → B
C	      3	              A → C
E	      7	              A → B → G → E
D	      9	              A → B → G → E → D
F	      8	              A → B → G → E → F
G	      6	              A → B → G

👩‍💻 Autores
- Bianca Milani
- Ana Beatriz Costa
- Sara Andrade
- Ágata Silvério
