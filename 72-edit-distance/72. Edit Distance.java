class Solution {
    public int minDistance(String word1, String word2) {
        
        if (word1.length() == 0) {
            return word2.length();
        } else if (word2.length() == 0) {
            return word1.length();
        }
        
        int[][] costMatrix = new int[word1.length()][word2.length()];

        int lastRow = word1.length() - 1;
        int lastCol = word2.length() - 1; 

        boolean isMatch = true;
        if (word1.charAt(lastRow) != word2.charAt(lastCol)) {
            costMatrix[lastRow][lastCol] = 1;
            isMatch = false;
        }

        for (int j = lastCol - 1; j >= 0; j--) {
            if (word1.charAt(lastRow) == word2.charAt(j)) {
                isMatch = true;
            } 

            costMatrix[lastRow][j] = lastCol - j + 1;
            if (isMatch) {
                costMatrix[lastRow][j]--;
            }
        }

        isMatch = word1.charAt(lastRow) == word2.charAt(lastCol);
        for (int i = lastRow - 1; i >= 0; i--) {
            if (word1.charAt(i) == word2.charAt(lastCol)) {
                isMatch = true;
            } 

            costMatrix[i][lastCol] = lastRow - i + 1;
            if (isMatch) {
                costMatrix[i][lastCol]--;
            }
        }

        for (int i = lastRow - 1; i >= 0; i--) {
            for (int j = lastCol - 1; j >= 0; j--) {
                if (word1.charAt(i) == word2.charAt(j)) {
                    costMatrix[i][j] = costMatrix[i + 1][j + 1];
                } else {
                    int min = Math.min(costMatrix[i + 1][j], costMatrix[i][j + 1]);
                    min = Math.min(min, costMatrix[i + 1][j + 1]);
                    costMatrix[i][j] = 1 + min;
                }
            }
        }

        return costMatrix[0][0];
    }
}