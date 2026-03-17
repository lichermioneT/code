#include<iostream>
#include <ctime>

using namespace std;
template<class K>
struct BSTreeNode
{
	BSTreeNode(const K& k)
		:_left(nullptr)
		,_right(nullptr)
		,_key(k)
	{}
	BSTreeNode* _left;
	BSTreeNode* _right;
	K _key;
};

template<class K>
class BSTree
{
typedef BSTreeNode<K> Node;
public:
	BSTree()
	  :_root(nullptr)
	{}

	bool insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur != nullptr)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(key);
		if (parent->_key > cur->_key)
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}
		return true;
	}

public:
	bool erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;

		while (cur != nullptr)
		{
			if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if(cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;

			}
			else
			{
				if (cur->_left == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}
					delete cur;
				}
				else if(cur->_right == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else
					{
						if (cur == parent->_left)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
					}
					delete cur;
				}
				else
				{
					Node* rightMinParent = cur;
					Node* rightMin = cur->_right;
					while (rightMin ->_left != nullptr)
					{
						rightMinParent = rightMin;
						rightMin = rightMin->_left;
					}

					cur->_key = rightMin->_key;

					if (rightMin == rightMinParent->_left)
					{
						rightMinParent->_left = rightMin->_right; // 这是找到了右边最小的，去变量出来的。
					}
					else
					{
						rightMinParent->_right = rightMin->_right;   // 循环没有进去，直接就是rim
					}
					
					delete rightMin;
				}
				return true;
			}

		}
		return false;


	}

public:
	void inOrder()
	{
		_Inorder(_root);
	}
private:
	void _Inorder(Node* root)
	{
		if (root == nullptr)
			return;
		_Inorder(root->_left);
		cout << root->_key << " ";
		_Inorder(root->_right);
	}

private:
	Node* _root;
};

void test()
{	
	BSTree<int> t;
	std::srand(static_cast<unsigned>(std::time(nullptr))); // 种种子

	for (int i = 20; i >= 0; --i)
	{
		t.insert(i);
	}

	for (int i = 20; i >= 0; --i)
	{
		t.inOrder();
		cout << endl;
		t.erase(i);
	}

	

}

int main()
{

	test();


	return 0;
}