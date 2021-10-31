#include <bits/stdc++.h>

using namespace std;

vector <int> W;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    W.push_back(-1000);
    int n, x, len = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        if(x > W.back()){
            W.push_back(x);
            len++;
        }else{
            auto pivot = lower_bound(W.begin(), W.end(), x);
            *pivot = x;
        }
    }

    cout << len;

    return 0;
}