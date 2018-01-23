#pragma once

using namespace std;
template <class T, int size_mem=10>
class map_alloc
{
public:
 typedef T value_type;
 typedef T* pointer;
 typedef T& reference;
 typedef const T* const_pointer;
 typedef const T& const_reference;
public:
 map_alloc();
 ~map_alloc(){free(main_pointer_v);}
 T* allocate(int n);
 void deallocate(T* p, std::size_t n);
 void construct(T* p, const T& val){new((void *)p) T(val);}
 void distroy(T* p){((T*)p)->~T();}
private:
 void* main_pointer_v;
 T* main_pointer;
 T* move_pointer;
};

 template <class T, int size_mem>                           
 map_alloc<T, size_mem>::map_alloc()
{
 main_pointer_v=malloc(size_mem*sizeof(T));
 main_pointer=reinterpret_cast<T *>(main_pointer_v);
 move_pointer=main_pointer;
}
                      
template <class T, int size_mem>
T* map_alloc<T, size_mem>::allocate(int n)
{
 auto p=move_pointer;
 move_pointer+=n;
return p;
}
