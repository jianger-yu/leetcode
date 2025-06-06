#include <bits/stdc++.h>
using namespace std;

bool goaround(int st,int &end, vector<int>& gas, vector<int>& cost){
        int cnt = gas[st], i = st;
        while(1){
            cnt -= cost[i];
            if(cnt < 0){
                end = i + 1;
                return false;
            }
            i++;
            if(i == st) return true;
            if(i == gas.size()) i = 0;
            cnt = cnt + gas[i];
        }
    }
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int st = 0, end = 0, road = 0;
    while(1){
        if(goaround(st, end, gas, cost)) return st; 
        else{
            if(end > st)
                road += end - st + 1;
            else break;
            st = end;
            if(road >= gas.size()) break;
            continue;
        }
    }
    return -1;
}
