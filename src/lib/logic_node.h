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


	typedef struct node *LogicNode;

	/**
	    Create empty logic's node.
	    @param void
	    @return LogicNode.
	*/
	LogicNode createLogicicNode();

	/**
	    Set name of logic node.
	    @param logic node(LogicNode *) and chain id to assign (char *)
	    @return void.
	*/
	void setLNodeChainId(LogicNode *, const char *);

	/**
	    Set ip of logic node.
	    @param logic node(LogicNode *) and height to assign (int)
	    @return void.
	*/
	void setLNodeHeight(LogicNode *, int);

	/**
	    Set port of communication of logic node.
	    @param logic node(LogicNode *) and Time to assign (char *)
	    @return void.
	*/
	void setLNodeTime(LogicNode *, time_t);

	/**
	    Set protocol using for communication of logic node.
	    @param logic node(LogicNode *) and LastBlockHash to assign (char)
	    @return void.
	*/
	void setLNodeLastBlockHash(LogicNode *, const byte *);

	/**
	    Set public key using for communication with another logic node.
	    @param logic node(LogicNode *) and part's header of last block to assign (char *)
	    @return void.
	*/
	void setLNodeLastBlockParts(LogicNode *, const char *);

	/**
	    Set public key using for communication with another logic node.
	    @param logic node(LogicNode *) and hash of current block transform to assign (char *)
	    @return void.
	*/
	void setLNodeStateHash(LogicNode *, const byte *);




#endif
