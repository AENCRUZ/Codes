import java.util.*;

public class NQueens {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("n = ");
        int n = input.nextInt();
        solveNQueens(n);
    }

    public static void solveNQueens(int n) {
        char[][] board = new char[n][n];
        for (char[] row : board)
            Arrays.fill(row, '.');
        
        if (placeQueen(board, 0)) {
            for (char[] row : board) {
                for (int j = 0; j < n; j++) {
                    System.out.print(row[j]);
                    if (j < n - 1) System.out.print(" ");
                }
                System.out.println();
            }
        } else {
            System.out.println("No solution exists.");
        }
    }

    static boolean placeQueen(char[][] board, int row) {
        int n = board.length;
        if (row == n)
            return true;

        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col)) {
                board[row][col] = 'Q';
                if (placeQueen(board, row + 1))
                    return true;
                board[row][col] = '.';
            }
        }
        return false;
    }

    static boolean isSafe(char[][] board, int row, int col) {
        int n = board.length;
        for (int i = 0; i < row; i++)
            if (board[i][col] == 'Q') return false;
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q') return false;
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q') return false;
        return true;
    }
}