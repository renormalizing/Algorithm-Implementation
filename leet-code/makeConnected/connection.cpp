#include <iostream>
#include <queue>
#include <vector>
#include <list>
using namespace std;

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1)
            return -1;
       std::vector<list<int>> adj(n);
       for(auto e:connections){
           adj[e[0]].push_back(e[1]);
           adj[e[1]].push_back(e[0]);
       }
       int comp = 0;
       bool visited[n];
       memset(visited, false, sizeof(bool)*n);
       queue<int> q;
       for (int i = 0; i < n; i++) {
           if(!visited[i]){
               q.push(i);
               comp++;
               while(!q.empty()){
                    int tmp = q.front();
                    visited[tmp] = true;
                    q.pop();
                    auto it = adj[tmp].begin();
                    while(it!=adj[tmp].end()){
                        cout << *it;
                        if(!visited[*it])
                            q.push(*it);
                        it++;
                    }
               }
           }
       }
       return comp-1;
       
}
};
int main(){
    std::vector<vector<int>> t = {{0,1}, {0,2},{1,2}};
    cout << Solution().makeConnected(4,t);
}
