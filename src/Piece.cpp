#include "Piece.h"
#include <stdexcept>
#include <utility>

Piece initPiece(int valeur, int x, int y ){
   //On peut ajouter des controles ici
   if( valeur < 0 || valeur > 8){
      throw std::out_of_range("Piece pas valide");
   }
   return  (Piece){.valeur = valeur, .x = x, .y = y};
}

void swap(Piece& lhs, Piece& rhs){
   std::swap(lhs.valeur, rhs.valeur);
}