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


	#define MAX(x, y) ((x) >= (y) ? (x) : (y))
	#define MIN(x, y) ((x) <= (y) ? (x) : (y))


	typedef struct node *PhysicNode;

	/**
	    Create empty physic's node.
	    @param void
	    @return PhysicNode.
	*/
	PhysicNode createPhysicNode();

	/**
	    Set name of physic node.
	    @param physic node(PhysicNode *) and name to assign (char *)
	    @return void.
	*/
	void setPNodeName(PhysicNode *, const char *);

	/**
	    Set ip of physic node.
	    @param physic node(PhysicNode *) and ip to assign (char *)
	    @return void.
	*/
	void setPNodeIp(PhysicNode *, const char *);

	/**
	    Set port of communication of physic node.
	    @param physic node(PhysicNode *) and port to assign (char *)
	    @return void.
	*/
	void setPNodePort(PhysicNode *, const char *);

	/**
	    Set protocol using for communication of physic node.
	    @param physic node(PhysicNode *) and protocole to assign (char)
	    @return void.
	*/
	void setPNodeProtocol(PhysicNode *, char );

	/**
	    Set public key using for communication with another physic node.
	    @param physic node(PhysicNode *) and name to assign (char *)
	    @return void.
	*/
	void setPNodePublicKey(PhysicNode *, const char *);


	/**
	    Add neighbour to local neighbours list
	    @param physic node(PhysicNode *) and neighbours to add (PhysicNode )
	    @return void.
	*/
	void pNodeAddNeighbour(PhysicNode *,PhysicNode *);

	/**
	    Remove neighbour to local neighbours list
	    @param physic node(PhysicNode *) and neighbours to remove (PhysicNode )
	    @return void.
	*/
	const PhysicNode *pNodeRemoveNeighbour(PhysicNode *, PhysicNode *);

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
	const char * getPNodeName(PhysicNode);

	/**
	    Return ip address of PhysicNode
	    @param physic node(PhysicNode *)
	    @return ip.
	*/
	const char * getPNodeIp(PhysicNode);

	/**
	    Return port  of PhysicNode
	    @param physic node(PhysicNode *)
	    @return port.
	*/
	const char * getPNodePort(PhysicNode);

	/**
	    Return protocol  of PhysicNode
	    @param physic node(PhysicNode *)
	    @return protocol.
	*/
	char getPNodeProtocol(PhysicNode);

	/**
	    Return public key  of PhysicNode
	    @param physic node(PhysicNode *)
	    @return privete_key.
	*/
	const char * getPNodePublicKey(PhysicNode);


	/**
	    Return PhysicNode if it's neighbour of PhysicNode
	    @param physic node(PhysicNode ) and name (char *)
	    @return PhysicNode.
	*/
	PhysicNode *pNodeFind(PhysicNode , const char *);

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
