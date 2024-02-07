#include <stddef.h>
#include "binaryTree.h"
#include "node.h"

node_t* head = NULL;

/* Method: Search
 * Description: Used to lookup some data contained in the tree
 * Returns: The desired data
 */
void* search_data(void* data) {
  
  if (head == NULL) {
    return NULL;
  }

  return get_data(head);
}

/* Method: Insert
 * Description: Used to insert some data into the tree 
 * Returns: 1 on successful insertion, 0 otherwise.
 */
int insert_data(void* data) {
  if (data == NULL) {
    return 0;
  }

  node_t* node;
  init_node(&node);

  set_data(node, data);

  head = node;

  return 1;
}

/* Method: Remove
 * Description: Used to remove some data from the tree
 * Returns: 1 on successful removal, 0 otherwise.
 */
int remove_data(void* data) {

  if (head == NULL) {
    return 0;
  }

  free_node(&head);

  return 1;
}

int delete_tree() {
  
  free_node(&head);

  return 1;
}
