import java.io.*;
import java.util.*;

public class GoodProblem {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long n = Long.parseLong(st.nextToken());
            long l = Long.parseLong(st.nextToken());
            long r = Long.parseLong(st.nextToken());
            long k = Long.parseLong(st.nextToken());

            long ans;
            if ((n & 1) == 1) {
                ans = l;
            } else if (n == 2) {
                ans = -1;
            } else {
                long highestBit = Long.highestOneBit(l);
                long m = highestBit << 1;
                if (m > r) {
                    ans = -1;
                } else {
                    if (k <= n - 2) {
                        ans = l;
                    } else {
                        ans = m;
                    }
                }
            }

            sb.append(ans).append('\n');
        }
        System.out.print(sb);
    }
}
