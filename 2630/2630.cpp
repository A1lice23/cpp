#include <bits/stdc++.h>

using namespace std;

int paper[128][128] = {0, };

pair<int, int> check(int x, int y, int N){
    
    pair<int, int> res, p;
    int sign[4][2] = {{0,0}, {0,1}, {1,0},{1,1}};
    
    if(N == 1){
        if(paper[x][y] == 1)
            return make_pair(0, 1);
        else
            return make_pair(1, 0);
    }else{
        res = make_pair(0,0);
        for(int i = 0; i < 4; i++){
            p = check(x+sign[i][0]*(N/2), y+sign[i][1]*(N/2), N/2);
            res.first += p.first;
            res.second += p.second;
        }
        //cout << "x" << x << " " << "y" << y << "\n"; 
        //cout << "point" << res.first << " " << res.second << "\n";
        if(res.first == 4 && res.second == 0){
            return make_pair(1, 0);
        }else if(res.second == 4 && res.first == 0){
            return make_pair(0, 1);
        }else{
            return res;
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> paper[i][j];
    
    pair<int,int> ans = check(0, 0, n);
    cout << ans.first << '\n' << ans.second;

    return 0;
}