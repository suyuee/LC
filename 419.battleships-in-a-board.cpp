/*
 * @lc app=leetcode id=419 lang=cpp
 *
 * [419] Battleships in a Board
 *
 * https://leetcode.com/problems/battleships-in-a-board/description/
 *
 * algorithms
 * Medium (66.65%)
 * Likes:    493
 * Dislikes: 375
 * Total Accepted:    71.4K
 * Total Submissions: 106.6K
 * Testcase Example:  '[["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]'
 *
 * Given an 2D board, count how many battleships are in it. The battleships are
 * represented with 'X's, empty slots are represented with '.'s. You may assume
 * the following rules:
 * 
 * 
 * You receive a valid board, made of only battleships or empty slots.
 * Battleships can only be placed horizontally or vertically. In other words,
 * they can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1
 * column), where N can be of any size.
 * At least one horizontal or vertical cell separates between two battleships -
 * there are no adjacent battleships.
 * 
 * 
 * Example:
 * X..X
 * ...X
 * ...X
 * 
 * In the above board there are 2 battleships.
 * 
 * Invalid Example:
 * ...X
 * XXXX
 * ...X
 * 
 * This is an invalid board that you will not receive - as battleships will
 * always have a cell separating between them.
 * 
 * Follow up:Could you do it in one-pass, using only O(1) extra memory and
 * without modifying the value of the board?
 */

// @lc code=start
class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int count = 0;
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j) {
                if (board[i][j] == 'X') {
                    ++count;
                    for (int right = j + 1; right < board[0].size() && board[i][right] == 'X'; ++right)
                        board[i][right] = 'Y';
                    for (int down = i + 1; down < board.size() && board[down][j] == 'X'; ++down)
                        board[down][j] = 'Y';
                }
            }
        return count;
    }
};
// @lc code=end
