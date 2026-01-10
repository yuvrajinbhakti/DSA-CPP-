/**
 * @param {Array} arr
 * @param {number} depth
 * @return {Array}
 */
var flat = function (arr, n) {
    const result = [];

    function dfs(current, depth) {
        for (const item of current) {
            // If item is an array AND we are allowed to flatten further
            if (Array.isArray(item) && depth < n) {
                dfs(item, depth + 1);
            } 
            // Otherwise, keep the item as-is
            else {
                result.push(item);
            }
        }
    }

    dfs(arr, 0);
    return result;
};


/*

Concise logic:

Traverse the array left to right.
Track current depth (start at 0).
For each element:
    - If it’s not an array → add to result.
    - If it is an array:
        - If depth < n → recursively traverse it with depth + 1.
        - If depth == n → add the array as-is.
Preserve order.
Stop flattening once depth reaches n.

*/