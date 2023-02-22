/*
 * @Author: Kk-knight liubin999000@163.com
 * @Date: 2023-02-21 21:13:18
 * @LastEditors: liuyanbin liuyanbin@maxieyetech.com
 * @LastEditTime: 2023-02-22 12:19:46
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
    std::cout << "Real time: "
              << Duration(real_time_start_, real_time_end_) / 1000000 << "ms "
              << std::endl;
    std::cout << "CPU time: "
              << Duration(cpu_time_start_, cpu_time_end_) / 1000000 << "ms "
              << std::endl;
    std::cout << "Thread time: "
              << Duration(thread_time_start_, thread_time_end_) / 1000000
              << "ms" << std::endl;
}

void Clock::Start() {
    clock_gettime(CLOCK_MONOTONIC, &real_time_start_);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &cpu_time_start_);
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &thread_time_start_);
}

void Clock::Stop() {
    clock_gettime(CLOCK_MONOTONIC, &real_time_end_);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &cpu_time_end_);
    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &thread_time_end_);
}