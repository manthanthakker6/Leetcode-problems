/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* createMapping(TreeNode* root, int target, unordered_map<TreeNode*, TreeNode*>& nodeToParent) {
        TreeNode* targetNode = nullptr;
        queue<TreeNode*> q;
        q.push(root);
        nodeToParent[root] = nullptr;

        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();

            // LeetCode TreeNode uses 'val', not 'data'
            if (front->val == target) {
                targetNode = front;
            }
            if (front->left) {
                nodeToParent[front->left] = front;
                q.push(front->left);
            }
            if (front->right) {
                nodeToParent[front->right] = front;
                q.push(front->right);
            }
        }
        return targetNode;
    }

    int infectTree(TreeNode* targetNode, unordered_map<TreeNode*, TreeNode*>& nodeToParent) {
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;

        q.push(targetNode);
        visited[targetNode] = true;

        int time = 0;

        while (!q.empty()) {
            int size = q.size();
            bool flag = false;

            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();
                q.pop();

                // 1. Infect left child
                if (front->left && !visited[front->left]) {
                    flag = true;
                    visited[front->left] = true;
                    q.push(front->left);
                }

                // 2. Infect right child
                if (front->right && !visited[front->right]) {
                    flag = true;
                    visited[front->right] = true;
                    q.push(front->right);
                }

                // 3. Infect parent
                if (nodeToParent[front] && !visited[nodeToParent[front]]) {
                    flag = true;
                    visited[nodeToParent[front]] = true;
                    q.push(nodeToParent[front]);
                }
            }

            if (flag) {
                time++;
            }
        }
        return time;
    }

    int amountOfTime(TreeNode* root, int start) {
        if (!root) {
            return 0;
        }

        // Use unordered_map for O(1) average lookup time
        unordered_map<TreeNode*, TreeNode*> nodeToParent;
        TreeNode* targetNode = createMapping(root, start, nodeToParent);

        int ans = infectTree(targetNode, nodeToParent);
        return ans;
    }
};