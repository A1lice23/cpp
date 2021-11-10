#include <bits/stdc++.h>

using namespace std;

int n, m;
int dict[10];
int print[10];
bool check[10];

void printComb(int cnt){
    if(cnt == m){
        for(int i = 0; i < m; i++)
            cout << print[i] << " ";
        cout << "\n";
        return;
    }

    for(int i = 0; i < n; i++){
        if(check[i])
            continue;
        check[i] = true;
        print[cnt] = dict[i];
        printComb(cnt + 1);
        check[i] = false;
        
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    
    for(int i = 0; i < n; i++)
        cin >> dict[i];
    
    sort(dict, dict+n);
    printComb(0);

    return 0;
}