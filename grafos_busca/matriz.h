#pragma once

#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>

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

void visita(vector<vector<int>>matriz ,vector<bool>&visitados, int vertice) {

	visitados[vertice] = true;
	cout << vertice+1 << ", " << endl;

	for (auto i = matriz[vertice].begin(); i < matriz[vertice].end(); i++) {
		
		if (!visitados[*i]) {
			visita(matriz, visitados, *i);
		}
	}
}

void dfs(vector<vector<int>>matriz, vector<bool>&visitados, int vertice_partida) {
	for (int it = 0; it < vertice_partida; it++) {
		if (!visitados[vertice_partida]) {
			visita(matriz, visitados, vertice_partida);
		}
	}

	system("pause");
}