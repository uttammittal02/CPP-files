// Adelson-Velskii and Landis Tree
// a type of self balancing binary search tree

#include<iostream>
#include<queue>
using namespace std;

struct Node {

        int key;
        Node *left;
        Node *right;
        int height;

        Node(int x){
                key = x;
                left = NULL;
                right = NULL;
                height = 0;
        }
        ~Node(){
                delete left;
                delete right;
        }
};

int height(Node *N) {
        if(N == NULL)
                return -1;
        return N->height;
}

Node *rightRotate(Node *y) {
        Node *x = y->left;
        Node *T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
}

Node *leftRotate(Node *x) {
        Node *y = x->right;
        Node *T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
}

// Get the balance factor of each node
int BalanceFactor(Node *N) {
        if(!N)
                return 0;
        return height(N->left) - height(N->right);
}

// Insert a node
Node *insertNode(Node *node, int key) {
        // Find the correct postion and insert the node
        if(node == NULL){
                Node* t = new Node(key);
                return t;
        }
        if(key < node->key)
                node->left = insertNode(node->left, key);
        else if (key > node->key)
                node->right = insertNode(node->right, key);
        else
                return node;

        // Update the balance factor of each node and
        // balance the tree
        node->height = 1 + max(height(node->left),
               height(node->right));
        int balanceFactor = BalanceFactor(node);
        if(balanceFactor > 1) {
                if (key < node->left->key) {
                        return rightRotate(node);
                } 
                else if (key > node->left->key) {
                        node->left = leftRotate(node->left);
                        return rightRotate(node);
                }
        }
        if(balanceFactor < -1) {
                if (key > node->right->key) {
                        return leftRotate(node);
                } 
                else if (key < node->right->key) {
                        node->right = rightRotate(node->right);
                        return leftRotate(node);
                }
        }
        return node;
}

// Node with minimum value
Node *nodeWithMimumValue(Node *node) {
        Node *current = node;
        while (current->left != NULL)
                current = current->left;
        return current;
}

// Delete a node
Node *deleteNode(Node *root, int key) {
        // cout << height(root->left) << " "<< root -> key <<" "<< height(root->right) << endl;
        // Find the node and delete it
        if (!root)
                return root;
        if (key < root->key)
                root->left = deleteNode(root->left, key);
        else if (key > root->key)
                root->right = deleteNode(root->right, key);
        else{
                if ((root->left == NULL) || (root->right == NULL)) {
                        Node *temp = root->left ? root->left : root->right;
                        if (temp == NULL) {
                                temp = root;
                                root = NULL;
                        } 
                        else
                                *root = *temp;
                        delete temp;
                } 
                else{
                        Node *temp = nodeWithMimumValue(root->right);
                        root->key = temp->key;
                        root->right = deleteNode(root->right, temp->key);
                }
        }

        if (root == NULL)
        return root;

        // Update the balance factor of each node and
        // balance the tree
        root->height = 1 + max(height(root->left), height(root->right));

        int balanceFactor = BalanceFactor(root);
        // cout << height(root->left) << " balance factor of pehle 4 phir 5: "<< height(root->right) << endl;
        if (balanceFactor > 1) {
                if (BalanceFactor(root->left) >= 0) {
                        return rightRotate(root);
                } 
                else {
                        root->left = leftRotate(root->left);
                        return rightRotate(root);
                }
        }
        if (balanceFactor < -1) {
                if (BalanceFactor(root->right) <= 0) {
                        return leftRotate(root);
                } 
                else {
                        root->right = rightRotate(root->right);
                        return leftRotate(root);
                }
        }
        return root;
}

void levelOrder(Node* root){
        queue<Node*> q;

        q.push(root);

        cout << endl;
        while(q.empty() == false){
                int s = q.size();

                while(s--){
                        Node *t = (q.front());

                        q.pop();

                        cout << t->key << ' ';

                        if(t->left) q.push(t->left);
                        if(t->right) q.push(t->right);
                }   
                cout << endl;    
        }
        cout << endl;
}

int main() {
        Node *root = NULL;
        cout << "Hi!! Welcome to Uttam's interactive AVL tree.\nPress 1 x to insert an element x into the tree.\nPress 2 x to delete an element x from the tree.\nPress 3 to display the elements of the tree as level-order traversal.\nPress any other key to exit\n";
        while (true){
                int x; cin >> x;
                if (x == 1){
                        int ele; cin >> ele;
                        root = insertNode(root, ele);
                }
                else if (x == 2){
                        int ele; cin >> ele;
                        root = deleteNode(root, ele);
                }
                else if (x == 3){
                        // cout << "height of 3 is: " << height(root -> left) << endl;
                        levelOrder(root);}
                else
                        break;
        }
        return 0 ;      
}
