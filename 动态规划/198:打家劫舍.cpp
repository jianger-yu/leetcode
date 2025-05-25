#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dp[110];
    int rob(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)  
            dp[i+2]=max(dp[i+1],dp[i]+nums[i]);
        return dp[nums.size()+1];
    }
};