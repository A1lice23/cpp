#include <bits/stdc++.h>

using namespace std;

int main(){

    vector<int> v, l;
    int n, x;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        v.push_back(x);
        l.push_back(x);
    }
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());

    for(auto it = l.begin(); it != l.end(); it++){
        printf("%d ", lower_bound(v.begin(), v.end(), *it) - v.begin());
    }

    return 0;
}