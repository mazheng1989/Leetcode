#include "stdafx.h"
#include <vector>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>    // std::reverse
#include <list>
#include <iostream>
#include "use_solution.h"
#include <unordered_map>
using namespace std;

    void Solution1::build(unordered_set<string> &dict){
        int i, j;
        vdict.clear();
        unordered_map<string, int> ids;
        for(auto it=dict.begin(); it != dict.end(); it++){
            ids[*it] = vdict.size();
            vdict.push_back(*it);
        }
        adj.clear();
        adj.resize(vdict.size());
        for(int i = 0; i < vdict.size(); i++){
            string w = vdict[i];
            for(int j = 0; j < vdict[i].size(); j++){
                for(char c = 'a'; c <= 'z'; c++)
                    if(c != vdict[i][j]){
                        w[j] = c;
                        if(ids.count(w)){
                            adj[i].push_back(ids[w]);
                        }
                        w[j] = vdict[i][j];
                    }
            }
        }
    }

    void Solution1::gen(int v1, int v2, vector<vector<int> >& prev, vector<int>& path, vector<vector<string> >&ans){
        path.push_back(v2);
        if(v2 == v1 && path.size() > 1){
            ans.push_back(vector<string>());
            for(auto rit = path.rbegin(); rit != path.rend(); rit++){
                ans.back().push_back(vdict[*rit]);
            }
        }else{
            int i;
            for(i = 0; i < prev[v2].size(); i++){
                gen(v1, prev[v2][i], prev, path, ans);
            }
        }
        path.pop_back();
    }
    vector<vector<string> > Solution1::findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        dict.insert(start);
        dict.insert(end);
        build(dict);
        queue<int> que;
        vector<vector<int> > prev(vdict.size());
        vector<int> distance(vdict.size());

        int v, v1, v2;
        for(v1 = 0; vdict[v1] != start; v1++);
        for(v2 = 0; vdict[v2] != end; v2++);
        for(int i = 0; i < adj[v1].size(); i++){
            v = adj[v1][i];
            que.push(v);
            prev[v].push_back(v1);
            distance[v] = 1;
        }
        while(!que.empty()){
            int v1 = que.front(); que.pop();
            if(v1 == v2) 
				break;
            int d = distance[v1] + 1;
            for(int i = 0; i < adj[v1].size(); i++){
                v = adj[v1][i];
                if(prev[v].size() == 0){
                    prev[v].clear();
                    prev[v].push_back(v1);
                    distance[v] = d;
                    que.push(v);
                }else if(distance[v] == d){
                    prev[v].push_back(v1);
                }
            }
        }

        vector<vector<string> > ans;

        vector<int> path;
        gen(v1, v2, prev, path, ans);

        return ans;
    }