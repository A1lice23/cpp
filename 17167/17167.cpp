#include <iostream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    unsigned long long a, b;
    int cnt = 0;
    vector<string> v;

    cin >> a >> b;

    while(!((a & 1) && (b & 1))){
        if(a & 1){
            b >>= 1; cnt++;
            v.push_back("A+=A");
        }
        else{
            a >>= 1; cnt++;
            v.push_back("B+=B");
        }
    }
    while(a != b){
        if(a > b){
            a += b; cnt++;
            v.push_back("A+=B");
        }
        else{
            b += a; cnt++;
            v.push_back("B+=A");
        }
        while(!((a & 1) && (b & 1))){
            if(a & 1){
                b >>= 1; cnt++;
                v.push_back("A+=A");
            }
            else{
                a >>= 1; cnt++;
                v.push_back("B+=B");
            }
        }
    }
    cout << cnt << "\n";
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << "\n";
    }

    return 0;
}