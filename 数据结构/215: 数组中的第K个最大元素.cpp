#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> hp;
        for(int dig : nums) hp.push(dig);
        for(int i = 0 ; i < k - 1 ; i++) hp.pop();
        return hp.top();
    }
};