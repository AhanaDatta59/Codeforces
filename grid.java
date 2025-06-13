import java.io.*;
import java.util.*;

public class grid {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();
        int T = Integer.parseInt(in.readLine().trim());
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            int[] A = new int[n], B = new int[n];
            st = new StringTokenizer(in.readLine());
            for (int i = 0; i < n; i++)
                A[i] = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(in.readLine());
            for (int i = 0; i < n; i++)
                B[i] = Integer.parseInt(st.nextToken());

            // 1) Gather positions of each value in A and in B
            List<Integer>[] posA = makePos(n, m, A);
            List<Integer>[] posB = makePos(n, m, B);

            boolean ok = true;
            // 2) For each x, sizes must match
            for (int x = 1; x <= m; x++) {
                if (posA[x].size() != posB[x].size()) {
                    ok = false;
                    break;
                }
            }
            // 3) Check cyclic distance sequences
            if (ok) {
                for (int x = 1; x <= m; x++) {
                    List<Integer> aList = posA[x], bList = posB[x];
                    int k = aList.size();
                    if (k <= 1)
                        continue; // one occurrence => distance = n in both
                    // build distance arrays of length k
                    int[] dA = new int[k], dB = new int[k];
                    for (int i = 0; i < k - 1; i++) {
                        dA[i] = aList.get(i + 1) - aList.get(i);
                        dB[i] = bList.get(i + 1) - bList.get(i);
                    }
                    // wrap‐around
                    dA[k - 1] = (aList.get(0) + n) - aList.get(k - 1);
                    dB[k - 1] = (bList.get(0) + n) - bList.get(k - 1);

                    // check if dB is a cyclic rotation of dA
                    if (!isCyclicRotation(dA, dB)) {
                        ok = false;
                        break;
                    }
                }
            }

            out.append(ok ? "YES\n" : "NO\n");
        }
        System.out.print(out);
    }

    // Build an array of lists: positions[x] = all indices i where arr[i]==x
    static List<Integer>[] makePos(int n, int m, int[] arr) {
        @SuppressWarnings("unchecked")
        List<Integer>[] pos = new ArrayList[m + 1];
        for (int x = 1; x <= m; x++)
            pos[x] = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            pos[arr[i]].add(i);
        }
        return pos;
    }

    // Check if small[] is a cyclic rotation of big[] (they have equal length)
    static boolean isCyclicRotation(int[] big, int[] small) {
        int k = big.length;
        // KMP on pattern=small, text=big+big
        int[] lps = buildLPS(small);
        int j = 0; // index in small
        for (int i = 0; i < 2 * k; i++) {
            int v = big[i % k];
            while (j > 0 && small[j] != v) {
                j = lps[j - 1];
            }
            if (small[j] == v) {
                j++;
                if (j == k)
                    return true;
            }
        }
        return false;
    }

    // KMP prefix‐function
    static int[] buildLPS(int[] pat) {
        int k = pat.length;
        int[] lps = new int[k];
        int len = 0;
        for (int i = 1; i < k; i++) {
            while (len > 0 && pat[i] != pat[len]) {
                len = lps[len - 1];
            }
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
            }
        }
        return lps;
    }
}
