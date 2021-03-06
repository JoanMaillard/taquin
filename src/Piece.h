#include <iostream>

#ifndef LABO12_ASD_PIECE_H
#define LABO12_ASD_PIECE_H

struct Piece {
   int valeur;
   int x;
   int y;
};

Piece initPiece(int valeur, int x, int y );
void swap(Piece& lhs, Piece& rhs);
std::ostream& operator<<(std::ostream& out, const Piece &a);

#endif //LABO12_ASD_PIECE_H
