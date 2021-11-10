#include <bits/stdc++.h>

using namespace std;
using ll = long long;

bool check[100003];
vector<ll> primes;
ll Times[100003];
ll s, f, m, times, tmp, cnt;

void findPrime(){
    memset(check, true, sizeof(check));
    check[1] = false;
    for(ll i = 2; i*i <= m*m; i++){
        //printf("findprime %d \n", i);
        if(!check[i])
            continue;
        primes.push_back(i);
        for(ll j = 2*i; j <= m; j += i)
            check[j] = false;
    }
    return;
}

ll getTimes(ll a, ll b, ll x){
    ll n = a + b;
    ll total = 0;
    while(n){
        total += n/x;
        total -= a/x;
        total -= b/x;
        n /= x;
        a /= x;
        b /= x;
        if((total >= 20) && ((a == 0) && (b == 0)))
            break;
    }
    return total;
}

int main(){

    bool flag = true;
    
    scanf("%lld %lld %lld", &s, &f, &m);

    findPrime();

    for(ll i = 0; i < primes.size(); i++)
        Times[i] = getTimes(s, f, primes[i]);
    
    for(ll k = m; k >= 1; k--){
        tmp = k;
        //printf("%lld\n", tmp);
        for(ll i = 0; i < primes.size(); i++){
            cnt = 0;
            if(tmp % primes[i] == 0){
                while(1){
                    tmp /= primes[i];
                    cnt++;
                    if(tmp % primes[i] != 0)
                        break;
                }
            }

            if(cnt > Times[i]){
                flag = false;
                break;
            }
        }
        if(flag && (tmp == 1)){
            printf("%lld", k);
            break;
        }
        flag = true;
    }

    return 0;
}