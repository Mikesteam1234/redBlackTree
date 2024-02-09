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

typedef struct payload {
  int header;
  int data;
  int send_off;
} payload_t;


int main(int argc, char* argv[]) { 

  bTree_t* tree = init_tree();

  payload_t* packet = (payload_t*)malloc(sizeof(payload_t));
  packet->header = 80085;
  packet->data = 1337;
  packet->send_off = 10101;

  insert_data(tree, packet);

  payload_t* acket = (payload_t*)search_data(tree, packet);

  printf("Packet returned from tree as,\nHeader: %d\nData: %d\nSend Off: %d\n", acket->header, acket->data, acket->send_off);

  payload_t* removed_acket = (payload_t*)remove_data(tree, acket);
  free(removed_acket);

  delete_tree(tree);
  return 0;
}
