#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
  int n, m;
  cin >> n >> m;
  string s1, s2, str;
  cin >> s1 >> s2;
  sort(s2.begin(), s2.end());
  int j = 0;
  for(int i = 0; i < s1.size(); i++){
    if(s2[j] < s1[i]) {
      s1.insert(s1.begin() + i, s2[j]);
      j++;
    }
    if(j == s2.size()) break;
  } 
  if(j != s2.size()){
    s2.erase(s2.begin(), s2.begin() + j);
    s1 += s2;
  }
  printf("%s",s1.data());
  return 0;
}