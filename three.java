import java.io.*;
import java.util.*;

public class three {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            int[] x = new int[n];
            int[] y = new int[n];
            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());
                x[i] = Integer.parseInt(st.nextToken());
                y[i] = Integer.parseInt(st.nextToken());
            }
          
            long[] u = new long[n], v = new long[n];
            for (int i = 0; i < n; i++) {
                u[i] = (long)x[i] + y[i];
                v[i] = (long)x[i] - y[i];
            }
          
            Integer[] idxU = new Integer[n], idxV = new Integer[n];
            for (int i = 0; i < n; i++) {
                idxU[i] = i;
                idxV[i] = i;
            }
           
            Arrays.sort(idxU, (i, j) -> {
                int cmp = Long.compare(u[i], u[j]);
                if (cmp != 0) return cmp;
                return Long.compare(v[i], v[j]);
            });
           
            Arrays.sort(idxV, (i, j) -> {
                int cmp = Long.compare(v[i], v[j]);
                if (cmp != 0) return cmp;
                return Long.compare(u[i], u[j]);
            });
           
            long sumU = 0, sumV = 0;
            int half = n >> 1;
            StringBuilder mbU = new StringBuilder();
            StringBuilder mbV = new StringBuilder();
            for (int k = 0; k < half; k++) {
                int i1 = idxU[k], i2 = idxU[n - 1 - k];
                sumU += Math.abs(x[i1] - x[i2]) + Math.abs(y[i1] - y[i2]);
                mbU.append((i1+1)).append(' ').append((i2+1)).append('\n');

                int j1 = idxV[k], j2 = idxV[n - 1 - k];
                sumV += Math.abs(x[j1] - x[j2]) + Math.abs(y[j1] - y[j2]);
                mbV.append((j1+1)).append(' ').append((j2+1)).append('\n');
            }
          
            if (sumU >= sumV) {
                out.print(mbU);
            } else {
                out.print(mbV);
            }
        }
        out.flush();
    }
}
