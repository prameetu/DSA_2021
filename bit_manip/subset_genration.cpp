#include<bits/stdc++.h>
using namespace std;

vector <vector <int> > subsets(vector <int> nums)
{
    int n(nums.size());
    vector <vector <int> > res{{}};
    if(n==0)
        return res;
    for(auto x:nums)
    {
        int s = res.size();
        for(int i=0;i<s;i++)
        {
            vector <int> r = res[i];
            r.push_back(x);
            res.push_back(r);
        }
    }
    
    return res;
}

vector <vector <int> > subsets_bit_masking(vector <int> nums)
{
    int n(nums.size());
    int num_subsets(1 << n) ;    // 2^n = 1 << n
    vector <vector <int>> power_set;
    for(int i=0;i<num_subsets;i++)
    {
        vector <int> subset;
        for(int j=0;j<n;j++)
        {
            if((i & (1 << j)))
                subset.push_back(nums[j]);
        }

        power_set.push_back(subset);
    }

    return power_set;
} 
int main()
{
    int n;
    cin >> n;
    vector <int> nums(n);
    for(int i=0;i<n;i++)
    {
        cin >> nums[i];
    }
    subsets(nums);
}