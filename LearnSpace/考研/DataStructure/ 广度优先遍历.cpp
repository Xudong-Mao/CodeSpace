// 二叉树实现广度优先遍历
// 广度优先遍历：按层遍历二叉树，每层从左到右遍历
# include <iostream>
# include <queue>
using namespace std;

// 定义二叉树节点
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 广度优先遍历
void levelOrder(TreeNode *root) {
    if (root == NULL) return;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();
        cout << node->val << " ";
        if (node->left != NULL) q.push(node->left);
        if (node->right != NULL) q.push(node->right);
    }
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
    levelOrder(root);
    return 0;
}
