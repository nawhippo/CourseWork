import java.util.*;

public class Graph {
    private List<Node> nodes;

    public Graph() {
        nodes = new ArrayList<>();
    }

    public Graph(List<Node> nodes) {
        this.nodes = nodes;
    }

    // TODO: Initialize the nodes
    public void init(int n) {
        for (int i = 0; i < n; i++) {
            nodes.add(new Node(i));
        }
    }

    // TODO: not tested for credit technically but this method should reset your node's value
    public void reset() {
        //just initialize again.
        int n = nodes.size();
        nodes = new ArrayList<>();
        init(n);
    }

    // TODO:
    public void addEdge(Node src, Node dest, int weight) {
        //add to the nodes edgelist
        src.getEdges().add(new Edge(dest, weight));
    }

    // TODO: remove the edge from the Node
    public void removeEdge(Node src, Node dest) {
        //remove from nodes edge list
        if(nodes.get(src.getName()).getEdges().contains(dest)){
            nodes.get(src.getName()).getEdges().remove(dest);
        }
    }

    // TODO: Return the shortest path from start to dest with the correct cost of the nodes; return null if no path possible
    //pseudo-dijkstra's
    public List<Node> shortestPath(int start, int dest) {
        Node source = nodes.get(start);
        Node target = nodes.get(dest);

        //same location
        if(source == target){
            return Arrays.asList(source);
        }

        //initialize all nodes to have infinite distance and no previous node
        for (Node n : nodes) {
            n.setValue(Integer.MAX_VALUE);
            n.setPrev(null);
        }

        //set the distance of the source node to 0
        source.setValue(0);

        //create a priority queue and add all nodes to it
        //use comparator of size instead of name... to avoid it being just natural order
        PriorityQueue<Node> queue = new PriorityQueue<Node>(nodes.size(), new Comparator<Node>() {
            public int compare(Node n1, Node n2) {
                return Integer.compare(n1.getValue(), n2.getValue());
            }
        });


        //enqueue all nodes
        for (Node n : nodes) {
            queue.add(n);
        }

        //Run the algorithm
        while (!queue.isEmpty()) {
            Node curr = queue.poll();
            //if destination is reached
            if (curr == target) {
                break;
            }

            //iterate through each of the edges in our current node
            for (Edge edge : curr.getEdges()) {
                Node destvert = edge.getDestVertex();
                if (queue.contains(destvert)) {
                    //alt is the combined cost
                    int alt = curr.getValue()+edge.getWeight();
                    if (alt < destvert.getValue()) {
                        //this new value is the traversal path's cost included
                        destvert.setValue(alt);
                        destvert.setPrev(curr);
                        //update the priority of the node in the queue
                        queue.remove(destvert);
                        queue.add(destvert);
                    }
                }
            }
        }

        //traverse backwards construct/return the shortest path, if it exists
        if (target.getPrev() != null || target == source) {
            List<Node> path = new ArrayList<Node>();
            for (Node node = target; node !=null; node = node.getPrev()) {
                path.add(node);
            }
            Collections.reverse(path);
            //if the shortest path is one edge, ie: the problem solves itself..
            if(path.size() == 2 && source.getEdges().contains(new Edge(target, path.get(1).getValue()))){
                return Arrays.asList(source,target);
            } else {
                return path;
            }
        } else {
            return null;
        }
    }
    }
