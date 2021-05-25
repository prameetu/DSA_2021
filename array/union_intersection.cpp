//union and intersection of two sorted arrays
#include<bits/stdc++.h>

using namespace std;

void unions(vector <int> v1,vector <int> v2)
{
    vector <int> ans;
    int i(0),j(0),k(0);
    while(i<v1.size() && j<v2.size())
    {
        if(v1[i] < v2[j])
        {
            ans.push_back(v1[i]);
            k++;
            i++;
        }
        else if(v1[i] > v2[j])
        {
            ans.push_back(v2[j]);
            k++;
            j++;
        }
        else
        {
            ans.push_back(v2[j]);
            i++;
            j++;

        }
    }
    for(;i<v1.size();i++)
    {
        ans.push_back(v1[i]);
        k++;
    }
    for(;j<v2.size();j++)
    {
        ans.push_back(v2[j]);
        k++;
    }

    for(auto x:ans)
        cout << x << " ";


}

void intersection(vector <int> v1,vector <int> v2)
{
    vector <int> ans;
    int i(0),j(0),k(0);
    while(i<v1.size() && j<v2.size())
    {
        if(v1[i] < v2[j])
        {
            
            i++;
        }
        else if(v1[i] > v2[j])
        {
            
            j++;
        }
        else
        {
            ans.push_back(v2[j]);
            i++;
            j++;

        }
    }
    for(auto x:ans)
        cout << x << " ";
    
}

int main()
{
    vector <int> v1,v2;
    int n,m;
    cin >> n >> m;
    int x;

    while(n--)
    {
        cin >> x;
        v1.push_back(x);
    }

    while(m--)
    {
        cin >> x;
        v2.push_back(x);
    }
    unions(v1,v2);
    cout << "\n\n";
    intersection(v1,v2);
}