#pragma once

using namespace std;

template<class T, int size=1>
class my_alloc
{
privare:
int mem_size;
T* mem_spase;
public:

using value_tyoe = T;
my_alloc(){
mem_size=size;
 }
~my_alloc(){}
 
T* allocate(std::size_t n);
void deallocate(T* p, std::size_t n);

template <typename U, typename .. Args>
void construct(T* p, Args&& ... args)
{new((void *)p) U(std::forward<Args>(args) ...);}
void destroy(T* p){p->~T()}




};
template <class T>
T* my_alloc::allocate(std::size_t n)
{
 auto p=std::malloc(n*sizeof(T));
 if(!p)
   throw std::bad_alloc();
return reinterpret_cast<T *>(p);
}

template <class T>
void my_alloc::deallocate(T* p,std::size_t n)
{
std::free(p);
}

