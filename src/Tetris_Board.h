#ifndef TETRIS_BOARD_H
#define TETRIS_BOARD_H

#include "Tetris_Shape.h"
#include <wx/wx.h>

class Board : public wxPanel
{

public:
    Board(wxFrame *parent);
    void Start();
    void Pause();
    void linesRemovedChanged(int numLines);

protected:
    void OnPaint(wxPaintEvent& event);
    void OnKeyDown(wxKeyEvent& event);
    void OnTimer(wxCommandEvent& event);

private:
    enum { BoardWidth = 10, BoardHeight = 22 };

    Tetrominoes & ShapeAt(int x, int y) { return board[(y * BoardWidth) + x]; }

    int SquareWidth() { return GetClientSize().GetWidth() / BoardWidth; }
    int SquareHeight() { return GetClientSize().GetHeight() / BoardHeight; }
    void ClearBoard();
    void DropDown();
    void OneLineDown();
    void PieceDropped();
    void RemoveFullLines();
    void NewPiece();
    bool TryMove(const Shape& newPiece, int newX, int newY);
    void DrawSquare(wxPaintDC &dc, int x, int y, Tetrominoes shape);

    wxTimer *timer;
    bool isStarted;
    bool isPaused;
    bool isFallingFinished;
    Shape curPiece;
    int curX;
    int curY;
    int numLinesRemoved;
    Tetrominoes board[BoardWidth * BoardHeight];
    wxStatusBar *m_stsbar;
};



#endif // TETRIS_BOARD_H
