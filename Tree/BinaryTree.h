#pragma once 
#include<vector>
#include<cassert>
#include<exception>

using namespace std; 
template<typename T>
class TreeNode
{
public : 
	T data; 
	TreeNode<T>* left;
	TreeNode<T>* right;
	TreeNode(T number) : data(number) , left(nullptr) , right(nullptr) {}
};

template<typename T>
class BinaryTree {
private :
	TreeNode<T>* root; 
public :
	BinaryTree(T root_val) : root(new TreeNode<T>(root_val)) {}
	void addNode(vector<T>values, vector<char>directions);
	void print_inorder(TreeNode<T>r); 
	void print_postorder(TreeNode<T>r); 
	void print_preorder(TreeNode<T>r); 
};

template<typename T>
inline void BinaryTree<T>::addNode(vector<T> values, vector<char> directions)
{
	if(values.size()!=directions.size())
	{
		throw _Xinvalid_argument("Should the sizes to be matched")
	}
	TreeNode<T>*current = root; 
	for (size_t i = 0; i < directions.size();i++)
	{
		try {
			if (current == nullptr) {
				throw _Xruntime_error("Current Node is null"); 
			}
			if (directions[i] == 'L')
			{
				if (current != nullptr)
				{
					current->left = new TreeNode<int>(values[i]);
				}
				else {
					throw _Xruntime_error("Left child already exists!"); 
				}
				current = current->left; 
			}
			else
			{
				if (directions[i] == 'R')
				{
					if (current != nullptr)
					{
						current->right = new TreeNode<int>(values[i]);
					}
					else
					{
						throw _Xruntime_error("Right child already exists!");
					}
					current = current->right;
				}
			}
		}
		catch (const exception& e)
		{
			cout << "Warning"; 
			if (current != nullptr)
			{
				if (directions[i] == 'L')
				{
					current = current->left;
				}
				else if (directions[i] == 'R')
				{
					current = current->right;
				}
			}
		}
	}
}

template<typename T>
inline void BinaryTree<T>::print_inorder(TreeNode<T> r)
{
	if (r == nullptr)
		return;

	print_inorder(r->left); 
	cout << r->data << " "; 
	print_inorder(r->right);
}
