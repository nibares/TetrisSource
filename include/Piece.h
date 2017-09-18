#ifndef PIECE_H
#define PIECE_H

#include <vector>

class Piece
{
private:
    void clearPieceCanvas();
    void copyPieceCanvas(const std::vector< std::vector<bool>> originCanvas, std::vector< std::vector<bool>> destinationCanvas);

    int maxPieceColumn;
    int maxPieceRow;

public:

    std::vector<std::vector<bool>> pieceCanvas;

    void createPiece (const int PieceColumnSize, const int PieceRowSize);
    void createPiece (const int PieceColumnSize, const int PieceRowSize, const std::vector< std::vector<bool>> NewPieceCanvas);

    void rotateRight();
    void rotateLeft();



    Piece();
    virtual ~Piece();
};

#endif // PIECE_H
