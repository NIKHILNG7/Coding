class Solution {
        func maxConsecutiveAnswers(_ answerKey: String, _ k: Int) -> Int {
            var answerArray = answerKey.map { $0 }
            var maxConsecutive = 0
            
            var trueCount = 0
            var falseCount = 0
            
            var left = 0
            var right = 0
            
            while left < answerArray.count && right < answerArray.count {
                //print("left: \(left), right: \(right), maxConsecutive: \(maxConsecutive)")
                
                if answerArray[right] == "F" {
                    falseCount += 1
                } else if answerArray[right] == "T" {
                    trueCount += 1
                }
                
                if min(trueCount, falseCount) <= k {
                    maxConsecutive = max(maxConsecutive, trueCount + falseCount)
                    right += 1
                } else {
                    if answerArray[left] == "F" {
                        falseCount -= 1
                    } else if answerArray[left] == "T" {
                        trueCount -= 1
                    }
                    left += 1
                    right += 1
                }
                
            }
            
            
            return maxConsecutive
        }
    }