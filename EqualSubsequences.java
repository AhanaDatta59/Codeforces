import java.io.*;
import java.util.*;

public class EqualSubsequences {
    public static void main(String[] args) throws IOException {
        // Fast I/O setup
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();

        // Read number of test cases
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            StringBuilder sb = new StringBuilder(n);
            for (int i = 0; i < k; i++) {
                sb.append('1');
            }
            for (int i = 0; i < n - k; i++) {
                sb.append('0');
            }

            out.append(sb).append('\n');
        }

        // Print all answers at once
        System.out.print(out);
    }
}
