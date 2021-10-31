/*
#include <iostream>
#include <vector>

using namespace std;

long long sum(std::vector<int> &a){
  std::vector<int>::iterator iter;
  long long result = 0;
  for(iter=a.begin(); iter!= a.end(); iter++)
    result += *iter;

  return result;
}

vector<int> a(6, 3);

int main(){

  long long res;
  res = sum(a);

  printf("%lld", res);

  return 0;
}
*/
#include <stdio.h>

int main(){
  char quiz[100];
  int n, cnt = 0, sum = 0;

  scanf("%d", &n);

  for(int i = 0; i < n; i++){
    scanf("%s", quiz);
    for(int j = 0; quiz[j] != '\0'; j++){
      if(quiz[j]=='O'){
        cnt++;
        sum += cnt;
      }else{
        cnt = 0;
      }
    }
    printf("%d\n", sum);
    sum = 0;
    cnt = 0;
  }
  return 0;
}
