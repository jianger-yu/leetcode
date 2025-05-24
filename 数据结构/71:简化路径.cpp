#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        //对“/”去重
        for(int i=1;i<path.size();i++){
            if(path[i]=='/'&&path[i-1]=='/') {
                path.erase(path.begin()+i,path.begin()+i+1);
                i--;
            }
        }
        //处理“.”
        for(int i=1;i<path.size();i++){
            if(path[i]=='.'&&path[i-1]=='/'){
                if(i!=path.size()-1&&path[i+1]!='/') continue;
                path.erase(path.begin()+i-1,path.begin()+i+1);
                if(path.empty()) path.push_back('/');
                i-=2;
            }
        }
        //处理".."
        for(int i=1;i<path.size()-1;i++){
            if(path[i]=='.'&&path[i+1]=='.'&&path[i-1]=='/'){
                if(i!=path.size()-2&&path[i+2]!='/') continue;
                int j=i,cnt=0;
                while(j>0){
                    if(path[j]=='/') cnt++;
                    if(cnt==2) break;
                    j--;
                }
                path.erase(path.begin()+j,path.begin()+i+2);
                if(path.empty()) path.push_back('/');
                i=j;
            }
        }
        if(path.size()>1&&path.back()=='/') path.pop_back();
        return path;
    }
};