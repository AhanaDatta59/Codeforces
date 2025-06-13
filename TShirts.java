import java.io.*;
import java.util.*;

public class TShirts {
    static class Shirt {
        int price, quality;

        Shirt(int price, int quality) {
            this.price = price;
            this.quality = quality;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        // 1) Read n and the shirt types
        int n = Integer.parseInt(in.readLine());
        Shirt[] shirts = new Shirt[n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(in.readLine());
            int c = Integer.parseInt(st.nextToken());
            int q = Integer.parseInt(st.nextToken());
            shirts[i] = new Shirt(c, q);
        }

        // 2) Sort by quality desc, price asc
        Arrays.sort(shirts, (a, b) -> {
            if (a.quality != b.quality) {
                return Integer.compare(b.quality, a.quality);
            } else {
                return Integer.compare(a.price, b.price);
            }
        });

        // 3) Build prefix sums of prices
        long[] prefix = new long[n + 1];
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + shirts[i - 1].price;
        }

        // 4) Answer queries
        int k = Integer.parseInt(in.readLine());
        st = new StringTokenizer(in.readLine());
        StringBuilder out = new StringBuilder();
        for (int i = 0; i < k; i++) {
            long budget = Long.parseLong(st.nextToken());
            // Binary search for the largest idx with prefix[idx] <= budget
            int lo = 0, hi = n;
            while (lo < hi) {
                int mid = (lo + hi + 1) >>> 1;
                if (prefix[mid] <= budget)
                    lo = mid;
                else
                    hi = mid - 1;
            }
            out.append(lo).append(i + 1 < k ? ' ' : '\n');
        }

        System.out.print(out);
    }
}
