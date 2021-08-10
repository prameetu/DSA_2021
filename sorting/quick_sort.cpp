#include<bits/stdc++.h>

using namespace std;

int partition(vector <int> &v,int l,int h)
{
    int pivot(v[l]);
    int i(l),j(h);
    while(i<j)
    {
        do{
            i++;
        }while(v[i] < pivot);

        do{
            j--;
        }while(v[j] > pivot);

        if(i<j)
            swap(v[i],v[j]);
    }

    swap(v[l],v[j]);
    return j;
}

void quick_sort(vector <int> &v,int l,int h)
{
    if(l<h)
    {
        int j = partition(v,l,h);
        quick_sort(v,l,j);
        quick_sort(v,j+1,h);
    }
}

int main()
{
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i=0;i<n;i++)
    {
        v[i] = rand();
    }

    quick_sort(v,0,n);

    for(auto x:v)
        cout << x << " ";
}