//3중 for문 사용
//다른 방식에 Kruth's optimization을 사용하는 방식이 있다고 함
//다른 방식도 꼭 해보기
//https://js1jj2sk3.tistory.com/3

#include <bits/stdc++.h>

using namespace std;

int cost[501][501];
int sum[501];

int main(){
    int t, k, input;
    cin >> t;
    for(int x = 0; x < t; x++){
        cin >> k;
        for(int y = 1; y <= k; y++){
            cin >> input;
            sum[y] = sum[y-1] + input;
        }
        for(int i = 1; i < k; i++){
            for(int tx = 1; tx + i <= k; tx++){
                int ty = tx + i;
                cost[tx][ty] = INT_MAX;
                for(int div = tx; div < ty; div++){
                    cost[tx][ty] = min(cost[tx][ty], cost[tx][div] + cost[div+1][ty] + sum[ty] - sum[tx-1]);
                }
            }
        }

        cout << cost[1][k] << "\n";
    }
    return 0;
}