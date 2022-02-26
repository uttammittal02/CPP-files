#include <iostream>
using namespace std;
#define loop(var, init, end)    for(int var = init; var < end; var++)

// int input(){int k; cin>>k; return k;}
const int n = 5;
template <class T> class custom_Stack{
    public:

        void push(T x);

        T pop();


        void display();

        bool full();

        bool empty();
    
    private:

        int top = -1;

        T arr[n];

};

template <class T> void custom_Stack<T>::push(T x){
    if (full()){
        cout<<"    Overflow\n";
        return;
    }
    cout<<x<<" has been inserted in Uttam's stack.\n";
    top++;
    arr[top] = x;
    return;
}

template <class T> void custom_Stack<T>::display(){
    if (empty()){
        cout<<"No elements present in Uttam's stack\n";
        return;
    }
    cout<<"The following elements are present in Uttam Mittal's stack:\n";
    loop(i, 0, top+1){
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

template <class T> T custom_Stack<T>::pop(){
    if (empty()){
        cout<<"    Underflow   \n";
        T x;
        return x;
    }
    cout<<arr[top]<<" is the deleted element.\n";

    top--;

    return arr[top + 1];
}

template <class T> bool custom_Stack<T>::full(){
    if (top == n - 1) return true;

    return false;
}

template <class T> bool custom_Stack<T>::empty(){
    if (top == -1) return true;

    return false;
}

int main(int argc, char const *argv[])
{
    /* code */
    custom_Stack<int> stack;
    stack.pop();
    stack.push(1);
    stack.push(2);
    stack.push(0);
    stack.display();
    stack.pop();
    stack.display();
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.display();

    return 0;
}
