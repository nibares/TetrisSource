#ifndef PIECE_H
#define PIECE_H


class Piece
{
public:
    const int MAXPIECEROW=3, MAXPIECECOLUMN=3;

    bool pieceCanvas[3][3];

    void rotateRight();

    void clearPieceCanvas();

    Piece();
    virtual ~Piece();
};

#endif // PIECE_H
