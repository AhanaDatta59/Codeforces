import java.io.*;
import java.util.*;

public class easy {
    static final long STRIP_MAX = 1_000_000_000_000_000L;

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();

        int T = Integer.parseInt(in.readLine().trim());
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());

            long[] p = new long[n];
            st = new StringTokenizer(in.readLine());
            for (int i = 0; i < n; i++) {
                p[i] = Long.parseLong(st.nextToken());
            }

            int[] d = new int[n];
            st = new StringTokenizer(in.readLine());
            for (int i = 0; i < n; i++) {
                d[i] = Integer.parseInt(st.nextToken());
            }

            // Map each light‐position to its index 0..n-1
            HashMap<Long, Integer> pos2idx = new HashMap<>();
            for (int i = 0; i < n; i++) {
                pos2idx.put(p[i], i);
            }

            // Prepare our “visited” timestamp array:
            // visitedStamp[i][dir][tmod] == lastQueryId when we visited
            int[][][] visitedStamp = new int[n][2][k];
            int queryId = 0;

            int Q = Integer.parseInt(in.readLine().trim());
            st = new StringTokenizer(in.readLine());
            for (int qi = 0; qi < Q; qi++) {
                long start = Long.parseLong(st.nextToken());
                queryId++;

                boolean leaves = willLeave(start, n, k, p, d, pos2idx, visitedStamp, queryId);
                out.append(leaves ? "YES\n" : "NO\n");
            }
        }

        System.out.print(out);
    }

    static boolean willLeave(long pos, int n, int k,
            long[] p, int[] d,
            HashMap<Long, Integer> pos2idx,
            int[][][] visitedStamp,
            int queryId) {
        int dir = +1; // +1 = right, -1 = left
        long t = 0;

        // 1) Skip from a non-light start to first event (either a light or off-strip)
        while (true) {
            if (pos < 1 || pos > STRIP_MAX)
                return true;
            Integer j0 = pos2idx.get(pos);
            if (j0 != null)
                break; // we landed on a light
            // else march straight until next light or strip‐end
            long D = nextEventDistance(pos, dir, n, p);
            if (D < 0)
                return true; // -1 signals "we run off the strip"
            pos += dir * D;
            t += D;
        }

        // 2) Now iteratively process light‐hits
        while (true) {
            if (pos < 1 || pos > STRIP_MAX)
                return true;

            // We must be exactly on a light cell here
            int j = pos2idx.get(pos);
            int tmod = (int) (t % k);
            int di = (dir == 1 ? 1 : 0);

            // cycle‐detection
            if (visitedStamp[j][di][tmod] == queryId) {
                return false;
            }
            visitedStamp[j][di][tmod] = queryId;

            // 2a) If the light is red now, reverse
            if (tmod == d[j]) {
                dir = -dir;
            }
            // 2b) Step one cell
            pos += dir;
            t++;
            if (pos < 1 || pos > STRIP_MAX)
                return true;

            // 2c) If that lands on another light, loop back;
            // else skip across the empty run again
            if (pos2idx.containsKey(pos)) {
                continue;
            }
            while (true) {
                long D = nextEventDistance(pos, dir, n, p);
                if (D < 0)
                    return true;
                pos += dir * D;
                t += D;
                if (pos < 1 || pos > STRIP_MAX)
                    return true;
                // now pos must be a light
                break;
            }
        }
    }

    /**
     * Compute how many steps we can march from 'pos' in direction 'dir'
     * until either we hit a light, or we exit the strip.
     * Returns:
     * >0 = the distance to the next light,
     * -1 = we leave the strip before hitting any light.
     */
    static long nextEventDistance(long pos, int dir, int n, long[] p) {
        if (dir == 1) {
            // find first light strictly > pos
            int idx = upperBound(p, pos);
            long dLight = (idx < n ? p[idx] - pos : Long.MAX_VALUE);
            long dEdge = STRIP_MAX - pos + 1;
            if (dEdge <= dLight)
                return -1; // run off before any light
            return dLight;
        } else {
            // dir == -1, head left
            int idx = lowerBound(p, pos) - 1;
            long dLight = (idx >= 0 ? pos - p[idx] : Long.MAX_VALUE);
            long dEdge = pos; // distance to cell 0 from pos
            if (dEdge <= dLight)
                return -1;
            return dLight;
        }
    }

    // first index i with p[i] > key
    static int upperBound(long[] arr, long key) {
        int idx = Arrays.binarySearch(arr, key);
        if (idx < 0)
            return -idx - 1;
        // if exact match at idx, we want idx+1
        while (idx < arr.length && arr[idx] == key)
            idx++;
        return idx;
    }

    // first index i with p[i] >= key
    static int lowerBound(long[] arr, long key) {
        int idx = Arrays.binarySearch(arr, key);
        if (idx < 0)
            return -idx - 1;
        // exact match
        while (idx > 0 && arr[idx - 1] == key)
            idx--;
        return idx;
    }
}
