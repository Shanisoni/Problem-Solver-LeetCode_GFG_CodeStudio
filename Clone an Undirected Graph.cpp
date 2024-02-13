#include <bits/stdc++.h>
#include <sstream>
using namespace std;

struct Node {
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
vector<Node*> bfs(Node *src){
    vector<Node*>ans;
    map<Node*, bool> visit;
    queue<Node*> q;
    q.push(src);
    visit[src] = true;
    while (!q.empty()) {
        Node *u = q.front();
        ans.push_back(u);
        q.pop();
        vector<Node *> v = u->neighbors;
        int n = v.size();
        for (int i = 0; i < n; i++){
            if (!visit[v[i]]){
                visit[v[i]] = true;
                q.push(v[i]);
            }
        }
    }
    return ans;
}

bool compare(Node* prev, Node* new_node, unordered_set<Node*>& prev_vis, unordered_set<Node*>& new_vis) {
    if (prev == new_node) {
        return false;
    }
    if (!prev || !new_node) {
        if ((!prev && new_node) || (prev && !new_node)) {
            return false;
        }
        return true;
    }

    if (prev_vis.count(prev) || new_vis.count(new_node)) {
        if ((prev_vis.count(prev) && !new_vis.count(new_node)) || (!prev_vis.count(prev) && new_vis.count(new_node))) {
            return false;
        }
        return true;
    }
    prev_vis.insert(prev);
    new_vis.insert(new_node);

    if (prev->val != new_node->val) {
        return false;
    }

    size_t prev_n = prev->neighbors.size();
    size_t new_n = new_node->neighbors.size();
    if (prev_n != new_n) {
        return false;
    }

    sort(prev->neighbors.begin(), prev->neighbors.end(), [](Node* a, Node* b) { return a->val < b->val; });
    sort(new_node->neighbors.begin(), new_node->neighbors.end(), [](Node* a, Node* b) { return a->val < b->val; });

    for (size_t i = 0; i < prev_n; ++i) {
        if (!compare(prev->neighbors[i], new_node->neighbors[i], prev_vis, new_vis)) {
            return false;
        }
    }

    return true;
}


// } Driver Code Ends
//User function Template for C++

// struct Node {
//     int val;
//     vector<Node*> neighbors;
//     Node() {
//         val = 0;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val) {
//         val = _val;
//         neighbors = vector<Node*>();
//     }
//     Node(int _val, vector<Node*> _neighbors) {
//         val = _val;
//         neighbors = _neighbors;
//     }
// };

class Solution {
public:
    Node* cloneGraph(Node* node) {
         if (!node) {
            return nullptr;
        }

        unordered_map<Node*, Node*> clonedMap;

        // Create nodes
        queue<Node*> q;
        q.push(node);
        clonedMap[node] = new Node(node->val);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            for (Node* neighbor : current->neighbors) {
                if (!clonedMap.count(neighbor)) {
                    q.push(neighbor);
                    clonedMap[neighbor] = new Node(neighbor->val);
                }
            }
        }

        // Connect neighbors
        for (auto& entry : clonedMap) {
            Node* original = entry.first;
            Node* cloned = entry.second;

            for (Node* neighbor : original->neighbors) {
                cloned->neighbors.push_back(clonedMap[neighbor]);
            }
        }

        return clonedMap[node];
    }
};
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Node* root = NULL;
        vector<Node*>v(N);
        std::string buffer;
        std::getline(std::cin, buffer);
        for (int i = 0; i < N; i++)v[i] = new Node(i);
        for (int i = 0; i < N; i++) {
            std::vector<Node*> vec;
            std::string buffer;
            int data;
            std::getline(std::cin, buffer);
            std::istringstream iss(buffer);
            while (iss >> data)
                vec.push_back(v[data]);
            v[i]->neighbors = vec;
        }
        Solution ob;
        vector<Node*>prev = bfs(v[0]);
        Node* ans = ob.cloneGraph(v[0]);
        //vector<Node*>now = bfs(ans);
        unordered_set<Node*>prev_vis, new_vis;
        cout << compare(v[0], ans, prev_vis, new_vis) << endl;

    }
    return 0;
}