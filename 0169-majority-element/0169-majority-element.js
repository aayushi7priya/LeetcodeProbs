/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
     let count = 0, ans = null;
  for (let num of nums) {
    if (count === 0) {
       ans = num;
       count++;
    } 
    else if (ans === num)  //count not zero and same ans so increase count
      count++;
    else count--;         //count not zero ans different, so decrease
 }
  
  return ans;
};