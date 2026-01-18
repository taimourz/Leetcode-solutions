/**
 * @param {number[][]} intervals
 * @param {number[]} newInterval
 * @return {number[][]}
 */
var insert = function(intervals, newInterval) {
    let i = 0
    let merged = []
    
    while(i<intervals.length && intervals[i][1] < newInterval[0])
    {
        merged.push(intervals[i])
        i++
    }
    while(i<intervals.length && intervals[i][0] <= newInterval[1])
    {
        newInterval[0] = Math.min(intervals[i][0], newInterval[0])
        newInterval[1] = Math.max(intervals[i][1], newInterval[1])
        i++
    }
    merged.push(newInterval)
    while(i<intervals.length)
    {
        merged.push(intervals[i])
        i++
    }
    debugger
    
    return merged 

    
};

console.log(insert([[1,3],[6,9]],[2,5]))
console.log(insert([[1,2],[3,5],[6,7],[8,10],[12,16]], [4,8]))


/*



[1,3] 

*/
