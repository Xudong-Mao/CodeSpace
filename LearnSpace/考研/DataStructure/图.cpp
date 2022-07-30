// 图广度优先算法
// 图的广度优先算法是指，从一个顶点出发，沿着图的边一直走到最后一个顶点，然后把这个顶点的所有邻接点都访问一遍，这样就能访问所有的顶点。
// 广度优先算法的基本思想是，每次从一个顶点出发，沿着图的边一直走到最后一个顶点，然后把这个顶点的所有邻接点都访问一遍，这样就能访问所有的顶点。
// 广度优先算法的基本步骤是：
// 1. 创建一个队列，将起始顶点加入队列。
// 2. 当队列不为空时，取出队列的第一个顶点，访问它，并将它的所有邻接点加入队列。
// 3. 重复步骤2，直到队列为空。
// # include <iostream>
// # include <queue>
// using namespace std;

// // 图节点
// struct GraphNode {
//     int val;
//     vector<GraphNode *> neighbors;
//     GraphNode(int x) : val(x) {}
// };

// // 广度优先算法
// void bfs(GraphNode *root) {
//     if (root == NULL) return;
//     queue<GraphNode *> q;
//     q.push(root);
//     while (!q.empty()) {
//         GraphNode *node = q.front();
//         cout << node->val << " ";
//         q.pop();
//         for (int i = 0; i < node->neighbors.size(); i++) {
//             q.push(node->neighbors[i]);
//         }
//     }
// }

// // 测试
// int main() {
//     GraphNode *root = new GraphNode(1);
//     root->neighbors.push_back(new GraphNode(2));
//     root->neighbors.push_back(new GraphNode(3));
//     root->neighbors[0]->neighbors.push_back(new GraphNode(4));
//     root->neighbors[0]->neighbors.push_back(new GraphNode(5));
//     root->neighbors[1]->neighbors.push_back(new GraphNode(6));
//     root->neighbors[1]->neighbors.push_back(new GraphNode(7));
//     bfs(root);
//     return 0;
// }

// 深度优先算法
// 深度优先算法是指，从一个顶点出发，沿着图的边一直走到最后一个顶点，然后把这个顶点的所有邻接点都访问一遍，这样就能访问所有的顶点。
// 深度优先算法的基本思想是，每次从一个顶点出发，沿着图的边一直走到最后一个顶点，然后把这个顶点的所有邻接点都访问一遍，这样就能访问所有的顶点。
// 深度优先算法的基本步骤是：
// 1. 创建一个队列，将起始顶点加入队列。
// 2. 当队列不为空时，取出队列的第一个顶点，访问它，并将它的所有邻接点加入队列。
// 3. 重复步骤2，直到队列为空。
# include <iostream>
# include <stack>
using namespace std;

// 图节点
struct GraphNode {
    int val;
    vector<GraphNode *> neighbors;
    GraphNode(int x) : val(x) {}
};

// 深度优先算法(有点问题不能运行)
void dfs(GraphNode *root) {
    if (root == NULL) return;
    stack<GraphNode *> s;
    s.push(root);
    while (!s.empty()) {
        GraphNode *node = s.top();
        cout << node->val << " ";
        s.pop();
        for (int i = 0; i < node->neighbors.size(); i++) {
            s.push(node->neighbors[i]);
        }
    }
}

//  测试
int main() {
    GraphNode *root = new GraphNode(1);
    root->neighbors.push_back(new GraphNode(2));
    root->neighbors.push_back(new GraphNode(3));
    root->neighbors[0]->neighbors.push_back(new GraphNode(4));
    root->neighbors[0]->neighbors.push_back(new GraphNode(5));
    root->neighbors[1]->neighbors.push_back(new GraphNode(6));
    root->neighbors[1]->neighbors.push_back(new GraphNode(7));
    dfs(root);
    return 0;
}
