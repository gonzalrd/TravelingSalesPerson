#include "MatrixGraph.h"



 MatrixGraph::MatrixGraph(unsigned num_nodes){
	 M = std::vector<std::vector<EdgeWeight> > ();
	 M.resize(num_nodes);
	 //TO DO:need to resize each node in M to be num_nodes
	 
	 for(int n = 0; n < M.size(); n++){

		 M.at(n).resize(num_nodes);
		 
	 }


  }
 MatrixGraph::~MatrixGraph(){};

  // Modifiers
 void MatrixGraph::addEdge(NodeID u, NodeID v, EdgeWeight weight){
 /// every vector of u contains weights with id's v.
	 if(u < M.size() && v < M.size() && u!=v && weight > 0){
	
		 M[u][v] = weight;
		 M[v][u] = weight;


	 }
 
 }
  
  // Inspectors
 EdgeWeight MatrixGraph::weight(NodeID u, NodeID v) const{
	
	 EdgeWeight wght = M[u][v];
	 return wght;
 }
 //virtual std::list<NWPair> getAdj(NodeID u) const;
 unsigned MatrixGraph::degree(NodeID u) const{return 0.0;}
 std::list<NWPair> MatrixGraph::getAdj(NodeID u) const{

	std::list<NWPair> n;
	 
	 return n; //look at notes for how a matrix is formed with the num edges and notes
	  }
 unsigned MatrixGraph::size() const{return 0.0;}
 unsigned MatrixGraph::numEdges() const{return 0.0;}