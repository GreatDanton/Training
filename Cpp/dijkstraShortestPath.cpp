#include <iostream>
#include <limits>
#include <vector>
/**
 * Dijkstra shortest path algorithm using adjacency matrix representation of the graph.
 * Some additional material describing the algorithm and implementation ideas could
 * be found below:
 *
 * Intro:
 *  - https://medium.com/basecs/finding-the-shortest-path-with-a-little-help-from-dijkstra-613149fbdc8e
 *
 *
 * A*:
 *  - https://www.redblobgames.com/pathfinding/a-star/implementation.html
 *
 *
 * A few different ways of implementing it:
 *  - https://stackoverflow.com/questions/3447566/dijkstras-algorithm-in-c
 *
 */

const std::vector<std::vector<int64_t>> graph = {
    {0, 7, 3, 0, 0}, // vertex a distances
    {7, 0, 1, 2, 6}, // vertex b distances
    {3, 1, 0, 2, 0}, // vertex c distances
    {0, 2, 2, 0, 4}, // vertex d distances
    {0, 6, 0, 4, 0}  // vertex e distances
};

/**
 * Print the end result:
 * vertex | distance from starting point
 *
 * @param distances - array of distances from the starting point to the graph vertex
 */
void printSolution(std::vector<int64_t> &distances)
{
    std::cout << std::endl;
    std::cout << "Vertex: | Distance " << std::endl;
    for (size_t i = 0; i < distances.size(); i++)
    {
        std::cout << i << "           " << distances.at(i) << std::endl;
    }
}

/**
 * Get index of the unvisited vertex with the shortest travelled distance
 *
 * @param distances - vector of distances between the chosen starting point and any graph vertex
 * @param visitedVertices - vector of vertices which contains all graph vertices and their state
 * (true if the vertex was visited, false if it was not)
 *
 * @return graph index of the unvisited vertex with the shortest travelled distance or -1 if no such vertex
 * exist (vertices were already visited)
 */
int64_t vertexWithMinDistance(std::vector<int64_t> &distances, std::vector<bool> &visitedVertices)
{
    int64_t minDistance = std::numeric_limits<int64_t>::max();
    int64_t vertexIndex = -1;

    for (size_t i = 0; i < visitedVertices.size(); i++)
    {
        // vertex is not visited, check it's distance
        if (!visitedVertices.at(i))
        {
            int64_t vertexDistance = distances.at(i);

            if (vertexDistance < minDistance)
            {
                minDistance = vertexDistance;
                vertexIndex = i;
            }
        }
    }

    return vertexIndex;
}

/**
 * Set the initial values for the vertex distances and visited arrays
 *
 * @param graphSize - size of the graph for which we are calculating shortest path
 * @param distances - vector of distances between the graph starting point and any other graph vertex
 * @param visited - contains info about visited state of each graph vertex
 * @param startingVertex - index of the starting graph vertex
 */
void initialize(std::vector<int64_t> &distances, std::vector<bool> &visited, int64_t startingVertex)
{
    for (size_t i = 0; i < visited.size(); i++)
    {
        distances.at(i) = std::numeric_limits<int64_t>::max();
        visited.at(i) = false;
    }

    distances.at(startingVertex) = 0;
}

/**
 * Dijkstra shortest path algorithm. Finds the shortest path between the starting
 * vertex and any other vertex in the graph
 *
 * Traverse logic:
 * 1. Select the starting vertex
 * 2. For the currently selected vertex, check every connection with another vertex
 * 3. If the distance between the vertices is smaller than what we are tracking in our
 *    path distance table, update the path distance table
 * 4. Select the new unvisited vertex with the currently smallest distance and perform step 2
 *
 * @param graph - graph with vertices
 * @param startingVertex - index of the vertex in the graph for which we are calculating the
 * path distances
 */
void dijkstra(const std::vector<std::vector<int64_t>> &graph, int64_t startingVertex)
{
    if (graph.size() - 1 < startingVertex)
    {
        std::cout << "Graph does not contain the starting vertex" << std::endl;
        return;
    }

    /** Contains distances from the starting point to the chosen vertex (index of the array represents vertex in the graph) */
    std::vector<int64_t> distances(graph.size());
    /** Contains graph vertices that were already visited (set to true). Index of the array represents vertex in the graph)*/
    std::vector<bool> visited(graph.size());

    initialize(distances, visited, startingVertex);

    while (true)
    {
        // in the first iteration a starting vertex will be chosen
        int64_t currentVertex = vertexWithMinDistance(distances, visited);
        if (currentVertex == -1)
        {
            break;
        }
        std::cout << "Traversed vertex: " << currentVertex << std::endl;

        std::vector<int64_t> currentVertexDistances = graph.at(currentVertex);

        // iterate over distances for the current vertex and update distance array where applicable
        for (size_t vertex = 0; vertex < currentVertexDistances.size(); vertex++)
        {
            int64_t addDistance = currentVertexDistances.at(vertex);
            // when distance is 0, it means there is no connection between the two vertices,
            // we should move on to the next vertex
            if (addDistance == 0)
            {
                continue;
            }

            // if the sum of current vertex path + new path is smaller than what we allready have
            // in the distance table => update the distance table
            int64_t currentVertexDistance = distances.at(currentVertex);
            int64_t pathDistance = addDistance + currentVertexDistance;
            if (pathDistance < distances.at(vertex))
            {
                distances.at(vertex) = pathDistance;
            }
        }

        // mark vertex as visited, and move on to the next unvisited vertex
        visited.at(currentVertex) = true;
    }

    printSolution(distances);
}

int main()
{
    dijkstra(graph, 0);
    return 0;
}