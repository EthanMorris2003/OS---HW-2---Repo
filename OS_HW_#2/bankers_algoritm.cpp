#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    ifstream file("input.txt");
    if (!file) {
        cerr << "Error: Unable to open input file." << endl;
        return 1;
    }

    int n, m;  
    file >> n >> m;

    vector<vector<int> > alloc(n, vector<int>(m));
    vector<vector<int> > max(n, vector<int>(m));
    vector<int> avail(m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            file >> alloc[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            file >> max[i][j];
        }
    }

    for (int j = 0; j < m; j++) {
        file >> avail[j];
    }

    file.close();

    vector<int> f(n, 0), ans(n);
    int ind = 0;

    vector<vector<int> > need(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    int y = 0;
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (f[i] == 0) {  
                int flag = 0;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }

                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++) {
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    bool safe = true;
    for (int i = 0; i < n; i++) {
        if (f[i] == 0) {
            safe = false;
            cout << "The given sequence is not safe." << endl;
            break;
        }
    }

    if (safe) {
        cout << "Following is the SAFE Sequence:" << endl;
        for (int i = 0; i < n - 1; i++) {
            cout << " P" << ans[i] << " ->";
        }
        cout << " P" << ans[n - 1] << endl;
    }

    return 0;
}