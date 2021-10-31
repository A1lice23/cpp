#include <bits/stdc++.h>

using namespace std;

int total[1025][1025];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    int x;
    int x1, x2, y1, y2;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> x;
            total[i][j] = total[i][j-1] + total[i-1][j] - total[i-1][j-1] + x;
        }
    }
    while(m--){
        cin >> x1 >> y1 >> x2 >> y2;
        cout << total[x2][y2] - total[x1-1][y2] - total[x2][y1-1] + total[x1-1][y1-1] << "\n";
    }
    return 0;
}