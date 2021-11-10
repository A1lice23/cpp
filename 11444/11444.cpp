#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Mat{
    ll mat[2][2];
};

Mat setMat(ll a, ll b, ll c, ll d){
    Mat x;
    x.mat[0][0] = a; x.mat[0][1] = b;
    x.mat[1][0] = c; x.mat[1][1] = d;
    return x;
}

Mat multiply(Mat a, Mat b){
    Mat c;
    c.mat[0][0] = (a.mat[0][0] * b.mat[0][0] + a.mat[0][1] * b.mat[1][0]) % 1000000007;
	c.mat[0][1] = (a.mat[0][0] * b.mat[0][1] + a.mat[0][1] * b.mat[1][1]) % 1000000007;
	c.mat[1][0] = (a.mat[1][0] * b.mat[0][0] + a.mat[1][1] * b.mat[1][0]) % 1000000007;
	c.mat[1][1] = (a.mat[1][0] * b.mat[0][1] + a.mat[1][1] * b.mat[1][1]) % 1000000007;
    return c;
}

Mat powM(Mat a, ll b){
    Mat res = setMat(1, 0, 0, 1);
    Mat powN = a;
    while(b){
        if(b & 1)
            res = multiply(res, powN);
        b >>= 1;
        powN = multiply(powN, powN);
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    Mat k = powM(setMat(1, 1, 1, 0), n);
    cout << k.mat[0][1];

    return 0;
}