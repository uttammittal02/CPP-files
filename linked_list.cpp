#include <iostream>
#include <cmath>
#include <vector>

#define loop(j,n) for(int i = j; i < n; i++)
using namespace std;

class node{
    
public:
    int data;
    node *next;
    node *prev;
    node(int d){
        data = d;
        next = NULL;
        prev = NULL;
    }
}

class linked_list{
public:
    node *head;
    linked_list(){
        head = NULL;
        tail = NULL;
        int size = 0
    }
    void push_front(int d){
        node *new_head = new node(d);
        if (head == NULL) tail = new_head;
        else head -> prev = new_head;
        new_head -> next = head;
        head = new_head;
        size++;
    }
    void push_back(int d){
        node *new_tail = new node(d);
        if (tail == NULL) head = new_tail;
        else tail -> next = new_tail;
        new_tail -> prev = tail;
        new_tail->prev = tail;
        tail = new_tail;
        size++;
    }
    void insert(node *cur, int d){ //address of node after which the new element is to be iinserted is given
        node *new_node = new node(d);
        new_node-> next = curr->next;
        curr-> next = new_node;
        new_node-> prev = curr;
        if (new_node->next == NULL) new_node->next->prev = new_node;
        else tail = new_tail;
        size++;
    }
    void pop_back(){ //O(n) for singly linked and O(1) for doubly linked
        if (tail == NULL) return;
        else{
        if (tail-> prev == NULL) delete head, head = tail = NULL;
        else {
            node *new_tail = tail->prev;
            new_tail -> next = NULL;
            delete tail;
            tail = new_tail;
        }
        size--;}
    }
    void pop_front(){

    }
    void pop(node *curr){
        if (size == 1){
            delete curr;
            head = tail = NULL;
        }
        if (curr -> prev == NULL){
            curr -> next -> prev = NULL;
            head = curr -> next;
        }
        if (curr -> next = NULL){
            tail = curr -> prev;
        }
        curr -> next -> prev = curr -> next;
    }
}