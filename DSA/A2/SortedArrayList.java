import com.sun.jdi.Value;
import java.lang.reflect.Array;
public class SortedArrayList<E extends Comparable> extends List<E> {
    private int size;
    private int capacity;
    private Object[] ls;
// TODO: default: should create a sortedarraylist that is capable of holding 10 element
    public SortedArrayList(){
        Object[] myarray = new Object[10];
        this.capacity = 10;
        this.size = 0;
        this.ls = myarray;
    }
    // TODO: second constructor - should create a sortedarraylist that is capable of holding x element that size
    public SortedArrayList(Class<E> c, int capacity){
        Object[] myarray = new Object[capacity];
        this.capacity = 10;
        this.size = 0;
        this.ls = myarray;
    }
    public int size(){
        return this.size;
    }
    public E get(int index) throws IndexOutOfBoundsException{
        if(index >= this.size){
            throw new IndexOutOfBoundsException();
        }
        return (E) this.ls[index];
    }

    public void add(E value) {
        if (size == capacity) {
            //If the array is full, resize it to double its current capacity and copy all values
            capacity = capacity*2;
            Object[] newlist = new Object[capacity];
            System.arraycopy(ls, 0, newlist, 0, size);
            ls = newlist;
        }
        int i = 0;
        // Find the index at which to insert the new element
        while (i < size && ((E)ls[i]).compareTo(value) < 0) {
            i++;
        }
        // Shift all elements after the insertion point to the right
        for (int p = size - 1; p >= i; p--) {
            ls[p+1] = ls[p];
        }
        // Insert the new element at the insertion point
        ls[i] = value;
        size++;
    }







    //Should function the same way as normal array list
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
            ls = smallerarray;
            size--;
        }
    public int search(E value) {
        int start = 0;
        int end = size - 1;
        while (start <= end) {
            int mid = (start + end)/2;
            int cmp = ((Comparable<E>) ls[mid]).compareTo(value);
            if (cmp == 0) {
                return mid;
            } else if (cmp < 0) {
                start = mid+1;
            } else {
                end = mid -1;
            }
        }
        return -1;
    }

    //should only need one loop o(n)
    //Should work
    public boolean equals(Object o) {
    if(o == this){
        return true;
    }
    //not a sorted list
    if(!(o instanceof SortedArrayList<?>)) {
        return false;
    }
    SortedArrayList<?> other = (SortedArrayList<?>) o;
    //unequal size would denote false
    if(size != other.size()){
        return false;
    }
    //difference
    for(int i = 0; i < size; i++){
        if(!ls[i].equals(other.get(i))){
            return false;
        }
    }
    return true;
    }







    // helper
    public String toString(){
        String ret = "";
        for(int i = 0; i < this.capacity; i++){
            ret += i + ": "+ this.ls[i] + "\n";
        }
        return ret;
    }
}