// https://codeforces.com/contest/1800/problem/A

import java.io.*;
import static java.lang.System.out;
import static java.lang.Integer.parseInt;
 
public class IsItACat {
    public static void main(String[] args) throws IOException {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        int nC = parseInt(stdin.readLine());
        for (int tC = 0; tC < nC; tC++) {
            int sL = parseInt(stdin.readLine());
            String s = stdin.readLine();
            out.println((isCat(s, sL) ? "YES" : "NO"));
        }
    }
 
    public static boolean isCat(String s, int sL) {
        int i = 0;
        boolean b = false;
        for (; i < sL; i++) {
            char ch = s.charAt(i);
            if (ch == 'm' || ch == 'M')
                b = true;
            else if (b && (ch == 'e' || ch == 'E'))
                break;
            else
                return false;
        }
        b = false;
        for (; i < sL; i++) {
            char ch = s.charAt(i);
            if (ch == 'e' || ch == 'E')
                b = true;
            else if (b && (ch == 'o' || ch == 'O'))
                break;
            else 
                return false;
        }
        b = false;
        for (; i < sL; i++) {
            char ch = s.charAt(i);
            if (ch == 'o' || ch == 'O')
                b = true;
            else if (b && (ch == 'w' || ch == 'W'))
                break;
            else
                return false;
        }
        for (; i < sL; i++) {
            char ch = s.charAt(i);
            if (ch == 'w' || ch == 'W') {
                if (i == sL - 1)
                    return true;
            }
            else
                    return false;
        }
        return false;
    }
}
