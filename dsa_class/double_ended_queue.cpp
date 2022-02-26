#include <iostream>
using namespace std;

template <class T> class deque{
    public:

        int n;

        void deque(int x){
            n = x;
            T *arr = new T[x];
            start = -1;
            end = -1;
        }

        void push_front(int x);

        void push_back(int x);

        void pop_front(int x);

        void pop_back();

        int front();

        int back();

    private:

        int start;

        int end;

};

template <class T> void deque<T>::push_front(int x){
    start ++;
    arr[start] = x;
}

