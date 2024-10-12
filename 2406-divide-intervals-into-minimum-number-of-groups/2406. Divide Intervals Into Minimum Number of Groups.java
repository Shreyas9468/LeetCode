import java.util.Arrays;

class Solution {
    public int minGroups(int[][] intervals) {

        int minoverlaps = 0;
        int overlaps = 0;
        int[][] events = new int[intervals.length * 2][2];
        int index = 0;
        for (int[] interval : intervals) {
            // Arrival event (time, +1)
            events[index][0] = interval[0]; // Start time
            events[index][1] = 1;           // +1 for arrival
            index++;

            // Departure event (time, -1)
            events[index][0] = interval[1] + 1; // End time (+1 to avoid overlap)
            events[index][1] = -1;              // -1 for departure
            index++;
        }
        Arrays.sort(events, (a, b) -> {
            if (a[0] == b[0]) return a[1] - b[1]; // Sort by type if times are equal
            return a[0] - b[0]; // Otherwise sort by time
        });
        int maxOverlaps = 0;
        int currentOverlaps = 0;

        // Iterate through events and track maximum overlaps
        for (int[] event : events) {
            currentOverlaps += event[1]; // +1 for arrival, -1 for departure
            maxOverlaps = Math.max(maxOverlaps, currentOverlaps); // Update max overlaps
        }

        return maxOverlaps;
    }
}