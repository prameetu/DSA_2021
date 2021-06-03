//Unique element in an array where all elements occur k times except one
#include<bits/stdc++.h>
using namespace std;

void func(vector <int> nums,int k)
{
    int n = nums.size();
    int size = 8 * sizeof(unsigned int);
    vector <int> count(size);
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(nums[j] & (1 << i))
                count[i] += 1;
        }
    }
    int res(0);
    for(int i = 0;i<size;i++)
    {
        count[i] = count[i] % k;
        if(count[i])
            res = res + pow(2,i);
    }

    cout << res;


}

int main()
{
    int k;
    cin >> k;

    vector <int> nums{6,2,2,2,2};

    func(nums,k);

}