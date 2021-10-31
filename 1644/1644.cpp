#include <bits/stdc++.h>

using namespace std;

int prime[500000];
bool check[4000000] = {false, };

int main(){

    int n, l = 0, r = 0, idx = 0, sum = 0, cnt = 0;

    for(int i = 2; i*i <= 4000000; i++){
        if(!check[i]){
            for(int j = 2; i*j<= 4000000; j++)
                check[j*i] = true;
        }
    }
    for(int i = 2; i <= 4000000; i++){
        if(!check[i])
            prime[idx++] = i;
    }
    
    cin >> n;
    while(r <= idx){
        if(sum < n){
            sum += prime[r++];
            continue;
        }
        if(sum == n)
            cnt++;

        sum -= prime[l++];
    }
    cout << cnt;

    return 0;
}