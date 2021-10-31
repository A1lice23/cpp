#include <stdio.h>

int main(){
    int a, b;
    int Ca, Cb;

    scanf("%d %d", &a, &b);
    
    Ca += 100 * (a % 10);
    Ca += 10 * ((a % 100) / 10);
    Ca += a / 100;
    Cb += 100 * (b % 10);
    Cb += 10 * ((b % 100) / 10);
    Cb += b / 100;
    
    printf("%d", Ca > Cb ? Ca : Cb);

    return 0;
}