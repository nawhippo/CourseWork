import java.security.Key;
import java.util.Map;

import static java.lang.Math.*;

public class HashTableOpenAddressing<K, V> extends Dictionary<K, V> {
    public int getCapacity() {
        return capacity;
    }

    private int capacity;  // size of the table
    private int size;  // number of elements in the table
    private int previousPrime; //store prev prime so that it is not calculated again and again in double hashing.
    private int mode;

    public static int LINEARPROBING = 1;
    public static int QUADRATICPROBING = 2;
    public static int DOUBLEHASHING = 3;
    private double loadFactor;
    private Entry<K, V>[] table;

    public HashTableOpenAddressing() {
        this(DOUBLEHASHING, 11, 0.75);  // default initial capacity of 11
    }

    public HashTableOpenAddressing(int mode) {
        this(mode, 11, 0.75);
    }

    public HashTableOpenAddressing(int capacity, double loadFactor) {
        this(LINEARPROBING, capacity, loadFactor);
    }

    /*
    TODO:
    This constructor takes a mode, capacity, loadFactor, and sets those variables + relevant variables
    according to such. Additionally, it will set up the table according to the capacity.
    If the mode is DOUBLEHASHING, please calculate the previousPrime and set it.
     */
    public HashTableOpenAddressing(int mode, int capacity, double loadFactor) {
        if (mode == DOUBLEHASHING) {
            this.capacity = previousPrime(capacity);
        } else this.capacity = capacity;
        this.mode = mode;
        if (loadFactor > 1) {
            System.out.println("invalid loadfactor: defaulting to 1");
            this.loadFactor = 1;
        } else {
            this.loadFactor = loadFactor;
        }
        this.table = new Entry[capacity];
    }

    private int previousPrime(int number) {
        while (true) {
            if (isPrime(number)) {
                return number;
            }
            number--;
        }
    }


    // TODO:
    //  second hash should be prevPrime - (key % prevPrime)...shouldn't be negative
    private int hash2(K key) {
        int prevPrime = previousPrime(capacity - 1);
        int result = (prevPrime - (hash(key) % prevPrime)) % capacity;
        return Math.abs(result);
    }





    // TODO: gets the next index given the index and the offset. Please take into account the mode.
    private int getNextIndex(K key, int offset) {
        int ind = hash(key);
        if (mode == LINEARPROBING) {
            //simply add the offset number
            return Math.abs((ind + offset) % capacity);
        } else if (mode == DOUBLEHASHING) {
            int secondhash = hash2(key);
            //add the offset * the result of our second hash.
            return Math.abs((ind + offset * secondhash) % capacity);
        } else if (mode == QUADRATICPROBING) {
            //add the square of the offset
            return Math.abs((ind + offset * offset) % capacity);
        }
        return offset;
    }

    // TODO:
    //  Put a key, value pair into the table.
    //  If the key already exists/inactive, override it. Else, put it into the table.
    //  Throw a RuntimeException if there is an infinite loops.

    public void put(K key, V value) throws RuntimeException {
        if (size >= capacity * loadFactor) {
            resize();
        }

        int index = hash(key);
        int offset = 0;
        int insertionIndex = -1;

        while (table[index] != null && offset < capacity) {
            if (table[index].getKey().equals(key)) {
                if (!table[index].isActive && insertionIndex == -1) {
                    insertionIndex = index;
                }

                if (table[index].isActive) {
                    table[index].setValue(value);
                    return;
                }
            }

            offset++;
            index = getNextIndex(key, offset);
        }

        if (insertionIndex != -1) {
            table[insertionIndex].key = key;
            table[insertionIndex].value = value;
            table[insertionIndex].isActive = true;
        } else {
            table[index] = new Entry<>(key, value);
        }

        size++;

        if (offset == capacity) {
            throw new RuntimeException("Infinite loop detected while trying to insert key: " + key);
        }
    }

