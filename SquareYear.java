import java.io.*;
import java.util.*;

public class SquareYear {
    public static void main(String[] args) throws IOException {
        // fast I/O
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine().trim());
        StringBuilder sb = new StringBuilder(t * 8);

        while (t-- > 0) {
            String s = in.readLine().trim(); // exactly 4 chars, may have leading zeros
            int N = Integer.parseInt(s); // parses "0001"→1, "2025"→2025, etc.

            int r = (int) Math.sqrt(N);
            if (r * r == N) {
                // we can choose (a,b) = (0, r), since (0 + r)^2 = r^2 = N
                sb.append(0).append(' ').append(r).append('\n');
            } else {
                sb.append(-1).append('\n');
            }
        }

        System.out.print(sb);
    }
}
