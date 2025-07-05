import java.io.*;
import java.util.*;

public class AndConstraint {
    static final int B = 30;  
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[] a = new int[n-1];
            int[] b = new int[n];
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n-1; i++) {
                a[i] = Integer.parseInt(st.nextToken());
            }
            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                b[i] = Integer.parseInt(st.nextToken());
            }

            long totalCost = 0;
            boolean bad = false;
            for (int i = 0; i < n; i++) {
                int mustOne = 0;
                if (i > 0)  mustOne |= a[i-1];
                if (i < n-1) mustOne |= a[i];
                int v = b[i];
                if ((v & mustOne) == mustOne) {
                    continue;
                }
               
                int deltaMask = mustOne & ~v;  
                int kbit = 31 - Integer.numberOfLeadingZeros(deltaMask);
             
                int prefix = (v >>> kbit) + 1;   // bump at kbit
                int y = (prefix << kbit)
                      | (mustOne & ((1 << kbit) - 1));
           
                totalCost += (long)(y - v);
                if (totalCost < 0) { bad = true; break; }
            }

            sb.append(bad ? -1 : totalCost).append('\n');
        }
        System.out.print(sb);
    }
}
