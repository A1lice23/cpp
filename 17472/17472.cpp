#include <bits/stdc++.h>

using namespace std;

struct link{
    int start, end, cost;
};

int n, m;
int seamap[11][11];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int parent[7];
int islandNum = 0;

vector<link> edge;

bool compare(link a, link b){
    return a.cost < b.cost;
}

int find(int x){
    if(x == parent[x])
        return x;
    return parent[x] = find(parent[x]);
}

bool unionfind(int x, int y){
    x = find(x);
    y = find(y);
    
    if(x == y)
        return true;
    else{
        parent[x] = y;
        return false;
    }
}

void numberingIsland(int x, int y){
    seamap[x][y] = islandNum;
    int numx = x;
    int numy = y;
    
    for(int i = 0; i < 4; i++){
        numx = x + dx[i];
        numy = y + dy[i];
        if(numx >= 1 && numx <= n){
            if(numy >= 1 && numy <= m){
                if(seamap[numx][numy] == 9){
                    seamap[numx][numy] = islandNum;
                    numberingIsland(numx, numy);
                }
            }
        }

    }
}

void getDistance(int x, int y){
    int start = seamap[x][y];
    for(int i = 0; i < 4; i++){
        int numx = x;
        int numy = y;
        int cost = 0;
        
        while(true){
            numx += dx[i];
            numy += dy[i];
            
            if(numx < 1 || numx > n || numy < 1 || numy > m || seamap[numx][numy] == start)
                break;

            if(seamap[numx][numy] != 0){
                link tmp;
                tmp.start = start;
                tmp.end = seamap[numx][numy];
                tmp.cost = cost;
                edge.push_back(tmp);
                break;
            }
            cost++;
        }
    }
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);

    cin >> n >> m;
    int x;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            cin >> x;
            if(x != 0){
                x = 9;
            seamap[i][j] = x;
        }
    }
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            if(seamap[i][j] == 9){
                islandNum++;
                numberingIsland(i, j);
            }
        }
    /*
    cout << "\n";
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cout << seamap[i][j] << " ";
        }
        cout << "\n";
    }
    */
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(seamap[i][j] != 0)
                getDistance(i, j);
        }
    }
    for(int i = 1; i <= islandNum; i++)
        parent[i] = i;

    for(int i = 0; i < edge.size(); i++){
        if(edge[i].cost < 2)
            continue;
        unionfind(edge[i].start, edge[i].end);
        //cout << edge[i].start << " " << edge[i].end << " " << edge[i].cost << "\n";
    }
    bool flag = true;
    int sum = 0;

    for(int i = 1; i < islandNum; i++){
        if(!unionfind(i, i+1)){
            flag = false;
            break;
        }
    }
    for(int i = 1; i <= islandNum; i++)
        parent[i] = i;
    if(!flag){
        cout << -1;
    }else{
        sort(edge.begin(), edge.end(), compare);
        for(int i = 0; i < edge.size(); i++){
            if(edge[i].cost < 2)
                continue;
            if(!unionfind(edge[i].start, edge[i].end))
                sum += edge[i].cost;
        }
        cout << sum;
    }
    
    return 0;
}