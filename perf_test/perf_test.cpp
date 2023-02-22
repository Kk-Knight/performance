/*
 * @Author: Kk-knight liubin999000@163.com
 * @Date: 2023-02-21 21:10:07
 * @LastEditors: liuyanbin liuyanbin@maxieyetech.com
 * @LastEditTime: 2023-02-22 12:27:19
 * @FilePath: /performance/perf_test/perf_test.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置
 * 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <unistd.h>

#include <iostream>
#include <thread>

#include "clock.h"

#define SWAP(a, b)  \
    {               \
        (a) ^= (b); \
        (b) ^= (a); \
        (a) ^= (b); \
    }

int CalculatFunc() {
    uint64_t count = UINT64_MAX;
    int a = rand() % 20000;
    int b = rand() % 10000;
    Clock clock;

    clock.Start();
    for (uint64_t i = 0; i < count; i++) {
        SWAP(a, b);
    }
    clock.Stop();
    clock.PrintInfo();

    return 0;
}

int SleepFunc(int sleep_ms) {
    uint64_t count = UINT64_MAX;
    int a = rand() % 20000;
    int b = rand() % 10000;
    Clock clock;

    std::cout << "sleep time = " << sleep_ms << "ms" << std::endl;
    clock.Start();
    for (uint64_t i = 0; i < count; i++) {
        SWAP(a, b);
        a = a * b;
        b = b / a;
    }
    usleep(sleep_ms * 1000);
    clock.Stop();
    clock.PrintInfo();

    return 0;
}

int NanosleepFunc(int sleep_ms) {
    uint64_t count = UINT64_MAX;
    int a = rand() % 20000;
    int b = rand() % 10000;
    Clock clock;

    std::cout << "sleep time = " << sleep_ms << "ms" << std::endl;
    clock.Start();
    for (uint64_t i = 0; i < count; i++) {
        SWAP(a, b);
        a = a * b;
        b = b / a;
    }
    struct timespec tm;
    tm.tv_sec = 0;
    tm.tv_nsec = sleep_ms * 1000000;
    nanosleep(&tm, NULL);
    clock.Stop();
    clock.PrintInfo();

    return 0;
}

int MultiTHreadFunc() {
    uint64_t count = UINT64_MAX;
    int a = rand() % 20000;
    int b = rand() % 10000;
    Clock clock;

    clock.Start();

    auto t = std::thread([&] {
        int c = rand() % 20000;
        int d = rand() % 10000;
        for (uint64_t i = 0; i < count; i++) {
            SWAP(c, d);
        }
    });

    for (uint64_t i = 0; i < count; i++) {
        SWAP(a, b);
        a = a * b;
        b = b / a;
    }
    t.join();
    clock.Stop();
    clock.PrintInfo();

    return 0;
}

int main(int argc, char *argv[]) {
    std::cout << "CalculatFunc :" << std::endl;
    CalculatFunc();
    std::cout << std::endl;

    std::cout << "SleepFunc :" << std::endl;
    SleepFunc(1);
    std::cout << std::endl;

    std::cout << "NanosleepFunc :" << std::endl;
    NanosleepFunc(1);
    std::cout << std::endl;

    std::cout << "MultiTHreadFunc :" << std::endl;
    MultiTHreadFunc();

    return 0;
}