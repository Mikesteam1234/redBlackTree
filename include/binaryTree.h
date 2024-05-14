#ifndef BinaryTree
#define BinaryTree

typedef struct bTree bTree_t;
typedef int (*compare_t)(void*, void*);

bTree_t* init_tree();

bTree_t* init_tree_with_comp(compare_t compare_func);

void* search_data(bTree_t* tree, void* data);

int insert_data(bTree_t* tree, void* data);

void* remove_data(bTree_t* tree, void* data);

int delete_tree(bTree_t* tree);

#endif //BinaryTree
