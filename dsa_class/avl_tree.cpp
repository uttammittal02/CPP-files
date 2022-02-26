#include <iostream>
using namespace std;

struct Node{
    int val;
    Node *left, *right;
    Node(int x){
        val = x;
        left = right = NULL;
    }
};

class Bst
{
public:

    Node *root;

    Bst(int x) {
        root = new Node(x);
        // root -> val = x;
    }
    
    Node *insert(int x, Node *head){
        if (head == NULL){
            Node *t = new Node(x);
            return t;
        }
        if (x > head -> val)
            head -> right = insert(x, head ->right);
        
        else
            head -> left = insert(x, head ->left);
        
        return head;
    }

    bool search(int x, Node *head){
        if (!head) return false;
        if (head -> val == x) return true;
        if (head -> val < x) return search(x, head->right);
        return search(x, head->left);
    }

    void Inorder(Node *head){
        if (!head) return;
        Inorder(head->left);
        cout << head->val << ' ';
        Inorder(head->right);
    }

};

int main(){
    Bst b(5);
    b.insert(1, b.root);
    b.insert(8, b.root);
    b.insert(3, b.root);
    b.insert(2, b.root);
    b.insert(9, b.root);
    b.Inorder(b.root);
    // cout << b.search(30, b.root) << endl;
}