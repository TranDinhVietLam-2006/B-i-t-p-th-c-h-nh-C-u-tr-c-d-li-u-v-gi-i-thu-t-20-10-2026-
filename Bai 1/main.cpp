#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100;

int n;
int A[MAX][MAX];
char tenDinh[] = "ABCDEFGH";

bool Nhap() {
    ifstream f("Grap.txt");

    if (!f.is_open()) {
        cout << "Khong mo duoc file Grap.txt!";
        return false;
    }

    f >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            f >> A[i][j];
        }
    }

    f.close();
    return true;
}

void HienThi() {
    cout << "Ma tran ke:\n";
    cout << "  ";

    for (int j = 0; j < n; j++) {
        cout << tenDinh[j] << " ";
    }

    cout << endl;

    for (int i = 0; i < n; i++) {
        cout << tenDinh[i] << " ";

        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }

        cout << endl;
    }
}

void BFS(int u, int v) {
    bool daTham[MAX] = {false};
    int truoc[MAX];

    for (int i = 0; i < n; i++) {
        truoc[i] = -1;
    }

    queue<int> q;
    daTham[u] = true;
    q.push(u);

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        for (int y = 0; y < n; y++) {
            if (A[x][y] == 1 && !daTham[y]) {
                daTham[y] = true;
                truoc[y] = x;
                q.push(y);
            }
        }
    }

    if (!daTham[v]) {
        cout << "Khong co duong di!";
        return;
    }

    vector<int> duongDi;

    for (int x = v; x != -1; x = truoc[x]) {
        duongDi.push_back(x);
    }

    reverse(duongDi.begin(), duongDi.end());

    cout << "Duong di ngan nhat: ";

    for (int i = 0; i < (int)duongDi.size(); i++) {
        cout << tenDinh[duongDi[i]];

        if (i < (int)duongDi.size() - 1) {
            cout << " -> ";
        }
    }

    cout << "\nSo canh: " << duongDi.size() - 1 << endl;
}

int main() {
    if (!Nhap()) {
        return 1;
    }

    HienThi();

    cout << "\nDuong di tu A den H:\n";
    BFS(0, 7);

    return 0;
}
