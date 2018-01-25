#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NEIGHBOUR 10
#include "logic_node.h"
struct HEADER{
        int chainId;
        int height;
        time_t time;
        char * lastBlockHash;
        char * lastBlockParts;
        char * stateHash;
    };
struct node
{
    HEADER header;
    DATA data;
    struct node * next;
};