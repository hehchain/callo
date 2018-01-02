/**
    Interface, physic_node.h
    Purpose: Interface of PhysiNode
    @author feavfeav@gmail.com
    @version 1.0 02/01/18 
*/
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

typedef struct *node PhysicNode;
/**
    Set name of physic node.
    @param physic node(PhysicNode *) and name to assign (char *)
    @return void.
*/
void setName(PhysicNode *, char *);

/**
    Set ip of physic node.
    @param physic node(PhysicNode *) and ip to assign (char *)
    @return void.
*/
void setIp(PhysicNode *, char *);

/**
    Set port of communication of physic node.
    @param physic node(PhysicNode *) and port to assign (char *)
    @return void.
*/
void setPort(PhysicNode *, char *);

/**
    Set protocol using for communication of physic node.
    @param physic node(PhysicNode *) and protocole to assign (char)
    @return void.
*/
void setProtocol(PhysicNode *, char );

/**
    Set public key using for communication with another physic node.
    @param physic node(PhysicNode *) and name to assign (char *)
    @return void.
*/
void setPublicKey(PhysicNode *, char *);

/**
    Set private key using for communication with another physic node.
    @param physic node(PhysicNode *) and name to assign (char *)
    @return void.
*/
void setPrivateKey(PhysicNode *, char *);

/**
    Add neighbour to local neighbours list
    @param physic node(PhysicNode *) and neighbours to add (PhysicNode )
    @return void.
*/
void pNodeAddNeighbour(PhysicNode *,PhysicNode);

/**
    Remove neighbour to local neighbours list
    @param physic node(PhysicNode *) and neighbours to remove (PhysicNode )
    @return void.
*/
PhysicNode *pNodeRemoveNeighbour(PhysicNode *, PhysicNode);

/**
    Destroy PhysicNode and his depencees
    @param physic node(PhysicNode *)
    @return void.
*/
void pNodeDestroy(PhysicNode *);


/**
    Return name of PhysicNode
    @param physic node(PhysicNode *)
    @return name.
*/
char * getName(PhysicNode);

/**
    Return ip address of PhysicNode
    @param physic node(PhysicNode *)
    @return ip.
*/
char * getIp(PhysicNode);

/**
    Return port  of PhysicNode
    @param physic node(PhysicNode *)
    @return port.
*/
char * getPort(PhysicNode);

/**
    Return protocol  of PhysicNode
    @param physic node(PhysicNode *)
    @return protocol.
*/
char getProtocol(PhysicNode);

/**
    Return public key  of PhysicNode
    @param physic node(PhysicNode *)
    @return privete_key.
*/
char * getPublicKey(PhysicNode);

/**
    Return private key  of PhysicNode
    @param physic node(PhysicNode *)
    @return privete_key.
*/
char * getPrivateKey(PhysicNode);

/**
    Return PhysicNode if it's neighbour of PhysicNode
    @param physic node(PhysicNode ) and name (char *)
    @return PhysicNode.
*/
PhysicNode *pNodeFind(PhysicNode , char *);

/**
    Return number of neighbour of PhysicNode
    @param physic node(PhysicNode)
    @return lengh.
*/
int pNodeNeighbourLength(PhysicNode );

/**
    print PhysicNode and his neighbour
    @param physic node(PhysicNode )
    @return void.
*/
void pNodePrint(PhysicNode );


#endif
