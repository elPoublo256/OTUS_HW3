#pragma once
#include <memory>
#include <iostream>
#include  <cstdlib>
template <class T>
class map_alloc : public std::allocator<T>  
{
public:
 template <class U > struct rebind { typedef map_alloc<U> other;};
 typedef unsigned int size_type;
 typedef unsigned int difference_type;
 typedef T value_type;          
 typedef T* pointer;            
 typedef T& reference;          
 typedef const T* const_pointer;
 typedef const T& const_reference;
public:
 map_alloc();
 map_alloc(const map_alloc &cop){std::cout<<"copy allocator"<<std::endl;}
~map_alloc(){free(main_pointer_v);} 
 T* allocate(int n);
 void deallocate(T* p, std::size_t n){}
 void construct(T* p, const T& val){ new((void *)p) T(val); }
 void destroy(T* p){((T*)p)->~T();}
 void* main_pointer_v;
 T* main_pointer;
 T* move_pointer;
};

 template <class T>                           
 map_alloc<T>::map_alloc()
{
 main_pointer_v=malloc(10*sizeof(T));
 main_pointer=reinterpret_cast<T *>(main_pointer_v);
 move_pointer=main_pointer;
std::cout<<"FINISH"<<std::endl;
}
                      
template <class T>
T* map_alloc<T>::allocate(int n)
{
 //std::cout<<"constructor allocator"<<std::endl;
 T* p=move_pointer;
 move_pointer+=n;
return p;
}
