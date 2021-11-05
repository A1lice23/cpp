#include <bits/stdc++.h>

using namespace std;

int seq[100001];

int l, r;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, s;
    cin >> n >> s;

    for(int i = 0; i < n; i++)
        cin >> seq[i];
    
    int sum = seq[0];
    int res = 200000000;

    while(l <= r && r < n){
        if(sum < s)
            sum += seq[++r];
        else if(sum == s){
            res = min(res, (r - l + 1));
            sum += seq[++r];
        }else if(sum > s){
            res = min(res, (r - l + 1));
            sum -= seq[l++];
        }
    }
    if(res == 200000000)
        cout << 0;
    else
        cout << res;

    return 0;
}