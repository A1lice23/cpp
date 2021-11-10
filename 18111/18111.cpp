#include <bits/stdc++.h>

using namespace std;

int ground[501][501];

int main(){

    int n, m, b, max = -1, min = 257;
    cin >> n >> m >> b;


    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++){
            cin >> ground[i][j];
            if(max < ground[i][j])
                max = ground[i][j];
            if(min > ground[i][j])
                min = ground[i][j];
        }
    int ans = 1000000000, bsum, tsum = 0, x, h;
    for(int k = min; k <= max; k++){
        bsum = b;
        tsum = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                x = ground[i][j];
                if(x-k < 0){
                    bsum -= (k-x);
                    tsum += (k-x);
                }else{
                    bsum += (x-k);
                    tsum += 2*(x-k);
                }
            }
        }
        if(bsum >= 0 && tsum <= ans){
            ans = tsum;
            h = k;
        }
    }
    cout << ans << " " << h;

    return 0;
}