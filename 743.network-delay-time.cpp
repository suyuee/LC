/*
 * @lc app=leetcode id=743 lang=cpp
 *
 * [743] Network Delay Time
 *
 * https://leetcode.com/problems/network-delay-time/description/
 *
 * algorithms
 * Medium (43.30%)
 * Total Accepted:    41.8K
 * Total Submissions: 96.6K
 * Testcase Example:  '[[2,1,1],[2,3,1],[3,4,1]]\n4\n2'
 *
 * There are N network nodes, labelled 1 to N.
 * 
 * Given times, a list of travel times as directed edges times[i] = (u, v, w),
 * where u is the source node, v is the target node, and w is the time it takes
 * for a signal to travel from source to target.
 * 
 * Now, we send a signal from a certain node K. How long will it take for all
 * nodes to receive the signal? If it is impossible, return -1.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * 
 * 
 * Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
 * Output: 2
 * 
 * 
 * 
 * 
 * Note:
 * 
 * 
 * N will be in the range [1, 100].
 * K will be in the range [1, N].
 * The length of times will be in the range [1, 6000].
 * All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.
 * 
 * 
 */
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        constexpr int MAX = 1e9;
        vector<int> records(N, MAX);
        records[K - 1] = 0;
        for (int i = 0; i < N; ++i)
            for (const auto &t : times) {
                int u = t[0] - 1, v = t[1] - 1, w = t[2]; 
                records[v] = min(records[v], records[u] + w);
            }
        int delay = *max_element(records.begin(), records.end());
        return delay >= MAX ? -1 : delay;
    }
};
