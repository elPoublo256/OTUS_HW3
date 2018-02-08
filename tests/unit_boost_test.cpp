#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE test_test

#include <boost/test/unit_test.hpp>
#include "../my_alloc.h"
#include "../my_list.h"
#include <map>
#include <vector>

//#define BOOST_TEST_MODULE test_test


BOOST_AUTO_TEST_CASE(test_test)
{
  std::vector<int> std_vec;
  std::vector<int,map_alloc<int> > vec;
  std::list<int> std_list;
  my_list<int> m_list; 
  for(int i=0;i<9;i++)
  {
    std_vec.push_back(i);
    vec.push_back(i);
    std_list.push_back(i);
    m_list.push_back(i);
 
  }
//  std::map<int,int, map_alloc<std::pair<const int,int> > my_map;
  BOOST_CHECK_EQUAL_COLLECTIONS(std_vec.begin(), std_vec.end(),
  vec.begin(), vec.end());
// BOOST_CHECK(true);
  BOOST_CHECK_EQUAL_COLLECTIONS(std_list.begin(), std_list.end(),
  m_list.begin(), m_list.end());
}

