class Solution {
    private int dfs(
        final Set<Integer> rows, 
        final List<Integer> sortedVals,
        final Map<Integer, Set<Integer>> valToIndex,
        final int score,
        int depth
    ) {
        if (++depth == sortedVals.size()) {
            return score;
        }
        final int value = sortedVals.get(depth);
        
        final List<Integer> scores = new ArrayList<>();
        final int nxt_depth = depth;
        valToIndex.get(value)
                  .stream()
                  .filter(row -> !rows.contains(row))
                  .forEach(row -> {
            final Set<Integer> updatedRows = new HashSet<>(rows);
            updatedRows.add(row);
            scores.add(dfs(updatedRows, sortedVals, valToIndex, score + value, nxt_depth));
        });
        if (scores.isEmpty()) {
            return dfs(rows, sortedVals, valToIndex, score, depth);
        } else {
           return Collections.max(scores);
        }
    }

    public int maxScore(List<List<Integer>> grid) {
        final Set<Integer> vals =  grid.stream().flatMap(List::stream).collect(Collectors.toSet());
        final Map<Integer, Set<Integer>> valToIndex = new HashMap<>();
        vals.forEach(val -> valToIndex.put(val, new HashSet<>()));
        IntStream.range(0, grid.size()).forEach(row -> {
            vals.forEach(val -> {
                if (grid.get(row).contains(val)) {
                    valToIndex.get(val).add(row);
                }
            });
        });
        final List<Integer> sortedVals = new ArrayList<>(vals);
        Collections.sort(sortedVals, Collections.reverseOrder());
        return dfs(new HashSet<>(), sortedVals, valToIndex, 0, -1);
    }
}