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

	matriz[vertice1].at(vertice2) = 1;

}