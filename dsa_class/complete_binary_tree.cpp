#include <iostream>
using namespace std;

int search_in_bt(int *arr, int i, int last, int target)
{
    if (i >= last) return -1;// if tree has no nodes further, then return

    if (arr[i] == target) return i;

    return max(search_in_bt(arr, 2*i+1, last, target), search_in_bt(arr, 2*i + 2, last, target)); // move to its left child; 
}

void pre_order(int *arr, int i, int last)
{
    if (i >= last) return;// if tree has no nodes further, then return

    cout << *(arr + i) << " ";

    pre_order(arr, 2*i+1, last); // move to its left child

    pre_order(arr, 2*i + 2, last); // move to its right child
}


void post_order(int *arr, int i, int last)
{
    if (i >= last) return;// if tree has no nodes further, then return

    post_order(arr, 2*i+1, last); // move to its left child
    
    post_order(arr, 2*i + 2, last); // move to its right child

    cout << *(arr + i) << " ";
}


void in_order(int *arr, int i, int last)
{
    if (i >= last) return;// if tree has no nodes further, then return

    in_order(arr, 2*i+1, last); // move to its left child
    
    cout << *(arr + i) << " ";

    in_order(arr, 2*i + 2, last); // move to its right child
}

void BFS(int *arr, int last)
{
    for(int i = 0; i < last; i ++){
        cout << arr[i] << ' ';
    }
}

int main()
{
    int n;
    cout<<"Please enter the maximum capacity of the tree: ";
    cin>>n;
    int *arr = new int[n];
    cout<<"Press 1 x to insert a node with value x.\nPress 2 x to delete a node x.\nPress 3, 4, 5 and 6 for pre-order traversal, in-order, post-order traversal and breadth-first search respectively.\nPress -1 to stop.\n";
    int i = 0;

    while (true){
        int x; cin>>x;
        if (x == -1) 
            break;
        if (x == 3){ 
            pre_order(arr, 0, i); cout << endl;
        }
        if (x == 4){
            in_order(arr, 0, i);
            cout << endl;
        }
        if (x == 5){ 
            post_order(arr, 0, i); cout << endl;
        }
        if (x == 6) {
            BFS(arr, i); cout << endl;
        }
        if (x == 1){
            int a; cin >> a;
            if (i >= n){
                cout << "Tree full!!\n";
                continue;
                // break;
            }
            arr[i] = a;
            i++;
        }
        if (x == 2){
            int a; cin >> a;
            int idx = search_in_bt(arr, 0, i, a);
            if (idx == -1){
                cout << "Node doesn't exist\n";
                continue;
            }
            arr[idx] = arr[i-1];
            i --;
        }
    }
    return 0;
}
//        1
//    2       3
//  4   5  6    
// (c*x + h*(x + 1)) = t(2x+1)
// x(c + h - 2t) = t - h