#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "trie.h"

#define NUM_CHARS 256

typedef struct TrieNode{
    struct TrieNode *children[NUM_CHARS];
    bool terminal;
}TrieNode;


TrieNode *trie_node_create(){
    TrieNode *node = (TrieNode *)malloc(sizeof(TrieNode));

    for(int i = 0; i < NUM_CHARS; i++){
        node->children[i] = NULL;
    }

    node->terminal = false;

    return node;
}

struct Trie{
    TrieNode *root;
};

Trie *trie_create(){
    Trie *trie = (Trie *)malloc(sizeof(Trie));

    trie->root = trie_node_create();
}