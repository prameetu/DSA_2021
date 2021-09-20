//print root to a particular node path in binary tree
#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool helper(TreeNode *A,int B,vector <int> &res)
{
    if(!A)
        return false;
    res.push_back(A->val);
    if(A->val == B)
        return true;
    
    if(helper(A->left,B,res) || helper(A->right,B,res))
        return true;
    
    res.pop_back();
    return false; 
    

}

vector<int> solve(TreeNode *A, int B)
{
    vector <int> ans;
    
    if(!A)
        return ans;
    
    helper(A,B,ans);
    return ans;
}
