#include <stddef.h>
#include <stdlib.h>
#include "binaryTree.h"
#include "node.h"

struct bTree {
  node_t* root;
};

/* Method: Init tree
 * */
bTree_t* init_tree() {

  bTree_t* tree = (bTree_t*)malloc(sizeof(bTree_t)); 

  tree->root = NULL;

  return tree; 
}

/* Method: Search
 * Description: Used to lookup some data contained in the tree
 * Returns: The desired data
 */
void* search_data(bTree_t* tree, void* data) {
  
  if (tree->root == NULL) {
    return NULL;
  }

  return get_data(tree->root);
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

  tree->root = node;

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
    free_node(tree->root);
  }

  free(tree);

  return 1;
}
