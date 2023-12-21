import java.util.LinkedList;

public class Node implements Comparable<Node>{
    private final int name;
    private LinkedList<Edge> edgeList;
    private int value;
    private Node prev;

    // TODO: set up prev, edgeList, and the value
    //just the name
    public Node(int name) {
        this.name = name;
        this.edgeList = new LinkedList<>();
        this.value = 0;
        this.prev = null;
    }

    //w/ all parameters
    public Node(int name, LinkedList<Edge> edgeList, int value, Node prev) {
        this.name = name;
        this.edgeList = edgeList;
        this.value = value;
        this.prev = prev;
    }


    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Node n = (Node) o;
        return n.getValue() == this.value &&
                this.name == n.name;
    }

    @Override
    public int compareTo(Node o) {
        return Integer.compare(this.value, o.getValue());
    }

    public void setValue(int val){
        this.value = val;
    }

    public void setPrev(Node prev){
        this.prev = prev;
    }

    public Node getPrev(){
        return this.prev;
    }

    public int getValue(){
        return value;
    }

    public int getName() {
        return name;
    }

    public LinkedList <Edge> getEdges() {
        return edgeList;
    }

    public String toString(){
        return name + " " + value;
    }

}
