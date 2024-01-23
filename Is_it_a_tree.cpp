#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


class Solution {
  public:
    int isTree(int n, int m, vector<vector<int>> &adj) {
       
         vector<int> parent(n, -1); // To store parent of each node

        for (int i = 0; i < m; ++i) {
            int u = adj[i][0];
            int v = adj[i][1];

            if (find(parent, u) == find(parent, v)) {
                return 0; // Cycle detected
            }

            unionSets(parent, u, v);
        }

        int components = 0;
        for (int i = 0; i < n; ++i) {
            if (parent[i] == -1) {
                components++;
                if (components > 1) {
                    return 0; // More than one connected component
                }
            }
        }

        return 1;
    }

  private:
    int find(vector<int> &parent, int node) {
        return (parent[node] == -1) ? node : find(parent, parent[node]);
    }

    void unionSets(vector<int> &parent, int u, int v) {
        parent[find(parent, u)] = find(parent, v);
    }
    
};

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

