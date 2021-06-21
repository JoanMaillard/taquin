#include "Pathfinder.h"
#include "Node.h"
#include "Taquin.h"
#include <map>
#include <string>
#include <iostream>

void push(std::map<Taquin, Node>& map, Node node){
	auto tempNodePtr = map.find(node.getTaquin());
	if (tempNodePtr == map.end()) {
		map[node.getTaquin()] = node;
	} else if (tempNodePtr->second.getPriority() > node.getPriority()) {
		map[node.getTaquin()] = node;
	}
}

Node top(const std::map<Taquin, Node>& map) {
	Taquin returnIndex = map.begin()->first;
	int lowestPriority = map.begin()->second.getPriority();

	for (auto it = ++map.begin(); it != map.end(); ++it) {
		int priority = it->second.getPriority();
		if (priority < lowestPriority) {
			returnIndex = it->first;
			lowestPriority = priority;
		}
	}
	return map.find(returnIndex)->second;
}

void pop(std::map<Taquin, Node>& map) {
	map.erase(top(map).getTaquin());
}

std::string pathFind(const Node startNode) {
	static int index = 0;// index de queue
	Node currentNode = startNode; // node de départ
	std::string toReturn = "";


	std::map<Taquin, Node> openList; // map de Taquin-Node.
	push(openList, startNode); // push la première node dans la map


	do {
		currentNode = top(openList);
		std::cout << "Current node: " << currentNode << std::endl;
		pop(openList);
		std::vector<int> nextMoves = currentNode.getPossibleMoves(); // liste des mouvements possibles avec la situation actuelle

		// generation de toutes les possibilites suivantes et adjonction dans la openList
		for (int i = 0; i < nextMoves.size(); ++i) {
			std::vector<int> tempPreviousMoves = currentNode.getPreviousMoves();// copie de liste de mouvements precedents de la node actuelle

			tempPreviousMoves.push_back(nextMoves[i]); // adjonction du dernier mouvement a la copie de liste
			Taquin tempTaquin = currentNode.getTaquin(); // copie du taquin actuel
			int tempPiece = tempTaquin.trouvePiece(0);
			tempTaquin.swapPiece(tempPiece, nextMoves[i]); // modification de la copie

			push(openList, (Node){tempTaquin, currentNode.getLevel()+currentNode.getPriority(), tempPreviousMoves});// construction et adjonction de la nouvelle node dans la openList
			++index;

		}
		// test de resolution
		if (currentNode.getTaquin().estResolu()) {
			std::cout << "Solution la plus courte :";
			while (!openList.empty()) {
				pop(openList); // destruction de toutes les nodes restantes, garbage collection
			}
			for (int i = 0; i < currentNode.getPreviousMoves().size(); ++i) {
				std::cout << currentNode.getPreviousMoves()[i] << " "; // display
			}
		}

	} while (!openList.empty()); // infinite loop guard


	return toReturn;
}
