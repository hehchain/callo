#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/**
    Implementation, physic_node.h
    Purpose: Interface of PhysiNode
    @author feavfeav@gmail.com
    @version 1.0 02/01/18 
*/
struct node
{
    char *name;
    char *ip;
    char *port;
    char protocol;
    char *publicKey;
    struct node **neighbours;
};

/**
    Set name of physic node.
    @param physic node(PhysicNode *) and name to assign (char *)
    @return void.
*/
void setName(PhysicNode *, char *){}

/**
    Set ip of physic node.
    @param physic node(PhysicNode *) and ip to assign (char *)
    @return void.
*/
void setIp(PhysicNode *, char *){}

/**
    Set port of communication of physic node.
    @param physic node(PhysicNode *) and port to assign (char *)
    @return void.
*/
void setPort(PhysicNode *, char *){}

/**
    Set protocol using for communication of physic node.
    @param physic node(PhysicNode *) and protocole to assign (char)
    @return void.
*/
void setProtocol(PhysicNode *, char ){}

/**
    Set public key using for communication with another physic node.
    @param physic node(PhysicNode *) and name to assign (char *)
    @return void.
*/
void setPublicKey(PhysicNode *, char *){}

/**
    Add neighbour to local neighbours list
    @param physic node(PhysicNode *) and neighbours to add (PhysicNode )
    @return void.
*/
void pNodeAddNeighbour(PhysicNode *,PhysicNode){}

/**
    Remove neighbour to local neighbours list
    @param physic node(PhysicNode *) and neighbours to remove (PhysicNode )
    @return void.
*/
PhysicNode *pNodeRemoveNeighbour(PhysicNode *, PhysicNode){}

/**
    Destroy PhysicNode and his depencees
    @param physic node(PhysicNode *)
    @return void.
*/
void pNodeDestroy(PhysicNode *){}


/**
    Return name of PhysicNode
    @param physic node(PhysicNode *)
    @return name.
*/
char * getName(PhysicNode){}

/**
    Return ip address of PhysicNode
    @param physic node(PhysicNode *)
    @return ip.
*/
char * getIp(PhysicNode){}

/**
    Return port  of PhysicNode
    @param physic node(PhysicNode *)
    @return port.
*/
char * getPort(PhysicNode){}

/**
    Return protocol  of PhysicNode
    @param physic node(PhysicNode *)
    @return protocol.
*/
char getProtocol(PhysicNode){}

/**
    Return public key  of PhysicNode
    @param physic node(PhysicNode *)
    @return privete_key.
*/
char * getPublicKey(PhysicNode){}

/**
    Return PhysicNode if it's neighbour of PhysicNode
    @param physic node(PhysicNode ) and name (char *)
    @return PhysicNode.
*/
PhysicNode *pNodeFind(PhysicNode , char *){}

/**
    Return number of neighbour of PhysicNode
    @param physic node(PhysicNode)
    @return lengh.
*/
int pNodeNeighbourLength(PhysicNode ){}

/**
    print PhysicNode and his neighbour
    @param physic node(PhysicNode )
    @return void.
*/
void pNodePrint(PhysicNode ){}
