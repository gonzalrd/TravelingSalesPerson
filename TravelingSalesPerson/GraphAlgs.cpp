#include "GraphAlgs.h";




std::vector<NodeID> curIds;
EdgeWeight best;


//solves the traveling salesperson problem defined it its .h file
std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){
curIds = std::vector<NodeID>();

EdgeWeight bestFound = BestTour(G, 0);


std::pair<std::vector<NodeID>, EdgeWeight> bestTour = make_pair(curIds, best);
 
return bestTour;
}
 EdgeWeight BestTour(Graph* G, int startPoint){

	 EdgeWeight cur = 0.0;

	std::vector<NodeID> Ids = std::vector<NodeID>();

			
		if(G->size()-startPoint == 1){
				return best;
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

		 best = BestTour(G, startPoint+1);

		if(best > cur && cur!=0){
			best = cur;
			curIds = Ids;
			return best;
		}

		else if(best == 0.0){
			best = cur;
			return BestTour(G, startPoint+1);
		}

		else return BestTour(G, startPoint+1);

}