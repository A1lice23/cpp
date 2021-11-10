#include <bits/stdc++.h>

using namespace std;

int Times[100001];

void mul(int q){
    for(int i = 2; i*i <= q; i++){
        while(q % i == 0){
            q /= i;
            Times[i]++;
        }
    }
    if(q != 1)
        Times[q]++;
}

void div(int q){
    for(int i = 2; i*i <= q; i++){
        while(q % i == 0){
            q /= i;
            Times[i]--;
        }
    }
    if(q != 1)
        Times[q]--;
}


int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);
    
    bool flag = false, isInt = false;
    int n, x;
    char c;

	cin >> n;
	for (int i = 0; i < n; i++) {
		if (!i) {
			cin >> x;
            x = abs(x);
			if (x == 0)
                flag = true;
            if(x)
                mul(x);
		}
		else {
			cin >> c >> x;
            x = abs(x);
			if (x == 0)
                flag = true;
			if(c == '/')
                div(x);
			else if(x)
                mul(x);
		}
	}
	if(flag)
        cout << "mint chocolate";
	else{
		for(int i = 2; i <= 100000; i++)
			if(Times[i] < 0)
                isInt = true;
		if(isInt)
            cout << "toothpaste";
		else
            cout << "mint chocolate";
	}

    return 0;
}