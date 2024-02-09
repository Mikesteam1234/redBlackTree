#include <stddef.h>
#include <stdlib.h>
#include "node.h"

struct node {
  node_t* parent;
  node_t* l_child;
  node_t* r_child;
  void* data;
};

node_t* init_node(void* data) {

  node_t* p = (node_t*)malloc(sizeof(node_t));

  p->parent = NULL;
  p->l_child = NULL;
  p->r_child = NULL;
  p->data = data;

  return p;
}

int free_node(node_t* p) {
  p->parent = NULL;
  p->l_child = NULL;
  p->r_child = NULL;
  p->data = NULL;

  free(p);

  return 1;
}

//DATA
void set_data(node_t* p, void* data) {
  p->data = data;
}

void* get_data(node_t* p) {
  return p->data;
}

//PARENT
void set_parent(node_t* p, node_t* parent) {
  p->parent = parent; 
}

node_t* get_parent(node_t* p) {
  return p->parent;
}

//LEFT
void set_left(node_t* p, node_t* left) {
  p->l_child = left;
}

node_t* get_left(node_t* p) {
  return p->l_child;
}

//RIGHT
void set_right(node_t* p, node_t* right) {
  p->r_child = right;
}

node_t* get_right(node_t* p) {
  return p->r_child;
}
