import java.io.*;
import java.util.*;

public class LineSegments {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            StringTokenizer st = new StringTokenizer(br.readLine());
            long px = Long.parseLong(st.nextToken());
            long py = Long.parseLong(st.nextToken());
            long qx = Long.parseLong(st.nextToken());
            long qy = Long.parseLong(st.nextToken());

            st = new StringTokenizer(br.readLine());
            long sum = 0;
            long max = 0;
            for (int i = 0; i < n; i++) {
                long a = Long.parseLong(st.nextToken());
                sum += a;
                if (a > max) max = a;
            }

            long rest = sum - max;
            long L = max > rest ? max - rest : 0;
            long U = sum;

            long dx = qx - px;
            long dy = qy - py;
            long dist2 = dx*dx + dy*dy;

            if (dist2 >= L*L && dist2 <= U*U) {
                out.append("Yes\n");
            } else {
                out.append("No\n");
            }
        }
        System.out.print(out);
    }
}
