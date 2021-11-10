#include <bits/stdc++.h>

using namespace std;

vector<int> leaf[51];
bool visited[51];
queue<int> erase;

int main(){

    int n, x, k, cnt = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        if(x != -1)
            leaf[x].push_back(i);
    }
    scanf("%d", &k);
    erase.push(k);

    while(!erase.empty()){
        int node = erase.front();
        erase.pop();
        visited[node] = true;
        for(int i = 0; i < leaf[node].size(); i++){
            if(!visited[leaf[node][i]])
                erase.push(leaf[node][i]);
        }
    }

    for(int i = 0; i < n; i++){
        if(!visited[i]){
            int j = -1;
            for(j = 0; j < leaf[i].size(); j++){
                if(!visited[leaf[i][j]])
                    break;
            }
            if(j == leaf[i].size())
                cnt++;
        }
    }
    printf("%d", cnt);

    return 0;
}