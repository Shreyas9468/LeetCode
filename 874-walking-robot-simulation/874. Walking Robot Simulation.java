import java.util.HashSet;
import java.util.Set;

public class Solution {
    public int robotSim(int[] commands, int[][] obstacles) {
        // Directions array: (north, east, south, west)
        int[][] directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int x = 0, y = 0; // Robot starts at (0, 0)
        int dir = 0; // Start facing north
        int maxDistSquared = 0;

        // Use a set to store the obstacles
        Set<String> obstacleSet = new HashSet<>();
        for (int[] obstacle : obstacles) {
            obstacleSet.add(obstacle[0] + "," + obstacle[1]);
        }

        for (int command : commands) {
            if (command == -1) {
                // Turn right
                dir = (dir + 1) % 4;
            } else if (command == -2) {
                // Turn left
                dir = (dir + 3) % 4;
            } else {
                // Move forward
                for (int i = 0; i < command; i++) {
                    int nextX = x + directions[dir][0];
                    int nextY = y + directions[dir][1];

                    if (!obstacleSet.contains(nextX + "," + nextY)) {
                        x = nextX;
                        y = nextY;
                        maxDistSquared = Math.max(maxDistSquared, x * x + y * y);
                    } else {
                        // Stop moving if an obstacle is encountered
                        break;
                    }
                }
            }
        }

        return maxDistSquared;
    }


}
