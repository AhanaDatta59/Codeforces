import java.io.*;
import java.util.*;

public class ComeALittleCloser {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();
        int t = Integer.parseInt(in.readLine().trim());

        while (t-- > 0) {
            int n = Integer.parseInt(in.readLine().trim());
            int[] xs = new int[n], ys = new int[n];
            long minX1 = Long.MAX_VALUE, minX2 = Long.MAX_VALUE;
            long maxX1 = Long.MIN_VALUE, maxX2 = Long.MIN_VALUE;
            long minY1 = Long.MAX_VALUE, minY2 = Long.MAX_VALUE;
            long maxY1 = Long.MIN_VALUE, maxY2 = Long.MIN_VALUE;

            for (int i = 0; i < n; i++) {
                StringTokenizer st = new StringTokenizer(in.readLine());
                int x = Integer.parseInt(st.nextToken());
                int y = Integer.parseInt(st.nextToken());
                xs[i] = x;
                ys[i] = y;
                // update minX1/minX2
                if (x <= minX1) {
                    minX2 = minX1;
                    minX1 = x;
                } else if (x < minX2) {
                    minX2 = x;
                }
                // update maxX1/maxX2
                if (x >= maxX1) {
                    maxX2 = maxX1;
                    maxX1 = x;
                } else if (x > maxX2) {
                    maxX2 = x;
                }
                // same for Y
                if (y <= minY1) {
                    minY2 = minY1;
                    minY1 = y;
                } else if (y < minY2) {
                    minY2 = y;
                }
                if (y >= maxY1) {
                    maxY2 = maxY1;
                    maxY1 = y;
                } else if (y > maxY2) {
                    maxY2 = y;
                }
            }

            // no-move bounding box
            long w0 = (maxX1 - minX1 + 1);
            long h0 = (maxY1 - minY1 + 1);
            long best = w0 * h0;

            // consider removing each point i
            for (int i = 0; i < n; i++) {
                long lowX = (xs[i] == minX1 ? minX2 : minX1);
                long highX = (xs[i] == maxX1 ? maxX2 : maxX1);
                long lowY = (ys[i] == minY1 ? minY2 : minY1);
                long highY = (ys[i] == maxY1 ? maxY2 : maxY1);

                long wi = highX - lowX + 1;
                long hi = highY - lowY + 1;

                // if all points collinear in one direction, ensure width/height >=1
                if (wi <= 0)
                    wi = 1;
                if (hi <= 0)
                    hi = 1;

                long area;
                long base = wi * hi;
                if (base >= n) {
                    area = base;
                } else {
                    // expand height
                    long needH = Math.max(hi, (n + wi - 1) / wi);
                    long areaA = wi * needH;
                    // expand width
                    long needW = Math.max(wi, (n + hi - 1) / hi);
                    long areaB = needW * hi;
                    area = Math.min(areaA, areaB);
                }
                if (area < best)
                    best = area;
            }

            out.append(best).append('\n');
        }

        System.out.print(out);
    }
}
