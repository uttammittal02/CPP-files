#include <iostream>
// #include <vector>
using namespace std;
class custom_vect 
{
    int *a;
    int sz,cap;
public:
    custom_vect() 
    {
        a = NULL; sz =0; cap = 0;
    }
    void push_back(int num)
    {
        if(sz+1<=cap) 
        {
            a[sz] = num;
            sz++;
        }
        else
        {
            int *b;
            if(cap)
                b = new int[2*cap], cap*=2;
            else
                b = new int[1], cap=1;

            for(int i=0; i<sz; i++) 
                b[i]= a[i];

            delete[] a;

            a=b;
            a[sz] = num;
            sz++;
        }
    }

    int size() 
    {
        return sz;
    }

    int capacity() 
    {
        return cap;
    }

    void pop_back() 
    {
        if(sz)
            sz--;
    }

    int &back()
    {
        return a[sz-1];
    }

    int operator[](int i) {
        return a[i];
    }
};

int main() {
    custom_vect v;
    for(int i=0; i<100; i++) {
        v.push_back(1);
        cout<<v[i]<<' ';
        cout<<v.size()<<" "<<v.capacity()<<endl;
    }

    v.pop_back();
    cout<<v.size()<<endl;

    // Using vector of STL(Standard Template Library)
    // vector<int> vect;
    // vect.push_back(2);
    // cout<<vect.size()<<endl;
    // cout<<vect.capacity()<<endl;
    // vect.emplace_back(7);
    // for(int i=0; i<vect.size(); i++) cout<<vect[i]<<endl;
    
    return 0;
}