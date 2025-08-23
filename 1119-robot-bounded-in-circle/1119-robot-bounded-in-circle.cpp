class Solution {
public:
    bool isRobotBounded(string instructions) {
        // initial position and direction
        int x = 0, y = 0;
        int dx = 0, dy = 1; // facing north

        for (char ch : instructions) {
            if (ch == 'G') {
                x += dx;
                y += dy;
            } else if (ch == 'L') {
                int temp = dx;
                dx = -dy;
                dy = temp;
            } else { // 'R'
                int temp = dx;
                dx = dy;
                dy = -temp;
            }
        }

        return (x == 0 && y == 0) || !(dx == 0 && dy == 1);
    }
};
