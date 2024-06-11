class Solution {
    public int[] relativeSortArray(int[] arr1, int[] arr2) {
        int[] sortedArray = new int[arr1.length];
        HashMap<Integer, Integer> hm = new HashMap<>();

        // Populate the HashMap with frequencies of elements in arr1
        for (int num : arr1) {
            hm.put(num, hm.getOrDefault(num, 0) + 1);
        }

        int index = 0;

        // Process elements in arr2
        for (int num : arr2) {
            if (hm.containsKey(num)) {
                int count = hm.get(num);
                for (int i = 0; i < count; i++) {
                    sortedArray[index++] = num;
                }
                hm.remove(num);
            }
        }

        // Collect remaining elements from the HashMap
        List<Integer> remaining = new ArrayList<>();
        for (int key : hm.keySet()) {
            int count = hm.get(key);
            for (int i = 0; i < count; i++) {
                remaining.add(key);
            }
        }

        // Sort the remaining elements
        Collections.sort(remaining);

        // Add sorted remaining elements to the result array
        for (int num : remaining) {
            sortedArray[index++] = num;
        }

        return sortedArray;
    }
}