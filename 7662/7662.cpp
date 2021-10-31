#include <bits/stdc++.h>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T, t, num;
    char com;
    //scanf("%d", &T);
    cin >> T;
    for(int i = 0; i < T; i++){
        //scanf("%d", &t);
        cin >> t;
        priority_queue<int, vector<int>> great;
        priority_queue<int, vector<int>, greater<int>> less;
        map<int, int> index;
        for(int j = 0; j < t; j++){
            //scanf("%s %d", &com, &num);
            cin >> com >> num;
            if(com == 'D'){
                if(!index.empty()){
                    if(num==1){
                    while(!great.empty() && index[great.top()] == 0) great.pop();
                    if(!great.empty()){
                        index[great.top()]--;
                        great.pop();
                    }
                    }else{
                        while(!less.empty() && index[less.top()] == 0) less.pop();
                        if(!less.empty()){
                            index[less.top()]--;
                            less.pop();
                        }
                    }
                }
            }else{
                less.push(num);
                great.push(num);
                index[num]++;
            }
            
        }
        while(!great.empty() && index[great.top()] == 0) {great.pop();}
        while(!less.empty() && index[less.top()] == 0) {less.pop();}
        if(great.empty() || less.empty()){ /*printf("EMPTY\n");*/ cout << "EMPTY\n"; }
        else{ /*printf("%d %d\n", great.top(), less.top());*/ cout << great.top() << " " << less.top() << "\n";}
    }
    return 0;
}

//multiset 이용 방식 - 시간초과인지 메모리탓인지는 모르겠으나 실패

/*
int main(){
    multiset <long long> ms;

    int T, t;
    long long num;
    char com;
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%d", &t);
        for(int j = 0; j < t; j++){
            scanf("%s %lld", &com, &num);
            //printf("task %d\n", j);
            if(com == 'I'){
                ms.insert(num);
            }else if((num == 1) && !ms.empty()){
                //printf("%d\n", *(--ms.end()));
                ms.erase(--ms.end());
            }else if((num == -1) && !ms.empty()){
                //printf("%d\n", *(ms.begin()));
                ms.erase(ms.begin());
            }
        }
        if(ms.empty()){
            printf("EMPTY\n");
        }else{
            printf("%lld %lld\n", *(--ms.end()), *ms.begin());
        }
        ms.clear();
    }
    return 0;
}
*/