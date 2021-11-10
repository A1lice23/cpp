#include <bits/stdc++.h>

using namespace std;

priority_queue<int> maxpq;
priority_queue<int, vector<int>, greater<int>> minpq;

int main(){
    int n, x;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &x);

        if(maxpq.size() == 0)
            maxpq.push(x);
        else{
            if(maxpq.size() > minpq.size())
                minpq.push(x);
            else
                maxpq.push(x);
            if(maxpq.top() > minpq.top()){
                int maxt = maxpq.top();
                int mint = minpq.top();
                maxpq.pop();
                minpq.pop();
                maxpq.push(mint);
                minpq.push(maxt);
            }
        }
        printf("%d\n", maxpq.top());
    }
    
    
    return 0;
}