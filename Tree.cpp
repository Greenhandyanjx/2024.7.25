#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;
struct TreeNode {
public:
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode():left(NULL),right(NULL){}
	TreeNode(int val):left(NULL),right(NULL),val(val){}
};
class Solution {
public:
	TreeNode* pre = NULL;
	void traversal(TreeNode* root) {
		if (root == NULL)return;
		traversal(root->right);
		if (pre != NULL) {
			root->val += pre->val;
		}
		pre = root;
		traversal(root->left);
		return;
	}
	TreeNode* convertBST(TreeNode* root) {
		traversal(root);
		return root;
	}
};
//class Solution {
//public:
//	TreeNode* traversal(vector<int>& nums, int left, int right) {
//		if (left > right)return NULL;
//		int mid = (left + right) / 2;
//		TreeNode* root = new TreeNode(nums[mid]);
//		root->left = traversal(nums, left, mid - 1);
//		root->right = traversal(nums, mid+1, right);
//		return root;
//	}
//	TreeNode* sortedArrayToBST(vector<int>& nums) {
//		return traversal(nums, 0, nums.size() - 1);
//	}
//};
//class Solution {
//public:
//	TreeNode* trimBST(TreeNode* root, int low, int high) {
//		if (root == NULL)return NULL;
//		if (root->val < low) {
//			TreeNode* right = trimBST(root->right, low, high);
//			delete root;
//			return right;
//		}
//		if (root->val > high) {
//			TreeNode* left = trimBST(root->left, low, high);
//			delete root;
//			return left;
//		}
//		root->left = trimBST(root->left, low, high);
//		root->right = trimBST(root->right, low, high);
//		return root;
//	}
//};
//class Solution {
//public:
//	TreeNode* deleteNode(TreeNode* root, int key) {
//		if (root == NULL)return NULL;
//		if (root->val == key) {
//			if (root->left == NULL && root->right == NULL)
//			{
//				delete root;
//				return NULL;
//			}
//			if (root->left != NULL && root->right == NULL) {
//				TreeNode* node = root->left;
//				delete root;
//				return node;
//			}
//			if (root->left == NULL && root->right != NULL) {
//				TreeNode* node = root->right;
//				delete root;
//				return node;
//			}
//			if (root->left != NULL && root->right != NULL) {
//				TreeNode* cur = root->right;
//				while (cur->left != NULL) {
//					cur = cur->left;
//				}
//				cur->left = root->left;
//				TreeNode* node = root->right;
//				delete root;
//				return node;
//			}
//		}
//		if (root->val < key) {
//			root->right = deleteNode(root->right, key);
//		}
//		if (root->val > key) {
//			root->left = deleteNode(root->left, key);
//		}
//		return root;
//	}
//};