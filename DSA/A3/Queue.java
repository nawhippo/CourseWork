class EmptyQueueE extends Exception{}

public class Queue<E> {
    private DoublyLinkedList<E> q;
    private int size;

    // TODO: default constructor
    public Queue(){
    q = new DoublyLinkedList<>();
    size = 0;
    }

    // TODO: Put element at end of queue
    //end of queue is head.
    public void enqueue(E elem){
        size++;
    q.insertAtHead(elem);
    }

    // TODO: Return the head of the queue; If there's nothing to return then throw EmptyQueueE
    //the last would be the first inserted, because a queue is fifo
    public E dequeue() throws EmptyQueueE {
        E temp = null;
        try {
            temp = this.q.deleteAtTail();
            size--;
        } catch (EmptyListE e) {
            throw new EmptyQueueE();
        }
        return temp;
    }
    // TODO: Without affecting the queue, return the element at the top of the queue
    public E peek() throws IndexOutOfBoundsException{
            if(q.get(size-1) == null){
                throw new IndexOutOfBoundsException("Can't peek from an empty stack");
            }
            else return q.get(size-1);
        }


    public int size() {
        return this.size;
    }

    // TODO: Checks if inputted is the same Queue
    public boolean equals(Object o) {
        if(o instanceof Queue<?>){
            Queue queue = (Queue) o;
            if(this.q.equals(queue.q)){
            return true;
            }
        }
        return false;
    }

    public String toString(){
        return "" + q.size();
    }
}
