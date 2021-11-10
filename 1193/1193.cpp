#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, cnt = 1;
    cin >> n;
    for(int i = 1; i <= n; i++){
        if(n <= i*(i+1)/2){
            cnt = i;
            break;
        }
    }
    int mod = n - cnt * (cnt-1) / 2;
    cnt++;
    if(cnt % 2 == 0)
        cout << cnt - mod << "/" << mod << "\n";
    else
        cout << mod << "/" << cnt - mod << "\n";

    return 0;
}