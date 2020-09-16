#include "graph.h"
#include <stdio.h>

void buildFirstTopology(){

    int vertex = 3;
    int edges = 3;
    graph *topology = createGraph(vertex,edges);  	// Graph creation

    /*
				   
				  		  +-----------+
		              0/2 |   R0      | 0/0					10
		 +----------------+           +--------------------------+
		 |     	   		  | 	      |                          |
		 |                +-----------+                          |
	30	 |                                                       |
		 |                                                       |
		 |                                                       |
		 |                                            	   		 |
		 |0/2                                                    |0/1
	     +---+---+                                              +----+-----+
	     |       |0/1                                        0/2|          |
	     | R2    +----------------------------------------------+    R1    |
	     |       |               15       	      		        |          |
	     +-------+                                              +----------+
	   						

*/
    node *router0 = & (topology->routersArray[0]);
    node *router1 = & (topology->routersArray[1]);
    node *router2 = & (topology->routersArray[2]);
    
    
    addEdge(topology,router0,router1,"eth0/0","eth0/1",10);
    addEdge(topology,router1,router2,"eth0/2","eth0/1",15);
    addEdge(topology,router2,router0,"eth0/2","eth0/2",30);

    initializeRoutingTables(topology);

    // printGraph(topology);
    activateTopology(topology);
    // printRoutingTables(topology);

    // printEdges(topology,edges);

	// bellmanFord(topology,vertex,edges,router0,0);

    updatedBellmanFord(topology,vertex,edges,router0);

	printRoutingTables(topology);

    // bellmanFord(topology,vertex,edges,router0,0);
    
}



void buildSecondTopology(){

    int vertex = 10;
    int edges = 45;
    graph *topology = createGraph(vertex,edges);  	// Graph creation

    node *router0 = & (topology->routersArray[0]);
    node *router1 = & (topology->routersArray[1]);
    node *router2 = & (topology->routersArray[2]);
    node *router3 = & (topology->routersArray[3]);
    node *router4 = & (topology->routersArray[4]);
    node *router5 = & (topology->routersArray[5]);
    node *router6 = & (topology->routersArray[6]);
    node *router7 = & (topology->routersArray[7]);
    node *router8 = & (topology->routersArray[8]);
    node *router9 = & (topology->routersArray[9]);
    
    addEdge(topology,router0,router1,"eth0/1","eth1/1",1);
    addEdge(topology,router0,router2,"eth0/2","eth2/1",3);
    addEdge(topology,router0,router3,"eth0/3","eth3/1",5);
    addEdge(topology,router0,router4,"eth0/4","eth4/1",7);
    addEdge(topology,router0,router5,"eth0/5","eth5/1",9);
    addEdge(topology,router0,router6,"eth0/6","eth6/1",11);
    addEdge(topology,router0,router7,"eth0/7","eth7/1",13);
    addEdge(topology,router0,router8,"eth0/8","eth8/1",15);
    addEdge(topology,router0,router9,"eth0/9","eth9/1",17);
    addEdge(topology,router1,router2,"eth1/2","eth2/2",19);
    addEdge(topology,router1,router3,"eth1/3","eth3/2",21);
    addEdge(topology,router1,router4,"eth1/4","eth4/2",23);
    addEdge(topology,router1,router5,"eth1/5","eth5/2",26);
    addEdge(topology,router1,router6,"eth1/6","eth6/2",29);
    addEdge(topology,router1,router7,"eth1/7","eth7/2",32);
    addEdge(topology,router1,router8,"eth1/8","eth8/2",35);
    addEdge(topology,router1,router9,"eth1/9","eth9/2",38);
    addEdge(topology,router2,router3,"eth2/3","eth3/3",5);
    addEdge(topology,router2,router4,"eth2/4","eth4/3",10);
    addEdge(topology,router2,router5,"eth2/5","eth5/3",15);
    addEdge(topology,router2,router6,"eth2/6","eth6/3",20);
    addEdge(topology,router2,router7,"eth2/7","eth7/3",25);
    addEdge(topology,router2,router8,"eth2/8","eth8/3",30);
    addEdge(topology,router2,router9,"eth2/9","eth9/3",35);
    addEdge(topology,router3,router4,"eth3/4","eth4/4",40);
    addEdge(topology,router3,router5,"eth3/5","eth5/4",4);
    addEdge(topology,router3,router6,"eth3/6","eth6/4",8);
    addEdge(topology,router3,router7,"eth3/7","eth7/4",12);
    addEdge(topology,router3,router8,"eth3/8","eth8/4",16);
    addEdge(topology,router3,router9,"eth3/9","eth9/4",20);
    addEdge(topology,router4,router5,"eth4/5","eth5/5",24);
    addEdge(topology,router4,router6,"eth4/6","eth6/5",28);
    addEdge(topology,router4,router7,"eth4/7","eth7/5",32);
    addEdge(topology,router4,router8,"eth4/8","eth8/5",36);
    addEdge(topology,router4,router9,"eth4/9","eth9/5",40);
    addEdge(topology,router5,router6,"eth5/6","eth6/6",6);
    addEdge(topology,router5,router7,"eth5/7","eth7/6",12);
    addEdge(topology,router5,router8,"eth5/8","eth8/6",18);
    addEdge(topology,router5,router9,"eth5/9","eth9/6",24);
    addEdge(topology,router6,router7,"eth6/7","eth7/7",30);
    addEdge(topology,router6,router8,"eth6/8","eth8/7",36);
    addEdge(topology,router6,router9,"eth6/9","eth9/7",42);
    addEdge(topology,router7,router8,"eth7/8","eth8/8",7);
    addEdge(topology,router7,router9,"eth7/9","eth9/8",14);
    addEdge(topology,router8,router9,"eth8/9","eth9/9",21);
    

    initializeRoutingTables(topology);
    // printRoutingTables(topology);
    activateTopology(topology);
    // printRoutingTables(topology);

    // printRoutingTables(topology);

    // printGraph(topology);

    // printRoutingTables(topology);

    // printEdges(topology,edges);

	// bellmanFord(topology,vertex,edges,router9,9);

    updatedBellmanFord(topology,vertex,edges,router3);

	printRoutingTables(topology);

    // initializeRoutingTables(topology);          bellmanFord(topology,vertex,edges,router0,0);
    // initializeRoutingTables(topology);          bellmanFord(topology,vertex,edges,router1,1);
    // initializeRoutingTables(topology);          bellmanFord(topology,vertex,edges,router2,2);
    // initializeRoutingTables(topology);          bellmanFord(topology,vertex,edges,router3,3);
    // initializeRoutingTables(topology);          bellmanFord(topology,vertex,edges,router4,4);
    // initializeRoutingTables(topology);          bellmanFord(topology,vertex,edges,router5,5);
    // initializeRoutingTables(topology);          bellmanFord(topology,vertex,edges,router6,6);
    // initializeRoutingTables(topology);          bellmanFord(topology,vertex,edges,router7,7);
    // initializeRoutingTables(topology);          bellmanFord(topology,vertex,edges,router8,8);
    // initializeRoutingTables(topology);          bellmanFord(topology,vertex,edges,router9,9);
    
}


