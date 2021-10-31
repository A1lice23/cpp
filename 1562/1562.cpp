// 비트마스크의 사용

#include <bits/stdc++.h>

using namespace std;

const int mod = 1000000000;
int sn[10][101][1 << 10];

int main(){
    int n;

    cin >> n;

    for(int i = 1; i <= 9; i++){
        sn[i][1][1 << i] = 1;
    }

    for(int i = 2; i <= n; i++){
        for(int j = 0; j <= 9; j++){
            for(int k = 0; k <= (1 << 10) - 1; k++){
                if(j == 0){
                    sn[0][i][k | (1 << 0)] += sn[1][i-1][k];
                    sn[0][i][k | (1 << 0)] %= mod;
                }else if(j == 9){
                    sn[9][i][k | (1 << 9)] += sn[8][i-1][k];
                    sn[9][i][k | (1 << 9)] %= mod;
                }else{
                    sn[j][i][k | (1 << j)] += sn[j-1][i-1][k];
                    sn[j][i][k | (1 << j)] += sn[j+1][i-1][k];
                    sn[j][i][k | (1 << j)] %= mod;
                }
            }
        }
    }
    
    int res = 0;

    for(int i = 0; i <= 9; i++){
        res += sn[i][n][(1 << 10) - 1];
        res %= mod;
    }

    cout << res;

    return 0;
}

