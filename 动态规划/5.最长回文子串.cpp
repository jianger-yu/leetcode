#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool ck(int i, int j, string &s){
        while(i <= j){
            if(s[i++] != s[j--]) return false;
        }
        return true;
    }
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        string ans;
        ans.push_back(s[0]);
        for(int i = 0; i < s.size() - 1; i++){
            for(int j = i + 1; j < s.size(); j++){
                if(j-i+1 > ans.size() && ck(i,j,s)){
                    ans = s.substr(i, j - i + 1);
                }
            }
        }
        return ans;
    }
};