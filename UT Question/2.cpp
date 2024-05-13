

    class Solution {
      public:
        int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
            int ans=0;
            vector<int> vis(v+1);
            vector<vector<int>> graph(v+1);
            for(auto e: edges){
                graph[e[0]].push_back(e[1]);
                graph[e[1]].push_back(e[0]);
            }
            for(int i=1;i<=v;i++){
                int vCount=0,eCount=0;
                if(!vis[i]){
                    queue<int> q;
                    q.push(i);
                    vis[i]=1;
                    while(!q.empty()){
                        int node=q.front();
                        q.pop();
                        vCount++;
                        eCount+=graph[node].size();
                        for(int adj:graph[node]){
                            if(!vis[adj]){
                                vis[adj]=1;
                                q.push(adj);
                            }
                        }
                    }
                    ans+=(eCount == vCount*(vCount-1));
                }
            }
            return ans;
        }
    };

