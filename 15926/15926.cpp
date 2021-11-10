#include <bits/stdc++.h>

using namespace std;
stack<int> s;

int main(){
    int n, curlen = 0, maxlen = 0;
    string gwalho;
    scanf("%d", &n);
    cin >> gwalho;
    s.push(-1);

    for(int i = 0; i < gwalho.length(); i++){
        if(gwalho[i] == '('){
            s.push(i);
        }else if(gwalho[i] == ')'){
            s.pop();
            if(!s.empty()) maxlen = max(maxlen, i - s.top());
            else s.push(i);
        }
    }
    printf("%d", maxlen);

    return 0;
}