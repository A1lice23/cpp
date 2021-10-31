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
                cout << sudoku[i][j];
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

/*
int sudoku[10][10];
bool row[10][10], col[10][10], sub_sq[10][10];

bool flag = false;

void find(int id){
    if(id == 81){
        for(int i = 1; i <= 9; i++){
            for(int j = 1; j <= 9; j++){
                cout << sudoku[i][j] << " ";
            }
            cout << "\n";
        }
        flag = true;
        return;
    }
    int x = (id / 9) + 1;
    int y = (id % 9) + 1;
    for(int i = 1; i <= 9; i++){
        if(!row[x][i] && !col[y][i] && !sub_sq[((x-1)/3)*3 + (y-1)/3 + 1][i]){
            row[x][i] = true;
            col[y][i] = true;
            sub_sq[((x-1)/3)*3 + (y-1)/3 + 1][i] = true;
            find(id+1);
            if(flag){
                return;
            }
            row[x][i] = false;
            col[y][i] = false;
            sub_sq[((x-1)/3)*3 + (y-1)/3 + 1][i] = false;
        }
    }
}
*/

int main(){
    
    for(int i = 1; i <= 9; i++){
        char tmp[10];
        cin >> tmp;
        for(int j = 1; j <= 9; j++){
            sudoku[i][j] = tmp[j-1] - '0';
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