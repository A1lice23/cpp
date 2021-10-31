#include <bits/stdc++.h>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int m, n, t, x, y, ans = 0;
    int sign[4][2] = {{1,0}, {0,1}, {-1,0},{0,-1}};
    cin >> m >> n;

    int tmap[m][n] = {0, };
    queue<pair<int, int_fast32_t>> q;
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> t;
            if(t == 0){
            }else if(t == 1){
                    q.push(make_pair(j, i));
            }
            tmap[j][i] = t;
        }
    }
    while(!q.empty()){
        pair<int, int> p = q.front();
        for(int i = 0; i < 4; i++){
            x = p.first + sign[i][0];
            y = p.second + sign[i][1];
            if(x >= 0 && x < m){
                if(y >= 0 && y < n){
                    if(tmap[x][y]==0){
                        q.push(make_pair(x,y));
                        //cout << x << " " << y << " " << tmap[x][y] << "\n";
                        tmap[x][y] = tmap[p.first][p.second] + 1;
                    }
                }
            }
        }
        q.pop();
    }
    //cout << tcnt << "\n";
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(tmap[j][i] == 0){
                cout << -1;
                return 0;
            }
            if(ans < tmap[j][i]){
                ans = tmap[j][i];
            }
        }
    }
    cout << ans-1;
    return 0;
}