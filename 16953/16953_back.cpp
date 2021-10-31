#include <bits/stdc++.h>

using namespace std;

int a, b, cost;

int main(){
    cin >> a >> b;
    while(1){
        if(a > b){
            cout << -1;
            break;
        }
        if(a == b){
            cost++;
            cout << cost;
            break;
        }
        if(b % 10 == 1){
            b--;
            b /= 10;
        }else if(b % 2 == 0){
            b /= 2;
        }else{
            cout << -1;
            break;
        }
        cost++;
    }

    return 0;
}