#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> stat;

int main(){

    int n, x, y, cnt;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x >> y;
        stat.push_back({x, y});
    }
    for(int i = 0; i < n; i++){
        cnt = 1;
        pair<int, int> check = stat[i];
        for(int j = 0; j < n; j++){
            if((check.first < stat[j].first) && (check.second < stat[j].second))
                cnt++;
        }
        cout << cnt << " ";
    }

    return 0;
}