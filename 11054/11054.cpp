#include <bits/stdc++.h>

using namespace std;

int w[1001], d[1001], rd[1001];

int main(){

    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> w[i];

    for(int i = 0; i < n; i++){
        d[i] = 1;
        for(int j = 0; j < i; j++){
            if(w[j] < w[i]){
                d[i] = max(d[i], d[j] + 1);
            }
        }
    }
    for(int i = n-1; i >= 0; i--){
        rd[i] = 1;
        for(int j = n-1; j > i; j--){
            if(w[j] < w[i]){
                rd[i] = max(rd[i], rd[j] + 1);
            }
        }
    }
    int max_len = -1;
    for(int i = 0; i < n; i++){
        if(max_len < d[i] + rd[i]-1){
            max_len = d[i] + rd[i] - 1;
        }
    }
    cout << max_len;

    return 0;
}