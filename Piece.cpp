#include "Piece.h"

Piece::Piece()
{
   // Piece();

    pieceCanvas[0][0] = false;
    pieceCanvas[1][0] = true;
    pieceCanvas[2][0] = false;

    pieceCanvas[0][1] = false;
    pieceCanvas[1][1] = true;
    pieceCanvas[2][1] = false;

    pieceCanvas[0][2] = false;
    pieceCanvas[1][2] = false;
    pieceCanvas[2][2] = false;

}

void Piece::rotateRight(){

    bool pieceCanvasOriginalState[MAXCOLUMN][MAXROW];
    bool pieceCanvasDestinationState[3][3];

    for (int column = 0; column < MAXCOLUMN; column++)
    {
        for (int row = 0; row < MAXROW; row++){
            pieceCanvasOriginalState[column][row] = pieceCanvas[column][row];
        }
    }

    for (int column = 0; column < MAXCOLUMN; column++)
    {
        for (int row = 0; row < MAXROW; row++){
            pieceCanvasDestinationState[column][row] =  pieceCanvasOriginalState[row][((MAXROW-1)-column)];
        }
    }

    for (int column = 0; column < 3; column++)
    {
        for (int row = 0; row < 3; row++){
            pieceCanvas[column][row] = pieceCanvasDestinationState[column][row];
        }
    }


};

Piece::~Piece(){};
