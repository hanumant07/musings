var binaryTreePaths = function(root) {
    var result = [];
    var graph = [];
    
    var result_string="";
    if (root === null)
        return result;
    var root_descriptor = {};
    root_descriptor.node = root;
    graph.push(root_descriptor);
    while(graph.length > 0) {
        var root_entry = graph.shift();
        if (root_entry.path)
            var current_path = root_entry.path + root_entry.node.val.toString();
        else
            var current_path = root_entry.node.val.toString();
        if (root_entry.node.left === null && root_entry.node.right === null) {
            result.push(current_path);
            console.log('paths so far' + result);
        }
        if (root_entry.node.left !== null) {
            var left_entry = {};
            left_entry.node = root_entry.node.left;
            left_entry.path = current_path + '->';
            graph.push(left_entry);
        } if (root_entry.node.right !== null) {
            var right_entry = {};
            right_entry.node = root_entry.node.right;
            right_entry.path = current_path + '->';
            graph.push(right_entry);
        } 
    }
    return result;
};