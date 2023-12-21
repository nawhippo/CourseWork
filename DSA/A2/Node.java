
public class Node implements Comparable {
    private String keyword;
    private List<String> references;
    // TODO: given some keyword, and mode (1 = arraylist 2 = sorted arraylist) set up the Node
    public Node(String keyword, int mode){
        this.keyword = keyword;
        if(mode==1){
            this.references = new ArrayList();
        } else if(mode==2){
            this.references = new SortedArrayList();
        }
    }
    public String getKeyword(){
        return this.keyword;
    }
    public List getReferences(){
        return this.references;
    }
    public void insertReference(String website){
        this.references.add(website);
    }
    // TODO: Compare some other Node to this Node, String compareTo is your bestfriend here; return -1 if the other object of comparison isn't a Node
    public int compareTo(Object o) {
        if (o instanceof Node) {
            Node comp = (Node) o;
            int cmp = this.keyword.compareTo(comp.keyword);
            if (cmp != 0) {
                return cmp;
            }
            int size1 = this.references.size();
            int size2 = comp.references.size();
            int minSize = Math.min(size1, size2);
            for (int i = 0; i < minSize; i++) {
                cmp = this.references.get(i).compareTo(comp.references.get(i));
                if (cmp != 0) {
                    return cmp;
                }
            }
            if (size1 < size2) {
                return -1;
            } else if (size1 > size2) {
                return 1;
            } else {
                return 0;
            }
        }
        return -1;
    }
    
    // TODO: similar to compareTo except in boolean format and is only concerned if the other Node has the same keyword or not
    public boolean equals (Object o) {
        if (o instanceof Node) {
//downcast
            Node compnode = (Node)o;
            if(this.keyword.equals(compnode.keyword)){
                return true;
            }
        }
        return false;
    }
    public String toString(){
        return this.keyword + " " + this.references;
    }
}
