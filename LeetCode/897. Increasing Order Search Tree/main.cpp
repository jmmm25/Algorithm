#include <iostream>
#include <vector>

using namespace std;

//  Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> v;
void inorder(TreeNode *root)
{
    if (root == nullptr)
    {
        return;
    }
    inorder(root->left);
    v.push_back(root->val);
    inorder(root->right);
}

class Solution
{
public:
    TreeNode *increasingBST(TreeNode *root)
    {
        inorder(root);
        TreeNode *ret = new TreeNode(v[0]);
        TreeNode *tmp = ret;

        for (int i = 1; i < v.size(); i++)
        {
            TreeNode *node = new TreeNode(v[i]);
            tmp->right = node;
            tmp = tmp->right;
        }
        v.clear();
        return ret;
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
