import java.io.*;
import java.util.*;

public class KireiAttacksEstate {
    static class Edge {
        int to, next;
    }

    static int[] head;
    static Edge[] edges;
    static int edgeCnt;
    static int n;

    static void addEdge(int u, int v) {
        edges[edgeCnt] = new Edge();
        edges[edgeCnt].to = v;
        edges[edgeCnt].next = head[u];
        head[u] = edgeCnt++;
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine().trim());
        StringBuilder out = new StringBuilder();
        while (t-- > 0) {
            n = Integer.parseInt(in.readLine().trim());
            long[] a = new long[n + 1];
            StringTokenizer st = new StringTokenizer(in.readLine());
            for (int i = 1; i <= n; i++) {
                a[i] = Long.parseLong(st.nextToken());
            }
            // build adjacency
            head = new int[n + 1];
            Arrays.fill(head, -1);
            edges = new Edge[2 * (n - 1)];
            edgeCnt = 0;
            for (int i = 0; i < n - 1; i++) {
                st = new StringTokenizer(in.readLine());
                int u = Integer.parseInt(st.nextToken());
                int v = Integer.parseInt(st.nextToken());
                addEdge(u, v);
                addEdge(v, u);
            }

            long[] ans = new long[n + 1];

            // explicit DFS stack
            // each frame: (u, parent, nextEdgeIdx, depthParity, val, minVal, maxVal)
            Deque<long[]> stack = new ArrayDeque<>();
            // initialize: at root=1, depthParity=0 (even), val=a[1], minVal=0,maxVal=0 for
            // prefix
            // we push entry frame with nextEdgeIdx = -1 to signal “first visit”
            stack.push(new long[] { 1, 0, -1, 0, a[1], 0L, 0L });

            while (!stack.isEmpty()) {
                long[] f = stack.pop();
                int u = (int) f[0];
                int p = (int) f[1];
                int ei = (int) f[2];
                int par = (int) f[3]; // depth[u] % 2 (0=even,1=odd)
                long val_u = f[4];
                long minV = f[5];
                long maxV = f[6];

                if (ei == -1) {
                    // first time we see u: compute its threat
                    // threat[u] = if depth even: val[u] - minV
                    // else: maxV - val[u]
                    long threat = (par == 0 ? val_u - minV : maxV - val_u);
                    ans[u] = threat;

                    // update minV, maxV with val_u before visiting children
                    minV = Math.min(minV, val_u);
                    maxV = Math.max(maxV, val_u);

                    // mark nextEdgeIdx = head[u] for iterating adjacency
                    ei = head[u];
                    // push back frame to continue after children
                    f[2] = ei;
                    f[5] = minV;
                    f[6] = maxV;
                    stack.push(f);
                    // then push the first child
                    if (ei != -1) {
                        int v = edges[ei].to;
                        if (v != p) {
                            // compute child val and parity
                            int childPar = par ^ 1;
                            long val_v = (childPar == 0 ? val_u + a[v] // even depth => add
                                    : val_u - a[v]); // odd depth => subtract
                            stack.push(new long[] { v, u, -1, childPar, val_v, minV, maxV });
                        }
                    }
                } else {
                    // we are returning from a child (or just re-entering)
                    ei = edges[ei].next;
                    // skip parent link
                    while (ei != -1 && edges[ei].to == p) {
                        ei = edges[ei].next;
                    }
                    if (ei != -1) {
                        // still have a child to visit
                        f[2] = ei;
                        stack.push(f);
                        int v = edges[ei].to;
                        // compute child frame
                        int childPar = par ^ 1;
                        long val_v = (childPar == 0 ? val_u + a[v] : val_u - a[v]);
                        stack.push(new long[] { v, u, -1, childPar, val_v, minV, maxV });
                    }
                    // else no more children: simply drop frame
                }
            }

            // output
            for (int i = 1; i <= n; i++) {
                out.append(ans[i]).append(' ');
            }
            out.append('\n');
        }
        System.out.print(out);
    }
}
