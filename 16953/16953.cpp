#include <bits/stdc++.h>

using namespace std;
int mincost = 100000;
long long a, b;

void dfs(long long int x, int cost){
    if(x > b){
        return;
    }else if(x == b){
        if(mincost > cost){
            mincost = cost;
        }
        return;
    }else{
        dfs(2*x, cost+1);
        dfs(10*x+1, cost+1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> a >> b;
    dfs(a, 1);

    if(mincost < 100000){
        cout << mincost;
    }else{
        cout << -1;
    }
    return 0;
}