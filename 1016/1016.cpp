#include <bits/stdc++.h>

using namespace std;
bool check[1000001];

int main(){

    long long min, max, min2, cnt = 0;
    cin >> min >> max;

    for(long long i = 2; i <= sqrt(max); i++){
        if(min % (i*i) != 0)
            min2 = min/(i*i) + 1;
        else
            min2 = min/(i*i);
        for(long long j = min2; j <= max/(i*i); j++){
            if(!check[i*i*j-min]){
                check[i*i*j - min] = true;
                cnt++;
            }
        }
    }
    cout << max - min - cnt + 1;
    return 0;
}