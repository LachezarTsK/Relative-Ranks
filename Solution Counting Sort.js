
/**
 * @param {number[]} scores
 * @return {string[]}
 */
var findRelativeRanks = function (scores) {
    const topThreeRanks = ["Gold Medal", "Silver Medal", "Bronze Medal"];
    const NOT_INDEX = -1;

    const maxScore = Math.max(...scores);
    const scoreToIndex = new Array(maxScore + 1).fill(NOT_INDEX);
    for (let i = 0; i < scores.length; ++i) {
        scoreToIndex[scores[i]] = i;
    }

    const allRanks = new Array(scores.length);
    let index = scoreToIndex.length - 1;
    let rank = 1;

    while (index >= 0 && rank < 4) {
        if (scoreToIndex[index] !== NOT_INDEX) {
            allRanks[scoreToIndex[index]] = topThreeRanks[rank - 1];
            ++rank;
        }
        --index;
    }

    while (index >= 0) {
        if (scoreToIndex[index] !== NOT_INDEX) {
            allRanks[scoreToIndex[index]] = (rank).toString();
            ++rank;
        }
        --index;
    }

    return allRanks;
};
