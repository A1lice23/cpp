#include <bits/stdc++.h>

using namespace std;

char starmap[2500][2500] = {};

void drawstar(int x, int y, int n){
    if(n == 0){
        starmap[x][y] = '*';
    }
    else{
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(i == 1 && j == 1)
                    continue;
            
                drawstar(x+i*(n/3), y+j*(n/3), n/3);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int k;
    cin >> k;

    drawstar(0, 0, k);

    for(int i = 0; i < k; i++){
        for(int j = 0; j < k; j++){
            if(starmap[i][j] == '*')
                cout << '*';
            else
                cout << ' ';
        }
        cout << "\n";
    }

    return 0;
}