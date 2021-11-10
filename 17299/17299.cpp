#include <bits/stdc++.h>

using namespace std;
stack<int> s;
int a[1000001];
int cnt[1000001];
int ngf[1000001];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", a+i);
        cnt[a[i]]++;
    }
    
    for(int i = n-1; i >= 0; i--){
        while(!s.empty() && cnt[s.top()] <= cnt[a[i]])
            s.pop();
        if(s.empty())
            ngf[i] = -1;
        else
            ngf[i] = s.top();
        
        s.push(a[i]);
    }
    for(int i = 0; i < n; i++)
        printf("%d ", ngf[i]);

    return 0;
}