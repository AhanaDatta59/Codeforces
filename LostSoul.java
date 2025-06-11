import java.io.*;
import java.util.*;

public class LostSoul {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            int[] a = new int[n + 1], b = new int[n + 1];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= n; i++)
                a[i] = Integer.parseInt(st.nextToken());
            st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= n; i++)
                b[i] = Integer.parseInt(st.nextToken());

            // best suffix without removal:
            int bestNoRem = 0;
            // we scan from the right; maintain last matched value for a chain
            int val = -1;
            for (int i = n; i >= 1; i--) {
                if (i == n) {
                    if (a[i] == b[i]) {
                        val = a[i];
                        bestNoRem = 1;
                    } else {
                        val = -1;
                        bestNoRem = 0;
                    }
                } else {
                    if (val != -1 && (a[i] == val || b[i] == val)) {
                        bestNoRem++;
                    } else {
                        break;
                    }
                }
            }

            // now try exactly one removal at position k:
            // we’ll build prefix‐suffix runs of “how long would the suffix be if we skip
            // this one index”
            // we precompute L[i] = length of suffix‐chain starting at i (as above)
            int[] L = new int[n + 2];
            val = -1;
            for (int i = n; i >= 1; i--) {
                if (i == n) {
                    if (a[i] == b[i]) {
                        val = a[i];
                        L[i] = 1;
                    } else {
                        val = -1;
                        L[i] = 0;
                    }
                } else {
                    if (val != -1 && (a[i] == val || b[i] == val)) {
                        L[i] = L[i + 1] + 1;
                    } else {
                        // restart chain at i
                        if (a[i] == b[i]) {
                            val = a[i];
                            L[i] = 1;
                        } else {
                            val = -1;
                            L[i] = 0;
                        }
                    }
                }
            }
            // R[i] = length of prefix‐chain up to i (for use when removal splits the chain)
            int[] R = new int[n + 2];
            val = -1;
            for (int i = 1; i <= n; i++) {
                if (i == 1) {
                    if (a[i] == b[i]) {
                        val = a[i];
                        R[i] = 1;
                    } else {
                        val = -1;
                        R[i] = 0;
                    }
                } else {
                    if (val != -1 && (a[i] == val || b[i] == val)) {
                        R[i] = R[i - 1] + 1;
                    } else {
                        if (a[i] == b[i]) {
                            val = a[i];
                            R[i] = 1;
                        } else {
                            val = -1;
                            R[i] = 0;
                        }
                    }
                }
            }

            int best = bestNoRem;
            // if we remove k, we can splice R[k-1] and L[k+1]
            for (int k = 1; k <= n; k++) {
                int left = (k > 1 ? R[k - 1] : 0);
                int right = (k < n ? L[k + 1] : 0);
                best = Math.max(best, left + right);
            }

            bw.append(String.valueOf(best)).append('\n');
        }
        bw.flush();
    }
}
