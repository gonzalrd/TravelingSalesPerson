#include "GraphAlgs.h";




std::vector<NodeID> curIds;
//EdgeWeight best;


//solves the traveling salesperson problem defined it its .h file
std::pair<std::vector<NodeID>, EdgeWeight> TSP(Graph* G){
curIds = std::vector<NodeID>();
EdgeWeight n = 0.0;

EdgeWeight bestFound = BestTour(G, 0,n);


std::pair<std::vector<NodeID>, EdgeWeight> bestTour = make_pair(curIds, bestFound);
 
return bestTour;
}
 EdgeWeight BestTour(Graph* G, int startPoint, EdgeWeight bestSoFar){

	EdgeWeight cur = 0.0;
	std::vector<NodeID> Ids = std::vector<NodeID>();
	
		if(G->size()-startPoint == 1){
				return bestSoFar;
			}
		else{
//this method needs to loop back around to get all of the points
		for(int i = startPoint; i<G->size(); i++){
			if(i != G->size()-1){//check for last one so you dont go out of bounds
				 cur = cur + G->weight(i , i+1);
				 Ids.push_back(i);
				 if( cur > bestSoFar && bestSoFar !=0){// branch and bound
					 return BestTour(G, startPoint +1 , bestSoFar);
				 }
			}
			else {
				//adds the last one the TSP
				cur = cur + G->weight(i , 0);
				 Ids.push_back(i);
			}
			}
		
		//add the ones before the startpoint to the end
	for(int j = 0; j < startPoint; j++){
			cur = cur + G->weight(j , j+1);
				 if( cur > bestSoFar && bestSoFar !=0){// branch and bound
					 return BestTour(G, startPoint +1 , bestSoFar);
				 }
			Ids.push_back(j);
		}

		if(bestSoFar > cur || bestSoFar == 0){
			bestSoFar = cur;
			curIds = Ids;
			bestSoFar = BestTour(G, startPoint+1, bestSoFar);
		}
//I would no longer need the following
//		else if(best == 0){ 
//			best = cur;
//			curIds = Ids;
//			 best = BestTour(G, startPoint+1);
//		}
//
//		else{
//			
//			 best = BestTour(G, startPoint+1);
//			}
//
//			return best;
//		
		return bestSoFar;

		}
}