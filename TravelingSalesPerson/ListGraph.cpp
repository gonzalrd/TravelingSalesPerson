#include "ListGraph.h"



ListGraph::ListGraph(int numNodes){

	edgeList = std::vector<EList>();
	edgeList.resize(numNodes); //274 class lecture
	num_edges = 0;
	

}

ListGraph::~ListGraph(){
	//deconstructor
}

//used ajduberstein HW05 code to learn how to use NWpairs and add them correctly to edgelist
void ListGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
	
	if(u < edgeList.size() && v < edgeList.size() && u!=v && weight>0){
		edgeList.at(u).push_back(NWPair(v,weight));
		edgeList.at(v).push_back(NWPair(u,weight));

		num_edges = num_edges + 1;
	}

}

EdgeWeight ListGraph::weight(NodeID u, NodeID v)const{
	
	EdgeWeight wght = 0.0;

	EList uLst = edgeList.at(u);

	std::list<NWPair>::iterator it;
	//got syntax for list from http://www.cplusplus.com/reference/list/list/begin/
	for( it=uLst.begin(); it!=uLst.end(); it++){
		if(v == it->first){
			wght = it->second;
		}
	}

	return wght;
}


unsigned ListGraph::degree(NodeID u) const{ 

	unsigned dg = -1.0;
	if(u < edgeList.size()){
		dg = edgeList.at(u).size();
	}
	return dg;
}
std::list<NWPair> ListGraph::getAdj(NodeID u) const{

	return edgeList.at(u);
	
	
};
unsigned ListGraph::size() const{ return edgeList.size();}

unsigned ListGraph::numEdges() const { return num_edges;}