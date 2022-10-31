#include <iostream>
#include <complex>
#include <vector>

using cpx = std::complex<double>;
using vec = std::vector<cpx>;

const double pi = acos(-1);

void FFT(vec &a, bool inv){
    int n = (int) a.size();
    for(int i = 1, j = 0; i < n; i++){
        int bit = n >> 1;
        while(!((j ^= bit) & bit)) bit >>= 1;
        if(i < j) swap(a[i], a[j]);
    }
    for(int i = 1; i < n; i <<= 1){
        double x = inv ? pi / i : -pi / i;
        cpx w = {cos(x), sin(x)};
        for(int j = 0; j < n; j += i << 1){
            cpx th = {1, 0};
            for(int k = 0; k < i; k++){
                cpx tmp = a[i+j+k] * th;
                a[i+j+k] = a[j+k] - tmp;
                a[j+k] += tmp;
                th *= w;
            }
        }
    }
    if(inv){
        for(int i = 0; i < n; i++){
            a[i] /= n;
        }
    }
}

void mul(vec &a, vec &b){
    int n = 1;
    while(n <= (int) std::max(a.size(), b.size())) n <<= 1;
    n <<= 1;
    a.resize(n); b.resize(n);
    FFT(a, false); FFT(b, false);
    for(int i = 0; i < n; i++) a[i] = a[i] * b[i];
    FFT(a, true);
}

int main(){
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);
    int n;
    std::cin >> n;
    vec a(n<<1);
    vec b(n);
    for(int i = 0, tmp; i < n; i++){
        std::cin >> tmp;
        a[i] = tmp;
        a[i+n] = tmp;
    }
    for(int i = n-1, tmp; i >= 0; i--){
        std::cin >> tmp;
        b[i] = tmp;
    }
    mul(a, b);
    int ans = -1;
    for(int i = 0; i < a.size(); i++){
        if(round(a[i].real()) > ans)
            ans = round(a[i].real());
    }
    std::cout << ans;

    return 0;
}