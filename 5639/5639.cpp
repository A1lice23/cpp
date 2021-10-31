#include <bits/stdc++.h>

using namespace std;

int pre[10001];

void postOrder(int l, int r){
    if(l > r) return;

    int rt = pre[l];
    int last = r;
    while(pre[last] > rt){
        last--;
    }
    postOrder(l + 1, last);
    postOrder(last + 1, r);
    cout << rt << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int data, size = 0;
    while(cin >> data){
        if(data == EOF) break;
        pre[size++] = data;
    }
    postOrder(0, size-1);

    return 0;
}
