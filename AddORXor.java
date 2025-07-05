import java.io.*;
import java.util.*;

public class AddORXor {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb = new StringBuilder();
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());

            long ans;
            if (a == b) {
                ans = 0;
            } else if (b < a) {
                if (a == b + 1 && (a % 2 == 1)) {
                    ans = y;
                } else {
                    ans = -1;
                }
            } else {
                int d = b - a;
                if (y >= x) {
                    ans = (long) d * x;
                } else {
                    int evens = (a % 2 == 0) ? ((d + 1) / 2) : (d / 2);
                    int odds  = d - evens;
                    ans = (long) evens * y + (long) odds * x;
                }
            }

            sb.append(ans).append('\n');
        }
        System.out.print(sb);
    }
}
