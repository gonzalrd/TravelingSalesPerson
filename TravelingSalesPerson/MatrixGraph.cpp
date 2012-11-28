#include "MatrixGraph.h"



 MatrixGraph::MatrixGraph(unsigned num_nodes){
	 M.resize(num_nodes);
  }
 MatrixGraph::~MatrixGraph(){};

  // Modifiers
 void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){}
  
  // Inspectors
 EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const{return 0.0;}
 //virtual std::list<NWPair> getAdj(NodeID u) const;
 unsigned MatrixGraph::degree(NodeID u) const{return 0.0;}
 std::list<NWPair> MatrixGraph::getAdj(NodeID u) const{
	 
	 return ;
	  }
 unsigned MatrixGraph::size() const{return 0.0;}
 unsigned MatrixGraph::numEdges() const{return 0.0;}