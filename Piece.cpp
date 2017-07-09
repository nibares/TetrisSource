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

    int originColumnIndex = 0;
    int originRowIndex = 0;

    copyPieceCanvas(pieceCanvas, pieceCanvasOriginalState);

    for (int column = 0; column < MAXPIECECOLUMN; column++)
    {
        for (int row = 0; row < MAXPIECEROW; row++){

            originColumnIndex = row;
            originRowIndex = (MAXPIECEROW-1) - column;
            pieceCanvasDestinationState[column][row] =  pieceCanvasOriginalState[originColumnIndex][originRowIndex];
        }
    }

    copyPieceCanvas(pieceCanvasDestinationState, pieceCanvas);

};

void Piece::rotateLeft(){
    bool pieceCanvasOriginalState[3][3];
    bool pieceCanvasDestinationState[3][3];
    int originColumnIndex = 0;
    int originRowIndex = 0;

     copyPieceCanvas(pieceCanvas, pieceCanvasOriginalState);

     for (int column = 0; column < MAXPIECECOLUMN; column++)
     {
         for (int row = 0; row < MAXPIECEROW; row++){

             originColumnIndex = (MAXPIECECOLUMN - 1) - row;
             originRowIndex = column;

             pieceCanvasDestinationState[column][row] =  pieceCanvasOriginalState[originColumnIndex][originRowIndex];
         }
     }

     copyPieceCanvas(pieceCanvasDestinationState, pieceCanvas);
}

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
