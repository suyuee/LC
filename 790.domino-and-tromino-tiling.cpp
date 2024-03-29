/*
 * @lc app=leetcode id=790 lang=cpp
 *
 * [790] Domino and Tromino Tiling
 *
 * https://leetcode.com/problems/domino-and-tromino-tiling/description/
 *
 * algorithms
 * Medium (36.24%)
 * Total Accepted:    9K
 * Total Submissions: 24.6K
 * Testcase Example:  '3'
 *
 * We have two types of tiles: a 2x1 domino shape, and an "L" tromino shape.
 * These shapes may be rotated.
 * 
 * 
 * XX  <- domino
 * 
 * XX  <- "L" tromino
 * X
 * 
 * 
 * Given N, how many ways are there to tile a 2 x N board? Return your answer
 * modulo 10^9 + 7.
 * 
 * (In a tiling, every square must be covered by a tile. Two tilings are
 * different if and only if there are two 4-directionally adjacent cells on the
 * board such that exactly one of the tilings has both squares occupied by a
 * tile.)
 * 
 * 
 * 
 * Example:
 * Input: 3
 * Output: 5
 * Explanation: 
 * The five different ways are listed below, different letters indicates
 * different tiles:
 * XYZ XXZ XYY XXY XYY
 * XYZ YYZ XZZ XYY XXY
 * 
 * Note:
 * 
 * 
 * N  will be in range [1, 1000].
 * 
 * 
 * 
 * 
 */
class Solution {
public:
    int numTilings(int N) {
        const int modulo = 1000000007;
        //xx...xx
        //xx...xx
        vector<long> type1(N + 1, 0);
        //xx...x
        //xx...xx
        vector<long> type2(N + 1, 0);
        type1[0] = 1;
        type1[1] = 1;

        for (int i = 2; i <= N; ++i) {
            type1[i] = (type1[i-2] + type1[i-1] + 2 * type2[i-1]) % modulo;
            type2[i] = (type1[i-2] + type2[i-1]) % modulo;
        }
        return type1[N];
    }
};
