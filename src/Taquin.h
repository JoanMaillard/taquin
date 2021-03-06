#ifndef LABO12_ASD_TAQUIN_H
#define LABO12_ASD_TAQUIN_H
#include "Piece.h"
#include <string>
#include <array>
#include <vector>
#include <iostream>

class Taquin{
friend std::ostream& operator<<(std::ostream& out, const Taquin &a);
friend bool operator==(const Taquin &lhs, const Taquin &rhs);
friend std::string hash(const Taquin &taquin);
public:
	Taquin();
	Taquin(const std::array<int,9>& array);
	int distanceManhattan() const;
	bool estResolu();
	int trouvePiece(int valeur);
	std::vector<int> getPossibleMoves() const;
	void swapPiece(int lhs, int rhs);
	long long int getValue();

private:
	std::array< std::array < Piece,3 > ,3 > puzzle;
	//Taquin* parent = nullptr;
	std::vector<int> _possibleMoves; // calculé pour permettre à l'algo d'exploration de savoir quels sont les enfants
								// à explorer plus loin dans l'arbre
	void evaluatePossibleMoves(std::vector<int>& movesTable);


};

bool inputSolvable(const std::array<int,9>& array);



#endif //LABO12_ASD_TAQUIN_H
