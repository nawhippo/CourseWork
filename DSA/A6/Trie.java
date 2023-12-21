import java.util.ArrayList;
public class Trie {
    TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    public Trie(TrieNode root) {
        this.root = root;
    }

    // Setters & Getters
    public TrieNode getRoot() {
        return this.root;
    }

    public void setRoot(TrieNode root) {
        this.root = root;
    }

    // Actual methods -- part of Lab7
    // TODO:
    public void insert(String word) {
        TrieNode curr = root;

        //traverse through each character of the word
        for (int i = 0; i < word.length(); i++) {
            //for case insensitivity
            char c = Character.toLowerCase(word.charAt(i));

            //check if the current char is already present in the trie
            TrieNode node = curr.children.get(c);

            //create a new node and add it to the trie if it doesn't exist
            if (node == null) {
                node = new TrieNode();
                curr.children.put(c, node);
            }

            //move to the next node
            curr = node;
            }
        //if this is the last character of the word, mark it as a word and increment the frequency
        curr.frequency++;
        curr.isWord = true;

    }



    // TODO:
    boolean search(String word) {
        TrieNode curr = root;
        for (char c : word.toCharArray()) {
            //searches are case insensitive as well
            if (curr.children.get(Character.toLowerCase(c)) == null) return false;
            curr = curr.children.get(Character.toLowerCase(c));
        }
        return (curr.isWord);
    }

    /*
    TODO: Remove the TrieNodes associated with the word. There are 3 cases to be concerned with.
        - key is unique: no part of key contains another key nor is the key itself a prefix of another key in the trie: remove all nodes
        - key is prefix key of another key: unmark the leaf node
        - key has at least one other word as a prefix: delete the nodes from the end of the key :p
        This is NOT the delete you implemented in lab.
 */


    public void delete(String word) {
        deleteHelper(root, word, 0);
    }

    private boolean deleteHelper(TrieNode node, String word, int index) {
        if (index == word.length()) {
            // If we've reached the end of the word, unmark the node as a word and decrement frequency
            if (node.isWord) {
                if (node.frequency > 1) {
                    node.frequency--;
                } else {
                    node.isWord = false;
                    node.frequency--;
                }
            }
                // If this node has no children and no other words use it as a prefix, remove it from the trie
                return node.children.isEmpty() && node.frequency == 0;
            }

            char c = Character.toLowerCase(word.charAt(index));
            TrieNode childNode = node.children.get(c);
            if (childNode == null) {
                // The word is not in the trie
                return false;
            }

            boolean shouldDeleteChildNode = deleteHelper(childNode, word, index + 1);
            if (shouldDeleteChildNode) {
                node.children.remove(c);
                // If this node has no other children or is marked as a word, remove it from the trie
                return node.children.isEmpty() && node.frequency == 0;
            }
            return false;
        }



    // TODO: Gets all possible words with the prefix through traversing the Trie. If it's a word, then turn it into an Entry.
    //       If not, ignore. Put the Entry's into a list and return.
    //       Hint: Look at your MazeSolver with a stack for inspiration for the traversal.
    //       EX: If you have prefix "ca", then it should look at all combinations of the words starting with "ca".

    public ArrayList<Entry> generateWordsFromPrefix(String prefix) {
        ArrayList<Entry> result = new ArrayList<>();
        TrieNode node = findNodeHelper(prefix);
        if (node != null) traverseSubtreeHelper(node, prefix, result);
        return result;
    }

    private void traverseSubtreeHelper(TrieNode node, String prefix, ArrayList<Entry> result) {
        if (node.isWord) {
            //create new Entry object to add to our list of word entries
            result.add(new Entry(node.frequency, prefix));
        }
        //returns set of characters that are keys in the children map,
        //so we can iterate over characters that have children
        for (char c : node.children.keySet()) {
            TrieNode childNode = node.children.get(Character.toLowerCase(c));
            //add to the character
            String newPrefix = prefix + Character.toLowerCase(c);
            //traverse the tree again with the slightly longer word.
            traverseSubtreeHelper(childNode, newPrefix, result);
        }
    }

    //basically search but returns the actual node.
    private TrieNode findNodeHelper(String prefix) {
        TrieNode current = root;
        for (int i = 0; i < prefix.length(); i++) {
            char c = Character.toLowerCase(prefix.charAt(i));
            if (!current.children.containsKey(Character.toLowerCase(c))) {
                return null;
            }
            current = current.children.get(Character.toLowerCase(c));
        }
        return current;
    }


    //check a words frequency, mostly for debugging
    int frequencycheck(String word) {
        TrieNode curr = root;
        for (char c : word.toCharArray()) {
            if (curr.children.get(Character.toLowerCase(c)) == null) return 0;
            curr = curr.children.get(Character.toLowerCase(c));
        }
        if (curr.isWord) return curr.frequency;
        return 0;
    }

}