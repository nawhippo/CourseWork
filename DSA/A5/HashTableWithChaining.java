import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

public class HashTableWithChaining<K, V> extends Dictionary<K, V> {

    private int capacity;  // size of the table
    private int size;  // number of elements in the table

    private double loadFactor;
    private List<LinkedList<Entry<K, V>>> table;  // hash table

    // Entry class to hold key-value pairs
    private class Entry<K, V> {
        private K key;
        private V value;

        public Entry(K key, V value) {
            this.key = key;
            this.value = value;
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
    }

    public HashTableWithChaining() {
        this.capacity = 11;
        this.loadFactor = 0.75;
        this.size = 0;
        this.table = new ArrayList<>(capacity);
        //initialize all the linked lists
        for (int i = 0; i < capacity; i++) {
            table.add(new LinkedList<>());
        }
    }

    public HashTableWithChaining(int capacity) {
        this.capacity = capacity;
        this.loadFactor = 0.75;
        this.size = 0;
        this.table = new ArrayList<>(capacity);
        //initialize all the linked lists
        for (int i = 0; i < capacity; i++) {
            table.add(new LinkedList<>());
        }
    }

    /*
    TODO:
    This constructor takes a capacity and loadFactor, and sets those variables + relevant variables
    according to such. Additionally, it will set up the table according to the capacity.
     */
    public HashTableWithChaining(int capacity, double loadFactor) {
        this.capacity = capacity;
        this.loadFactor = loadFactor;
        this.size = 0;
        this.table = new ArrayList<>(capacity);
        //initialize all the linked lists
        for (int i = 0; i < capacity; i++) {
            table.add(new LinkedList<>());
        }
    }

    // TODO:
    //  Put a key, value pair into the table.
    //  If the key already exists, update it with the new value.
    //  If there is no key at that index, add it into the table.
    //  Resize when the size is > the loadFactor * capacity.
    //  Remember that multiple keys can exist at the same index.
    public void put(K key, V value) {
        int hash = hash(key);
        //returns the arraylist at that specific index
        LinkedList<Entry<K, V>> temp = table.get(hash);

        //if key exists, sets every value at that index to this one.
        for (Entry<K, V> entry : temp) {
            if (entry.getKey().equals(key)) {
                entry.setValue(value);
                return;
            }
        }
        //else make a new entry to temp
        Entry<K, V> newEntry = new Entry<>(key, value);
        temp.add(newEntry);
        size++;
        if (size > loadFactor * capacity) {
            resize();
        }
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
        List<LinkedList<Entry<K, V>>> oldTable = table;
        int oldCap = capacity;

        capacity = nextPrime(2 * oldCap);
        size = 0;
        table = new ArrayList<>(capacity);
        for (int i = 0; i < capacity; i++) {
            //initialize all of the new linked lists.
            table.add(new LinkedList<>());
        }
        for (LinkedList<Entry<K, V>> temp : oldTable) {
            for (Entry<K, V> entry : temp) {
                //return all values from linked list
                put(entry.getKey(), entry.getValue());
            }
        }
    }


    // TODO:
    //  Retrieves the value of a key in the table.
    //  Return null if not there.
    public V get(K key) {
        //Compute the hash code for the key
        int hash = hash(key);
        //grab the linked the list at the index.
        LinkedList<Entry<K, V>> temp = table.get(hash);

        //iterate through it and find the key.
        if (temp != null) {
            for (Entry<K, V> entry : temp) {
                if (entry.getKey().equals(key)) {
                    return entry.getValue();
                }
            }
        }
        return null;
    }

    // TODO: Searches the table to see if the key exists or not.
    public boolean containsKey(K key) {
        //Compute the hash code for the key
        int hash = hash(key);

        //Get the linked list at the hashed index
        LinkedList<Entry<K, V>> list = table.get(hash);

        //Check if the key exists in the linked list
        //virtually the same as get
        if (list != null) {
            for (Entry<K, V> entry : list) {
                if (entry.getKey().equals(key)) {
                    return true;
                }
            }
        }
        //Key not found
        return false;
    }

    // TODO:
    //  Remove the entry under that key. Return true.
    //  If there is no key, return false.
    public boolean remove(K key) {
       //get hash
        int hash = hash(key);

        //Get the linked list at the hashed index
        LinkedList<Entry<K, V>> list = table.get(hash);

        if (list == null) {
           //no entry w/ key
            return false;
        }

        //Search for the entry with the given key in the linked list
        for (int i = 0; i < list.size(); i++) {
            Entry<K, V> entry = list.get(i);
            if (entry.getKey().equals(key)) {
                // Remove the entry and return true
                list.remove(i);
                return true;
            }
        }

        //no entry
        return false;
    }

    public void clear() {
        for (LinkedList<Entry<K, V>> list : table) {
            list.clear();
        }
        size = 0;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public int size() {
        return size;
    }

    // TODO: Calculate the absolute hash of the key. Do not overthink this.
    private int hash(K key) {
        return Math.abs(key.hashCode()) % capacity;
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append("{");
        int index = 0;
        for (LinkedList<Entry<K, V>> list : table) {
            if (list.size() > 0) {
                sb.append(index + ": ");
                for (Entry<K, V> entry : list) {
                    sb.append(entry.getKey() + "=" + entry.getValue() + ",");
                }
                index++;
                sb.append(";");
            }
        }
        if (sb.length() > 1) {
            sb.setLength(sb.length() - 2);
        }
        sb.append("}");
        return sb.toString();
    }


    public static void main(String[] args) {
        HashTableWithChaining<String, Integer> hashTable = new HashTableWithChaining<>();

        hashTable.put("Hi", 2);
        hashTable.put("Ih", 2);
        hashTable.put("Hit", 2);
        hashTable.put("Him", 20);
        hashTable.put("His", 1);
        hashTable.put("Hiasdasd", 2);
        hashTable.put("Hiasdasds", 1);
        hashTable.put("Hiasdasadsd", 2);
        hashTable.put("H12is", 1);
        hashTable.put("H123iasdasd", 2);
        hashTable.put("Hita123s1d3asads", 2);
        System.out.println(hashTable);

    }
}

