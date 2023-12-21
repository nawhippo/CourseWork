import java.lang.reflect.Array;
public class ArrayList<E extends Comparable> extends List<E> {
    private int size;
    private int capacity;
    private Object[] ls;
// TODO: default: should create an arraylist that is capable of holding 10
    public ArrayList() {
        Object[] myarray = new Object[10];
        this.capacity = 10;
        this.size = 0;
        this.ls = myarray;
    }
    // TODO: second constructor - should create an arraylist that is capable of
    public ArrayList(int capacity) {
        Object[] myarray = new Object[capacity];
        this.capacity = capacity;
        this.size = 0;
        this.ls = myarray;
    }
    public int size() {
        return this.size;
    }
    public E get(int index) throws IndexOutOfBoundsException {
        if ((index > size) || (index < 0)) {
            throw new IndexOutOfBoundsException();
        }
        return (E) this.ls[index];
    }
// TODO: insert --> takes some element and inserts it at the end of the arraylist, resizes to double capacity if no space
    public void add(E value) {
        if (capacity == size) {
            capacity = capacity * 2;
            Object[] newArray = new Object[capacity];
            //copy over old values
            for (int i = 0; i < size; i++) {
                newArray[i] = ls[i];
            }
            newArray[size] = value;
            ls = newArray;
        } else {
            //just add the value
            ls[size] = value;
        }
        size++;
    }
    // TODO: delete - deletes an element at said index; moves elements such that there are no gaps in between them
    public void delete(int index) throws IndexOutOfBoundsException {
        if (index >= size || index < 0) {
            throw new IndexOutOfBoundsException();
        }
        Object[] smallerarray = new Object[capacity];
        for (int i = 0; i < size; i++) {
            if (i < index) {
                smallerarray[i] = this.ls[i];
//start skipping values
            } else if (i >= index) {
                smallerarray[i] = this.ls[i + 1];
            }
        }
        this.ls = smallerarray;
        this.size--;
    }
// TODO: searches one by one to find the element, if it doesn't exist then return -1
    public int search(E value) {
        for (int i = 0; i < size; i++) {
            if (ls[i].equals(value)) {
                return i;
            }
        }
        return -1;
    }
// TODO: given some other arraylist, compare it to see if it has the same contents
public boolean equals(Object o) {
    if (o instanceof ArrayList<?>) {
        ArrayList<?> comp = (ArrayList<?>) o;
        if (this.size != comp.size) {
            return false;
        }
        for (int i = 0; i < size; i++) {
            Object elem1 = ls[i];
            Object elem2 = comp.ls[i];
            if (elem1 == null && elem2 == null) {
                continue;
            }
            if (elem1 == null || elem2 == null) {
                return false;
            }
            if (!elem1.equals(elem2)) {
                return false;
            }
        }
        return true;
    }
    return false;
}


    // to help you
    public String toString() {
        String ret = "";
        for (int i = 0; i < this.size; i++) {
            ret += i + ": " + this.ls[i] + "\n";
        }
        return ret;
    }
}