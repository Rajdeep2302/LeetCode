import java.util.ArrayList;
import java.util.List;

class Solution {
    public String convert(String s, int numRows) {
        if (numRows == 1) {
            return s;
        }

        List<StringBuilder> rows = new ArrayList<>();
        for (int i = 0; i < numRows; i++) {
            rows.add(new StringBuilder());
        }

        int currentRow = 0;
        boolean goingDown = false;

        for (char c : s.toCharArray()) {
            rows.get(currentRow).append(c);

            if (currentRow == 0 || currentRow == numRows - 1) {
                goingDown = !goingDown;
            }

            if (goingDown) {
                currentRow++;
            } else {
                currentRow--;
            }
        }

        StringBuilder result = new StringBuilder();
        for (StringBuilder row : rows) {
            result.append(row);
        }

        return result.toString();
    }
}

public class Main {
    public static void main(String[] args) {
        Solution sol = new Solution();

        String s1 = "PAYPALISHIRING";
        int numRows1 = 3;
        System.out.println("Input: s = \"" + s1 + "\", numRows = " + numRows1);
        System.out.println("Output: \"" + sol.convert(s1, numRows1) + "\""); 

        String s2 = "PAYPALISHIRING";
        int numRows2 = 4;
        System.out.println("\nInput: s = \"" + s2 + "\", numRows = " + numRows2);
        System.out.println("Output: \"" + sol.convert(s2, numRows2) + "\""); 

        String s3 = "A";
        int numRows3 = 1;
        System.out.println("\nInput: s = \"" + s3 + "\", numRows = " + numRows3);
        System.out.println("Output: \"" + sol.convert(s3, numRows3) + "\"");

        String s4 = "AB";
        int numRows4 = 1;
        System.out.println("\nInput: s = \"" + s4 + "\", numRows = " + numRows4);
        System.out.println("Output: \"" + sol.convert(s4, numRows4) + "\"");

        String s5 = "ABCDE";
        int numRows5 = 2;
        System.out.println("\nInput: s = \"" + s5 + "\", numRows = " + numRows5);
        System.out.println("Output: \"" + sol.convert(s5, numRows5) + "\""); 
    }
}
