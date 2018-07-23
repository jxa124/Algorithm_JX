/*
题目：输入两棵二叉树A，B，判断B是不是A的子结构。（ps：我们约定空树不是任意一个树的子结构）

思路：
（1）在树A中找到和树B根节点一样的节点R
（2）判断以节点R为根节点的子树是否包含和树B一样的结构
*/
#include <iostream>

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
	bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
	{
		if (pRoot1 == NULL || pRoot2 == NULL) return false; //判断如果是空树，则不为子树
		return isSubtree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
	}
private:
	bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (pRoot2 == NULL) return true; //当树B为空，则全部子树已经找完（A与B都空）
		if (pRoot1 == NULL) return false;
		if (pRoot1->val == pRoot2->val) {
			return isSubtree(pRoot1->left, pRoot2->left) && isSubtree(pRoot1->right, pRoot2->right);
		}
		else return false;
	}
};


//===========================================================
//树A:
void CreateBinaryTree(TreeNode * T)
{

	char data;
	cin >> data;
	if (data == '#')
		T = NULL;
	else
	{
		T = new TreeNode(data);
		T->val = data;

		CreateBinaryTree(T->left);
		CreateBinaryTree(T->right);
	}
}

int main() {
	TreeNode * root1 = new TreeNode(8);
	CreateBinaryTree(root1);
	TreeNode * root2 = new TreeNode(8);
	CreateBinaryTree(root2);
	Solution s; 
	cout << s.HasSubtree(root1, root2) << endl;	
}
