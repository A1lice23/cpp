#include <bits/stdc++.h>

using namespace std;

long long int n, m, tree[1000001];
long long int l = 0, r = 1000000000;
long long int pivot, ans;

bool check(long long int height){
    long long int total = 0;
    for(int i = 0; i < n; i++){
        if(tree[i] >= height)
            total += (tree[i] - height);
        if(total >= m)
            return true;
    }
    return false;
}
int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> tree[i];

    sort(tree, tree+n);

    while(l <= r){
        pivot = (l + r) / 2;
        if(check(pivot)){
            ans = pivot;
            l = pivot + 1;
        }else{
            r = pivot - 1;
        }
    }   

    cout << ans << "\n";

    return 0;
}