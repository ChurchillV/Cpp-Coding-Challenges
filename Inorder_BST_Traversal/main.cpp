#include <iostream>
#include <vector>
#include <functional>


// Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
    public:
        std::vector<int> inorderTraversal(TreeNode* root) {
            std::vector<int> output;
            std::function<void(TreeNode*)> dfs = [&](TreeNode* root) {
                if(!root) {
                    return;
                }
                dfs(root -> left);
                output.push_back(root->val);
                dfs(root -> right);
            };

            dfs(root);
            return output;
        }
    };

void printVector(std::vector<int> testVector) {
    for (int i = 0; i <= testVector.size(); i++) {
        std::cout << "\n" << testVector[i];
    }
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution* solution = new Solution();
    std::vector<int> inorder = solution->inorderTraversal(root);
    printVector(inorder);
    return 0;
}