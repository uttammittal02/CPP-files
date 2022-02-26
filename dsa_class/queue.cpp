#include <iostream>
using namespace std;

int n;

template <class T> class queue{
    public:

        queue(int n){
            T *arr = new T[n];
            start = -1;
            end = -1;
        }

        void enque(T x);

        void display();

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
template <class T> void queue<T>::display(){
    int i = start + 1;
    if (end == -1){
        cout<<endl;
        return;
    }
    while(true){
        cout<<*(arr+i)<<' ';
        i++;
        i%=n;
        if (i == (end + 1)%n) break;
    }
    cout<<endl;
} 
int main(){
    cout<<"Hi. \nWelcome to Uttam's interactive circular queue!!!\nEnter the capacity your queue should have : " ;
    cin>>n;
    cout<<"\nPress '1' for enque.\nPress 2 for deque.\nPress 3 to see the front of queue.\nPress 4 to display all the elements.\nPress any other key to exit.\n";
    queue <int> trial(n);
    while (true){
        int r; cin>>r;
        if (r==1){
            cout<<"Enter the element you want to insert in the queue : ";
            int temp; cin>>temp; 
            trial.enque(temp);
        }
        else if (r == 2)    trial.deque();
        else if (r == 3)    cout<<trial.front()<<endl;
        else if (r == 4)    trial.display();
        else break;
    }
    return 0;
}
