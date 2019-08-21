#include <iostream>
#include <unordered_map>
#include <tuple>
#include <vector>
using namespace std;


struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};

class Solution {
public:

  TreeNode* Convert(TreeNode* pRootOfTree)
  {
    TreeNode* h = NULL;
    helper(pRootOfTree, h);

    while (pRootOfTree->left != NULL)pRootOfTree = pRootOfTree->left;
    return pRootOfTree;
  }

  void helper(TreeNode* node, TreeNode* &h){
    if(node== NULL)return;
    helper(node->left, h);
    if(h== NULL){
      h = node;
    }else{
      node->left = h;
      h->right = node;
      h = node;
    }
    helper(node->right, h);
  }

};

int main() {
  TreeNode a(234);
  TreeNode b(123);
  TreeNode c(456);
  TreeNode d(66);
  TreeNode e(125);
  a.left = &b;
  a.right = &c;
  b.left = &d;
  b.right = &e;
  Solution s;
  cout << s.Convert(&a)->right->right->right->val << endl;

  return 0;
