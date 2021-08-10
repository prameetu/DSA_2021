#include<bits/stdc++.h>

using namespace std;

void insertion_sort(vector <int> &v)
{
    int n(v.size());
    int j;
    for(int i=1;i<n-1;i++){
        j = i-1;
        int key = v[i];

        while(j >=0 && v[j] > key){
            v[j+1] = v[j];
            j--;
        }

        v[j+1] = key;
    }
}

int main()
{
    int n;
    cin >> n;
    vector <int> v(n);
    for(int i=0;i<n;i++)
    {
        cin  >> v[i];
    }

    insertion_sort(v);

    for(auto x:v)
        cout << x << " ";
}