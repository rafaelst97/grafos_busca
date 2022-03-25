// grafos_busca.cpp : Este arquivo cont√©m a fun√ß√£o 'main'. A execu√ß√£o do programa come√ßa e termina ali.
//

#include <iostream>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <locale>
#include <locale.h>
#include "matriz.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");

    vector<vector<int>> matriz;
    vector<bool> visitados;
    int vertices = 0;
    int opcao_menu = 0;
    bool sair_menu = false;
    
    system("cls");
    cout << "Qual ser· o n˙mero de vÈrtices que o grafo ter·?" << endl;
    cin >> vertices;
    matriz = inicializa_matriz(vertices);
    visitados = inicializa_visitado(vertices);

    while (sair_menu == false) {

        int vertice1 = 0;
        int vertice2 = 0;
        int vertice_partida = 0;

        system("cls");

        cout << "Escolha uma opÁ„o:" << endl;
        cout << "(1) Adicionar aresta" << endl;
        cout << "(2) Exibir matriz" << endl;
        cout << "(3) Fazer busca DFS" << endl;
        cout << "(4) Fazer busca BFS" << endl;
        cout << "(0) Sair do programa" << endl;
        cin >> opcao_menu;

        switch (opcao_menu)
        {
        case 1:

            system("cls");

            cout << "Escolha um vÈrtice entre 1 e " << vertices << endl;
            do {
                cin >> vertice1;
                vertice1--;
            } while (vertice1 >= vertices);

            system("cls");

            cout << "O vÈrtice " << vertice1+1 << " ser· ligado ‡ qual vÈrtice? (Este vÈrtice deve ser menor que " << vertices << ")" << endl;
            do {
                cin >> vertice2;
                vertice2--;
            } while (vertice2 >= vertices);

            system("cls");
            

            adicionar_aresta(matriz, vertice1, vertice2);

            break;

        case 2:

            system("cls");

            for (auto& linha : matriz) {
                for (auto& coluna : linha) {
                    cout << " | " << coluna;
                }
                cout << endl;
            }

            system("pause");

            break;

        case 3:

            system("cls");

            cout << "Qual ser· o vÈrtice de partida?" << endl;
            do {
                cin >> vertice_partida;
            } while (vertice_partida >= vertices);

            dfs(matriz, visitados, vertice_partida);

            break;

        case 0:

            system("cls");
            sair_menu = true;

            break;
        }
        
    }
    
}