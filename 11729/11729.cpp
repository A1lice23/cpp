#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll cnt = 0;

ll hanoi_cnt(int n){
    if(n <= 1)
        return 1;
    else
        return 2 * hanoi_cnt(n-1) + 1;
}

void hanoi(int n, int start, int blank, int end){
    if(n <= 1){
        cout << start << " " << end << "\n";
    }else{
        hanoi(n-1, start, end, blank);
        cout << start << " " << end << "\n";
        hanoi(n-1, blank, start, end);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int k;
    cin >> k;

    cout << hanoi_cnt(k) << "\n";
    hanoi(k, 1, 2, 3);


    return 0;
}