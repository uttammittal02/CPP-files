#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <cmath>
using namespace std;

int to_binary(int x)
{
    int no , final_binary = 0;
    vector<int> pre_binary;
    int copy = x;
    while(copy != 0)
    {
        int rem = copy % 2;
        copy = copy / 2;
        pre_binary.push_back(rem);
    }
    reverse(pre_binary.begin() , pre_binary.end());
    
    for(int i = 0; i < pre_binary.size(); i++)
    {
        final_binary = final_binary * 10 + pre_binary[i];

    }

    //cout << final_binary << endl;
    
    return final_binary;
    
}

int main()
{// { cout<<(1^2)<<endl;
    int t , n;
    cin >> t;
    while(t > 0)
    {
        t--;
        cin >> n;
        int count = 0;
        // vector<int> entire_range;
        for(int i = 0; i <= (int)((pow(2.0 , n)) - 1) ; i++)
        {
            if ((i ^ (i + 1)) == ((i + 2) ^ (i + 3)))
            {
                count ++;
            }
        }

        cout << count % 1000000007 << endl;
    }
}