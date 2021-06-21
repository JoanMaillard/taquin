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

