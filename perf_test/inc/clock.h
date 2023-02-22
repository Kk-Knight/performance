/*
 * @Author: Kk-knight liubin999000@163.com
 * @Date: 2023-02-21 21:13:24
 * @LastEditors: liuyanbin liuyanbin@maxieyetech.com
 * @LastEditTime: 2023-02-22 13:18:22
 * @FilePath: /performance/perf_test/inc/clock.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#pragma once

#include <time.h>

#include <iostream>

enum TimerBit {
    MONO_TIMER = 0x1,
    REAL_TIMER = 0x10,
    CPU_TIMER = 0x100,
    THREAD_TIMER = 0x1000,
};

class Clock {
public:
    Clock() = delete;
    ~Clock() = default;
    Clock(int timer_flag) : timer_flag_(timer_flag) {}

    void Start();
    void Stop();
    void PrintInfo();

private:
    double Duration(timespec &start, timespec &end);

private:
    timespec mono_time_start_;
    timespec real_time_start_;
    timespec cpu_time_start_;
    timespec thread_time_start_;

    timespec mono_time_end_;
    timespec real_time_end_;
    timespec cpu_time_end_;
    timespec thread_time_end_;

    int timer_flag_;
};
