
#include <array>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    
    inline static const array<string, 3> topThreeRanks {"Gold Medal", "Silver Medal", "Bronze Medal"};
    inline static const int NOT_INDEX = -1;

public:
    vector<string> findRelativeRanks(const vector<int>& scores) const {
        //C++20: int maxScore= *ranges::max_element(scores);
        int maxScore = *max_element(scores.begin(), scores.end());
        vector<int> scoreToIndex(maxScore + 1, NOT_INDEX);
        for (int i = 0; i < scores.size(); ++i) {
            scoreToIndex[scores[i]] = i;
        }

        vector<string> allRanks(scores.size());
        size_t index = scoreToIndex.size() - 1;
        int rank = 1;

        while (index != variant_npos && rank < 4) {
            if (scoreToIndex[index] != NOT_INDEX) {
                allRanks[scoreToIndex[index]] = topThreeRanks[rank - 1];
                ++rank;
            }
            --index;
        }

        while (index != variant_npos) {
            if (scoreToIndex[index] != NOT_INDEX) {
                allRanks[scoreToIndex[index]] = to_string(rank);
                ++rank;
            }
            --index;
        }

        return allRanks;
    }
};
