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
	typedef struct data{
		char * data;
	} *DATA;

	/**
	    Create empty logic's node.
	    @param void
	    @return LogicNode.
	*/
	LogicNode createLogicicNode();

	/**
	    Create root fixed logic's node.
	    @param void
	    @return LogicNode.
	*/
	LogicNode createRootLogicicNode();

	/**
	    Get previous logic's node.
	    @param void
	    @return LogicNode.
	*/
	LogicNode previousLNode();

	/**
	    Get next logic's node.
	    @param void
	    @return LogicNode.
	*/
	LogicNode nextLNode();

	/**
	 * ************************************************************************
	 * 					SETTER METHODS OF HEADER OG LOGIC NODE				   *
	 * ************************************************************************
	 **/

	/**
	    Set if of logic node in chain.
	    @param logic node(LogicNode *) and chain id to assign (char *)
	    @return void.
	*/
	void setLNodeChainId(LogicNode *, const char *);

	/**
	 * Not userful
	    Set heigth of logic node.
	    @param logic node(LogicNode *) and height to assign (int)
	    @return void.
	*/
	void setLNodeHeight(LogicNode *, int);

	/**
	 * may be set only during create node
	    Set time of created node logic node.
	    @param logic node(LogicNode *) and Time to assign (char *)
	    @return void.
	*/
	void setLNodeTime(LogicNode *, time_t);

	/**
	    Set hash of previous logic node.
	    @param logic node(LogicNode *) and LastBlockHash to assign (char)
	    @return void.
	*/
	void setLNodeLastBlockHash(LogicNode *, const char *);

	/**
	    Set header informations of last node logic node.
	    @param logic node(LogicNode *) and part's header of last block to assign (char *)
	    @return void.
	*/
	void setLNodeLastBlockParts(LogicNode *, const char *);

	/**
	    Set hash of current logic node.
	    @param logic node(LogicNode *) and hash of current block transform to assign (char *)
	    @return void.
	*/
	void setLNodeStateHash(LogicNode *, const char *);

	/**
	 * ************************************************************************
	 * 					GETTER METHODS OF HEADER OG LOGIC NODE				  *
	 * ************************************************************************
	 **/

	/**
	    Get id of logic node in chain.
	    @param logic node(LogicNode *)
	    @return const char*.
	*/
	const char* getLNodeChainId(LogicNode *);

	/**
	    Get height of logic node.
	    @param logic node(LogicNode *)
	    @return int.
	*/
	int getLNodeHeight(LogicNode *);

	/**
	    Get Time of save logic node.
	    @param logic node(LogicNode *)
	    @return time_t.
	*/
	time_t getLNodeTime(LogicNode *);

	/**
	    Get hash of previous block logic's node.
	    @param logic node(LogicNode *) 
	    @return const char *.
	*/
	const char * setLNodeLastBlockHash(LogicNode *);

	/**
	    Get the last block header stringify information.
	    @param logic node(LogicNode *)
	    @return const char *.
	*/
	const char * setLNodeLastBlockParts(LogicNode *);

	/**
	    Get hash of current  logic node.
	    @param logic node(LogicNode *)
	    @return const char *.
	*/
	const char * setLNodeStateHash(LogicNode *);

	/**
	 * ************************************************************************
	 * 					SETTER METHODS OF BODY OG LOGIC NODE				   *
	 * ************************************************************************
	 **/

	/**
	    Set data of logic node in chain.
	    @param logic node(LogicNode *) and chain id to assign (char *)
	    @return void.
	*/
	void setLNodeData(LogicNode *, DATA);


	/**
	 * ************************************************************************
	 * 					GETTER METHODS OF BODY OG LOGIC NODE				  *
	 * ************************************************************************
	 **/

	/**
	    Get data of logic node in chain.
	    @param logic node(LogicNode *)
	    @return const char*.
	*/
	const DATA getLNodeData(LogicNode *);

#endif
