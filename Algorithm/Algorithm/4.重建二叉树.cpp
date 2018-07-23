/*
��Ŀ������ĳ��������ǰ���������������Ľ�������ؽ����ö����������������ǰ���������������Ľ���ж������ظ������֡�
��������ǰ���������{1,2,4,7,3,5,6,8}�������������{4,7,2,1,5,3,8,6}�����ؽ�������������

˼·��
��1��������׸���Ϊ���ڵ㣬Ȼ��ݹ������������
��2��������������ҵ�����ڵ���ͬ�ĵ�i�����������������Ϊ��left��vinStart, i-1����right��i+1, vinEnd��
��3���������������Ҫ�������������������Ĵ�С�����㣬�����������left��preStart+1, i-1-vinStart+preStart+1����right��preStart-vinStart+i+1,preEnd��
��4��������start��end��ʱ�����أ�
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
//��ӡ�����������������ӡ��
void printTree(TreeNode *T, int n)
{
	if (!T)return;
	printTree(T->right, n + 2);
	space(n);
	cout << T->val << endl;
	printTree(T->left, n + 2);
}

//=========== ���Դ��� =============
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