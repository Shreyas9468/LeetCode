class Solution {
   public boolean isNStraightHand(int[] hand, int groupSize) {
        int n = hand.length;
        if (n % groupSize != 0) {
            return false;
        }

        HashMap<Integer, Integer> hm = new HashMap<>();
        for (int card : hand) {
            hm.put(card, hm.getOrDefault(card, 0) + 1);
        }

        while (!hm.isEmpty()) {
            // Find the smallest key (card) in the hashmap
            int first = Integer.MAX_VALUE;
            for (int key : hm.keySet()) {
                first = Math.min(first, key);
            }

            // Try to form a consecutive sequence starting from 'first'
            for (int i = 0; i < groupSize; i++) {
                int card = first + i;
                if (!hm.containsKey(card)) {
                    return false;
                }

                // Decrease the count of the current card
                int count = hm.get(card);
                if (count == 1) {
                    hm.remove(card);
                } else {
                    hm.put(card, count - 1);
                }
            }
        }

        return true;
    }
}