import java.io.*;

public class Shrink {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine().trim());
            // Print: 2, 3, 4, ... , n, 1
            // This permutation always achieves score = n - 2.
            for (int i = 2; i <= n; i++) {
                bw.write(i + " ");
            }
            bw.write("1\n");
        }
        bw.flush();
    }
}
