# 스택을 이용하엿 더 깔끔하게 변경 할 수 있을 듯
# 일단 for문 넣는대로 다 스택에 넣고
# top을 확인 했을 때 a면 뒤랑 스택의 크기 확인을 통해서
# PPAP인지 NP인지 확인 하는 식으로 바꾸면 더 깔끔할듯

#include <bits/stdc++.h>

using namespace std;

stack<char> ppap;

int main(){
    string s;
    cin >> s;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'P'){
            ppap.push(s[i]);
            continue;
        }
        if(ppap.size() >= 2 && s[i+1] == 'P'){
            ppap.pop();
            i++;
        }else{
            printf("NP");
            return 0;
        }
    }
    if(ppap.size() == 1)
        printf("PPAP");
    else
        printf("NP");

    return 0;
}