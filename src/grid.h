#pragma once 
#include <vector>
#include <raylib.h>

class Grid
{
    public:
        Grid();
        void Initialize();
        void Print();
        void Draw();
        int grid[20][10];
        bool IsCellOutside(int row, int col);
        bool IsCellEmpty(int row, int col);
        int ClearFullRows();

    private:
        bool isRowFull(int row);
        void ClearRow(int row);
        void MoveRowDown(int row, int col);
        int numRows;
        int numCols;
        int cellSize;
        std::vector<Color> colors;
};