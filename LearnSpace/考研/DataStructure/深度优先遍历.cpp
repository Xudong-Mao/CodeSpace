// 二叉树实现深度优先遍历
// 思路：
// 1. 先序遍历：根左右
// 2. 中序遍历：左根右
// 3. 后序遍历：左右根
// 4. 层序遍历：按层遍历二叉树，每层从左到右遍历
// 5. 广度优先遍历：按层遍历二叉树，每层从左到右遍历
// 6. 深度优先遍历：按层遍历二叉树，每层从左到右遍历
# include <iostream>
# include <stack>
using namespace std;

// 定义二叉树节点
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 深度优先遍历
void preOrder(TreeNode *root) {
    if (root == NULL) return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}

// 测试
int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    preOrder(root);
    return 0;
}
