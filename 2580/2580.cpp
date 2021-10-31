#include <bits/stdc++.h>

using namespace std;

int sudoku[10][10];
pair<int, int> zero[81];
int row[10], col[10], square[10];

int idx = 0;
bool flag = false;

void find(int id){
    if(id >= idx){
        for(int i = 1; i <= 9; i++){
            for(int j = 1; j <= 9; j++){
                cout << sudoku[i][j] << " ";
            }
        cout << "\n";
        }
        flag = true;
        return;
    }
    int x = zero[id].first;
    int y = zero[id].second;
    for(int i = 1; i <= 9; i++){
        if((row[x] & (1 << i)) == 0 && (col[y] & (1 << i)) == 0 && (square[((x-1)/3)*3+((y-1)/3)+1] & (1 << i)) == 0){
            row[x] |= (1 << i);
            col[y] |= (1 << i);
            square[((x-1)/3)*3+((y-1)/3)+1] |= (1 << i);
            sudoku[x][y] = i;
            find(id + 1);
            if(flag)
                return;
            row[x] &= ~(1 << i);
            col[y] &= ~(1 << i);
            square[((x-1)/3)*3+((y-1)/3)+1] &= ~(1 << i);
        }
    }
}

int main(){
    
    for(int i = 1; i <= 9; i++){
        for(int j = 1; j <= 9; j++){
            cin >> sudoku[i][j];
            if(sudoku[i][j] == 0)
                zero[idx++] = {i, j};
            else{
                row[i] |= (1 << sudoku[i][j]);
                col[j] |= (1 << sudoku[i][j]);
                square[((i-1)/3)*3+((j-1)/3)+1] |= (1 << sudoku[i][j]);
            }
        }
    }
    find(0);

    return 0;
}