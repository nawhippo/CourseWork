class EmptyStackE extends Exception{}

public class Stack<E>{
    private DoublyLinkedList<E> st;
    private int size;

    // TODO: default constructor
    public Stack(){
    size = 0;
    this.st = new DoublyLinkedList<>();
    }

    // TODO: Push the element to the top of stack
    public void push(E elem){
    st.insertAtHead(elem);
    size++;
    }

    // TODO: Pop the element off the top of the stack. If nothing to pop, throw EmptyStackE
    //tail is the oldest object in the stack, so we delete the head.
    //lifo
    public E pop() throws EmptyStackE {
        E temp = null;
        try {
            temp = this.st.deleteAtHead();
            size--;
        } catch (EmptyListE e) {
            throw new EmptyStackE();
        } catch (NullPointerException e){
            throw new EmptyStackE();
        }
        return temp;
    }

    // TODO: Without affecting the stack, return the element at the top of the stack
    public E peek(){
        if(st.get(0) == null){
            throw new IndexOutOfBoundsException("Can't peek from an empty stack");
        }
        else return st.get(0);
        }

    public int size() {
        return this.size;
    }

    // TODO: Check if some other object is the same Stack
    public boolean equals(Object o){
        if(o instanceof Stack<?>){
            Stack stack = (Stack) o;
            if(this.st.equals(stack.st)){
                return true;
            }
        }
        return false;
    }

    public String toString(){
        return st.toString();
    }
}
