#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> left;
        for(int i = 0; i < s.size() ; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{' )
                left.push(s[i]);
            else{
                if(left.empty()) return false;
                switch(s[i]){
                    case ')': if(left.top() != '(') return false; break;
                    case ']': if(left.top() != '[') return false; break;
                    case '}': if(left.top() != '{') return false; break;
                }
                left.pop();
            }
        }
        if(left.empty()) return true;
        else return false;
    }
};
