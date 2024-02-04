#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};
class Solution {

public:

    int length(Node* head){

        Node* temp=head;

        int count=1;

        while(temp){

            temp=temp->next;

            count++;

        }

        return count;

    }

    

    Node* reverse(Node* head){

        Node*temp=head;

        Node* next=head->next;

        Node* prev=NULL;

        while(next){

            temp->next=prev;

            prev=temp;

            temp=next;

            next=temp->next;

        }

        

        temp->next=prev;

        return temp;

    }

 

    Node* subLinkedList(Node* head1, Node* head2) {

        //  implementation of subLinkedList goes here

        //sure to return the head of the resulting linked list

        while(head1->next!=NULL && head1->data==0){

            head1=head1->next;

        }

        while(head2->next!=NULL && head2->data==0){

            head2=head2->next;

        }

        

        int n1=length(head1);

        int n2=length(head2);

        

        if(n1==0 && n2==0){

            return new Node(0);

        }

        if(n1<n2){

            return subLinkedList(head2, head1);

        }

        else if(n1==n2){

            Node*t1=head1;

            Node*t2=head2;

            while(t1 && t2 && t1->data==t2->data){

                t1=t1->next;

                t2=t2->next;

            }

            if(t1==NULL){

                return new Node(0);

            }

            else if(t1->data < t2->data){

                return subLinkedList(head2, head1);

            }

        }

        

        head1=reverse(head1);

        head2=reverse(head2);

        

        Node* t1=head1;

        Node* t2=head2;

        

        Node* res=NULL;

        

        while(t1){

            int sub=0;

            if(t2!=NULL){

                sub=t2->data;

                t2=t2->next;

            }

            

            if(t1->data < sub){

                t1->next->data-=1;

                t1->data+=10;

            }

            

            Node* n=new Node(t1->data-sub);

            t1=t1->next;

            

            n->next=res;

            res=n;

        }

        

        while(res->next && res->data==0){

            res=res->next;

        }

        

        return res;

    }

};
// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}