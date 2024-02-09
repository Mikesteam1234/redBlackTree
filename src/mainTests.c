#include <stdio.h>
#include <stdlib.h>
#include "binaryTree.h"

#define ANSI_COLOR_RED    "\x1b[31m"
#define ANSI_COLOR_GREEN  "\x1b[32m"
#define ANSI_COLOR_RESET  "\x1b[0m"

void insert_test();
void init_test();

typedef void (*test_type)(void);

int main(int argc, char argv[]) {

  test_type test_funcs[2] = {&init_test, &insert_test};
  int num_tests = *(&test_funcs + 1) - test_funcs;

  printf("Running Tests\n---------------\n");
  for (int i = 0; i < num_tests; i++) {
    printf("[%d/%d] ", i + 1, num_tests);
    test_funcs[i]();
  }

  return 0;
}

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

  free(tree);

  print_test("Tree Insertion", test_result);
}
