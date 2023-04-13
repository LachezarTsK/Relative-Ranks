
import java.util.PriorityQueue;

public class Solution {

    private record ScoreAndIndex(int score, int index) {}
    private static final String[] topThreeRanks = {"Gold Medal", "Silver Medal", "Bronze Medal"};

    public String[] findRelativeRanks(int[] scores) {
        PriorityQueue<ScoreAndIndex> maxHeap = new PriorityQueue<>((x, y) -> y.score - x.score);
        for (int i = 0; i < scores.length; ++i) {
            maxHeap.add(new ScoreAndIndex(scores[i], i));
        }

        String[] allRanks = new String[scores.length];
        int rank = 1;

        while (!maxHeap.isEmpty() && rank < 4) {
            ScoreAndIndex current = maxHeap.poll();
            allRanks[current.index] = topThreeRanks[rank - 1];
            ++rank;
        }

        while (!maxHeap.isEmpty()) {
            ScoreAndIndex current = maxHeap.poll();
            allRanks[current.index] = Integer.toString(rank);
            ++rank;
        }

        return allRanks;
    }
}
