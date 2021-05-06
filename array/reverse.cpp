//reverse a string
//Expected Time Complexity: O(|S|).
//Expected Auxiliary Space: O(1)
#include <bits/stdc++.h>

using namespace std;

string reverse_string(string s)
{
    int i(0),j(s.size()-1);
    while(i<j)
    {
        char temp;
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;

        i++;
        j--;
    }

    return s;


}

int main()
{
    string s;
    int t;
    cin >> t;
    while(t--){
        cin >> s;
        cout << reverse_string(s) << endl;
    }  
}