import java.util.*;

public class Kruskals {

    /**
     * MST
     * <p>
     * implement Kruskal's MST algorithm from class.
     * <p>
     * As a refresher,
     * <p>
     * Get a list of edges and their weights (use the
     * Edge class for this).
     * Sort the edges. (You may use Collections.sort()).
     * Then, add the edges in order of smallest to
     * largest into the MST.
     * If a cycle is created, then don't add the edge.
     * Once each node has an edge, you're done!
     * One important note about the mst array.
     * It does not contain information on the weights,
     * only the nodes of the edges.
     * i        = u
     * mst[i]     = v
     * graph[i][mst[i]] = weight(u, v)
     *
     * @param graph graph of edges and weights.
     * @return a Minimum Spanning Tree of the graph.
     */
    public static int[] mst(Graph graph) throws DisconnectedGraphException{
        int n = graph.getNumNodes();
        //minimum spanning tree
        int[] mst = new int[n];
        //create list of edges and their weights
        List<Edge> edges = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            //if a row ends up being empty in rows and columns
            for (int j = 0; j < n; j++) {
                //edge exists
                if (graph.getEdge(i,j) > 0) {
                    edges.add(new Edge(i, j, graph.getEdge(i,j)));
                }
            }
        }
        //no edges case
        if(edges.isEmpty()){
            return null;
        }
        //check for disconnects
        boolean[] notempty = new boolean[graph.getNumNodes()];
        Arrays.fill(notempty,false);
        for(int i = 0; i < graph.getNumNodes(); i++) {
            for (int p = 0; p < edges.size(); p++) {
                if (edges.get(p).v == i || edges.get(p).u == i) {
                    notempty[i] = true;
                }
            }
        }

        //if there is a disjointed graph.
        for(int i = 0; i < notempty.length; i++){
            if(notempty[i] == false){
                throw new DisconnectedGraphException();
            }
        }


        //sort edges by weight
        Collections.sort(edges);

        int[] mstcopy;
        //avoid index out of bounds except
       for(int i = 0; i < edges.size(); i+=2){
           mstcopy = Arrays.copyOf(mst, mst.length);
           //if we hypothetically plugged in this
           //source
           mstcopy[i] = edges.get(i).u;
           //dest
           mstcopy[i+1] = edges.get(i).v;
           if(!cycleExists(mstcopy)){
               //only plug it in if there isn't a cycle
               //node
               mst[i] = edges.get(i).u;
               //end
               mst[i+1] = edges.get(i).v;
           } else {
               mst = Arrays.copyOf(mstcopy, mstcopy.length);
           }
       }
       return mst;
    }


    /**
     * CYCLEEXISTS
     * <p>
     * Use any cycle detection algorithm of your choosing.
     * <p>
     * BFS/DFS recommended
     * <p>
     * Simply traverse the graph and if you encounter a node
     * twice, then there is a cycle. Return true.
     * <p>
     * Otherwise, there is no cycle. Return false.
     *
     * @param mst The MST in progress.
     * @return True, if a cycle is detected, otherwise false.
     */

    public static boolean cycleExists(int[] mst) {
        if(mst.length == 0){
            return false;
        }
        int n = mst.length;
        boolean[] visited = new boolean[n];
        //creating an adjacency list representation of the MST
        Map<Integer, List<Integer>> adjacencyList = new HashMap<>();
        for (int i = 0; i < n; i += 2) {
            int u = mst[i];
            int v = mst[i + 1];
            //put both in the adjacency list

            adjacencyList.putIfAbsent(u, new ArrayList<>());
            adjacencyList.putIfAbsent(v, new ArrayList<>());

            //add the connection both ways to the adjacency list
            adjacencyList.get(u).add(v);
            adjacencyList.get(v).add(u);
        }

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, visited, adjacencyList)) {
                    return true;
                }
            }
        }
        return false;
    }

    private static boolean dfs(int current, int parent, boolean[] visited, Map<Integer, List<Integer>> adjacencyList){
        visited[current] = true;
        //if it is present in the adjacency list
        if (!adjacencyList.containsKey(current)) {
            return false;
        }
        //check every neighbor of the current node in the adjacency list
        for (int neighbor : adjacencyList.get(current)) {
            if (neighbor != parent) {
                if (visited[neighbor]) {
                    return true;
                } else {
                    //recursively call it with the neighbor as the current and the current as the parent
                    if (dfs(neighbor, current, visited, adjacencyList)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
}
