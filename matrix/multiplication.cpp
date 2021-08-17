#include<bits/stdc++.h>

using namespace std;

void multiply(vector <vector <int> > mat1,vector <vector <int> > mat2)
{
    vector < vector <int > > mat3(3,{0,0,0});
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            mat3[i][j] = 0; 
            for(int k=0;k<2;k++)
            {
                mat3[i][j] += mat1[i][k] *mat2[k][j];
            }
        }
    }

    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            cout << mat3[i][j] << " ";
        }
        cout << endl;
    }


}

int main()
{
    vector <vector <int> > mat1 = {{1,2},
                                   {3,4},
                                   {5,6}};
    vector <vector <int> > mat2 = {{1,2,3},
                                   {4,5,6}};
    
    multiply(mat1,mat2);


}