#include <bits/stdc++.h>

using namespace std;

bool isVisted[100001] = {false};

pair<int,int> dfs(vector<pair<int, int>> *t, int start){
    fill_n(isVisted, 100001, false);
    stack<int> s;
    stack<int> add;
    s.push(start);
    add.push(0);
    isVisted[start] = true;
    int cur_len = 0;
    int max_len = 0;
    int max_node;

    while(!s.empty()){
        bool check = false;
        int cur = s.top();

        //cout << cur << "\n";

        for(auto it = t[cur].begin(); it != t[cur].end(); it++){
            if(!isVisted[(*it).first]){
                check = true;
                cur_len += (*it).second;
                add.push((*it).second);
                if(max_len < cur_len){
                    max_len = cur_len;
                    max_node = (*it).first;
                }
                s.push((*it).first);
                isVisted[(*it).first] = true;
                break;
            }
        }
        if(!check){
            s.pop();
            //cout << s.size() << "\n";
            cur_len -= add.top();
            add.pop();
        }
    }

    //cout << "done" << "\n";

    return make_pair(max_node, max_len);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int v, x, y, node;
    cin >> v;

    vector<pair<int, int>> tree[v+1];
    for(int i = 1; i <= v; i++){
        cin >> node;
        while(true){
            cin >> x;
            if(x == -1)
                break;
            cin >> y;
            tree[node].push_back(make_pair(x, y));
        }
    }

    pair<int, int> f_node, s_node;

    f_node = dfs(tree, 2);

    s_node = dfs(tree, f_node.first);

    cout << s_node.second;

    return 0;
}