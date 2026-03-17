#include <iostream>
#include <utility>
using namespace std;
enum color{Red, Black};

// 红黑树的Node
template<class K, class V>
struct RBTreeNode
{
	RBTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_kv(kv)
		,_col(Red)
	{ }
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	pair<K,V> _kv;
	color _col;
};

template<class K, class V>
class RBTree
{
typedef RBTreeNode<K, V> Node;
public:
	RBTree()
	  :_root(nullptr)
	{}

public:
	bool insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			// 
			_root = new Node(kv);   
			_root->_col = Black;
			return true;
		}

// 按照搜索树进行插入，
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur != nullptr)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		if (parent->_kv.first > cur->_kv.first)
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}

// 新插入的节点一定是红色的方便调整，黑色的话，每一条路径的黑色数量一致，太麻烦了
		cur->_col = Red; 

		// 开始调整
		// 父亲存在
		while (parent != nullptr && parent->_col == Red)
		{
			Node* grandfather = parent->_parent;

			if (grandfather->_left == parent)
			{
				Node* uncle = grandfather->_right;
				if (uncle != nullptr && uncle->_col == Red)
				{
					parent->_col = uncle->_col = Black;
					grandfather->_col = Red;

					// 继续往上处理
					cur = grandfather;
					parent = grandfather->_parent;
				}
				else
				{
					if (cur == parent->_right)
					{
						RotateL(parent);
						std::swap(cur, parent);
					}

					RotateR(grandfather);
					grandfather->_col = Red;
					parent->_col = Black;

					break;
				}
			}
			else
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == Red)
				{
					parent->_col = uncle->_col = Black;
					grandfather->_col = Red;

					cur = grandfather; // 继续往上更新了
					parent = cur->_parent;
				}
				else // 看你是哪一种旋转了 
				{
					if (cur == parent->_left)
					{
						RotateR(parent);
						swap(parent, cur);
					}
					RotateL(grandfather);

					grandfather->_col = Red;
					parent->_col = Black;
					break;
				}
			}

			_root->_col = Black;  // 确保根为黑
			return true;
		}
	}

	public:
		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}

private:
// 左单旋，左边高的按下来了的
//  1           2
//   2        1   3
//     3
	void RotateL(Node* parent)
	{
		Node* pparent = parent->_parent;
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL != nullptr)
			subRL->_parent = parent;

		subR->_left = parent;
		parent->_parent = subR;


		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (pparent->_left == parent)
			{
				pparent->_left = subR;
			}
			else
			{
				pparent->_right = subR;
			}
			subR->_parent = pparent;
		}
	}
//  右单旋转的了	
	void RotateR(Node* parent)
	{
		Node* pparent = parent->_parent;
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR != nullptr)
			subLR->_parent = parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (_root == parent)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (parent == pparent->_left)
			{
				pparent->_left = subL;
			}
			else
			{
				pparent->_right = subL;
			}
			
			subL->_parent = pparent;
		}

	}
private:
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

private:
	Node* _root;

};
void test()
{
	
	 int a[] = {16, 3, 7, 11, 9, 26, 18, 14, 15};
	 
	//int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };

	RBTree<int, int> t;
	for (auto e : a)
	{
		t.insert(make_pair(e, e));
	}
	t.InOrder();
}




int main()
{
	test();


	return 0;
}