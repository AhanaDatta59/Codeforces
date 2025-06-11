import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class FalseAlarm {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder out = new StringBuilder();
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer tok = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(tok.nextToken());
            int x = Integer.parseInt(tok.nextToken());

            tok = new StringTokenizer(br.readLine());
            int first = -1, last = -1;
            for (int i = 1; i <= n; i++) {
                if (tok.nextToken().charAt(0) == '1') {
                    if (first == -1)
                        first = i;
                    last = i;
                }
            }

            // span of closed doors is last - first + 1
            out.append((last - first + 1) <= x ? "YES\n" : "NO\n");
        }
        System.out.print(out);
    }
}
