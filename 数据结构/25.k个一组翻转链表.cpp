#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head->next == NULL) return head;
        ListNode* arr[5010];
        int size = -1;
        while(head != NULL){
            arr[++size] = head;
            head = head -> next;
        }
        int i = 0, t = (size+1) / k;
        for(i = 0; i < t; i++){
            int st = i * k;
            for(int j = st; j < st + k; j++){
                if(j == st) arr[j]->next = arr[st+k-1]->next;
                else arr[j]->next = arr[j - 1];
                if(j == st+k-1){
                    if(i == 0)
                        head = arr[j];
                    if((i+2)*k - 1 <= size)
                        arr[st]->next = arr[(i+2)*k - 1];
                }
            }
        }
        return head;
    }
};