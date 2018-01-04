#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_NEIGHBOUR 10
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
    char protocol;
    char *publicKey;
    int maxSize;
    int size;
    struct node **neighbours;
};

/**
    Copy a string and allocate space for it
    @param nameDst (char *) and nameSrc (char *)
    @return void.
*/
void StrCpy(char *src, char *dst){
	if(src){
		realloc(src,strlen(dst)*sizeof(char));
		strcpy(src,dst);
	}
}
/**
    Set name of physic node.
    @param physic node(PhysicNode *) and name to assign (char *)
    @return void.
*/
void setName(PhysicNode *nd, char *name){
	if(*nd){
		StrCpy(*nd->name,name);
	}
}

/**
    Set ip of physic node.
    @param physic node(PhysicNode *) and ip to assign (char *)
    @return void.
*/
void setIp(PhysicNode *nd, char *ip){
	if(*nd){
		StrCpy(*nd->ip,ip);
	}
}

/**
    Set port of communication of physic node.
    @param physic node(PhysicNode *) and port to assign (char *)
    @return void.
*/
void setPort(PhysicNode *nd, char *port){
	if(*nd){
		StrCpy(*nd->node,node);
	}
}

/**
    Set protocol using for communication of physic node.
    @param physic node(PhysicNode *) and protocole to assign (char)
    @return void.
*/
void setProtocol(PhysicNode *nd, char protocole){
	if(*nd){
		*nd->ip=ip;
	}
}

/**
    Set public key using for communication with another physic node.
    @param physic node(PhysicNode *) and publicKey to assign (char *)
    @return void.
*/
void setPublicKey(PhysicNode *nd, char *publicKey){
	if(*nd){
		StrCpy(*nd->publicKey,publicKey);
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
			*ng->neighbours = malloc(MAX_NEIGHBOUR*sizeof(PhysicNode));
			*ng->size = 0;
			*ng->maxSize *= MAX_NEIGHBOUR;
		}

		/**
			If list is yet full we double his length
		*/
		if(size >= *ng->maxSize){
 			realloc(*ng->neighbours,2*ng->maxSize*sizeof(PhysicNode));
 			*ng->maxSize *= 2;
		}

		/**
			Now add node neighbour
		*/
		*nd->neighbours[*ng->size] = ng;
		*ng->size++;
	}
}

/**
    Remove neighbour to local neighbours list
    @param physic node(PhysicNode *) and neighbours to remove (PhysicNode )
    @return void.
*/
PhysicNode *pNodeRemoveNeighbour(PhysicNode *nd,PhysicNode* ng){
	if(*nd){
		int size = pNodeNeighbourLength(*nd),i,overwrite=0;
		for(i=0;i<size;i++){
			/**
			    Overwrite the previous nodes with the next
			*/
			if(overwrite && i)
				*nd->neighbours[i-1] = *nd->neighbours[i];

			/**
			    Overwrite when we have find the node to remove
			*/
			if(*nd->neighbours[i] == ng)
				overwrite = 1;
		}

		/**
			Update length of neighbour
		*/
		if(overwrite)
			*ng->size--;
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
		free(*nd->neighbours);
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
}

/**
    Return private key  of PhysicNode
    @param physic node(PhysicNode *)
    @return privete_key.
*/
const char * getPrivateKey(PhysicNode nd){
	if(nd){
		return nd->privateKey;
	}
}

/**
    Return PhysicNode if it's neighbour of PhysicNode
    @param physic node(PhysicNode ) and name (char *)
    @return PhysicNode.
*/
const PhysicNode *pNodeFind(PhysicNode nd, char *name){
	if(nd){
		int size = pNodeNeighbourLength(nd),i;
		for(i=0;i<size;i++){
			if(strcmp(nd->neighbours[i].name,name))
				return nd->neighbours[i];
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
		int size = pNodeNeighbourLength(nd),i;
		printf("NAME : %s\n",nd->name);
		printf("IP : %s\n",nd->ip);
		printf("PORT : %c\n",nd->port);
		printf("PROTOCOLE : %s\n",nd->protocole);
		printf("NEIGHBOUR : %d\n",nd->size);
		for(i=0;i<size;i++)
			printf("\tNAME =  %s | ADSRESS = %s:%s | PUBLIC KEY :%s\n",nd->name,nd->ip,nd->port,nd->publicKey);
	}
	
}

