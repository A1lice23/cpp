#include <bits/stdc++.h>

using namespace std;

int numbers[500001];
int check[8002];
int max_num[8002];

int main(){
    int n, x, many_num, max = -5000, min = 5000, max_cnt = 0, equal_cnt = 1;
    double sum = 0;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        if(max < x)
            max = x;
        if(min > x)
            min = x;
        numbers[i] = x;
        sum += x;
        check[x + 4000]++;
    }
    for(int i = 0; i < 8001; i++){
        if(max_cnt < check[i]){
            equal_cnt = 1;
            max_cnt = check[i];
        }else if(max_cnt == check[i])
            equal_cnt = 2;
    }
    for(int i = 0; i < 8001; i++){
        if(max_cnt == check[i]){
            if(equal_cnt == 1){
                many_num = i - 4000;
                break;
            }else{
                equal_cnt--;
            }
        }
    }
    sort(numbers, numbers+n);
    printf("%.0f\n%d\n%d\n%d", sum/n, numbers[n/2], many_num, max-min);


    return 0;
}