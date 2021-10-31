#include <bits/stdc++.h>
using namespace std;

deque <int> dq;

int main(){
    int n,in;
    char c[15];

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", c);
        if(!strcmp(c,"push_front")){
            scanf("%d", &in);
            dq.push_front(in);
        }else if(!strcmp(c, "push_back")){
            scanf("%d", &in);
            dq.push_back(in);
        }
        else if(!strcmp(c, "pop_front")){
            if(!dq.empty()){
            printf("%d\n", dq.front());
            dq.pop_front();
            }
            else{
                printf("-1\n");
            }
        }else if(!strcmp(c, "pop_back")){
            if(!dq.empty()){
            printf("%d\n", dq.back());
            dq.pop_back();
            }
            else{
                printf("-1\n");
            }
        }else if(!strcmp(c, "size")){
            printf("%d\n", dq.size());
        }else if(!strcmp(c, "empty")){
            printf("%d\n",dq.empty());
        }else if(!strcmp(c, "back")){
            if(!dq.empty()){
            printf("%d\n", dq.back());
            }
            else{
                printf("-1\n");
            }
        }else if(!strcmp(c, "front")){
            if(!dq.empty()){
            printf("%d\n", dq.front());
            }
            else{
                printf("-1\n");
            }
        }
    }
    return 0;
}