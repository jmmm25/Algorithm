struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int min_val = -10001;

int dfs(TreeNode *root, int min_val) {
    int ret = 0;
    if (root == nullptr) {
        return 0;
    }
    if (root->val >= min_val) {
        ret++;
        min_val = root->val;
    }
    // left
    ret += dfs(root->left, min_val);
    // right
    ret += dfs(root->right, min_val);

    return ret;
}

class Solution {
   public:
    int goodNodes(TreeNode *root) {
        int answer = dfs(root, min_val);
        return answer;
    }
};