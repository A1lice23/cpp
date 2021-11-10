#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll dnum[1000001];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i <= 9; i++)
        dnum[i] = i;
    int cnt = 10;
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < (dnum[i]%10); j++)
            dnum[cnt++] = dnum[i]*10 + j;

    if(n > 1022)
        printf("-1");
    else
        printf("%lld", dnum[n]);

    return 0;
}