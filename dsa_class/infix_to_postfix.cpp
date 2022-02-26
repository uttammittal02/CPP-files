#include <iostream>
#include <stack>
using namespace std;

// const int n = 1000005;

// template <class T> class custom_Stack{
//     public:

//         void push(T x);

//         T pop();


//         T top();

//         bool full();

//         bool empty();
    
//     private:

//         int last = -1;

//         T arr[n];

// };

// template <class T> void custom_Stack<T>::push(T x){
//     if (full()){
//         cout<<"    Overflow\n";
//         return;
//     }
//     last++;
//     arr[last] = x;
//     return;
// }

// template <class T> T custom_Stack<T>::top(){
//     if (empty()){
//         cout<<"No elements present in Uttam's stack\n";
//         return -1;
//     }
//     return arr[last];
// }

// template <class T> T custom_Stack<T>::pop(){
//     if (empty()){
//         cout<<"    Underflow   \n";
//         T x;
//         return x;
//     }

//     last--;

//     return arr[last + 1];
// }

// template <class T> bool custom_Stack<T>::full(){
//     if (last == n - 1) return true;

//     return false;
// }

// template <class T> bool custom_Stack<T>::empty(){
//     if (last == -1) return true;

//     return false;
// }

int precedence(char symbol){
    if (symbol == '^') return 3;
    if (symbol == '*' || symbol == '/') return 2;
    if (symbol == '(') return 0;
    return 1;
}

void infix_to_postfix(string a){
    string result;
    stack <char> symbols;
    for (int i =0; i < a.size(); i++){
        char temp = a[i];
        if (temp == '+' || temp == '-' || temp == '*' || temp == '/' || temp == '^'){
            while(!symbols.empty() && precedence(temp) <= precedence(symbols.top())){
                result += symbols.top();
                symbols.pop();
            }
            symbols.push(temp);
        }
        else if (temp == '(') 
            symbols.push(temp);

        else if (temp == ')'){
            while(symbols.top() != '('){
                result+= symbols.top();
                symbols.pop();
            }
            symbols.pop();
        }
        else result += temp;
    }
    while (!symbols.empty()) {
        result+= symbols.top();
        symbols.pop();
    }
    cout<<"Postfix expression \t"<<result<<endl;
}

int main(){
    string infix;
    cin>>infix;
    cout<<"Infix expression \t"<<infix<<endl;
    infix_to_postfix(infix);
    return 0;
}