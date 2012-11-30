#include "GraphAlgs.h";




std::vector<NodeID> curIds;
//solves the traveling salesperson problem defined it its .h file
std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){
curIds = std::vector<NodeID>();

EdgeWeight best = BestTour(G, 0);


std::pair<std::vector<NodeID>, EdgeWeight> bestTour = make_pair(curIds, best);
 
return bestTour;
}
 EdgeWeight BestTour(Graph* G, int startPoint){

	std::vector<NodeID> Ids = std::vector<NodeID>();

	EdgeWeight cur = 0.0;
			
		if(G->size()-startPoint == 1){
				return cur;
			}
			else
		//this method needs to loop back around to get all of the points
		for(int i = startPoint; i<G->size(); i++){
			if(i != G->size()-1){//check for last one so you dont go out of bounds
				 cur = cur + G->weight(i , i+1);
				 curIds.push_back(i);
			}
			
			}
		for(int j = 0; j < startPoint; j++){
			cur = cur + G->weight(j , j+1);
			curIds.push_back(j);
		}

		EdgeWeight best = BestTour(G, startPoint+1);

		if(best > cur){
			best = cur;
			curIds = Ids;
			return cur;
		}

		else return BestTour(G, startPoint+1);

}