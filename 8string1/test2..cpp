
template<class iterator, class Ref, class Ptr>
struct StringIterator
{
	iterator _it;
	StringIterator(iterator it)
		:_it(it)
	{
	}

	Ref operator*()  // Ref就是char
	{
		return *_it;
	}

	Ptr operator->()
	{
		return &(*_it);
	}


};