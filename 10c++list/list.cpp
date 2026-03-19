template<class T>
struct ListNode
{
	ListNode(const T& data = T())
		:_next(nullptr)
		,_prev(nullptr)
		,_data(data)
	ListNode<T>* _next;
	ListNode<T>* _prev;
	T _data;
};

template<class T>
class list
{
	typedef ListNode<T>*  Node;
public:
	list()
	:_head(nullptr)
	{}


private:
	Node _head;
};