🔍 Algoritmo de Dijkstra em C — Menores Caminhos

Este projeto implementa o Algoritmo de Dijkstra em linguagem C, permitindo calcular o menor caminho entre um vértice de origem e todos os demais vértices de um grafo direcionado e ponderado. O programa foi desenvolvido como trabalho da disciplina LCII (laboratótio de Computação II), aplicando conceitos de grafos, algoritmos de caminhos mínimos e manipulação de matrizes.

🧠 Sobre o Algoritmo

O Algoritmo de Dijkstra encontra o menor custo de deslocamento entre um ponto inicial e todos os outros vértices de um grafo, desde que os pesos das arestas sejam positivos.

No seu programa:

O grafo possui 7 vértices (A a G).

As arestas possuem pesos positivos.

A matriz é preenchida com INF para representar ausência de aresta.

O caminho mínimo é reconstruído e exibido ao usuário.

📌 Funcionalidades

- Recebe como entrada um vértice de origem (A-G)
- Calcula o menor caminho para todos os outros vértices
- Reconstrói e mostra o caminho percorrido
- Exibe "sem caminho" quando não existe trajeto possível
- Grafo totalmente configurado no código

🗺 Estrutura do Grafo (arestas)

Representação das ligações:

De	Para	Peso
A	B	5
A	C	3
D	A	2
B	C	2
B	G	1
B	E	3
C	E	7
C	D	7
D	F	6
F	E	1
G	E	1

Mapeamento dos vértices:

A = 0
B = 1
C = 2
D = 3
E = 4
F = 5
G = 6


💻 Principais Partes do Código
📌 Função menorDistancia()

- Seleciona o próximo vértice com menor distância ainda não visitado.

📌 Função dijkstra()

- Inicializa vetores de distância, visitados e caminho anterior

- Percorre o grafo

- Atualiza menores caminhos

- Reconstrói o caminho final para cada vértice

- Exibe os resultados

📌 Grafo pré-definido

- Representado por uma matriz 7×7 com valores de peso ou INF.

👩‍💻 Autor(a)
- Bianca Milani
- Ana Beatriz Costa
- Sara Andrade
- Ágata Silverio
