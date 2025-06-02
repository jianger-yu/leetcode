#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
queue<int> q;
int h[5050], e[5050], ne[5050], idx = 0;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int ru[2010];
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> ans;
    memset(h, -1, sizeof h);
    for(int i = 0; i < prerequisites.size(); i++){
        add(prerequisites[i][1], prerequisites[i][0]);
        ru[prerequisites[i][0]]++;
    }
    for(int i = 0; i < numCourses; i++)
        if(ru[i] == 0)
            q.push(i),ans.push_back(i);
    while(q.size()){
        int t = q.front();
        q.pop();
        for(int i = h[t]; i != -1; i = ne[i]){
            int u = e[i];
            if(ru[u] > 0) ru[u]--;
            if(ru[u] == 0) q.push(u),ans.push_back(u);
        }
    }
    for(int i = 0; i < numCourses; i++)
        if(ru[i] != 0){
            ans.clear();
            break;
        }
    return ans;
}
};
