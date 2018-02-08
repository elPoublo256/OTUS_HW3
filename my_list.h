#pragma once
#include <memory>
#include <iterator>
template <class T, class Alloc=std::allocator<T> >
class my_list
{

public:
 class my_iterator : public std::iterator<std::forward_iterator_tag,T>
 {
   public:
		typedef my_iterator self_type;
                typedef T value_type;
                typedef T& reference;
                typedef T* pointer;
                typedef std::forward_iterator_tag iterator_category;
                typedef int difference_type;
	T* p;
        my_iterator* next;
	my_iterator* back;
	my_iterator(){p=NULL; next=NULL; back=NULL;}
	my_iterator(my_iterator* n, my_iterator* b, T* prt){next=n; back=b; p=prt;}
	my_iterator(const my_iterator &copy){p=copy.p; next=copy.next; back=copy.back;}
	my_iterator operator ++ (){this=next; return this;}
	my_iterator operator -- (){this=back; return this;}
	bool operator == (const my_iterator &it)
	{return (p==it.p||next==it.next||back==it.back);}

	bool operator != (const my_iterator &it)
	{return !(p==it.p||next==it.next||back==it.back);}

	T* &operator * () {return p;}
};
private:
T* chunk;
Alloc alloc;
my_iterator bbegin;
my_iterator eend;
int ssize;
int reserved_size;
public:
my_list();
my_list(const int &n);
my_list(const my_list &copy);

public:
my_iterator begin(){return bbegin;}
my_iterator end(){return eend;}

public:
void push_back(const T &val);
void push_front(const T &val);
T pop_front(); 
T pop_back();
int size(){return ssize;}
bool is_empty(){return ssize==0;}
};

template <class T, class Alloc>
my_list<T, Alloc>::my_list()
{
chunk=NULL;
ssize=0;
bbegin.next=&eend;
eend.back=&bbegin;
}

template <class T, class Alloc>
my_list<T, Alloc>::my_list(const int &n) : my_list()
{
chunk=alloc.allocate;
eend.p=chunk+(n+1);
reserved_size=n;
}

template <class T, class Alloc>
my_list<T, Alloc>::my_list(const my_list<T,Alloc> &copy)
{
ssize=copy.ssize;
chunk=copy.chunk;
reserved_size=copy.reserved_siz;
bbegin=copy.begin();
eend=copy.end();
}

template <class T, class Alloc>
void my_list<T, Alloc>::push_back(const T &val)
{
  T* prt=alloc.allocate(1);
  alloc.construct(prt,val);
  auto new_it=new my_iterator();
  new_it->p=prt;
  new_it->next=&eend;
  new_it->back=eend.back;
  eend.back->next=new_it;
  eend.back=new_it;
  ssize++;
}

template <class T, class Alloc>
void my_list<T, Alloc>::push_front(const T &val)
{
  T* prt=alloc.allocate(1);
  alloc.construct(prt,val);
  my_iterator new_it;
  new_it.p=prt;
  bbegin.back=&new_it;
  new_it.next=&bbegin;
  bbegin=new_it;
  
  ssize++;
}

template <class T, class Alloc>
T  my_list<T, Alloc>::pop_front()
{
 T res=*bbegin;
 T* p_res=bbegin.p;
 bbegin++;
 alloc.distroy(p_res);
 alloc.deallocate(p_res);
 return res; 
}

template <class T, class Alloc>
T  my_list<T, Alloc>::pop_back()
{
 T* p_res=eend.back->p;
 T res=*p_res;
 alloc.distroy(p_res);
 alloc.deallocate(p_res);
 eend--;
 eend.next=NULL;
 return res;
}


