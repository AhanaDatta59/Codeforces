import java.io.*;
import java.util.*;

public class ChangingString {
    public static void main(String[] args) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter out = new PrintWriter(System.out);
        int t = Integer.parseInt(in.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            int n = Integer.parseInt(st.nextToken());
            int q = Integer.parseInt(st.nextToken());
            String s = in.readLine();
            char[][] ops = new char[q][2];
            for (int i = 0; i < q; i++) {
                st = new StringTokenizer(in.readLine());
                ops[i][0] = st.nextToken().charAt(0);
                ops[i][1] = st.nextToken().charAt(0);
            }

            int INF = 10000000;
            int[][] costs = new int[3][3];
            for (int i = 0; i < 3; i++) {
                Arrays.fill(costs[i], INF);
                costs[i][i] = 0;
            }

            for (int i = q - 1; i >= 0; i--) {
                int x = ops[i][0] - 'a';
                int y = ops[i][1] - 'a';
                int[][] newCosts = new int[3][3];
                for (int j = 0; j < 3; j++) {
                    newCosts[j] = costs[j].clone();
                }
                for (int target = 0; target < 3; target++) {
                    int candidate = costs[y][target] + 1;
                    if (candidate < newCosts[x][target]) {
                        newCosts[x][target] = candidate;
                    }
                }
                costs = newCosts;
            }

            int remaining = q;
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < s.length(); i++) {
                int state = s.charAt(i) - 'a';
                char chosen = 'z';
                int costUsed = -1;
                for (int target = 0; target < 3; target++) {
                    if (costs[state][target] <= remaining) {
                        chosen = (char) ('a' + target);
                        costUsed = costs[state][target];
                        break;
                    }
                }
                if (chosen == 'z') {
                    chosen = s.charAt(i);
                    costUsed = 0;
                }
                sb.append(chosen);
                remaining -= costUsed;
            }
            out.println(sb.toString());
        }
        out.close();
    }
}