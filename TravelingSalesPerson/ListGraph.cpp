#include "ListGraph.h"



ListGraph::ListGraph(int numNodes){
	edgeList.resize(numNodes); //274 class lecture

}

ListGraph::~ListGraph(){
	//deconstructor
}


void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){}

EdgeWeight ListGraph::weight(NodeID u, NodeID v)const{
	return 0.0;
}


unsigned ListGraph::degree(NodeID u) const{ return 0.0;}
std::list<NWPair> ListGraph::getAdj(NodeID u) const{
	return edgeList.at(u);
};
unsigned ListGraph::size() const{ return 0.0;}
unsigned ListGraph::numEdges() const { return 0.0;}