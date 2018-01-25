#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NEIGHBOUR 10
#include "physic_node.h"

/**
    Implementation, physic_node.h
    Purpose: Interface of PhysiNode
    @author feavfeav@gmail.com
    @version 1.0 03/01/18 
*/
struct node
{
    char *name;
    char *ip;
    char *port;
    char protocole;
    char *publicKey;
    int maxSize;
    int size;
    struct node ***neighbours;
};

void StrCpy(const char *, char *);

/**
    Create empty physic's node.
    @param void
    @return PhysicNode.
*/
PhysicNode createPhysicNode(){
	PhysicNode pNode= (PhysicNode) malloc(sizeof(struct node));
	pNode->size = 0;
	pNode->maxSize = MAX_NEIGHBOUR;
}
/**
    Copy a string and allocate space for it
    @param nameDst (char *) and nameSrc (char *)
    @return void.
*/
void StrCpy(char **src, const char *dst){
	if(dst){
		*src = (char*)malloc(strlen(dst)*sizeof(char));
		if(*src){
			strcpy(*src,dst);
		}
	}
}


/**
    Set name of physic node.
    @param  nd physic node(PhysicNode *) and name to assign (char *)
    @return void.
*/
void setName(PhysicNode *nd, const char *name){
	if(*nd){
		StrCpy(&(*nd)->name,name);
	}
}

/**
    Set ip of physic node.
    @param physic node(PhysicNode *) and ip to assign (char *)
    @return void.
*/
void setIp(PhysicNode *nd, const char *ip){
	if(*nd){
		StrCpy(&(*nd)->ip,ip);
	}
}

/**
    Set port of communication of physic node.
    @param physic node(PhysicNode *) and port to assign (char *)
    @return void.
*/
void setPort(PhysicNode *nd, const char *port){
	if(*nd){
		StrCpy(&(*nd)->port,port);
	}
}

/**
    Set protocol using for communication of physic node.
    @param physic node(PhysicNode *) and protocole to assign (char)
    @return void.
*/
void setProtocol(PhysicNode *nd, char protocole){
	if(*nd){
		(*nd)->protocole=protocole;
	}
}

/**
    Set public key using for communication with another physic node.
    @param physic node(PhysicNode *) and publicKey to assign (char *)
    @return void.
*/
void setPublicKey(PhysicNode *nd, const char *publicKey){
	if(*nd){
		StrCpy(&(*nd)->publicKey,publicKey);
	}
}



/**
    Add neighbour to local neighbours list
    @param physic node(PhysicNode * nd) and neighbours to add (PhysicNode ng)
    @return void.
*/
void pNodeAddNeighbour(PhysicNode *nd,PhysicNode* ng){
	if(*nd){
		int size = pNodeNeighbourLength(*nd);
		/**
			If list is yet empty we initilize if to MAX_NEIGHBOUR length
		*/
		if(size==0){
			(*nd)->neighbours = (PhysicNode**) malloc(MAX_NEIGHBOUR*sizeof(PhysicNode*));
			(*nd)->size = 0;
			(*nd)->maxSize = MAX_NEIGHBOUR;
		}

		/**
			If list is yet full we double his length
		*/
		if(size >= (*nd)->maxSize){
 			if(realloc((*nd)->neighbours,2*(*nd)->maxSize*sizeof(PhysicNode*)))
 				(*nd)->maxSize *= 2;
		}


		/**
			Now add node neighbour
		*/
		(*nd)->neighbours[(*nd)->size] = ng;
		(*nd)->size++;
	}
}

/**
    Remove neighbour to local neighbours list
    @param physic node(PhysicNode *) and neighbours to remove (PhysicNode )
    @return void.
*/
const PhysicNode *pNodeRemoveNeighbour(PhysicNode *nd,PhysicNode* ng){
	if(*nd){
		int size = pNodeNeighbourLength(*nd),i,overwrite=0;
		for(i=0;i<size;i++){
			/**
			    Overwrite the previous nodes with the next
			*/
			if(overwrite && i)
				(*nd)->neighbours[i-1] = (*nd)->neighbours[i];

			/**
			    Overwrite when we have find the node to remove
			*/
			if(!strcmp((*(*nd)->neighbours[i])->publicKey, (*ng)->publicKey))
				overwrite = 1;
		}

		/**
			Update length of neighbour
		*/
		if(overwrite)
			(*nd)->size--;
	}
}

/**
    Destroy PhysicNode and his depencees
    @param physic node(PhysicNode *)
    @return void.
*/
void pNodeDestroy(PhysicNode *nd){
	if(*nd){
		/**
			Free list of his neighbours
		*/
		free((*nd)->neighbours);
		/**
			Free node
		*/
		free(*nd);
	}
}


/**
    Return name of PhysicNode
    @param physic node(PhysicNode *)
    @return name.
*/
const char * getName(PhysicNode nd){
	if(nd){
		return nd->name;
	}
	return NULL;
}

/**
    Return ip address of PhysicNode
    @param physic node(PhysicNode *)
    @return ip.
*/
const char * getIp(PhysicNode nd){
	if(nd){
		return nd->ip;
	}
	return NULL;
}

/**
    Return port  of PhysicNode
    @param physic node(PhysicNode *)
    @return port.
*/
const char * getPort(PhysicNode nd){
	if(nd){
		return nd->port;
	}
	return NULL;
}

/**
    Return protocol  of PhysicNode
    @param physic node(PhysicNode *)
    @return protocol.
*/
char getProtocol(PhysicNode nd){
	if(nd){
		return nd->protocole;
	}
	return 0;
}

/**
    Return public key  of PhysicNode
    @param physic node(PhysicNode *)
    @return privete_key.
*/
const char * getPublicKey(PhysicNode nd){
	if(nd){
		return nd->publicKey;
	}
	return NULL;
}


/**
    Return PhysicNode if it's neighbour of PhysicNode
    @param physic node(PhysicNode ) and public key (char *)
    @return PhysicNode.
*/
PhysicNode *pNodeFind(PhysicNode nd, const char *publicKey){

	if(nd){
		int size = pNodeNeighbourLength(nd),i;
		for(i=0;i<size;i++){
			/**
			    Find a reseach node
			*/
			if(!strcmp((*(nd)->neighbours[i])->publicKey, publicKey))
				return (nd)->neighbours[i];
		}

	}
	return NULL;
}

/**
    Return number of neighbour of PhysicNode
    @param physic node(PhysicNode)
    @return lengh.
*/
int pNodeNeighbourLength(PhysicNode nd){
	if(nd){
		return nd->size;
	}
	return 0;
}

/**
    print PhysicNode and his neighbour
    @param physic node(PhysicNode )
    @return void.
*/
void pNodePrint(PhysicNode nd){
	if(nd){
		printf("\n---------------------------%d\n", pNodeNeighbourLength(nd));
		int size = pNodeNeighbourLength(nd),i;
		printf("NAME : %s\n",nd->name);
		printf("IP : %s\n",nd->ip);
		printf("PORT : %s\n",nd->port);
		printf("PROTOCOLE : %c\n",nd->protocole);
		printf("NEIGHBOUR : %d\n",nd->size);
		printf("PUBLIC KEY : %s\n",nd->publicKey);
		for(i=0;i<size;i++)
			printf("\tNAME =  %s | ADSRESS = %s:%s | PUBLIC KEY :%s  \n",(*nd->neighbours[i])->name,(*nd->neighbours[i])->ip,(*nd->neighbours[i])->port,(*nd->neighbours[i])->publicKey);
	}
	
}
