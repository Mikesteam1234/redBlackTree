#ifndef BinaryTree
#define BinaryTree

typedef struct bTree bTree_t;

bTree_t* init_tree();

void* search_data(bTree_t* tree, void* data);

int insert_data(bTree_t* tree, void* data);

void* remove_data(bTree_t* tree, void* data);

int delete_tree(bTree_t* tree);

#endif //BinaryTree
