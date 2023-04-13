
#include <array>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {

    struct ScoreAndIndex {
        int score;
        size_t index;
        ScoreAndIndex(int score, size_t index): score{score}, index{index}{};
    };
    inline static const array<string, 3> topThreeRanks{ "Gold Medal", "Silver Medal", "Bronze Medal"};

public:
    vector<string> findRelativeRanks(const vector<int>& scores) const {
        static const auto comparator = [](const auto& first, const auto& second) {return first.score < second.score;};
        priority_queue<ScoreAndIndex, vector<ScoreAndIndex>, decltype(comparator) > maxHeap(comparator);
        for (size_t i = 0; i < scores.size(); ++i) {
            maxHeap.push(ScoreAndIndex(scores[i], i));
        }

        vector<string> allRanks(scores.size());
        int rank = 1;

        while (!maxHeap.empty() && rank < 4) {
            ScoreAndIndex current = maxHeap.top();
            maxHeap.pop();
            allRanks[current.index] = topThreeRanks[rank - 1];
            ++rank;
        }

        while (!maxHeap.empty()) {
            ScoreAndIndex current = maxHeap.top();
            maxHeap.pop();
            allRanks[current.index] = to_string(rank);
            ++rank;
        }

        return allRanks;
    }
};
