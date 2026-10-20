
#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

int A[100][100];
int n;
int visited[100];
int path[100];
int bestPath[100];
int minCost = INT_MAX;
int pathLength = 0;
int bestLength = 0;

void Nhap() {
    ifstream f("Grap.txt");
    f >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            f >> A[i][j];

    f.close();
}

void HienThi() {
    cout << "  ";
    for (int i = 0; i < n; i++)
        cout << char('A' + i) << " ";
    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << char('A' + i) << " ";
        for (int j = 0; j < n; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
}

void DFS(int u, int v, int cost) {
    visited[u] = 1;
    path[pathLength++] = u;

    if (u == v) {
        if (cost < minCost) {
            minCost = cost;
            bestLength = pathLength;

            for (int i = 0; i < pathLength; i++)
                bestPath[i] = path[i];
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (A[u][i] > 0 && !visited[i] &&
                cost + A[u][i] < minCost) {
                DFS(i, v, cost + A[u][i]);
            }
        }
    }

    pathLength--;
    visited[u] = 0;
}

int main() {
    Nhap();

    cout << "Ma tran trong so:\n";
    HienThi();

    int u = 0, v = 6;
    DFS(u, v, 0);

    if (minCost == INT_MAX) {
        cout << "Khong co duong di\n";
    } else {
        cout << "Duong di ngan nhat: ";

        for (int i = 0; i < bestLength; i++) {
            cout << char('A' + bestPath[i]);

            if (i < bestLength - 1)
                cout << " -> ";
        }

        cout << "\nTong trong so: " << minCost << endl;
    }

    return 0;
}
