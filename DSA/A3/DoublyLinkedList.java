import org.w3c.dom.Node;

class EmptyListE extends Exception{}

public class DoublyLinkedList<E> {

    private NodeDL<E> head;
    private NodeDL<E> tail;
    private int size;

    // TODO: default constructor
    public DoublyLinkedList() {
        this.head = null;
        this.tail = null;
        size = 0;
    }

    // TODO: secondary constructor
    public DoublyLinkedList(NodeDL<E> head, NodeDL<E> tail) {

        this.head = head;
        this.tail = tail;
        NodeDL temp = head;
        //count the first node
        int tempsize = 1;
        while(temp != tail){
            tempsize++;
            temp = temp.next;
        }
        size = tempsize;
        if(head == tail){
            this.size = 1;
        }
    }

    public int size() {
        return this.size;
    }

    // TODO: Insert elem at the start of the DoublyLinkedList
    void insertAtHead(E elem) {
       size++;
       NodeDL nodeDL = new NodeDL<>(elem);
       if(head == null){
           head = nodeDL;
           tail = nodeDL;
           return;
       }
       nodeDL.next = head;
       if(head != null){
          head.prev = nodeDL;
       }
       head = nodeDL;
    }


    // TODO: Insert elem at the end of the DoublyLinkedList
 void insertAtTail(E elem) {
        NodeDL nodeDL = new NodeDL(elem);
        size++;
        if (head == null){
            head = nodeDL;
            tail = nodeDL;
            return;
        }
        tail.next = nodeDL;
        tail = nodeDL;
    }

    // TODO: Delete the element from the start of the DoublyLinkedList. Throw an EmptyListE if there's nothing to delete
    E deleteAtHead() throws EmptyListE {
        E temp;
        if (head == null) {
            throw new EmptyListE();
        } else {
            temp = head.data;
            head = head.next;
            if(head != null){
                head.prev = null;
            }
        }
        size--;
        return temp;
    }


    // TODO: Delete the element from the end of the DoublyLinkedList. Throw an EmptyListE if there's nothing to delete
    E deleteAtTail() throws EmptyListE {
        //if head is defined, tail ought to be defined
        if(head == null){
            throw  new EmptyListE();
        }
        E temp = tail.data;
        size--;
        //if there is only one element
        if(head == tail){
            head = null;
            tail = null;
            return temp;
        }
        else {
            tail = tail.prev;
            tail.next = null;
        }
        return temp;
        }

    // TODO: Get the element at some position. If it's not possible, throw an IndexOutOfBoundsException
    E get(int index) throws IndexOutOfBoundsException {
        if((head == null) | (index >= size) | (index < 0)){
            throw new IndexOutOfBoundsException();
        }
        int count = 0;
        NodeDL temp = head;
        while (count != index) {
            temp = temp.next;
            count++;
        }
        return (E) temp.data;
    }

    // TODO: Search the DoublyLinkedList for elem. If not found, return -1;
    public int search(E elem) {
        NodeDL temp = head;
        int count = 0;
        while (count < size)
    {   if(temp.data == elem){
        return (int)temp.data;
    }
        temp = temp.next;
        count++;
    }
        return -1;
}
    // TODO: When passed some object, return true if it's a DoublyLinkedList, has the same elements in the same order.
    public boolean equals(Object o){
        NodeDL temp = head;
        int count = 0;
        if(o instanceof DoublyLinkedList<?>){
            DoublyLinkedList tempdl = (DoublyLinkedList) o;
            //in the case that they're different sizes.
            if(tempdl.size != this.size){
                return false;
            }
            NodeDL temp2 = ((DoublyLinkedList<?>) o).head;
            while(count < size){
                if(temp.data != temp2.data){
                    return false;
                }
                temp = temp.next;
                temp2 = temp2.next;
                count++;
            }
        } else {
            return false;
        }
        return true;
    }

    public String toString(){
        String ret = "";
        NodeDL<E> temp = head;
        for(int i = 0; i < size; i++){
            ret += temp.data + " ";
            temp = temp.next;
        }
        return ret;
    }
}
