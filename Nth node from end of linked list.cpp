#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

int getNthFromLast(struct Node* head, int n);

class Solution{
public:
    int getNthFromLast(Node *head, int n)
    {

            Node* temp=head;
           int cnt=0;
           while(temp!=NULL){
               temp=temp->next;
               cnt++;
           }
        int res=cnt-n;
        Node* tem=head;
        while(res!=0 && tem!=NULL){
            tem=tem->next;
            res--;
        }
       return res==0?tem->data:-1;
    }
};
int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
    cout<<obj.getNthFromLast(head, k)<<endl;
    }
    return 0;
}