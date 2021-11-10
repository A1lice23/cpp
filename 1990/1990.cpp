
// 기본적으로는 에라토스테네스 체와 펠린드롬 확인을 통한 문제이나
// 소수를 구할 때 i를 1억으로 잡으면 시간 초과가 나고, python으로 
// 1억의 리스트를 잡으면 메모리 초과가 난다.
// 이를 해결하기 위해 천만부터 1억까지는 펠린드롬소수가 없다는 것을 이용해서
// 계산하는 범위를 줄여서 시간을 줄여 해결하는 문제였다.

#include <bits/stdc++.h>

using namespace std;

bool check[100000002];

void findPrime(){
    memset(check, true, sizeof(check));
    check[1] = false;
    for(int i = 2; i*i < 10000002; i++){
        if(!check[i]) continue;
        for(int j = 2*i; j < 10000002; j += i)
            check[j] = false;
    }
    for(int i = 10000000; i <= 100000000; i++)
        check[i] = false;
}
bool isPal(int n){
    string str;
    str = to_string(n);
    for(int i = 0; i < str.size()/2; i++){
        if(str[i] != str[str.size() - i - 1])
            return false;
    }
    return true;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;

    findPrime();

    for(int i = a; i <= b; i++){
        if(check[i])
            if(isPal(i))
                cout << i << "\n";
    }
    cout << -1;
    return 0;
}