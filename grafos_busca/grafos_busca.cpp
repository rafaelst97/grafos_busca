// grafos_busca.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
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
    cout << "Qual ser? o n?mero de v?rtices que o grafo ter??" << endl;
    cin >> vertices;
    matriz = inicializa_matriz(vertices);
    visitados = inicializa_visitado(vertices);

    while (sair_menu == false) {

        int vertice1 = 0;
        int vertice2 = 0;
        int vertice_partida = 0;
        int opcao = 0;

        system("cls");

        cout << "Escolha uma op??o:" << endl;
        cout << "(1) Adicionar aresta" << endl;
        cout << "(2) Exibir matriz" << endl;
        cout << "(3) Fazer busca DFS" << endl;
        cout << "(4) Fazer busca BFS" << endl;
        cout << "(5) Excluir aresta" << endl;
        cout << "(6) Adicionar novo v?rtice" << endl;
        cout << "(7) Excluir v?rtice" << endl;
        cout << "(0) Sair do programa" << endl;
        cin >> opcao_menu;

        switch (opcao_menu)
        {
        case 1:

            system("cls");

            cout << "Escolha um v?rtice entre 1 e " << vertices << endl;
            do {
                cin >> vertice1;
                vertice1--;
            } while (vertice1 >= vertices);

            system("cls");

            cout << "O v?rtice " << vertice1+1 << " ser? ligado ? qual v?rtice? (Este v?rtice deve ser menor que " << vertices << ")" << endl;
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

            cout << "Qual ser? o v?rtice de partida?" << endl;
            do {
                cin >> vertice_partida;
                vertice_partida--;
            } while (vertice_partida >= vertices);

            dfs(matriz, visitados, vertice_partida);

            break;

        case 4:

            system("cls");

            cout << "Qual ser? o v?rtice de partida?" << endl;
            do {
                cin >> vertice_partida;
                vertice_partida--;
            } while (vertice_partida >= vertices);

            bfs(matriz, visitados, vertice_partida);

            break;

        case 5:

            system("cls");

            cout << "Escolha um v?rtice entre 1 e " << vertices << endl;
            do {
                cin >> vertice1;
                vertice1--;
            } while (vertice1 >= vertices);

            system("cls");

            cout << "O v?rtice " << vertice1 + 1 << " ser? desligado de qual v?rtice? (Este v?rtice deve ser menor que " << vertices << ")" << endl;
            do {
                cin >> vertice2;
                vertice2--;
            } while (vertice2 >= vertices);

            system("cls");


            excluir_aresta(matriz, vertice1, vertice2);

            break;

        case 6:

            system("cls");

            cout << "Deseja realmente adicionar um novo v?rtice?" << endl;
            cout << "(1) Sim" << endl;
            cout << "(2) N?o" << endl;
            do {
                cin >> opcao;
            } while (opcao > 1);

            system("cls");

            if (opcao == 1) {
                adicionar_vertice(matriz);
                cout << "V?rtice adicionado" << endl;
                vertices = matriz.size();
                system("pause");
            }

            break;

        case 7:

            system("cls");

            cout << "Qual v?rtice deseja excluir?" << endl;
            do {
                cin >> opcao;
            } while (opcao > matriz.size());

            excluir_vertice(matriz, opcao);
            vertices = matriz.size();
            system("cls");

            break;

        case 0:

            system("cls");
            sair_menu = true;

            break;
        }
        
    }
    
}