#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, cnt = 0;;
    bool prime[246913];
    fill_n(prime, 246913, true);
    
    scanf("%d", &n);

    while(n!=0){
        for(int i = 2; i <= sqrt(2*n); i++){
            if(!prime[i])
                continue;
            
            for(int j = i * i; j <= 2*n; j += i)
                prime[j] = false;
        }
        for(int i = n+1; i <= 2*n; i++){
        if(prime[i])
            cnt++;
        }
        printf("%d\n", cnt);
        fill_n(prime, 2*n+1, true);
        cnt = 0;
        scanf("%d", &n);
    }
    return 0;
}