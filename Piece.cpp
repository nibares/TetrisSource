#include "Piece.h"

Piece::Piece()
{
   // Piece();
    clearPieceCanvas();

    pieceCanvas[1][0] = true;
    pieceCanvas[1][1] = true;

}

void Piece::rotateRight(){

    bool pieceCanvasOriginalState[3][3];
    bool pieceCanvasDestinationState[3][3];

    copyPieceCanvas(pieceCanvas, pieceCanvasOriginalState);

    for (int column = 0; column < MAXPIECECOLUMN; column++)
    {
        for (int row = 0; row < MAXPIECEROW; row++){
            pieceCanvasDestinationState[column][row] =  pieceCanvasOriginalState[row][((MAXPIECEROW-1)-column)];
        }
    }

    copyPieceCanvas(pieceCanvasDestinationState, pieceCanvas);

};

void Piece::clearPieceCanvas()
{
    for (int column = 0; column<MAXPIECECOLUMN; column++){

        for (int row = 0; row < MAXPIECEROW; row++){
                   pieceCanvas [column][row] = false;
        }
    }
}

void Piece::copyPieceCanvas(const bool originCanvas[3][3], bool destinationCanvas[3][3]){

    for (int column = 0; column < MAXPIECECOLUMN; column++)
    {
        for (int row = 0; row < MAXPIECEROW; row++){
            destinationCanvas[column][row] = originCanvas[column][row];
        }
    }

}

Piece::~Piece(){};
