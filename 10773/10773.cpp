#include <bits/stdc++.h>

using namespace std;

stack<int> s;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int k, x;
    cin >> k;
    for(int i = 0; i < k; i++){
        cin >> x;
        if(x == 0)
            s.pop();
        else
            s.push(x);
    }
    int sum = 0;
    while(!s.empty()){
        sum += s.top();
        s.pop();
    }
    cout << sum;
    return 0;
}