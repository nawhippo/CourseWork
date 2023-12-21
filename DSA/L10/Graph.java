import java.util.*;

public class Graph {

    private List<Node> nodes; // List of all nodes in a graph
    private boolean[][] adjacencyMatrix; // directional adjacency matrix that has adjacencyMatrix[v][w] = true if v is connected to w

    public Graph(List<Node> nodes, boolean[][] adjacencyMatrix){
        this.nodes = nodes;
        this.adjacencyMatrix = adjacencyMatrix;
    }


    /** CONNECTED
     *
     * This method is a very simple graph traversal problem.
     *
     * Using the traversal algorithm of your choosing, (BFS/DFS recommended)
     * Traverse the graph starting from a node v until you find a node w.
     * Once found, return the path from v to w.
     *
     * This path does not need to be the shortest nor the most efficient,
     * simply a path. You will have difference outputs depending on which
     * traversal you use.
     *
     * Use the helper method getPath() to retrieve the path once you have
     * found w.
     *
     * @param v starting node
     * @param w ending node
     * @return Arraylist path from v to w
     */
    public ArrayList<Node> connected(Node v, Node w){
    Stack<Node> stack = new Stack();
    ArrayList<Node> result = new ArrayList<Node>();
    pathfinderhelper(stack,v,w);
    //add values from the stack
        while(!stack.isEmpty()){
            //put it at the beginning of the arraylist sequentially so it returns from the beginning to the end;
              result.add(0,stack.pop());
            }
    return result;
    }

    public ArrayList<Node> pathfinderhelper(Stack<Node> stack, Node currnode, Node end) {
        //mark current node as visited
        currnode.setVisited();
        //add current node to the stack
        stack.push(currnode);

        if (currnode == end) {
            //if current node is the end node, return the path
            ArrayList<Node> path = new ArrayList<>();
            Node node = stack.pop();
            while (node != null) {
                path.add(node);
                //go backwards from the end
                node = node.getPath();
            }
            return path;
        }



        //explore neighbors
        int ind = currnode.getName();
        for (int i = 0; i < nodes.size(); i++) {
            //if there is an adjacency detected and it hasn't been visited
            if (adjacencyMatrix[ind][i] && nodes.get(i).isNotVisited()) {
                Node neighbor = nodes.get(i);
                //set the path field of the neighbor node
                neighbor.setPath(currnode);
                ArrayList<Node> path = pathfinderhelper(stack, neighbor, end);  // explore the neighbor
                if (path != null) {
                    return path;
                }
            }
        }

        //backtrack by removing the current node from the stack
        stack.pop();
        //reset the path field of the current node
        currnode.setPath(null);
        //no path found
        return null;
    }

    /** GETPATH
     *
     * Each node has a path variable that stores a node. This node is
     * the previous node in the path. If the path variable is equal to
     * null that means that it is the origin node in the path.
     *
     * Recursively add those nodes to an arraylist and then return
     * that arraylist once you encounter a null path variable to retrieve
     * the entire path.
     *
     * If no path exists, simply return an arraylist only containing
     * the given node.
     *
     * @param node ending node in the path
     * @return ordered arraylist that is a path from the
     *          origin node to the specified node.
     */
    public ArrayList<Node> getPath(Node node) {
        //TODO
        ArrayList<Node> path = new ArrayList<>();
        if(node.getPath() == null){
            path.add(node);
            return path;
        }
        //stopping condition
        if (node == null){
        } else {
            //add nodes to the path recursively, until origin
            path.addAll(getPath(node.getPath()));
            //to the beginning of the path
            path.add(0,node);
        }
        return path;
    }


}
