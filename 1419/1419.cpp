#include <bits/stdc++.h>

using namespace std;

int main(){
    int l, r, k, cnt = 0;
    scanf("%d %d %d", &l, &r, &k);
    switch (k) {

    case 2:
        printf("%d", max(r - max(3,l) + 1, 0));
        break;
    case 3:
        for(int i = max(l, 6); i <= r; i++){
            if(i%3 == 0)
                cnt++;
        }
        printf("%d", cnt);
        break;
    case 4:
        for(int i = max(l, 10); i <= r; i++){
            if((i%2 == 0) && i != 12)
                cnt++;
        }
        printf("%d", cnt);
        break;
    case 5:
        for(int i = max(l, 15); i <= r; i++){
            if(i%5 == 0)
                cnt++;
        }
        printf("%d", cnt);
        break;
    }

    return 0;
}