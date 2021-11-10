#include <bits/stdc++.h>

using namespace std;
stack<int> s;
int a[1000001];
int nge[1000001];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", a+i);
    
    for(int i = n-1; i >= 0; i--){
        while(!s.empty() && s.top() <= a[i])
            s.pop();
        if(s.empty())
            nge[i] = -1;
        else
            nge[i] = s.top();
        
        s.push(a[i]);
    }
    for(int i = 0; i < n; i++)
        printf("%d ", nge[i]);

    return 0;
}