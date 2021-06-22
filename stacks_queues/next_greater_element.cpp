//find the next greater element toward the right for every number in the given array.
#include <bits/stdc++.h>
#define MOD 1000000007
#define ll long long int
#define rep(i,a,b) for(ll i=a;i<b;i++)

using namespace std;

vector <int> next_greater_element(vector<int> v)
{
    int n(v.size());
    stack <int> st;
    vector <int> ans(n);
    for(int j=n-1;j>=0;j--){

        while(!st.empty() && st.top() <= v[j]){
            st.pop();
        }
        if(!st.empty()){
            ans[j] = st.top();
        }
        else{
            ans[j] = -1;
        }

        st.push(v[j]);
    }
}

int main()
{
    int n;
    cin >> n;
    vector <int> v(n);
    rep(i,0,n){
        cin >> v[i];
    }

    vector <int> ans = next_greater_element(v);
}