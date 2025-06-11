import java.io.*;
import java.util.*;

public class Main {

    // integer floor((len-1)/d) with len, d > 0
    private static long gap(long len, long d) {
        return (len <= 0) ? 0 : (len - 1) / d;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        StringBuilder sb = new StringBuilder();

        while (T-- > 0) {

            StringTokenizer st = new StringTokenizer(br.readLine());
            long n = Long.parseLong(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            long d = Long.parseLong(st.nextToken());

            long[] pos = new long[m + 2]; // p[0..m+1]
            pos[0] = 1;
            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= m; i++)
                pos[i] = Long.parseLong(st.nextToken());
            pos[m + 1] = n + 1; // dummy seller at the end

            long[] g = new long[m + 1]; // gaps between pos[i] & pos[i+1]
            long sumGap = 0;
            for (int i = 0; i <= m; i++) {
                g[i] = gap(pos[i + 1] - pos[i], d);
                sumGap += g[i];
            }

            long base = sumGap + m + 1; // Lemma 2

            long best = Long.MAX_VALUE;
            long cnt = 0;

            for (int j = 1; j <= m; j++) { // delete seller at pos[j]
                long merged = gap(pos[j + 1] - pos[j - 1], d);
                long cand = base - g[j - 1] - g[j] + merged - 1; // Lemma 3

                if (cand < best) {
                    best = cand;
                    cnt = 1;
                } else if (cand == best) {
                    cnt++;
                }
            }
            sb.append(best).append(' ').append(cnt).append('\n');
        }
        System.out.print(sb);
    }
}
