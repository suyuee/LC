/*
 * @lc app=leetcode id=839 lang=cpp
 *
 * [839] Similar String Groups
 *
 * https://leetcode.com/problems/similar-string-groups/description/
 *
 * algorithms
 * Hard (34.98%)
 * Total Accepted:    10K
 * Total Submissions: 28.4K
 * Testcase Example:  '["tars","rats","arts","star"]'
 *
 * Two strings X and Y are similar if we can swap two letters (in different
 * positions) of X, so that it equals Y.
 * 
 * For example, "tars" and "rats" are similar (swapping at positions 0 and 2),
 * and "rats" and "arts" are similar, but "star" is not similar to "tars",
 * "rats", or "arts".
 * 
 * Together, these form two connected groups by similarity: {"tars", "rats",
 * "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group
 * even though they are not similar.  Formally, each group is such that a word
 * is in the group if and only if it is similar to at least one other word in
 * the group.
 * 
 * We are given a list A of strings.  Every string in A is an anagram of every
 * other string in A.  How many groups are there?
 * 
 * Example 1:
 * 
 * 
 * Input: ["tars","rats","arts","star"]
 * Output: 2
 * 
 * Note:
 * 
 * 
 * A.length <= 2000
 * A[i].length <= 1000
 * A.length * A[i].length <= 20000
 * All words in A consist of lowercase letters only.
 * All words in A have the same length and are anagrams of each other.
 * The judging time limit has been increased for this question.
 * 
 * 
 */
class Solution {
public:
    int numSimilarGroups(vector<string>& A) {
        vector<int> leader(A.size());
        iota(leader.begin(), leader.end(), 0);
        int n = A.size();
        for (int i = 0; i < A.size(); ++i)
            for (int j = i + 1; j < A.size(); ++j) {
                if (!isSimilar(A[i], A[j]))
                    continue;
                int ileader = trace(leader, i), jleader = trace(leader, j);
                if (ileader != jleader) {
                    leader[jleader] = leader[ileader];
                    --n;
                }
            }
        return n;
    }
private:
    int trace(vector<int> &leader, int a) {
        if (leader[a] != a)
            leader[a] = trace(leader, leader[a]);
        return leader[a];
    }
    bool isSimilar(const string &a, const string &b) {
        int diff = 0;
        for (int i = 0; i < a.length(); ++i)
            if (a[i] != b[i] && ++diff > 2)
                return false;
        return true;
    }
};
