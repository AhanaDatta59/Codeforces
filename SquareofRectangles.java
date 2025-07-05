import java.io.*;
import java.util.*;

public class SquareofRectangles {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int t = Integer.parseInt(br.readLine().trim());
        // Precompute all 6 permutations of indices [0,1,2]
        int[][] perms = {
                { 0, 1, 2 }, { 0, 2, 1 },
                { 1, 0, 2 }, { 1, 2, 0 },
                { 2, 0, 1 }, { 2, 1, 0 }
        };
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int[] l = new int[3], b = new int[3];
            for (int i = 0; i < 3; i++) {
                l[i] = Integer.parseInt(st.nextToken());
                b[i] = Integer.parseInt(st.nextToken());
            }
            // total area must be a perfect square
            int area = l[0] * b[0] + l[1] * b[1] + l[2] * b[2];
            int s = (int) Math.sqrt(area);
            if (s * s != area) {
                out.println("NO");
                continue;
            }
            boolean ok = false;
            // Try every assignment of rectangles to roles A,B,C
            for (int[] p : perms) {
                int A = p[0], B = p[1], C = p[2];
                // 1) All three stacked vertically: widths == s, sum of heights == s
                if (l[A] == s && l[B] == s && l[C] == s
                        && b[A] + b[B] + b[C] == s) {
                    ok = true;
                }
                // 2) One full-height on left, two stacked on right
                // A on left: height == s; B and C on right: b[B]+b[C]==s, widths equal == s -
                // l[A]
                if (!ok && b[A] == s
                        && b[B] + b[C] == s
                        && l[A] + l[B] == s
                        && l[B] == l[C]) {
                    ok = true;
                }
                // 3) Two side-by-side on top, one full-width on bottom
                // A,B on top: same height; widths sum == s; C on bottom: width == s, its height
                // + top height == s
                if (!ok && b[A] == b[B]
                        && l[A] + l[B] == s
                        && l[C] == s
                        && b[A] + b[C] == s) {
                    ok = true;
                }
                if (ok)
                    break;
            }
            out.println(ok ? "YES" : "NO");
        }
        out.flush();
    }
}
