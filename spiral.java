import java.io.*;
import java.util.*;

public class spiral {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();

        int t = Integer.parseInt(in.readLine().trim());
        while (t-- > 0) {
            String line;
            // skip blank lines (if any)
            do {
                line = in.readLine();
            } while (line != null && line.trim().isEmpty());
            if (line == null)
                break;

            String[] parts = line.trim().split("\\s+");
            int n = Integer.parseInt(parts[0]);
            int m = Integer.parseInt(parts[1]);

            int total = n * m;
            int centerR = (n + 1) / 2;
            int centerC = (m + 1) / 2;

            // directions: right, up, left, down
            int[] dr = { 0, -1, 0, +1 };
            int[] dc = { +1, 0, -1, 0 };

            boolean[][] seen = new boolean[n + 2][m + 2];
            int r = centerR, c = centerC;
            seen[r][c] = true;
            out.append(r).append(' ').append(c).append('\n');
            int count = 1;

            int step = 1;
            outer: while (count < total) {
                for (int dir = 0; dir < 4; dir++) {
                    int len = step;
                    // after every two directions, increase the step length
                    if (dir == 2 || dir == 0) {
                        // dir==0 or dir==2 are right or left, step==current
                        // dir==1 or dir==3 are up/down, step==current
                    }
                    for (int i = 0; i < len; i++) {
                        r += dr[dir];
                        c += dc[dir];
                        if (r >= 1 && r <= n && c >= 1 && c <= m && !seen[r][c]) {
                            seen[r][c] = true;
                            out.append(r).append(' ').append(c).append('\n');
                            if (++count >= total)
                                break outer;
                        }
                    }
                    // every two legs, bump step
                    if (dir % 2 == 1) {
                        step++;
                    }
                }
            }
        }

        System.out.print(out);
    }
}
