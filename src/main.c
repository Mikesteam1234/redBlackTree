/* Author: 	Michael Remley
 * Email:  	Mikejamesremley@gmail.com
 * Date:	  Feb 6th 2024
 * 
 * Project Details:
 * A red black tree written in C. 
 * */

#include <stdio.h>
#include <binaryTree.h>

int main(int argc, char* argv[]) { 

  int some_item = 10;
  void* nullptr = NULL;

  void* pointer_to_some_item = &some_item;

  int result_of_insertion = Insert(pointer_to_some_item);

  printf("Result of insert operation: %d\n", result_of_insertion);

  return 0;
}
