# include <stab.h>
// 二叉树的定义
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 创建二叉树
TreeNode* createTree(int* arr, int n) {
    if (n == 0) return NULL;
    TreeNode* root = new TreeNode(arr[0]);
    for (int i = 1; i < n; i++) {
        TreeNode* cur = root;
        while (cur) {
            if (arr[i] < cur->val) {
                if (cur->left) cur = cur->left;
                else {
                    cur->left = new TreeNode(arr[i]);
                    break;
                }
            } else {
                if (cur->right) cur = cur->right;
                else {
                    cur->right = new TreeNode(arr[i]);
                    break;
                }
            }
        }
    }
    return root;
}
// 先序遍历
void preOrder(TreeNode* root) {
    if (root == NULL) return;
    cout << root->val << " ";
    preOrder(root->left);
    preOrder(root->right);
}
// 中序遍历
void inOrder(TreeNode* root) {
    if (root == NULL) return;
    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}
// 后序遍历
void postOrder(TreeNode* root) {
    if (root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << " ";
}
// 层序遍历
void levelOrder(TreeNode* root) {
    if (root == NULL) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* cur = q.front();
        q.pop();
        cout << cur->val << " ";
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
}
// 求二叉树的深度
int depth(TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + max(depth(root->left), depth(root->right));
}
// 求二叉树的宽度
int width(TreeNode* root) {
    if (root == NULL) return 0;
    int res = 0;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        res = max(res, n);
        while (n--) {
            TreeNode* cur = q.front();
            q.pop();
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
    }
    return res;
}
// 求二叉树的叶子节点数
int leafNum(TreeNode* root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return leafNum(root->left) + leafNum(root->right);
}
// 求二叉树的节点数
int nodeNum(TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + nodeNum(root->left) + nodeNum(root->right);
}
// 求二叉树的高度
int height(TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + max(height(root->left), height(root->right));
}
// 测试二叉树
void testTree() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
    int n = sizeof(arr) / sizeof(int);
    TreeNode* root = createTree(arr, n);
    cout << "先序遍历: ";
    preOrder(root);
    cout << endl;
    cout << "中序遍历: ";
    inOrder(root);
    cout << endl;
    cout << "后序遍历: ";
    postOrder(root);
    cout << endl;
    cout << "层序遍历: ";
    levelOrder(root);
    cout << endl;
    cout << "深度: " << depth(root) << endl;
    cout << "宽度: " << width(root) << endl;
    cout << "叶子节点数: " << leafNum(root) << endl;
    cout << "节点数: " << nodeNum(root) << endl;
    cout << "高度: " << height(root) << endl;
}

