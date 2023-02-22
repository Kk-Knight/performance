/*
 * @Author: Kk-knight liubin999000@163.com
 * @Date: 2023-02-21 21:13:18
 * @LastEditors: liuyanbin liuyanbin@maxieyetech.com
 * @LastEditTime: 2023-02-22 13:16:53
 * @FilePath: /performance/perf_test/src/clock.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "clock.h"

double Clock::Duration(timespec &start, timespec &end) {
    return ((end.tv_sec - start.tv_sec) * 1000000000 +
            (end.tv_nsec - start.tv_nsec));
}

void Clock::PrintInfo() {
    if (timer_flag_ & MONO_TIMER) {
        std::cout << "Mono time: "
                  << Duration(real_time_start_, real_time_end_) / 1000000
                  << "ms " << std::endl;
    }
    if (timer_flag_ & REAL_TIMER) {
        std::cout << "Real time: "
                  << Duration(real_time_start_, real_time_end_) / 1000000
                  << "ms " << std::endl;
    }
    if (timer_flag_ & CPU_TIMER) {
        std::cout << "CPU time: "
                  << Duration(cpu_time_start_, cpu_time_end_) / 1000000 << "ms "
                  << std::endl;
    }
    if (timer_flag_ & THREAD_TIMER) {
        std::cout << "Thread time: "
                  << Duration(thread_time_start_, thread_time_end_) / 1000000
                  << "ms" << std::endl;
    }
}

void Clock::Start() {
    if (timer_flag_ & MONO_TIMER) {
        clock_gettime(CLOCK_MONOTONIC, &mono_time_start_);
    }
    if (timer_flag_ & REAL_TIMER) {
        clock_gettime(CLOCK_REALTIME, &real_time_start_);
    }
    if (timer_flag_ & CPU_TIMER) {
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &cpu_time_start_);
    }
    if (timer_flag_ & THREAD_TIMER) {
        clock_gettime(CLOCK_THREAD_CPUTIME_ID, &thread_time_start_);
    }
}

void Clock::Stop() {
    if (timer_flag_ & MONO_TIMER) {
        clock_gettime(CLOCK_MONOTONIC, &mono_time_end_);
    }
    if (timer_flag_ & REAL_TIMER) {
        clock_gettime(CLOCK_REALTIME, &real_time_end_);
    }
    if (timer_flag_ & CPU_TIMER) {
        clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &cpu_time_end_);
    }
    if (timer_flag_ & THREAD_TIMER) {
        clock_gettime(CLOCK_THREAD_CPUTIME_ID, &thread_time_end_);
    }
}