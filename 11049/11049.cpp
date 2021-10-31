#include <bits/stdc++.h>

using namespace std;

int dp[501][501];

pair<int, int> m[501];

int mat(int x, int y){
    if(x==y)
        return 0;
    int& ref = dp[x][y];
    if(ref != -1)
        return ref;
    
    int mm = INT_MAX;
    for(int k = x; k < y; k++)
        mm = min(mm, mat(x, k) + mat(k+1, y) + m[x].first * m[k].second * m[y].second);
    
    return ref = mm;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> m[i].first >> m[i].second;
    
    memset(dp, -1, sizeof(dp));

    cout << mat(0, n-1);

    return 0;
}