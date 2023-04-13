
import java.util.Arrays;

public class Solution {

    private static final String[] topThreeRanks = {"Gold Medal", "Silver Medal", "Bronze Medal"};
    private static final int NOT_INDEX = -1;

    public String[] findRelativeRanks(int[] scores) {
        int maxScore = Arrays.stream(scores).max().getAsInt();
        int[] scoreToIndex = new int[maxScore + 1];
        Arrays.fill(scoreToIndex, NOT_INDEX);
        for (int i = 0; i < scores.length; ++i) {
            scoreToIndex[scores[i]] = i;
        }

        String[] allRanks = new String[scores.length];
        int index = scoreToIndex.length - 1;
        int rank = 1;

        while (index >= 0 && rank < 4) {
            if (scoreToIndex[index] != NOT_INDEX) {
                allRanks[scoreToIndex[index]] = topThreeRanks[rank - 1];
                ++rank;
            }
            --index;
        }

        while (index >= 0) {
            if (scoreToIndex[index] != NOT_INDEX) {
                allRanks[scoreToIndex[index]] = Integer.toString(rank);
                ++rank;
            }
            --index;
        }

        return allRanks;
    }
}
