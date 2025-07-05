import java.io.*;
import java.util.*;

public class VolcanicEruptions {
    static int N;
    static List<Integer>[] g;
    static int[] w;
    static int[] dist;     
    static int[] parent, depth;
    static int[] up;       
    static int LOG;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            String[] parts = br.readLine().split(" ");
            N = Integer.parseInt(parts[0]);
            int st = Integer.parseInt(parts[1]) - 1;  // 0‐based

            w = new int[N];
            parts = br.readLine().split(" ");
            for (int i = 0; i < N; i++) {
                w[i] = Integer.parseInt(parts[i]);
            }

           
            g = new ArrayList[N];
            for (int i = 0; i < N; i++) g[i] = new ArrayList<>();
            for (int i = 0; i < N-1; i++) {
                parts = br.readLine().split(" ");
                int u = Integer.parseInt(parts[0]) - 1;
                int v = Integer.parseInt(parts[1]) - 1;
                g[u].add(v);
                g[v].add(u);
            }

          
            bfsRoot();
            buildLifting();

            long answer = simulateMoves(st);
            sb.append(answer).append('\n');
        }
        System.out.print(sb);
    }

    static void bfsRoot() {
        dist = new int[N];
        parent = new int[N];
        depth = new int[N];
        Arrays.fill(parent, -1);
        Queue<Integer> q = new ArrayDeque<>();
        q.add(0);
        dist[0] = 0;
        depth[0] = 0;
        parent[0] = 0;
        while (!q.isEmpty()) {
            int u = q.poll();
            for (int v : g[u]) {
                if (v == parent[u]) continue;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                dist[v] = depth[v];   
                q.add(v);
            }
        }
    }

    static void buildLifting() {
        LOG = 1;
        while ((1<<LOG) <= N) LOG++;
        up = new int[N * LOG];
        for (int i = 0; i < N; i++) up[i] = parent[i];
        for (int k = 1; k < LOG; k++) {
            int base = k * N;
            int prev = (k-1)*N;
            for (int i = 0; i < N; i++) {
                up[base + i] = up[prev + up[prev + i]];
            }
        }
    }

    static int jump(int v, int steps) {
        for (int k = 0; k < LOG; k++) {
            if ((steps & (1<<k)) != 0) {
                v = up[k*N + v];
            }
        }
        return v;
    }

    static long simulateMoves(int st) {
        long S = 1;
        long time = 0;
        int cur = st;
        long moves = 0;

        PriorityQueue<Integer> pq = new PriorityQueue<>(
          (a,b) -> Integer.compare(dist[b], dist[a]));

       
        if (w[st] == 1) pq.add(st);
        boolean[] used = new boolean[N];
        used[st] = true;

        while (true) {
        
            S += w[cur];
            if (S <= 0) break;

           
            if (time >= dist[cur]) break;

           
            while (!pq.isEmpty() && dist[pq.peek()] <= time+1) {
                pq.poll();
            }
            if (!pq.isEmpty()) {
               
                int nxt = pq.poll();
                
                int lca = lca(cur, nxt);
                int upSteps = depth[cur] - depth[lca];
                int dnSteps = depth[nxt] - depth[lca];
               
                for (int i = 0; i < upSteps; i++) {
                    cur = parent[cur];
                    time++;
                    moves++;
                    
                    if (S + w[cur] <= 0 || time >= dist[cur]) return moves;
                    S += w[cur];
                }
               
                int back = nxt;
                for (int i = 0; i < dnSteps; i++) {
                   
                    cur = up(cur, lca, back);  
                    time++;
                    moves++;
                    if (S + w[cur] <= 0 || time >= dist[cur]) return moves;
                    S += w[cur];
                }
              
                if (!used[nxt]) {
                    used[nxt] = true;
                    // expose its neighbors for future +1 nodes
                    for (int v : g[nxt]) {
                        if (!used[v] && w[v] == 1) {
                            pq.add(v);
                            used[v] = true;
                        }
                    }
                }
               
            } else {
               
                break;
            }
        }

        return moves;
    }

   
    static int lca(int u, int v) {
        if (depth[u] < depth[v]) {
            int t = u; u = v; v = t;
        }
      
        int diff = depth[u] - depth[v];
        for (int k = 0; k < LOG; k++)
            if ((diff & (1<<k)) != 0)
                u = up[k*N + u];
        if (u == v) return u;
        for (int k = LOG-1; k >= 0; k--) {
            int uu = up[k*N + u], vv = up[k*N + v];
            if (uu != vv) {
                u = uu;
                v = vv;
            }
        }
        return parent[u];
    }

   
    static int up(int cur, int lca, int target) {
      
        if (cur == lca) {
            for (int ch : g[cur]) {
                if (depth[ch] == depth[cur]+1 && isAncestor(ch, target)) {
                    return ch;
                }
            }
            throw new RuntimeException("should not happen");
        } else {
          
            return parent[cur];
        }
    }

 
    static boolean isAncestor(int u, int v) {
      
        if (depth[v] < depth[u]) return false;
        int diff = depth[v] - depth[u];
        for (int k = 0; k < LOG; k++)
            if ((diff & (1<<k)) != 0)
                v = up[k*N + v];
        return v == u;
    }
}
