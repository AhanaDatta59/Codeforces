import java.io.*;
import java.util.*;

public class Perm {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();

        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            // We will do exactly 2n-2 operations:
            // For each row i=1..n:
            // if i>1: reverse A[i][1..i]
            // if i<n: reverse A[i][i+1..n]
            // that produces the Latin square
            int k = 2 * n - 2;
            out.append(k).append('\n');

            for (int i = 1; i <= n; i++) {
                if (i > 1) {
                    // reverse the prefix [1..i]
                    out.append(i).append(' ').append(1).append(' ').append(i).append('\n');
                }
                if (i < n) {
                    // reverse the suffix [i+1..n]
                    out.append(i).append(' ').append(i + 1).append(' ').append(n).append('\n');
                }
            }
        }

        System.out.print(out);
    }
}
