#define BOOST_TEST_MODULE  const unit_boost_test
#include <boost/test/unit_test.hpp>
#include "my_alloc.h"
#include "my_list.h"

BOOST_AUTO_TEST_SUITE(unit_boost_test)

BOOST_AUTO_TEST_CASE(my_list_test)
{
BOOST_CHECK(1==1);
}

}
