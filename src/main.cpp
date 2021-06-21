/* Important note: this is an algorithm rework of a previous work made by one of this group's submitters.
Most of the framework that was already put in place in order to make the program was reused. However, the
key points of the algorithm itself were given an attempt at a complete rework. */

#include <iostream>
#include <string>
#include "Node.h"
#include "Pathfinder.h"

using namespace std;
int main() {

	std::array<int,9> array;
	int size = array.size();
	//Creation taquin (test)
	cout<<"entrez l'etat du taquin :";
	for(int i = 0; i < size; ++i){
		cin >> array[i];
	}
	Node startingNode(array);

	string result = pathFind(startingNode);

	cout << result;

	return EXIT_SUCCESS;
}

