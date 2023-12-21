import java.io.*;
import java.util.Scanner;

public class MazeSolver {
    static char[][] maze;
    static int m, n; // dimensions of the maze; row and col

    public static char[][] setMaze(String input) throws IOException {
        File inputfile = new File(input);
        BufferedReader br = new BufferedReader(new FileReader(inputfile));
        Scanner scanner = new Scanner(inputfile);

        //just to read two integers
        int row = scanner.nextInt();
        int col = scanner.nextInt();
        scanner.close();

        String line = br.readLine();
        System.out.println(row);
        System.out.println(col);
        char[][] array = new char[row][col];
            for (int i = 0; i < row; i++) {
                line = br.readLine();
                for (int j = 0; j < col; j++) {
                        array[i][j] = line.charAt(j);
                    }
                }
        return array;
        }

    public static boolean isValid(int x, int y) {
        // modify
        if(x >= maze.length || y >= maze[0].length || y < 0 || x < 0){
            return false;
        }
        else if(maze[x][y] != '#' && maze[x][y] != 'v') {
            return true;
        }
        return false;
    }


    public static boolean solveMaze(int x, int y) {
        //finds the start if it's there.
        if(x == -1 && y == -1){
            for(int i = 0; i < maze.length; i++){
                for(int j = 0; j < maze[0].length; j++){
                    if(maze[i][j] == 'S'){
                        x = i;
                        y = j;
                    }
                }
            }
        }
        if (maze[x][y] == 'G') {
            return true;
        }

        // mark the current location as visited
        maze[x][y] = 'v';

        // check if it's safe to move to the next location in each direction
        // if it's safe, recursively call the solveMaze function on that location
        if (isValid(x + 1, y) && solveMaze(x + 1, y)) {
            return true;

        } else if (isValid(x, y + 1) && solveMaze(x, y + 1)) {
            return true;

        } else if (isValid(x - 1, y) && solveMaze(x - 1, y)) {
            return true;

        } else if (isValid(x, y - 1) && solveMaze(x, y - 1)) {
            return true;
        }

        // if none of the directions lead to the end of the maze, backtrack
        // by marking the current location as unvisited ('.')
        maze[x][y] = '.';
        return false;
    }

    public static boolean solve(String file) throws IOException {
        // modify
        MazeSolver myMazesolver = new MazeSolver();
        MazeSolver.maze = MazeSolver.setMaze(file);

        if(myMazesolver.solveMaze(-1,-1) == true){
            System.out.println("Maze can be solved: " + true);
            return true;
        }
        System.out.println("Maze can be solved: " + false);
        return false;
    }


    public static void main(String[] args) throws IOException {
        solve("HW1/maze.txt");
        solve("HW1/maze2.txt");
        solve("HW1/maze3.txt");
    }

}