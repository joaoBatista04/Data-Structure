#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "vector.h"

//KEYVALPAIR FUNCTIONS
KeyValPair *key_val_pair_construct(void *key, void *val){
    KeyValPair *pair = (KeyValPair *)calloc(1, sizeof(KeyValPair));

    pair->key = key;
    pair->value = val;

    return pair;
}

void key_val_pair_destroy(KeyValPair *kvp){
    free(kvp);
}

//BINARY TREE NODE FUNCTIONS
Node *node_construct(void *key, void *value, Node *parent, Node *left, Node *right){
    Node *node = (Node *)calloc(1, sizeof(Node));

    node->kvp = key_val_pair_construct(key, value);

    node->parent = parent;
    node->left = left;
    node->right = right;

    return node;
}

void node_destroy(Node *node){
    free(node);
}

//BINARY TREE FUNCTIONS
BinaryTree *binary_tree_construct(CmpFn cmp_fn, KeyDestroyFn key_destroy_fn, ValDestroyFn val_destroy_fn){
    BinaryTree *bt = (BinaryTree *)calloc(1, sizeof(BinaryTree));

    bt->cmp_fn = cmp_fn;
    bt->key_destroy_fn = key_destroy_fn;
    bt->val_destroy_fn = val_destroy_fn;
    bt->root = NULL;
    bt->size = 0;

    return bt;
}

Node *_add_recursive(BinaryTree *bt, Node *node, void *key, void *value){
    if(node == NULL){
        return node_construct(key, value, node, NULL, NULL);
    }

    if(bt->cmp_fn(key, node->kvp->key) < 0){
        node->left = _add_recursive(bt, node->left, key, value);
    }

    else if(bt->cmp_fn(key, node->kvp->key) > 0){
        node->right = _add_recursive(bt, node->right, key, value);
    }

    else{
        bt->val_destroy_fn(node->kvp->value);
        bt->key_destroy_fn(node->kvp->key);

        node->kvp->key = key;
        node->kvp->value = value;
    }

    return node;
}

void binary_tree_add(BinaryTree *bt, void *key, void *value){
    bt->root = _add_recursive(bt, bt->root, key, value);

    bt->size++;
}

int binary_tree_empty(BinaryTree *bt){
    return bt->size == 0;
}

void _binary_tree_transplant(BinaryTree *bt, Node *u, Node *v){
    if(u->parent == NULL){
        bt->root = v;
    }

    else if(u == u->parent->left){
        u->parent->left = v;
    }

    else{
        u->parent->right = v;
    }

    if(v != NULL){
        v->parent = u->parent;
    }
}

void binary_tree_remove(BinaryTree *bt, void *key){
    Node *curr = bt->root;
    Node *prev_curr = NULL;
    Node *aux = NULL;
    Node *prev_aux = NULL;

    while (curr) {
        if(bt->cmp_fn(curr->kvp->key, key) < 0){
            prev_curr = curr;
            curr = curr->right;
        }

        else if(bt->cmp_fn(curr->kvp->key, key) > 0){
            prev_curr = curr;
            curr = curr->left;
        }

        else{
            break;
        }
    }
    
    if (curr == NULL){
        return;
    }

    if(curr->right) {
        prev_aux = curr;
        aux = curr->right;

        while (aux->left){
            prev_aux = aux;
            aux = aux->left;
        }

        bt->key_destroy_fn(curr->kvp->key);
        bt->val_destroy_fn(curr->kvp->value);
        key_val_pair_destroy(curr->kvp);
        curr->kvp = aux->kvp;

        if(prev_aux != curr){ 
            prev_aux->left = aux->right;
        }

        else{
            prev_aux->right = aux->right;
        }

        node_destroy(aux);
    }

    else if(curr->left){
        prev_aux = curr;
        aux = curr->left;

        while(aux->right){
            prev_aux = aux;
            aux = aux->right;
        }

        bt->key_destroy_fn(curr->kvp->key);
        bt->val_destroy_fn(curr->kvp->value);
        key_val_pair_destroy(curr->kvp);
        curr->kvp = aux->kvp;

        if(prev_aux != curr){
            prev_aux->right = aux->left;
        }

        else{
            prev_aux->left = aux->left;
        }

        node_destroy(aux);
    }

    else{
        if(prev_curr == NULL){
            bt->root = NULL;
        }

        else if(bt->cmp_fn(prev_curr->kvp->key, key) < 0){
            prev_curr->right = NULL;
        }

        else if(bt->cmp_fn(prev_curr->kvp->key, key) > 0){
            prev_curr->left = NULL;
        }
        
        bt->key_destroy_fn(curr->kvp->key);
        bt->val_destroy_fn(curr->kvp->value);
        key_val_pair_destroy(curr->kvp);
        node_destroy(curr);
    }

    bt->size--;
}

KeyValPair *binary_tree_min(BinaryTree *bt){
    Node *current = bt->root;

    while(current){
        if(current->left == NULL){
            return current->kvp;
        }

        current = current->left;
    }

    return NULL;
}

KeyValPair *binary_tree_max(BinaryTree *bt){
    Node *current = bt->root;

    while(current){
        if(current->right == NULL){
            return current->kvp;
        }

        current = current->right;
    }

    return NULL;
}

KeyValPair *binary_tree_pop_min(BinaryTree *bt){
    KeyValPair *value = NULL;
    Node *target = bt->root;
    Node *parent = NULL;

    while(target){
        if(!target->left){
            break;
        }

        parent = target;
        target = target->left;
    }

    value = target->kvp;

    if(parent){
        parent->left = target->right;
    } 
    
    else{
        bt->root = target->right;
    }

    node_destroy(target);

    bt->size--;

    return value;
}

