#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

class Solution{
    public:
   
    Node* solve(Node* root,int a,int b){
        if(root == NULL){
            return NULL;
        }
        if(root->data == a || root->data == b){
            return root;
        }
        
        Node* l = solve(root->left,a,b);
        Node* r = solve(root->right,a,b);
        
        if(l != NULL && r != NULL){
            return root;
        }
        else if(l == NULL && r != NULL){
            return r;
        }
        else if(l != NULL && r == NULL){
            return l;
        }
    }
    pair<int,int> solve2(Node* root,int a){
        if(root == NULL){
            return {0,0};
        }
        if(root->data == a){
            return {1,1};
        }
        
        pair<int,int> l = solve2(root->left,a);
        pair<int,int> r = solve2(root->right,a);
        
        if(l.first == 1 || r.first == 1){
            return {1,l.second+r.second+1};
        }
        else{
            return {0,l.second+r.second};
        }
    }
    int findDist(Node* root, int a, int b) {
        //Step1 = Calculate LCA of a and LCA of b
        //Step2 = Now take out the distance of a and b from the given LCA
        //Step3 = Add the edges from the left and right of LCA
        Node* strt = solve(root,a,b);
        
        int l = (strt->data == a) ? 0: solve2(strt,a).second-1;
        int r = (strt->data == b) ? 0: solve2(strt,b).second-1;
        return l+r;
    }
};
int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}
