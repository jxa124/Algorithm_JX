/*
��Ŀ���������ö�����A��B���ж�B�ǲ���A���ӽṹ����ps������Լ��������������һ�������ӽṹ��

˼·��
��1������A���ҵ�����B���ڵ�һ���Ľڵ�R
��2���ж��Խڵ�RΪ���ڵ�������Ƿ��������Bһ���Ľṹ
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
		if (pRoot1 == NULL || pRoot2 == NULL) return false; //�ж�����ǿ�������Ϊ����
		return isSubtree(pRoot1, pRoot2) || HasSubtree(pRoot1->left, pRoot2) || HasSubtree(pRoot1->right, pRoot2);
	}
private:
	bool isSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
		if (pRoot2 == NULL) return true; //����BΪ�գ���ȫ�������Ѿ����꣨A��B���գ�
		if (pRoot1 == NULL) return false;
		if (pRoot1->val == pRoot2->val) {
			return isSubtree(pRoot1->left, pRoot2->left) && isSubtree(pRoot1->right, pRoot2->right);
		}
		else return false;
	}
};


//===========================================================
//��A:
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