void buildThirdTopology(){

    int vertex = 5;
    int edges = 5;
    graph *topology = createGraph(vertex,edges);  	// Graph creation

  
    node *router0 = & (topology->routersArray[0]);
    node *router1 = & (topology->routersArray[1]);
    node *router2 = & (topology->routersArray[2]);
    node *router3 = & (topology->routersArray[3]);
    node *router4 = & (topology->routersArray[4]);
    
    
    addEdge(topology,router0,router1,"eth0/0","eth0/1",1);
    addEdge(topology,router1,router2,"eth0/2","eth0/1",6);
    addEdge(topology,router2,router3,"eth0/2","eth0/2",2);
    addEdge(topology,router3,router4,"eth0/2","eth0/2",4);
    addEdge(topology,router4,router1,"eth0/2","eth0/2",3);

    initializeRoutingTables(topology);

    activateTopology(topology);

    // printGraph(topology);
    // printRoutingTables(topology);
    // printEdges(topology,edges);
    // bellmanFord(topology,vertex,edges,router0,0);

    updatedBellmanFord(topology,vertex,edges,router0);

	printRoutingTables(topology);
    
}

void buildFourthTopology(){

    int vertex = 10;
    int edges = 24;
    graph *topology = createGraph(vertex,edges);  	// Graph creation

    node *router0 = & (topology->routersArray[0]);
    node *router1 = & (topology->routersArray[1]);
    node *router2 = & (topology->routersArray[2]);
    node *router3 = & (topology->routersArray[3]);
    node *router4 = & (topology->routersArray[4]);
    node *router5 = & (topology->routersArray[5]);
    node *router6 = & (topology->routersArray[6]);
    node *router7 = & (topology->routersArray[7]);
    node *router8 = & (topology->routersArray[8]);
    node *router9 = & (topology->routersArray[9]);
    
    addEdge(topology,router0,router1,"eth0/1","eth1/1",1);
    addEdge(topology,router0,router2,"eth0/2","eth2/1",3);
    addEdge(topology,router0,router8,"eth0/8","eth8/1",15);
    addEdge(topology,router0,router9,"eth0/9","eth9/1",17);
    addEdge(topology,router1,router2,"eth1/2","eth2/2",19);
    addEdge(topology,router1,router3,"eth1/3","eth3/2",21);
    addEdge(topology,router1,router9,"eth1/9","eth9/2",15);
    addEdge(topology,router2,router3,"eth2/3","eth3/3",5);
    addEdge(topology,router2,router4,"eth2/4","eth4/3",10);
    addEdge(topology,router2,router7,"eth2/7","eth7/3",15);
    addEdge(topology,router2,router8,"eth2/8","eth8/3",30);
    addEdge(topology,router3,router4,"eth3/4","eth4/4",20);
    addEdge(topology,router3,router5,"eth3/5","eth5/4",4);
    addEdge(topology,router3,router7,"eth3/7","eth7/4",12);
    addEdge(topology,router3,router8,"eth3/8","eth8/4",16);
    addEdge(topology,router4,router5,"eth4/5","eth5/5",24);
    addEdge(topology,router4,router6,"eth4/6","eth6/5",28);
    addEdge(topology,router5,router6,"eth5/6","eth6/6",6);
    addEdge(topology,router5,router7,"eth5/7","eth7/6",12);
    addEdge(topology,router6,router7,"eth6/7","eth7/7",30);
    addEdge(topology,router6,router8,"eth6/8","eth8/7",16);
    addEdge(topology,router7,router8,"eth7/8","eth8/8",7);
    addEdge(topology,router7,router9,"eth7/9","eth9/8",14);
    addEdge(topology,router8,router9,"eth8/9","eth9/9",21);
    

    initializeRoutingTables(topology);
    activateTopology(topology);

    // printGraph(topology);

    // printRoutingTables(topology);

    // printEdges(topology,edges);

    updatedBellmanFord(topology,vertex,edges,router0);

	printRoutingTables(topology);
    
}
