//
// Created by Oskar Zdziarski on 5/11/23.
//

#include <gtest/gtest.h>

#include <vector>

void DepthFirstSearch(std::vector<std::vector<char>>& grid, int r, int c, int height, int width) {
    if (r < 0 || c < 0 || r >= height || c >= width || grid[r][c] == '0') return;
    grid[r][c] = '0';

    DepthFirstSearch(grid, r - 1, c, height, width);
    DepthFirstSearch(grid, r + 1, c, height, width);
    DepthFirstSearch(grid, r, c - 1, height, width);
    DepthFirstSearch(grid, r, c + 1, height, width);
}

int numIslands(std::vector<std::vector<char>>& grid) {
    int result = 0;
    auto height = grid.size();
    auto width = grid[0].size();
    for (int r = 0; r < height; r++) {
        for (int c = 0; c < width; c++) {
            if (grid[r][c] == '1') {
                DepthFirstSearch(grid, r, c, height, width);
                result++;
            }
        }
    }
    return result;
}

TEST(NumberOfIslands, Case1) {
    std::vector<std::vector<char>> grid = {
            {'1','1','1','1','0'},
            {'1','1','0','1','0'},
            {'1','1','0','0','0'},
            {'0','0','0','0','0'}
    };
    ASSERT_EQ(numIslands(grid), 1);
}

TEST(NumberOfIslands, Case2) {
    std::vector<std::vector<char>> grid = {
            {'1','1','0','0','0'},
            {'1','1','0','0','0'},
            {'0','0','1','0','0'},
            {'0','0','0','1','1'}
    };
    ASSERT_EQ(numIslands(grid), 3);
}