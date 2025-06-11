import java.io.*;
import java.util.*;

public class BuildArray {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine().trim());
        StringBuilder sb = new StringBuilder();
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            long k = Long.parseLong(st.nextToken());
            long[] a = new long[n + 1];
            st = new StringTokenizer(in.readLine());
            for (int i = 1; i <= n; i++) {
                a[i] = Long.parseLong(st.nextToken());
            }
            // precompute ctz and odd parts
            int[] ctz = new int[n + 1];
            long[] odd = new long[n + 1];
            for (int i = 1; i <= n; i++) {
                int c = Long.numberOfTrailingZeros(a[i]);
                ctz[i] = c;
                odd[i] = a[i] >> c;
            }
            // prefix sums L[i] = sum_{j=1..i} f(a[j], a[j+1])
            long[] L = new long[n + 2], R = new long[n + 2];
            for (int i = 1; i < n; i++) {
                L[i] = L[i - 1] + f(a[i], a[i + 1], ctz[i], ctz[i + 1], odd[i], odd[i + 1]);
            }
            // suffix sums R[i] = sum_{j=i..n-1} f(a[j+1], a[j])
            for (int i = n; i > 1; i--) {
                R[i] = R[i + 1] + f(a[i], a[i - 1], ctz[i], ctz[i - 1], odd[i], odd[i - 1]);
            }
            boolean ok = false;
            for (int i = 1; i <= n; i++) {
                long full = 1L << ctz[i];
                long left = (i > 1 ? L[i - 1] : 0L);
                long right = (i < n ? R[i + 1] : 0L);
                if (full + left + right >= k) {
                    sb.append("YES\n");
                    ok = true;
                    break;
                }
            }
            if (!ok)
                sb.append("NO\n");
        }
        System.out.print(sb);
    }

    // f(x,y) = max pieces you can build on the 'x' side before
    // an accidental cross-boundary merge would occur.
    static long f(long x, long y,
            int cx, int cy,
            long ox, long oy) {
        long px = 1L << cx;
        if (ox != oy) {
            // odd parts differ → you can split x fully
            return px;
        } else {
            // same odd part → limited by y's height
            long py = 1L << cy;
            return Math.min(px, py);
        }
    }
}
