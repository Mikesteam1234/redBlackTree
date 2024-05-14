#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"
#include "debug.h"

#define ANSI_COLOR_RED    "\x1b[31m"
#define ANSI_COLOR_GREEN  "\x1b[32m"
#define ANSI_COLOR_RESET  "\x1b[0m"

FILE *dbgf;
int dbgmsk = 0;

void insert_test();
void init_test();
void init_with_comp_test();
void remove_test();
void deleteTree_test();
void insertDataTwice_test();
void insertTwice_searchLast_test();
void insertTwice_searchFirst_test();
void insertOneHundred_searchHalf_test();

typedef void (*test_type)(void);

int compare_ints(void* a, void* b) {
  return *(int *)a - *(int*)b;
}

int main(int argc, char argv[]) {

  dbgf = fopen("../logs/debug.log", "w");
  dbgmsk = D_MIN;

  test_type test_funcs[9] = {&init_test, &init_with_comp_test, &insert_test, &remove_test, 
    &deleteTree_test, &insertDataTwice_test, &insertTwice_searchLast_test,
    &insertTwice_searchFirst_test, &insertOneHundred_searchHalf_test};

  int num_tests = *(&test_funcs + 1) - test_funcs;

  printf("Running Tests [%d]\n---------------\n", num_tests);
  for (int i = 0; i < num_tests; i++) {
    printf("[%d/%d] ", i + 1, num_tests);
    test_funcs[i]();
  }

  return 0;
}

/* Print Test
 * Description: This function prints the result of a test
 * */
void print_test(char title[], int was_successful) {
  if (was_successful) {
    printf("Test Completed: %s... " ANSI_COLOR_GREEN "[PASSED]" ANSI_COLOR_RESET "\n", title);
  } else {
    printf("Test Completed: %s... " ANSI_COLOR_RED "[FAILED]" ANSI_COLOR_RESET "\n", title);
  }
}

/* Test Name: Init
 * Description: This test expects the following behavior,
 *  - Memory is well-behaved
 * */
void init_test() {

  int test_result = 0;

  bTree_t* tree = init_tree();
  
  if (tree != NULL) {
    test_result = 1;
  }

  free(tree);

  print_test("Tree Initialization", test_result);
}

/* Test Name: Init with Comparator
 * Description: This test expects the following behavior,
 *  - Memory is well-behaved
 * */
void init_with_comp_test() {

  int test_result = 0;

  bTree_t* tree = init_tree_with_comp(&compare_ints);
  
  if (tree != NULL) {
    test_result = 1;
  }

  free(tree);

  print_test("Tree Initialization with Comparator", test_result);
}

/* Insert Test
 * Description: This test expects the following behavior,
 *  - The insertion operator returns 1
 * */
void insert_test() {
  
  int test_result;

  bTree_t* tree = init_tree();
  
  int some_data = 1;
  
  int operation_result = insert_data(tree, &some_data); 
  
  if (operation_result == 1) {
    test_result = 1;
  }

  delete_tree(tree);

  print_test("Tree Insertion", test_result);
}

/* Test: Remove Data Test
 * Description: This test expects the following behavior,
 *  - The remove operator returns the data that was removed
 * */
void remove_test() {

  int some_data = 1;
  int test_result;
  bTree_t* tree = init_tree();
  
  insert_data(tree, &some_data);
  int* result_of_remove = remove_data(tree, &some_data);
  test_result = some_data & *result_of_remove;

  free(tree);

  print_test("Remove Data", test_result);
}

/* Test: Delete Tree Test
 * Description: This test expects the following behavior,
 *  - The delete operator returns 1, or success
 * */
void deleteTree_test() {

  bTree_t* tree = init_tree();

  int result = delete_tree(tree);

  print_test("Delete Tree", result);
}

/* Test: Insert Data Twice Test
 * Description: This test expects the following behavior,
 *  - The insert operator returns 1 for all insertions
 * */
void insertDataTwice_test() {

  bTree_t* tree = init_tree_with_comp(&compare_ints);
  int some_data = 5;
  int insert_result = 1; //True to start

  for (int i = 0; i < 2; i++) {
    insert_result &= insert_data(tree, &some_data);
  }

  int delete_result = delete_tree(tree);

  if (delete_result != 1) {
    fprintf(stderr, "Tree Delete Failed in InsertDataTwice_test with val: %d", delete_result);
  }

  print_test("Insert Twice", insert_result);
}

/* Test: Insert Twice, Search Last
 * Description: This test expects the following behavior,
 *  - The search operator returns the last inserted data
 * */
void insertTwice_searchLast_test() {

  bTree_t* tree = init_tree_with_comp(&compare_ints);

  int some_data = 5;
  int other_data = 10;
  
  insert_data(tree, &some_data);
  insert_data(tree, &other_data);

  int* found_data = search_data(tree, &other_data);

  int test_result = 0;
  if (found_data != NULL && *found_data == other_data) {
    test_result = 1;
  }

  delete_tree(tree);

  print_test("Insert Twice, Search, Expect Last", test_result);
}

/* Test: Insert Twice, Search First
 * Description: This test expects the following behavior,
 *  - The search operator returns the first inserted data
 * */
void insertTwice_searchFirst_test() {

  bTree_t* tree = init_tree_with_comp(&compare_ints);

  int some_data = 5;
  int other_data = 10;
  
  insert_data(tree, &some_data);
  insert_data(tree, &other_data);

  int* found_data = search_data(tree, &some_data);

  int test_result = 0;
  if (found_data != NULL && *found_data == some_data) {
    test_result = 1;
  }

  delete_tree(tree);

  print_test("Insert Twice, Search, Expect First", test_result);
}

/* Test: Insert One Hundred, Search Middle
 * Description: This test expects the following behavior,
 *  - The search operator returns the 49th inserted data
 * */
void insertOneHundred_searchHalf_test() {
  bTree_t* tree = init_tree_with_comp(&compare_ints);

  int some_constant = 98247923;
  srand(some_constant);

  int* array_of_ints[100];

  for (int i = 0; i < 100; i++) {
    int* val = (int*)malloc(sizeof(int));
    *val = (rand() % some_constant) - i; 

    array_of_ints[i] = val;
    insert_data(tree, array_of_ints[i]);
  }
  
  int* found_data = (int*)search_data(tree, array_of_ints[49]);

  D(D_MIN, "Inserted: address -> %p, val -> %d\r\n", array_of_ints[49], *array_of_ints[49]);

  int test_result = 0;
  if (found_data != NULL && *found_data == *array_of_ints[49]) {
    test_result = 1;
    D(D_MIN,"Found: address -> %p, val -> %d\r\n", found_data, *found_data);
  }

  delete_tree(tree);
  for (int i = 0; i < 100; i++) {
    free(array_of_ints[i]);
  }

  print_test("Insert One Hundred, Search, Expect 49th.", test_result);
}
