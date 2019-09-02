class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
        bool res = true;
        getd(pRoot, res);
        return res;
    }
    int getd(TreeNode* node, bool& res){
        if(node == NULL)return 0;
        int lh = getd(node->left, res);
        int rh = getd(node->right, res);
        if(abs(lh-rh)>1)res = false;
        return max(lh, rh)+1;
    }
};