KeyValPair *binary_tree_pop_max(BinaryTree *bt){
    KeyValPair *value = NULL;
    Node *target = bt->root;
    Node *parent = NULL;

    while(target) {
        if(!target->right){
            break;
        }

        parent = target;
        target = target->right;
    }

    value = target->kvp;

    if(parent){
        parent->right = target->left;
    } 
    
    else{
        bt->root = target->left;
    }

    node_destroy(target);

    bt->size--;

    return value;
}

void *_binary_tree_get_recursive(BinaryTree *bt, Node *node, void *key) {
    if(node == NULL){
        return NULL;
    }

    if(bt->cmp_fn(key, node->kvp->key) < 0){
        return _binary_tree_get_recursive(bt, node->left, key);
    } 
    
    else if(bt->cmp_fn(key, node->kvp->key) > 0){
        return _binary_tree_get_recursive(bt, node->right, key);
    }
    
    return node->kvp->value;
}

void *binary_tree_get(BinaryTree *bt, void *key) {
    return _binary_tree_get_recursive(bt, bt->root, key);
}

void _binary_tree_destroy_recursive(BinaryTree *bt, Node *node){
    if(node == NULL){
        return;
    }

    bt->val_destroy_fn(node->kvp->value);
    bt->key_destroy_fn(node->kvp->key);
    key_val_pair_destroy(node->kvp);

    _binary_tree_destroy_recursive(bt, node->right);
    _binary_tree_destroy_recursive(bt, node->left);

    node_destroy(node);
}

void binary_tree_destroy(BinaryTree *bt){
    _binary_tree_destroy_recursive(bt, bt->root);

    free(bt);
}

Vector *binary_tree_inorder_traversal(BinaryTree *bt){
    Vector *vector = vector_construct();
    Vector *vector_aux = vector_construct();
    Node *node = bt->root;

    while(1){
        while(node){
            vector_push_back(vector_aux, node);
            node = node->left;
        }

        if(vector_size(vector_aux) == 0){
            break;
        }

        else{
            Node *btn = vector_pop_back(vector_aux);
            vector_push_back(vector, btn->kvp);
            node = btn->right;
        }
    }

    vector_destroy(vector_aux);

    return vector;
}

Vector *binary_tree_preorder_traversal(BinaryTree *bt){
    Vector *vector = vector_construct();
    Vector *vector_aux = vector_construct();

    vector_push_back(vector_aux, bt->root);

    while(vector_size(vector_aux) != 0){
        Node *node = vector_pop_back(vector_aux);
        vector_push_back(vector, node->kvp);

        if(node->right){
            vector_push_back(vector_aux, node->right);
        }

        if(node->left){
            vector_push_back(vector_aux, node->left);
        }
    }

    vector_destroy(vector_aux);

    return vector;
}

Vector *binary_tree_postorder_traversal(BinaryTree *bt){
    Vector *vector = vector_construct();
    Vector *aux1 = vector_construct();
    Vector *aux2 = vector_construct();

    vector_push_back(aux1, bt->root);

    while(vector_size(aux1) != 0){
        Node *node = vector_pop_back(aux1);

        if(node->left){
            vector_push_back(aux1, node->left);
        }

        if(node->right){
            vector_push_back(aux1, node->right);
        }

        vector_push_back(aux2, node);
    }

    while(vector_size(aux2) != 0){
        Node *node = vector_pop_back(aux2);

        vector_push_back(vector, node->kvp);
    }

    vector_destroy(aux1);
    vector_destroy(aux2);

    return vector;
}

Vector *binary_tree_levelorder_traversal(BinaryTree *bt){
    Vector *vector = vector_construct();
    Vector *aux = vector_construct();

    vector_push_back(aux, bt->root);

    while(vector_size(aux) != 0){
        Node *node = vector_pop_front(aux);

        vector_push_back(vector, node->kvp);

        if(node->left){
            vector_push_back(aux, node->left);
        }

        if(node->right){
            vector_push_back(aux, node->right);
        }
    }

    vector_destroy(aux);

    return vector;
}

void _binary_tree_inorder_transversal_recursive(Node *node, Vector *vector){
    if(node == NULL){
        return;
    }

    _binary_tree_inorder_transversal_recursive(node->left, vector);
    vector_push_back(vector, node->kvp);
    _binary_tree_inorder_transversal_recursive(node->right, vector);
}

Vector *binary_tree_inorder_traversal_recursive(BinaryTree *bt){
    Vector *vector = vector_construct();

    _binary_tree_inorder_transversal_recursive(bt->root, vector);

    return vector;
}

void _binary_tree_preorder_transversal_recursive(Node *node, Vector *vector){
    if(node == NULL){
        return;
    }

    vector_push_back(vector, node->kvp);
    _binary_tree_preorder_transversal_recursive(node->left, vector);
    _binary_tree_preorder_transversal_recursive(node->right, vector);
}

Vector *binary_tree_preorder_traversal_recursive(BinaryTree *bt){
    Vector *vector = vector_construct();

    _binary_tree_preorder_transversal_recursive(bt->root, vector);

    return vector;
}

void _binary_tree_postorder_transversal_recursive(Node *node, Vector *vector){
    if(node == NULL){
        return;
    }

    _binary_tree_postorder_transversal_recursive(node->left, vector);
    _binary_tree_postorder_transversal_recursive(node->right, vector);
    vector_push_back(vector, node->kvp);
}

Vector *binary_tree_postorder_traversal_recursive(BinaryTree *bt){
    Vector *vector = vector_construct();

    _binary_tree_postorder_transversal_recursive(bt->root, vector);

    return vector;
}