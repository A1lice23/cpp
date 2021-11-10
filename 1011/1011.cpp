#include <bits/stdc++.h>

using namespace std;

void printNum(int length){
    int length_left = length;
    int max_go = 2;
    int cnt = 1;
    while(length_left >= max_go){
        length_left -= max_go;
        max_go = 2*(++cnt);
    }
    if(length_left == 0){
        cout << 2*(cnt-1) << "\n";
    }else if(length_left <= cnt){
        cout << 2*(cnt-1)+1 << "\n";
    }else{
        cout << 2*(cnt-1)+2 << "\n";
    }
    
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, x, y;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> x >> y;
        printNum(y-x);
    }

    return 0;
}