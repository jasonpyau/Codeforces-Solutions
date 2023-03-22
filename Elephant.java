// https://codeforces.com/contest/617/problem/A

import java.io.*;
import static java.lang.System.out;
import static java.lang.Integer.parseInt;
 
public class Elephant {
    public static void main(String[] args) throws IOException {
        BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
        int input = parseInt(stdin.readLine());
        out.println(((input-1)/5)+1);
    }
 
}
