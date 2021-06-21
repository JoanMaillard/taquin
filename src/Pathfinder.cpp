#include "Pathfinder.h"
#include "Node.h"
#include "Taquin.h"
#include <queue>
#include <string>
#include <iostream>

void push(std::priority_queue<Node>& map, Node node){
	map.push(node);
}

void push(std::vector<Taquin>& map, Taquin taquin){
	map.push_back(taquin);
}

bool has(const std::vector<Taquin>& map, const Taquin &taquin) {
	for (size_t i = 0; i < map.size(); ++i) {
		if (taquin == map[i]) {
			return true;
		}
	}
	return false;
}

Node top(const std::priority_queue<Node>& map) {
	return map.top();
}

void pop(std::priority_queue<Node>& map) {
	map.pop();
}

std::string pathFind(Node startNode) {
	bool solved = false;
	static int index = 0;// index de queue
	Node currentNode = startNode; // node de départ
	std::string toReturn = "";


	std::priority_queue<Node> openList; // map de Taquin-Node.
	std::vector<Taquin> blackList;
	std::cout << "Open list: " << std::endl;
	push(openList, startNode); // push la première node dans la map
	push(blackList, startNode.getTaquin());
	std::cout << "----------------------------------------------" << std::endl;

	do {
		std::cout << "Current node: " << std::endl;
		currentNode = top(openList);
		std::cout << currentNode << std::endl;
		std::vector<int> nextMoves = currentNode.getPossibleMoves(); // liste des mouvements possibles avec la situation actuelle

		// generation de toutes les possibilites suivantes et adjonction dans la openList
		for (int i = 0; i < nextMoves.size(); ++i) {
			std::vector<int> tempPreviousMoves = currentNode.getPreviousMoves();// copie de liste de mouvements precedents de la node actuelle

			tempPreviousMoves.push_back(nextMoves[i]); // adjonction du dernier mouvement a la copie de liste
			Taquin tempTaquin = currentNode.getTaquin(); // copie du taquin actuel
			int tempPiece = tempTaquin.trouvePiece(0);
			tempTaquin.swapPiece(tempPiece, nextMoves[i]); // modification de la copie
			Node tempNode {tempTaquin, currentNode.getLevel()+1, tempPreviousMoves};
			if (!has(blackList, tempNode.getTaquin())) {
				push(openList, tempNode);// construction et adjonction de la nouvelle node dans la openList
				push(blackList, tempNode.getTaquin());
				++index;
			}
		}
		pop(openList);
		// test de resolution
		if (currentNode.getTaquin().estResolu()) {
			solved = true;
			std::cout << "Solution la plus courte :";
			for (size_t i = 0; i < openList.size(); ++i) {
				pop(openList);
			}
			blackList.clear();
			for (int i = 0; i < currentNode.getPreviousMoves().size(); ++i) {
				std::cout << currentNode.getPreviousMoves()[i] << " "; // display
			}
		}

	} while (!openList.empty() && !solved); // infinite loop guard


	return toReturn;
}
