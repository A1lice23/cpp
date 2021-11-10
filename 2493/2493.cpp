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
    
    for(int i = 0; i < n; i++){
        while(!s.empty() && a[s.top()] <= a[i])
            s.pop();
        if(s.empty())
            nge[i] = -1;
        else
            nge[i] = s.top();
        
        s.push(i);
    }
    for(int i = 0; i < n; i++)
        printf("%d ", nge[i]+1);

    return 0;
}