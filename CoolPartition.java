import java.io.*;
import java.util.*;

public class CoolPartition {
    // upper bound on sum of n
    static final int MAXN = 200_000 + 5;
    // since 2^18 = 262144 > 200k
    static final int MAXK = 18;

    static int[] lg = new int[MAXN];
    static int[][] stMin = new int[MAXK][MAXN];
    static int[] a = new int[MAXN];
    static int[] last = new int[MAXN];
    static int[] seg; // segment tree for dp
    static int segSize; // leaf count (power of two)

    public static void main(String[] args) throws IOException {
        // precompute binary‐logs
        lg[1] = 0;
        for (int i = 2; i < MAXN; i++) {
            lg[i] = lg[i >> 1] + 1;
        }
        // build one global segment‐tree large enough
        segSize = 1;
        while (segSize < MAXN)
            segSize <<= 1;
        seg = new int[2 * segSize];
        // all zero initially

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 1; i <= n; i++) {
                a[i] = Integer.parseInt(st.nextToken());
            }
            // compute last occurrence
            for (int i = 1; i <= n; i++) {
                last[a[i]] = i;
            }
            // build sparse table over last[a[i]]
            for (int i = 1; i <= n; i++) {
                stMin[0][i] = last[a[i]];
            }
            for (int k = 1; (1 << k) <= n; k++) {
                int len = 1 << k;
                for (int i = 1; i + len - 1 <= n; i++) {
                    stMin[k][i] = Math.min(
                            stMin[k - 1][i],
                            stMin[k - 1][i + (len >> 1)]);
                }
            }

            // helper for RMQ min on [l..r]
            class RMQ {
                int query(int l, int r) {
                    int span = r - l + 1;
                    int j = lg[span];
                    int left = stMin[j][l];
                    int right = stMin[j][r - (1 << j) + 1];
                    return left < right ? left : right;
                }
            }
            RMQ rmq = new RMQ();

            // initialize dp[n+1] = 0 in segtree
            {
                int leaf = segSize + (n + 1);
                seg[leaf] = 0;
                for (leaf >>= 1; leaf > 0; leaf >>= 1) {
                    seg[leaf] = Math.max(seg[2 * leaf], seg[2 * leaf + 1]);
                }
            }

            // DP from i=n down to 1:
            // dp[i] = 1 if R<i else 1 + max(dp[i+1..R+1])
            // and then update segtree at pos=i
            for (int i = n; i >= 1; i--) {
                // binary search for first mid in [i..n+1] where min(last[a[k]] k∈[i..mid]) <=
                // mid
                int lo = i, hi = n + 1;
                while (lo < hi) {
                    int mid = (lo + hi) >>> 1;
                    // if all last[a[k]]>mid => rmq(i,mid)>mid
                    if (rmq.query(i, mid) > mid) {
                        lo = mid + 1;
                    } else {
                        hi = mid;
                    }
                }
                int R = lo - 1;

                int dpi;
                if (R < i) {
                    dpi = 1;
                } else {
                    // range max on [i+1 .. R+1]
                    int L = i + 1 + segSize;
                    int Rpos = R + 1 + segSize;
                    int best = 0;
                    while (L <= Rpos) {
                        if ((L & 1) == 1)
                            best = Math.max(best, seg[L++]);
                        if ((Rpos & 1) == 0)
                            best = Math.max(best, seg[Rpos--]);
                        L >>= 1;
                        Rpos >>= 1;
                    }
                    dpi = 1 + best;
                }

                // update segtree at position i
                int p = segSize + i;
                seg[p] = dpi;
                for (p >>= 1; p > 0; p >>= 1) {
                    seg[p] = Math.max(seg[2 * p], seg[2 * p + 1]);
                }
            }

            // answer is dp[1] in the tree
            sb.append(seg[segSize + 1]).append('\n');
        }

        System.out.print(sb);
    }
}
