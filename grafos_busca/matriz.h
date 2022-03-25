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

void visita(vector<vector<int>>matriz ,vector<bool>&visitados, int vertice, vector<int>&resultado) {

	if (visitados[vertice] == false) {
		resultado.push_back(vertice);
	}
	visitados[vertice] = true;
	cout << vertice+1 << ", " << endl;

	for (auto i = matriz[vertice].begin(); i < matriz[vertice].end(); i++) {
		
		if (!visitados[*i]) {
			visita(matriz, visitados, *i, resultado);
		}
	}
}

void dfs(vector<vector<int>>matriz, vector<bool>&visitados, int vertice_partida, int vertices) {

	stack<int> pilha;

	while (true) {
		if (!visitados[vertice_partida]) {
			
			cout << vertice_partida + 1 << ", ";
			visitados[vertice_partida] = true;
			pilha.push(vertice_partida);
		}

		bool encontrado = false;
		int i;

		for (i = 0; i < vertices; i++) {

			if (!visitados[i]) {
				encontrado = true;
				break;
			}

		}

		if (encontrado) {

			vertice_partida = i;
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
}