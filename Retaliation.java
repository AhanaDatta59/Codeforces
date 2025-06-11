import java.io.*;
import java.util.*;

public class Retaliation {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            StringTokenizer st = new StringTokenizer(br.readLine());
            long[] a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = Long.parseLong(st.nextToken());
            }

            // If n == 1 (not in this problem), always YES, but here n >= 2.
            // Check if a[] is an arithmetic progression.
            long d = a[1] - a[0];
            boolean isAP = true;
            for (int i = 2; i < n; i++) {
                if (a[i] - a[i - 1] != d) {
                    isAP = false;
                    break;
                }
            }
            if (!isAP) {
                out.append("NO\n");
                continue;
            }

            // We need a[i] = x*i + y*(n-i+1) for some x,y >= 0.
            // That is a[i] = A*i + B with A = x - y, B = y*(n+1).
            long A = d;
            // For 1-based i, B = a1 - A*1
            long B = a[0] - A;
            long denom = n + 1L;
            if (B < 0 || B % denom != 0) {
                out.append("NO\n");
                continue;
            }
            long y = B / denom;
            long x = A + y;
            if (y < 0 || x < 0) {
                out.append("NO\n");
            } else {
                out.append("YES\n");
            }
        }
        System.out.print(out);
    }
}
