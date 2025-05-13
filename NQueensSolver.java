public class NQueensSolver {

    public static void main(String[] args) {
        int n = 8; 
        solveNQueens(n);
    }

    public static void solveNQueens(int n) {
        int[] board = new int[n]; 
        placeQueens(board, 0, n);
    }

    private static void placeQueens(int[] board, int row, int n) {
        if (row == n) {
            printBoard(board);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col)) {
                board[row] = col;
                placeQueens(board, row + 1, n);
            }
        }
    }

    private static boolean isSafe(int[] board, int row, int col) {
        for (int i = 0; i < row; i++) {
            if (board[i] == col || Math.abs(board[i] - col) == Math.abs(i - row)) {
                return false;
            }
        }
        return true;
    }

    private static void printBoard(int[] board) {
        int n = board.length;
        System.out.println("Solution:");
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (board[row] == col) {
                    System.out.print(" Q ");
                } else {
                    System.out.print(" . ");
                }
            }
            System.out.println();
        }
        System.out.println();
    }
}
