/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function(intervals) {
    intervals.sort((a,b) => a[0] - b[0])
    if(intervals.length < 2) return intervals


    let mergedIntervals = []
    let start = intervals[0][0]
    let end = intervals[0][1]
    
    for(let i = 1; i < intervals.length; i++)
    {
        if(intervals[i][0] <= end)
        {
            end = Math.max(intervals[i][1], end)
        }
        else
        {
            mergedIntervals.push([intervals[i][0], end])
            start = intervals[i][0]
            end = intervals[i][1]
        }
        debugger
    }


    mergedIntervals.push([start, end])
    return mergedIntervals
};


console.log(merge([[1,3],[2,6],[8,10],[15,18]]))
