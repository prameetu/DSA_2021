#include<bits/stdc++.h>

using namespace std;

void merge(vector <int> &v,int l,int m,int h)
{
    int i=l,j=m+1,k=l;
    vector <int> p(h+1);

    while(i<=m && j<=h){
        if(v[i] < v[j])
            p[k++] = v[i++];
        else
            p[k++] = v[j++];
    }
    int r(l);
    while(i<=m)
        p[k++] = v[i++];
    while(j<=h)
        p[k++] = v[j++];
    
    while(r<=h){
        v[r] = p[r];
        r++;
    }


}
void merge_sort(vector <int> &v,int l,int h)
{
    if(l<h)
    {
        int mid = (l+h)/2;
        merge_sort(v,l,mid);
        merge_sort(v,mid+1,h);
        merge(v,l,mid,h);
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

    

    merge_sort(v,0,n-1);

    for(auto x:v)
        cout << x << " ";
}