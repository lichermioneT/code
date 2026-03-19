#include <iostream>
#include <vector>
using namespace std;

template<class T>
struct HashNode
{
	T _data;
	HashNode<T>* _next;
};

template<class K, class T, class KeyOft>
class HashTable
{
	typedef HashNode<T> Node;

public:
	bool insert(const T& data)
	{
		KeyOfT koft;
		size_t index = koft(data) % _table.size();

		Node* cur = _table[index];
		while (cur != nullptr)
		{
			koft(cur->_data)
		}
	}

private:
	vector<Node*> _table;
	size_t _num = 0;
};