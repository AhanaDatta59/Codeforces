import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

public class Buttons {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        StringBuilder sb = new StringBuilder();

        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long a = Long.parseLong(st.nextToken());
            long b = Long.parseLong(st.nextToken());
            long c = Long.parseLong(st.nextToken());

            if (a > b) {
                sb.append("First\n");
            } else if (a < b) {
                sb.append("Second\n");
            } else { // a == b
                sb.append((c & 1L) == 1L ? "First\n" : "Second\n");
            }
        }
        System.out.print(sb.toString());
    }
}
