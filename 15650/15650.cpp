#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[9];
bool visited[9];

void dfs(int pivot, int cnt){
    if(cnt == m){
        for(int i = 0; i <m; i++)
            cout << arr[i] << ' ';
        cout << "\n";
        return;
    }
    for(int i = pivot; i <= n; i++){
       arr[cnt] = i;
       dfs(i+1, cnt+1);
    }
}

int main(){
    cin >> n >> m;
    dfs(1, 0);
    return 0;
}