#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <int> DSU(200);

int find (int i) {
    return (i == DSU[i]) ? i : find(DSU[i]);
}

void unite (int u, int v) {
    u = find(u);
    v = find(v);
    if (v != u)
        DSU[v] = u; 

}

void fillMatrix(int** a, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
}
int main() {
    vector <pair <int, pair<int, int>>> edges;
    int n;
    cout << "Type N and adjacency matrix:" << endl;
    cin >> n;
    DSU.resize(n);
    int** Matrix = new int* [n];
    for (int i = 0; i < n; i++) {
        Matrix[i] = new int[n];
    }
    fillMatrix(Matrix, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (Matrix[i][j] != -1){
                pair<int, pair<int, int>> a;
                a.first = Matrix[i][j];
                a.second.first = i;
                a.second.second = j;
                edges.push_back(a);
            }
        }
    }
    sort(edges.begin(), edges.end());
    vector <pair<int, pair <int, int>>> result;
    for (int i = 0; i < n; i++) 
        DSU[i] = i;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].second.first, v = edges[i].second.second;
        if (find(u) != find(v)) {
            result.push_back(edges[i]);
            unite(u,v);
        }
    }
    int** MatrixRes = new int* [n];
    for (int i = 0; i < n; i++) {
        MatrixRes[i] = new int[n];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            MatrixRes[i][j] = -1;
        }
    }
    for (int i = 0; i < result.size(); i++) {
        int u = result[i].second.first, v = result[i].second.second, w = result[i].first;
        MatrixRes[v][u] = MatrixRes[u][v] = w;
    }
    cout << endl;cout << endl;cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << MatrixRes[i][j] << " ";
        }
        cout << endl;
    }
    for (int i = 0; i < result.size(); i++) {
        cout << "(" << result[i].second.first << ", " << result[i].second.second << "): " << result[i].first << "; ";
    }
    return 0;
}
