#pragma once 
#include<vector>
#include<cassert>
#include <stdexcept>
#include<algorithm>
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
    void print_inorder(TreeNode<T>* root) {
        if (root == nullptr)
            return;
        print_inorder(root->left); 
        cout << root->data << " "; 
        print_inorder(root->right); 
    };
    void print_postorder(TreeNode<T>* root) {
        if (root == nullptr)
            return;
        print_postorder(root->left);
        print_postorder(root->right);
        cout << root->data << " "; 
    };
    void print_preorder(TreeNode<T>* root) {
        if (root == nullptr)
            return;
        cout << root->data << " ";
        print_preorder(root->left);
        print_preorder(root->right);
    };
    T maxVal(TreeNode<T>* root) {
        if (root == nullptr)
            return INT_MIN;
        T maxLeft = maxVal(root->left);
        T maxRight = maxVal(root->right);

        return(max(root->data, max(maxLeft, maxRight)));
    };
    T minVal(TreeNode<T>* root) {
        if (root == nullptr)
            return INT_MAX;
        T minLeft = minVal(root->left);
        T minRight = minVal(root->right);

        return(min(root->data, min(minLeft, minRight)));
    }; 
    int height(TreeNode<T>* root) {
        if (root == nullptr)
            return -1; // because I start from level 0 
        int leftHeight = height(root->left); 
        int rightHeigh = height(root->right);
        return (max(leftHeight, rightHeigh) + 1); 
    };
    int leavesCount(TreeNode<T>*root) {
        if (root == nullptr)
            return 0; 
        if (root->left == nullptr && root->right == nullptr)
            return 1; 
       
        int leftLeavesCount = leavesCount(root->left); 
        int rightLeavesCount = leavesCount(root->right); 

        return(leftLeavesCount + rightLeavesCount); 
    };
    int nodeCounts(TreeNode<T>* root) {
        if (root == nullptr)
            return 0;
        int leftCount = nodeCounts(root->left);
        int rightCount = nodeCounts(root->right);

        return(1 + leftCount + rightCount); 
    };
    bool find(TreeNode<T>* root, T value) {
        if (root  == nullptr)
            return false;
        if (root->data == value)
            return true;
        bool leftSubTree = find(root->left, value); 
        bool rightSubTree = find(root->right, value); 
        return (leftSubTree || rightSubTree); 
    };
    bool isLeaveNode(Node<T>* node)
    {
        if (node == nullptr)
            return false; 
        if (node->left == nullptr && node->right == nullptr)
            return true; 
    };
    
public :
	BinaryTree(T root_val) : root(new TreeNode<T>(root_val)) {}
	void addNode(vector<T>values, vector<char>directions);
	void print_inorder(); 
	void print_postorder(); 
	void print_preorder(); 
    T maxVal(); 
    T minVal(); 
    int height();
    int leavesCount(); 
    int nodeCounts();
    bool find(T value); 
};

template<typename T>
inline void BinaryTree<T>::addNode(vector<T> values, vector<char> directions)
{
    if (values.size() != directions.size())
    {
        throw invalid_argument("Sizes must match");
    }

    TreeNode<T>* current = root;

    for (size_t i = 0; i < directions.size(); i++)
    {
        if (current == nullptr)
        {
            cout << "Error: Current node is null\n";
            return;
        }

        if (directions[i] == 'L')
        {
            if (current->left == nullptr)
            {
                current->left = new TreeNode<T>(values[i]);
            }
            else
            {
                cout << "Warning: Left child already exists\n";
            }

            current = current->left;
        }
        else if (directions[i] == 'R')
        {
            if (current->right == nullptr)
            {
                current->right = new TreeNode<T>(values[i]);
            }
            else
            {
                cout << "Warning: Right child already exists\n";
            }

            current = current->right;
        }
        else
        {
            cout << "Invalid direction (must be L or R)\n";
            return;
        }
    }
}

template<typename T>
inline void BinaryTree<T>::print_inorder()
{
    print_inorder(root); 
    cout << endl; 
}

template<typename T>
inline void BinaryTree<T>::print_postorder()
{
    print_postorder(root); 
    cout << endl; 
}

template<typename T>
inline void BinaryTree<T>::print_preorder()
{
    print_preorder(root); 
    cout << endl; 
}

template<typename T>
inline T BinaryTree<T>::maxVal()
{
    return(maxVal(root)); 
}

template<typename T>
inline T BinaryTree<T>::minVal()
{
    return (minVal(root));
}

template<typename T>
inline int BinaryTree<T>::height()
{
    return height(root);
}

template<typename T>
inline int BinaryTree<T>::leavesCount()
{
    return leavesCount(root);
}

template<typename T>
inline int BinaryTree<T>::nodeCounts()
{
    return nodeCounts(root);
}

template<typename T>
inline bool BinaryTree<T>::find(T value)
{
    return find(root , value);
}
