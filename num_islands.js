/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/

/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    var i = 0;
    var islands = 0;
    var current_graph = [];
    var visited = [];
    if (grid === null)
        return 0;
    if (grid.length === 0)
        return 0;
    var num_points = grid[0].length;
    var num_edges = grid.length;
    for ( i = 0; i < num_points; i++) {
        if (visited[i] === true)
            continue;
        current_graph.push(i);
        while(current_graph.length > 0) {
            var current_vertex = current_graph.pop();
            visited[current_vertex] = true;
            /* push all connected, unvisited, nodes of the current node in visiting queue */
            for (j = 0; j < num_edges; j++) {
                if (grid[current_vertex][j] === 1 && !visited(j))
                    current_graph.push(j);
            }
        }
        islands++;
    }
    return islands;
};