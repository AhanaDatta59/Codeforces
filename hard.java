import java.io.*;
import java.util.*;

public class hard {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();

        int T = Integer.parseInt(in.readLine().trim());
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            long k = Long.parseLong(st.nextToken());

            long[] p = new long[n];
            st = new StringTokenizer(in.readLine());
            for (int i = 0; i < n; i++) {
                p[i] = Long.parseLong(st.nextToken());
            }

            long[] d = new long[n];
            st = new StringTokenizer(in.readLine());
            for (int i = 0; i < n; i++) {
                d[i] = Long.parseLong(st.nextToken());
            }

            // Precompute dangerous gaps between i and i+1
            // dangerous[i] means the gap (p[i], p[i+1]) is a permanent trap
            boolean[] dangerous = new boolean[n - 1];
            for (int i = 0; i < n - 1; i++) {
                long L = p[i + 1] - p[i];
                // check 2L ≡ 0 (mod k)
                if (((L % k) * 2L) % k != 0)
                    continue;
                // check d[i+1] ≡ d[i] + L (mod k)
                if ((((d[i + 1] - d[i] - (L % k)) % k) + k) % k != 0)
                    continue;
                dangerous[i] = true;
            }

            // Read queries
            int q = Integer.parseInt(in.readLine().trim());
            st = new StringTokenizer(in.readLine());
            for (int qi = 0; qi < q; qi++) {
                long a = Long.parseLong(st.nextToken());

                // Case 1: start strictly left of the first light
                if (a < p[0]) {
                    out.append("YES\n");
                    continue;
                }
                // Case 2: start strictly right of the last light
                if (a > p[n - 1]) {
                    out.append("YES\n");
                    continue;
                }

                // Case 3: start exactly on a light?
                int idx = Arrays.binarySearch(p, a);
                if (idx >= 0) {
                    // at t=0, check if it's red => d[idx] ≡ 0 (mod k)
                    if (d[idx] % k == 0) {
                        // you turn left and step into gap (idx-1, idx)
                        if (idx == 0) {
                            // no left neighbor => you step off the strip
                            out.append("YES\n");
                        } else {
                            out.append(dangerous[idx - 1] ? "NO\n" : "YES\n");
                        }
                    } else {
                        // you step right into gap (idx, idx+1)
                        if (idx == n - 1) {
                            out.append("YES\n");
                        } else {
                            out.append(dangerous[idx] ? "NO\n" : "YES\n");
                        }
                    }
                    continue;
                }

                // Case 4: strictly between two lights
                int ins = -idx - 1; // insertion point
                // gap is (ins-1, ins)
                int gap = ins - 1;
                // if gap<0 or gap>=n-1 we are outside => YES
                if (gap < 0 || gap >= n - 1) {
                    out.append("YES\n");
                } else {
                    out.append(dangerous[gap] ? "NO\n" : "YES\n");
                }
            }
        }

        System.out.print(out);
    }
}
