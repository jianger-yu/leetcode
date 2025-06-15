#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arr[300]={0};
    bool strok(int l,int r ,string s){
        for(int i=l;i<=r;i++){
            if(arr[s[i]]>=2) return false;
        }
        return true;
    }
    int lengthOfLongestSubstring(string s) {
        int l=0,r,ans=0;
        for(r=0;r<s.size();r++){
            arr[s[r]]++;
            if(strok(l,r,s)){
                ans=max(ans,r-l+1);
            }
            while((!strok(l,r,s))&&l<r) {
                arr[s[l]]--;
                l++;
            }
        }
        return ans;
    }
};