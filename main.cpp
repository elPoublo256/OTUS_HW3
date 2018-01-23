#include <iostream>
#include <map>
#include "my_alloc.h"
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


int main()
{
std::map<int,int> std_map;
for(int i=0;i<10;i++)
{
 std_map[i]=factorial(i);
 std::cout<<"int "<<i<<" insert"<<std_map[i]<<std::endl;
}

std::map<int,int,map_alloc<std::pair< int, int>>> my_alloc_map;
 
return 0;

}
