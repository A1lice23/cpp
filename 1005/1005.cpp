#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T;
    cin >> T;
    while(T--){
        int N, K, target, x, y;
        int time[1001] ={0};
        int con[1001] = {0};
        int ans[1001] = {0};
        vector<int> check[1001];
        queue<int> q;
        cin >> N >> K;
        for(int i = 1; i <= N; i++)
            cin >> time[i];
        for(int i = 0; i < K; i++){
            cin >> x >> y;
            check[x].push_back(y);
            con[y]++;
        }
        for(int i = 1; i <= N; i++){
            if(con[i] == 0)
                q.push(i);
        }
        cin >> target;
        
        int node;
        while(con[target] > 0){
            node = q.front();
            q.pop();
            for(int i : check[node]){
                ans[i] = max(ans[i], ans[node] + time[node]);
                if(--con[i] == 0)
                    q.push(i);
            }
        }
        cout << ans[target] + time[target] << "\n";
    }
    return 0;
}