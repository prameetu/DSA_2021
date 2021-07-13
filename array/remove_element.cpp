//leetcode - 27 

#include<bits/stdc++.h>

using namespace std;

int remove_element(vector <int> &nums,int val)
{
    int size(0);

    for(int i=0;i<nums.size();i++)
    {
        if(nums[i] != val)
        {
            nums[size] =  nums[i];
            size++;
        }
    }

    return size;
   
}

int main()
{
    vector <int> v;
    int n,x,val;
    cin >> n >> val;
    while(n--)
    {
        cin >> x;
        v.push_back(x);
    }

    for(int i=0;i<remove_element(v,val);i++)
    {
        cout << v[i] << " ";
    }
}