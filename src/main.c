/* Author: 	Michael Remley
 * Email:  	Mikejamesremley@gmail.com
 * Date:	  Feb 6th 2024
 * 
 * Project Details:
 * A red black tree written in C. 
 * */

#include <stdio.h>
#include <binaryTree.h>
#include <stdlib.h>

int main(int argc, char* argv[]) { 

  int* some_item = (int*)malloc(sizeof(int));
  *some_item = 10;

  printf("int val: %d\n", *some_item);

  int result_of_insertion = insert_data(some_item);
  int* result_of_search = (int*)search_data(some_item);

  printf("Result of insert operation: %d\n", result_of_insertion);
  printf("Result of search operation: %d\n", *result_of_search);

  free(some_item);

  return delete_tree();
}
