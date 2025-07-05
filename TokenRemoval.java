import java.io.*;
import java.util.*;

public class TokenRemoval {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            long[] dp = new long[n+1];
            dp[0] = 1;

            int maxK = 0;  
            for (int x = n; x >= 1; x--) {
                long nxp1 = (n - x + 1L) % m;
                
                for (int j = maxK; j >= 0; j--) {
                    long ways = dp[j];
                    if (ways != 0) {
                        long factor = (nxp1 - j) % m;
                        if (factor < 0) factor += m;
                        long add = (ways * x) % m * factor % m;
                        dp[j+1] = (dp[j+1] + add) % m;
                    }
                }
                maxK++;
            }

            long ans = 0;
            for (int j = 0; j <= n; j++) {
                ans = (ans + dp[j]) % m;
            }
            sb.append(ans).append('\n');
        }
        System.out.print(sb);
    }
}
