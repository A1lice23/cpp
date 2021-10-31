#include <bits/stdc++.h>

using namespace std; 

int n, k, ans, max_num = 0;
int line[10001];
long long pivot, h, l;

int main(){
    cin >> k >> n;
    for(int i = 0; i < k; i++){
        cin >> line[i];
        if(max_num < line[i])
            max_num = line[i];
    }
    l = 1;
    h = max_num;
    
    while(l <= h){
        pivot = (l + h) / 2;
        int cnt = 0;
        for(int i = 0; i < k; i++)
            cnt += line[i]/pivot;
        if(cnt >= n){
            l = pivot+1;
            if(ans < pivot)
                ans = pivot;
        }else{
            h = pivot - 1;
        }
    }
    cout << ans;

    return 0;
}