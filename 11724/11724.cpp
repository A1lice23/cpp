#include <bits/stdc++.h>

using namespace std;

bool visited[1001] = {false, };

void bfs(vector<int> *v, int s){
    queue<int> q;
    visited[s] = true;
    q.push(s);

    while(!q.empty()){
        int vec = q.front();
        q.pop();

        for(int i = 0; i < v[vec].size(); i++){
            if(!visited[v[vec][i]]){
                q.push(v[vec][i]);
                visited[v[vec][i]] = true;
            }
        }
    }
}

int main(){
    int n, m, x, y, cnt = 0;

    scanf("%d %d", &n, &m);
    vector<int> graph[n+1];

    for(int i = 0; i < m; i++){
        scanf("%d %d", &x, &y);
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(int i = 0; i < n; i++){
        if(!visited[i+1]){
            cnt++;
            bfs(graph, i+1);
        }
    }
    printf("%d", cnt);

    return 0;
}