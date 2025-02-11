#!/bin/bash

# 用于自动化测试获得不同规模下的数据

# 定义输出文件名
OUTPUT_FILE="output.txt"

# 以追加模式写入输出文件
>> "$OUTPUT_FILE"

# 循环执行DP程序，n从100开始，每次增加100，直到1000
for (( n=100; n<1000; n+=100 ))
do
    ./DP -n "$n" -w 1000 -r 10 >> "$OUTPUT_FILE"
done

# 循环执行DP程序，n从1000开始，每次增加1000，直到10000
for (( n=1000; n<10000; n+=1000 ))
do
    ./DP -n "$n" -w 1000 -r 10 >> "$OUTPUT_FILE"
done

# 循环执行DP程序，n从10000开始，每次增加10000，直到100000
for (( n=10000; n<=100000; n+=10000 ))
do
    ./DP -n "$n" -w 1000 -r 10 >> "$OUTPUT_FILE"
done