    // TODO:
    //  Retrieves the value of a key in the table.
    //  If there is an infinite loop, throw a RuntimeException.
    //  Return null if not there.
    public V get(K key) throws RuntimeException {
        if(this.isEmpty() || this.containsKey(key) == false){
            return null;
        }
        int index = hash(key);
        int offset = 0;
        //the condition wherein the index is null, or we've gone through the whole list and haven't gotten our key.
        while (table[index] != null && offset < capacity) {
            if (table[index].getKey().equals(key)) {
                if (table[index] == null || !table[index].isActive) {
                    return null;
                }
                return table[index].getValue();
            }

            offset++;
            index = getNextIndex(key, offset);
        }
        //looped through every possible term and couldn't find it.
        //if((this.mode == LINEARPROBING) || (this.mode == QUADRATICPROBING)){
            return null;
        //}
        //throw new RuntimeException("Infinite loop detected w/ key: " + key);
    }

    // TODO: Searches the table to see if the key exists or not.
    public boolean containsKey(K key) {
        int index = hash(key);
        int offset = 0;
        //if we haven't found the index equal to null, or we haven't looped around the entire list
        while (table[index] != null && (offset < capacity)) {
            //found
            if (table[index].getKey().equals(key)) {
                if (table[index].isActive) {
                    return true;
                } else {
                    return false;
                }
            }
            offset++;
            index = getNextIndex(key, offset);
        }
        return false;
    }

    // TODO:
    //  Set the key as inactive if it exists in the table. Return true.
    //  If there is no key, return false.
    //  If there's an infinite loop, throw a RuntimeException.
    public boolean remove(K key) {
        int index = hash(key);
        int offset = 0;

        while (table[index] != null && offset < capacity) {
            if (table[index].getKey().equals(key)) {
                if (table[index].isActive) {
                    table[index].setActive(false);
                    size--;
                    return true;
                } else {
                    return false;
                }
            }
            offset++;
            index = getNextIndex(key, offset);
        }

        if (offset == capacity) {
            throw new RuntimeException("Infinite loop detected while trying to remove key: " + key);
        }

        return false;
    }


    public int size() {
        return size;
    }

    public boolean isEmpty() {
        if (size == 0) {
            return true;
        }
        return false;
    }

    // TODO:
    //  Calculate the absolute hash of the key. Do not overthink this.
    private int hash(K key) {
        return Math.abs(key.hashCode() % capacity);
    }


    private boolean isPrime(int number) {
        for (int i = 2; i <= number / 2; i++) {
            if (number % i == 0) {
                return false;
            }
        }
        return true;
    }

    private int nextPrime(int number) {
        while (true) {
            if (isPrime(number)) {
                return number;
            }
            number++;
        }
    }

    // TODO:
    //  Set the capacity to the nextPrime of the capacity doubled.
    //  Calculate the previousPrime and set up the new table with the old tables'
    //  contents now hashed to the new.
    private void resize() {
        int newCapacity = nextPrime(capacity * 2);

        if (mode == DOUBLEHASHING) {
            previousPrime = previousPrime(newCapacity - 1);
        }

        Entry<K, V>[] oldTable = table;
        capacity = newCapacity;
        table = new Entry[capacity];
        size = 0;

        //copy all active entries to the new table.
        for (Entry<K, V> entry : oldTable) {
            if (entry != null && entry.getActive()) {
                put(entry.getKey(), entry.getValue());
            }
        }
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("{");
        int index = 0;

        for (Entry<K, V> entry : table) {
            sb.append(index + ": ");
            index++;
            if (entry != null) {
                sb.append(entry.getKey() + "=" + entry.getValue() + ",");
            }
            sb.append(";");
        }

        if (sb.length() > 1) {
            sb.setLength(sb.length() - 2);
        }
        sb.append("}");
        return sb.toString();
    }

    private class Entry<K, V> {
        private K key;
        private V value;

        private boolean isActive;

        public Entry(K key, V value) {
            this.key = key;
            this.value = value;
            isActive = true;
        }

        public K getKey() {
            return key;
        }

        public V getValue() {
            return value;
        }

        public void setValue(V value) {
            this.value = value;
        }

        public boolean getActive() {
            return isActive;
        }

        public void setActive(boolean active) {
            isActive = active;
        }
    }

    public static void main(String[] args) {
    }

}
