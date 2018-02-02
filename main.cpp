#include <iostream>
#include <map>
#include <vector>
#include "my_alloc.h"
#include "my_list.h"
#include <memory>
#include <list>

int factorial(int n)
{
int res=1;
if(n>0)
{
 for(int i=1;i<=n;i++)
  res=res*i;

}
return res;
}

template <class alloc>
void test_map(std::map<int,int,std::less<int>,alloc> &t_map)
{
 
for(int i=0;i<10;i++)
{
 t_map[i]=factorial(i);
 std::cout<<"int "<<i<<" insert "<<t_map[i]<<std::endl;
}
}
int main()
{
std::map<int,int> std_map;
test_map(std_map);
std::vector<int, map_alloc<int> > vec;
vec.push_back(1);
vec.push_back(1);
std::map<int,int, map_alloc<std::pair<const int, int> > > my_map;
//test_map(my_map);
my_list<int> l;
l.push_back(1);
return 0;

}
