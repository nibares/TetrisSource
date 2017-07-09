#ifndef PIECE_H
#define PIECE_H


class Piece
{
private:
    void clearPieceCanvas();
    void copyPieceCanvas(const bool originCanvas[3][3], bool destinationCanvas[3][3]);

public:
    const int MAXPIECEROW=3, MAXPIECECOLUMN=3;

    bool pieceCanvas[3][3];

    void rotateRight();



    Piece();
    virtual ~Piece();
};

#endif // PIECE_H
