#include <bits/stdc++.h>

using namespace std;

int root[100001];

int find_rt(int x){
    if(x == root[x])
        return x;
    return root[x] = find_rt(root[x]);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int g, p, gi, docker, cnt = 0;
    cin >> g >> p;
    for(int i = 1; i <= g; i++)
        root[i] = i;
    for(int i = 0; i < p; i++){
        cin >> gi;
        docker = find_rt(gi);
        if(docker != 0){
            root[find_rt(docker)] = find_rt(docker-1);
            cnt++;
        }else{
            break;
        }    
        /*
        for(int j = 1; j <= g; j++)
            cout << root[j] << " ";
        cout << "\n";
        */
    }
    cout << cnt;
    return 0;
}