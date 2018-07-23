/*
题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
例如输入前序遍历序列{1,2,4,7,3,5,6,8}和中序遍历序列{4,7,2,1,5,3,8,6}，则重建二叉树并返回

思路：
（1）先序的首个数为根节点，然后递归的找左右子树
（2）中序的索引：找到与根节点相同的第i个数，则中序的索引为：left（vinStart, i-1）、right（i+1, vinEnd）
（3）先序的索引：需要计算中序中左右子树的大小来计算，先序的索引：left（preStart+1, i-1-vinStart+preStart+1）、right（preStart-vinStart+i+1,preEnd）
（4）当索引start比end大时，返回；
*/
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode * reConstructBinaryTree(vector<int> pre, vector<int> vin) {
		int length = pre.size();
		TreeNode * root = reTree(pre, 0, length-1, vin, 0, length-1);
		return root;
	}
private:
	TreeNode * reTree(vector<int> pre, int preStart, int preEnd, vector<int> vin, int vinStart, int vinEnd) {
		if (preStart>preEnd || vinStart>vinEnd) {
			return NULL;
		}
		TreeNode *root = new TreeNode(pre[preStart]);
		
		for (int i = vinStart; i <= vinEnd;  i++) {
			if (vin[i] == pre[preStart]) {
				root->left = reTree(pre, preStart+1, i - vinStart + preStart, vin, vinStart, i-1 );
				root->right = reTree(pre, i - vinStart + preStart+1, preEnd, vin, i+1, vinEnd);
				   break;
			}
		}

		return root;
	}
};




void space(int n)
{
	for (int i = 0; i<n; i++)
		cout << ' ';
}
//打印二叉树（按层遍历打印）
void printTree(TreeNode *T, int n)
{
	if (!T)return;
	printTree(T->right, n + 2);
	space(n);
	cout << T->val << endl;
	printTree(T->left, n + 2);
}

//=========== 测试代码 =============
void Test(vector<int> pre, vector<int> vin)
{

	int length = pre.size();
	printf("The preorder sequence is: ");
	for (int i = 0; i < length; ++i)
		printf("%d ", pre[i]);
	printf("\n");

	printf("The inorder sequence is: ");
	for (int i = 0; i < length; ++i)
		printf("%d ", vin[i]);
	printf("\n");

		Solution s;
		TreeNode * root = s.reConstructBinaryTree(pre, vin);
		printTree(root, 0);

}

void Test1()
{
	vector<int> pre = { 1, 2, 4, 7, 3, 5, 6, 8 };
	vector<int> vin = { 4, 7, 2, 1, 5, 3, 8, 6 };

	Test( pre, vin);
}

/*int main(int argc, char* argv[])
{
	Test1();
	return 0;
}*/