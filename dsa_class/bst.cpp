#include <iostream>
using namespace std;

int n = 1e7;

template <class T> class queue{
    public:

        queue(int n){
            T *arr = new T[n];
            start = -1;
            end = -1;
        }

        void enque(T x);

        bool empty();

        void deque();

        T front();
    
    private:

        T *arr;

        int start;

        int end;

};

template <class T> void queue<T>::enque(T x){
    if ((start == -1 and end == n-1) or (start == end and start != -1)){
        cout<<"Queue is full\n";
        return;
    }

    end++;
    end %= n;
    arr[end] = x;
    return;
}

template <class T> void queue<T>::deque(){
    if (-1 == end){
        cout<<"Queue is empty\n";
        return;
    }
    if ((end + n - start) % n == 1){
        start = -1;
        end = -1;
        return;
    }
    start++;
    start %= n;
    return;
}
template <class T> T queue<T>::front(){
    
    return *(arr+(start+1)%n);
}
 
template <class T> bool queue<T>::empty(){
    if (-1 == end){
        // cout<<"Queue is empty\n";
        return 1;
    }
    return 0;
}

struct Node{
    int val;

    Node *left, *right, *parent;

    Node(int data, Node *par){
        val = data;

        left = NULL, right = NULL, parent = par;
    }
};

struct BinarySearchTree{
    Node *root;

    BinarySearchTree(int val){
        this->root = new Node(val, NULL);
    }
    // void Insert(int n){
    //     insert(n, this->root, NULL);
    // }
    void insert(int n, Node *root, Node *parent){
        if(root == NULL){
            if(parent->val > n) parent->left = new Node(n, parent);

            else parent->right = new Node(n, parent);

            return;
        }
        if(root->val > n){
            insert(n, root->left, root);
        }
        else insert(n, root->right, root);
    }
    Node *find_value(int n, Node *root){
        if(root == NULL) return NULL;

        if(root->val == n) return root;

        if(root->val > n) return find_value(n, root->left); else return find_value(n, root->right);
    }
    Node *find_max_subtree(Node* root){
        if(root->right) return find_max_subtree(root->right);

        return root;
    }
    void deleteNode(int n){
        
        Node * delete_node = find_value(n, this->root);

        if(!delete_node){
            cout << "Node doesn't exist." << endl; return;
        }

        if(delete_node->right and delete_node->left){

            Node * rightmost_leaf_in_left_subtree = find_max_subtree(delete_node->left);
            int t = rightmost_leaf_in_left_subtree->val;

            deleteNode(t);

            delete_node->val = t;

            return;
        }
        if(delete_node->right or delete_node->left){
            // corner case if this->root is to be deleted

            if(this->root == delete_node){
                Node* t = this->root;

                this->root = (this->root->left ? this->root->left : this->root->right);

                t->left=t->right=NULL;
                delete t;
                return;
            }

            Node * Parent = delete_node->parent;

            (Parent->left == delete_node ? Parent->left : Parent->right) = (delete_node->left ? delete_node->left : delete_node->right);

            delete_node->left=delete_node->right=NULL;

            delete delete_node; return;
        }
        // no child found i.e. the given node is a leaf
        Node *P = delete_node->parent;
        (P->left->val == n ? P->left : P->right) = NULL;
        delete delete_node;
    }
    void levelOrderTraversal(){
        queue<Node *> Q((int)1e7);
        
        Q.enque(root);

        while(Q.empty() == 0){
            Node *p = Q.front();

            cout << p->val << ' ';

            Q.deque();

            if(p->left) Q.enque(p->left); if(p->right) Q.enque(p->right);
        }
        cout << endl;
    }
    void InOrderTraversal(Node *root){
        if(!root) return;
        InOrderTraversal(root->left); cout << root->val << " "; InOrderTraversal(root->right);
    }
    void PreOrderTraversal(Node *root){
        if(!root) return;
        cout << root->val << " "; PreOrderTraversal(root->left); PreOrderTraversal(root->right);
    }
    void PostOrderTraversal(Node *root){
        if(!root) return;
        PostOrderTraversal(root->left); PostOrderTraversal(root->right); cout << root->val << " ";
    }
    
};

int32_t main(){
    cout << "Enter the root node to start with : ";
    int x; cin >> x;
    BinarySearchTree B(x);
    cout<<"Press 1 x to insert a node with value x.\nPress 2 x to delete a node x.\nPress 3, 4, 5 and 6 for pre-order traversal, in-order, post-order traversal and level-order traversal respectively.\nPress -1 to stop.\n";
    // int i = 0;
    while(true){
        int x; cin >> x;
        if (x == 1){
            int a; cin >> a;
            B.insert(a, B.root, NULL);
        }
        if (x == 2){
            int a; cin >> a;
            B.deleteNode(a);
        }

        if(x == 3)  {
            B.PreOrderTraversal(B.root);
            cout << '\n';
        }

        if (x == 4) {
            B.InOrderTraversal(B.root);
            cout << '\n';
        }

        if (x == 5) {
            B.PostOrderTraversal(B.root);
            cout << '\n';
        }

        if (x == 6) {
            B.levelOrderTraversal();
            cout << '\n';
        }
        
        if  (x == -1) break; 
    }
    return 0;
}
