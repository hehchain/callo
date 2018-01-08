#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#if !defined(_WIN32) || defined(__MINGW32__)
#include <sys/time.h>
#endif

#ifndef _WIN32
#include <unistd.h>
#include <fcntl.h>

#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#else
#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600 /* Windows Vista */
#endif
#ifndef WINVER
#define WINVER _WIN32_WINNT
#endif
#include <ws2tcpip.h>
#include <windows.h>
#endif

#ifndef MSG_CONFIRM
#define MSG_CONFIRM 0
#endif

#if !defined(_WIN32) || defined(__MINGW32__)
#define dht_gettimeofday(_ts, _tz) gettimeofday((_ts), (_tz))
#else
extern int dht_gettimeofday(struct timeval *tv, struct timezone *tz);
#endif

#ifdef _WIN32

#undef EAFNOSUPPORT
#define EAFNOSUPPORT WSAEAFNOSUPPORT
/* We set sin_family to 0 to mark unused slots. */
#if AF_INET == 0 || AF_INET6 == 0
#error You lose
#endif

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
/* nothing */
#elif defined(__GNUC__)
#define inline __inline
#if (__GNUC__ >= 3)
#define restrict __restrict
#else
#define restrict /**/
#endif
#else
#define inline   /**/
#define restrict /**/
#endif

#define MAX(x, y) ((x) >= (y) ? (x) : (y))
#define MIN(x, y) ((x) <= (y) ? (x) : (y))

struct node
{
    char *name;
    char *ip;
    char *port;
    char protocol;
    time_t time;        /* time of last message received */
    time_t reply_time;  /* time of last correct reply received */
    time_t pinged_time; /* time of last request */
    int pinged;         /* how many requests we sent since last reply */
    struct node *neighbours;
};

typedef struct node list;

//new ADT interface ....
struct header{
    char *chainId;
    int height;
    time_t time;
    char *lastBlockHash;
    char *stateHash;
    char *lastBlockParts;
};
typedef struct header Header;

struct Transaction{
    int value;
    char *adress;
    int index;
    char *signature;//transaction signature ...
    struct Transaction *next;
};

typedef struct Transaction Txs;

struct block {
    Header * header;
    Txs * transactions;
    char *LastCommit;//block signature ...
    struct block *next;
} ;
typedef struct block Block;

int block_length(Block *head);//Number of block ...
Block *search_block(Block *head,char *stateHash);//you can add more criteria ...
int block_add(Block **head,Block *block_elt);// add new block  in the list ...
int remove_block(Block **head,Block *block_elt);// remove some block...
int add_transaction(Block **head,char *stateHash,Transaction *tx);// add transaction tx in some block with stateHash criteria ...
int count_transaction(Block *block);// number of transaction in one block ...

char *hash_transaction(int transaction_value,char *transaction_adress,int transaction_index);// get transaction signature or hash ...
char *hash_block(void *more_header_criteria,void *more_transaction_criteria,char *block_lastComit);//block hash ....





char *strstp(char *str, char *stp, int *size);
int list_length(list *head);
void list_add(list **head, char *name, char *ip, char *port, char protocol);
list *list_find(list *head, char *name);
void list_destroy(list **head);
void list_print(list *head);
list *list_remove(list *head, list *element);





#include "linkedlist.cpp"
#endif