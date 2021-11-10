#include <bits/stdc++.h>

using namespace std;
stack<int> s;
char a[500001];
int bign[1000001];

int main(){
    int n, k, cnt = 1, size;
    scanf("%d %d", &n, &k);
    scanf("%s", a);
    
    for(int i = 0; i < n; i++){
        while(k && !s.empty() && s.top() < a[i]){
            s.pop();
            k--;
        }
        s.push(a[i]);
    }
    cnt = s.size();
    size = cnt;
    while(!s.empty()){
        bign[cnt-1] = s.top();
        s.pop();
        cnt--;
    }
    for(int i = 0; i < size-k; i++)
        printf("%c", bign[i]);

    return 0;
}