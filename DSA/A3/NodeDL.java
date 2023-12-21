public class NodeDL<E> {
    E data;
    NodeDL<E> prev;
    NodeDL<E> next;

    public NodeDL(E elem) {
        this.data = elem;
    }

    public String toString() {
        return "" + this.data;
    }

    // TODO: Return whether the other has same type and same pointers
    public boolean equals(Object o){
        //same type
        if(o instanceof NodeDL<?>){
            NodeDL nodeDL = (NodeDL) o;
            //same pointers..
            if((nodeDL.prev == this.prev) & (nodeDL.next == this.next)){
                return true;
            }
        }
        return false;
    }
}
