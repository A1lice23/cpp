#include <bits/stdc++.h>

using namespace std;

int main(){

    int n, solution[100001] = {0, };
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> solution[i];
    }
    int start = 0, end = n-1, min_num, max_num;
    int ans = 2000000000;
    while(start < end){
        if(abs(solution[start] + solution[end]) < ans){
            min_num = solution[start];
            max_num = solution[end];
            ans = abs(solution[start] + solution[end]);
        }
        if(solution[start] + solution[end] > 0){
            end--;
        }else if(solution[start] + solution[end] <0){
            start++;
        }else{
            break;
        }
    }

    cout << min_num << " " << max_num << "\n";

    return 0;
}