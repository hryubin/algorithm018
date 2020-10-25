/*
 * @lc app=leetcode.cn id=66 lang=c
 *
 * [66] 加一
 */

// @lc jH=start


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize){
    // 输入数组从数值个位开始逐位 加一 ，无进位时跳出
    for (int i = digitsSize - 1; i >= 0 ; i--) {
        digits[i] = ++digits[i] % 10; // 加一 后取 个位
        if (digits[i] != 0) break; // 无进位，退出循环
    }

    // 最高位产生进位：输出长度 +1；输出最高位置为 1
    // 其他 位/情况 按 加一 后结果输出
    *returnSize = digitsSize + (digits[0] == 0); // 首位为0——最高位进位，长度+1
    int* res = (int*)malloc(*returnSize * sizeof(int));
    res[0] = 1; // 预设输出最高位为 1
    memcpy(res + (digits[0] == 0), digits, digitsSize * sizeof(int)); // 复制digits到res的后digitsSize位中
    // 这里比较巧妙的是，两次 (digits[0] == 0) 数据类型自动转换的使用
    // (digits[0] == 0) bool 值为 True 时，转 int 值为 1 ；False 为 0
    // 正好是 returnSize 需要扩展 和 memcpy 需要偏移 的数值

    return res;
}