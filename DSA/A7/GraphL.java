import java.lang.reflect.Array;
import java.util.*;

class CycleDetected extends Exception{};

public class GraphL implements Graph {
    // An Array of nodes where each item points to a list of adjacent nodes
    private List<Node>[] nodeArray;
    // A List of nodes that will be referenced in the nodeArray
    private List<Node> nodes;
    // Number of edges in the graph
    private int numEdge;

    public GraphL(int n){
        this.nodes = new ArrayList<>();
        init(n);
    }

    // TODO:
    public GraphL(List<Node>[] nodeArray, List<Node> nodes){
        this.nodeArray = nodeArray;
        this.nodes = nodes;
    }

    // Implement the missing functions here:
    // TODO:
    public void init(int n) {
        List<Node>[] nodeArray = new ArrayList[n * 100];
        for(int i = 0; i < nodeArray.length; i++){
            nodeArray[i] = new ArrayList<>();
        }
        for(int i = 0; i < n; i++){
            Node node = new Node(i);
            nodes.add(node);
        }
        this.nodeArray = nodeArray;
    }

    // Hint: may need a reset function for the Runner class (not in the Interface)
    public void reset(){
        //set all nodes as unvisited, presumably every time after a sort is ran
        for(int i = 0; i < nodes.size(); i++){
            nodes.get(i).setUnvisited();
        }
    }

    // TODO:
    public int nodeCount() {
        return nodes.size();
    }

    // TODO:
    public int edgeCount() {
        //count every edge everywhere
        int count = 0;
        //check each node's adjacency list
        for(int i = 0; i < nodeArray.length; i++){
            if (!nodeArray[i].isEmpty()){
                for(int p = 0; p < nodeArray[i].size(); p++){
                    //if its in the adjacency list, it represents an edge.
                    count++;
                }
            }
        }
        //update the number of edges, so we can retrieve this info without loops
        numEdge = count;
        return count;
    }

    // TODO:
    public void addEdge(int v, int w) {
        Node node1 = null;
        Node node2 = null;
        //Find the nodes with values v and w in the list
        for (Node node : nodes) {
            if (node.getName() == v) {
                node1 = node;
            } else if (node.getName() == w) {
                node2 = node;
            }
        }

        //If either node is not found, create a new node and add it to the list
        if (node1 == null) {
            node1 = new Node(v);
            nodes.add(node1);
        }
        if (node2 == null) {
            node2 = new Node(w);
            nodes.add(node2);
        }

        //Add to the adjacency list of the first node, a 1 way connection
        nodeArray[node1.getName()].add(node2);
    }

    // TODO:
    public void removeEdge(int v, int w) {
        Node node1 = null;
        Node node2 = null;
        //Find the nodes with values v and w in the list
        for (Node node : nodes) {
            if (node.getName() == v) {
                node1 = node;
            } else if (node.getName() == w) {
                node2 = node;
            }
        }

        //If either node is not found, return
        if ((node1 == null) || (node2 == null)) return;
        //remove node1's connection to node 2, through the adjacency list
        nodeArray[node1.getName()].remove(node2);
    }


    // TODO:
    public boolean hasEdge(int v, int w) {
        Node node1 = null;
        Node node2 = null;
        //Find the nodes with values v and w in the list, and their indices in the nodeArray
                for (Node node : nodes) {
                    if (node.getName() ==  v) {
                        node1 = node;
                    } else if (node.getName() == w) {
                        node2 = node;
                    }
                }

        //check if there is an edge between the nodes with an and condition
        return nodeArray[node1.getName()].contains(nodes.get(node2.getName()));
    }

    // TODO:
    public List<Node> neighbors(int v) {
        //return adjacency list of an index.
        //assuming that is maps to a node's index
        for (int i = 0; i < nodes.size(); i++) {
            if (nodes.get(i).getName() == v) {
                return nodeArray[i];
            }
        }
        return Collections.emptyList();
    }
    // TODO: Implement topological sort with stack.
    /*
    Potential way to implement:
    1. For each node in the nodes, you can perform DFS
     */
    // Hint: think of how you can use the value of the Node (not the name)
    public List<Node> topologicalSortStack() throws CycleDetected {
        Stack<Node> stack = new Stack<>();
        List<Node> sortedNodes = new ArrayList<>();
        //to prevent duplicates
        List<Node> addedToStack = new ArrayList<>();
        List<Node> visitedNodes = new ArrayList<>();
        for(int i = 0; i <  nodes.size(); i++){
            Node node = nodes.get(i);
            if (!node.getVisited()) {
                topologicalSortStackHelper(node, stack,addedToStack, visitedNodes);
            }
        }
        while (!stack.isEmpty()) {
            sortedNodes.add(stack.pop());
        }
        return sortedNodes;
    }

    public void topologicalSortStackHelper(Node node, Stack<Node> stack, List<Node> addedtoStack, List<Node> visitedNodes) throws CycleDetected {
        if (addedtoStack.contains(node)) {
            //cycle detected
            throw new CycleDetected();
        }
        //sort through the neighbors
        //if it isn't in the visited nodes list.
        if (!visitedNodes.contains(node)) {
            //add it to the current stack list and visited list
            visitedNodes.add(node);
            addedtoStack.add(node);
            //recursive call the neighbors
            for (Node neighbor : neighbors(nodes.indexOf(node))) {
                topologicalSortStackHelper(neighbor, stack, addedtoStack, visitedNodes);
            }
            //remove it from the pushed to stack list
            addedtoStack.remove(node);
            //push it to the actual stack
            stack.push(node);
        }
    }


    // TODO: Implement topological sort with queue.
    /*
    Potential way to implement:
    1. Go through the edges and set the value of the node to the number of incoming edges and unvisited.
    2. Push nodes that have 0 incoming edges into the queue.
    3. Implement BFS
        -Everytime you process a node, decrease it's value.
     */

    @Override
    public List<Node> topologicalSortQueue() throws CycleDetected {
        List<Node> sortedNodes = new ArrayList<>();
        Queue<Node> queue = new LinkedList<>();

        //set the value of the node to the number of incoming edges and unvisited
        int[] incomingEdges = new int[nodes.size()];
        for (int i = 0; i < nodes.size(); i++) {
            List<Node> neighbors = nodeArray[i];
            for (Node neighbor : neighbors) {
                //count the neighbors
                incomingEdges[nodes.indexOf(neighbor)]++;
            }
        }

        //enqueue those with 0 incoming edges
        for (int i = 0; i < nodes.size(); i++) {
            if (incomingEdges[i] == 0) {
                queue.offer(nodes.get(i));
            }
        }

        //do bfs
        while (!queue.isEmpty()) {
            //node becomes head of queue
            Node node = queue.poll();
            //add the starting node to sorted nodes
            sortedNodes.add(node);

            //search through the neighbors of the starting node, much like the stack queue sort.
            for (Node neighbor : nodeArray[nodes.indexOf(node)]) {
                int index = nodes.indexOf(neighbor);
                incomingEdges[index]--;
                if (incomingEdges[index] == 0) {
                    //send it to the end of the queue
                    queue.offer(neighbor);
                }
            }
        }

        //if there are still nodes with incoming edges, then there must be a cycle
        for (int i = 0; i < nodes.size(); i++) {
            if (incomingEdges[i] != 0) {
                 throw new CycleDetected();
            }
        }

        return sortedNodes;
    }
}