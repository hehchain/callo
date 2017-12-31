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

char *strstp(char *str, char *stp, int *size);
int list_length(list *head);
void list_add(list **head, char *name, char *ip, char *port, char protocol);
list *list_find(list *head, char *name);
void list_destroy(list **head);
void list_print(list *head);
char *strstp(char *str, char *stp, int *size);

list *list_remove(list *head, list *element);

#include "linkedlist.c"
#endif