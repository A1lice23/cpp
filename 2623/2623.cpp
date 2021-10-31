#include <bits/stdc++.h>

using namespace std;

vector<int> graph[1001];
int edgeCnt[1001] = {0};
int printList[1001];
bool flag = true;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m, x;
    cin >> n >> m;
    while(m--){
        cin >> x;
        int pre = 0, cur = 0;
        for(int i = 0; i < x; i++){
            cin >> cur;
            if(pre != 0){
                graph[pre].push_back(cur);
                edgeCnt[cur]++;
            }
            pre = cur;
        }
    }

    queue<int> q;

    for(int i = 1; i <= n; i++){
        if(edgeCnt[i] == 0)
            q.push(i);
    }
    for(int i = 0; i < n; i++){
        if(q.empty()){
            cout << 0;
            flag = false;
            break;
        }
        int node = q.front();
        q.pop();
        printList[i] = node;

        for(int target : graph[node]){
            edgeCnt[target]--;
            if(edgeCnt[target] == 0)
                q.push(target);
        }
    }
    if(flag){
        for(int i = 0; i < n; i++)
            cout << printList[i] << "\n";
    }
    return 0;
}