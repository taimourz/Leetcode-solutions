/**
 * @param {number[][]} firstList
 * @param {number[][]} secondList
 * @return {number[][]}
 */
var intervalIntersection = function(firstList, secondList) {
    
    let ans = []
    let i = 0
    let j = 0

    while(i < firstList.length && j < secondList.length)
    {
        // check if intervals overlap. firstList start time lies within other intervals(secondList) time
        let a_overlaps_b = firstList[i][0] >= secondList[j][0] && firstList[i][0] <= secondList[j][1]
        // check if intervals overlap. secondList start time lies within other intervals(firstList) time
        let b_overlaps_a = secondList[j][0] >= firstList[i][0] && secondList[j][0] <= firstList[i][1]

        // take max of start and min of end
        if(a_overlaps_b || b_overlaps_a)
        {
            start = Math.max(firstList[i][0], secondList[j][0])
            end = Math.min(firstList[i][1], secondList[j][1])
            ans.push([start, end])
        }


        // move the interval for which the end time comes first
        if(firstList[i][1] < secondList[j][1])
        {
            i++
        }
        else
        {
            j++
        } 
        
    }

    return ans
    

};


console.log(intervalIntersection([[0,2],[5,10],[13,23],[24,25]], [[1,5],[8,12],[15,24],[25,26]]))
