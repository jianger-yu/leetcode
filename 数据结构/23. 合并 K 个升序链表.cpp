#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = NULL, *last;
        priority_queue<int, vector<int>, greater<int>> heap;
        for(int i = 0; i < lists.size(); i++){
            ListNode* node = lists[i];
            while(node != NULL){
                heap.push(node->val);
                node = node->next;
            }
        }
        while(heap.size()){
            ListNode *node = new ListNode;
            node->next = NULL;
            node->val = heap.top();
            heap.pop();
            if(ans == NULL){
                ans = node;
                last = node;
                continue;
            }
            else{
                last->next = node;
                last = node;
                continue;
            }
        }
        return ans;
    }
};