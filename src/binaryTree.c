#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include "binaryTree.h"
#include "node.h"

struct bTree {
  node_t* root;
  compare_t compare_values;
};

void delete_tree_helper(node_t* node);

/* Method: Init tree
 * */
bTree_t* init_tree() {

  bTree_t* tree = (bTree_t*)malloc(sizeof(bTree_t)); 

  tree->root = NULL;

  return tree; 
}

bTree_t* init_tree_with_comp(compare_t compare_func) {

  bTree_t* tree = init_tree();

  tree->compare_values = compare_func;

  return tree;
}

/* Method: Search
 * Description: Used to lookup some data contained in the tree
 * Returns: The desired data
 */
void* search_data(bTree_t* tree, void* data) {
  
  node_t* curr = tree->root;

  while (curr != NULL) { 

    int result = tree->compare_values(data, get_data(curr));

    if (result == 0) {
      break;    
    }
    else if (result >= 1) {
      curr = get_right(curr);
    }
    else {
      curr = get_left(curr);
    }
  }

  if (curr == NULL) {
    return NULL;
  }

  return get_data(curr);
}

/* Method: Insert
 * Description: Used to insert some data into the tree 
 * Returns: 1 on successful insertion, 0 otherwise.
 */
int insert_data(bTree_t* tree, void* data) {
  if (data == NULL) {
    return 0;
  }

  node_t* node = init_node(data);

  if (tree->root == NULL) {
    tree->root = node;
  } else {

    int result = tree->compare_values(data, get_data(tree->root));

    if (result <= -1) { //Set Left
      set_left(tree->root, node);
    }
    else { // Set Right
      set_right(tree->root, node);
    }    
  }
  return 1;
}

/* Method: Remove
 * Description: Used to remove some data from the tree
 * Returns: 1 on successful removal, 0 otherwise.
 */
void* remove_data(bTree_t* tree, void* data) {

  if (tree->root == NULL) {
    return 0;
  }

  void* data_ptr = get_data(tree->root);

  free_node(tree->root);

  return data_ptr;
}

int delete_tree(bTree_t* tree) {

  if (tree->root != NULL) {
    delete_tree_helper(tree->root);
  }

  free(tree);

  return 1;
}

void delete_tree_helper(node_t* node) {
  
  if (node == NULL) return;

  node_t* left = get_left(node);
  delete_tree_helper(left);

  node_t* right = get_right(node);
  delete_tree_helper(right);

  free_node(node);
}
