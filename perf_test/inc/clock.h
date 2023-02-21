/*
 * @Author: Kk-knight liubin999000@163.com
 * @Date: 2023-02-21 21:13:24
 * @LastEditors: Kk-knight liubin999000@163.com
 * @LastEditTime: 2023-02-21 21:30:25
 * @FilePath: /perf_test/clock.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once

#include <time.h>
#include <iostream>

class Clock
{
public:
    Clock() = default;
    ~Clock() = default;

    void Start();
    void Stop();
    void PrintInfo();
private:
    uint64_t Duration(timespec &start, timespec &end);

private:
    timespec real_time_start_;
    timespec cpu_time_start_;
    timespec thread_time_start_;

    timespec real_time_end_;
    timespec cpu_time_end_;
    timespec thread_time_end_;
};
