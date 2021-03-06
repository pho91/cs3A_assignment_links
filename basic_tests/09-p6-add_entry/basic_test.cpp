#include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>

#include "../../includes/add_entry/add_entry.h"

using namespace std;


bool test_basic_add_entry(bool debug = false){
  cout << "MINIMUM_CAPACITY: " << MINIMUM_CAPACITY << endl;
  int capacity = MINIMUM_CAPACITY;
  int *arr = allocate<int>(capacity);
  int size = 0;
  for (int i = 0; i < 10; i++){
    cout << "adding [" << i << "] ";
    arr = add_entry(arr, i, size, capacity);
    print_list(arr, size, capacity);
  }

  int* index = search_entry(arr, 4, size);
  cout << endl
       << "search_entry returned: " << *index << endl;

  arr = remove_entry(arr, 4, size, capacity);
  cout << "removed [4]: ";
  print_list(arr, size, capacity);
  cout << endl
       << endl;

  for (int i = size - 1; i >= 0; i--)
  {
    int item;
    arr = remove_last_entry(arr, item, size, capacity);
    cout << "removed: [" << item << "] ";
    print_list(arr, size, capacity);
  }
    cout << "----- end of function --------" << endl;

  return true;
}
//----- ----- ----- ----- ----- ----- ----- ----- ----- ----- 
//Lord help me! 
bool debug = false;
//----- ----- ----- ----- ----- ----- ----- ----- ----- ----- 


TEST(TEST_BASIC, TestBasic){
  bool success =test_basic_add_entry(debug);
  EXPECT_EQ(success, true);
}



int main(int argc, char **argv) {
  if (argc>1){
    debug = argv[1][0]=='t';
  }
  ::testing::InitGoogleTest(&argc, argv);
  std::cout<<"\n\n---------- running basic_test ---------\n\n"<<std::endl;
  return RUN_ALL_TESTS();
}


/*

---------- running basic_test ---------


[==========] Running 1 test from 1 test case.
[----------] Global test environment set-up.
[----------] 1 test from TEST_BASIC
[ RUN      ] TEST_BASIC.TestBasic
MINIMUM_CAPACITY: 3
adding [0] (1/3) [    0 ]
adding [1] (2/3) [    0     1 ]
adding [2] (3/3) [    0     1     2 ]
adding [3] (4/6) [    0     1     2     3 ]
adding [4] (5/6) [    0     1     2     3     4 ]
adding [5] (6/6) [    0     1     2     3     4     5 ]
adding [6] (7/12) [    0     1     2     3     4     5     6 ]
adding [7] (8/12) [    0     1     2     3     4     5     6     7 ]
adding [8] (9/12) [    0     1     2     3     4     5     6     7     8 ]
adding [9] (10/12) [    0     1     2     3     4     5     6     7     8     9 ]

search_entry returned: 4
removed [4]: (9/12) [    0     1     2     3     5     6     7     8     9 ]


removed: [9] (8/12) [    0     1     2     3     5     6     7     8 ]
removed: [8] (7/12) [    0     1     2     3     5     6     7 ]
removed: [7] (6/12) [    0     1     2     3     5     6 ]
removed: [6] (5/12) [    0     1     2     3     5 ]
removed: [5] (4/12) [    0     1     2     3 ]
removed: [3] (3/6) [    0     1     2 ]
removed: [2] (2/6) [    0     1 ]
removed: [1] (1/3) [    0 ]
removed: [0] (0/3) []
----- end of function --------
[       OK ] TEST_BASIC.TestBasic (2 ms)
[----------] 1 test from TEST_BASIC (2 ms total)

[----------] Global test environment tear-down
[==========] 1 test from 1 test case ran. (2 ms total)
[  PASSED  ] 1 test.


*/