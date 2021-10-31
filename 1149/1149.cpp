#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, r, g, b;

    scanf("%d", &n);
    scanf("%d %d %d", &r, &g, &b);

    int cost[n+1][3] = {0, };
    cost[0][0] = r;
    cost[0][1] = g;
    cost[0][2] = b;

    for(int i = 1; i < n; i++){
        scanf("%d %d %d", &r, &g, &b);
        cost[i][0] = min(cost[i-1][1], cost[i-1][2]) + r;
        cost[i][1] = min(cost[i-1][0], cost[i-1][2]) + g;
        cost[i][2] = min(cost[i-1][0], cost[i-1][1]) + b;
    }

    printf("%d", min(min(cost[n-1][0], cost[n-1][1]), cost[n-1][2]));

    return 0;
}