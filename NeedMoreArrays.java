import java.io.*;
import java.util.*;

public class NeedMoreArrays {
    public static void main(String[] args) throws IOException {
        // Fast I/O
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();

        int t = Integer.parseInt(in.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(in.readLine().trim());
            StringTokenizer st = new StringTokenizer(in.readLine());

            int blocks = 0;
            int last = Integer.MIN_VALUE; // sentinel for "no last picked"

            for (int i = 0; i < n; i++) {
                int x = Integer.parseInt(st.nextToken());
                if (blocks == 0) {
                    // pick the very first element
                    blocks = 1;
                    last = x;
                } else if (x >= last + 2) {
                    // can start a new block
                    blocks++;
                    last = x;
                }
                // otherwise skip x
            }

            out.append(blocks).append('\n');
        }

        System.out.print(out);
    }
}
