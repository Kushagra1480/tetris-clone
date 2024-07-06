#include "grid.h"
#include <iostream>
#include "colors.h"


Grid::Grid() {
    numRows = 20;
    numCols = 10;
    cellSize = 30;
    Initialize();
    colors = GetCellColors();
}

void Grid::Initialize() {
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            grid[row][col] = 0;
        }
    }
}

void Grid::Print() {
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            printf("%d ", grid[row][col]);
        }
        printf("\n");
    }
}

void Grid::Draw() {
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < numCols; col++) {
            int cellValue = grid[row][col];
            DrawRectangle(col * cellSize + 1, row * cellSize + 1, cellSize - 1, cellSize - 1, colors[cellValue]);
        }
    }
}

bool Grid::IsCellOutside(int row, int col) {
    if (row >= 0 && row < numRows && col >= 0 && col < numCols) {
        return false;
    }
    return true;
}

bool Grid::IsCellEmpty(int row, int col) {
    if(grid[row][col] == 0) {
        return true;
    }
    return false;
}

int Grid::ClearFullRows() {
    int clearedRows = 0;
    for (int row = 0; row < numRows; row++) {
        if(isRowFull(row)) {
            ClearRow(row);
            MoveRowDown(row, 0);
            clearedRows++;
        }
    }
    return clearedRows;
}

bool Grid::isRowFull(int row) {
    for (int col = 0; col < numCols; col++) {
        if(grid[row][col] == 0) {
            return false;
        }
    }
    return true;
}

void Grid::ClearRow(int row) {
    for (int col = 0; col < numCols; col++) {
        grid[row][col] = 0;
    }
}

void Grid::MoveRowDown(int row, int col) {
    for (int col = 0; col < numCols; col++) {
        grid[row + numRows][col] = grid[row][col];
        grid[row][col] = 0;
    }
}