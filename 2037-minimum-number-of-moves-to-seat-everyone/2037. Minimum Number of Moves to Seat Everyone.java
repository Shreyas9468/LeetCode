import java.util.Arrays;

class Solution {
    public int minMovesToSeat(int[] seats, int[] students) {
        Arrays.sort(seats);
        Arrays.sort(students);
        int count = 0;
        for(int i = 0;i<students.length;i++){
            count += Math.abs(students[i] - seats[i]);
        }
        return count;
    }
}