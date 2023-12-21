import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.util.Scanner;

// Feel free to reuse from HW1

public class MazeSolver {
    static char[][] maze;
    static int m, n; // dimensions of the maze

    /*
    TODO: setMaze - sets up the board
    This method will take in a String, file, which is the path of the file we want to look at.
    Using BufferedReader and FileReader, write this method so that it sets the rows, m, and columns, n,
    to the first line of input. Then it fills the maze with the maze from the file.
     */
    public static void setMaze(File file) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(file));
        Scanner scanner = new Scanner(file);

        //just to read two integers
        m = scanner.nextInt();
        n = scanner.nextInt();
        scanner.close();

        String line = br.readLine();
        System.out.println(m);
        System.out.println(n);
        char[][] array = new char[m][n];
        for (int i = 0; i < m; i++) {
            line = br.readLine();
            for (int j = 0; j < n; j++) {
                array[i][j] = line.charAt(j);
            }
        }
        maze = array;
    }

    /*
    TODO: isValid - checks if a position on the board has not been visited and is within bounds
     */
    public static boolean isValid(int x, int y) {
        if (x < 0 | y < 0 | y >= n | x >= m) {
            return false;
        }
        if ((maze[x][y] == '.') | (maze[x][y] == 'S') | (maze[x][y] == 'G')) {
            return true;
        }
        return false;
    }


    /*
    TODO: Using a stack, solve the maze WITHOUT recursion.
    Pseudo:
    1) Push start position onto Stack.
    2) While it's not empty;
        3) Pop from the stack to get the current considered location
        4) If it's already explored ignore
        5) If it's the goal, return true
        6) If it's not the goal, then explore it.
        7) You will need to compute all the possible neighbors. Then push those on the stack
    8) Return false
     */

    public static boolean solveMazeStack(int x, int y) throws EmptyStackE {
        //takes a prearranged list of potential moves, checks if they're valid and then adds them to the stack.
        //those moves are extracted from the stack and then their potential moves are evaluated, which are also added to the stack
        //eventually it will reach a "g" if its possible and return true.
        final Coord[] potentialmoves = new Coord[]{new Coord(-1, 0), new Coord(0, 1), new Coord(1, 0), new Coord(0, -1)};
        Stack stack = new Stack<>();
        //push the starting point
        stack.push(new Coord(x, y));
        try {
            while (stack.peek() != IndexOutOfBoundsException.class) {
                Coord spot = (Coord) stack.pop();
                if (maze[spot.getX()][spot.getY()] == 'G') {
                    return true;
                }
                //mark a path as visited.
                else if (maze[spot.getX()][spot.getY()] == '.') {
                    maze[spot.getX()][spot.getY()] = 'V';
                }
                //so we don't have to go through the arduous task of adding each point adjustment
                for (int i = 0; i < potentialmoves.length; i++) {
                    //this will cycle through each point in potential moves, and add them if they're valid moves to the stack!
                    int xcoord = spot.getX() + potentialmoves[i].getX();
                    int ycoord = spot.getY() + potentialmoves[i].getY();
                    if (isValid(xcoord, ycoord)) {
                        stack.push(new Coord(xcoord, ycoord));
                    }
                }
            }
        } catch (IndexOutOfBoundsException e) {
            return false;
        }
        return false;
    }

    // TODO: Using a queue, solve the maze. Be sure to explain your algorithm for full points.
    public static boolean solveMazeQueue(int x, int y) throws EmptyQueueE {
        //takes a prearranged list of potential moves, checks if they're valid and then adds them to the queue.
        //those moves are extracted from the queue and then their potential moves are evaluated, which are also added to the queue
        //eventually it will reach a "g" if its possible and return true.
        //this works in virtually the same way as solving with a stack.
        final Coord[] potentialmoves = new Coord[]{new Coord(-1, 0), new Coord(0, 1), new Coord(1, 0), new Coord(0, -1)};
        Queue queue = new Queue<>();
        //push the starting point
        queue.enqueue(new Coord(x, y));
        try {
            while (queue.peek() != IndexOutOfBoundsException.class) {
                Coord spot = (Coord) queue.dequeue();
                if (maze[spot.getX()][spot.getY()] == 'G') {
                    return true;
                }
                //mark a path as visited.
                if (maze[spot.getX()][spot.getY()] == '.') {
                    maze[spot.getX()][spot.getY()] = 'V';
                }
                //so we don't have to go through the arduous task of adding each point adjustment
                for (int i = 0; i < potentialmoves.length; i++) {
                    //this will cycle through each point in potential moves, and add them if they're valid moves to the stack!
                    int xcoord = spot.getX() + potentialmoves[i].getX();
                    int ycoord = spot.getY() + potentialmoves[i].getY();
                    if (isValid(xcoord, ycoord)) {
                        queue.enqueue(new Coord(xcoord, ycoord));
                    }
                }
            }
        } catch (IndexOutOfBoundsException e) {
            return false;
        }
        return false;
    }

    // TODO: Solve the board. Mode 1 = stack solving. Mode 2 = queue solving.
    // 1: stack
    // 2: queue
    public static boolean solve(String file, int mode) throws IOException, EmptyStackE, EmptyQueueE, EmptyListE {
        File file1 = new File(file);
        setMaze(file1);

        // find starting point
        int xstart = 0;
        int ystart = 0;
        for(int i = 0; i < maze.length; i++){
            for(int j = 0; j < maze[0].length; j++){
                if(maze[i][j] == 'S'){
                    xstart = i;
                    ystart = j;
                    break;
                }
            }
        }
        // check if the maze can be solved
        boolean solved = false;
        if(mode == 1){
            if(solveMazeStack(xstart,ystart)){
                return true;
            }
        }
        else if (mode == 2){
            if(solveMazeQueue(xstart,ystart)){
                return true;
            }
        }
        System.out.println("Maze can be solved: " + solved);
        return false;
    }
}