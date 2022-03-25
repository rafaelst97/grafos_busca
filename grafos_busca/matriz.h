#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
#include <stack>

using namespace std;


vector<bool> visitados;

vector<vector<int>> inicializa_matriz(int numero_vertices) {

	vector<vector<int>> matriz;
	matriz.assign(numero_vertices, vector<int>(numero_vertices, 0));

	return matriz;
}

vector<bool> inicializa_visitado(int numero_vertices) {

	visitados.assign(numero_vertices, false);

	return visitados;
}

void adicionar_aresta(vector<vector<int>> &matriz, int vertice1, int vertice2) {

	int v1 = vertice1 - 1;
	int v2 = vertice2 - 1;

	matriz[vertice1].at(vertice2) = 1;

}

void excluir_aresta(vector<vector<int>>& matriz, int vertice1, int vertice2) {

	int v1 = vertice1 - 1;
	int v2 = vertice2 - 1;

	matriz[vertice1].at(vertice2) = 0;

}

void dfs(vector<vector<int>>matriz, vector<bool>&visitados, int vertice_partida) {

	stack<int> pilha;
	int maximo = visitados.size();

	system("cls");

	while (true) {
		if (!visitados[vertice_partida]) {
			
			cout << vertice_partida + 1 << ", ";
			visitados[vertice_partida] = true;
			pilha.push(vertice_partida);
		}

		bool vertice_valido = false;
		bool encontrado = false;
		int iterador = 0;


		for (iterador = 0; iterador < maximo; iterador++) {

			if (matriz[vertice_partida].at(iterador) == 1) {

				vertice_valido = true;

			}

			if (!visitados[iterador] && vertice_valido) {
				encontrado = true;
				break;
			}

		}

		if (encontrado) {

			vertice_partida = iterador;
		}
		else {
			pilha.pop();

			if (pilha.empty()) {
				break;
			}

			vertice_partida = pilha.top();
		}

		
	}
	
	system("pause");

	fill(visitados.begin(), visitados.end(), false);
}

void bfs(vector<vector<int>>matriz, vector<bool>& visitados, int vertice_partida) {

	system("cls");

	queue<int> fila;
	int maximo = visitados.size();

	for (int i = 0; i < vertice_partida; i++) {
		visitados[i] = false;
	}

	cout << vertice_partida+1 << ", ";

	visitados[vertice_partida] = true;

	while (true) {

		int iterador = 0;
		bool vertice_valido = false;

		for (iterador = 0; iterador < maximo; iterador++) {

			if (matriz[vertice_partida].at(iterador) == 1) {

				vertice_valido = true;

			}

			if (!visitados[iterador] && vertice_valido) {
				cout << iterador+1 << ", ";
				visitados[iterador] = true;
				fila.push(iterador);
			}
		}

		if (!fila.empty()) {

			vertice_partida = fila.front();
			fila.pop();

		}
		else

			break;
	}

	system("pause");

	fill(visitados.begin(), visitados.end(), false);
}