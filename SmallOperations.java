import java.io.*;
import java.util.*;

public class SmallOperations {
    static final int INF = -1;

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(in.readLine().trim());
        StringBuilder out = new StringBuilder();
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            if (x == y) {
                out.append(0).append('\n');
                continue;
            }

            // Set an upper‐bound on the search space
            int MAX = Math.min(2_000_000, Math.max(x, y) * 2);

            // Distances from x and from y
            int[] distX = new int[MAX + 1], distY = new int[MAX + 1];
            Arrays.fill(distX, INF);
            Arrays.fill(distY, INF);

            Deque<Integer> qX = new ArrayDeque<>();
            Deque<Integer> qY = new ArrayDeque<>();
            distX[x] = 0;
            qX.add(x);
            distY[y] = 0;
            qY.add(y);

            int answer = -1;
            // alternate expansions
            while (!qX.isEmpty() || !qY.isEmpty()) {
                answer = expand(qX, distX, distY, k, MAX);
                if (answer != -1)
                    break;
                answer = expand(qY, distY, distX, k, MAX);
                if (answer != -1)
                    break;
            }
            out.append(answer).append('\n');
        }
        System.out.print(out);
    }

    /**
     * Expand one layer of BFS from queue qA with distances distA,
     * checking for meeting any node already visited by distB.
     */
    static int expand(Deque<Integer> qA, int[] distA, int[] distB, int k, int MAX) {
        int sz = qA.size();
        while (sz-- > 0) {
            int v = qA.poll();
            int d = distA[v];

            // 1) Multiplication edges
            for (int a = 1; a <= k; a++) {
                long w = (long) v * a;
                if (w > MAX)
                    break;
                int u = (int) w;
                if (distA[u] == INF) {
                    distA[u] = d + 1;
                    // if the other BFS has visited u, we meet here
                    if (distB[u] != INF) {
                        return distA[u] + distB[u];
                    }
                    qA.add(u);
                }
            }

            // 2) Integer‐root edges
            for (int a = 2; a <= k; a++) {
                int u = integerRoot(v, a);
                if (u <= 1)
                    break; // no further nontrivial roots
                if (distA[u] == INF) {
                    distA[u] = d + 1;
                    if (distB[u] != INF) {
                        return distA[u] + distB[u];
                    }
                    qA.add(u);
                }
            }
        }
        return -1;
    }

    /**
     * If there exists an integer u>=2 with u^a == v, return u; else return -1.
     * We compute u ≈ floor(v^(1/a)) then adjust.
     */
    static int integerRoot(int v, int a) {
        int u = (int) Math.pow(v, 1.0 / a);
        if (u < 2)
            return -1;
        long pw = 1;
        for (int i = 0; i < a; i++) {
            pw *= u;
            if (pw > v)
                break;
        }
        if (pw > v) {
            // maybe we guessed one too large
            u--;
            pw = 1;
            for (int i = 0; i < a; i++)
                pw *= u;
        }
        return (pw == v ? u : -1);
    }
}
