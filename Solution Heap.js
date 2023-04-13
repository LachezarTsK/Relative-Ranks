
/**
 * @param {number[]} scores
 * @return {string[]}
 */
var findRelativeRanks = function (scores) {
    const topThreeRanks = ["Gold Medal", "Silver Medal", "Bronze Medal"];

    //const {MaxPriorityQueue} = require('@datastructures-js/priority-queue');
    //MaxPriorityQueue<ScoreAndIndex>
    const maxHeap = new MaxPriorityQueue({compare: (x, y) => y.score - x.score});
    for (let i = 0; i < scores.length; ++i) {
        maxHeap.enqueue(new ScoreAndIndex(scores[i], i));
    }

    const allRanks = new Array(scores.length);
    let rank = 1;

    while (!maxHeap.isEmpty() && rank < 4) {
        const current = maxHeap.dequeue();
        allRanks[current.index] = topThreeRanks[rank - 1];
        ++rank;
    }

    while (!maxHeap.isEmpty()) {
        const current = maxHeap.dequeue();
        allRanks[current.index] = (rank).toString();
        ++rank;
    }

    return allRanks;
};

/**
 * @param {number} score
 * @param {number} index
 */
function ScoreAndIndex(score, index) {
    this.score = score;
    this.index = index;
}
