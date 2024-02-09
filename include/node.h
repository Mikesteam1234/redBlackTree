/* Author: Michael Remley
 * Email: Mikejamesremley@gmail.com
 * Date: Feb 7th 2024
 * Description: A set of methods and definitions that represet a node
 *  intented to be used in a binary tree, bst, and/or rbt.
 * */

#ifndef NODE_H
#define NODE_H

typedef struct node node_t;

/* Method: init_node
 * Description: If given a block of memory of size node_t, will initialize 
 *  with expected data 
 * Returns: 1 on successful initialization, 0 otherwise
 * Thread Safe: Single Thread
 * */
node_t* init_node(void* data);

/* Method: free_node
 * Description: If given a block of memory of size node_t, will free
 *  that memory, and clean up references.
 * Returns: 1 on successful clean up, 0 otherwise
 * Thread Safe: Single Thread
 * */
int free_node(node_t* p);

/* Method: set_data
 * Description:
 * Returns: 
 * Thread Safe: Single Thread
 * */
void set_data(node_t* p, void* data);

/*
 * */
void* get_data(node_t* p);

/*
 * */
void set_parent(node_t* p, node_t* parent);

/*
 * */
node_t* get_parent(node_t* p);

/*
 * */
void set_left(node_t* p, node_t* left);

/*
 * */
node_t* get_left(node_t* p);

/*
 * */
void set_right(node_t* p, node_t* right);

/*
 * */
node_t* get_right(node_t* p);

#endif
