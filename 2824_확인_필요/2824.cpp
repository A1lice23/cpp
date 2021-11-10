#include <bits/stdc++.h>
#define MAX 40000

using namespace std;
using ll = long long;

bool check[40000];
vector<int> primes;
map<int, int> A, B;

void findPrime(){
    for(int i = 2; i < 40000; i++){
        if(check[i]) continue;
        primes.push_back(i);
        for(int j = 2*i; j < 40000; j += i)
            check[j] = true;
    }
}

int main(){
    int n, x, tmp;
    scanf("%d", &n);

    findPrime();

    for(int k = 0; k < n; k++){
        scanf("%d", &x);
        tmp = x;
        for(int i = 0; i < primes.size(); i++){
            while(tmp%primes[i] == 0){
                A[primes[i]]++;
                tmp /= primes[i];
            }
        }
        if(tmp != 1)
            A[tmp]++;
    }
    scanf("%d", &n);
    for(int k = 0; k < n; k++){
        scanf("%d", &x);
        tmp = x;
        for(int i = 0; i < primes.size(); i++){
            while(tmp%primes[i] == 0){
                B[primes[i]]++;
                tmp /= primes[i];
            }
        }
        if(tmp != 1)
            B[tmp]++;
    }
    ll total = 1LL;
    bool flag = false;
    for(auto iter: A){
        if(!B[iter.first])
            continue;
        int cnt = min(iter.second, B[iter.first]);
        while(cnt--){
            total *= iter.first;
            if(total >= 1000000000){
                flag = true;
                total %= 1000000000;
            }
        }
    }
    if(flag){
        printf("%09lld", total);
    }else{
        printf("%lld", total);
    }

    return 0;
}
