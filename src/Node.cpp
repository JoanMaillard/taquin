#include "Node.h"
#define FACTEUR_ELARGISSEMENT 1

Node::Node(Taquin taquin, int level, std::vector<int> previousMoves) {
	_taquin = taquin;
	_level = level;
	updatePriority();
	_previousMoves = previousMoves;
}

Node::Node(std::array<int, 9> array) {
	_taquin = Taquin(array);
	_level = 0;
	updatePriority();
}

Taquin Node::getTaquin() {
	return _taquin;
}

int Node::getLevel() const {
	return _level;
}

int Node::getPriority() const {
	return _priority;
}

std::vector<int> Node::getPossibleMoves() const {
	return _taquin.getPossibleMoves();
}


std::vector<int> Node::getPreviousMoves() const {
	return _previousMoves;
}

void Node::updatePriority() {
	_priority = _level + manhattanDistance() * FACTEUR_ELARGISSEMENT;
}

const int Node::manhattanDistance() {
	return _taquin.distanceManhattan();
}

bool operator<(const Node &a, const Node &b) {
	return a.getPriority() > b.getPriority();
}
