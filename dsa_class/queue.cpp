#include <iostream>
using namespace std;

// const int n = 5;
int n;

template <class T> class queue{
    public:
        void enque(T x);

        void display();

        void deque();

        T front();
    
    private:

        T *arr = new int(n);

        int start = -1;

        int end = -1;

};

template <class T> void queue<T>::enque(T x){
    if (end == start and start != -1){
        cout<<"Queue is full\n";
        return;
    }
    arr[end] = x;
    end++;
    end %= n;
    return;
}

template <class T> void queue<T>::deque(){
    if (start == -1){
        cout<<"Queue is empty\n";
        return;
    }
    if ((n + end - start)%n == 1) {
        start = -1;
        end = -1;
        return;
    }
    start++;
    start%=n;
    
    
    return;
}

template <class T> T queue<T>::front(){
    
    return arr[(start + 1)%n];
}

template <class T> void queue<T>::display(){
    for (int i = start; i != end; i=(i+1)%n){
        cout<<arr[i]<<' ';
        
    }
    cout<<endl;
}


int main(){
    cout<<"Hi. \nWelcome to the interactive queue!!!\nEnter the capacity your queue should have : " ;
    cin>>n;
    cout<<"\nPress '1' for enque.\nPress 2 for deque.\nPress 3 to see the front of queue.\nPress 4 to display all the elements.\nPress any other key to exit.\n";
    queue <int> trial;
    

    while (true){
        int r; cin>>r;
        if (r==1){
            cout<<"Enter the element you want to insert in the queue :";
            int temp; cin>>temp; trial.enque(temp);
        }
        else if (r == 2){
            trial.deque();
        }
        else if (r == 3){
            cout<<trial.front()<<endl;
        }
        else if (r == 4){
            trial.display();
        }
        else break;
    }
    return 0;
}
