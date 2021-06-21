#include "Taquin.h"
#include <stdexcept>
#include <algorithm>
//Taquin resolu/objectif
	Taquin objectif;

//Le constructeur par défaut crée un taquin résolu
Taquin::Taquin(){
	const size_t puzzleSize = puzzle.size();
	for(std::size_t x = 0; x < puzzleSize; ++x){
		for(std::size_t y = 0; y < puzzleSize; ++y){
			size_t valeur = x * puzzleSize  + y;
			puzzle[x][y] = initPiece(valeur, x, y);
		}
	}
	evaluatePossibleMoves(_possibleMoves);
}

//Constructeur avec un tableaux d'elements
Taquin::Taquin(const std::array<int,9>& array){
	if(inputValide(array)) {
		const size_t puzzleSize = puzzle.size();
		for (std::size_t x = 0; x < puzzleSize; ++x) {
			for (std::size_t y = 0; y < puzzleSize; ++y) {
				size_t valeur = array[x * puzzleSize + y];
				puzzle[x][y] = initPiece(valeur, x, y);
			}
		}
		evaluatePossibleMoves(_possibleMoves);
	}
	else {
		throw std::invalid_argument("Taquin pas valide");
	}
}

bool Taquin::estResolu(){
	const size_t puzzleSize = puzzle.size();
	for(std::size_t x = 0; x < puzzleSize; ++x){
		for(std::size_t y= 0; y < puzzleSize; ++y){
			if(puzzle[x][y].valeur != objectif.puzzle[x][y].valeur)
				return false;
		}
	}
	return true;
}

bool inputValide(const std::array<int,9>& array){
	int inversions = 0;

	for ( int i = 0; i < 9; i++ )
		for ( int j = i + 1; j < 9; j++ )
			if ( array[j] > array[i] && array[i] != 0 && array[j] != 0 )
				inversions++;

	// Si le nombre d'inversion est paire le puzzle est valide
	return inversions % 2 == 0;

}

// utilisé pour la distance de Manhattan
int distancePiece(const Piece& piece, int cordX, int cordY){
	int distanceX = abs(piece.x - cordX);
	int distanceY = abs(piece.y - cordY);
	return distanceX + distanceY;
}

int Taquin::distanceManhattan(){
	int distance = 0;
	const size_t puzzleSize = puzzle.size();

	for (size_t x = 0; x < puzzleSize; ++x) {
		for (size_t y = 0; y < puzzleSize; ++y) {
			Piece piece = puzzle[x][y]; // 2 1 5
			int cordX = piece.valeur % 3;
			int cordY = (piece.valeur) / 3;
			distance += distancePiece(piece, cordX, cordY);
		}
	}
	return distance;
}

 // trouve une pièce de la valeur voulue dans le taquin
int Taquin::trouvePiece(int valeur){
	if(!(valeur >= 0 && valeur < 9 )) {
		throw std::invalid_argument("Taquin pas valide");
	}
	const size_t puzzleSize = puzzle.size();
	int toReturn = -1;
	for (size_t x = 0; x < puzzleSize; ++x) {
		for (size_t y = 0; y < puzzleSize; ++y) {
			if (puzzle[x][y].valeur == valeur)
				toReturn =  x * puzzleSize + y;
		}
	}
	if (toReturn != -1) {
		return toReturn;
	} else {
		throw std::runtime_error("Piece introuvable");
	}
}

void Taquin::evaluatePossibleMoves(std::vector<int>& movesTable) {
   const size_t puzzleSize = puzzle.size();
   int index;
   for (size_t x = 0; x < puzzleSize; ++x) {
      for (size_t y = 0; y < puzzleSize; ++y) {
         if (puzzle[x][y].valeur == 0)
            index = x * puzzleSize + y;
      }
   }
  switch (index) {
	 case 0:
		movesTable = std::vector<int>{1, 3};
		break;
	 case 1:
		movesTable = std::vector<int>{0, 2, 4};
		break;
	 case 2:
		movesTable = std::vector<int>{1, 5};
		break;
	 case 3:
		movesTable = std::vector<int>{4, 0, 6};
		break;
	 case 4:
		movesTable = std::vector<int>{3, 5, 1, 7};
		break;
	 case 5:
		movesTable = std::vector<int>{4, 2, 8};
		break;
	 case 6:
		movesTable = std::vector<int>{7, 3};
		break;
	 case 7:
		movesTable = std::vector<int>{6, 8, 4};
		break;
	 case 8:
		movesTable = std::vector<int>{7, 5};
		break;
	 default:
		throw std::out_of_range("Vector pas valide");
  }
}

std::vector<int> Taquin::getPossibleMoves() const {
	return _possibleMoves;
}

void Taquin::swapPiece(int lhs, int rhs) {
	swap(puzzle[lhs/3][lhs%3], puzzle[rhs/3][rhs%3]);
	evaluatePossibleMoves(_possibleMoves);
}