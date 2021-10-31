#include <bits/stdc++.h>

using namespace std;

int inorder[100001], postorder[100001], node[100001];

void solve(int inStart, int inEnd, int postStart, int postEnd){
    if (inStart > inEnd || postStart > postEnd)
        return;
    int root = postorder[postEnd];
    cout << root << " ";
    solve(inStart, node[root] - 1, postStart, postStart + (node[root] - inStart) - 1);
    solve(node[root] + 1, inEnd, postStart + (node[root] - inStart), postEnd - 1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> inorder[i];
        node[inorder[i]] = i;
    }
    for(int i = 0; i < n; i++)
        cin >> postorder[i];


    solve(0, n-1, 0, n-1);

    return 0;
}