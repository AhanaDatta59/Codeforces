import java.io.*;
import java.util.*;

public class NonPalindromic {
    public static void main(String[] args) throws IOException {
        // Fast input
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine().trim());
        StringBuilder sb = new StringBuilder();

        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            String s = in.readLine().trim();

            // Count zeros
            int c0 = 0;
            for (char ch : s.toCharArray()) {
                if (ch == '0')
                    c0++;
            }

            // Compute the value we need to be even and in [0..2k]
            // namely: c0 - (n/2 - k)
            int needed = c0 - (n / 2 - k);

            // Check: even, >=0, <=2k
            if (needed >= 0 && needed <= 2 * k && (needed % 2 == 0)) {
                sb.append("YES\n");
            } else {
                sb.append("NO\n");
            }
        }

        // Print all answers
        System.out.print(sb);
    }
}
