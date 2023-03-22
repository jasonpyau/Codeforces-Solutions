// https://codeforces.com/contest/149/problem/A

import java.io.*;
import java.util.*;
import static java.lang.System.out;
import static java.lang.Integer.parseInt;
 
public class BusinessTrip {
 
    final static int NUM_MON = 12;
    public static void main(String[] args) throws IOException {
        Scanner stdin = new Scanner(System.in);
        int k = stdin.nextInt();
        if (k == 0) {
            out.println(0);
            return;
        }
        int[] arr = new int[NUM_MON];
        for (int i = 0; i < NUM_MON; i++)
            arr[i] = stdin.nextInt();
        
        for (int i = 0; i < NUM_MON; i++) {
            int max = arr[i];
            for (int j = i+1; j < NUM_MON; j++) {
                if (arr[j] > max) {
                    max = arr[j];
                    arr[j] = arr[i];
                    arr[i] = max;
                } 
            }
        }
        int sum = 0;
        for (int i = 0; i < NUM_MON; i++) {
            if ((sum += arr[i]) >= k) {
                out.println(i+1);
                return;
            }
        }
        out.println(-1);
    }
