#include <bits/stdc++.h>

using namespace std;

int graph[501][501], way[501][501];
int sign[2][4] = {{0, 1, 0, -1}, {1, 0, -1, 0}};

int dfs(int y, int x, int m, int n){
    if(y == m && x == n)
        return 1;
    else if(way[y][x] == -1){
        way[y][x] = 0;
        for(int i = 0; i < 4; i++){
            int nx = x + sign[0][i];
            int ny = y + sign[1][i];
            if(nx > 0 && ny > 0 && nx <= n && ny <= m && graph[y][x] > graph[ny][nx]){
                way[y][x] += dfs(ny, nx, m, n);
            }
        }
    }
    return way[y][x];
}

int main(){

    int m, n;

    cin >> m >> n;

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            way[i][j] = -1;
        }
    }

    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            cin >> graph[i][j];
        }
    }

    cout << dfs(1, 1, m, n);

    return 0;
}