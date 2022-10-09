Approach #1: Recursive Method

The recursive Approach is the straight forward and classical approach.

If the current node is not empty :
1. Traverse the left subtree
2. Traverse the right subtree
3.  Print the node

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        postorder(root, nodes);
        return nodes;
    }
private:
    void postorder(TreeNode* root, vector<int>& nodes) {
        if (!root) {
            return;
        }
        postorder(root -> left, nodes);
        postorder(root -> right, nodes);
        nodes.push_back(root -> val);
    }
};
