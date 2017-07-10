#include "Piece.h"

Piece::Piece()
{
   // Piece();

};

void Piece::createPiece(const int PieceColumnSize, const int PieceRowSize){

    maxPieceColumn = PieceColumnSize;
    maxPieceRow = PieceRowSize;

    pieceCanvas.resize(maxPieceColumn);

    for (int i = 0; i<maxPieceColumn; i++){
        pieceCanvas[i].resize(maxPieceRow);
    }

    clearPieceCanvas();

}

void Piece::createPiece(const int PieceColumnSize, const int PieceRowSize, const std::vector< std::vector<bool>> NewPieceCanvas){

    maxPieceColumn = PieceColumnSize;
    maxPieceRow = PieceRowSize;

    pieceCanvas.resize(maxPieceColumn);

    for (int i = 0; i<maxPieceColumn; i++){
        pieceCanvas[i].resize(maxPieceRow);
    }

     copyPieceCanvas(NewPieceCanvas, pieceCanvas);
     pieceCanvas = NewPieceCanvas;
};

void Piece::rotateRight(){

    std::vector<std::vector<bool>>  pieceCanvasOriginalState;
    std::vector<std::vector<bool>>  pieceCanvasDestinationState;

    pieceCanvasOriginalState.resize(maxPieceColumn);

    for (int i = 0; i<maxPieceColumn; i++){
        pieceCanvasOriginalState[i].resize(maxPieceRow);
    }

    pieceCanvasDestinationState.resize(maxPieceColumn);

    for (int i = 0; i<maxPieceColumn; i++){
        pieceCanvasDestinationState[i].resize(maxPieceRow);
    }


    int originColumnIndex = 0;
    int originRowIndex = 0;

    copyPieceCanvas(pieceCanvas, pieceCanvasOriginalState);

    for (int column = 0; column < maxPieceColumn; column++)
    {
        for (int row = 0; row < maxPieceRow; row++){

            originColumnIndex = row;
            originRowIndex = (maxPieceRow-1) - column;
            pieceCanvasDestinationState[column][row] =  pieceCanvasOriginalState[originColumnIndex][originRowIndex];
        }
    }

    copyPieceCanvas(pieceCanvasDestinationState, pieceCanvas);

};

void Piece::rotateLeft(){
     std::vector<std::vector<bool>> pieceCanvasOriginalState;
     std::vector<std::vector<bool>> pieceCanvasDestinationState;

     pieceCanvasOriginalState.resize(maxPieceColumn);

     for (int i = 0; i<maxPieceColumn; i++){
         pieceCanvasOriginalState[i].resize(maxPieceRow);
     }

     pieceCanvasDestinationState.resize(maxPieceColumn);

     for (int i = 0; i<maxPieceColumn; i++){
         pieceCanvasDestinationState[i].resize(maxPieceRow);
     }

    int originColumnIndex = 0;
    int originRowIndex = 0;

     copyPieceCanvas(pieceCanvas, pieceCanvasOriginalState);

     for (int column = 0; column < maxPieceColumn; column++)
     {
         for (int row = 0; row < maxPieceRow; row++){

             originColumnIndex = (maxPieceColumn - 1) - row;
             originRowIndex = column;

             pieceCanvasDestinationState[column][row] =  pieceCanvasOriginalState[originColumnIndex][originRowIndex];
         }
     }

     copyPieceCanvas(pieceCanvasDestinationState, pieceCanvas);
}

void Piece::clearPieceCanvas()
{
    for (int column = 0; column<maxPieceColumn; column++){
        for (int row = 0; row < maxPieceRow; row++){
                   pieceCanvas[column][row] = false;
        }
    }
}

void Piece::copyPieceCanvas(const std::vector<std::vector<bool>> originCanvas, std::vector<std::vector<bool>> destinationCanvas){

    for (int column = 0; column < maxPieceColumn; column++)
    {
        for (int row = 0; row < maxPieceRow; row++){
            destinationCanvas[column][row] = originCanvas[column][row];
        }
    }

}

Piece::~Piece(){};
