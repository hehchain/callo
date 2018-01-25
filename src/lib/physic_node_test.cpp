#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "physic_node.h"
void testCreatePhysicNode();
void testAddNeighborPhysicNode();
int main(){
	//testCreatePhysicNode();
	testAddNeighborPhysicNode();
	return 1;
}

void testCreatePhysicNode(){
	/*
	*  TEST CREATION OF PHYSIC NODE
	**/
	printf("*************************************************\n");
	printf("************* TEST CREATE PHYSIC NODE ***********\n");
	printf("*************************************************\n");
	PhysicNode physicNode = createPhysicNode();
	setPNodeName(&physicNode,"PC EMBOLO");
	setPNodeIp(&physicNode,"192.168.122.4");
	setPNodePort(&physicNode,"3345");
	setPNodeProtocol(&physicNode,'3');
	setPNodePublicKey(&physicNode,"8hf48c873eh3e38u92je");
	pNodePrint(physicNode);
	pNodeDestroy(&physicNode);
}
void testAddNeighborPhysicNode(){
	/*
	*  TEST ADD NEIGHBOR OF PHYSIC NODE
	**/
	printf("*************************************************\n");
	printf("********** TEST ADD NEIGHBOR PHYSIC NODE ********\n");
	printf("*************************************************\n");
	PhysicNode physicNode = createPhysicNode();
	setPNodeName(&physicNode,"PC EMBOLO");
	setPNodeIp(&physicNode,"192.168.122.48");
	setPNodePort(&physicNode,"3345");
	setPNodeProtocol(&physicNode,'3');
	setPNodePublicKey(&physicNode,"8hf48c873eh3e38u92je");
	
	//printf("\n************ BEFORE ADDING NEIGHBOR **********\n");
	pNodePrint(physicNode);


	PhysicNode physicNode1 = createPhysicNode();
	setPNodeName(&physicNode1,"PC 1");
	setPNodeIp(&physicNode1,"132.38.12.4");
	setPNodePort(&physicNode1,"3345");
	setPNodeProtocol(&physicNode1,'3');
	setPNodePublicKey(&physicNode1,"232uy3g23872hd872h8f8");
	pNodePrint(physicNode1);


	PhysicNode physicNode2 = createPhysicNode();
	setPNodeName(&physicNode2,"PC 2");
	setPNodeIp(&physicNode2,"192.138.32.41");
	setPNodePort(&physicNode2,"3345");
	setPNodeProtocol(&physicNode2,'3');
	setPNodePublicKey(&physicNode2,"87h83hddhy2gd39pp983j");
	pNodePrint(physicNode2);


	PhysicNode physicNode3 = createPhysicNode();
	setPNodeName(&physicNode3,"PC 3");
	setPNodeIp(&physicNode3,"192.38.132.02");
	setPNodePort(&physicNode3,"3345");
	setPNodeProtocol(&physicNode3,'3');
	setPNodePublicKey(&physicNode3,"3738f83oho34878fh48f3");
	pNodePrint(physicNode3);

	printf("\n************ AFTER ADDING NEIGHBORS PC1 PC2 PC3 to PC EMBOLO **********\n");
	pNodeAddNeighbour(&physicNode,&physicNode1);
	pNodeAddNeighbour(&physicNode,&physicNode2);
	pNodeAddNeighbour(&physicNode,&physicNode3);
	pNodePrint(physicNode);
	pNodePrint(physicNode1);
	pNodePrint(physicNode2);
	pNodePrint(physicNode3);
	
	
	pNodeDestroy(&physicNode);
	pNodeDestroy(&physicNode1);
	pNodeDestroy(&physicNode2);
	pNodeDestroy(&physicNode3);
}


void testRemoveNeighborPhysicNode(){
	/*
	*  TEST ADD NEIGHBOR OF PHYSIC NODE
	**/
	printf("*************************************************\n");
	printf("********** TEST ADD NEIGHBOR PHYSIC NODE ********\n");
	printf("*************************************************\n");
	PhysicNode physicNode = createPhysicNode();
	setPNodeName(&physicNode,"PC EMBOLO");
	setPNodeIp(&physicNode,"192.168.122.48");
	setPNodePort(&physicNode,"3345");
	setPNodeProtocol(&physicNode,'3');
	setPNodePublicKey(&physicNode,"8hf48c873eh3e38u92je");
	
	//printf("\n************ BEFORE ADDING NEIGHBOR **********\n");
	pNodePrint(physicNode);


	PhysicNode physicNode1 = createPhysicNode();
	setPNodeName(&physicNode1,"PC 1");
	setPNodeIp(&physicNode1,"132.38.12.4");
	setPNodePort(&physicNode1,"3345");
	setPNodeProtocol(&physicNode1,'3');
	setPNodePublicKey(&physicNode1,"232uy3g23872hd87h8f8");
	//pNodePrint(physicNode1);


	PhysicNode physicNode2 = createPhysicNode();
	setPNodeName(&physicNode2,"PC 2");
	setPNodeIp(&physicNode2,"192.138.32.41");
	setPNodePort(&physicNode2,"3345");
	setPNodeProtocol(&physicNode2,'3');
	setPNodePublicKey(&physicNode2,"87h83hddhy2gd39pp98j");
	//pNodePrint(physicNode2);


	PhysicNode physicNode3 = createPhysicNode();
	setPNodeName(&physicNode3,"PC 3");
	setPNodeIp(&physicNode3,"192.38.132.2");
	setPNodePort(&physicNode3,"3345");
	setPNodeProtocol(&physicNode3,'3');
	setPNodePublicKey(&physicNode3,"3738f83oho34878fh48f3");
	//pNodePrint(physicNode3);

	printf("\n************ AFTER ADDING NEIGHBORS PC1 PC2 PC3 to PC EMBOLO **********\n");
	pNodeAddNeighbour(&physicNode,&physicNode1);
	pNodeAddNeighbour(&physicNode,&physicNode2);
	pNodeAddNeighbour(&physicNode,&physicNode3);
	pNodePrint(physicNode);

	printf("\n************ AFTER REMOVING NEIGHBORS  PC1 PC3 to PC EMBOLO **********\n");
	pNodeRemoveNeighbour(&physicNode,&physicNode1);
	pNodeRemoveNeighbour(&physicNode,&physicNode3);
	pNodePrint(physicNode);

	pNodeDestroy(&physicNode);
	pNodeDestroy(&physicNode1);
	pNodeDestroy(&physicNode2);
	pNodeDestroy(&physicNode3);
}
