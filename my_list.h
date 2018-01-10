#pragma once

template <class T, class alloc=std::allocator>
class my_list
{

public:
 class iterator : public std::iterator<std::forward_iterator_tag,T>
 {
   public:
	T* p;
	iterator* next, back;
	iterator(){p=NULL;next=NULL;back=NULL;}
	

};
private:
iterator it_begin, it_end;
};
