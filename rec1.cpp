//Write a function that takes two inputs n and m and o
//outputs the number of unique paths from the top left corner to bottom right corner of n*m grid
//Contraint : Move down or right 1 unit at a time

#include<bits/stdc++.h>

using namespace std;

int max_num_of_path(int n, int m)
{
    if(n==1 || m==1){
        return 1;
    }
    else{
        return max_num_of_path(n-1,m) + max_num_of_path(n,m-1);
    }

}

int main()
{
    cout << max_num_of_path(3,4);
}