
# 通过字典缓存数组元素，如果 target - num 在该字典里，返回相应下标
# time O(n)
# space O(n) 



class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hashtable = dict()
        for i, num in enumerate(nums):
            if target - num in hashtable:
                return [hashtable[target - num], i]
            hashtable[nums[i]] = i
        return []




# class Solution(object):
#     def twoSum(self, nums, target):
#         if len(nums) <= 1:
#             return False
#         buff_dict = {}
#         for i in range(len(nums)):
#             if nums[i] in buff_dict:
#                 return [buff_dict[nums[i]], i]
#             else:
#                 buff_dict[target - nums[i]] = i
# 