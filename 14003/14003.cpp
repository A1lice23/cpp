#include <bits/stdc++.h>

using namespace std;

int seq[1000001], L[1000001], idx[1000001];
void lis(int id, int num){
    if(id == 0)
        return;
    if(idx[id] == num){
        lis(id-1, num-1);
        cout << seq[id] << " ";
    }else{
        lis(id-1, num);
    }
}

int main(){
    int len = 0, n;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> seq[i];
        auto piv = lower_bound(L+1, L+len+1, seq[i]);
        *piv = seq[i];
        idx[i] = distance(L, piv);
        if(piv == L + len + 1)
            len++;
    }
    cout << len << "\n";
    lis(n, len);

    return 0;
}