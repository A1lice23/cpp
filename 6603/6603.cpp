#include <bits/stdc++.h>

using namespace std;

int k;
int dict[14];

void printLotto(int cnt, int low, int bitmap){
    if(low == k && cnt < 6)
        return;
    if(cnt == 6){
        for(int i = 0; i < k; i++){
            if((bitmap & (1 << i)) != 0)
                cout << dict[i] << " ";
        }
        cout << "\n";
    }else{
        for(int i = low; i < k; i++){
            printLotto(cnt+1, i+1, bitmap | (1 << i));
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> k;
    while(k != 0){
        for(int i = 0; i < k; i++)
            cin >> dict[i];
        printLotto(0, 0, 0);
        cout << "\n";
        cin >> k;
    }

    return 0;
}