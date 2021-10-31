#include <bits/stdc++.h>

using namespace std;

int n,s;
int arr[40];
vector<long long> f, b;

void dfs(int st, int end, long long sum, vector<long long> &v){
    if(st == end){
        v.push_back(sum);
        return;
    }
    dfs(st+1, end, sum, v);
    dfs(st+1, end, sum + arr[st], v);
}

int main(){

    cin >> n >> s;
    int x;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    dfs(0, n/2, 0, f);
    dfs(n/2, n, 0, b);

    sort(b.begin(), b.end());
    
    //cout << "\n";
    long long up_pos, lw_pos, ans = 0;
    for(int i = 0; i < f.size(); i++){
        up_pos = upper_bound(b.begin(), b.end(), s - f[i]) - b.begin();
        lw_pos = lower_bound(b.begin(), b.end(), s - f[i]) - b.begin();
        //cout << f[i] << " " << up_pos << " " << lw_pos << "\n";
        ans += up_pos - lw_pos;
    }
    if(s == 0)
        ans--;
    cout << ans;

    return 0;
}