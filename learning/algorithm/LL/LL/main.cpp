//
//  main.cpp
//  LL
//
//  Created by Mac Bellingrath on 8/4/17.
//  Copyright © 2017 McmillanBellingrath. All rights reserved.
//

#include <cstddef>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d){
        data=d;
        next=NULL;
    }
};

class Solution{
public:

    /**
     removes duplicates from linked list

     @param head node nude
     @return head node from updated list after duplicates have been removed
     */
    Node* removeDuplicates(Node *head)
    {
        Node* n = head;

        while( n != NULL ) {

            while( n->next != NULL && n->data == n->next->data ) {
                Node* delete_me = n->next;
                n->next = n->next->next;
                delete delete_me;
            }
            
            n = n->next;
        }
        return head;
    }

    Node* insert(Node *head,int data)
    {
        Node* p=new Node(data);
        if(head==NULL){
            head=p;

        }
        else if(head->next==NULL){
            head->next=p;

        }
        else{
            Node *start=head;
            while(start->next!=NULL){
                start=start->next;
            }
            start->next=p;

        }
        return head;


    }
    void display(Node *head)
    {
        Node *start=head;
        while(start)
        {
            cout<<start->data<<" ";
            start=start->next;
        }
    }
};

int main()
{
    Node* head=NULL;
    Solution mylist;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        head=mylist.insert(head,data);
    }
    head=mylist.removeDuplicates(head);

    mylist.display(head);

}
