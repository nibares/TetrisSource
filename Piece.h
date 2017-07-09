#ifndef PIECE_H
#define PIECE_H


class Piece
{
public:
    const int MAXROW=3, MAXCOLUMN=3;

    bool pieceCanvas[3][3];

    void rotateRight();

    Piece();
    virtual ~Piece();
};

#endif // PIECE_H
