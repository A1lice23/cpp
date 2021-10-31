#include <bits/stdc++.h>

using namespace std;

int main(){

    int T, n;
    bool prime[10001];
    fill_n(prime, 10001, true);
    for(int i = 2; i <= sqrt(10000); i++){
        if(!prime)
            continue;
        for(int j = i*i; j <= 10000; j += i)
            prime[j] = false;
    }
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%d", &n);
        for(int j = n/2; j >=2; j--){
            if(prime[j]){
                if(prime[n-j]){
                    printf("%d %d\n", j, n-j);
                    break;
                }
            }
        }
    }
    return 0;
}