import java.io.*;
import java.util.*;

public class WildFlower {
    static final int MOD = 1_000_000_007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());

        // Precompute powers of two up to 2e5+5
        int MAXN = 200_000 + 5;
        long[] pow2 = new long[MAXN];
        pow2[0] = 1;
        for (int i = 1; i < MAXN; i++) {
            pow2[i] = (pow2[i - 1] << 1) % MOD;
        }

        StringBuilder sb = new StringBuilder();
        while (T-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            List<Integer>[] adj = new List[n + 1];
            for (int i = 1; i <= n; i++)
                adj[i] = new ArrayList<>();
            for (int i = 0; i < n - 1; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                adj[u].add(v);
                adj[v].add(u);
            }

            // Root the tree at 1 and build parent/children counts
            int[] parent = new int[n + 1];
            int[] childCount = new int[n + 1];
            parent[1] = 0;
            Deque<Integer> dq = new ArrayDeque<>();
            dq.add(1);
            while (!dq.isEmpty()) {
                int u = dq.poll();
                for (int w : adj[u]) {
                    if (w == parent[u])
                        continue;
                    parent[w] = u;
                    childCount[u]++;
                    dq.add(w);
                }
            }

            // Count rooted‐leaves (nodes with no children)
            int leaves = 0;
            for (int i = 1; i <= n; i++) {
                if (childCount[i] == 0)
                    leaves++;
            }
            if (leaves > 2) {
                sb.append("0\n");
                continue;
            }
            // Case 1: exactly one leaf → it's a single path → all 2^n assignments work
            if (leaves == 1) {
                sb.append(pow2[n]).append('\n');
                continue;
            }

            // Case 2: exactly two leaves → there must be exactly one branching node S with
            // 2 children
            int S = -1;
            for (int i = 1; i <= n; i++) {
                if (childCount[i] == 2) {
                    S = i;
                    break;
                }
            }
            // Gather its two children
            int c1 = -1, c2 = -1;
            for (int w : adj[S]) {
                if (parent[w] == S) {
                    if (c1 < 0)
                        c1 = w;
                    else
                        c2 = w;
                }
            }

            // Measure the two chain‐lengths from S down
            int len1 = 0, len2 = 0;
            // walk from c1
            {
                int cur = c1;
                while (true) {
                    len1++;
                    if (childCount[cur] != 1)
                        break;
                    // find the unique child
                    for (int w : adj[cur]) {
                        if (parent[w] == cur) {
                            cur = w;
                            break;
                        }
                    }
                }
            }
            // walk from c2
            {
                int cur = c2;
                while (true) {
                    len2++;
                    if (childCount[cur] != 1)
                        break;
                    for (int w : adj[cur]) {
                        if (parent[w] == cur) {
                            cur = w;
                            break;
                        }
                    }
                }
            }

            long ans;
            if (len1 == len2) {
                // ℓ₁ == ℓ₂
                // ans = 2^{ n - 3 }
                ans = pow2[n - 3];
            } else {
                // ℓ₁ != ℓ₂
                int d = Math.min(len1, len2);
                // ans = 3 * 2^{ n - (2*d + 1) } mod
                int exp = n - (2 * d + 1);
                ans = (3 * pow2[exp]) % MOD;
            }

            sb.append(ans).append('\n');
        }

        System.out.print(sb);
    }
}
