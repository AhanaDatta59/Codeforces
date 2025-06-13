import java.io.*;
import java.util.*;

public class Beautiful {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringBuilder answer = new StringBuilder();

        int T = Integer.parseInt(br.readLine().trim());
        while (T-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            long k = Long.parseLong(st.nextToken());

            long[] a = new long[n];
            int[] pop0 = new int[n];
            long baseBeauty = 0;

            st = new StringTokenizer(br.readLine());
            for (int i = 0; i < n; i++) {
                a[i] = Long.parseLong(st.nextToken());
                pop0[i] = Long.bitCount(a[i]);
                baseBeauty += pop0[i];
            }

            // Count how many elements are even => cheap +1 at cost=1
            int totalEven = 0;
            // Count how many a[i]%4 in {0,1} => +1 at cost=2
            int totalMod01 = 0;
            for (long x : a) {
                if ((x & 1) == 0)
                    totalEven++;
                int m4 = (int) (x & 3);
                if (m4 == 0 || m4 == 1)
                    totalMod01++;
            }

            long bestGain = 0;

            // Try reserving the "big jump" on each index j
            for (int j = 0; j < n; j++) {
                // how many cheap ops remain among the OTHER n-1 elements?
                int evenRem = totalEven - (((a[j] & 1) == 0) ? 1 : 0);
                int mod01Rem = totalMod01 - ((((int) (a[j] & 3)) == 0 ||
                        ((int) (a[j] & 3)) == 1) ? 1 : 0);

                int basePopJ = pop0[j];
                long aj = a[j];

                // Build all candidate big‐jump pairs (s, Δ)
                // Δ = popcount(aj + s) - basePopJ
                // where either (aj+s) = 2^m-1 for m<=~60, or s=k
                HashMap<Long, Integer> bestForS = new HashMap<>();
                // s=0
                bestForS.put(0L, 0);

                // upper m so that (2^m -1) <= aj + k
                long cap = aj + k + 1;
                int mmax = 63 - Long.numberOfLeadingZeros(cap);

                for (int m = 1; m <= mmax; m++) {
                    long targ = (1L << m) - 1;
                    if (targ < aj)
                        continue;
                    long s = targ - aj;
                    if (s > k)
                        continue;
                    int gain = m - basePopJ;
                    bestForS.merge(s, gain, Math::max);
                }

                // also the candidate "use all k here"
                int gainAtK = Long.bitCount(aj + k) - basePopJ;
                bestForS.merge(k, gainAtK, Math::max);

                // Evaluate each candidate (s,Δ)
                for (Map.Entry<Long, Integer> e : bestForS.entrySet()) {
                    long sJump = e.getKey();
                    int dJump = e.getValue();
                    long rem = k - sJump;
                    if (rem < 0)
                        continue;

                    // greedily spend the remainder on cost=1 ops then cost=2 ops
                    long use1 = Math.min(evenRem, rem);
                    rem -= use1;
                    long use2 = Math.min(mod01Rem, rem / 2);

                    long totalGain = dJump + use1 + use2;
                    if (totalGain > bestGain)
                        bestGain = totalGain;
                }
            }

            answer.append(baseBeauty + bestGain).append('\n');
        }

        System.out.print(answer);
    }
}
