#include <stdio.h>
#include <string>

using namespace std;


int main(){

    string s;
    char temp[101] = {};

    scanf("%s", temp);
    s = temp;

    for(int i = 0; i < 26; i++)
        printf("%d ", s.find(i+97));

    return 0;
}