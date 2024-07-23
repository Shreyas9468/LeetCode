class Solution {
        int i = 0;
    public int[] frequencySort(int[] nums) {
        Arrays.stream(nums).boxed()
                .collect(Collectors.groupingBy(Function.identity(), Collectors.counting()))
                .entrySet().stream()
                .sorted((x1, x2) -> x1.getValue() == x2.getValue() ? x2.getKey() - x1.getKey() : (int) (x1.getValue() - x2.getValue()))
                .forEach(x -> Stream.iterate(0, n -> n + 1).limit(x.getValue()).forEach(n -> nums[i++] = x.getKey()));
        return nums;
    }	
}