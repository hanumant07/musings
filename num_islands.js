/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
*/


var doOneDimension = function(grid) {
    var numIslands = 0;
    var i = 0;
    var vector = grid[0];
    if (vector.charAt(0) === '1')
        numIslands++;
    for (i = 1; i < vector.length; i ++) {
        if (grid[i] === '1')
            continue;
        else
            numIslands++;
    }
    return numIslands;
};

var doTwoDimension = function(grid, visited, rows, cols) {
    var i;
    var j;
    var currentIsland = [];
    var numIslands = 0;
    for ( i = 0; i < rows; i++) {
        for ( j = 0; j < cols; j++) {
            // Check if current site is already part of some island
            //console.log('visited[' + i + ']' + '[' + j + '] = ' + visited[i][j]);
            if (visited[i][j] === 1) {
                console.log('Already visted ' + i + ',' + j);
                continue;
            }
            if (grid[i].charAt(j) === '0') {
                visited[i][j] = 1;
                continue;
            }
            /* Create Island containing current vertex i, j */
            //console.log('current row ' + grid[i] + ' current index ' + j);
            
            currentIsland.push([i, j]);
            while(currentIsland.length > 0) {
                var current_vertex = currentIsland.pop();
                /* Mark current vertex as visited */
                visited[current_vertex[0]][current_vertex[1]] = 1;
                /* Establish horizontal and vertical neighbours of current vertex */
                var right = [ current_vertex[0], current_vertex[1] + 1 ];
                var down = [ current_vertex[0] + 1, current_vertex[1] ];
                var left = [ current_vertex[0], current_vertex[1] - 1 ];
                var up = [ current_vertex[0] + 1, current_vertex[0] ];
                if ( (up[0] >= 0) && (grid[ up[0] ].charAt(up[1]) === 1) && (visited[ up[0] ][ up[1] ] !== 1) ) 
                    /* the vertical neighbour should be visited to grow island*/
                    currentIsland.push([up[0], up[1]]);
                if ( (down[0] < rows) && (grid[down[0] ].charAt(down[1]) === 1) && (visited[down[0] ][down[1]] !== 1) ) 
                    /* the vertical neighbour should be visited to grow island*/
                    currentIsland.push([down[0], down[1]]);

                    /* check if site next to the current one can be visited */    
                if ( (right[1] < cols) && (grid[right[0] ].charAt(right[1]) === 1) && (visited[ right[0] ][ right[1] ] !== 1) )
                    /* the horizontal neighbour should be visited */
                    currentIsland.push([right[0], right[1]]);
                if ( (left[1] >= 0) && (grid[left[0] ].charAt(left[1]) === 1) && (visited[ left[0] ][ left[1] ] !== 1) )
                    /* the horizontal neighbour should be visited */
                    currentIsland.push([left[0], left[1]]);
            }
            numIslands++;  

        }

        console.log('numislands at row ' + i + ' :' + numIslands);
    }
    return numIslands;
};
/**
 * @param {character[][]} grid
 * @return {number}
 */
var numIslands = function(grid) {
    if (grid === null)
        return 0;
    if (grid.length === 0)
        return 0;
    var rows = grid.length;
    var rowVector = grid[0];
    var cols = rowVector.length;
    console.log('columns ' + cols); 
    if (rows === 1)
        return doOneDimension(grid);
    else if (!rows)
        return doOneDimension(grid);
    else {
        var visited = new Array(rows, cols);
        
        visited.fill(0);
        return doTwoDimension(grid, visited, rows, cols);
    }
return 0;
}